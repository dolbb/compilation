#ifndef __SYMBOL_TABEL
#define __SYMBOL_TABEL
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "parser.hpp"
#include "output.hpp"
#include "bp.hpp"

#ifndef YYERROR_VERBOSE
#define YYERROR_VERBOSE 0 
#endif

using namespace std;
using namespace output;


typedef struct {
	string name;
	VariableType type;
	unsigned int offset;
} VariableEntry;

typedef struct {
	string name;
	VariableType returnType;
	vector<VariableType> argTypes;
	vector<string> argTypesNames;
	string implementation; //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
} FunctionEntry;

typedef vector<VariableEntry> VariableTable;
typedef vector<FunctionEntry> FunctionTable;

//example: bool isA = isVarExists(_TablesStack.back(), "a");
bool isVarExists(const string& name);
//example: bool isFunA = isFunExists(_FunctionsStack, "funcA");
bool isFunExists(const string& name);
VariableType getVariableType(string name);
VariableType getFunctionReturnType(string name);
vector<VariableType>& getFunctionArgsTypes(string name);
void declareVariable(VariableType type, string name);
void declareArgument(VariableType type, string name);
void declareFunction(VariableType type, string name);
// VariableEntry& getVariable(string name);//$$$$$$$$$$$$$
VariableEntry getVariable(string name); // $$$$$$$$$$$$$$
void openScope();
void closeScope();
void closeGlobalScope();
FunctionEntry& getFunction(string name);
void declarePrinti();
void declarePrint();
VariableType getReturnType();

bool isDefault();
void setIsDefault();

int scope_size();

#endif // __SYMBOL_TABEL