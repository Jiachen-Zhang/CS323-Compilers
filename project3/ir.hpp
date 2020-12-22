#include<bits/stdc++.h>
#include"semantic.hpp"
using namespace std;

class TAC;
enum class Operator;
extern const int INFO_SIZE;
extern vector<TAC *> tac_vector;
#define DEBUG(msg) fprintf(stdout, "%s\n", msg);

string addr_to_string(int addr){
    char buffer[INFO_SIZE];
    if (addr > 0){
        sprintf(buffer, "t%d", addr);
    } else{
        sprintf(buffer, "#%d", -addr);
    }
    return buffer;
}

enum class Operator {
    ADD_OPERATOR,
    SUB_OPERATOR,
    MUL_OPERATOR,
    DIV_OPERATOR,
    LE_OPERATOR,
    LT_OPERATOR,
    GE_OPERATOR,
    GT_OPERATOR,
    NE_OPERATOR,
    EQ_OPERATOR,
};

string operator_to_string(Operator op) {
    switch (op) {
        case Operator::ADD_OPERATOR: return "+";
        default: exit(-10);
    }
}

/* Translator Assembler Complier */
class TAC {
public:
    int address;
    bool is_swap = false;
    string name;
    Type *type;
    TAC() { is_swap = false; }
    TAC(int address) : address(address) {}
    virtual string to_string() { return ""; }
    virtual int emit(){
        int index = tac_vector.size();
        tac_vector.push_back(this);
        return index;
    }
};

class LabelTAC: public TAC {
public:
    LabelTAC(int address) {
        TAC::address = address;
    };
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "LABEL label%d :", TAC::address);
        return buffer;
    }
};

class FunctionTAC: public TAC {
public:
    FunctionTAC(int address, string name) {
        TAC::address = address;
        TAC::name = name;
    }

    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "FUNCTION %s :", TAC::name.c_str());
        return buffer;
    }
};

class AssignTAC: public TAC {
public:
    int right_address;
    AssignTAC(int address, int right_address) {
        this->right_address = right_address;
        TAC::address = address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "t%d := %s", TAC::address, addr_to_string(right_address).c_str());
        return buffer;
    }
};

class AssignAddressTAC: public TAC {
private:
    int right_address;
public:
    AssignAddressTAC(int address, int right_address) {
        this->right_address = right_address;
        TAC::address = address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "t%d := &t%d", TAC::address, right_address);
        return buffer;
    }
};

class AssignValueTAC: public TAC {
private:
    int right_address;
public:
    AssignValueTAC(int address, int right_address) {
        this->right_address = right_address;
        TAC::address = address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "t%d := *t%d", TAC::address, right_address);
        return buffer;
    }
};

class ArithmeticTAC: public TAC {
private:
    Operator op;
    int left_address;
    int right_address;
public:
    ArithmeticTAC(int address, Operator op, int left_address, int right_address) {
        TAC::address = address;
        this->op = op;
        this->left_address = left_address;
        this->right_address = right_address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "t%d := %s %s %s", TAC::address, addr_to_string(left_address).c_str(), operator_to_string(op).c_str(), addr_to_string(right_address).c_str());
        return buffer;
    }
};

class CopyToAddressTAC: public TAC {
public:
    int right_address;
    CopyToAddressTAC(int address, int right_address) {
        this->right_address = right_address;
        TAC::address = address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "*t%d := t%d", TAC::address, right_address);
        return buffer;
    }
};

class GoToTAC: public TAC {
public:
    int* label;
    GoToTAC(int address, int* label) {
        TAC::address = address;
        this->label = label;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "GOTO label%d", *label);
        return buffer;
    }
};

class IfTAC: public TAC {
private:
    Operator op;
    int left_address;
    int right_address;
public:
    int *label;
    IfTAC(int address, Operator op, int left_address, int right_address, int *label) {
        TAC::address = address;
        this->left_address = left_address;
        this->right_address = right_address;
        this->op = op;
        this->label = label;
    }
    
    string to_string() {
        // IF v1 > t2 GOTO label1
        char buffer[INFO_SIZE];
        sprintf(buffer, "IF v%d %s t%d GOTO label%d", left_address, operator_to_string(op).c_str(), right_address, *label);
        return buffer;
    }
};

class ReturnTAC: public TAC {
private:
    int right_address;
public:
    ReturnTAC(int address, int right_address) {
        TAC::address = address;
        this->right_address = right_address;
    }
    
    string to_string() {
        // RETURN t8
        char buffer[INFO_SIZE];
        sprintf(buffer, "RETURN %s", addr_to_string(right_address).c_str());
        return buffer;
    }
};


class DecTAC: public TAC{
public:
    vector<int> suffix;
    vector<int> sizes;
    DecTAC(int address, Type *type, string name, vector<int> sizes){
        TAC::type = type;
        TAC::address = address;
        TAC::name = name;
        this->sizes = vector<int>();
        this->sizes.insert(this->sizes.end(), sizes.begin(), sizes.end());
        int last = 1;
        for (int i = sizes.size() - 1; i >= 0; --i)
        {
            suffix.push_back(last);
            last *= sizes[i];
        }
    }
    string to_string(){
        // DEC x [size] 
        char buffer[INFO_SIZE];
        int size = 1;
        for (auto s: sizes){
            size *= s;
        }
        sprintf(buffer, "DEC t%d %d", TAC::address, TAC::type->getSize() * size);
        return buffer;
    }
};

class ParamTAC : public TAC
{
private:
    vector<int> sizes;
public:
    vector<int> suffix;
    ParamTAC(int address, Type* type, vector<int> sizes) {
        TAC::address = address;
        TAC::type = type;
        this->sizes = vector<int>();
        this->sizes.insert(this->sizes.end(), sizes.begin(), sizes.end());
        int last = 1;
        for (int i = sizes.size() - 1; i >= 0; --i)
        {
            suffix.push_back(last);
            last *= sizes[i];
        }
    }
    string to_string() {
        // PARAM x
        char buffer[INFO_SIZE];
        sprintf(buffer, "PARAM t%d", TAC::address);
        return buffer;
    }
};

class ArgTAC : public TAC
{
private:
    int right_address;
public:
    ArgTAC(int address, int right_address) {
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string() {
        // ARG x
        char buffer[INFO_SIZE];
        sprintf(buffer, "ARG t%d", right_address);
        return buffer;
    }
};

class CallTAC: public TAC{
private:
    string label;
public:
    CallTAC(int address, string label) {
        TAC::address = address;
        this->label = label;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "t%d := CALL %s", TAC::address, label.c_str());
        return buffer;
    }
};

class ReadTAC: public TAC{
public:
    ReadTAC(int address) {
        TAC::address = address;
    }
    string to_string() {
        char buffer[INFO_SIZE];
        sprintf(buffer, "READ t%d", TAC::address);
        return buffer;
    }
};

class WriteTAC: public TAC{
private:
    int right_address;
public:
    WriteTAC(int address, int right_address) {
        TAC::address = address;
        this->right_address = right_address;
    }
    string to_string(){
        char buffer[INFO_SIZE];
        sprintf(buffer, "WRITE t%d", right_address);
        return buffer;
    }
};
extern map<string, int> table;
extern vector<TAC*> tacs;
void init();

void irProgram(AST *root);
void irExtDefList(AST *node);
void irExtDef(AST *node);
Type* irSpecifier(AST *node);
void irExtDecList(AST *node, Type * type);
float parsePrimitive(string name, string value){
    if (name.compare("INT") == 0){
        return atoi(value.c_str());
    } else if (name.compare("FLOAT") == 0){
        return atof(value.c_str());
    } else {
        return atoi(value.c_str());
    }
}
void insertIR(string name, int id){
    table[name] = id;
}
int emit(TAC *tac){
    int _index = tacs.size();
    tacs.push_back(tac);
    DEBUG(tac->to_string().c_str());
    return _index;
}
void irFunDec(AST *node, Type *type);
void irVarList(AST *node);
void irCompSt(AST *node);
void irDefList(AST *node);
void irDef(AST *node);
void irDecList(AST *node, Type*type);
int irExp(AST *node, bool single=false);
int *emitlist(int id = tacs.size() + 1);
void irStmtList(AST *node);
void irStmt(AST *node);
void backPatch(int id, int truelist, int falselist){
    if (tacs[id]->is_swap){
        swap(truelist, falselist);
    }
    *dynamic_cast<IfTAC *>(tacs[id])->label = truelist;
    *dynamic_cast<GoToTAC *>(tacs[id + 1])->label = falselist;
}
void backPatchLoop(vector<int>* sta, int last, int target){
    while (sta->size()>last){//continue
        int top = sta->back();
        sta->pop_back();
        *dynamic_cast<GoToTAC *>(tacs[top])->label = target;
    }
}