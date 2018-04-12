%{
#include <stdio.h>
#include <string.h>
char array[9999];
void PrintToken(char* token);
%}

%option yylineno
%option noyywrap
%x COMMENT

STARTSTRUCT 	(---)
ENDSTRUCT 		(\.\.\.)
LLIST 			(\[)
RLIST 			(\])
LDICT 			(\{)
RDICT 			(\})
KEY 			(:)
COMPLEXKEY			(\?)
ITEM			(-)
COMMA			(,)
TYPE			!![a-zA-Z]+
SPACE			[\t \n\r]+
CMNT			#[^\r\n]*(\r\n|\r|\n)




%%

{CMNT}				PrintToken("COMMENT");
.					{printf("Error %s\n", yytext); exit(0);}



%%

void PrintToken(char* token) {
	printf("%d %s %s\n", yylineno, token, yytext);
}