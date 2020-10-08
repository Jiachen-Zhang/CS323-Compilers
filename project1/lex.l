%{
    #include"syntax.tab.h"
    // just let you know you have macros!
    #define EXIT_OK 0
    #define EXIT_FAIL 1
    #define DISPLAY_SYNTAX(syntax) fprintf(stdout, "%s(%d)\n", syntax, yylineno);
    #define DISPLAY_TOKEN(token) fprintf(stdout, "    %s[%d](%s)\n", token, yycolno, yytext);
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
decimal_int 0|(-?[1-9][0-9]*)
int {decimal_int}|(0[xX][0-9a-fA-F]{1,6})
float {decimal_int}\.[0-9]+
letter [a-zA-Z_]
id [a-zA-Z_][0-9a-zA-Z_]*
type (int)|(fload)|(char)
char ('[ -~]')|('0[xX][0-9a-fA-F]{1,2}')
%%
(0[0-9]+)|(0[xX])|(0[xX][0-9a-fA-F]{6}[0-9a-fA-F]+) { DISPLAY_TOKEN("ERROR_INT"); return ERROE_INT; }
(0\.) { DISPLAY_TOKEN("ERROR_FLOAT"); return ERROR_FLOAT; }
{float} { DISPLAY_TOKEN("FLOAT"); return FLOAT; /* floating point number (only dot-form) */}
{int} { DISPLAY_TOKEN("INT"); return INT; /* integer in 32-bits (decimal or hexadecimal) */}
{char} { DISPLAY_TOKEN("CHAR"); return CHAR; /* single character (printable or hex-form) */ }
"struct" { DISPLAY_TOKEN("STRUCT"); return STRUCT; }
"if" { DISPLAY_TOKEN("IF"); return IF; }
"else" { DISPLAY_TOKEN("ELSE"); return ELSE; }
"while" { DISPLAY_TOKEN("WHILE"); return WHILE; }
"return" { DISPLAY_TOKEN("RETURN"); return RETURN; }
{type} { DISPLAY_TOKEN("TYPE"); return TYPE; }
{id} { DISPLAY_TOKEN("ID"); return ID; /* should be after type */}
"." { DISPLAY_TOKEN("DOT"); return DOT; }
";" { DISPLAY_TOKEN("SEMI"); return SEMI; }
"," { DISPLAY_TOKEN("COMMA"); return COMMA; }
"=" { DISPLAY_TOKEN("ASSIGN"); return ASSIGN; }
"<" { DISPLAY_TOKEN("LT"); return LT; }
"<=" { DISPLAY_TOKEN("LE"); return LE; }
">" { DISPLAY_TOKEN("GT"); return GT; }
">=" { DISPLAY_TOKEN("GE"); return GE; }
"!=" { DISPLAY_TOKEN("NE"); return NE; }
"==" { DISPLAY_TOKEN("EQ"); return EQ; }
"+" { DISPLAY_TOKEN("PLUS"); return PLUS; }
"-" { DISPLAY_TOKEN("MINUS"); return MINUS; }
"*" { DISPLAY_TOKEN("MUL"); return MUL; }
"/" { DISPLAY_TOKEN("DIV"); return DIV; }
"&&" { DISPLAY_TOKEN("AND"); return AND; }
"||" { DISPLAY_TOKEN("OR"); return OR; }
"!" { DISPLAY_TOKEN("NOT"); return NOT; }
"(" { DISPLAY_TOKEN("LP"); return LP; }
")" { DISPLAY_TOKEN("RP"); return RP; }
"[" { DISPLAY_TOKEN("LB"); return LB; }
"]" { DISPLAY_TOKEN("RB"); return RB; }
"{" { DISPLAY_TOKEN("LC"); return LC; }
"}" { DISPLAY_TOKEN("RC"); return RC; }
\n { yycolno = 1; }
[ \t]+ {}
. { printf("lexical error at line %d col %d: %s\n", yylineno, yycolno, yytext);; return -1; }
<<EOF>> { fprintf(stdout, "<<EOF>>\n"); return 0; }
%%
