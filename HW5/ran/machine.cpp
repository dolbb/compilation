#include "machine.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define $RA "$ra"
#define $SP "$sp"
#define $SP_ADDRSS "($sp)"

RegisterManager mgr;
AssemblyCommands asem;
SymbolsTable symbolsTable;
AssemblyStack asmStack;


void updateArrEntry(){
	
	string reg1 = mgr.getReg();
	std::cout << "reg1 is " << reg1 << std::endl;
	mgr.storeToRegImm(reg1, 0);
	
	symbolsTable.addSymbol("x", TypeInfo(DATA_INT, 2) );
	symbolsTable.addSymbol("y", TypeInfo(DATA_INT, 3) );
	string reg2 = mgr.getReg();
	std::cout << "reg2 is " << reg2 << std::endl;
	mgr.storeToRegImm(reg2, 9);
	
	asmStack.addNewVar("x",symbolsTable);
	asmStack.addNewVar("y",symbolsTable);
	asmStack.updateArrEntry("y",symbolsTable,reg1,reg2);
}


int main(){
	symbolsTable.addScope();
	
	updateArrEntry();
	//symbolsTable.addScope();
	
	//symbolsTable.addSymbol("x", TypeInfo(DATA_INT, 1) );
	//string reg1 = mgr.getReg();
	//std::cout << "reg1 is " << reg1 << std::endl;
	//mgr.storeToRegImm(reg1, 1);
	
	//symbolsTable.addSymbol("y", TypeInfo(DATA_INT, 3) );
	//string reg2 = mgr.getReg();
	//std::cout << "reg2 is " << reg2 << std::endl;
	//mgr.storeToRegImm(reg2, 3);
	
	
	
	
	//symbolsTable.addSymbol("z", TypeInfo(DATA_INT, 1) );
	//mgr.storeRegsToStack();
	//mgr.loadRegsFromStack();
	
	//int fpOffset = symbolsTable.getSymbolOffset("x");
	//asmStack.getFPOffset("x", symbolsTable);
	//std::cout << fpOffset << std::endl;
	
	
	//asmStack.addNewVar("x",symbolsTable);
	//asmStack.addNewVar("y",symbolsTable);
	//asmStack.updateArrEntry("y",symbolsTable,reg1,reg2);
	//asmStack.addNewVar("z",symbolsTable,reg2);
	//asem.multiply(reg1,reg2,false);
	//asmStack.updateVar("z",symbolsTable,reg1);
	
	
	//reg1 = asmStack.loadVar("x",symbolsTable);
	//reg2 = asmStack.loadVar("y",symbolsTable);
	//std::cout << "reg1 is " << reg1 << std::endl;
	//
	//string reg2 = mgr.getRegAndPromote();
	//string reg3 = mgr.getRegAndPromote();
	
	
	//mgr.storeToRegImm(reg2, 4);
	//mgr.storeToRegImm(reg3, 3);
	
	//asem.add(reg1,reg2, true);
	//asem.divide(reg1,reg2,false);
	//asem.multiply(reg1,reg2,false);
	//asem.sub(reg1,reg2, false);
	
	
	//mgr.freeReg(reg1);
	
	
	
	
	mgr.print();
	//std::cout << mgr.getRegAndPromote() << std::endl;
	//std::cout << mgr.getRegAndPromote() << std::endl;
}

