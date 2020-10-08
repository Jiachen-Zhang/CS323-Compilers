#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include "ast.h"

ast *new_ast(char *type, int token_type, char *value, int lineno, int child_num, ...){
    ast *a = malloc(sizeof(ast));

    a->type = type;
    a->token_type = token_type;
    a->value = value;
    a->lineno = lineno;
    a->child = NULL;
    a->child_num = child_num;
    if (child_num)
    {
        a->child = malloc(sizeof(ast *) * child_num);
    }

    va_list args;
    va_start(args, child_num);

    for (ast **p = a->child; child_num--;++p)
    {
        *p = va_arg(args, ast *);
    }
    return a;
}


void print_ast(ast *a, int tabnum){
    if (a->token_type == 1)
    { //nonterminal
        if (a->child) {//printed only if has a child
            indent(tabnum);
            fprintf(fileout,"%s (%d)\n", a->type, a->lineno);
        }
    }
    else if (a->token_type == 2){//token_with_value
        indent(tabnum);
        fprintf(fileout,"%s: %s\n", a->type, a->value);
    }
    else{ //token_without_value
        indent(tabnum);
        fprintf(fileout,"%s\n",a->type);
    }
    for (int i = 0; i < a->child_num;++i)
    {
        print_ast(a->child[i], tabnum + 2);
    }
}

void print_symbol(char *s, int tabnum){
    indent(tabnum);
    fprintf(fileout, "%s", s);
}

void indent(int n){
    while (n--){
        fprintf(fileout," ");
    }
}

void free_ast(ast *a){
    for (int i = 0; i < a->child_num;++i)
    {
        free_ast(a->child[i]);
    }
    free(a);
}


/** creat a ASTNode with children */
ASTNode *new_ast_node(char *node_name, TokenType node_type, char *node_value, 
                    int line_num, int child_num, ...) {
    ASTNode *astNode = malloc(sizeof(ast));
    astNode->node_name = node_name;
    astNode->node_type = node_type;
    astNode->node_value = node_value;
    astNode->line_num = line_num;
    astNode->child_num = child_num;
    if (child_num)
        astNode->children = malloc(sizeof(ast *) * child_num);
    else
        astNode->children = NULL;
    va_list args;
    va_start(args, child_num);
    for (ASTNode **p = astNode->children; child_num--;++p)
        *p = va_arg(args, ASTNode *);
    return astNode;
}
/** free all the nodes connected with the specific ast node */
void free_ast_node(ASTNode *astNode) {
    for (int i = 0; i < astNode->child_num;++i)
        free_ast_node(astNode->children[i]);
    free(astNode);
}
/** print all the nodes connected with the specific ast node, with the indent num spaces */
void print_ast_node(ASTNode *astNode, int indent_num) {
    fprintf(stdout, "START PRINT\n");
    if (astNode->node_type == NONE_TERMINAL && astNode->children)
    { 
        fprintf(stdout, "NONE_TERMINAL\n");
        indent(indent_num);
        fprintf(fileout,"%s (%d)\n", astNode->node_name, astNode->line_num);
    } 
    else if (astNode->node_type == TOKEN_WITH_VALUE) 
    {
        fprintf(stdout, "TOKEN_WITH_VALUE\n");
        indent(indent_num);
        fprintf(fileout,"%s: %s\n", astNode->node_name, astNode->node_value);
    } 
    else if (astNode->node_type == TOKEN_WITHOUT_VALUE) 
    {
        fprintf(stdout, "TOKEN_WITHOUT_VALUE\n");
        indent(indent_num);
        fprintf(fileout,"%s\n",astNode->node_name);
    }
    for (int i = 0; i < astNode->child_num;++i)
    {
        print_ast_node(astNode->children[i], indent_num + INDENT_NUM);
    }
}