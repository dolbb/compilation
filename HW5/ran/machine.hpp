#pragma once
#ifndef MACHINE_HPP
#define MACHINE_HPP

#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
#include <sstream>
#include "bp.hpp"
#include "commonHeader.hpp"
using namespace std;

#define BP (CodeBuffer::instance())
#define FIRST_REGISTER (25)
#define LAST_REGISTER (8)
#define RA "$ra"
#define $SP "$sp"
#define $SP_ADDRSS "($sp)"
#define $FP_ADDRSS "($fp)"
#define DEBUG

int currentReg = FIRST_REGISTER;

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
	#ifdef DEBUG
	if (reg <= FIRST_REGISTER && reg >= LAST_REGISTER) return;
	cout << "\033[1;31m failed on reg $\033[0m" << reg << endl;
	ASSERT(false);
	#endif
}

class RegisterManager{
	void doRegOp(string op, string left, string right){
		BP.emit(op + " " + left + ", " + right);
	}
public:	
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


class AssemblyCommands {
	RegisterManager mgr;
	void handleByte(string regRes, bool isB){
		if (isB){
			BP.emit("# byte mask");
			string tmpReg = mgr.getRegAndPromote();	
			mgr.storeToRegImm(tmpReg, 256);
			BP.emit("div " + regRes + "," + tmpReg);
			BP.emit("mfhi " + regRes);
			mgr.freeCurrReg();
			
		}
	}
public:	
	void multiply(string regLeftRes, string regRight, bool isB){
		BP.emit("mult " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
		handleByte(regLeftRes, isB);
	}
	void divide(string regLeftRes, string regRight, bool isB){
		//TODO - check for DIVIEBYZERO
		BP.emit("div " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
		handleByte(regLeftRes, isB);
	}
	void sub(string regLeftRes, string regRight, bool isB){
		if (isB) {
			BP.emit("addiu " + regLeftRes + ", " + regLeftRes + ", 256");
		}
		BP.emit("subu " + regLeftRes + "," + regLeftRes + "," + regRight);
		handleByte(regLeftRes, isB);
	}
	void add(string regLeftRes, string regRight, bool isB){
		BP.emit("addu " + regLeftRes + ","+regLeftRes+","+regRight);
		handleByte(regLeftRes, isB);
	}
	
	
	
	
};

class AssemblyStack {
	RegisterManager mgr;
	int getFPOffset(string symbol, SymbolsTable symTable) {
		int fpOffset = symTable.getSymbolOffset(symbol);
		return (fpOffset + 1) * (-4);
	}
	
public:
	void push(){
		BP.emit("subu $sp, $sp, 4 #push stack");
	}
	void pop(int size) {
		BP.emit("addu $sp, $sp, " + toString(4*size) + " #popping " + toString(size) +" items");
	}
	//should be used when declaring a new var
	void addNewVar(string symbol, string reg, SymbolsTable symTable){
		BP.emit("#---------saving new variable " + symbol + "------------");
		push();
		int fpOffset = getFPOffset(symbol, symTable);
		mgr.storeFromReg(reg, toString(fpOffset) + "($fp)");
		BP.emit("#---------finished saving new variable -----------");
	}
	void updateVar(string symbol, string reg, SymbolsTable symTable){
		BP.emit("#---------updating variable " + symbol + "------------");
		int fpOffset = getFPOffset(symbol, symTable);
		mgr.storeFromReg(reg, toString(fpOffset) + "($fp)");
		BP.emit("#---------finished updating variable -----------");
	}
	
	
	
};

















#endif