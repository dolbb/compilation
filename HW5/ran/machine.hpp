#pragma once
#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
#include <sstream>
#include "bp.hpp"
using namespace std;

#define BP (CodeBuffer::instance())
#define FIRST_REGISTER (25)
#define LAST_REGISTER (8)
#define $RA "$ra"
#define $SP "$sp"
#define $SP_ADDRSS "($sp)"
#define DEBUG

string toString(int num)
{
    ostringstream os;
	os << num;
    return os.str();
}

void ASSERT(bool condition){
	#ifdef DEBUG
	if(!condition) {
		cout << "\033[1;31m ASSERT FAILED \033[0m" << endl;
		BP.printCodeBuffer();
	}
	assert(condition);
	#endif
}

void ASSERT_REG(int reg) {
	if (reg <= FIRST_REGISTER && reg >= LAST_REGISTER) return;
	cout << "\033[1;31m failed on reg $\033[0m" << reg << endl;
	ASSERT(false);
}

class RegisterManager{
	int currentReg; 
	void doRegOp(string op, string left, string right){
		BP.emit(op + " " + left + ", " + right);
	}
public:
	RegisterManager(){
		currentReg = FIRST_REGISTER;
	}
	~RegisterManager(){
		//BP.printCodeBuffer();
	}
	string getCurrReg() {
		return "$" + toString(currentReg);
	}
	string getRegAndPromote(){
		string ret = getCurrReg();
		currentReg--;
		ASSERT_REG(currentReg);
		return ret;
	}
	void freeCurrReg(){
		currentReg++;
		ASSERT_REG(currentReg);
	}
	void storeFromReg(string reg, string dest){
		doRegOp("sw", reg, dest);		
	}
	void storeToReg(string reg, string source){
		doRegOp("lw", reg, source);		
	}
	void storeToRegImm(string reg, int value){
		doRegOp("li", reg, toString(value));		
	}
	
	
	
	void print(){
		BP.printCodeBuffer();
	}
};


class Assembly {
public:
	Assembly(){};
	void multiply(string regLeftRes, string regRight){
		BP.emit("mult " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
	}
	void divide(string regLeftRes, string regRight){
		//TODO - check for DIVIEBYZERO
		BP.emit("div " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
	}
	void sub(string regLeftRes, string regRight, bool isB){
		if (isB) {
			BP.emit("addiu " + regLeftRes + ", " + regLeftRes + ", 256");
		}
		BP.emit("subu " + regLeftRes + "," + regLeftRes + "," + regRight);
	}
	void add(string regLeftRes, string regRight){
		BP.emit("addu " + regLeftRes + ","+regLeftRes+","+regRight);
	}
	
	
	
	
};























#endif