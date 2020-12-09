#define INDENT_NUM 2

FILE *filein, *fileout;

typedef enum TokenType
{
    NONE_TERMINAL, TOKEN_WITH_VALUE, TOKEN_WITHOUT_VALUE
} TokenType;

typedef struct ASTNode{
	char *node_name;
    TokenType node_type;
    char *node_value;
    int line_num;
    int child_num;
    struct ASTNode** children;
}ASTNode;

void indent(int n);

/** creat a ASTNode with children */
ASTNode *new_ast_node(char *node_name, TokenType node_type, char *node_value, 
                    int line_num, int child_num, ...);
/** free all the nodes connected with the specific ast node */
void free_ast_node(ASTNode *astNode);
/** print all the nodes connected with the specific ast node, with the indent num spaces */
void print_ast_node(ASTNode *astNode, int indent_num);
