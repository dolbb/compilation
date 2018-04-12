%{
/* declarations section */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void ToToken(char *);
void StringToToken(int StartCondition);
char buffer[10000];
%}

%option yylineno
%option noyywrap
%x  STREAM STRI1 STRI2

STREAMLINE	[^\n\r]
NEWLINE		(\r\n|\r|\n)
LBRACE		(\[)
RBRACE		(\])
COMMENT		%[^\r\n]*
TRUE		(true)
FALSE		(false)
INTEGER		([+-]?[0-9]+)
REAL		[+-]?([0-9]+[.]([0-9]*)?|[.][0-9]+)
STR			\((\\.|[^()\\]|(\\[0-7]{3}))*\)|([<](([ ]*[a-fA-F0-9]{1}[ ]*[a-fA-F0-9]{1}[ ]*)*)[>])
STRING		([(](\\([()bnrtf]|\n|\\)|[^\\\n\v\f\r\a\b\t\(\)\0]|(\\[0-7]{3}))*[)])|([<](([ ]*[a-fA-F0-9]{1}[ ]*[a-fA-F0-9]{1}[ ]*)*)[>])
NAME		\/[a-zA-Z0-9]+
NULL		(null)
ESCAPE_ER			([(]((\\[()\n\\bnrtf])|[^\\\n\v\f\r\a\b\t\(\)\0]|(\\[0-7]{3}))*[)])|([<](([ ]*[a-fA-F0-9]{1}[ ]*[a-fA-F0-9]{1}[ ]*)*)(\\[^()\n\\bnrtf]))
INCOMPLETE_BYTE_ER ([<](([ ]*[a-fA-F0-9]{1}[ ]*[a-fA-F0-9]{1}[ ]*)*[a-fA-F0-9]{1}[ ]*)[>])
UNCLOSED_STRING_ER_TYPE1	([(]((\\[)(\\brtf])|[^\\\n\v\f\r\a\b\t\(\)\0]|(\\[0-7]{3}))*)
UNCLOSED_STRING_ER_TYPE2	([<](([ ]*[a-fA-F0-9]{1}[ ]*[a-fA-F0-9]{1}[ ]*)*))
SPACE				[\t \n\r]+
ESCAPE			[\\\v\f\r\a\b\t\(\)\0]
STRINGLINE		[^\n\r\\\(\)]
STRING2LINE		[a-fA-F0-9 \n\t\r]
NOTSTRING2LINE	[^a-fA-F0-9 \n\t\r]


%%

"stream"{NEWLINE}			{ BEGIN(STREAM);}
<STREAM>{NEWLINE}endstream		{ printf("%d STREAM %s\n",yylineno,buffer);buffer[0]='\0';BEGIN(INITIAL);}
<STREAM>{STREAMLINE}*				{sprintf(buffer,"%s%s",buffer,yytext);}
<STREAM>{NEWLINE}		{sprintf(buffer,"%s%s",buffer,yytext);}
<STREAM><<EOF>>			{printf("Error unclosed stream\n");exit(0);}
<STRI1>{STRINGLINE}*\)				{StringToToken(1);BEGIN(INITIAL);}
<STRI1>{NEWLINE}			{printf("Error %c\n",yytext[0]); exit(0);}
<STRI1>\\{NEWLINE}			;
<STRI1>{ESCAPE}{STRINGLINE}+	{printf("Error undefined escape sequence %c\n", yytext[1]); exit(0);}
<STRI1>{ESCAPE}			{printf("Error %c\n",yytext[yyleng-1]); exit(0);}
<STRI1>{STRINGLINE}*	{printf("Error unclosed string\n"); exit(0);}

<STRI2>{STRING2LINE}*\>	{StringToToken(2);BEGIN(INITIAL);}
<STRI2>{NEWLINE}		;
<STRI2>{STRING2LINE}*{NOTSTRING2LINE}			{printf("Error %c\n",yytext[yyleng-1]); exit(0);}
<STRI2>{STRING2LINE}*	{printf("Error unclosed string\n"); exit(0);}
"obj"					ToToken("OBJ");
"endobj"				ToToken("ENDOBJ");
{LBRACE}				ToToken("LBRACE");
{RBRACE}				ToToken("RBRACE");
"<<"					ToToken("LDICT");
">>"					ToToken("RDICT");
{COMMENT}				ToToken("COMMENT");
{TRUE}					ToToken("TRUE");
{FALSE}					ToToken("FALSE");
{INTEGER}				ToToken("INTEGER");
{REAL}					ToToken("REAL");
{STRING}				StringToToken(0);
{NAME}					ToToken("NAME");
{NULL}					ToToken("NULL");
{SPACE}					;
{ESCAPE_ER}				{printf("Error undefined escape sequence %c\n", yytext[yyleng-1]); exit(0);}
{UNCLOSED_STRING_ER_TYPE1}	BEGIN(STRI1);
{UNCLOSED_STRING_ER_TYPE2}	BEGIN(STRI2);
{INCOMPLETE_BYTE_ER}	{printf("Error incomplete byte\n"); exit(0);}
<<EOF>>					{printf("%d EOF \n", yylineno); return 0;}
.						{printf("Error %s\n", yytext); exit(0);}

%%
void ToToken(char * name) {
	printf("%d %s %s\n", yylineno, name, yytext);
}



void StringToToken(int StartCondition){
	if(StartCondition == 2 || yytext[0]=='<'){
		int matchi;
		if(StartCondition == 2){
			matchi=0;
		}
		else{
			matchi=1;
		}
		char parsedString[10000];
		char char_hex[2];
		int netoLength=0;
		int i;
		int hexatoint;
		int hasone=0;
		for (i=matchi; i<yyleng; i++){
			if(yytext[i]!=' '&&yytext[i]!='\n'&&yytext[i]!='\t'&&yytext[i]!='\r'&&yytext[i]!='>'&&hasone==0){
				char_hex[0] = yytext[i];
				hasone=1;
			}
			else if(yytext[i]!=' '&&yytext[i]!='\n'&&yytext[i]!='\t'&&yytext[i]!='\r'&&yytext[i]!='>'&&hasone==1){
				char_hex[1] = yytext[i];
				sscanf(char_hex,"%2x",&hexatoint);
				parsedString[netoLength++]= (char)hexatoint;
				// long s = strtol(char_hex, NULL, 10);
				// sprintf(parsedString+netoLength, "%c", (int)s);
				hasone=0;
			}
		}
		printf("%d ", yylineno);
		printf("STRING ");
		printf("%.*s\n", netoLength, parsedString);
	}
	else if(yytext[0]=='('||StartCondition == 1){
		int matchi;
		if(StartCondition == 1){
			matchi=0;
		}
		else{
			matchi=1;
		}
		char parsedString[10000];
		int i;
		int netoLength=0;
		for (i=matchi; i<yyleng; i++) {
			if (yytext[i] != '\\') {
				parsedString[netoLength] = yytext[i];
			}
			else {
				if (!isdigit(yytext[i+1])) { 						// in case of '\x' where x!=u
					char esc_char=0;
						switch(yytext[i+1]) {
							case '"':
								esc_char = '"';
								break;
							case '(':
								esc_char = '(';
								break;
							case ')':
								esc_char = ')';
								break;	
							case '\\':
								esc_char = '\\';
								break;
							case 'b':
								esc_char = '\b';
								break;
							case 'f':
								esc_char = '\f';
								break;
							case 'n':
								esc_char = '\n';
								break;
							case 'r':
								esc_char = '\r';
								break;
							case 't':
								esc_char = '\t';
								break;
							default:
								break;
						}
					if(esc_char == 0){
						netoLength--;
					}
					else{
					parsedString[netoLength] = esc_char;
					}
					i++;
				}
				else { 											// in case of '\uABCD' where A,B,C,D are in 0-7.
					i ++;
					char num_oct[3];								
					strncpy(num_oct, yytext+i, 3);					// get hexa number
					long n = strtol(num_oct, NULL, 8);				// get number in decimal
					char num_dec[3];
					sprintf(num_dec, "%ld", n);
					long num = strtol(num_dec, NULL, 10);
					char c = num;							
					sprintf(parsedString+netoLength, "%c", n);					
					i += 2;											// skip the 4 digits: the next i++													// we want.
				}
			}
			netoLength++;
		}
		printf("%d ", yylineno);
		printf("STRING ");
		printf("%.*s\n", netoLength-matchi, parsedString);
	}
	
	
}
//([\n\r])|(\n\r)
//(\x0D\x0A|\x0D|\x0A)
