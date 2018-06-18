#ifndef __REGISTERS_H
#define __REGISTERS_H
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include "stack.hpp"

using namespace std;

class Registers {
	Registers();
	string getTempReg();
	string getSavedReg();
	// void releaseTempReg(string);
	// void releaseSavedReg(string);
public:
	map<string, bool> temp_regs;
	map<string, bool> saved_regs;
	static Registers &instance();
	string getReg();
	void releaseReg(string reg);
	void storeRegistersOnStack();
	void restoreRegistersOnStack();


};

#endif