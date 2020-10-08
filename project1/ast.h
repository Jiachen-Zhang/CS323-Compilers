#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

#define INDENT_NUM 2

FILE *filein, *fileout;

typedef struct ast{//defaut 0
    char *type;
    int token_type; //non_terminal, token_with_value, token_without_value
    char* value;
    int child_num;
    struct ast **child;
    int lineno;
} ast;

typedef enum TokenType
{
    NONE_TERMINAL, TOKEN_WITH_VALUE, TOKEN_WITHOUT_VALUE
} TokenType;

//TYPE: value, ID: value
//INT: value, CHAR: value, FLOAT: value

ast *new_ast(char *type, int token_type, char *name, int lineno, int child_num, ...);

void print_ast(ast *a, int tabnum);

void indent(int n);

void free_ast(ast *a);

typedef struct ASTNode{
	char *node_name;
    TokenType node_type;
    char *node_value;
    int line_num;
    int child_num;
    struct ASTNode** children;
}ASTNode;

/** creat a ASTNode with children */
ASTNode *new_ast_node(char *node_name, TokenType node_type, char *node_value, 
                    int line_num, int child_num, ...);
/** free all the nodes connected with the specific ast node */
void free_ast_node(ASTNode *astNode);
/** print all the nodes connected with the specific ast node, with the indent num spaces */
void print_ast_node(ASTNode *astNode, int indent_num);
