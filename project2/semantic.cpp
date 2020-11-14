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
vector<Variable_Type*> checkVarList(AST *node);
Variable_Type * checkParamDec(AST *node);
vector<Type*> checkArgs(AST *node);

Variable_Type* getVariable(string identifier) {
    auto it = var_map.find(identifier);
    int count = var_map.count(identifier);
    if (count == 0) {
        return NULL;
    }
    assert(count == 1);
    for (int i = 0, len = var_map.count(identifier);i < len; ++i,++it) {
		return it->second;
	}
    return NULL;
}

void updateVariable(Variable_Type *variable) {
    printf("updateVariable %s\n", variable->name.c_str());
    Variable_Type *var = getVariable(variable->name);
    if (!var) {
        var_map.insert(make_pair(variable->name, variable));
    } else {
        if (var->isfunction == true) {
            semantic_error(SemanticErrorType::REDEFINED_FUNCTION, variable->lineno, variable->name.c_str());
        } else {
            semantic_error(SemanticErrorType::REDEFINED_VARIABLE, variable->lineno, variable->name.c_str());
        }
        
    }
}

void report_semantic_error(const char *s,...) {
    va_list args;
    va_start(args, s);
    vfprintf(stdout, s, args);
    fprintf(stdout, "\n");
}

void semantic_error(SemanticErrorType error_type, int line_num, ...) {
    va_list args;
    va_start(args, line_num);
    switch (error_type){ 
        case SemanticErrorType::UNDEFINED_VARIABLE:
            fprintf(stdout, "Error type 1 at Line %d: undefined variable: ", line_num);
            vfprintf(stdout, "%s", args);
            break;
        case SemanticErrorType::UNDEFINED_FUNCTION:
            fprintf(stdout, "Error type 2 at Line %d: undefined function: ", line_num);
            vfprintf(stdout, "%s", args);
            break;
        case SemanticErrorType::REDEFINED_VARIABLE:
            fprintf(stdout, "Error type 3 at Line %d: redefine variable: ", line_num);
            vfprintf(stdout, "%s", args);
            break;
        case SemanticErrorType::REDEFINED_FUNCTION:
            fprintf(stdout, "Error type 4 at Line %d: redefine function: ", line_num);
            vfprintf(stdout, "%s", args);
            break;
        case SemanticErrorType::UNMATCHING_TYPE_OF_ASSIGNMENT:
            fprintf(stdout, "Error type 5 at Line %d: unmatching type on both sides of assignment", line_num);
            break;
        default:
            assert(false);
            break;
    }
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
        updateVariable(func_variable);
        return;
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
        vector<Variable_Type *> variables = checkVarList(node->child[2]);
        // printf("function %s has", node->value.c_str());
        // for (auto i : variables) {
        //     printf(" %s,", i->name.c_str());
        // }
        // printf("\n");
        return new Variable_Type(identifier, type, variables, true, node->lineno);
    }
    if (node->child[2]->type_name.compare("RP") == 0) {
        return new Variable_Type(identifier, type, vector<Variable_Type*>(), true, node->lineno);
    } 
    assert(false && "checkFunc Failed");
}

string checkID(AST *node) {
    DEBUG("checkID", node);
    return node->value;
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
    return;
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
        updateVariable(variable);
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
        if (node->child[0]->type_name.compare("FLOAT") == 0) {
            return new Primitive_Type(TokenType::FLOAT_T, node->lineno);
        }
        if (node->child[0]->type_name.compare("ID") == 0) {
            string identifier = checkID(node->child[0]);
            Variable_Type* variable = getVariable(identifier);
            if (!variable) {
                semantic_error(SemanticErrorType::UNDEFINED_VARIABLE, node->lineno, identifier.c_str());
                return EMPTYTYPE;
            }
            assert(variable && "checkExp Failed");
            return variable->type;
            assert(false && "checkExp Failed");
        }
    } else if (node->child_num == 2) {
        // MINUS Exp
        // NOT Exp
        assert(node->child[1]->type_name.compare("Exp") == 0);
        if (node->child[0]->type_name.compare("MINUS") == 0) {
            Type *returnType = checkExp(node->child[1]);
            return returnType;
        } else if (node->child[0]->type_name.compare("NOT") == 0) {
            assert(false && "checkExp Failed");
        } 
    } else if (node->child_num == 3) {
        // Exp ASSIGN Exp
        if (node->child[1]->type_name.compare("ASSIGN") == 0) {
            assert(node->child[0]->type_name.compare("Exp") == 0);
            assert(node->child[2]->type_name.compare("Exp") == 0);
            Type *targetType = checkExp(node->child[0]);
            Type *returnType = checkExp(node->child[2]);
            if (!typecheck(targetType, returnType)) {
                semantic_error(SemanticErrorType::UNMATCHING_TYPE_OF_ASSIGNMENT, node->child[1]->lineno);
            }
            return EMPTYTYPE;
        }
        // Exp AND Exp
        // Exp OR Exp
        // Exp LT Exp
        // Exp LE Exp
        // Exp GT Exp
        // Exp GE Exp
        // Exp NE Exp
        // Exp EQ Exp
        // Exp PLUS Exp
        // Exp MINUS Exp
        // Exp MUL Exp
        // Exp DIV Exp
        if (node->child[2]->type_name.compare("Exp") == 0) {
            assert(node->child[0]->type_name.compare("Exp") == 0);
            Type *expType1 = checkExp(node->child[0]);
            Type *expType2 = checkExp(node->child[2]);
            assert(typecheck(expType1, expType2, true));
            return expType1;
        }
        // LP Exp RP
        // ID LP RP
        // Exp DOT ID
        assert(false && "checkExp Failed");
    } else if (node->child_num == 4) {
        if (node->child[0]->type_name.compare("ID") == 0) {
            // ID LP Args RP
            assert(node->child[1]->type_name.compare("LP") == 0);
            assert(node->child[2]->type_name.compare("Args") == 0);
            assert(node->child[3]->type_name.compare("RP") == 0);
            string identifier = checkID(node->child[0]);
            Variable_Type *func_variable = getVariable(identifier);
            if (!func_variable) {
                semantic_error(SemanticErrorType::UNDEFINED_FUNCTION, node->lineno, identifier.c_str());
                return EMPTYTYPE;
            }
            assert(func_variable->isfunction == true);
            vector<Type*> args_types = checkArgs(node->child[2]);
            assert(args_types.size() == func_variable->args.size());
            for (int i = 0; i < args_types.size(); i++) {
                assert(typecheck(args_types[i], func_variable->args[i]->type));
            }
            return func_variable->type;
        } else if (node->child[0]->type_name.compare("Exp") == 0) {
            // Exp LB Exp RB
            assert(false && "checkExp Failed");
        }
        assert(false && "checkExp Failed");

        
    }
    printf("node->child_num = %d\n", node->child_num);
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
        return;
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
    if (node->child_num == 1) {
        // CompSt
        assert(node->child[0]->type_name.compare("CompSt") == 0);
        checkCompSt(node->child[0], type);
        return;
    } else if (node->child_num == 2) {
        // Exp SEMI
        assert(node->child[0]->type_name.compare("Exp") == 0);
        assert(node->child[1]->type_name.compare("SEMI") == 0);
        checkExp(node->child[0]);
        return;
    } else if (node->child_num == 3) {
        // RETURN Exp SEMI
        assert(node->child[0]->type_name.compare("RETURN") == 0);
        assert(node->child[1]->type_name.compare("Exp") == 0);
        assert(node->child[2]->type_name.compare("SEMI") == 0);
        Type *returnType = checkExp(node->child[1]);
        if (!typecheck(returnType, type, true)){
            report_semantic_error("Error type 8 at line %d: the function’s return value type mismatches the declared type", node->child[0]->lineno);
        }
        return;
    } else if (node->child_num == 5) {
        // IF LP Exp RP Stmt
        if (node->child[0]->type_name.compare("IF") == 0) {
            assert(node->child[0]->type_name.compare("IF") == 0);
            assert(node->child[1]->type_name.compare("LP") == 0);
            assert(node->child[2]->type_name.compare("Exp") == 0);
            assert(node->child[3]->type_name.compare("RP") == 0);
            assert(node->child[4]->type_name.compare("Stmt") == 0);
            Type *returnType = checkExp(node->child[2]);
            assert(typecheck(returnType, new Primitive_Type(TokenType::INT_T)) == true);
            checkStmt(node->child[4], type);
            return;
        } else if (node->child[0]->type_name.compare("WHILE") == 0) {
            assert(false && "checkStmt Failed");
        }
        assert(false && "checkStmt Failed");
    } else if (node->child_num == 7) {
        // IF LP Exp RP Stmt ELSE Stmt
        assert(node->child[0]->type_name.compare("IF") == 0);
        assert(node->child[1]->type_name.compare("LP") == 0);
        assert(node->child[2]->type_name.compare("Exp") == 0);
        assert(node->child[3]->type_name.compare("RP") == 0);
        assert(node->child[4]->type_name.compare("Stmt") == 0);
        assert(node->child[5]->type_name.compare("ELSE") == 0);
        assert(node->child[6]->type_name.compare("Stmt") == 0);
        Type *returnType = checkExp(node->child[2]);
        assert(typecheck(returnType, new Primitive_Type(TokenType::INT_T)) == true);
        checkStmt(node->child[4], type);
        checkStmt(node->child[6], type);
        return;
    }
    printf("node->child_num == %d\n", node->child_num);
    assert(false && "checkStmt Failed");
}

/**
 * VarList: ParamDec COMMA VarList
 * VarList: ParamDec
 */
vector<Variable_Type*> checkVarList(AST *node) {
    DEBUG("checkStmt", node);
    assert(node->child[0]->type_name.compare("ParamDec") == 0);
    vector<Variable_Type*> variables = vector<Variable_Type*>();
    Variable_Type *variable = checkParamDec(node->child[0]);
    variables.push_back(variable);
    if (node->child_num == 1) {
        return variables;
    } else if (node->child_num == 3) {
        assert(node->child[1]->type_name.compare("COMMA") == 0);
        assert(node->child[2]->type_name.compare("VarList") == 0);
        vector<Variable_Type*> next_variables = checkVarList(node->child[2]);
        // merge variables
        variables.insert(variables.end(), next_variables.begin(), next_variables.end());
        return variables;
    }
    assert(false && "checkStmt Failed");
}

/**
 * ParamDec: Specifier VarDec
 */
Variable_Type *checkParamDec(AST *node) {
    DEBUG("checkParamDec", node);
    assert(node->child[0]->type_name.compare("Specifier") == 0);
    assert(node->child[1]->type_name.compare("VarDec") == 0);
    Type *type = checkSpecifier(node->child[0]);
    Variable_Type *variable = checkVarDec(node->child[1], type);
    updateVariable(variable);
    return variable;
}

/**
 * Args: Exp COMMA Args
 * Args: Exp
 */
vector<Type*> checkArgs(AST *node) {
    DEBUG("checkArgs", node);
    assert(node->child[0]->type_name.compare("Exp") == 0);
    vector<Type*> types = vector<Type*>();
    Type *type = checkExp(node->child[0]);
    types.push_back(type);
    if (node->child_num == 1) {
        return types;
    } else if (node->child_num == 3) {
        assert(node->child[1]->type_name.compare("COMMA") == 0);
        assert(node->child[2]->type_name.compare("Args") == 0);
        vector<Type*> next_types = checkArgs(node->child[2]);
        // merge variables
        types.insert(types.end(), next_types.begin(), next_types.end());
        return types;
    }
    assert(false && "checkArgs Failed");
}
