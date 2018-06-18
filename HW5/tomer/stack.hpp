#ifndef __STACK_H
#define __STACK_H
#include "parser.hpp"
#include <string>

class Stack {
    static int getStackOffset(string symbol_name, SymbolTables&);
public:
    // needs to be called when declaring a variable
    static void push();
    static void pop(int);
    static void load(string symbol_name, SymbolTables&, string reg);
    static void store(string symbol_name, SymbolTables&, string reg);
    static void storeRegister(string);
    static void restoreRegister(string);
    static void storeFP();

};

#endif