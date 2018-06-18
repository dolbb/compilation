#ifndef __HELPERS_H
#define __HELPERS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <utility>

#include "parser.hpp"
using namespace std;

SymbolTables initialzeSymbolTables();

int getTop(SymbolTables&);

int getLastTableCountOfLocalVars(SymbolTables&);

STYPE getSymbol(SymbolTables&, string);

bool isSymbolInSymbolTables(SymbolTables&, string);

bool isFunctionInSymbolTables(SymbolTables&, string);

MyType getSymbolType(SymbolTables&, string);

vector<STYPE> getFunctionArgs(SymbolTables&, string);

void insertNewTableForScope(SymbolTables&);

void insertNewTableForFunction(SymbolTables&, STYPE);

const char* getStringFromMyType(MyType);

void takeOutLastTable(SymbolTables&);

void insertNewValIntoTable(SymbolTables&, STYPE);

void insertNewFunctionIntoTable(SymbolTables&, STYPE);

void handleNewFunction(SymbolTables&, STYPE);

MyType getFunctionRetType(string);

int getNumberOfArgumentsOfLastFunction();

int getCountOfLocalVarsUntilFunction(SymbolTables&);



#endif
