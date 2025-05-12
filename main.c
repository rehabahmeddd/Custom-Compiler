#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "quadruples.h"

// External declarations from generated parser
extern FILE* yyin;
extern int yyparse();
extern Scope* global_scope;
extern Scope* current_scope;

void print_usage() {
    printf("Usage: compiler <input_file>\n");
}

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc != 2) {
        print_usage();
        return 1;
    }
    
    // Open the input file
    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file %s\n", argv[1]);
        return 1;
    }
    
    // Set input for lexer
    yyin = input_file;
    
    // Initialize compiler components
    init_quadruples();
    global_scope = create_scope(NULL);
    current_scope = global_scope;
    
    printf("Compiling file: %s\n\n", argv[1]);
    
    // Parse the input file
    int parse_result = yyparse();
    
    // Close the input file
    fclose(input_file);
    
    if (parse_result == 0) {
        printf("\nCompilation successful!\n");
        
        // Print the symbol table
        printf("\n---- SYMBOL TABLE ----\n");
        print_scope(global_scope, 0);
        
        // Print quadruples
        print_quadruples();
        
        // Optionally, save quadruples to a file
        FILE* quad_file = fopen("output.quad", "w");
        if (quad_file) {
            // Redirect stdout temporarily
            FILE* old_stdout = stdout;
            stdout = quad_file;
            
            print_quadruples();
            
            // Restore stdout
            stdout = old_stdout;
            fclose(quad_file);
            printf("\nQuadruples saved to output.quad\n");
        }
    } else {
        printf("\nCompilation failed with errors.\n");
    }
    
    // Free resources
    free_quadruples();
    free_scope(global_scope);
    
    return parse_result;
}