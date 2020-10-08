%{
    #include"lex.yy.c"
    int yylex();
    void yyerror(const char *s);
    int line_num = 1;
    ASTNode *root;
    // int yydebug=1;
%}
%locations
%start Program
%error-verbose
%union{
    struct ASTNode *ast_node;
    float fval;
    char *str;
}

%token ERROE_INT ERROR_FLOAT
%token <ast_node> INT CHAR FLOAT
%token <ast_node> WHILE IF ELSE
%token <ast_node> ID TYPE 
%token <ast_node> DOT COMMA ASSIGN
%token <ast_node> STRUCT
%token <ast_node> SEMI
%token <ast_node> LP RP LC RC LB RB
%token <ast_node> RETURN
%token <ast_node> POUND QUOTE LITERAL INCLUDE
// computation operator
%token <ast_node> PLUS MUL MINUS DIV
// logic operator
%token <ast_node> NOT OR AND NE LT LE GT GE EQ

%type <ast_node> ExtDefList ExtDef ExtDecList
%type <ast_node> Specifier StructSpecifier
%type <ast_node> VarDec FunDec VarList ParamDec
%type <ast_node> CompSt Stmt StmtList
%type <ast_node> DefList Def DecList Dec
%type <ast_node> Exp
%type <ast_node> Args
%%
Program: ExtDefList { 
    DISPLAY_SYNTAX("Program"); 
    root = new_ast_node("Program", NONE_TERMINAL, NULL, @1.first_line, 1, $1); 
}   ;
ExtDefList: ExtDef ExtDefList { 
    DISPLAY_SYNTAX("ExtDefList-1");
    $$ = new_ast_node("ExtDefList", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | %empty { 
    DISPLAY_SYNTAX("ExtDefList-2");
    $$ = new_ast_node("ExtDefList", NONE_TERMINAL, NULL, yylineno, 0);
}   ;
ExtDef: Specifier ExtDecList SEMI { 
    DISPLAY_SYNTAX("ExtDef-1");
    $$ = new_ast_node("ExtDef", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Specifier SEMI { 
    DISPLAY_SYNTAX("ExtDef-2"); 
    $$ = new_ast_node("ExtDef", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | Specifier FunDec CompSt { 
    DISPLAY_SYNTAX("ExtDef-3");
    $$ = new_ast_node("ExtDef", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;
ExtDecList: VarDec { 
    DISPLAY_SYNTAX("ExtDecList"); 
    $$ = new_ast_node("ExtDecList", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | VarDec COMMA ExtDecList { 
    DISPLAY_SYNTAX("ExtDecList");
    $$ = new_ast_node("ExtDecList", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;
/* specifier */
Specifier: TYPE { 
    DISPLAY_SYNTAX("Specifier");
    $$ = new_ast_node("Specifier", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | StructSpecifier { 
    DISPLAY_SYNTAX("Specifier");
    $$ = new_ast_node("Specifier", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   ;
StructSpecifier: STRUCT ID LC DefList RC {
    DISPLAY_SYNTAX("StructSpecifier"); 
    $$ = new_ast_node("StructSpecifier", NONE_TERMINAL, NULL, @1.first_line, 5, $1, $2, $3, $4, $5);
}   | STRUCT ID { 
    DISPLAY_SYNTAX("StructSpecifier"); 
    $$ = new_ast_node("StructSpecifier", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   ;
/* declarator */
VarDec: ID {
    DISPLAY_SYNTAX("ID"); 
    $$ = new_ast_node("VarDec", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | VarDec LB INT RB { 
    DISPLAY_SYNTAX("ID"); 
    $$ = new_ast_node("VarDec", NONE_TERMINAL, NULL, @1.first_line, 4, $1, $2, $3, $4);
}   ;
FunDec: ID LP VarList RP { 
    DISPLAY_SYNTAX("FunDec");
    $$ = new_ast_node("FunDec", NONE_TERMINAL, NULL, @1.first_line, 4, $1, $2, $3, $4);
}   | ID LP RP { 
    DISPLAY_SYNTAX("FunDec");
    $$ = new_ast_node("FunDec", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;
VarList: ParamDec COMMA VarList {
    DISPLAY_SYNTAX("VarList");
    $$ = new_ast_node("VarList", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | ParamDec { 
    DISPLAY_SYNTAX("VarList"); 
    $$ = new_ast_node("VarList", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   ;
ParamDec: Specifier VarDec { 
    DISPLAY_SYNTAX("ParamDec");
    $$ = new_ast_node("ParamDec", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   ;
/* statement */
CompSt: LC DefList StmtList RC { 
    DISPLAY_SYNTAX("CompSt"); 
    $$ = new_ast_node("CompSt", NONE_TERMINAL, NULL, @1.first_line, 4, $1, $2, $3, $4);
}   ;
StmtList: Stmt StmtList { 
    DISPLAY_SYNTAX("StmtList"); 
    $$ = new_ast_node("StmtList", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | %empty { 
    DISPLAY_SYNTAX("StmtList"); 
    $$ = new_ast_node("StmtList", NONE_TERMINAL, NULL, yylineno, 0); 
}   ;
Stmt: Exp SEMI { 
    DISPLAY_SYNTAX("Stmt");
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | CompSt { 
    DISPLAY_SYNTAX("Stmt");
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | RETURN Exp SEMI { 
    DISPLAY_SYNTAX("Stmt"); 
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | IF LP Exp RP Stmt { 
    DISPLAY_SYNTAX("Stmt");
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 5, $1, $2, $3, $4, $5);
}   | IF LP Exp RP Stmt ELSE Stmt { 
    DISPLAY_SYNTAX("Stmt");
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 7, $1, $2, $3, $4, $5, $6, $7);
}   | WHILE LP Exp RP Stmt { 
    DISPLAY_SYNTAX("Stmt");
    $$ = new_ast_node("Stmt", NONE_TERMINAL, NULL, @1.first_line, 5, $1, $2, $3, $4, $5);
}   ;
/* local definition */
DefList: Def DefList {
    DISPLAY_SYNTAX("DefList");
    $$ = new_ast_node("DefList", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | %empty {
    DISPLAY_SYNTAX("DefList");
    $$ = new_ast_node("DefList", NONE_TERMINAL, NULL, yylineno, 0);
}   ;
Def: Specifier DecList SEMI {
    DISPLAY_SYNTAX("Def");
    $$ = new_ast_node("Def", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;
DecList: Dec {
    DISPLAY_SYNTAX("DecList");
    $$ = new_ast_node("DecList", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | Dec COMMA DecList {
    DISPLAY_SYNTAX("DecList");
    $$ = new_ast_node("DecList", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;
Dec: VarDec {
    DISPLAY_SYNTAX("Dec");
    $$ = new_ast_node("Dec", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | VarDec ASSIGN Exp {
    DISPLAY_SYNTAX("Dec");
    $$ = new_ast_node("Dec", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   ;

/* Expression */
Exp: Exp ASSIGN Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp AND Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp OR Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp LT Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp LE Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp GT Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp GE Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp NE Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp EQ Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp PLUS Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp MINUS Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp MUL Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp DIV Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | LP Exp RP {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | MINUS Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | NOT Exp {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 2, $1, $2);
}   | ID LP Args RP {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 4, $1, $2, $3, $4);
}   | ID LP RP {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp LB Exp RB {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 4, $1, $2, $3, $4);
}   | Exp DOT ID {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | ID {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | INT {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | FLOAT {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   | CHAR {
    DISPLAY_SYNTAX("Exp");
    $$ = new_ast_node("Exp", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   ;
Args: Exp COMMA Args {
    DISPLAY_SYNTAX("Args");
    $$ = new_ast_node("Args", NONE_TERMINAL, NULL, @1.first_line, 3, $1, $2, $3);
}   | Exp {
    DISPLAY_SYNTAX("Args");
    $$ = new_ast_node("Args", NONE_TERMINAL, NULL, @1.first_line, 1, $1);
}   ;

%%
void init() {
    root = NULL;
}

void yyerror(const char *s) {
  fprintf(stderr, "ERROR line %d: %s\n", yylloc.first_line, s);
}
int main(int argc, char **argv) {
    char *file_path;
    if ( argc < 2 ) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if( argc > 2 ){
        fprintf(stderr, "Too much arguments!\n");
        return EXIT_FAIL;
    }
    file_path = argv[1];
    if(!(yyin = fopen(file_path, "r"))){
        perror(argv[1]);
        return EXIT_FAIL;
    }
    init();
    yyparse();
    assert(root != NULL);
    print_ast_node(root, 0);
    return EXIT_OK;
}