%{
    #include"lex.yy.c"
    struct Json* json;
    int is_valid = 1;
    void yyerror(const char*);
%}
%union{
    struct Json* json;
    struct Object* object;
    struct Array* array;
    char string[100];
    double number;
    int boolean;
}

%token LC RC LB RB COLON COMMA
%token <string> STRING
%token <number> NUMBER
%token <boolean> TRUE FALSE 
%token <json> VNULL

%type <json> Json Value
%type <object> Object Members Member
%type <array> Array Values

%%

Json:
      Value {json = $1;}
    | Value COMMA error { puts("comma after the close, recovered"); }
    | Value RB error { puts("extra close, recovered"); }
    | Value STRING error { puts("misplaced quoted value, recovered"); }
    ;
Value:
      Object {$$ = createJson(); $$->object = $1; $$->category = OBJECT_; }
    | Array {$$ = createJson(); $$->array = $1; $$->category = ARRAY_; }
    | STRING {$$ = createJson(); $$->string = $1; $$->category = STRING_; }
    | NUMBER {  $$ = createJson(); 
                $$->number = $1; 
                $$->category = NUMBER_; 
            }
    | TRUE {$$ = createJson(); $$->boolean = $1; $$->category = BOOLEAN_; }
    | FALSE {$$ = createJson(); $$->boolean = $1; $$->category = BOOLEAN_; }
    | VNULL {$$ = $1; $$->category = VNULL_; }
    | NUMBER NUMBER error { puts("numbers cannot have leading zeros, recovered"); }
    ;
Object:
      LC RC {$$ = createObject();}
    | LC Members RC 
        { 
            $$ = $2;
            Object* object = $2;
            int table[26];
            // fprintf(stdout, "a = %d\n", (int)'a');
            while (object != NULL) {
                int key = (object->string)[1] - 97;
                // fprintf(stdout, ">%s< <%d>\n", object->string, key);
                if (table[key] == 0) {
                    table[key] = 1;

                } else {
                    is_valid = 0;
                    char buf[200];
                    sprintf(buf, "duplicate key: %s\n", object->string);
                    yyerror(buf);
                }
                object = object->members;
            }
        }
    ;
Members:
      Member 
        {
            $$ = $1;
            // fprintf(stdout, "<<%s>\n", $$->string);
        }
    | Member COMMA Members 
        {
            $$ = $1; 
            $1->members = $3;
        }
    | Member COMMA error { puts("extra comma, recovered"); }
    ;
Member:
      STRING COLON Value 
        {
            $$ = createObject();
            memset($$->string, '\0', sizeof($1));
            strcpy($$->string, $1);
            $$->value = $3;
        }   
    | STRING Value error { puts("missing colon, recovered"); }
    | STRING COLON COLON error { puts("double colon, recovered"); }
    | STRING COMMA Value error { puts("comma instead of colon, recovered"); }
    ;
Array:
      LB RB {$$ = createArray();}
    | LB Values RB {$$ = $2;}
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | LB Values error { puts("unclosed array, recovered"); }
    ;
Values:
      Value {$$ = createArray(); $$->value = $1;}
    | Value COMMA Values {$$ = createArray(); $$->value = $1; $$->values = $3;}
    | Value COMMA error { puts("extra comma, recovered"); }
    | Value COMMA COMMA error { puts("double extra comma, recovered"); }
    | COMMA Value error { puts("missing value, recovered"); }
    | Value COLON Values error { puts("colon instead of comma, recovered"); }
    ;
%%

void yyerror(const char *s){
    printf("%s", s);
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
    if(is_valid) {
        printf("%d\n", is_valid);
    }
    return 0;
}
