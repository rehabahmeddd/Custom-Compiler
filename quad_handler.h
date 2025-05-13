#ifndef QUAD_HANDLER_H
#define QUAD_HANDLER_H

#include <stdio.h>
#include "symbol_table.h"

// Forward declarations
void yyerror(const char* s);

// Operation types for quadruples
typedef enum {
    OP_ADD,         // +                                                            
    OP_SUB,         // -
    OP_MUL,         // *
    OP_DIV,         // /
    OP_MOD,         // %
    OP_ASSIGN,      // =
    OP_LT,          // <
    OP_GT,          // >
    OP_EQ,          // ==
    OP_NEQ,         // !=
    OP_LE,          // <=
    OP_GE,          // >=
    OP_AND,         // &&
    OP_OR,          // ||
    OP_NOT,         // !
    OP_LABEL,       // Label definition
    OP_GOTO,        // Unconditional jump
    OP_IF_TRUE,     // Conditional jump if true
    OP_IF_FALSE,    // Conditional jump if false
    OP_FUNC_BEGIN,  // Function declaration start
    OP_FUNC_END,    // Function declaration end
    OP_CALL,        // Function call
    OP_PARAM,       // Function parameter
    OP_RETURN       // Function return
} QuadOp;

// String representation of operations
extern const char* op_names[];

// Quadruple structure
typedef struct Quadruple {
    QuadOp op;             
    char *arg1;            
    char *arg2;            
    char *result;          
    struct Quadruple *next;
} Quadruple;

// Quad handler structure
typedef struct QuadHandler {
    Quadruple *first;      
    Quadruple *last;       
    int temp_count;        
    int label_count;      
    FILE *output_file;     
} QuadHandler;

// Initialize the quad handler
QuadHandler* quad_init(const char *filename);

// Clean up the quad handler
void quad_cleanup(QuadHandler *handler);

// Generate a new temporary variable name
char* quad_new_temp(QuadHandler *handler, DataType type);

// Generate a new label
char* quad_new_label(QuadHandler *handler);

// Add a quadruple
void quad_add(QuadHandler *handler, QuadOp op, const char *arg1, const char *arg2, const char *result);

// Add a label quadruple
void quad_add_label(QuadHandler *handler, const char *label);

// Add an unconditional jump
void quad_add_goto(QuadHandler *handler, const char *label);

// Add a conditional jump
void quad_add_if_jump(QuadHandler *handler, const char *condition, const char *label, int if_true);

// Add a function declaration
void quad_add_func_begin(QuadHandler *handler, const char *func_name);

// Add a function end
void quad_add_func_end(QuadHandler *handler);

// Add a function call
void quad_add_call(QuadHandler *handler, const char *func_name, int param_count, const char *result);

// Add a function parameter
void quad_add_param(QuadHandler *handler, const char *param);

// Add a function return
void quad_add_return(QuadHandler *handler, const char *value);

// Generate quad for arithmetic operation
Symbol* quad_gen_math(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2);

// Generate quad for relational operation
Symbol* quad_gen_rel(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2);

// Generate quad for logical operation
Symbol* quad_gen_logic(QuadHandler *handler, QuadOp op, Symbol *arg1, Symbol *arg2);

// Generate quad for assignment
void quad_gen_assign(QuadHandler *handler, Symbol *dest, Symbol *src);

// Generate quad for unary operation
Symbol* quad_gen_unary(QuadHandler *handler, QuadOp op, Symbol *arg);

// Print all quadruples to the output file
void quad_print(QuadHandler *handler);

#endif // quad_new_temp