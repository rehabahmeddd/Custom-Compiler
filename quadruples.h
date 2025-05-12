#ifndef QUADRUPLES_H
#define QUADRUPLES_H

// Operation codes for quadruples
typedef enum {
    OP_ADD,        // +
    OP_SUB,        // -
    OP_MUL,        // *
    OP_DIV,        // /
    OP_MOD,        // %
    OP_NEG,        // Unary minus
    OP_ASSIGN,     // =
    OP_LT,         // <
    OP_GT,         // >
    OP_LE,         // <=
    OP_GE,         // >=
    OP_EQ,         // ==
    OP_NEQ,        // !=
    OP_AND,        // &&
    OP_OR,         // ||
    OP_NOT,        // !
    OP_LABEL,      // Label for jump targets
    OP_JMP,        // Unconditional jump
    OP_JMPT,       // Jump if true
    OP_JMPF,       // Jump if false
    OP_PARAM,      // Function parameter
    OP_CALL,       // Function call
    OP_RETURN,     // Return from function
    OP_ALLOCATE    // Variable allocation
} QuadOpCode;

// Quadruple structure
typedef struct {
    QuadOpCode op;     // Operation code
    char* arg1;        // First argument
    char* arg2;        // Second argument
    char* result;      // Result
} Quadruple;

// Declare external variables
extern Quadruple* quads;
extern int quad_count;

// Initialize the quadruple system
void init_quads();

// Generate a new quadruple
int gen_quad(QuadOpCode op, const char* arg1, const char* arg2, const char* result);

// Print all quadruples
void print_quads();

// Free quadruples memory
void free_quads();

// Label management functions
int generate_label();
void reset_label_counter();
void push_label(int label);
int pop_label();
int peek_label();
char* create_label_str(int label_num);

// Get string representation of operation
const char* get_op_name(QuadOpCode op);

#endif // QUADRUPLES_H