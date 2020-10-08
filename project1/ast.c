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
// int main()
// {
//     int 013 = 1;

//     return 0;
// }