/* utils.h - Utility functions for the compiler */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symbol_table.h"

// Convert an integer to a string
char* int_to_str(int value);

// Convert a float to a string
char* float_to_str(float value);

// Convert a double to a string
char* double_to_str(double value);

// Convert a boolean to a string
char* bool_to_str(int value);

DataType infer_expr_type(Scope* current_scope, char* expr);

extern const char* dataTypeName[];

bool areTypesCompatibleForOp(DataType left, DataType right, const char* op);


#endif /* UTILS_H */