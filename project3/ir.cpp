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

void irCompSt(AST *node) {
    DEBUG("CompSt begin");
    irDefList(node->child[1]);
    irStmtList(node->child[2]);
    DEBUG("CompSt end");
}

void irStmtList(AST *node) {
    while (node->child_num) {
        irStmt(node->child[0]);
        node = node->child[1];
    }
}

void irStmt(AST *node) {
    //Exp
    if (node->child[0]->type_name.compare("Exp") == 0) {
        irExp(node->child[0]);
    }
    //CompSt
    else if (node->child[0]->type_name.compare("CompSt") == 0) {
        irCompSt(node->child[0]);
    }
    //RETURN
    else if (node->child[0]->type_name.compare("RETURN") == 0) {
        int expid = irExp(node->child[1]);
        emit(new ReturnTAC(tacs.size(), expid));
    }
    //IF
    else if (node->child[0]->type_name.compare("IF") == 0) {
        int expid = irCondition(node->child[2]);
        int truelist = emit(new LabelTAC(tacs.size()));
        irStmt(node->child[4]);
        int jumpid;
        if (node->child_num > 5){
            jumpid = emit(new GoToTAC(tacs.size(), emitlist()));
        }
        int falselist = emit(new LabelTAC(tacs.size()));
        //back patch
        backPatch(expid, truelist, falselist);
        if (node->child_num > 5)
        {
            irStmt(node->child[6]);
            int jumpto = emit(new LabelTAC(tacs.size()));
            *dynamic_cast<GoToTAC *>(tacs[jumpid])->label = jumpto;
        }
    }
    //WHILE
    else if (node->child[0]->type_name.compare("WHILE") == 0) {
        int contop = con.size();
        int brtop = br.size();
        int loopstart = emit(new LabelTAC(tacs.size()));
        int expid = irCondition(node->child[2]);
        int truelist = emit(new LabelTAC(tacs.size()));//M1
        irStmt(node->child[4]);
        int loopback = emit(new GoToTAC(tacs.size(), emitlist(loopstart)));
        int falselist = emit(new LabelTAC(tacs.size())); //M2
        //backpatch: exp.true=M1.inst, exp.false=M2.inst
        backPatch(expid, truelist, falselist);
        backPatchLoop(&con, contop, loopstart);
        backPatchLoop(&br, brtop, falselist);
    }
    //BREAK
    else if (node->child[0]->type_name.compare("BREAK") == 0) {
        int id = emit(new GoToTAC(tacs.size(), emitlist()));
        br.push_back(id);
    }
    //CONTINUE
    else if (node->child[0]->type_name.compare("CONTINUE") == 0) {
        int id = emit(new GoToTAC(tacs.size(), emitlist()));
        con.push_back(id);
    }
    //WRITE
    else if (node->child[0]->type_name.compare("WHILE") == 0) {
        auto res = irArgs(node->child[2]);
        for (auto id : res) {
            emit(new WriteTAC(tacs.size(), id));
        }
    } else {
        assert(NULL);
    }
}

void irDefList(AST *node) {
    DEBUG("CompSt begin");
    while (node->child_num){
        irDef(node->child[0]);
        node = node->child[1];
    }
    DEBUG("CompSt end");
}

void irDef(AST *node) {
    DEBUG("CompSt begin");
    Type * type = irSpecifier(node->child[0]);
    irDecList(node->child[1], type);
    DEBUG("CompSt end");
}

void irDecList(AST *node, Type*type) {
    DEBUG("CompSt begin");
    irDec(node->child[0], type);
    while (node->child_num>1){
        node = node->child[2];
        irDec(node->child[0], type);
    }
    DEBUG("CompSt end");
}

void irDec(AST *node, Type *type) {
    int expid = 0;
    if (node->child_num>1){
        expid = irExp(node->child[2]);
    }
    TAC *tac = irVarDec(node->child[0], type);
    if (expid) {
        dynamic_cast<AssignTAC *>(tac)->right_address = expid;
    }
    insertIR(tac->name, tac->emit());
}

int irExp(AST *node, bool single){
    DEBUG("Exp begin")
    //READ
    if (node->child[0]->type_name.compare("READ") == 0) {
        ReadTAC *exp = new ReadTAC(tacs.size());
        return emit(exp);
    }
    //INT/CHAR/FLOAT
    if (node->child[0]->type_name.compare("INT") == 0 ||
        node->child[0]->type_name.compare("CHAR") == 0 ||
        node->child[0]->type_name.compare("FLOAT") == 0) {
        AssignTAC *exp = new AssignTAC(tacs.size(), -parsePrimitive(node->child[0]->type_name, node->child[0]->value));
        int id = emit(exp);
        return id;
    }
    //SUB Exp
    if (node->child[0]->type_name.compare("SUB") == 0) {
        int cid = irExp(node->child[1]);
        ArithmeticTAC *exp = new ArithmeticTAC(tacs.size(), Operator::SUB_OPERATOR, 0, cid);
        int id = emit(exp);
        return id;
    }
    //NOT Exp
    if (node->child[0]->type_name.compare("NOT") == 0) {
        int cid = irExp(node->child[1]);
        // swap truelist - falselist | must be pointer
        tacs[cid]->is_swap ^= 1;
        return cid;
    }
    //ID(...)
    if (node->child[0]->type_name.compare("ID") == 0 && node->child_num>1) {
        string name = node->child[0]->value;
        if (node->child[2]->type_name.compare("Args") == 0){
            auto res = irArgs(node->child[2]);
            for (auto id: res){
                emit(new ArgTAC(tacs.size(), id));
            }
        }
        int id = emit(new CallTAC(tacs.size(), name));
        return id;
    }
    //ID
    if (node->child[0]->type_name.compare("ID") == 0){
        string name = node->child[0]->value;
        int id = getIR(name);
        if (single) {
            if (!id) {
                id = tacs.size();
                insertIR(name, id);
            }
            return emit(new AssignTAC(id, 0));
        }
        else if (!id){ //on the right but never show up before
            return emit(new AssignTAC(tacs.size(), 0));
        }else{
            return id;
        }
    }
    //Exp OR Exp
    if (node->child[1]->type_name.compare("OR") == 0) {
        int leftid = irExp(node->child[0]);
        //backpatch exp1.falselist=M.inst
        int id = emit(new LabelTAC(tacs.size()));
        int leftIsSwap = tacs[leftid]->is_swap;
        int rightid = irExp(node->child[2]);
        int rightIsSwap = tacs[rightid]->is_swap;

        //merge exp1.truelist | exp2.truelist
        if (leftIsSwap)
        { //exp1.falselist
            *dynamic_cast<IfTAC *>(tacs[leftid])->label = id;
            if (rightIsSwap){//exp2.falselist
                dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = dynamic_cast<GoToTAC *>(tacs[rightid + 1])->label;
            }
            else{ //exp2.truelist
                dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = dynamic_cast<IfTAC *>(tacs[rightid])->label;
            }
        }else{//exp1.truelist
            *dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = id;
            if (rightIsSwap){//exp2.falselist
                dynamic_cast<IfTAC *>(tacs[leftid])->label = dynamic_cast<GoToTAC *>(tacs[rightid + 1])->label;
            }
            else{ //exp2.truelist
                dynamic_cast<IfTAC *>(tacs[leftid])->label = dynamic_cast<IfTAC *>(tacs[rightid])->label;
            }
        }
        //Exp.falselist=exp2.falselist
        return rightid;
    }
    //Exp AND Exp
    if (node->child[1]->type_name.compare("AND") == 0) {
        int leftid = irExp(node->child[0]);
        //backpatch exp1.truelist=M.inst
        int id = emit(new LabelTAC(tacs.size()));
        int leftIsSwap = tacs[leftid]->is_swap;
        int rightid = irExp(node->child[2]);
        int rightIsSwap = tacs[rightid]->is_swap;
        //merge exp1.falselist | exp2.falselist
        if (leftIsSwap){//exp1.truelist
            *dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = id;
            if (rightIsSwap){//exp2.truelist
                dynamic_cast<IfTAC *>(tacs[leftid])->label = dynamic_cast<IfTAC *>(tacs[rightid])->label;
            }
            else{ //exp2.falselist
                dynamic_cast<IfTAC *>(tacs[leftid])->label = dynamic_cast<GoToTAC *>(tacs[rightid + 1])->label;
            }
        }else{ //exp1.falselist
            *dynamic_cast<IfTAC *>(tacs[leftid])->label = id;
            if (rightIsSwap){//exp2.truelist
                dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = dynamic_cast<IfTAC *>(tacs[rightid])->label;
            }
            else{ //exp2.falselist
                dynamic_cast<GoToTAC *>(tacs[leftid + 1])->label = dynamic_cast<GoToTAC *>(tacs[rightid + 1])->label;
            }
        }
        //Exp.truelist=Exp2.truelist
        return rightid;
    }
    //Exp LE/LT/GE/GT/NE/EQ Exp
    if (node->child[1]->type_name.compare("LE") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::LE_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    if (node->child[1]->type_name.compare("LT") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::LT_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    if (node->child[1]->type_name.compare("GE") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::GE_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    if (node->child[1]->type_name.compare("GT") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::GT_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    if (node->child[1]->type_name.compare("NE") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::NE_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    if (node->child[1]->type_name.compare("EQ") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        IfTAC *if_tac = new IfTAC(tacs.size(), Operator::EQ_OPERATOR, leftid, rightid, emitlist()); //back
        int ifid = emit(if_tac);
        TAC *goinst = new GoToTAC(tacs.size(), emitlist());//back
        int goid = emit(goinst);
        return ifid;
    }
    
    //Exp ASSIGN Exp
    if (node->child[1]->type_name.compare("ASSIGN") == 0){
        int rightid = irExp(node->child[2]);
        int leftid = irExp(node->child[0], true);
        if (typeid(*tacs[leftid])==typeid(AssignTAC)){
            dynamic_cast<AssignTAC *>(tacs[leftid])->right_address = rightid;
        } else {
            dynamic_cast<CopyToAddressTAC *>(tacs[leftid])->right_address = rightid;
        }
        return rightid;
    }
    //Exp Arith Exp
    if (node->child[1]->type_name.compare("ADD") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        ArithmeticTAC *exp = new ArithmeticTAC(tacs.size(), Operator::ADD_OPERATOR, leftid, rightid);
        int id=emit(exp);
        return id;
    }
    if (node->child[1]->type_name.compare("SUB") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        ArithmeticTAC *exp = new ArithmeticTAC(tacs.size(), Operator::SUB_OPERATOR, leftid, rightid);
        int id=emit(exp);
        return id;
    }
    if (node->child[1]->type_name.compare("MUL") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        ArithmeticTAC *exp = new ArithmeticTAC(tacs.size(), Operator::MUL_OPERATOR, leftid, rightid);
        int id=emit(exp);
        return id;
    }
    if (node->child[1]->type_name.compare("DIV") == 0) {
        int leftid = irExp(node->child[0]);
        int rightid = irExp(node->child[2]);
        ArithmeticTAC *exp = new ArithmeticTAC(tacs.size(), Operator::DIV_OPERATOR, leftid, rightid);
        int id=emit(exp);
        return id;
    }
    //Exp LB Exp RB
    if (node->child[1]->type_name.compare("LB") == 0){
        vector<AST *> _stack = {node};
        int head;
        while (!_stack.empty()) {
            AST *top = _stack.back();
            if (top->child[0]->type_name.compare("ID") == 0){
                head = irExp(top);
                _stack.pop_back();
                int typeSize = tacs[head]->type->getSize();
                vector<int> *suffix;
                if (typeid(*tacs[head]) == typeid(DecTAC)) {
                    suffix = &(dynamic_cast<DecTAC *>(tacs[head])->suffix);
                    head = emit(new AssignAddressTAC(tacs.size(), head));
                } else{
                    suffix = &(dynamic_cast<ParamTAC*>(tacs[head])->suffix);
                }
                int _index = _stack.size();
                while (_index--) {
                    AST *p = _stack.back();
                    _stack.pop_back();
                    int offset = irExp(p->child[2]);
                    offset = emit(new ArithmeticTAC(tacs.size(), Operator::MUL_OPERATOR, offset, -(*suffix)[_index] * typeSize));
                    head = emit(new ArithmeticTAC(tacs.size(), Operator::ADD_OPERATOR, head, offset));
                }
            } else {
                _stack.push_back(top->child[0]);
            }
        }
        if (single) {
            return emit(new CopyToAddressTAC(head, 0));
        } else {
            return emit(new AssignValueTAC(tacs.size(), head));
        }
    }
    //Exp DOT ID
    if (node->child[1]->type_name.compare("DOT") == 0){
        vector<AST *> _stack = {node};
        int head;
        while (!_stack.empty())
        {
            AST *top = _stack.back();
            if (top->child[0]->type_name.compare("ID") == 0){
                head = irExp(top);
                Type *type = tacs[head]->type;
                _stack.pop_back();
                if (typeid(*tacs[head])==typeid(DecTAC)){
                    head = emit(new AssignAddressTAC(tacs.size(), head));
                }
                int _index = _stack.size();
                while (_index--)
                {
                    AST *p = _stack.back();
                    _stack.pop_back();
                    string name = p->child[2]->value;
                    int offset = dynamic_cast<Structure_Type *>(type)->getOffset(name);
                    head = emit(new ArithmeticTAC(tacs.size(), Operator::ADD_OPERATOR, head, -offset));
                }
            }
            else {
                _stack.push_back(top->child[0]);
            }
        }
        if (single) {
            return emit(new CopyToAddressTAC(head, 0));
        } else {
            return emit(new AssignValueTAC(tacs.size(), head));
        }
    }
}

vector<int> irArgs(AST *node) {
    vector<int> args = vector<int>();
    int expid = irExp(node->child[0]);
    if (typeid(*tacs[expid])==typeid(DecTAC)) {
        expid = emit(new AssignAddressTAC(tacs.size(), expid));
    }
    args.push_back(expid);
    while (node->child_num > 1) {
        node = node->child[2];
        expid = irExp(node->child[0]);
        args.push_back(expid);
        if (typeid(*tacs[expid])!=typeid(DecTAC)){
            expid = emit(new AssignAddressTAC(tacs.size(), expid));
        }
    }
    return args;
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
int* emitlist(int id){
    int *label = new int(id);
    return label;
}


