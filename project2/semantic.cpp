#include "semantic.hpp"

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

void check_program(AST *root) {
    root->print();
}