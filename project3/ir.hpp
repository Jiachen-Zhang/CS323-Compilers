#include<bits/stdc++.h>
#include"semantic.hpp"
using namespace std;

class TAC;
enum class Operator;
extern const int INFO_SIZE;
extern vector<TAC *> tac_vector;



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

class LabelTAC: TAC {
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

class FunctionTAC: TAC {
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

class AssignTAC: TAC {
private:
    int right_address;
public:
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

class AssignAddressTAC: TAC {
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

class AssignValueTAC: TAC {
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

class ArithmeticTAC: TAC {
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

class CopyToAddressTAC: TAC {
private:
    int right_address;
public:
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

class GoToTAC: TAC {
private:
    int* label;
public:
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

class IfTAC: TAC {
private:
    Operator op;
    int left_address;
    int right_address;
    int *label;
public:
    IfTAC(int address, int left_address, Operator op, int right_address, int *label) {
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

class ReturnTAC: TAC {
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