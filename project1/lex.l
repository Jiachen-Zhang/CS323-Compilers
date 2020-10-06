%{
    #include"syntax.tab.h"
    // just let you know you have macros!
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #define YY_USER_ACTION \
        yylloc.first_line = yylineno; \
        yylloc.first_column = yycolno; \
        yylloc.last_line = yylineno; \
        yylloc.last_column = yycolno + yyleng; \
        yycolno += yyleng; 
    // and global variables
    int yycolno = 1; 
    int chars = 0;
    int words = 0;
    int lines = 0;
%}
%option yylineno
letter [a-zA-Z]
%%
{letter}+ { words++; chars+=strlen(yytext); }
\n { chars++; lines++; yycolno = 1; }
. { chars++; }
%%
