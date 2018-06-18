#include "stack.hpp"
#include "bp.hpp"
#include "helpers.hpp"
#include <iostream>
#include <sstream>

using namespace std;


// int Stack::getStackOffset(string symbol_name, SymbolTables& symbol_tables) {
//     int top = getTop(symbol_tables);
//     int offset = getSymbol(symbol_tables, symbol_name).offset;
//     return (top-offset-1)*4;
// }

int Stack::getStackOffset(string symbol_name, SymbolTables& symbol_tables) {
    int offset = getSymbol(symbol_tables, symbol_name).offset;
    return -(offset+1)*4;
}

void Stack::push() {
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    stringstream push_code;
    push_code << "subu $sp, $sp, 4 #push";
    codeBuffer.emit(push_code.str());
}

void Stack::pop(int i) {
    if (i != 0){
        CodeBuffer& codeBuffer = CodeBuffer::instance();
        int num_to_pop = 4*i;
        stringstream push_code;
        push_code << "addu $sp, $sp, " << num_to_pop <<" #pop";
        codeBuffer.emit(push_code.str());
    }
}

// void Stack::load(string symbol_name, SymbolTables& symbol_tables, string reg) {
//     int stack_offset = getStackOffset(symbol_name, symbol_tables);
//     CodeBuffer& codeBuffer = CodeBuffer::instance();
//     stringstream push_code;
//     push_code << "lw " << reg << ", " << stack_offset << "($sp)";
//     codeBuffer.emit(push_code.str());
// }

// void Stack::store(string symbol_name, SymbolTables& symbol_tables, string reg) {
//     int stack_offset = getStackOffset(symbol_name, symbol_tables);
//     CodeBuffer& codeBuffer = CodeBuffer::instance();
//     stringstream push_code;
//     push_code << "sw " << reg << ", " << stack_offset << "($sp)";
//     codeBuffer.emit(push_code.str());
// }

void Stack::load(string symbol_name, SymbolTables& symbol_tables, string reg) {
    int stack_offset = getStackOffset(symbol_name, symbol_tables);
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    stringstream push_code;
    push_code << "lw " << reg << ", " << stack_offset << "($fp) #load";
    codeBuffer.emit(push_code.str());
}

void Stack::store(string symbol_name, SymbolTables& symbol_tables, string reg) {
    int stack_offset = getStackOffset(symbol_name, symbol_tables);
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    stringstream push_code;
    push_code << "sw " << reg << ", " << stack_offset << "($fp) #store";
    codeBuffer.emit(push_code.str());
}

void Stack::storeRegister(string reg){
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    push();
    stringstream push_code;
    push_code << "sw " << reg << ", ($sp) #storeRegister";
    codeBuffer.emit(push_code.str());
}

void Stack::restoreRegister(string reg){
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    stringstream push_code;
    push_code << "lw " << reg << ", ($sp) #restoreRegister";
    codeBuffer.emit(push_code.str());
    pop(1);
}

void Stack::storeFP(){
    CodeBuffer& codeBuffer = CodeBuffer::instance();
    push();
    stringstream push_code;
    push_code << "sw $fp, ($sp) #storeFP";
    codeBuffer.emit(push_code.str());   
}
