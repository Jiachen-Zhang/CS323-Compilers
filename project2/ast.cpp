#include "ast.hpp"

using namespace std;

ast::ast(string type_name, symbolType symbol_type, string value, int lineno, int child_num, ...){
    this->type_name = type_name;
    this->symbol_type = symbol_type;
    this->value = value;
    this->child_num=child_num;
    this->child = vector<ast *>();
    this->lineno = lineno;

    va_list args;
    va_start(args, child_num);
    while (child_num--){
        ast *p = va_arg(args, ast *);
        this->child.push_back(p);
    }
}

void ast::print(int tabnum){
    switch (symbol_type) {
        case symbolType::NONTERMINAL:
            if (!child.empty()){
                indent(tabnum);
                fprintf(stdout, "%s (%d)\n", type_name, lineno);
            }
            break;
        case symbolType::TOKEN_VALUE:
            indent(tabnum);
            fprintf(stdout, "%s: %s\n", type_name, value.c_str());
            break;
        case symbolType::TOKEN:
            indent(tabnum);
            fprintf(stdout, "%s\n", type_name);
        default:
            throw 20;
    }
    for (auto it: child) {
        it->print(tabnum + 2);
    }
}

void indent(int tabnum){
    while (tabnum--)
        fprintf(stdout, " ");
}
