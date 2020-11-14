#include "semantic.hpp"

#define DEBUG(s, node) fprintf(stdout, "DEBUG: %20s | ", s); node->print_self();
#define ERROR(s, node) fprintf(stdout, "ERROR: %20s | ", s); node->print_self();

multimap<string, Variable_Type*> var_map = multimap<string, Variable_Type*>();
multimap<string, Structure_Type*> type_map = multimap<string, Structure_Type*>();
multimap<string, Variable_Type*> *container = &var_map;
void checkExtDefList(AST *node);
void checkExtDef(AST *node);
Type *checkSpecifier(AST *node);
Primitive_Type *checkType(AST *node);
Structure_Type *checkSructSpecifier(AST *node);

bool typecheck(Type *left, Type*right, bool weak) {
    if (*left==*EMPTYTYPE || *right==*EMPTYTYPE)
        return true;
    else if (weak && typeid(*left) == typeid(Primitive_Type) && typeid(*right) == typeid(Primitive_Type))
        return true;
    else
        return (*left == *right);
}
Type *EMPTYTYPE = new Type();
Variable_Type *EMPTYVAR = new Variable_Type("$", EMPTYTYPE);

void checkProgram(AST *root) {
    // root->print();
    DEBUG("checkProgram", root);
    checkExtDefList(root->child[0]);
}

void checkExtDefList(AST *node) {
    DEBUG("checkExtDefList", node);
    // ExtDefList: ExtDef ExtDefList
    // ExtDefList: %empty
    switch (node->child_num) {
        case 0: 
            return;
        case 2:
            assert(node->child.size() == 2);
            checkExtDef(node->child[0]);
            checkExtDefList(node->child[1]);
            break;
        default:
            assert(false && "checkExtDefList Failed");
    }
}

/**
 * ExtDef: Specifier ExtDecList SEMI
 * ExtDef: Specifier SEMI
 * ExtDef: Specifier FunDec CompSt
 */
void checkExtDef(AST *node) {
    DEBUG("checkExtDef", node);
    assert(node->child[0]->type_name.compare("Specifier") == 0);
    Type *type = checkSpecifier(node->child[0]);
    if (node->child[1]->type_name.compare("ExtDecList") == 0) {
        // ExtDef: Specifier ExtDecList SEMI
        assert(false && "ExtDef: Specifier ExtDecList SEMI");
    }
    if (node->child[1]->type_name.compare("SEMI") == 0) {
        // ExtDef: Specifier SEMI
        assert(false && "ExtDef: Specifier SEMI");
    }
    if (node->child[1]->type_name.compare("FunDec") == 0) {
        // ExtDef: Specifier FunDec CompSt
        assert(false && "ExtDef: Specifier FunDec CompSt");

    }
    assert(false && "checkExtDef Failed");
}

/**
 * Specifier: TYPE
 * Specifier: StructSpecifier
 */
Type *checkSpecifier(AST *node) {
    DEBUG("parseSpecifier", node);
    if (node->child[0]->type_name.compare("TYPE") == 0) {
        // Specifier: TYPE
        return checkType(node->child[0]);
    }
    if (node->child[0]->type_name.compare("StructSpecifier") == 0) {
        // Specifier: StructSpecifier
        return checkSructSpecifier(node->child[0]);
    }
}

Primitive_Type *checkType(AST *node) {
    DEBUG("checkType", node);
    if (node->value.compare("int") == 0) {
        return new Primitive_Type(TokenType::INT_T, node->lineno);
    }
    if (node->value.compare("float") == 0) {
        return new Primitive_Type(TokenType::FLOAT_T, node->lineno);
    }
    if (node->value.compare("char") == 0) {
        return new Primitive_Type(TokenType::CHAT_T, node->lineno);
    }
    assert(false && "checkType Failed");
}

Structure_Type *checkSructSpecifier(AST *node) {
    DEBUG("checkSructSpecifier", node);
    assert(false && "checkSructSpecifier Failed");
}