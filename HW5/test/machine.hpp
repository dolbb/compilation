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
int dataLabelIndex = 1;
string divErrorMessage = "Error division by zero\\n";
string indexErrorMessage = "Error index out of bounds\\n";
string divErrorHanlingLabel = "divErrorFunc";
string indexErrorHanlingLabel = "arrErrorFunc";

string toString(int num)
{
    ostringstream os;
	os << num;
    return os.str();
}

int toInt(char const *s)
{
     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) {
        ++s;
     }
     int result = 0;
     while(*s)
     {
          if ( *s >= '0' && *s <= '9' ){
            result = result * 10  - (*s - '0');  //assume negative number
          }
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
		if (reg == "") return;
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
	void loadAddressToReg(string reg, string label){
		doRegOp("la", reg, label);	
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
		BP.printDataBuffer();
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
		
		//division by zero
		vector<int> trueList = BP.makelist(BP.emit("bnez " + regRight + ", "));
		string reg = mgr.getReg();
		mgr.loadAddressToReg(reg,"divErrorMessage"); 
		mgr.storeFromReg(reg, "($sp)");
		BP.emit("j " + divErrorHanlingLabel);
		string nextLabel = BP.genLabel();
		BP.bpatch(trueList, nextLabel);
		mgr.freeReg(reg);
		
		
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
		
		string errReg = mgr.getReg();
		mgr.loadAddressToReg(errReg,"indexErrorMessage"); 
		push();
		mgr.storeFromReg(errReg, "($sp)");
		
		BP.emit("bgt " + regArrIndex +"," + tmpReg+","+indexErrorHanlingLabel); //TODO - add this label
		mgr.storeToRegImm(tmpReg, 0);
		BP.emit("blt " + regArrIndex +"," + tmpReg+","+indexErrorHanlingLabel);
		
		pop(1);
		mgr.freeReg(tmpReg);
		mgr.freeReg(errReg);
	}
public:
	void push(){
		BP.emit("subu $sp, $sp, 4 #push stack");
	}
	void pop(int size) {
		if (size == 0) return;
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
	void storeArg(string reg){
		push();
		mgr.storeFromReg(reg,"($sp)");
	}
	void storeArgArray(string id, SymbolsTable symTable){
		
	}
	void saveFP(){
		BP.emit("#--- store fp on stack ---");
		push();
		mgr.storeFromReg("$fp", "($sp)");
		BP.emit("#--- finished storing fp on stack ---");
	}
	
	void popScopeVars(SymbolsTable symTable){
		int offset = symTable.getCurrentScopeSize();
		pop(offset);
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
		return (4) * totalArgsOffset;
	}
public:	
	void callFunc(Func func) {
		
		BP.emit("#----- jumping to function" + func.id );
		//mgr.storeRegsToStack();
		asmStack.saveFP();
		asmStack.push(); //for $ra

		BP.emit("jal " + func.label);
		BP.emit("#----- finished jumping to function -----");
		//mgr.loadRegsFromStack();
	}
	
	//Call : ID LPAREN ExpList.argList RPAREN
	void callFuncWithParams(Func func, vector<TokenClass*> &argList, SymbolsTable &symTable) {
		BP.emit("#----- jumping to function" + func.id );
		
		//mgr.storeRegsToStack();
		asmStack.saveFP();
		asmStack.push(); //for $ra
	
		//update stack with arg's values		
		BP.emit("#----- passing arguments to function -----");
		std::vector<TokenClass*>::reverse_iterator rit = argList.rbegin();
		for (; rit!= argList.rend(); ++rit) {
			//add array arg
			if( (*rit)->typeInfo.id != "") {
				string tmpReg = mgr.getReg(); 
				string tmpReg2 = mgr.getReg(); //for index a[index]
				int size = symTable.getIdTypeInfo((*rit)->typeInfo.id).size;
				for (int i=0; i<size; i++) {
					mgr.storeToRegImm(tmpReg2,i);
					asmStack.getArrEntry((*rit)->typeInfo.id, symTable, tmpReg2, tmpReg);
					asmStack.storeArg(tmpReg);
				}		
				mgr.freeReg(tmpReg);
				mgr.freeReg(tmpReg2);
			}
			//add regular var
			else if( (*rit)->typeInfo.id == ""){
				string reg = (*rit)->transAux.assignedReg;
				asmStack.storeArg(reg);
				mgr.freeReg(reg);
			}
			else{
				ASSERT(false, "something wrong with one of the arguments");
			}
		}
		BP.emit("#----- finished passing arguments to function ----");
		
		BP.emit("jal " + func.label);
		BP.emit("#----- finished jumping to function -----");
	
		//mgr.loadRegsFromStack();
	}
	
	void functionInit(Func func){
		generateLabelByName(func.label);
		BP.emit("move $fp, $sp");
		int offset = getArgsOffset(func.argsTypes);
		mgr.storeFromReg("$ra", offset + "($sp)");
	}
	
	void functionEnd(Func func, SymbolsTable &symTable){
		int offset = symTable.getCurrentScopeSize();
		asmStack.pop(offset);
		offset = getArgsOffset(func.argsTypes);
		asmStack.pop(offset);
		mgr.storeToReg("$ra", "($sp)");
		asmStack.pop(1);
		mgr.storeToReg("$fp", "($sp)");
		asmStack.pop(1);
		BP.emit("jr $ra");
		
	}
	
	string generateDataLine(string s){
		std::stringstream label;
		label << "Dlabel_" << toString(dataLabelIndex);
		string ret(label.str());
		label << ": .asciiz \"" + s + "\"";
		BP.emitData(label.str());
		dataLabelIndex++;
		return ret;	
	}
	
	//will be called from EXP -> STRING in parser
	string saveStringInDataSection(string s){
		string label = generateDataLine(s);
		string reg = mgr.getReg();
		mgr.loadAddressToReg(reg,label);
		return reg;
	}

	//will  be called in the begining of compilation
	void generateDivError(){
		BP.emitData("divErrorMessage: .asciiz \"" + divErrorMessage + "\"");
		//write "printdiverror" function:
		generateLabelByName(divErrorHanlingLabel);
		BP.emit("jal printFunc");
		BP.emit("li $v0, 10");
		BP.emit("syscall");
	}
	
	void generateIndexError(){
		BP.emitData("indexErrorMessage: .asciiz \"" + indexErrorMessage + "\"");
		//write "printindexerror" function:
		generateLabelByName(indexErrorHanlingLabel);
		BP.emit("jal printFunc");
		BP.emit("li $v0, 10");
		BP.emit("syscall");
	}

	void generateLabelByName(string name){
		std::stringstream label;
		label << name;
		label << ":";
		BP.emit(label.str());
	}

	void initializeProg(){
		
		generateDivError();
		generateIndexError();
		
		BP.emit("#Initializtion-----------------------");
		BP.emit("printFunc:");
		BP.emit("lw $a0, 0($sp)"); 
		BP.emit("li $v0, 4");
		BP.emit("syscall");
		BP.emit("jr $ra");
		
		BP.emit("printiFunc:");
		BP.emit("lw $a0, 0($sp)"); 
		BP.emit("li $v0, 1");
		BP.emit("syscall");
		BP.emit("jr $ra");
		
		asmStack.push();
		asmStack.push();
		BP.emit("main:");
		BP.emit("j main2");
		BP.emit("#Finished Initializtion--------------");
	}
};
















#endif