%{
    #include"lex.yy.c"
    int yylex();
    void yyerror(const char *s);
    int line_num = 1;
%}
%locations
%start Program
%error-verbose

%token INT CHAR FLOAT
%token WHILE IF ELSE
%token ID TYPE 
%token DOT COMMA ASSIGN
%token STRUCT
%token SEMI
%token LP RP LC RC LB RB
%token RETURN
%token POUND QUOTE LITERAL INCLUDE
// computation operator
%token PLUS MUL MINUS DIV
// logic operator
%token NOT OR AND NE LT LE GT GE EQ
%%
Program: ExtDefList
    ;
ExtDefList: ExtDef ExtDefList
    | %empty
    ;
ExtDef: Specifier ExtDecList SEMI
    | Specifier SEMI
    | Specifier FunDec CompSt
    ;
ExtDecList: VarDec
    | VarDec COMMA ExtDecList
    ;
/* specifier */
Specifier: TYPE
    | StructSpecifier
    ;
StructSpecifier: STRUCT ID LC DefList RC
    | STRUCT ID
    ;
/* declarator */
VarDec: ID
    | VarDec LB INT RB
    ;
FunDec: ID LP VarList RP
    | ID LP RP
    ;
VarList: ParamDec COMMA VarList
    | ParamDec
    ;
ParamDec: Specifier VarDec
    ;
/* statement */
CompSt: LC DefList StmtList RC
    ;
StmtList: Stmt StmtList
    | %empty
    ;
Stmt: Exp SEMI
    | CompSt
    | RETURN Exp SEMI
    | IF LP Exp RP Stmt
    | IF LP Exp RP Stmt ELSE Stmt
    | WHILE LP Exp RP Stmt
    ;
/* local definition */
DefList: Def DefList
    | %empty
    ;
Def: Specifier DecList SEMI
    ;
DecList: Dec
    | Dec COMMA DecList
    ;
Dec: VarDec
    | VarDec ASSIGN Exp
    ;

/* Expression */
Exp: Exp ASSIGN Exp
    | Exp AND Exp
    | Exp OR Exp
    | Exp LT Exp
    | Exp LE Exp
    | Exp GT Exp
    | Exp GE Exp
    | Exp NE Exp
    | Exp EQ Exp
    | Exp PLUS Exp
    | Exp MINUS Exp
    | Exp MUL Exp
    | Exp DIV Exp
    | LP Exp RP
    | MINUS Exp
    | NOT Exp
    | ID LP Args RP
    | ID LP RP
    | Exp LB Exp RB
    | Exp DOT ID
    | ID
    | INT
    | FLOAT
    | CHAR
    ;
Args: Exp COMMA Args
    | Exp
    ;

%%
void init() {

}

void yyerror(const char *s) {
  fprintf(stderr, "ERROR line %d: %s\n", yylloc.first_line, s);
}

int main(void) {
    fprintf(stdout, " 1: ");
    yyparse();
    return 0;
}