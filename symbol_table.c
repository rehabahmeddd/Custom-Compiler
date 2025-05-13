#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

static Scope* global_scope = NULL;


Scope* create_scope(Scope* parent) {
    Scope* scope = (Scope*)malloc(sizeof(Scope));
    scope->parent = parent;
    scope->children = NULL;
    scope->sibling = NULL;
    scope->symbols = NULL;
    if (parent) {
        if (!parent->children) parent->children = scope;
        else {
            Scope* sibling = parent->children;
            while (sibling->sibling) sibling = sibling->sibling;
            sibling->sibling = scope;
        }
    }
    return scope;
}

void enter_scope(Scope** current) {
    Scope* new_scope = create_scope(*current);
    *current = new_scope;
}

void leave_scope(Scope** current) {
    if (*current && (*current)->parent) {
        *current = (*current)->parent;
    }
}

Symbol* insert_symbol(Scope* scope, const char* name, DataType type, VarKind kind, bool constant) {
    // Check for existing symbol in current scope
    Symbol* currentSym = scope->symbols;
    while (currentSym != NULL) {
        if (strcmp(currentSym->name, name) == 0) {
            fprintf(stderr, "Error: Variable '%s' already declared in this scope.\n", name);
            exit(EXIT_FAILURE);  // Terminate the program
        }
        currentSym = currentSym->next;
    }

    // No conflict, insert new symbol
    Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->kind = kind;
    sym->declared = true;
    sym->initialized = false;
    sym->constant = constant;
    sym->scope = scope;
    sym->next = scope->symbols;
    scope->symbols = sym;
    sym->param_count = 0;
    sym->param_types = NULL;

    return sym;
}

Symbol* lookup_symbol(Scope* scope, const char* name) {
    while (scope) {
        Symbol* sym = scope->symbols;
        while (sym) {
            if (strcmp(sym->name, name) == 0) {
                // fprintf(stderr, "Found symbol '%s' in scope (pointer: %p).\n", name, (void*)sym);
                return sym;
            }
            sym = sym->next;
        }
        scope = scope->parent;
    }
    return NULL;
}



bool is_declared(Scope* current_scope,const char* name) {
    return lookup_symbol(current_scope,name) != NULL;
}

void set_initialized(Scope* current_scope, const char* name) {
    Symbol* sym = lookup_symbol(current_scope, name);
    //print sym the ptr
   // printf("Symbol pointer: %p\n", (void*)sym);

    if (sym) {
        sym->initialized = true;
        printf("Variable '%s' initialized.\n", name);
    }
 
}
/*void set_value(const char* name, VarType type, void* value) {
    Symbol* sym = find_symbol(name);
    if (!sym) {
        fprintf(stderr, "Semantic Error: Variable '%s' not declared.\n", name);
        return;
    }
    if (sym->constant) {
        fprintf(stderr, "Semantic Error: Cannot assign to constant '%s'.\n", name);
        return;
    }
    if (sym->type != type) {
        fprintf(stderr, "Semantic Error: Type mismatch in assignment to '%s'. Expected %d but got %d.\n",
                name, sym->type, type);
        return;
    }
    sym->initialized = true;
    switch (type) {
        case TYPE_INT:
            sym->value.i_val = *(int*)value;
            break;
        case TYPE_FLOAT:
            sym->value.f_val = *(float*)value;
            break;
        case TYPE_DOUBLE:
            sym->value.d_val = *(double*)value;
            break;
        case TYPE_STRING:
            sym->value.s_val = strdup((char*)value);
            break;
        case TYPE_CHAR:
            sym->value.c_val = *(char*)value;
            break;
        case TYPE_BOOL:
            sym->value.b_val = *(bool*)value;
            break;
        default:
            fprintf(stderr, "Semantic Error: Cannot assign value to void type '%s'.\n", name);
            break;
    }
}*/
/*void set_value(const char* name, DataType type, void* value) {
    Scope* current_scope;
    Symbol* symbol = lookup_symbol(current_scope, name);
    if (symbol) {
        symbol->value = value;
        symbol->type = type;
    }
}
void set_value(const char* name, DataType type, void* value) {
    Symbol* sym = find_symbol(name);
    if (!sym) return;

    switch (type) {
        case TYPE_INT:
            sym->value = malloc(sizeof(int));
            *((int*)sym->value) = *((int*)value);
            break;
        case TYPE_FLOAT:
            sym->value = malloc(sizeof(float));
            *((float*)sym->value) = *((float*)value);
            break;
        case TYPE_DOUBLE:
            sym->value = malloc(sizeof(double));
            *((double*)sym->value) = *((double*)value);
            break;
        case TYPE_STRING:
            sym->value = strdup((char*)value);
            break;
        case TYPE_CHAR:
            sym->value = malloc(sizeof(char));
            *((char*)sym->value) = *((char*)value);
            break;
        case TYPE_BOOL:
            sym->value = malloc(sizeof(bool));
            *((bool*)sym->value) = *((bool*)value);
            break;
        default:
            break;
    }
}*/

void set_value(Scope* current_scope,const char* name, DataType type, void* value) {
    Symbol* sym = lookup_symbol(current_scope, name); // Use current_scope instead of NULL if in context
    if (!sym) return;
    if (sym->type != type) {
        fprintf(stderr, "Type mismatch when assigning to %s\n", name);
        return;
    }

    switch (type) {
        case TYPE_INT:
            sym->value = malloc(sizeof(int));
            *(int*)(sym->value) = *(int*)value;
            break;
        case TYPE_FLOAT:
            sym->value = malloc(sizeof(float));
            *(float*)(sym->value) = *(float*)value;
            break;
        case TYPE_DOUBLE:
            sym->value = malloc(sizeof(double));
            *(double*)(sym->value) = *(double*)value;
            break;
        case TYPE_STRING:
            sym->value = strdup((char*)value);
            break;
        case TYPE_CHAR:
            sym->value = malloc(sizeof(char));
            *(char*)(sym->value) = *(char*)value;
            break;
        case TYPE_BOOL:
            sym->value = malloc(sizeof(bool));
            *(bool*)(sym->value) = *(bool*)value;
            break;
        default:
            break;
    }
}

void print_scope(Scope* scope, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("Scope:\n");
    for (Symbol* sym = scope->symbols; sym; sym = sym->next) {
        for (int i = 0; i < depth; i++) printf("  ");
        printf("  %s (%d)\n", sym->name, sym->type);
    }
    for (Scope* child = scope->children; child; child = child->sibling) {
        print_scope(child, depth + 1);
    }
}





Scope* get_global_scope() {
    return global_scope;
}

void free_symbol(Symbol* sym) {
    if (!sym) return;
    if (sym->value) free(sym->value);
    free(sym->name);
    free(sym);
}

//free scope
void free_scope(Scope* scope) {
    if (!scope) return;
    Symbol* sym = scope->symbols;
    while (sym) {
        Symbol* next = sym->next;
        free_symbol(sym);
        sym = next;
    }
    free_scope(scope->children);
    free_scope(scope->sibling);
    free(scope);
}

//get symbol name 
 const char* get_symbol_name(Symbol* sym) {
    if (!sym) return NULL;
    return sym->name;
}
//intilized getter
bool is_initialized(Scope* current_scope, const char* name) {
    Symbol* sym = lookup_symbol(current_scope,name);
    if (sym) {
        return sym->initialized;
    }
    return false;
}