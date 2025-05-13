# Compiler and tools
CC      = gcc
FLEX    = flex
BISON   = bison

# Source files
LEX_SRC     = lexer.l
YACC_SRC    = parser.y
SYMTAB_SRC  = symbol_table.c
UTILS_SRC   = utils.c
QUAD_SRC    = quad_handler.c

# Generated files
LEX_C       = lex.yy.c
YACC_C      = y.tab.c
YACC_H      = y.tab.h

# Object files
LEX_O       = lex.yy.o
YACC_O      = y.tab.o
SYMTAB_O    = symbol_table.o
UTILS_O     = utils.o
QUAD_O      = quad_handler.o

# Output executable
OUTPUT      = compiler

# Compiler flags
CFLAGS      = -Wall -g

# Default target
all: $(OUTPUT)

# Generate lexer file
$(LEX_C): $(LEX_SRC)
	$(FLEX) $(LEX_SRC)

# Generate parser files
$(YACC_C) $(YACC_H): $(YACC_SRC)
	$(BISON) -d -y $(YACC_SRC)

# Compile lexer
$(LEX_O): $(LEX_C) $(YACC_H)
	$(CC) $(CFLAGS) -c $(LEX_C) -o $(LEX_O)

# Compile parser
$(YACC_O): $(YACC_C)
	$(CC) $(CFLAGS) -c $(YACC_C) -o $(YACC_O)

# Compile symbol table
$(SYMTAB_O): $(SYMTAB_SRC)
	$(CC) $(CFLAGS) -c $(SYMTAB_SRC) -o $(SYMTAB_O)

# Compile utilities
$(UTILS_O): $(UTILS_SRC)
	$(CC) $(CFLAGS) -c $(UTILS_SRC) -o $(UTILS_O)

# Compile quad handler
$(QUAD_O): $(QUAD_SRC) quad_handler.h
	$(CC) $(CFLAGS) -c $(QUAD_SRC) -o $(QUAD_O)

# Link everything
$(OUTPUT): $(LEX_O) $(YACC_O) $(SYMTAB_O) $(UTILS_O) $(QUAD_O)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(LEX_O) $(YACC_O) $(SYMTAB_O) $(UTILS_O) $(QUAD_O) -lfl

# Clean generated and compiled files
clean:
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(LEX_O) $(YACC_O) $(SYMTAB_O) $(UTILS_O) $(QUAD_O) $(OUTPUT)

# Test with sample input
test: $(OUTPUT)
	./$(OUTPUT) sample.txt