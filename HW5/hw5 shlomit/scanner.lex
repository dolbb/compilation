%{
    #define DEBUG3
	#include <stdio.h>
	#include "parser.hpp"
	#include "compiler.hpp"
    #include "parser.tab.hpp"
	#include "output.hpp"
    #include <iostream>
	#include "bp.hpp"
	#include <sstream>
    using namespace std;
	
	


%}

%option yylineno
%option noyywrap

whitespace		([\t\n\r ])
line_comment    ("//".*)
newline		([\n\r])
%%

[\(] { return LPAREN;}
[\)] { return RPAREN;}
[\{] { return LBRACE;}
[\}] { return RBRACE;}
[\;] { return SC;}
[\:] { return COLON;}
[\,] { return COMMA;}
[\=] { return ASSIGN;}
[\+] { return PLUS; }
[\-] { return MINUS; }
[\*] { return MULT; }
[\/] { return DIV; }
(\<=|\>=|\<|\>)  { 
/*
	if(yytext == "<="){
		yylval.relop = LE;
	}
	else if(yytext == ">="){
		yylval.relop = GE;
	}
	else if(yytext == "<"){
		yylval.relop = LT;
	}
	else {//if(yytext == ">")
		yylval.relop = GT;
	}
	*/
	if(yytext[0] == '<'){
		if(yytext[1] == '='){
			yylval.relop = LE;
		} else {
			yylval.relop = LT;
		}		
	} else {
		if(yytext[1] == '='){
			yylval.relop = GE;
		} else {
			yylval.relop = GT;	
		}	
	}
	
	return RELOP;
}
(==|!=)  {
	if(yytext[0] == '='){
		yylval.relop = EQ;
	}
	else{
		yylval.relop = NE;
	}
	return RELEQ;
 }
and { return AND; }
or  { return OR; }
b { return B; }
int { return INT; }
byte { return BYTE; }
void { return VOID; }
return { return RETURN; }
true { return TRUE; }
false { return FALSE; }
if { return IF; }
else { return ELSE; }
while { return WHILE; }
break { return BREAK; }
not { return NOT; }
bool { return BOOL; }
switch { return SWITCH; }
case { return CASE; }
default { return DEFAULT; }

 \"([^\n\r\"\\]|\\[rnt"\\])+\" {
	yylval.str = yytext;
	yylval.str = yylval.str.substr(1, yylval.str.length() - 2);
	return STRING; 
}
[a-zA-Z][a-zA-Z0-9]* { 
	yylval.name = yytext;
	return ID; 
}
([1-9][0-9]*|0) { 
	yylval.name = yytext;
	yylval.num = atoi((string(yytext)).c_str());
	return NUM; 
}

{newline}		{
    ostringstream os;
	os << yylineno;
	CODE.emit("######## \t line " + os.str() + ": \t ########");}
{whitespace}   	{}
{line_comment} 	{}

. {
	output::errorLex(yylineno);
	exit(1);
}

%%