%{
    #include"lex.yy.c"
    struct Json* json;
    void yyerror(const char*);
%}

%union{
    struct Json* json;
    struct Member* member;
    struct Array* array;
    char *string;
    double number;
    int boolean;
}

%token LC RC LB RB COLON COMMA
%token <string> STRING
%token <number> NUMBER
%token <boolean> TRUE FALSE 
%token <json> VNULL

%type <json> Json Value
%type <member> Object Members Member
%type <array> Array Values
%%

Json:
      Value {json = $1}
    | Value COMMA error { puts("Comma after the close, recovered"); }
    ;
Value:
      Object { $$ = newJson(); $$->value = $1; $$->category = _OBJECT; }
    | Array { $$ = newJson(); $$->value = $1; $$->category = _ARRAY; }
    | STRING { $$ = newJson(); $$->value = $1; $$->category = _STRING; }
    | NUMBER { $$ = newJson(); $$->value = $1; $$->category = _NUMBER; }
    | TRUE  { $$ = newJson(); $$->value = $1; $$->category = _BOOLEAN; }
    | FALSE { $$ = newJson(); $$->value = $1; $$->category = _BOOLEAN; }
    | VNULL { $$ = newJson(); $$->category = _VNULL; }
    ;
Object:
      LC RC { $$ = newMember(); }
    | LC Members RC { $$ = $2; }
    | LC Members RC Value error { puts("Extra value after close, recovered"); }
    ;
Members:
      Member {$$ = $1; }
    | Member COMMA Members { $$ = $1; $1->next = $3; }
    | Member COLON Members error {puts("Colon instead of comma, recovered");}
    ;
Member:
      STRING COLON Value { $$ = newMember(); $$->key = $1; $$->json = $3; }
    | STRING COLON Value COMMA error { puts("Comma instead if closing brace, recovered"); }
    | STRING COMMA Value error { puts("Comma instead of colon, recovered"); }
    | STRING COLON COLON Value error { puts("Double colon, recovered"); }
    | STRING Value error { puts("Missing colon, recovered"); }
    ;
Array:
      LB RB { $$ = newArray(); }
    | LB Values RB { $$ = newArray(); $$->json = $2; }
    | LB Values RB RB error { puts("Extra close, recovered"); }
    | LB Values RC error { puts("mismatch, recovered"); }
    | LB Values error { puts("Unclosed array, recovered"); }
    | LB COMMA error { puts("<-- missing value, recovered");}
    ;
Values:
      Value { $$ = newArray(); $$->json = $1;}
    | Value COMMA Values {  $$ = newArray(); $$->json = $1; $$->next = $3; }
    | Value COLON Values error  { puts("Colon instead of comma, recovered"); }
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
