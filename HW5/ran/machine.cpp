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

int main(){
	
	
	string reg1 = mgr.getRegAndPromote();
	string reg2 = mgr.getRegAndPromote();
	string reg3 = mgr.getRegAndPromote();
	
	mgr.storeToRegImm(reg1, 5);
	mgr.storeToRegImm(reg2, 4);
	//mgr.storeToRegImm(reg3, 3);
	
	asem.add(reg1,reg2, true);
	//asem.divide(reg1,reg2,false);
	//asem.multiply(reg1,reg2,false);
	//asem.sub(reg1,reg2, false);
	
	mgr.freeCurrReg();
	mgr.freeCurrReg();
	
	
	
	
	mgr.print();
	//std::cout << mgr.getRegAndPromote() << std::endl;
	//std::cout << mgr.getRegAndPromote() << std::endl;
}

