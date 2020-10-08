%{
    #include"lex.yy.c"
    int yylex();
    void yyerror(const char *s);
    int line_num = 1;
%}
%locations
%start Program
%error-verbose

%token ERROE_INT ERROR_FLOAT
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
Program: ExtDefList { DISPLAY_SYNTAX("Program"); }
    ;
ExtDefList: ExtDef ExtDefList { DISPLAY_SYNTAX("ExtDefList"); }
    | %empty { DISPLAY_SYNTAX("ExtDefList"); }
    ;
ExtDef: Specifier ExtDecList SEMI { DISPLAY_SYNTAX("ExtDef"); }
    | Specifier SEMI { DISPLAY_SYNTAX("ExtDef"); }
    | Specifier FunDec CompSt { DISPLAY_SYNTAX("ExtDef"); }
    ;
ExtDecList: VarDec { DISPLAY_SYNTAX("ExtDecList"); }
    | VarDec COMMA ExtDecList { DISPLAY_SYNTAX("ExtDecList"); }
    ;
/* specifier */
Specifier: TYPE { DISPLAY_SYNTAX("Specifier"); }
    | StructSpecifier { DISPLAY_SYNTAX("Specifier"); }
    ;
StructSpecifier: STRUCT ID LC DefList RC { DISPLAY_SYNTAX("StructSpecifier"); }
    | STRUCT ID { DISPLAY_SYNTAX("StructSpecifier"); }
    ;
/* declarator */
VarDec: ID { DISPLAY_SYNTAX("ID"); }
    | VarDec LB INT RB { DISPLAY_SYNTAX("ID"); }
    ;
FunDec: ID LP VarList RP { DISPLAY_SYNTAX("FunDec"); }
    | ID LP RP { DISPLAY_SYNTAX("FunDec"); }
    ;
VarList: ParamDec COMMA VarList { DISPLAY_SYNTAX("VarList"); }
    | ParamDec { DISPLAY_SYNTAX("VarList"); }
    ;
ParamDec: Specifier VarDec { DISPLAY_SYNTAX("ParamDec"); }
    ;
/* statement */
CompSt: LC DefList StmtList RC { DISPLAY_SYNTAX("CompSt"); }
    ;
StmtList: Stmt StmtList { DISPLAY_SYNTAX("StmtList"); }
    | %empty { DISPLAY_SYNTAX("StmtList"); }
    ;
Stmt: Exp SEMI { DISPLAY_SYNTAX("Stmt"); }
    | CompSt { DISPLAY_SYNTAX("Stmt"); }
    | RETURN Exp SEMI { DISPLAY_SYNTAX("Stmt"); }
    | IF LP Exp RP Stmt { DISPLAY_SYNTAX("Stmt"); }
    | IF LP Exp RP Stmt ELSE Stmt { DISPLAY_SYNTAX("Stmt"); }
    | WHILE LP Exp RP Stmt { DISPLAY_SYNTAX("Stmt"); }
    ;
/* local definition */
DefList: Def DefList { DISPLAY_SYNTAX("DefList"); }
    | %empty { DISPLAY_SYNTAX("DefList"); }
    ;
Def: Specifier DecList SEMI { DISPLAY_SYNTAX("Def"); }
    ;
DecList: Dec { DISPLAY_SYNTAX("DecList"); }
    | Dec COMMA DecList { DISPLAY_SYNTAX("DecList"); }
    ;
Dec: VarDec { DISPLAY_SYNTAX("Dec"); }
    | VarDec ASSIGN Exp { DISPLAY_SYNTAX("Dec"); }
    ;

/* Expression */
Exp: Exp ASSIGN Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp AND Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp OR Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp LT Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp LE Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp GT Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp GE Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp NE Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp EQ Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp PLUS Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp MINUS Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp MUL Exp { DISPLAY_SYNTAX("Exp"); }
    | Exp DIV Exp { DISPLAY_SYNTAX("Exp"); }
    | LP Exp RP { DISPLAY_SYNTAX("Exp"); }
    | MINUS Exp { DISPLAY_SYNTAX("Exp"); }
    | NOT Exp { DISPLAY_SYNTAX("Exp"); }
    | ID LP Args RP { DISPLAY_SYNTAX("Exp"); }
    | ID LP RP { DISPLAY_SYNTAX("Exp"); }
    | Exp LB Exp RB { DISPLAY_SYNTAX("Exp"); }
    | Exp DOT ID { DISPLAY_SYNTAX("Exp"); }
    | ID { DISPLAY_SYNTAX("Exp"); }
    | INT { DISPLAY_SYNTAX("Exp"); }
    | FLOAT { DISPLAY_SYNTAX("Exp"); }
    | CHAR { DISPLAY_SYNTAX("Exp"); }
    ;
Args: Exp COMMA Args { DISPLAY_SYNTAX("Args"); }
    | Exp { DISPLAY_SYNTAX("Args"); }
    ;

%%
void init() {

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
    yydebug=1;
    yylex();
    // yyparse();
    return EXIT_OK;
}