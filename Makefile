# Compiler and tools
CC = gcc
FLEX = flex
BISON = bison

# File names
LEX_FILE = lexer.l
YACC_FILE = parser.y
LEX_C = lex.yy.c
YACC_C = y.tab.c
YACC_H = y.tab.h
LEX_O = lex.yy.o
YACC_O = y.tab.o
EXEC = output

# Default rule
all: $(EXEC)

# Compile Flex and Bison
$(LEX_C): $(LEX_FILE)
	$(FLEX) $(LEX_FILE)

$(YACC_C): $(YACC_FILE)
	$(BISON) -d $(YACC_FILE)

# Compile object files
$(LEX_O): $(LEX_C)
	$(CC) -c $(LEX_C)

$(YACC_O): $(YACC_C)
	$(CC) -c $(YACC_C)

# Link objects to create executable
$(EXEC): $(LEX_O) $(YACC_O)
	$(CC) -o $(EXEC) $(LEX_O) $(YACC_O)

# Clean up
clean:
	rm -f $(LEX_C) $(YACC_C) $(YACC_H) $(LEX_O) $(YACC_O) $(EXEC)