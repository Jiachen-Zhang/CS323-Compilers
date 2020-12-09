#include<bits/stdc++.h>
#include"semantic.hpp"
using namespace std;

class TAC;
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