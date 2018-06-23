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
#define NUM_OF_REGS (18)
#define FIRST_REGISTER (25)
#define LAST_REGISTER (8)
#define RA "$ra"
#define $SP "$sp"
#define $SP_ADDRSS "($sp)"
#define $FP_ADDRSS "($fp)"
#define DEBUG

int currentReg = FIRST_REGISTER;
int regs[18] = {0};

string toString(int num)
{
    ostringstream os;
	os << num;
    return os.str();
}

int toInt(char const *s)
{
     if ( s == NULL || *s == '\0' )
        throw std::invalid_argument("null or empty string argument");

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
         ++s;

     if ( *s == '\0')
        throw std::invalid_argument("sign character only.");

     int result = 0;
     while(*s)
     {
          if ( *s >= '0' && *s <= '9' )
          {
              result = result * 10  - (*s - '0');  //assume negative number
          }
          else
              throw std::invalid_argument("invalid input string");
          ++s;
     }
     return negate ? result : -result; //-result is positive!
} 

void ASSERT(bool condition, string str = ""){
	#ifdef DEBUG
	if(!condition) {
		cout << "\033[1;31m ASSERT FAILED \033[0m" << str << endl;
		BP.printCodeBuffer();
	}
	assert(condition);
	#endif
}

void ASSERT_REG(int reg) {
	#ifdef DEBUG
	if (reg <= FIRST_REGISTER && reg >= LAST_REGISTER) return;
	cout << "\033[1;31m failed on reg $\033[0m" << reg + LAST_REGISTER << endl;
	ASSERT(false);
	#endif
}

class RegisterManager{
	int getRegInternal(){
		for(int i = NUM_OF_REGS - 1; i>=0; i--) {
			if (regs[i] == 0) {
				regs[i] = 1;
				return i + LAST_REGISTER;
			}
		}
		return -1;
	}
	int getRegFromString(string reg) {
		reg.erase(0,1); //removes $
		return toInt(reg.c_str());
	}
	string toRegString(int i){
		return "$" + toString(i);
	}
	void doRegOp(string op, string left, string right){
		BP.emit(op + " " + left + ", " + right);
	}
public:		
	string getReg(){
		int reg = getRegInternal();
		ASSERT_REG(reg);
		return toRegString(reg);
	}
	void freeReg(string reg){
		int regNum = getRegFromString(reg);	
		//cout << "\033[1;31mfreeing reg \033[0m" << regNum << endl;
		#ifdef DEBUG
		if (regs[regNum - LAST_REGISTER] == 0) {
			cout << "\033[1;31m register was already available \033[0m" << reg << endl;
			ASSERT(false);
		}
		#endif
		regs[regNum - LAST_REGISTER] = 0;
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
	//should be used when calling a function
	void storeRegsToStack(){
		BP.emit("#------ saving registers to stack ------");
		for(int i = NUM_OF_REGS - 1; i>=0; i--) {
			if (regs[i] == 1) {
				string reg = toRegString(i + LAST_REGISTER);
				//asmStack->saveReg(reg); cant have 2 classes using each other
				BP.emit("subu $sp, $sp, 4 #push stack");
				storeFromReg(reg, "($sp)");
			}
		}
		BP.emit("#------ done saving registers to stack ------");
	}
	void loadRegsFromStack(){
		BP.emit("#------ loading registers from stack ------");
		for(int i = 0; i<=NUM_OF_REGS - 1; i++) {
			if (regs[i] == 1) {
				string reg = toRegString(i + LAST_REGISTER);
				//asmStack->saveReg(reg); cant have 2 classes using each other
				storeToReg(reg, "($sp)");
				BP.emit("addu $sp, $sp, 4 #popping 1 items");
			}
		}
		BP.emit("#------ done loading registers from stack ------");
	}
	
	
	void print(){
		BP.printCodeBuffer();
	}
};

class AssemblyArithmeticCommands {
	RegisterManager mgr;
	void handleByte(string regRes, bool isB){
		if (isB){
			BP.emit("# byte mask");
			string tmpReg = mgr.getReg();	
			mgr.storeToRegImm(tmpReg, 256);
			BP.emit("div " + regRes + "," + tmpReg);
			BP.emit("mfhi " + regRes);
			mgr.freeReg(tmpReg);
			
		}
	}
public:	
	void multiply(string regLeftRes, string regRight, bool isB = 0){
		BP.emit("mult " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
		handleByte(regLeftRes, isB);
	}
	void divide(string regLeftRes, string regRight, bool isB = 0){
		//TODO - check for DIVIEBYZERO
		BP.emit("div " + regLeftRes + "," + regRight);
		BP.emit("mflo " + regLeftRes);
		handleByte(regLeftRes, isB);
	}
	void sub(string regLeftRes, string regRight, bool isB = 0){
		if (isB) {
			BP.emit("addiu " + regLeftRes + ", " + regLeftRes + ", 256");
		}
		BP.emit("subu " + regLeftRes + "," + regLeftRes + "," + regRight);
		handleByte(regLeftRes, isB);
	}
	void add(string regLeftRes, string regRight, bool isB = 0){
		BP.emit("addu " + regLeftRes + ","+regLeftRes+","+regRight);
		handleByte(regLeftRes, isB);
	}
	void multiplyImm(string reg, int num){
		string tmpReg = mgr.getReg();
		mgr.storeToRegImm(tmpReg,num);
		multiply(reg,tmpReg);
		mgr.freeReg(tmpReg);
	}
	
};



class AssemblyStack {
	RegisterManager mgr;
	AssemblyArithmeticCommands arithCommds;
	int getFPOffset(string id, SymbolsTable symTable) {
		int fpOffset = symTable.getSymbolOffset(id);
		return (fpOffset + 1) * (-4);
	}
	void validateArrLim(string id, SymbolsTable symTable, string regArrIndex){
		int size = symTable.getIdTypeInfo(id).size;
		string tmpReg = mgr.getReg();
		mgr.storeToRegImm(tmpReg, size - 1); //since index starts from 0
		
		BP.emit("bgt " + regArrIndex +"," + tmpReg+",array_out_of_bound"); //TODO - add this label
		mgr.storeToRegImm(tmpReg, 0);
		BP.emit("blt " + regArrIndex +"," + tmpReg+",array_out_of_bound");
		mgr.freeReg(tmpReg);
	}
public:
	void push(){
		BP.emit("subu $sp, $sp, 4 #push stack");
	}
	void pop(int size) {
		BP.emit("addu $sp, $sp, " + toString(4*size) + " #popping " + toString(size) +" items");
	}
	//should be used when declaring a new var 
	void addNewVar(string id, SymbolsTable symTable, string reg = ""){
		int fpOffset = getFPOffset(id, symTable);
		
		//uninitialized var
		if (reg == "") {
			BP.emit("#---------saving new uninitialzed variable " + id + "------------");
			reg = mgr.getReg();
			mgr.storeToRegImm(reg, 0);
			int size = symTable.getIdTypeInfo(id).size;
			if (size == 1) {
				
				push();
				mgr.storeFromReg(reg, toString(fpOffset) + "($fp)");
				
			}
			//array
			else if (size > 1) {
				for (int i=0; i<size; i++) {
					push();
					mgr.storeFromReg(reg, toString(fpOffset - i*4) + "($fp)");
				}				
			}
			else {
				ASSERT(false, "var size is less than 1 (WTF)");
			}
			mgr.freeReg(reg);
			BP.emit("#---------finished saving new variable -----------");
		}
		//initialzed var (not array) (Type ID ASSIGN Exp SC)
		else {
			BP.emit("#---------saving new initialzed variable " + id + "------------");
			push();
			mgr.storeFromReg(reg, toString(fpOffset) + "($fp)");
			BP.emit("#---------finished saving new variable -----------");
		}
				
	}
	//should be used when updating var (ID ASSIGN Exp SC)
	void updateVar(string id, SymbolsTable symTable, string reg, string arrID = ""){
		int size = symTable.getIdTypeInfo(id).size;
		int fpOffset = getFPOffset(id, symTable);
		//regular var
		if (size == 1 and arrID == "") {
			BP.emit("#---------updating variable " + id + "------------");			
			mgr.storeFromReg(reg, toString(fpOffset) + "($fp)");
			BP.emit("#---------finished updating variable -----------");
		}
		//array=array
		else if (size > 1 && arrID != "" ) {
			BP.emit("#---------updating array=array " + id +"="+ arrID +"------------");			
			string tmpReg = mgr.getReg();
			for (int i=0; i<size; i++) {
				int arrToCopyOffset = getFPOffset(arrID,symTable);
				mgr.storeToReg(tmpReg, toString(arrToCopyOffset - i*4) + "($fp)");
				//reg tmp = a[i]; b[i]=tmp
						
				mgr.storeFromReg(tmpReg, toString(fpOffset - i*4) + "($fp)");
			}	
			mgr.freeReg(tmpReg); 
			BP.emit("#---------finished updating array=array -----------");
		}
		else {
			ASSERT(false, "var size is less than 1 (WTF)");
		}
		
	}
	//ID LBRACK Exp.regArrIndex RBRACK ASSIGN Exp.regVal SC
	void updateArrEntry(string id, SymbolsTable symTable, string regArrIndex, string regVal){
		BP.emit("#---------updating array entry " + id + "------------");
		validateArrLim(id, symTable, regArrIndex);
		int fpOffset = getFPOffset(id, symTable); //array offset from $fp
		string tmpReg = mgr.getReg(); //tmpReg holds the final offset
		string tmpReg2 = mgr.getReg(); //tmpReg2 holds the byte offset from regArrIndex
		BP.emit("move " + tmpReg2 + "," + regArrIndex);
		mgr.storeToRegImm(tmpReg,fpOffset);
		
		arithCommds.multiplyImm(tmpReg2, -4);
		
		arithCommds.add(tmpReg, tmpReg2); //entry offset
		arithCommds.add(tmpReg, "$fp"); //entry location
		
		mgr.storeFromReg(regVal, "("+tmpReg+")");
		mgr.freeReg(tmpReg);
		mgr.freeReg(tmpReg2);
		BP.emit("#---------finished updating array entry -----------");
	}
	//Exp : ID LBRACK Exp RBRACK
	void getArrEntry(string id, SymbolsTable symTable, string regArrIndex, string regRes){
		BP.emit("#---------getting array entry " + id + "------------");
		validateArrLim(id, symTable, regArrIndex);
		int fpOffset = getFPOffset(id, symTable); //array offset from $fp
		string tmpReg = mgr.getReg(); //tmpReg holds the final offset
		string tmpReg2 = mgr.getReg(); //tmpReg2 holds the byte offset from regArrIndex
		BP.emit("move " + tmpReg2 + "," + regArrIndex);
		mgr.storeToRegImm(tmpReg,fpOffset);
		
		arithCommds.multiplyImm(tmpReg2, -4);
		
		arithCommds.add(tmpReg, tmpReg2); //entry offset
		arithCommds.add(tmpReg, "$fp"); //entry location
		
		mgr.storeToReg(regRes, "("+tmpReg+")");
		mgr.freeReg(tmpReg);
		mgr.freeReg(tmpReg2);
		BP.emit("#---------finished getting array entry -----------");
	}
	//should be used when loading var (EXP ID), returns register with loaded var
	string loadVar(string id, SymbolsTable symTable){
		string reg = mgr.getReg();	
		BP.emit("#---------loading variable " + id + " to register " + reg + " ------------");
		int fpOffset = getFPOffset(id, symTable);
		mgr.storeToReg(reg, toString(fpOffset) + "($fp)");
		BP.emit("#---------finished loading variable -----------");
		return reg;
	}
	void saveFP(){
		BP.emit("#--- store fp on stack ---");
		push();
		mgr.storeFromReg("$fp", "($sp)");
		BP.emit("#--- finished storing fp on stack ---");
	}
	
	
	
};

class AssemblyCommands {
	RegisterManager mgr;  
	AssemblyStack asmStack;
	int getArgsOffset(vector<TypeInfo> argsTypes){
		int totalArgsOffset = 0;
		for (vector<TypeInfo>::iterator it = argsTypes.begin(); it != argsTypes.end(); ++it) {
			totalArgsOffset += (*it).size;
		}
		std::cout << "size is " << totalArgsOffset << std::endl;
		return (4) * totalArgsOffset;
	}
public:	
	void callFunc() {
		int totalArgsOffset = getArgsOffset(argsTypes);
		//mgr.storeRegsToStack();
		asmStack.saveFP();
		asmStack.push(); //for $ra?
		totalArgsOffset += 8; //for saved fp + ra
		BP.emit("subu $fp, $fp, " + toString(totalArgsOffset) + "#push fp");
		
		
		
		//TODO jal to func label
		//mgr.loadRegsFromStack();
	}
	
	//Call : ID LPAREN ExpList.argList RPAREN
	void callFuncWithParams(Func func, vector<TypeInfo> argList, SymbolsTable symTable) {
		int totalArgsOffset = getArgsOffset(argList);
		//mgr.storeRegsToStack();
		asmStack.saveFP();
		asmStack.push(); //for $ra
		totalArgsOffset += 8; //for saved fp + ra
		BP.emit("subu $fp, $fp, " + toString(totalArgsOffset) + "#push fp");
		
		
		//make room in stack for arguments
		std::vector<argList>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= argList.rend(); ++rit) {
			
			
			
			
			
			
		}
		
		
		
		
		
		//update stack with arg's values
		rit = argList.rbegin();
		for (; rit!= argList.rend(); ++rit) {
			//add array arg
			if( (*it).reg == "" && (*it).id != "") {
				asmStack.addNewVar();
			}
			//add regular var
			else if( (*it).reg != "" && (*it).id == ""){
				asmStack.addNewVar();
			}
			else{
				ASSERT(false, "something wrong with one of the arguments");
			}
		}
		
		
		//TODO jal to func label
		//mgr.loadRegsFromStack();
	}
	
	
	
};
















#endif