# Compiler and tools
CC      = gcc
FLEX    = flex
BISON   = bison

# Source files
LEX_SRC     = lexer.l
YACC_SRC    = parser.y

# Generated files
LEX_C       = lex.yy.c
YACC_C      = parser.tab.c
YACC_H      = parser.tab.h

# Output executable
OUTPUT      = outputfile

# Default target
all: $(OUTPUT)

# Generate lexer file
$(LEX_C): $(LEX_SRC)
	$(FLEX) $(LEX_SRC)

# Generate parser files
$(YACC_C): $(YACC_SRC)
	$(BISON) $(YACC_SRC)

# Compile and link to create the executable
$(OUTPUT): $(LEX_C) $(YACC_C)
	$(CC) -o $(OUTPUT) $(LEX_C) $(YACC_C)

# Clean generated and compiled files
clean:
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(OUTPUT)
