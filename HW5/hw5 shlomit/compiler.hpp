#pragma once
#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <vector>
#include <string>
#include "parser.hpp"
#include "bp.hpp"
#include "symbol_tabel.hpp"

using namespace std;





// namespace compiler {
	void my_assert(bool assertion);
	BPlist emit_main();

	/*Part 1:
	Registers allocation and dellocation
	*/
	//reg_name
	string reg_GetName(int i);
	//reg_new_num
	//we can use operator++
	int reg_PromoteAndGetNumber();
	//reg_new_name
	string reg_PromoteAndGetName();
	//reg_pop_num
	//we can use operator--
	int reg_ReduceAndGetNumber();
	//reg_pop_name
	string reg_ReduceAndGetName();

	string reg_GetCurrentName();

	/*Part 2:
	Aritmetic Expressions
	*/
	//emit_const_num
	//Label emit_const_num();????

	//compile_constantNumber
	//Emites the number to the current register and returns the label it wrote to
	//Label compile_EmitNumber(int num);   // מצריך הוספת שדה 
										 //compile_binop
										 //why do we need the label?
	void compile_checkDivideByZero(string reg);

	void compile_binopAction(char op, string reg_out, string reg_last,bool isByte); // TODO: division by 0
																		 //compile_binop
																		 //why do we need the label?
	/*
		מאפס את הרגיסטר האחרון שבשימוש חוץ מהבית הימני.
		משתמש באופן זמני ברגיסטר חדש, ואז מוחק אותו
	*/
	void emit_byteMask();
	
	void compile_binop(char op  , bool is_byte = false );
	//compile_plus
	void compile_plus(bool is_byte = false);
	//compile_minus
	void compile_minus(bool is_byte = false);
	//compile_mul
	void compile_mul(bool is_byte = false);
	//comp div
	void compile_div(bool is_byte = false);
	
	 void compile_mod(bool is_byte); // in use for byte operations

	/*
		promote reg_current 
		and emit assembly that assign @num into the new register
	*/
	void compile_constantNumber(int num = 0);
	
	/*Part 3:
	Boolean Expressions
	*/
	//compile_jump
	/*
		promote reg_current 
		and emit assembly that assign @num into the new register
	*/
	//compile_relop
	BufferIndex compile_jump(string target = "");
	BufferIndex compile_relopAction(RelopType relop, string r1, string r2);
	//compile_relop
	YYSTYPE compile_relop(RelopType relop);
	//compile_const_bool
	//unconditional jump, if bool - can be 0 or 1
	// compile_conditionalJump;
	YYSTYPE compile_constantBoolJump(bool list);
	//compile_not
	YYSTYPE compile_not(YYSTYPE cond);
	//compile_and
	YYSTYPE compile_and(YYSTYPE cond1, YYSTYPE cond2, Label cond2label);
	//compile_or
	YYSTYPE compile_or(YYSTYPE cond1, YYSTYPE cond2, Label cond2label);
	//compile_cond
	void compile_backpatch(YYSTYPE cond, Label true_label, Label false_label);

	/*
	"the inversr operation" of emit_compute_bool.
	that is: emiting a B code section which jump is conditioned on the truth value of the current register.
	then reduce that register.

	to be called when reading a truth value of boolean variable
	*/
	YYSTYPE compile_registerBoolJump();

	/*Part 4:
	Saving of expressions to stack
	Some relevant functionalities were implemented in Symbol_tabel.
	*/
	
	/*
		change the stack pointer so that the stack would include @words_num more words, that might be used to save @name.
	*/
	void emit_stack_new(string name = "", int words_num = 1);
	/*
		change the stack pointer so that the stack would include @words_num less words,
		and by doing that - removes @name from the stack.
	*/
	void emit_stack_remove(string name = "", int words_num = 1);
	void compile_assign(int offset, string reg);
	void compile_assign(string id);
	void compile_assign(string id, YYSTYPE exp);
	// Label compile_stack_alloc(int n = 1);
	//Label compile_decl_assign(string id); // לזכור להקצות מקום ואז לקרוא להשמה רגילה
	//Label compile_decl(string id); // {compile_constantNumber(0); compile_decl_assign(id);} also for bool
	void compile_read_var(int offset, string reg);
	void compile_read_var(string id);

	/*Part 5:
			Statements Sequence
	*/

	//emit_compute_bool
	//returns -1 if tpe==bool, 1 in success
	int emit_compute_bool(YYSTYPE cond);
	//emit_halt
	
	/*
		emit a call to syscall number @num
	*/
	void emit_syscall(int num);
	
	void emit_halt(); // {emit_syscall(SYSCALL_EXIT_NUM);} 

	/*Part 6:
			Complicated structures
	*/
	YYSTYPE comp_break();
	void emit_while(Label cond_label, YYSTYPE cond_node, Label statement_label, YYSTYPE statement_node);

	void emit_compare_case(CaseRecord record);
	void emit_switch(YYSTYPE case_list_node, BufferIndex begining);

	YYSTYPE comp_case(int case_num, bool is_byte = false);

	YYSTYPE comp_default();
	

	/*Part 7:
			Output function calls
	*/
	
	/*
		מדפיס פונקציית מעטפת שקוראת לקריאת מערכת. הפרמטר לקריאה מתקבל על המחסנית.
	*/
	void emit_syscallCaller(int syscall_num);
	
	//emit_printi
	void emit_printi();
		
	/*
		מחזיר תווית שאינה בשימוש עבור אזור הדאטה
	*/
	string data_newLabel();	
		
	/*
		שומר את המחרוזת בזיכרון, ומייצר קוד ששם מצביע אליה ברגיסטר
	*/
	//compile_const_string
	void compile_constString(string str);  
	
	//initializes all the strings that will be needed 
	// void emit_stringsIntialization();

	//Label emit_print_error(string errorLabel);
	void emit_divError();

	//emit_print
	void emit_print();
	//compile_basic_funcs
	void compile_basic_funcs();
	
	
	/*Part 8:
			function calls
	*/

	/*
		push the @reg_num-th register into the stack.
	*/
	void emit_save_reg(int reg_num);
	void emit_save_reg(string reg);
	/*
		push all used registers into the stack.
	*/
	//compile_save_regs
	void compile_saveAllRegs(string func_name);	
	/*
		pop from the stack into the @reg_num-th register.
	*/
	void emit_load_reg(int reg_num);
	void emit_load_reg(string reg);
	
	/*
		pop from the stack into all used registers by oposit order.
	*/
	void compile_loadAllRegs();									// {for(int i = reg_current; i >= REG_FIRST; i--) emit_load_reg(i);}
	/*
		return the number of params of a given function
	*/
	int num_of_params(string func_name);
	/*
		like compile_loadAllRegs, but only for registers that are still in use after the function ended 
		(that is - do not load back the parameters that you have sent to the function)
	*/
	void compile_load_relevant_regs(string func_name);	
	Label emit_jumpToFunction(string func_name);
	/*
		do whatever one needs to do before jumping to a function,
		assuming that the parameters are already computed and their values are stored inside the registers.
		$ra and $fp are stored (in that order) before the registers (unlike in the assignment recomendation)
	*/
	void emit_caller_begin(string func_name);	
	/*
		do whatever one needs to do after jumping back from a function.
	*/	
	void emit_caller_end(string func_name);
	/*
		emiting all the code of a call to function @func_name, except for treating the return value
	*/	
	void emit_caller(string func_name);

	/*
		emiting assembly that save the return value of the last function to be called into a new register.
	*/
	void emit_caller_retval();								
	/*
		emiting whatever a function has to do right after it start runing.
	*/
	void emit_callee_begin();									
	/*
		emiting whatever a void function has to do before it returns the control to the caller.
	*/
	void emit_callee_retvoid();								
	/*
		emiting whatever a non-void function has to do before it returns the control to the caller (using emit_callee_retvoid).
		in main, emit a call to syscall exit().
	*/
	void emit_callee_retval();									



// }

#endif
