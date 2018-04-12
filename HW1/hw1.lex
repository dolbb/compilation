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




%%

"#"					{BEGIN(COMMENT); }
<COMMENT>"\r\n"  	{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\r"		{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\n"		{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT><<EOF>>	{printf("%d COMMENT %s\n", yylineno, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>.			{sprintf(array,"%s%s",array,yytext);}

{SPACE}		;
.					{printf("Error %s\n", yytext); exit(0);}



%%

void PrintToken(char* token) {
	printf("%d %s %s\n", yylineno, token, yytext);
}