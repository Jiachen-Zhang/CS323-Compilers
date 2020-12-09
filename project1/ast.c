#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include "ast.h"

void indent(int n) {
    while (n-- > 0){
        fprintf(stdout, " ");
    }
    return;
}

/** creat a ASTNode with children */
ASTNode *new_ast_node(char *node_name, TokenType node_type, char *node_value, 
                    int line_num, int child_num, ...) {
    ASTNode *astNode = malloc(sizeof(ASTNode));
    astNode->node_name = node_name;
    astNode->node_type = node_type;
    astNode->node_value = node_value;
    astNode->line_num = line_num;
    astNode->child_num = child_num;
    if (child_num)
        astNode->children = malloc(sizeof(ASTNode *) * child_num);
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
    if (astNode->node_type == NONE_TERMINAL && astNode->children)
    { 
        indent(indent_num);
        fprintf(stdout,"%s (%d)\n", astNode->node_name, astNode->line_num);
    } 
    else if (astNode->node_type == TOKEN_WITH_VALUE) 
    {
        indent(indent_num);
        fprintf(stdout,"%s: %s\n", astNode->node_name, astNode->node_value);
    } 
    else if (astNode->node_type == TOKEN_WITHOUT_VALUE) 
    {
        indent(indent_num);
        fprintf(stdout,"%s\n",astNode->node_name);
    }
    for (int i = 0; i < astNode->child_num;++i)
    {
        print_ast_node(astNode->children[i], indent_num + INDENT_NUM);
    }
}