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