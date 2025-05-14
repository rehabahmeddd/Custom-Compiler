#include "quad_handler.h"
#include <stdlib.h>
#include <string.h>
#include "quad_handler.h"


extern Scope* current_scope;
extern DataType infer_expr_type(Scope* scope, char* expr);

// Forward declarations
extern void yyerror(const char* s);

// String representation of operations
const char* op_names[] = {
    "ADD",          // OP_ADD
    "SUB",          // OP_SUB
    "MUL",          // OP_MUL
    "DIV",          // OP_DIV
    "MOD",          // OP_MOD
    "ASSIGN",       // OP_ASSIGN
    "LT",           // OP_LT
    "GT",           // OP_GT
    "EQ",           // OP_EQ
    "NEQ",          // OP_NEQ
    "LE",           // OP_LE
    "GE",           // OP_GE
    "AND",          // OP_AND
    "OR",           // OP_OR
    "NOT",          // OP_NOT
    "LABEL",        // OP_LABEL
    "GOTO",         // OP_GOTO
    "IF_TRUE",      // OP_IF_TRUE
    "IF_FALSE",     // OP_IF_FALSE
    "FUNC_BEGIN",   // OP_FUNC_BEGIN
    "FUNC_END",     // OP_FUNC_END
    "CALL",         // OP_CALL
    "PARAM",        // OP_PARAM
    "RETURN"        // OP_RETURN
};

// Helper function to create a new quadruple
static Quadruple* create_quad(QuadOp op, const char *arg1, const char *arg2, const char *result) {
    Quadruple *quad = (Quadruple*)malloc(sizeof(Quadruple));
    if (!quad) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    
    quad->op = op;
    quad->arg1 = arg1 ? strdup(arg1) : NULL;
    quad->arg2 = arg2 ? strdup(arg2) : NULL;
    quad->result = result ? strdup(result) : NULL;
    quad->next = NULL;
    
    return quad;
}

// Initialize the quad handler
QuadHandler* quad_init(const char *filename) {
    QuadHandler *handler = (QuadHandler*)malloc(sizeof(QuadHandler));
    if (!handler) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    
    handler->first = NULL;
    handler->last = NULL;
    handler->temp_count = 0;
    handler->label_count = 0;
    
    handler->output_file = fopen(filename, "w");
    if (!handler->output_file) {
        fprintf(stderr, "Error opening output file: %s\n", filename);
        free(handler);
        exit(1);
    }
    
    return handler;
}

// Clean up the quad handler
void quad_cleanup(QuadHandler *handler) {
    if (!handler) return;
    
    // Free all quadruples
    Quadruple *current = handler->first;
    while (current) {
        Quadruple *next = current->next;
        
        if (current->arg1) free(current->arg1);
        if (current->arg2) free(current->arg2);
        if (current->result) free(current->result);
        
        free(current);
        current = next;
    }
    
    // Close file
    if (handler->output_file) {
        fclose(handler->output_file);
    }
    
    // Free handler
    free(handler);
}

// Generate a new temporary variable name
char *quad_new_temp(QuadHandler *handler, DataType type)
{
    char *temp = (char *)malloc(20); // Enough for "t" + digits + type suffix
    if (!temp)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    // Add type suffix to temporary variable names
    const char* type_suffix = "";
    switch (type) {
        case TYPE_INT: type_suffix = "_int"; break;
        case TYPE_FLOAT: type_suffix = "_float"; break;
        case TYPE_DOUBLE: type_suffix = "_double"; break;
        case TYPE_BOOL: type_suffix = "_bool"; break;
        case TYPE_STRING: type_suffix = "_string"; break;
        case TYPE_CHAR: type_suffix = "_char"; break;
         case TYPE_VOID:   type_suffix = "_void"; break;
        default: type_suffix = ""; break;
    }
    
    sprintf(temp, "t%d%s", handler->temp_count++, type_suffix);
    return temp;
}

// Generate a new label
char* quad_new_label(QuadHandler *handler) {
    char *label = (char*)malloc(20); // Enough for "L" + digits
    if (!label) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    
    sprintf(label, "L%d", handler->label_count++);
    return label;
}

// Add a quadruple
void quad_add(QuadHandler *handler, QuadOp op, const char *arg1, const char *arg2, const char *result) {

    if (op == OP_LABEL && arg1 == NULL) {
        return;
    }

    Quadruple *quad = create_quad(op, arg1, arg2, result);
    
    if (!handler->first) {
        handler->first = quad;
        handler->last = quad;
    } else {
        handler->last->next = quad;
        handler->last = quad;
    }
    
    // Also write to file immediately
    if (handler->output_file) {
        fprintf(handler->output_file, "%s", op_names[op]);
        
        if (arg1) fprintf(handler->output_file, " %s", arg1);
        if (arg2) fprintf(handler->output_file, " %s", arg2);
        if (result) fprintf(handler->output_file, " %s", result);
        
        fprintf(handler->output_file, "\n");
    }
}

// Add a label quadruple
void quad_add_label(QuadHandler *handler, const char *label) {
    if (label == NULL) {
        return; 
    }
    quad_add(handler, OP_LABEL, label, NULL, NULL);
}


void quad_add_goto(QuadHandler *handler, const char *label) {
    if (!label) {
        fprintf(stderr, "ERROR: Attempted to add goto with NULL label\n");
        return;
    }
    quad_add(handler, OP_GOTO, label, NULL, NULL);
}

void quad_add_if_jump(QuadHandler *handler, const char *condition, const char *label, int if_true) {
    if (!condition || !label) {
        fprintf(stderr, "ERROR: Attempted to add conditional jump with NULL condition or label\n");
        return;
    }
    QuadOp op = if_true ? OP_IF_TRUE : OP_IF_FALSE;
    quad_add(handler, op, condition, label, NULL);
}

// Add a function declaration
void quad_add_func_begin(QuadHandler *handler, const char *func_name) {
    quad_add(handler, OP_FUNC_BEGIN, func_name, NULL, NULL);
}

// Add a function end
void quad_add_func_end(QuadHandler *handler) {
    quad_add(handler, OP_FUNC_END, NULL, NULL, NULL);
}

// Add a function call
void quad_add_call(QuadHandler *handler, const char *func_name, int param_count, const char *result) {
    char param_count_str[20];
    sprintf(param_count_str, "%d", param_count);
    quad_add(handler, OP_CALL, func_name, param_count_str, result);
}
// Add a function parameter
void quad_add_param(QuadHandler *handler, const char *param) {
    quad_add(handler, OP_PARAM, param, NULL, NULL);
}

// Add a function return
void quad_add_return(QuadHandler *handler, const char *value) {
    quad_add(handler, OP_RETURN, value, NULL, NULL);
}

// Generate quad for arithmetic operation
Symbol* quad_gen_math(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2) {
    // Check for NULL arguments (defensive)
    if (!arg1 || !arg2) {
        // Create a default int result if arguments are missing
        char *temp = quad_new_temp(handler, TYPE_INT);
        quad_add(handler, OP_ASSIGN, "0", NULL, temp);
        
        // Create and return a new symbol
        Symbol *result = (Symbol*)malloc(sizeof(Symbol));
        result->name = temp;
        result->type = TYPE_INT;
        result->kind = KIND_VAR;
        result->declared = true;
        result->initialized = true;
        result->constant = false;
        result->value = NULL;
        result->scope = NULL;
        result->next = NULL;
        
        return result;
    }
    
    // Create result with appropriate type
    DataType resultType = (arg1->type == TYPE_FLOAT || arg2->type == TYPE_FLOAT) ? TYPE_FLOAT : TYPE_INT;
    char *temp = quad_new_temp(handler, resultType);
    
    // Generate quadruple
    quad_add(handler, op, arg1->name, arg2->name, temp);
    
    // Create and return a new symbol
    Symbol *result = (Symbol*)malloc(sizeof(Symbol));
    result->name = temp;
    result->type = resultType;
    result->kind = KIND_VAR;
    result->declared = true;
    result->initialized = true;
    result->constant = false;
    result->value = NULL;
    result->scope = NULL;
    result->next = NULL;
    
    return result;
}

// Generate quad for relational operation
Symbol* quad_gen_rel(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2) {
    // Check for NULL arguments (defensive)
    if (!arg1 || !arg2) {
        // Create a default true result if arguments are missing
        char *temp = quad_new_temp(handler, TYPE_BOOL);
        quad_add(handler, OP_ASSIGN, "true", NULL, temp);
        
        // Create and return a new symbol
        Symbol *result = (Symbol*)malloc(sizeof(Symbol));
        result->name = temp;
        result->type = TYPE_BOOL;
        result->kind = KIND_VAR;
        result->declared = true;
        result->initialized = true;
        result->constant = false;
        result->value = NULL;
        result->scope = NULL;
        result->next = NULL;
        
        return result;
    }
    
    // Check for valid types
    if (arg1->type != TYPE_INT && arg1->type != TYPE_FLOAT && arg1->type != TYPE_BOOL) {
        yyerror("Invalid type for relational operation");
        return NULL;
    }
    if (arg2->type != TYPE_INT && arg2->type != TYPE_FLOAT && arg2->type != TYPE_BOOL) {
        yyerror("Invalid type for relational operation");
        return NULL;
    }
    
    // Create boolean result
    char *temp = quad_new_temp(handler, TYPE_BOOL);
    
    // Generate quadruple
    quad_add(handler, op, arg1->name, arg2->name, temp);
    
    // Create and return a new symbol
    Symbol *result = (Symbol*)malloc(sizeof(Symbol));
    result->name = temp;
    result->type = TYPE_BOOL;
    result->kind = KIND_VAR;
    result->declared = true;
    result->initialized = true;
    result->constant = false;
    result->value = NULL;
    result->scope = NULL;
    result->next = NULL;
    
    return result;
}

// Generate quad for logical operation
Symbol* quad_gen_logic(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2) {
    Symbol *result;
    char *temp;
    
    // For NULL arguments (defensive)
    if (!arg1 || (op != OP_NOT && !arg2)) {
        // Create a default true result if arguments are missing
        temp = quad_new_temp(handler, TYPE_BOOL);
        quad_add(handler, OP_ASSIGN, "true", NULL, temp);
        
        // Create and return a new symbol
        result = (Symbol*)malloc(sizeof(Symbol));
        result->name = temp;
        result->type = TYPE_BOOL;
        result->kind = KIND_VAR;
        result->declared = true;
        result->initialized = true;
        result->constant = false;
        result->value = NULL;
        result->scope = NULL;
        result->next = NULL;
        
        return result;
    }
    
    // For logical operations like AND, OR
    if (op != OP_NOT) {
        if (arg1->type != TYPE_BOOL || arg2->type != TYPE_BOOL) {
            yyerror("Invalid type for logical operation");
            return NULL;
        }
        
        temp = quad_new_temp(handler, TYPE_BOOL);
        quad_add(handler, op, arg1->name, arg2->name, temp);
    }
    // For NOT operation
    else {
        if (arg1->type != TYPE_BOOL) {
            yyerror("Invalid type for logical NOT operation");
            return NULL;
        }
        
        temp = quad_new_temp(handler, TYPE_BOOL);
        quad_add(handler, op, arg1->name, NULL, temp);
    }
    
    // Create and return a new symbol
    result = (Symbol*)malloc(sizeof(Symbol));
    result->name = temp;
    result->type = TYPE_BOOL;
    result->kind = KIND_VAR;
    result->declared = true;
    result->initialized = true;
    result->constant = false;
    result->value = NULL;
    result->scope = NULL;
    result->next = NULL;
    
    return result;
}

// Generate quad for assignment
void quad_gen_assign(QuadHandler *handler, Symbol *dest, Symbol *src) {
    // Check for NULL arguments
    if (!dest || !src) {
        return;
    }
    
    // Check for valid types
    if (dest->type == TYPE_VOID) {
        yyerror("Cannot assign to void type");
        return;
    }
    
    if (src->type == TYPE_VOID) {
        yyerror("Cannot assign void type");
        return;
    }
    
    // For now, simple assignment without type checking
    quad_add(handler, OP_ASSIGN, src->name, NULL, dest->name);
}

// Generate quad for unary operation
Symbol* quad_gen_unary(QuadHandler *handler, QuadOp op, Symbol *arg) {
    if (arg->type != TYPE_INT && arg->type != TYPE_FLOAT) {
        yyerror("Invalid type for unary operation");
        return NULL;
    }
    
    char *temp = quad_new_temp(handler, arg->type);
    
    // For unary operations like -a, we use SUB with 0 as first operand
    if (op == OP_SUB) {
        quad_add(handler, op, "0", arg->name, temp);
    } else {
        quad_add(handler, op, arg->name, NULL, temp);
    }
    
    // Create and return a new symbol
    Symbol *result = (Symbol*)malloc(sizeof(Symbol));
    result->name = temp;
    result->type = arg->type;
    result->kind = KIND_VAR;
    result->declared = true;
    result->initialized = true;
    result->constant = false;
    result->value = NULL;
    result->scope = NULL;
    result->next = NULL;
    
    return result;
}

// Print all quadruples to the output file
void quad_print(QuadHandler *handler) {
    if (!handler || !handler->output_file) return;
    
    // Rewind to beginning of the file
    rewind(handler->output_file);
    
    // Print all quadruples again (in case they were not printed immediately)
    Quadruple *current = handler->first;
    while (current) {
        fprintf(handler->output_file, "%s", op_names[current->op]);
        
        if (current->arg1) fprintf(handler->output_file, " %s", current->arg1);
        if (current->arg2) fprintf(handler->output_file, " %s", current->arg2);
        if (current->result) fprintf(handler->output_file, " %s", current->result);
        
        fprintf(handler->output_file, "\n");
        current = current->next;
    }
}