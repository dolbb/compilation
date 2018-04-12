%{
#include <stdio.h>
#include <string.h>
char array[9999];
void PrintToken(char* token);
void PrintInteger();
int StartsWith(const char *a, const char *b);
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
INTEGER			(0x[0-9a-fA-F]+)|(0o[0-7]+)|([-+]?[0-9]+)
REAL			([-+]?\.[0-9]+)|([-+]?[0-9]+\.[0-9]*)
EXPONENT		e[-+][0-9]+




%%

"#"					{BEGIN(COMMENT); }
<COMMENT>"\r\n"  	{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\r"		{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\n"		{printf("%d COMMENT %s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT><<EOF>>	{printf("%d COMMENT %s\n", yylineno, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>.			{sprintf(array,"%s%s",array,yytext);}

{STARTSTRUCT}		PrintToken("STARTSTRUCT");
{ENDSTRUCT}			PrintToken("ENDSTRUCT");
{LLIST}				PrintToken("LLIST");
{RLIST}				PrintToken("RLIST");
{LDICT}				PrintToken("LDICT");
{RDICT}				PrintToken("RDICT");
{KEY}				PrintToken("KEY");
{COMPLEXKEY}		PrintToken("COMPLEXKEY");
{ITEM}				PrintToken("ITEM");
{COMMA}				PrintToken("COMMA");
{TYPE}				PrintToken("TYPE");
{INTEGER}			PrintInteger();
{REAL}{EXPONENT}?	PrintToken("REAL");
".inf"|".NaN"		PrintToken("REAL");



{SPACE}		;
.					{printf("Error %s\n", yytext); exit(0);}



%%

void PrintToken(char* token) {
	printf("%d %s %s\n", yylineno, token, yytext);
}

void PrintInteger() {
	if (StartsWith("0x",yytext) == 1 || StartsWith("0o",yytext) == 1) PrintToken("INTEGER");
	else printf("%d INTEGER %d\n", yylineno, atoi(yytext));
}











int StartsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(a)) == 0) return 1;
   return 0;
}


