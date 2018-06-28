#ifndef __COMMON_HEADER_H
#define __COMMON_HEADER_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <cstdlib>
//#include "output.hpp"

using namespace std;
//using namespace output;
using std::string;
using std::map;
using std::vector;
using std::stack;
using std::stringstream;
using std::cout;
using std::endl;

/*=======================================
        definitions:    
=======================================*/

typedef enum {
    DATA_VOID,
    DATA_BOOL,
    DATA_BYTE,
    DATA_INT,
    DATA_STRING,
    DATA_ARR_BYTE,
    DATA_ARR_INT,
    DATA_ARR_BOOL,
    DATA_INVALID
} DATA_TYPE;

struct TypeInfo {
	DATA_TYPE type;
	int size;
    string id;

    TypeInfo(){
        type = DATA_INVALID;
        size = 0;
        id = "";
    }
    TypeInfo(DATA_TYPE inType, int inSize = 1){
        type  = inType;
        size = inSize;
    }
    bool operator!=(const TypeInfo& right) const {
        bool retVal = false;
        if(type != right.type || size != right.size){
            retVal = true;
        }
        return retVal;
    }
    string getAsString(){
        switch(type){
            case DATA_VOID: 
                return "VOID";
            case DATA_BOOL:
                return "BOOL";
            case DATA_BYTE: 
                return "BYTE";
            case DATA_INT: 
                return "INT";
            case DATA_STRING: 
                return "STRING";
            case DATA_ARR_BYTE: 
                return "BYTE";
            case DATA_ARR_INT: 
                return "INT";
            case DATA_ARR_BOOL: 
                return "BOOL";
        }
        return ""; 
    }    
    string getAsStringWithArraySizes(){
        stringstream res;
        switch(type){
            case DATA_VOID: 
                res << "VOID";
                break;
            case DATA_BOOL:
                res << "BOOL";
                break;
            case DATA_BYTE: 
                res << "BYTE";
                break;
            case DATA_INT: 
                res << "INT";
                break;
            case DATA_STRING: 
                res << "STRING";
                break;
            case DATA_ARR_BYTE: 
                res << "BYTE[" << size << "]";
                break;
            case DATA_ARR_INT: 
                res << "INT[" << size << "]";
                break;
            case DATA_ARR_BOOL: 
                res << "BOOL[" << size << "]";
                break;
            default:
                res << "";
        }
        return res.str(); 
    }
};

/*=======================================
        Translation Auxiliary classes:    
=======================================*/
struct TranslationAux{
    string assignedReg;
    string quad;
    string startLabel;
    vector<int> trueList;
    vector<int> falseList;
    vector<int> nextList;
    vector<int> afterExp;
};

/*=======================================
        SYMBOL TABLE classes:    
=======================================*/
struct Func{
	string id;
	vector<TypeInfo> argsTypes;
    TypeInfo funcRetVal;
    string label;

    Func(string inId, vector<TypeInfo> inArgsVec, TypeInfo retVal){
		id = inId;
        argsTypes = inArgsVec;
        funcRetVal = retVal;
        if(id == "main"){
            label = "main2";
        }else{
            label = "_" + id + "_";
        }
    }
};

class Symbol {
public: 
    /*  data:           */
    TypeInfo typeInfo;
    string id;
    int symbolOffset;
    
    /*  functions:      */
    Symbol(){
        typeInfo = DATA_INVALID;
        symbolOffset = 0;
    }
    Symbol(TypeInfo inTypeInfo, int inSymbolOffset, string inId) {
        typeInfo = inTypeInfo;
        id = inId;
        symbolOffset = inSymbolOffset;
    }       
};

class Scope {   
public:
    /*  data:           */
    vector<Symbol> symbols;
    
    /*  functions:      */
    void addSymbolToScope(Symbol symbol){
        symbols.push_back(symbol);
    }
    int getScopeSize(){
        return symbols.size();
    }
    bool idInScope(string id){
        for (vector<Symbol>::iterator it = symbols.begin(); it != symbols.end(); ++it) {
            if (it->id == id)
            return true;
        }       
        return false;
    }
    Symbol getId(string id){
    /*  assuming id present     */
        for (vector<Symbol>::iterator it = symbols.begin(); it != symbols.end(); ++it) {
            if (it->id == id)
            return *it;
        }       
        return Symbol();
    }   
};

class SymbolsTable {
    stack<Scope> scopes;    
    stack<int> offsets;
    vector<Func> funcsVec;

public:
    SymbolsTable(){
        offsets.push(0); //maybe? this is just initialization. need to intialize scopes/offsets/funcsvec?
    }
    
    void addScope(){                
        offsets.push(offsets.top());
        scopes.push(Scope());      
    }
    
    void removeScope(){
        offsets.pop();
        scopes.pop();
    }
    
    void addSymbol(string id, TypeInfo typeInfo) {
        //assuming we already checked symbol can be added
        //get offset to insert
        int symbolOffset = offsets.top();
        offsets.pop();
        //create new symbol to add
        Symbol symbol = Symbol(typeInfo,symbolOffset,id);
        //we add the symbol to the last scope - fix my syntax!!
        scopes.top().addSymbolToScope(symbol);     
        //update scope's offset (we popped last offset)
        offsets.push(symbolOffset + typeInfo.size);     
    }
    
    void addArgSymbol(string id, TypeInfo typeInfo) {
        //I think we can assume that when args are declared then the offset is always 0 so no need to touch it
        //get current scope
        Scope scope = scopes.top();
        //if current scope is empty set offset = -size
        int symbolOffset;
        if (scope.getScopeSize() == 0){
            symbolOffset = -typeInfo.size;
        }
        //else we want the offset to be last symbol's offset - current
        else {
            symbolOffset = scope.symbols[scope.getScopeSize()-1].symbolOffset - typeInfo.size;
        }
        Symbol symbol = Symbol(typeInfo, symbolOffset, id);
        //we add the symbol to the last scope - fix my syntax!!
        scopes.top().addSymbolToScope(symbol); 
    }

    bool isIdInTable(string id){
        bool idFound = false;
        stack<Scope> tmpStack = scopes;
        while (tmpStack.size() > 0 && !idFound) {
            if (tmpStack.top().idInScope(id)){
                idFound = true;
            }
            tmpStack.pop();
        }
        if(!idFound){
            idFound = isFuncInTable(id);
        }
        return idFound;
    }
    
    TypeInfo getIdTypeInfo(string id) {
        stack<Scope> tmpStack = scopes;
        TypeInfo retTypeInfo;
        while (tmpStack.size() > 0 && retTypeInfo.type == DATA_INVALID) {
            Scope scope = tmpStack.top();
            if (scope.idInScope(id)){
                retTypeInfo = scope.getId(id).typeInfo;
            }
            tmpStack.pop();
        }
        return retTypeInfo;
    }
	
	int getSymbolOffset(string id){
		stack<Scope> tmpStack = scopes;
        TypeInfo retTypeInfo;
        while (tmpStack.size() > 0 && retTypeInfo.type == DATA_INVALID) {
            Scope scope = tmpStack.top();
            if (scope.idInScope(id)){
                return scope.getId(id).symbolOffset;
            }
            tmpStack.pop();
        }
        return -1;
	}
    
    void addFuncSymbol(Func func) {
        /*assuming func doesnt exist*/
        funcsVec.push_back(func);
    }
        
    bool isFuncInTable(string id) {
        for (vector<Func>::iterator it = funcsVec.begin(); it != funcsVec.end(); ++it) {
            if (it->id == id){
                return true;
            }
        }
        return false;
    }
    
    Func getFunc(string id) {
        //assuming func exist
        for (vector<Func>::iterator it = funcsVec.begin(); it != funcsVec.end(); ++it) {
            if (it->id == id){
                return *it;
            }
        }
        vector<TypeInfo> tmpArgsVec;
        return Func(string(""), tmpArgsVec, TypeInfo());
    }
  
    vector<Func> getFuncs(){
        return funcsVec;
    }

    void printCurrentScopeSymbols(){
        /*
        Scope scope = scopes.top();
        for (vector<Symbol>::iterator it = scope.symbols.begin(); it != scope.symbols.end(); ++it){
            DATA_TYPE type = it->typeInfo.type;
            string typeStr = it->typeInfo.getAsString();
            if( type == DATA_ARR_BYTE   || type == DATA_ARR_INT    ||
                type == DATA_ARR_BOOL ){
                int arrSize = it->typeInfo.size;
                cout << it->id << " " << makeArrayType(typeStr, arrSize) << " " << it->symbolOffset <<endl;
            }
            else{
                printID(it->id, it->symbolOffset, typeStr);
            }
        }
        */
    }
    int getCurrentScopeSize(){
        if(scopes.size() == 0){
            return 0;
        }
        Scope scope = scopes.top();
        int ret = 0;
        for (vector<Symbol>::iterator it = scope.symbols.begin(); it != scope.symbols.end(); ++it){
            if (it->symbolOffset >= 0) {
                ret += it->typeInfo.size;           
            }   
        }
        return ret;
    }
};


/*=======================================
        main token class:    
=======================================*/
class Node{
public:
    virtual ~Node(){}
};

/*=======================================
        secondary token classes:    
=======================================*/
class TokenClass : public Node{
public:
    TypeInfo typeInfo;
    vector<TypeInfo> argList;
    TranslationAux transAux;

    TokenClass(){}
    TokenClass(TypeInfo inTypeInfo){
       typeInfo = inTypeInfo; 
    }
};

class StatementClass : public Node{
public:
    string start;
    vector<int> breakList;
    vector<int> nextList;
};

class String : public Node {
    string str;
public:
    String(const char* _str){
        str = string(_str);
    }
    string getString(){
        return str;
    }
};

class Num : public Node { 
    int val;
    string str;
public:
    Num(const char* valString){
        val = atoi(valString);
        str = string(valString);
    }
    int getNum(){
        return val;
    }
    string getStr(){
        return str;
    }
};

#define YYSTYPE Node*

#endif  /*__COMMON_HEADER_H*/
