#ifndef __PARSER_H
#define __PARSER_H
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <utility>

using namespace std;



enum MyType
{
	INT_TYPE,
	BYTE_TYPE,
	BOOL_TYPE,
	STRING_TYPE,
	VOID_TYPE
};

struct STYPE
{
	string name;
	MyType type;
	vector<STYPE> function_values;
	int offset;
	string value;

	string reg;
	vector<int> false_list;
	vector<int> true_list;
	vector<int> next_list;
	vector<int> break_list;
	vector<string> value_list;
	vector<string> quad_list;
	string quad;
	string start_exp;
	vector<int> after_exp;


};

typedef pair<map<string, STYPE>, int> TableOffset;
typedef vector<TableOffset> SymbolTables;



#define YYSTYPE STYPE	// Tell Bison to use STYPE as the stack type




#endif