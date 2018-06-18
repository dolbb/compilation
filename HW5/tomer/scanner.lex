%{
	/* declarations section */
	#include "parser.hpp"		
	#include <stdio.h>
	#include <string.h>
	#include "parser.tab.hpp"
	#include "output.hpp"
	#include "helpers.hpp"
	#include "output.hpp"
%}

%option yylineno
%option noyywrap

VOID 		(void)
INT			(int)
BYTE		(byte)
BOOL 		(bool)
BREAK		(break)
B 			(b)
AND			(and)
OR 			(or)
NOT			(not)
TRUE		(true)
FALSE		(false)
RETURN		(return)
IF			(if)
ELSE		(else)
WHILE		(while)
SWITCH		(switch)
CASE		(case)
COLON		[:]
SC 			[;]
COMMA		[,]
LPAREN		[(]
RPAREN		[)]
LBRACE		[{]
RBRACE		[}]
RELOP_COMP	(<|>|<=|>=)
RELOP_EQ	(==|!=)
ASSIGN		[=]
BINOP_ADD	[+-]
BINOP_MULT	[*/]
ID 			[a-zA-Z][a-zA-Z0-9]*
NUM			(0|[1-9][0-9]*)
STRING 		["]([^\n\r\"\\]|\\[rnt"\\])+["]
WHITESPACE	[ \n\t\r]+
LN_COMMENT	\/\/[^\r\n]*([\r\n]|(\r\n))?
		
%%

{VOID} 		{return VOID;}
{INT}			{return INT;}
{BYTE}		{return BYTE;}
{BOOL} 		{return BOOL;}
{BREAK}		{return BREAK;}
{B} 			{return B;}
{AND}			{return AND;}
{OR} 			{return OR;}
{NOT}			{return NOT;}
{TRUE}		{return TRUE;}
{FALSE}		{return FALSE;}
{RETURN}		{return RETURN;}
{IF}			{return IF;}
{ELSE}		{return ELSE;}
{WHILE}		{return WHILE;}
{SWITCH}		{return SWITCH;}
{CASE}		{return CASE;}
{COLON}		{return COLON;}
{SC} 			{return SC;}
{COMMA}		{return COMMA;}
{LPAREN}		{return LPAREN;}
{RPAREN}		{return RPAREN;}
{LBRACE}		{return LBRACE;}
{RBRACE}		{return RBRACE;}
{RELOP_COMP}	{yylval.value = yytext; return RELOP_COMP;}
{RELOP_EQ}	{yylval.value = yytext; return RELOP_EQ;}
{ASSIGN}		{return ASSIGN;}
{BINOP_ADD}	{yylval.value = yytext; return BINOP_ADD;}
{BINOP_MULT}	{yylval.value = yytext; return BINOP_MULT;}
{ID} 			{yylval.name = yytext; return ID;}
{NUM}			{yylval.value = yytext; return NUM;}
{STRING} 		{yylval.value = yytext; return STRING;}
{WHITESPACE}	;
{LN_COMMENT}	;

. 				{
					output::errorLex(yylineno);
					exit(0);
				}
%%