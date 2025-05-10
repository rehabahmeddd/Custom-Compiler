#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_STRING,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_VOID
} DataType;

typedef enum {
    KIND_VAR,
    KIND_FUNCTION,
    KIND_PARAMETER
} VarKind;

typedef union {
    int i_val;
    float f_val;
    double d_val;
    char* s_val;
    char c_val;
    bool b_val;
} Value;

typedef struct Symbol {
    char* name;
    DataType type;
    VarKind kind;
    bool declared;
    bool initialized;
    bool constant;
    void* value;

    struct Scope* scope;  // The scope in which the symbol is defined
    struct Symbol* next;  // Linked list of symbols in the same scope
} Symbol;

typedef struct Scope {
    struct Scope* parent;
    struct Scope* children;
    struct Scope* sibling;
    Symbol* symbols;
} Scope;

// Scope management
Scope* create_scope(Scope* parent);
void enter_scope(Scope** current_scope);
void leave_scope(Scope** current_scope);

// Symbol table operations
Symbol* insert_symbol(Scope* scope, const char* name, DataType type, VarKind kind, bool constant);
Symbol* lookup_symbol(Scope* scope, const char* name); // Lookup in current + parent scopes
Symbol* find_symbol(const char* name);                 // Global lookup
bool is_declared(const char* name);
void set_initialized(const char* name);

// Type-safe setter with semantic check
void set_value(const char* name, DataType type, void* value);

// Utility
void print_scope(Scope* scope, int depth);

//Free
void free_symbol(Symbol* sym);
void free_scope(Scope* scope);
#endif
