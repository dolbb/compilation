#include "symbol_tabel.hpp"	

#define CODE (CodeBuffer::instance())

vector<unsigned int> _ArgumentsOffsetsStack;
FunctionTable _FunctionsStack;
vector<VariableTable> _TablesStack;
vector<unsigned int> _OffsetsStack;
vector<bool> _DefaultsStack;

VariableType getReturnType(){
	return _FunctionsStack.back().returnType;
}

bool isVarExists(const string& name) {
	for (int i = _TablesStack.size() - 1; i >= 0; i--) {
		for (vector<VariableEntry>::iterator it = _TablesStack[i].begin();
			it != _TablesStack[i].end(); ++it) {
			if (name == it->name) return true;
		}
	}
	return false;
}

bool isFunExists(const string& name) {
	for (FunctionTable::iterator it = _FunctionsStack.begin(); it != _FunctionsStack.end(); ++it) {
		if (name == it->name) return true;
	}
	return false;
}

//VariableEntry& getVariable(string name) { 
VariableEntry getVariable(string name) { // $$$$$$$$$$$$$$
	for (int i = _TablesStack.size() - 1; i >= 0; i--) {
		for (vector<VariableEntry>::iterator it = _TablesStack[i].begin();
			it != _TablesStack[i].end(); ++it) {
			if (name == it->name) return *it;
		}
	}
	VariableEntry undef_output;
	undef_output.type = VAR_TYPE_UNDEFINED;
	return undef_output; 
}

VariableType getVariableType(string name) {	// $$$$$$$$$$$$$$
	return getVariable(name).type;
}

VariableType getFunctionReturnType(string name) { //@@@@@@@@@@@@@@@@@@
	for (FunctionTable::iterator it = _FunctionsStack.begin(); it != _FunctionsStack.end(); ++it) {
		if (name == it->name) return it->returnType;
	}
	return VAR_TYPE_UNDEFINED;
}

vector<VariableType>& getFunctionArgsTypes(string name) {
	for (FunctionTable::iterator it = _FunctionsStack.begin(); it != _FunctionsStack.end(); ++it) {
		if (name == it->name) return it->argTypes;
	}
}

void declareVariable(VariableType type, string name) {
	VariableEntry varEntry;
	varEntry.name = name;
	varEntry.type = type;
	varEntry.offset = _OffsetsStack.back();
	_TablesStack.back().push_back(varEntry);
	_OffsetsStack.back()++;
}

void declareArgument(VariableType type, string name) {
	VariableEntry varEntry;
	varEntry.name = name;
	varEntry.type = type;
	varEntry.offset = _ArgumentsOffsetsStack.back();
	_TablesStack.back().push_back(varEntry);
	_FunctionsStack.back().argTypes.push_back(type);
	switch (type) {
	case VAR_TYPE_INT:
		_FunctionsStack.back().argTypesNames.push_back("INT");
		break;
	case VAR_TYPE_BYTE:
		_FunctionsStack.back().argTypesNames.push_back("BYTE");
		break;
	case VAR_TYPE_STRING:
		_FunctionsStack.back().argTypesNames.push_back("STRING");
		break;
	case VAR_TYPE_BOOL:
		_FunctionsStack.back().argTypesNames.push_back("BOOL");
		break;
	}
	_ArgumentsOffsetsStack.back()--;
}

void declareFunction(VariableType type, string name) {
	FunctionEntry funEntry;
	funEntry.name = name;
	funEntry.returnType = type;
	funEntry.implementation = CODE.next();
	_FunctionsStack.push_back(funEntry);
	unsigned int currentOffset = -1;
	_ArgumentsOffsetsStack.push_back(currentOffset);
}


void declarePrint() {
	FunctionEntry funEntry;
	funEntry.name = "print";
	funEntry.returnType = VAR_TYPE_VOID;
	funEntry.argTypesNames.push_back("STRING");
	funEntry.argTypes.push_back(VAR_TYPE_STRING);
	funEntry.implementation = CODE.next();
	_FunctionsStack.push_back(funEntry);
}

void declarePrinti() {
	FunctionEntry funEntry;
	funEntry.name = "printi";
	funEntry.returnType = VAR_TYPE_VOID;
	funEntry.argTypesNames.push_back("INT");
	funEntry.argTypes.push_back(VAR_TYPE_INT);
	funEntry.implementation = CODE.next();
	_FunctionsStack.push_back(funEntry);
}

void openScope() {

	_TablesStack.push_back(VariableTable());

	unsigned int currentOffset;
	if (_OffsetsStack.empty()) {
		currentOffset = 0;
	}
	else {
		currentOffset = _OffsetsStack.back();
	}
	_OffsetsStack.push_back(currentOffset);
	_DefaultsStack.push_back(false);
}

void closeScope() {
	// endScope();
	/* 		
	VariableTable& vars = _TablesStack.back();
	for (vector<VariableEntry>::iterator it = vars.begin(); it != vars.end(); ++it) {
		string id = it->name;
		int offset = it->offset;

		switch (it->type) {
		case VAR_TYPE_INT:
			printID(id, offset, "INT");
			break;
		case VAR_TYPE_BYTE:
			printID(id, offset, "BYTE");
			break;
		case VAR_TYPE_STRING:
			printID(id, offset, "STRING");
			break;
		case VAR_TYPE_BOOL:
			printID(id, offset, "BOOL");
			break;
		}
	}
	*/
	
	//TODO - ADD: emit_stack_remove("all the " + to_string(vars.size) + "variables declared in the ending scope", vars.size); 
	// TODO: עדיף שזה ייקרה כאן או בחוץ? 		$$$$$$$$$$$$$
	
	_TablesStack.pop_back();
	_OffsetsStack.pop_back();
	_DefaultsStack.pop_back();
}

void closeGlobalScope() {
	// endScope();
	/*		$$$$$$$$$$$$$$
	for (FunctionTable::iterator it = _FunctionsStack.begin(); it != _FunctionsStack.end(); ++it) {
		//while (!_FunctionsStack.empty()) {
		//FunctionEntry& func = _FunctionsStack.back();
		string functionType;
		switch (it->returnType) {
		case VAR_TYPE_INT:
			functionType = makeFunctionType("INT", it->argTypesNames);
			break;
		case VAR_TYPE_BYTE:
			functionType = makeFunctionType("BYTE", it->argTypesNames);
			break;
		case VAR_TYPE_STRING:
			functionType = makeFunctionType("STRING", it->argTypesNames);
			break;
		case VAR_TYPE_BOOL:
			functionType = makeFunctionType("BOOL", it->argTypesNames);
			break;
		default:
			functionType = makeFunctionType("VOID", it->argTypesNames);
			break;
		}
		printID(it->name, 0, functionType);
		//_FunctionsStack.pop_back();
	}
	*/
}

FunctionEntry& getFunction(string name) {
	for (FunctionTable::iterator it = _FunctionsStack.begin(); it != _FunctionsStack.end(); ++it) {
		if (name == it->name) return *it;
	}
}

bool isDefault(){
	return (_DefaultsStack.back());
}

void setIsDefault(){
	_DefaultsStack.back() = true;
}

int scope_size(){
	return _TablesStack.back().size();
}

