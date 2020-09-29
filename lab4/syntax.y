%{
    #include"lex.yy.c"
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER
%token TRUE FALSE VNULL
%%

Json:
      Value
    | Value COMMA error { puts("Comma after the close, recovered"); }
    ;
Value:
      Object
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    ;
Object:
      LC RC
    | LC Members RC
    | LC Members COMMA error { puts("Comma instead if closing brace, recovered"); }
    | LC Members RC Value error { puts("Extra value after close, recovered"); }
    ;
Members:
      Member
    | Member COMMA Members
    ;
Member:
      STRING COLON Value
    | STRING COLON Value COMMA error { puts("Extra comma, recovered"); }
    | STRING COMMA Value error { puts("Comma instead of colon, recovered"); }
    | STRING COLON COLON Value error { puts("Double colon, recovered"); }
    | STRING Value error { puts("Missing colon, recovered"); }
    ;
Array:
      LB RB
    | LB Values RB
    | LB Values RB RB error { puts("Extra close, recovered"); }
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | LB Values error { puts("miss right bracket, recovered"); }
    | LB COMMA error { puts("miss value before comma, recovered");}
    ;
Values:
      Value
    | Value COMMA Values
    | Value COMMA error  { puts("extra comma, recovered"); }
    | Value COMMA COMMA error  { puts("double extra comma, recovered"); }
    ;
%%

void yyerror(const char *s){
    printf("syntax error: ");
}

int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
