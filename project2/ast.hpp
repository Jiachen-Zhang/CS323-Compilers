#include<bits/stdc++.h>

using namespace std;
#define INDENT_NUM 2

enum class symbolType {
    NONTERMINAL = 1,
    TOKEN_VALUE = 2,
    TOKEN = 3
};

class ast
{
    public:
        string type_name;
        symbolType symbol_type;
        string value;
        int child_num;
        int lineno;
        vector<ast *> child;

        ast(string type_name, symbolType symbol_type, string value, int lineno, int child_num, ...);
        void print(int tabnum);
};

void indent(int tabnum);
string to_str(int x);
