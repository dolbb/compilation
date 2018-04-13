%{
#include <stdio.h>
#include <string.h>
char array[9999];
char str[0];
void PrintToken(char* token);
void PrintInteger();
void HandleEscape();
int StartsWith(const char *a, const char *b);
%}

%option yylineno
%option noyywrap
%x COMMENT STR1 STR2 STR2TERMINATED

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
TRUE			true
FALSE			false
SPACE			[\t \n\r]+
INTEGER			(0x[0-9a-fA-F]+)|(0o[0-7]+)|([-+]?[0-9]+)
REAL			([-+]?\.[0-9]+)|([-+]?[0-9]+\.[0-9]*)
EXPONENT		e[-+][0-9]+
NEWLINE			(\r\n|\r|\n)
ESCAPE			(\\r)|(\\n)|(\\\\)|(\\a)|(\\b)|(\\e)|(\\f)|(\\t)|(\\v)|(\\x[0-9a-fA-F]{2})|(\\\")
ESCAPETERMINATE	(\\0)
VAL				[a-zA-Z]{1}[a-zA-Z0-9]*
DECLARATION		&[a-zA-Z]+
DEREFERENCE		\*[a-zA-Z]+



%%

"#"					{BEGIN(COMMENT); }
<COMMENT>"\r\n"  	{printf("%d COMMENT #%s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\r"		{printf("%d COMMENT #%s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT>"\n"		{printf("%d COMMENT #%s\n", yylineno-1, array); array[0]='\0';BEGIN(INITIAL);}
<COMMENT><<EOF>>	{printf("%d COMMENT #%s\n", yylineno, array); {printf("%d EOF \n", yylineno); exit(0);}}
<COMMENT>.			{sprintf(array,"%s%s",array,yytext);}

"'"					{BEGIN(STR1); }
<STR1><<EOF>>		{printf("Error unclosed string\n"); exit(0);}
<STR1>"'"			{printf("%d STRING %s\n", yylineno, array); array[0]='\0';BEGIN(INITIAL);}
<STR1>{NEWLINE}		{sprintf(array,"%s%s",array,yytext);}
<STR1>.				{sprintf(array,"%s%s",array,yytext);}

"\""				{BEGIN(STR2); }
<STR2>{ESCAPETERMINATE} {BEGIN(STR2TERMINATED); }
<STR2><<EOF>>		{printf("Error unclosed string\n");	exit(0);}
<STR2>"\""			{printf("%d STRING %s\n", yylineno, array); array[0]='\0';BEGIN(INITIAL);}
<STR2>{NEWLINE}		{sprintf(array,"%s%s",array," ");}
<STR2>{ESCAPE}		{HandleEscape();}
<STR2>"\\".			{printf("Error undefined escape sequence %s\n", ++yytext); exit(0);}
<STR2>.				{sprintf(array,"%s%s",array,yytext);}

<STR2TERMINATED>"\""			{printf("%d STRING %s\n", yylineno, array); array[0]='\0';BEGIN(INITIAL);}
<STR2TERMINATED><<EOF>> 		{printf("Error unclosed string\n");	exit(0);}
<STR2TERMINATED>{NEWLINE}		;
<STR2TERMINATED>{ESCAPE}		;
<STR2TERMINATED>"\\".			;
<STR2TERMINATED>.				;




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
{TRUE}				PrintToken("TRUE");
{FALSE}				PrintToken("FALSE");
{INTEGER}			PrintInteger();
{REAL}{EXPONENT}?	PrintToken("REAL");
".inf"|".NaN"		PrintToken("REAL");
{VAL}				PrintToken("VAL");
{DECLARATION}		PrintToken("DECLARATION");
{DEREFERENCE}		PrintToken("DEREFERENCE");


{SPACE}		;
<<EOF>>				{printf("%d EOF \n", yylineno); return 0;}
.					{printf("Error %s\n", yytext); exit(0);}



%%

void PrintToken(char* token) {
	printf("%d %s %s\n", yylineno, token, yytext);
}

void PrintInteger() {
	if (StartsWith("0x",yytext) == 1) 		printf("%d INTEGER %d\n", yylineno, (int)strtol(yytext, NULL, 16));
	else if (StartsWith("0o",yytext) == 1) 	{
		yytext[1]='0';
		yytext++;		
		printf("%d INTEGER %d\n", yylineno, (int)strtol(yytext, NULL, 8));
	}
	else 									printf("%d INTEGER %d\n", yylineno, atoi(yytext));
}

void HandleEscape() {
	int i;
	if (StartsWith("\\r",yytext) == 1) sprintf(array,"%s%s",array,"\r");
	else if (StartsWith("\\n",yytext) == 1) sprintf(array,"%s%s",array,"\n");
	else if (StartsWith("\\t",yytext) == 1) sprintf(array,"%s%s",array,"\t");
	else if (StartsWith("\\\\",yytext) == 1) sprintf(array,"%s%s",array,"\\");
	else if (StartsWith("\\\"",yytext) == 1) sprintf(array,"%s%s",array,"\"");
	else if (StartsWith("\\a",yytext) == 1) sprintf(array,"%s%s",array,"\a");
	else if (StartsWith("\\b",yytext) == 1) sprintf(array,"%s%s",array,"\b");
	else if (StartsWith("\\e",yytext) == 1) sprintf(array,"%s%s",array,"\e");
	else if (StartsWith("\\f",yytext) == 1) sprintf(array,"%s%s",array,"\f");
	else if (StartsWith("\\v",yytext) == 1) sprintf(array,"%s%s",array,"\v");
	else if (StartsWith("\\0",yytext) == 1) sprintf(array,"%s%s",array,"\0");
	else if (StartsWith("\\t",yytext) == 1) sprintf(array,"%s%s",array,"\t");
	else {
		//printf("this is %s\n",yytext);
		yytext[0]='0';
		i = (int)strtol(yytext, NULL, 16);
		if (i == 0) {
			BEGIN(STR2TERMINATED);
			return;
		}
		str[0]=i;
		//printf("and the int is %d\n",i);
		//printf("and the char is %c\n", str[0]);
		sprintf(array,"%s%s",array,str);
	}
	
}



int StartsWith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(a)) == 0) return 1;
   return 0;
}

