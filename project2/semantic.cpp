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
Variable_Type *checkFunc(AST *node, Type *type);
string checkID(AST *node);
void checkCompSt(AST *node, Type *type);
void checkDefList(AST *node);
void checkDef(AST *node);
void checkDecList(AST *node, Type *type);
void checkStmt(AST *node, Type *type);
void checkStmtList(AST *node, Type *type);
Variable_Type *checkDec(AST *node, Type *type);
Variable_Type *checkVarDec(AST *node, Type *type);
Type *checkExp(AST *node, bool single=false);
void updateVariable(Variable_Type *variable);
Variable_Type* getVariable(string name);

Variable_Type* getVariable(string identifier) {
    auto it = var_map.find(identifier);
    int count = var_map.count(identifier);
    assert(count <= 1);
    for (int i = 0, len = var_map.count(identifier);i < len; ++i,++it) {
		return it->second;
	}
    return NULL;
}

void updateVariable(Variable_Type *variable) {
    fprintf(stdout, "updateVariable\n");
    var_map.insert(make_pair(variable->name, variable));
}

void report_semantic_error(const char *s,...) {
    va_list args;
    va_start(args, s);
    vfprintf(stdout, s, args);
    fprintf(stdout, "\n");
}

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
    root->print();
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
        Variable_Type *func_variable = checkFunc(node->child[1], type);
        checkCompSt(node->child[2], type);
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

/**
 * FunDec: ID LP VarList RP
 * FunDec: ID LP RP
 */
Variable_Type *checkFunc(AST *node, Type *type) {
    DEBUG("checkFunc", node);
    assert(node->child[0]->type_name.compare("ID") == 0);
    assert(node->child[1]->type_name.compare("LP") == 0);
    string identifier = checkID(node->child[0]);
    if (node->child[2]->type_name.compare("VarList") == 0) {
        
    }
    if (node->child[2]->type_name.compare("RP") == 0) {
        return new Variable_Type(identifier, type, vector<Variable_Type*>(), true, node->lineno);
    } 
    assert(false && "checkFunc Failed");
}

string checkID(AST *node) {
    DEBUG("checkID", node);
    return node->type_name;
}

/**
 * CompSt: LC DefList StmtList RC
 */
void checkCompSt(AST *node, Type *type) {
    DEBUG("checkCompSt", node);
    assert(node->child[0]->type_name.compare("LC") == 0);
    assert(node->child[1]->type_name.compare("DefList") == 0);
    assert(node->child[2]->type_name.compare("StmtList") == 0);
    assert(node->child[3]->type_name.compare("RC") == 0);
    checkDefList(node->child[1]);
    checkStmtList(node->child[2], type);
    assert(false && "checkCompSt Failed");
}

/**
 * DefList: Def DefList
 * DefList: %empty
 */
void checkDefList(AST *node) {
    DEBUG("checkDefList", node);
    if (node->child_num == 0) {
        // DefList: %empty
        // assert(false && "checkDefList Failed");
        return;
    }
    assert(node->child[0]->type_name.compare("Def") == 0);
    assert(node->child[1]->type_name.compare("DefList") == 0);
    checkDef(node->child[0]);
    checkDefList(node->child[1]);
}

/**
 * Specifier DecList SEMI
 */
void checkDef(AST *node) {
    DEBUG("checkDef", node);
    assert(node->child[0]->type_name.compare("Specifier") == 0);
    assert(node->child[1]->type_name.compare("DecList") == 0);
    assert(node->child[2]->type_name.compare("SEMI") == 0);
    Type *type = checkSpecifier(node->child[0]);
    checkDecList(node->child[1], type);
    return;
}

/**
 * DecList: Dec
 * DecList: Dec COMMA DecList
 */
void checkDecList(AST *node, Type *type) {
    DEBUG("checkDecList", node);
    assert(node->child[0]->type_name.compare("Dec") == 0);
    if (node->child_num == 1) {
        Variable_Type *variable = checkDec(node->child[0], type);
        return;
    } else if (node->child_num == 3) {

    }
    assert(false && "checkDecList Failed");
}

/**
 * Dec: VarDec
 * Dec: VarDec ASSIGN Exp
 */
Variable_Type *checkDec(AST *node, Type *type) {
    DEBUG("checkDec", node);
    assert(node->child[0]->type_name.compare("VarDec") == 0);
    Variable_Type *variable = checkVarDec(node->child[0], type);
    if (node->child_num == 1) {
        // Dec: VarDec
        assert(false && "checkDec Failed");
    } else if (node->child_num == 3) {
        // Dec: VarDec ASSIGN Exp
        assert(node->child[1]->type_name.compare("ASSIGN") == 0);
        assert(node->child[2]->type_name.compare("Exp") == 0);
        Type *returnType = checkExp(node->child[2]);
        if (!typecheck(type, returnType, true)) {
            report_semantic_error("Error type 5 at line %d: unmatching types on both sides of assignment operator", node->child[1]->lineno);
        } else {
            updateVariable(variable);
        }

    }
    return variable;
}

/**
 * VarDec: ID
 * VarDec: VarDec LB INT RB
 */
Variable_Type *checkVarDec(AST *node, Type *type) {
    DEBUG("checkVarDec", node);
    if (node->child_num == 1) {
        assert(node->child[0]->type_name.compare("ID") == 0);
        string identifier = checkID(node->child[0]);
        return new Variable_Type(identifier, type, {}, 0, node->lineno);
    } else if (node->child_num == 4) {
        assert(node->child[0]->type_name.compare("VarDec") == 0);
        assert(node->child[1]->type_name.compare("LB") == 0);
        assert(node->child[2]->type_name.compare("INT") == 0);
        assert(node->child[3]->type_name.compare("RB") == 0);
    }
    assert(false && "checkVarDec Failed");
}

Type *checkExp(AST *node, bool single) {
    DEBUG("checkVarDec", node);
    if (node->child_num == 1) {
        // ID | INT | FLOAT | CHAR
        if (node->child[0]->type_name.compare("INT") == 0) {
            return new Primitive_Type(TokenType::INT_T, node->lineno);
        }
        if (node->child[0]->type_name.compare("ID") == 0) {
            string identifier = checkID(node->child[0]);
            Variable_Type* variable = getVariable(identifier);
            assert(variable && "checkExp Failed");
            return variable->type;
            assert(false && "checkExp Failed");
        }
    }
    assert(false && "checkExp Failed");
}

/**
 * StmtList: Stmt StmtList
 * StmtList: %empty
 */
void checkStmtList(AST *node, Type *type) {
    DEBUG("checkStmtList", node);
    if (node->child_num == 0) {
        return;
    } else if (node->child_num == 2) {
        assert(node->child[0]->type_name.compare("Stmt") == 0);
        assert(node->child[1]->type_name.compare("StmtList") == 0);
        checkStmt(node->child[0], type);
        checkStmtList(node->child[1], type);
        assert(false && "checkStmtList Failed");
    }
    assert(false && "checkStmtList Failed");
}

/**
 * Stmt: Exp SEMI
 * Stmt: CompSt
 * Stmt: RETURN Exp SEMI
 * Stmt: IF LP Exp RP Stmt
 * Stmt: WHILE LP Exp RP Stmt
 * Stmt: IF LP Exp RP Stmt ELSE Stmt
 */
void checkStmt(AST *node, Type *type) {
    DEBUG("checkStmt", node);
    if (node->child_num == 3) {
        assert(node->child[0]->type_name.compare("RETURN") == 0);
        assert(node->child[1]->type_name.compare("Exp") == 0);
        assert(node->child[2]->type_name.compare("SEMI") == 0);
        Type *returnType = checkExp(node->child[1]);
        if (!typecheck(returnType, type, true)){
            report_semantic_error("Error type 8 at line %d: the function’s return value type mismatches the declared type", node->child[0]->lineno);
        }
        return;
    }

    assert(false && "checkStmt Failed");
}
