// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <string>
#include "compiler.hpp"
#include <assert.h>
#include <iostream>
#include <sstream>
// #include "Utils.hpp"


using namespace std;

#define REG_FIRST (8)
#define REG_LAST (25)
#define USER_REGS_NUM (REG_LAST +1 - REG_FIRST)

#ifndef CODE
#define CODE (CodeBuffer::instance())
#endif

#define DIV_ERROR_TEXT ("Error division by zero\\n")
#define SYSCALL_EXIT_NUM (10)
#define SYSCALL_PRINT_NUM (4)
#define SYSCALL_PRINTI_NUM (1)


//global variable
int reg_current = REG_FIRST - 1;
// Label printLabel;
int data_currentLabel = 0;
// string DivErrorLabelName;
string divErrorLabelName = "divByZero";

// bool compiling_main_flag;
// bool main_declared_flag;

//namespace compiler {
	
string my_to_string(int num)
{
    ostringstream os;
	os << num;
    return os.str();
}

void my_assert(bool assertion){
	#ifdef MY_DEBUG_FLAG
	if(!assertion) {
		cout << "assertion failed" << endl;
		CODE.printCodeBuffer();
	}
	assert(assertion);
	#endif
}
	
	BPlist emit_main() {
		CODE.emit("main:");
		BPlist main_list = CODE.makelist(CODE.emit("jal "));
		emit_syscall(SYSCALL_EXIT_NUM);		
		return main_list;
	}

	//Part 1
	string reg_GetName(int i)
	{
		return "$" + my_to_string(i);
	}

	int reg_PromoteAndGetNumber()
	{
		//we can assert that the register quantity is enough 
		my_assert(reg_current < REG_LAST);
		CODE.emit("# register promoting from " + my_to_string(reg_current) + " to " + my_to_string(reg_current + 1));
		reg_current++;
		my_assert(reg_current >= REG_FIRST);
		return reg_current;
	}

	string reg_PromoteAndGetName()
	{
		return reg_GetName(reg_PromoteAndGetNumber());
	}

	int reg_ReduceAndGetNumber()
	{
		//we can assert it because the compiler passed the parser checks
		my_assert(reg_current >= REG_FIRST);
		CODE.emit("# register reducing from " + my_to_string(reg_current) + " to " + my_to_string(reg_current - 1));
		return reg_current--;
	}

	string reg_ReduceAndGetName()
	{
		return reg_GetName(reg_ReduceAndGetNumber());
	}

	string reg_GetCurrentName()
	{
		my_assert(reg_current >= REG_FIRST);
		return reg_GetName(reg_current);
	}

	//Part 2

	void compile_binopAction(char op, string reg_out, string reg_last,bool isByte)
	{
		CODE.emit("# compute binop: \"" + reg_out + " = " + reg_out + op + reg_last +"\"");
		switch (op) {
		case '+':
		{
			/* label = */ CODE.emit("addu " + reg_out + ","+reg_out+","+reg_last);
			break;
		}
		case '-':
		{
			if (isByte) {
				CODE.emit("addiu " + reg_out + ", " + reg_out + ", 256");
			}
			/* label = */ CODE.emit("subu " + reg_out + "," + reg_out + "," + reg_last);
			break;
		}
		case '/':
		{
			/* label = */ compile_checkDivideByZero(reg_last);
			CODE.emit("div " + reg_out + "," + reg_last);
			//CODE.emit("mov " + reg_out + ",$Lo");
			CODE.emit("mflo " + reg_out);

			break;
		}
		case '*':
		{
			/* label = */ CODE.emit("mult " + reg_out + "," + reg_last);
			CODE.emit("mflo " + reg_out);
			break;
		}
		case '%':
		{
			// used for mod256 only in the compiler - internal usage
			/* label = */ CODE.emit("div " + reg_out + "," + reg_last);
			CODE.emit("mfhi " + reg_out);
			break;
		}
		}
	}

	void compile_checkDivideByZero(string reg) {
		//Label l = compile_constantNumber(0);
		//string regZero = reg_PromoteAndGetName();
		//Label l = CODE.emit("li " + regZero + ",0");
		//CODE.emit("bne " + reg_GetCurrentName() + "," + reg + ", continue");
		BPlist true_list = CODE.makelist(CODE.emit("bnez " + reg + ", "));
		compile_jump(divErrorLabelName);
		Label cont = CODE.next();
		CODE.bpatch(true_list, cont);
	}

	void emit_byteMask(){
		CODE.emit("# byte operation:: make sure output is byte:");
		compile_constantNumber(MAX_BYTE + 1);
		compile_mod(false);
	}
	
	void compile_binop(char op , bool is_byte)
	{
		string reg2 = reg_ReduceAndGetName();
		string reg1 = reg_GetCurrentName();
		compile_binopAction(op, reg1, reg2,is_byte);
		
		if(is_byte)   {
			emit_byteMask();
		}
	}

	void compile_plus(bool is_byte)
	{
		compile_binop('+', is_byte);
	}

	void compile_minus(bool is_byte)
	{
		compile_binop('-', is_byte);
	}

	void compile_mul(bool is_byte)
	{
		compile_binop('*', is_byte);
	}

	void compile_div(bool is_byte) 
	{
		compile_binop('/', is_byte);
	}
	
	void compile_mod(bool is_byte) // @is_byte has no influance in the case of mod. It's here only for the sake of uniformity.
	{
		compile_binop('%', is_byte);
	}
	
	void compile_constantNumber(int num) {
		string reg = reg_PromoteAndGetName();
		CODE.emit("li "+ reg +", "+my_to_string(num)
		+ "\t# initialize " + reg + " with value " + my_to_string(num)
		);
	}

	//Part 3
	
	BufferIndex compile_jump(string target)
	{
		return CODE.emit("j "+target);
	}

	BufferIndex compile_relopAction(RelopType relop, string r1, string r2)
	{
		string command;
		string parameters = r1 + "," + r2 + ",";
		switch (relop) {
		case EQ:
		{
			command = "beq";
			break;
		}
		case LT:
		{
			command = "blt";
			break;
		}
		case LE:
		{
			command = "ble";
			break;
		}
		case GT:
		{
			command = "bgt";
			break;
		}
		case GE:
		{
			command = "bge";
			break;
		}
		case NE:
		{
			command = "bne";
			break;
		}
		}
		return CODE.emit(command + " " + parameters);
	}

	YYSTYPE compile_relop(RelopType relop)
	{
		yystype stype; // = yystype();
		//stype.label = CODE.next();
		string reg2 = reg_ReduceAndGetName();
		string reg1 = reg_ReduceAndGetName();
		int trueLabel = compile_relopAction(relop, reg1, reg2);
		int falseLabel = compile_jump();
		stype.true_list = CODE.makelist(trueLabel);
		stype.false_list = CODE.makelist(falseLabel);
		stype.type = VAR_TYPE_BOOL;
		return stype;
	}

	YYSTYPE compile_constantBoolJump(bool list)
	{
		YYSTYPE stype;
		if (list) {
			stype.true_list = CODE.makelist(compile_jump());
		}
		else {
			stype.false_list = CODE.makelist(compile_jump());
		}
		stype.type = VAR_TYPE_BOOL;
		return stype;
	}

	YYSTYPE compile_not(YYSTYPE cond)
	{
		assert(	cond.type == VAR_TYPE_BOOL);
		YYSTYPE stype;// = cond;
		stype.true_list = cond.false_list;
		stype.false_list = cond.true_list;
		stype.type = VAR_TYPE_BOOL;
		return stype;
	}

	YYSTYPE compile_and(YYSTYPE cond1, YYSTYPE cond2, Label cond2label)
	{
		my_assert(	cond1.type == VAR_TYPE_BOOL);
		my_assert(	cond2.type == VAR_TYPE_BOOL);
		YYSTYPE stype;
		stype.true_list = cond2.true_list;
		stype.false_list = CODE.merge(cond1.false_list, cond2.false_list);
		//append cond2.false to stype.false_list
		//stype.false_list.insert(stype.false_list.end(), cond2.false_list.begin(), cond2.false_list.end());
		CODE.bpatch(cond1.true_list, cond2label);
		stype.type = VAR_TYPE_BOOL;
		return stype;
	}

	YYSTYPE compile_or(YYSTYPE cond1, YYSTYPE cond2, Label cond2label)
	{
		return compile_not(compile_and(compile_not(cond1), compile_not(cond2), cond2label));
	}

	void compile_backpatch(YYSTYPE cond, Label true_label, Label false_label)
	{
		CODE.bpatch(cond.true_list, true_label);
		CODE.bpatch(cond.false_list, false_label);
	}

	YYSTYPE compile_registerBoolJump() {
		YYSTYPE stype;
		// stype.label = CODE.next();
		stype.true_list.push_back(CODE.emit("bnez " + reg_ReduceAndGetName() + ", "));
		stype.false_list.push_back(compile_jump());
		stype.type = VAR_TYPE_BOOL; 
		return stype;
	}

	//Part 4
	
	void emit_stack_new(string name, int words_num) {
		CODE.emit("addiu $sp, $sp, "
			+ my_to_string((-1)*words_num * BYTES_PER_WORD)
			+ "# new space on stack for " + name
			+ "(" + my_to_string((-1)*words_num) + " words)"
		);
	}

	void emit_stack_remove(string name, int words_num) {
		CODE.emit("addiu $sp, $sp, "
			+ my_to_string(words_num * BYTES_PER_WORD)
			+ "   # remove " + name + " from stack "
			+ "(" + my_to_string(words_num) + " words)"
		);
	}
	
	void compile_assign(int offset, string reg)
	{
		CODE.emit("sw " + reg + "," + my_to_string(-offset*BYTES_PER_WORD) + "($fp)");
	}

	void compile_assign(string id)
	{
		string reg = reg_ReduceAndGetName();
		CODE.emit("#saving " + reg + " into " + id + ":");
		compile_assign(getVariable(id).offset, reg);
	}
	
	void compile_assign(string id, YYSTYPE exp){
		emit_compute_bool(exp);
		compile_assign(id);
	}

	void compile_read_var(int offset, string reg)
	{
		CODE.emit("lw " + reg + "," + my_to_string(-offset*BYTES_PER_WORD) + "($fp)");
	}

	void compile_read_var(string id)
	{
		string reg = reg_PromoteAndGetName();
		CODE.emit("#saving to " + reg + " from " + id);
		compile_read_var(getVariable(id).offset, reg);
	}


	//Part 5
	int emit_compute_bool(YYSTYPE cond)
	{
		if (cond.type != VAR_TYPE_BOOL) {
			return -1;
		}
		Label true_label = CODE.next();
		compile_constantNumber(true);//writes to register and 
		BPlist jump_to_end = CODE.makelist(compile_jump());
		reg_ReduceAndGetName();
		Label false_label = CODE.next();
		compile_constantNumber(false);
		compile_backpatch(cond, true_label, false_label);
		Label End = CODE.next();
		CODE.bpatch(jump_to_end, End);
		return 1;
	}
	
	void emit_syscall(int num){
		CODE.emit("li $v0, "+ my_to_string(num));
		CODE.emit("syscall");
	}


	void emit_halt()
	{
		emit_syscall(SYSCALL_EXIT_NUM);
	}

	//Part 6

	YYSTYPE comp_break() {
		YYSTYPE out;
		out.break_list.push_back(compile_jump());
		return out;
	}

	void emit_while(Label cond_label, YYSTYPE cond_node, Label statement_label, YYSTYPE statement_node)
	{
		compile_jump(cond_label);
		CODE.bpatch(cond_node.true_list, statement_label); // if condition satisfied, do the statement.
		BPlist end_list = CODE.merge(statement_node.break_list, cond_node.false_list);
		// otherwize, go to the end of the while. also from break.
		CODE.emit("# end of while #");
		CODE.bpatch(end_list, CODE.next());
	}


	void emit_compare_case(CaseRecord record)
	{
		string keyReg = reg_GetCurrentName();
		compile_constantNumber(record.caseNum);
		string expReg = reg_ReduceAndGetName();
		CODE.emit("beq "
			+ expReg + ", "
			+ keyReg + ", "
			+ record.place
			+ "\t# If case is (" + my_to_string(record.caseNum) + "), go to the relevant code."
		);
	}

	void emit_switch(YYSTYPE case_list_node, BufferIndex begining) {		
		case_list_node.break_list.push_back(compile_jump()); // Last case must break
		CODE.emit("# Switch :: Coparing expression to " 
			+ my_to_string(case_list_node.case_list.size()) 
			+ " cases:");
		CODE.bpatch(CODE.makelist(begining), CODE.next());
		reg_PromoteAndGetNumber(); // we jump here while Exp is alive.
		
		for (std::vector<CaseRecord>::const_iterator it = case_list_node.case_list.begin(); it != case_list_node.case_list.end(); ++it) {
			emit_compare_case(*it);
		}
		reg_ReduceAndGetNumber(); // delete Exp
		
		if (case_list_node.default_label != "") {
			compile_jump(case_list_node.default_label);
		}
		CODE.emit("# end of switch #");
		CODE.bpatch(case_list_node.break_list, CODE.next());

	}

	void emit_complete_vars(){
		int vars_num = scope_size();
		/*
		emit_stack_new("vars defined in switch scope, before case " + my_to_string(case_num),
			vars_num);
		*/
		CODE.emit("# Case :: initialize all vars defined in switch scope untill now:");
		compile_constantNumber(); // 0 to be saved 
		for(int i=0; i < vars_num; i++){
			emit_save_reg(reg_GetCurrentName());
		}
		reg_ReduceAndGetNumber();
		//puts the register value of last line into the variable in memory
	}
	
	YYSTYPE comp_case(int case_num, bool is_byte) {
		YYSTYPE out;
		CaseRecord this_case;
		this_case.caseNum = case_num;
		CODE.emit("# Case :: continue to next case with all your vars:");
		BufferIndex jump_from_last = compile_jump();
		CODE.emit("# Case :: case " + my_to_string(this_case.caseNum) + (is_byte?" B":"") + ":");
		this_case.place = CODE.next();
		emit_complete_vars();
		CODE.emit("# Case :: Statments:");
		CODE.bpatch(CODE.makelist(jump_from_last), CODE.next());
		out.case_list.push_back(this_case);
		out.default_label = "";
		return out;
	}

	YYSTYPE comp_default() {
		YYSTYPE out;
		CODE.emit("# default:");
		out.default_label = CODE.next();
		return out;
	}


	//Part 7
	
	void emit_syscallCaller(int syscall_num){
		CODE.emit("lw $a0, 0($sp)"); 
		emit_syscall(syscall_num);
		CODE.emit("jr $ra");
	}
	
	void emit_printi() {
		CODE.emit("\n###### \t printi \t ######");
		emit_syscallCaller(SYSCALL_PRINTI_NUM);
	}

	string data_newLabel(){
		return "data_Label_" + my_to_string(data_currentLabel++);
	}

	//push string to data buffer (inteds to save strings like 'errordividebyzero' or any string we send to print function
	void compile_constString(string str /* ,string LabelName */)
	{
		string LabelName = data_newLabel();
		CODE.emitData(LabelName + ": .asciiz \"" + str +"\"");
		string reg = reg_PromoteAndGetName();
		CODE.emit("la " + reg + ", " + LabelName);
	}

	//will be called in the begining of main
	void emit_divError() {
		CODE.emit(divErrorLabelName +":");
		compile_constString(DIV_ERROR_TEXT);
		emit_caller("print");
		emit_halt();
	}
	
	void emit_print() {
		CODE.emit("\n###### \t print \t ######");
		emit_syscallCaller(SYSCALL_PRINT_NUM);
	}

	void compile_basic_funcs()
	{
		emit_printi();
		// printLabel = emit_print();
		emit_print();
	}



	//Part 8



	void emit_save_reg(int reg_num){
		return emit_save_reg(reg_GetName(reg_num));
	}
	
	void emit_save_reg(string reg) {
		// string reg = reg_GetName(reg_num);
		emit_stack_new(reg);
		CODE.emit("sw "
			+ reg + ", ($sp)"
			+ "#save register " + reg + " on top of the stack."
		);
	}

	void compile_saveAllRegs(string func_name) {
		CODE.emit("##### \t save all registers: \t #####");
		int params_num = num_of_params(func_name);
		CODE.emit("# num of params = " + my_to_string(params_num));
		my_assert(params_num >= 0);
		
		int last_normal_reg = reg_current - params_num;
		CODE.emit("### \t save non-parameter registers: \t ###");
		for (int i = REG_FIRST; i <= last_normal_reg /*reg_current*/; i++) {
			emit_save_reg(i);
		}
		CODE.emit("### \t save " + my_to_string(params_num) + " parameter registers: \t ###");
		for (int i = reg_current; i > last_normal_reg /*reg_current*/; i--) {
			emit_save_reg(i);
		}
	}
	
	void emit_load_reg(int reg_num) {
		emit_load_reg(reg_GetName(reg_num));
	}
	void emit_load_reg(string reg) {
		// string reg = reg_GetName(reg_num);
		//shlomit - changed from lw to move
		CODE.emit("lw "
			+ reg + ", ($sp)"
			+ "# load register " + reg
		);
		emit_stack_remove(reg);
	}

	void compile_loadAllRegs() {
		CODE.emit("# Call :: load all registers:");
		for (int i = reg_current; i >= REG_FIRST; i--) {
			emit_load_reg(i);
		}
	}

	int num_of_params(string func_name) {
		return getFunction(func_name).argTypes.size();
	}

	void compile_load_relevant_regs(string func_name) {
		int params_num = num_of_params(func_name);
		CODE.emit("# num of params = " + my_to_string(params_num));
		my_assert(params_num >= 0);
		CODE.emit("# currReg reduced from " + my_to_string(reg_current) + " to " + my_to_string(reg_current - params_num));
		reg_current -= params_num;
		CODE.emit("# register number = "+my_to_string(reg_current));
		my_assert(reg_current >= REG_FIRST - 1);
		emit_stack_remove("all params of function " + func_name, params_num);
		compile_loadAllRegs();
	}

	void emit_caller_begin(string func_name){
		emit_save_reg("$ra");
		emit_save_reg("$fp");
		compile_saveAllRegs(func_name);
	}
	
	Label emit_jumpToFunction(string func_name){
		CODE.emit("# jump to function " + func_name + " and save return adress at $ra");
		Label functionLabel = getFunction(func_name).implementation;
		CODE.emit("jal " + functionLabel);
		return functionLabel;
	}
	
	void emit_caller_end(string func_name){
		compile_load_relevant_regs(func_name);
		emit_load_reg("$fp");
		emit_load_reg("$ra");
	}
	void emit_caller(string func_name) {
		CODE.emit("#### \t Call Function " + func_name + ": \t ####");
		emit_caller_begin(func_name);
		emit_jumpToFunction(func_name);
		emit_caller_end(func_name);
	}

	void emit_caller_retval() {
		string reg = reg_PromoteAndGetName();
		CODE.emit("move " + reg + ", $v0"
		+"\t# load return value to register " + reg);
	}
	// use in exp->call, not in call->_____; for uniformity and to prevent loading of void

	void emit_callee_begin(){
		CODE.emit("addiu $fp, $sp, -4 \t# initialize the new function frame");

		// TODO: anything else?
	}
	void emit_callee_retvoid(){
		CODE.emit("# remove all local variables:");
		//CODE.emit("move $sp, $fp");   
		CODE.emit("addiu $sp, $fp, 4");
		/*if(compiling_main_flag){ 
			emit_halt();
		}*/
		/* else  */
		CODE.emit("jr $ra \t# jump back to the line after the calling line"); 
		//}
		// my_assert(reg_current < REG_FIRST); // all registers must be used and "deleted" inside the function.
	}
	
	void emit_callee_retval(){
		CODE.emit("move $v0, " + reg_ReduceAndGetName() 
				+ " \t# save the above-computed value in the return-value-register");
		emit_callee_retvoid ();
	}
// }

/*
int main()
{
	// using namespace compiler;
	declarePrint();
	emit_print();
	declarePrinti();
	emit_printi();
	
	emit_divError();

	//binop / action
	CODE.emit("main:");
	compile_constantNumber(5);
	compile_constantNumber(0);
	compile_binop('/');
	emit_halt();
	

	CODE.printDataBuffer();
	CODE.printCodeBuffer();
	

	//test 1
	



	string str;
	getline(std::cin, str);

	return 0;
}
*/
