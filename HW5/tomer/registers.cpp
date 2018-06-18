#include "registers.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

Registers::Registers() : temp_regs(), saved_regs() {
	stringstream sm;
	for (int i=0; i<10; i++) {
		sm.str("");
		sm << "$t" << i;
		temp_regs[sm.str()] = false;
	}
	for (int i=0; i<8; i++) {
		sm.str("");
		sm << "$s" << i;
		saved_regs[sm.str()] = false;
	}
}

Registers &Registers::instance() {
	static Registers inst;//only instance
	return inst;
}

string Registers::getTempReg() {
    for (std::map<string,bool>::iterator it=temp_regs.begin(); it!=temp_regs.end(); ++it) {
    	if (it->second == false) {
    		temp_regs[it->first] = true;
    		return it->first;
    	}
    }
    return "";
}

string Registers::getSavedReg() {
    for (std::map<string,bool>::iterator it=saved_regs.begin(); it!=saved_regs.end(); ++it) {
    	if (it->second == false) {
    		saved_regs[it->first] = true;
    		return it->first;
    	}
    }
    return "";
}

// void Registers::releaseTempReg(string reg) {
// 	if (temp_regs.count(reg) != 1) {
// 		throw runtime_error(string("releaseTempReg: no such register! --> ") + reg);
// 	}
// 	temp_regs[reg] = false;
// }

// void Registers::releaseSavedReg(string reg) {
// 	if (saved_regs.count(reg) != 1) {
// 		throw runtime_error(string("releaseSavedReg: no such register! --> ") + reg);
// 	}
// 	saved_regs[reg] = false;
// }

string Registers::getReg() {
	string myreg = getTempReg();
	if (myreg == "") {
		myreg = getSavedReg();
	}
	if (myreg == "") {
		throw runtime_error("no registers left!");
	}
	return myreg;
}

void Registers::releaseReg(string reg) {
	if (reg == "$v0"){
		return;
	}
	if (temp_regs.count(reg) == 1) {
		temp_regs[reg] = false;
	} else if (saved_regs.count(reg) != 1) {
		throw runtime_error(string("no such register! --> ") + reg);
	} else {
		saved_regs[reg] = false;
	}
}

void Registers::storeRegistersOnStack(){
	for (std::map<string,bool>::iterator it=temp_regs.begin(); it!=temp_regs.end(); ++it) {
		if (it-> second == true){
    		Stack::storeRegister(it->first);
    	}
    }
	for (std::map<string,bool>::iterator it=saved_regs.begin(); it!=saved_regs.end(); ++it) {
		if (it-> second == true){
    		Stack::storeRegister(it->first);
    	}
    }
}

void Registers::restoreRegistersOnStack(){
	for (std::map<string,bool>::reverse_iterator rit=saved_regs.rbegin(); rit!=saved_regs.rend(); ++rit) {
		if (rit-> second == true){
    		Stack::restoreRegister(rit->first);
		}
    }
	for (std::map<string,bool>::reverse_iterator rit=temp_regs.rbegin(); rit!=temp_regs.rend(); ++rit) {
    	if (rit-> second == true){
    		Stack::restoreRegister(rit->first);
    	}
    }
}






