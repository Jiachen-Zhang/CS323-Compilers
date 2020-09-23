%{
    #include"lex.yy.c"
    void yyerror(const char *s);
    int result = 0;
%}
%token LP RP LB RB LC RC
%%
QUIZ: Unit {result = $1;}
Unit: %empty {$$ = 1;}
    | Unit LP Unit RP {$$ = $1 * $3;}
    | Unit LB Unit RB {$$ = $1 * $3;}
    | Unit LC Unit RC {$$ = $1 * $3;}
    | Unit LP Unit RB {$$ = 0;}
    | Unit LP Unit RC {$$ = 0;}
    | Unit LB Unit RP {$$ = 0;}
    | Unit LB Unit RC {$$ = 0;}
    | Unit LC Unit RP {$$ = 0;}
    | Unit LC Unit RB {$$ = 0;}
    | Unit LP {$$ = 0;}
    | Unit LB {$$ = 0;}
    | Unit LC {$$ = 0;}
    | Unit RP {$$ = 0;}
    | Unit RB {$$ = 0;}
    | Unit RC {$$ = 0;}
    ;
Valid: 
%%

void yyerror(const char *s){
    // fprintf(stderr, "Syntax error: %s\n", s);
}

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    // printf("result = %d for expr = %s\n", result, expr);
    return result;
}
