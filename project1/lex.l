%{
    #include"syntax.tab.h"
    // just let you know you have macros!
    #define DISPLAY_TOKEN(token) fprintf(stdout, "%s (%d, %d) ", token, yylineno, yycolno);
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
%}
%option yylineno
letter [a-zA-Z_]
id [a-zA-Z_]+[0-9a-zA-Z_]*
type (int)|(fload)|(char)
%%
"/* integer in 32-bits (decimal or hexadecimal) */" { DISPLAY_TOKEN("INT "); }
"/* floating point number (only dot-form) */" { DISPLAY_TOKEN("FLOAT "); }
"/* single character (printable or hex-form) */" { DISPLAY_TOKEN("CHAR "); }
{type} { DISPLAY_TOKEN("TYPE"); }
"struct" { DISPLAY_TOKEN("STRUCT"); }
"if" { DISPLAY_TOKEN("IF"); }
"else" { DISPLAY_TOKEN("ELSE"); }
"while" { DISPLAY_TOKEN("WHILE"); }
"return" { DISPLAY_TOKEN("RETURN"); }
{id} { DISPLAY_TOKEN("ID"); /* should be after type */}
"." { DISPLAY_TOKEN("DOT"); }
";" { DISPLAY_TOKEN("SEMI"); }
"," { DISPLAY_TOKEN("COMMA"); }
"=" { DISPLAY_TOKEN("ASSIGN"); }
"<" { DISPLAY_TOKEN("LT"); }
"<=" { DISPLAY_TOKEN("LE"); }
">" { DISPLAY_TOKEN("GT"); }
">=" { DISPLAY_TOKEN("GE"); }
"!=" { DISPLAY_TOKEN("NE"); }
"==" { DISPLAY_TOKEN("EQ"); }
"+" { DISPLAY_TOKEN("PLUS"); }
"-" { DISPLAY_TOKEN("MINUS"); }
"*" { DISPLAY_TOKEN("MUL"); }
"/" { DISPLAY_TOKEN("DIV"); }
"&&" { DISPLAY_TOKEN("AND"); }
"||" { DISPLAY_TOKEN("OR"); }
"!" { DISPLAY_TOKEN("NOT"); }
"(" { DISPLAY_TOKEN("LP"); }
")" { DISPLAY_TOKEN("RP"); }
"[" { DISPLAY_TOKEN("LB"); }
"]" { DISPLAY_TOKEN("RB"); }
"{" { DISPLAY_TOKEN("LC"); }
"}" { DISPLAY_TOKEN("RC"); }
\n { yycolno = 1; fprintf(stdout, "\n"); }
. { ; }
<<EOF>> { fprintf(stdout, "END\n"); return 0; }
%%
