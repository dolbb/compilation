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


void updateArr(){
	
	string reg1 = mgr.getReg();
	std::cout << "reg1 is " << reg1 << std::endl;
	mgr.storeToRegImm(reg1, 2);
	
	string reg2 = mgr.getReg();
	std::cout << "reg2 is " << reg2 << std::endl;
	mgr.storeToRegImm(reg2, 9);
	
	symbolsTable.addSymbol("x", TypeInfo(DATA_INT, 3) );
	symbolsTable.addSymbol("z", TypeInfo(DATA_INT, 1) );
	symbolsTable.addSymbol("y", TypeInfo(DATA_INT, 3) );
	
	asmStack.addNewVar("x",symbolsTable);
	asmStack.addNewVar("z",symbolsTable);
	asmStack.addNewVar("y",symbolsTable);
	asmStack.updateArrEntry("x",symbolsTable,reg1,reg2); //x[2]=9
	
	string reg3 = mgr.getReg();
	asmStack.getArrEntry("x",symbolsTable,reg1,reg3);
	
	asmStack.updateVar("y",symbolsTable,"","x"); //y[]=x[]
}

void functionArgs(){
	
	vector<TypeInfo> args;
    args.push_back(TypeInfo(DATA_INT));
    string funcName = string("test");
    Func func(funcName, args, TypeInfo(DATA_VOID));
	symbolsTable.addFuncSymbol(func);
	
	symbolsTable.addArgSymbol("x", TypeInfo(DATA_INT, 1) );
	asmStack.addNewVar("x",symbolsTable);
	symbolsTable.addArgSymbol("y", TypeInfo(DATA_INT, 1) );
	asmStack.addNewVar("y",symbolsTable);
	symbolsTable.addSymbol("z", TypeInfo(DATA_INT, 1) );
	asmStack.addNewVar("y",symbolsTable);
	
	string reg1 = mgr.getReg();
	std::cout << "reg1 is x" << reg1 << std::endl;
	mgr.storeToRegImm(reg1, 1);
	
	string reg2 = mgr.getReg();
	std::cout << "reg2 is y" << reg2 << std::endl;
	mgr.storeToRegImm(reg2, 2);
	
	string reg3 = mgr.getReg();
	std::cout << "reg3 is z" << reg3 << std::endl;
	mgr.storeToRegImm(reg3, 3);
	
	asmStack.updateVar("x",symbolsTable,reg1); 
	asmStack.updateVar("y",symbolsTable,reg2); 
	asmStack.updateVar("z",symbolsTable,reg3); 
}

void callFunc(){
	string reg1 = mgr.getReg();
	std::cout << "reg1 is x" << reg1 << std::endl;
	mgr.storeToRegImm(reg1, 2);
	
	string reg2 = mgr.getReg();
	std::cout << "reg2 is y" << reg2 << std::endl;
	mgr.storeToRegImm(reg2, 9);
	
	string reg3 = mgr.getReg();
	std::cout << "reg3 is z" << reg3 << std::endl;
	mgr.storeToRegImm(reg3, 3);
	
		
	vector<TypeInfo> args;
	
	TypeInfo type1 = TypeInfo(DATA_INT);
	type1.reg = reg1;
		
	TypeInfo type2 = TypeInfo(DATA_INT,3);
	type2.id = "x";
	symbolsTable.addSymbol("x", type2 );
	asmStack.addNewVar("x",symbolsTable);
	asmStack.updateArrEntry("x",symbolsTable,reg1,reg2); //x[2]=9
	
	TypeInfo type3 = TypeInfo(DATA_INT);
	type3.reg = reg3;
	
    args.push_back(type1);
	args.push_back(type2);
	args.push_back(type3);
    
	string funcName = string("test");
    Func func(funcName, args, TypeInfo(DATA_VOID));
	symbolsTable.addFuncSymbol(func);
	
	asem.callFuncWithParams(func, args, symbolsTable);
	
}

void callFuncWithParams(){
	vector<TypeInfo> args;
    args.push_back(TypeInfo(DATA_INT));
	args.push_back(TypeInfo(DATA_INT,3));
    string funcName = string("test");
    Func func(funcName, args, TypeInfo(DATA_VOID));
	symbolsTable.addFuncSymbol(func);
	
	//asem.callFunc(func);
	
}


int main(){
	symbolsTable.addScope();
	
	callFunc();
	//functionArgs();
	//updateArr();
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

