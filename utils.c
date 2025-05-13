/* utils.c - Implementation of utility functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

// Convert an integer to a string
char* int_to_str(int value) {
    char* str = (char*)malloc(20); // Enough for 64-bit integers
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sprintf(str, "%d", value);
    return str;
}

// Convert a float to a string
char* float_to_str(float value) {
    char* str = (char*)malloc(30); // Enough for most floats with precision
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sprintf(str, "%f", value);
    return str;
}

// Convert a double to a string
char* double_to_str(double value) {
    char* str = (char*)malloc(30); // Enough for most doubles with precision
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sprintf(str, "%f", value);
    return str;
}

// Convert a boolean to a string
char* bool_to_str(int value) {
    return strdup(value ? "true" : "false");
}

DataType infer_expr_type(char* expr) {
    // You should improve this based on how you encode constants or temporaries
    if (strchr(expr, '.') != NULL) return TYPE_FLOAT;
    if (strcmp(expr, "true") == 0 || strcmp(expr, "false") == 0) return TYPE_BOOL;
    if (expr[0] == '"') return TYPE_STRING;
    if (expr[0] == '\'') return TYPE_CHAR;
    if (expr[0] == 't' && isdigit(expr[1])) return TYPE_INT; // assuming temporaries default to int
    return TYPE_INT;
}

const char* dataTypeName[] = {
    "int",
    "float",
    "double",
    "string",
    "char",
    "bool",
    "void"
};

