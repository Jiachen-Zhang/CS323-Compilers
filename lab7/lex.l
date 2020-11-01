%{
    #include"syntax.tab.h"
    #include"json_define.h"
%}
%option noyywrap

unic u[0-9a-fA-F]{4}
esc \\([\"\\/bfnrt]|{unic})
scp [^"\\\x00-\x1f]
string \"({esc}|{scp})*\"

int 0$|[1-9][0-9]*
frac \.[0-9]+
exp [Ee][+-]?[0-9]+
number -?{int}{frac}?{exp}?

empty [ \n\r\t]

%%

"{" { return LC; }
"}" { return RC; }
"[" { return LB; }
"]" { return RB; }
":" { return COLON; }
"," { return COMMA; }

"true" { JsonObject *jsonObject = newJsonObject(CategoryEnum.BOOLEAN, true); yylval.jsonObject = jsonObject; return TRUE; }
"false" { JsonObject *jsonObject = newJsonObject(CategoryEnum.BOOLEAN, false); yylval.jsonObject = jsonObject; return FALSE; }
"null" { JsonObject *jsonObject = newJsonObject(CategoryEnum.VNULL, NULL); yylval.jsonObject = jsonObject; return VNULL; }

{string} { yylval.string = yytext; return STRING; }
{number} { yylval.number = atof(yytext); return NUMBER; }

{empty} {}

. { printf("lexical error: %s\n", yytext); }
