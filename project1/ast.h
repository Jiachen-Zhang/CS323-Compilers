#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

FILE *filein,*fileout;

typedef struct ast{//defaut 0
    char *type;
    int token_type; //non_terminal, token_with_value, token_without_value
    char* value;
    int child_num;
    struct ast **child;
    int lineno;
} ast;

//TYPE: value, ID: value
//INT: value, CHAR: value, FLOAT: value

ast *new_ast(char *type, int token_type, char *name, int lineno, int child_num, ...);

void print_ast(ast *a, int tabnum);

void indent(int n);

void free_ast(ast *a);