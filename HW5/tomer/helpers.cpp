#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <utility>

#include <stdexcept>
#include "output.hpp"
#include "helpers.hpp"

using namespace std;
using namespace output;

vector<vector<STYPE> > ordered_symbols;
vector<STYPE> ordered_functions;
int position_of_last_function = 0;

SymbolTables initialzeSymbolTables() {
	SymbolTables symbol_tables;
	STYPE str_param = {"string", STRING_TYPE, vector<STYPE>(), 0};
	STYPE int_param = {"int", INT_TYPE, vector<STYPE>(), 0};
	vector<STYPE> print_args;
	print_args.push_back(str_param);
	vector<STYPE> printi_args;
	printi_args.push_back(int_param);
	STYPE print = {"print", VOID_TYPE, print_args, 0};
	STYPE printi = {"printi", VOID_TYPE, printi_args, 0};
	insertNewTableForScope(symbol_tables);
	symbol_tables[0].first[print.name] = print;
	symbol_tables[0].first[printi.name] = printi;
	return symbol_tables;
}

int getTop(SymbolTables& symbol_tables) {
	return symbol_tables.back().second;
}

int getLastTableCountOfLocalVars(SymbolTables& symbol_tables) {
	int count = 0;
	for (std::map<string,STYPE>::iterator it=symbol_tables.back().first.begin(); it!=symbol_tables.back().first.end(); ++it) {
    	if (it->second.offset >= 0){
    		count ++;
    	}
    }
	return count;
}

STYPE getSymbol(SymbolTables& symbol_tables, string symbol) {
	for (int i = symbol_tables.size() -1 ; i >= 0; --i) {
		map<string, STYPE>& table = symbol_tables[i].first;
		map<string, STYPE>::iterator it_table = table.find(symbol);
		if (it_table != table.end()){
			return it_table->second;
		}
	}
	throw runtime_error("getSymbol did not find the symbol");
}


bool isSymbolInSymbolTables(SymbolTables& symbol_tables, string symbol){
	for (int i = symbol_tables.size()-1 ; i >= 0 ; --i) {
		map<string, STYPE>& table = symbol_tables[i].first;
    	if (table.find(symbol) != table.end()){
    		return true;
    	}
	}
	return false;
}

bool isFunctionInSymbolTables(SymbolTables& symbol_tables, string name) {
	return (!symbol_tables.empty() && (symbol_tables[0].first.count(name)==1));
}

MyType getSymbolType(SymbolTables& symbol_tables, string symbol){
	for (int i = symbol_tables.size() -1 ; i >= 0; --i) {
		map<string, STYPE>& table = symbol_tables[i].first;
		map<string, STYPE>::iterator it_table = table.find(symbol);
    	if (it_table != table.end()){
    		return it_table->second.type;
    	}
	}
	throw runtime_error("getSymbolType did not find the symbol");
}

vector<STYPE> getFunctionArgs(SymbolTables& symbol_tables, string name) {
	if (symbol_tables.empty() || (symbol_tables[0].first.count(name)==0)) {
		throw runtime_error("getFunctionArgs did not find the symbol");
	}
	map<string, STYPE> funcmap =  symbol_tables[0].first;
	return funcmap[name].function_values;
}

void insertNewTableForScope(SymbolTables& symbol_tables){
	ordered_symbols.push_back(vector<STYPE>());

	if (!symbol_tables.empty()){
		symbol_tables.push_back(TableOffset(map<string, STYPE>(),symbol_tables.back().second));
	}
	else{
		symbol_tables.push_back(TableOffset(map<string, STYPE>(),0));
	}
}

void insertNewTableForFunction(SymbolTables& symbol_tables, STYPE parameters){
	ordered_symbols.push_back(vector<STYPE>());
	map<string, STYPE> new_table_map = map<string, STYPE>();
	vector<STYPE>& parameters_vec = parameters.function_values;
	for (int i = 0, designated_offset = - 1 ; i < parameters_vec.size(); ++i, --designated_offset) {
		parameters_vec[i].offset = designated_offset;
		new_table_map[parameters_vec[i].name] = parameters_vec[i];
		ordered_symbols.back().push_back(parameters_vec[i]);
	}

	symbol_tables.push_back(TableOffset(new_table_map,0));

}

const char* getStringFromMyType(MyType type) {
	switch (type) {
		case INT_TYPE: return "INT";
		case BYTE_TYPE: return "BYTE";
		case BOOL_TYPE: return "BOOL";
		case STRING_TYPE: return "STRING";
		case VOID_TYPE: return "VOID";
	}
}

// void printScopeSymbols(vector<STYPE>& symbols_vector) {
// 	for (int i=0; i<symbols_vector.size(); i++) {
// 		printID(symbols_vector[i].name.c_str(), symbols_vector[i].offset, 
// 			getStringFromMyType(symbols_vector[i].type));
// 	}
// }


// void printScopeFunctions() {
// 	for (int i=0; i<ordered_functions.size(); i++) {
// 		vector<const char*> arg_types;

// 		for (int j=0; j<ordered_functions[i].function_values.size(); j++) {
// 			arg_types.push_back(getStringFromMyType(
// 				ordered_functions[i].function_values[j].type));
// 		}
// 		string func_type = makeFunctionType(
// 			getStringFromMyType(ordered_functions[i].type), arg_types);

// 		printID(ordered_functions[i].name.c_str(), ordered_functions[i].offset, 
// 			func_type.c_str());
// 	}
// }

void takeOutLastTable(SymbolTables& symbol_tables){
	if (position_of_last_function == symbol_tables.size()-1){
		position_of_last_function--;
	}
	// endScope();
	if (symbol_tables.size() == 1) {
		// printScopeFunctions();
	} else {
		// printScopeSymbols(ordered_symbols.back());
		ordered_symbols.pop_back();
	}
	symbol_tables.pop_back();

}

void insertNewValIntoTable(SymbolTables& symbol_tables, STYPE newVal){
	TableOffset& last_table_offset = symbol_tables.back();
	int last_offset = last_table_offset.second;
	newVal.offset = last_offset;
	last_table_offset.second = last_offset + 1;
	last_table_offset.first[newVal.name] = newVal;
	ordered_symbols.back().push_back(newVal);
}

void insertNewFunctionIntoTable(SymbolTables& symbol_tables, STYPE newFunction){
	TableOffset& last_table_offset = symbol_tables.back();
	newFunction.offset = 0;
	last_table_offset.first[newFunction.name] = newFunction;
	ordered_functions.push_back(newFunction);
}

void handleNewFunction(SymbolTables& symbol_tables, STYPE function) {
	position_of_last_function++;
	insertNewFunctionIntoTable(symbol_tables, function);
	insertNewTableForFunction(symbol_tables, function);
}

MyType getFunctionRetType(string func_name){
	if (func_name.compare("print") != 0 && func_name.compare("printi") != 0){
		for (int i = 0; i < ordered_functions.size(); ++i) {
	    	if (ordered_functions[i].name.compare(func_name) == 0){
	    		return ordered_functions[i].type;
	    	}
		}
		throw runtime_error("getSymbolType did not find the symbol");
	}
	return VOID_TYPE;
}

int getNumberOfArgumentsOfLastFunction(){
	return ordered_functions.back().function_values.size();
}

int getCountOfLocalVarsUntilFunction(SymbolTables& symbol_tables){


	int count = 0;
	for (int i = symbol_tables.size()-1; i >= position_of_last_function; --i){
		for (std::map<string,STYPE>::iterator it=symbol_tables[i].first.begin(); it!=symbol_tables[i].first.end(); ++it) {
	    	if (it->second.offset >= 0){
	    		count ++;
	    	}
	    }
	}
	return count;
}