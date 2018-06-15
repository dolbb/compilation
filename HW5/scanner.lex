%{
    #include <stdio.h>
    #include <string.h>
    #include "commonHeader.hpp"
    #include "output.hpp"
    #include "parser.tab.hpp"

    using namespace output;
    using std::string;

    int identifierName();
    int numberHandler();
    int stringHandler();
    void errorHandler();
%}

%option yylineno
%option noyywrap

%%
void                              return VOID;
int                               return INT;
byte                              return BYTE;
b                                 return B;
bool                              return BOOL;
and                               return AND;
or                                return OR;
not                               return NOT;
true                              return TRUE;  
false                             return FALSE; 
return                            return RETURN;
if                                return IF;
else                              return ELSE;
while                             return WHILE;
break                             return BREAK;
;                                 return SC;
,                                 return COMMA;
\(                                return LPAREN;
\)                                return RPAREN;
\{                                return LBRACE;
\}                                return RBRACE;
\[                                return LBRACK;         
\]                                return RBRACK;
=                                 return ASSIGN;
(==)                              return EQUAL;              
(!=)                              return NOT_EQUAL;              
(<)                               return SMALLER_THAN;             
(>)                               return GREATER_THAN;            
(<=)                              return SMALLER_EQ_THAN;               
(>=)                              return GREATER_EQ_THAN;                                         
\+                                return PLUS;
-                                 return MINUS;
\*                                return MULT;
\/                                return DIV;
[a-zA-Z][a-zA-Z0-9]*              return identifierName();
(0|[1-9][0-9]*)                   return numberHandler();
\"([^\n\r\"\\]|\\[rnt\"\\])+\"    return stringHandler();
[\t\n\r ]                         ;   //all space variations  - IGNORE.
\/\/[^\r\n]*[\r|\n|\r\n]?         ;   //inline comments       - IGNORE.
.                                 errorHandler();

%%

int identifierName(){
  yylval = new String(yytext);
  return ID;
}

int numberHandler(){
  yylval = new Num(yytext);
  return NUM;
}

int stringHandler(){
  yylval = new String(yytext);
  return STRING;
}

void errorHandler() {
	errorLex(yylineno);
	exit(1);
}

