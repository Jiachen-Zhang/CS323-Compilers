#include "ir.hpp"
const int INFO_SIZE = 100;
vector<TAC*> tacs;
map<string, int> table;
vector<int> con, br;

void init() {
    tacs.clear();
    table.clear();
    con.clear();
    br.clear();
    tacs.push_back(new TAC());
}

void irProgram(AST *root) {
    init();
    
    irExtDefList(root->child[0]);

    for (int i = 1; i < tacs.size(); ++i){
        sprintf("%s\n", tacs[i]->to_string().c_str());
    }
}

void irExtDefList(AST *node) {
    DEBUG("ExtDefList begin");
    while (node->child_num) {
        irExtDef(node->child[0]);
        node = node->child[1];
    }
    DEBUG("ExtDefList end");
}

void irExtDef(AST *node) {
    DEBUG("ExtDef begin");
    Type *type = irSpecifier(node->child[0]);
    if (node->child[1]->type_name.compare("ExtDecList") == 0) {
        irExtDecList(node->child[1], type);
    }
    if (node->child[1]->type_name.compare("FunDec") == 0){
        irFunDec(node->child[1], type);
        irCompSt(node->child[2]);
    }
    DEBUG("ExtDef end");
}

void irFunDec(AST *node, Type *type) {
    DEBUG("FunDec begin");
    string name = node->child[0]->value;
    int fundec = emit(new FunctionTAC(tacs.size(), name));
    insertIR(name, fundec);
    if (node->child[2]->type_name.compare("VarList") == 0) {
        irVarList(node->child[2]);
    }
    DEBUG("FunDec end");
}

void irVarList(AST *node) {
    DEBUG("VarList begin");
    vector<AST *> _stack = {node->child[0]};
    while (node->child_num > 1){
        node = node->child[2];
        _stack.push_back(node->child[0]);
    }
    while (!_stack.empty()){
        irParamDec(_stack.back());
        _stack.pop_back();
    }
    DEBUG("VarList end");
}

void irParamDec(AST *node){
    DEBUG("ParamDec begin");
    Type *type = irSpecifier(node->child[0]);
    TAC *tac = irVarDec(node->child[1], type);
    if (typeid(*tac)==typeid(AssignTAC)){
        insertIR(tac->name, emit(new ParamTAC(tacs.size(), type, {})));
    } else {
        insertIR(tac->name, emit(new ParamTAC(tacs.size(), type, dynamic_cast<DecTAC *>(tac)->sizes)));
    }
    DEBUG("ParamDec end");
}

void irExtDecList(AST *node, Type * type) {
    DEBUG("ExtDecList begin");
    TAC* tac = irVarDec(node->child[0], type);
    while (node->child_num>1){
        node = node->child[2];
        TAC* tac = irVarDec(node->child[0], type);
    }
    insertIR(tac->name, tac->emit());
    DEBUG("ExtDecList end");
}

TAC* irVarDec(AST *node, Type* type) {
    vector<AST *> _stack = {node};
    vector<int> sizes = vector<int>();
    string name;
    while (!_stack.empty()) {
        AST *top = _stack.back();
        if (top->child[0]->type_name.compare("ID") == 0) {
            name = top->child[0]->value;
            _stack.pop_back();
            while (!_stack.empty()){
                AST *p = _stack.back();
                _stack.pop_back();
                int size = parsePrimitive("INT", p->child[2]->value);
                sizes.push_back(size);
            }
        } else {
            _stack.push_back(top->child[0]);
        }
    }
    if (sizes.size()){
        return new DecTAC(tacs.size(), type, name, sizes);
    } else if (typeid(*type)==typeid(Structure_Type)){
        return new DecTAC(tacs.size(), type, name, {});
    } else {
        TAC *tac = new AssignTAC(tacs.size(), 0);
        tac->name = name;
        return tac;
    }
}

Type* irSpecifier(AST *node) {
    DEBUG("Specifier begin");
    Type *type;
    if (node->child[0]->type_name.compare("TYPE") == 0){
        type = irType(node->child[0]);
    }
    else{
        type = irStructSpecifier(node->child[0]);
    }
    DEBUG("Specifier end");
    return type;
}

Type* irType(AST *node) {
    return checkType(node);
}

Type* irStructSpecifier(AST *node) {
    return findType(node->child[1]->value);
}

Type *findType(string name){
    auto it = global_type_map.find(name);
    int cnt = global_type_map.count(name);
    assert(cnt == 1);
    Type *res = it->second;
    return res;
}


