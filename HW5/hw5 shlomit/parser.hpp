#ifndef _236360_PARSER_HPP_
#define _236360_PARSER_HPP_

#include <string>
#include <vector>




#ifndef CODE
#define CODE (CodeBuffer::instance())
#endif

using namespace std;

typedef string Label;
typedef int BufferIndex;
typedef vector<BufferIndex> BPlist;
// typedef struct {int key; Label place;} CaseRecord; $$$$$$$$$$$$ 
#define BYTES_PER_WORD (4)
#define MAX_BYTE (255)

enum RelopType { EQ, LT, LE, GT, GE, NE };

typedef enum {
	VAR_TYPE_UNDEFINED,
	VAR_TYPE_INT,
	VAR_TYPE_BYTE,
	VAR_TYPE_STRING,
	VAR_TYPE_BOOL,
	VAR_TYPE_VOID
} VariableType;


typedef struct {
	Label place;
	int caseNum;
} CaseRecord;

typedef struct {
	string 	name;
	string 	str;
	int		num;
	VariableType type;
	VariableType returnType;
	BPlist true_list;
	BPlist false_list;
	BPlist main_list;
	BPlist break_list;
	vector<CaseRecord> case_list;
	Label default_label;
	Label label;
	BufferIndex bufferIndex;
	RelopType relop;
	vector<VariableType> argTypes;
} yystype;


#define YYSTYPE yystype

#endif
