/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "parser.ypp" /* yacc.c:339  */

	#include <iostream>
	#include "output.hpp"
	#include "commonHeader.hpp"
	#include "machine.hpp"

	using namespace std;
	using namespace output;

	/*	external data:					*/
	extern int yylex();
	extern int yylineno;
	void yyerror(const char*);
	
	/*	global data:					*/
	SymbolsTable symbolsTable; 	/* symbols data is stored here 	*/
	int numOfWhileContaining = 0;	/* field for when a break occures	*/
	bool isMainExist = false;
	TypeInfo funcReturnDataType; //this holds the current expected return type of a function
	string currentFuncId;
	AssemblyArithmeticCommands arithMgr;
	AssemblyStack asmStack;
	AssemblyCommands asmCmd; 
	stack<StatementClass*> statementStack;

	/*	translation addition: 			*/
	CodeBuffer& codeBuff = CodeBuffer::instance();
	RegisterManager mgr;
	vector<TokenClass*> expListVec;

	/*	local functions:				*/
	void saveInputNumIntoToken(TokenClass* token, int num);
	TokenClass* basicBoolPrint(bool isTrue);
	void checkBoolAndGenPrint(TokenClass* token, string reg);
	void relOpPrint(string op, TokenClass* resTok, TokenClass* leftExp, TokenClass* rightExp);
	TokenClass* logicalOpAction(TokenClass* exp1, TokenClass* exp2, string op, string quad);
	TokenClass* relOpAction(TokenClass* exp1, TokenClass* exp2, string op);
	TokenClass* binOpAction(TokenClass* exp1, TokenClass* exp2, string op);
	void verifyNumber(TokenClass* e);
	void verifyNumber(TokenClass* e1, TokenClass* e2);
	void verifyBool(TokenClass* e);
	void verifyBool(TokenClass* e1, TokenClass* e2);
	void verifyIdNotInSymbols(string id);
	void verifyIdInSymbols(string id);
	void verifyIdIsntFunction(string id);
	void verifyFunctionPresent(string id);
	Func getFuncFromTable(string id);
	void convertTypeInfoVecToStringVec(vector<TypeInfo>& typeVec, vector<string>& outputVec);
	void printFunctions();
	void printScopeSymbols();
	DATA_TYPE getTypeAsArrType(DATA_TYPE type);

#line 119 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    BYTE = 260,
    B = 261,
    BOOL = 262,
    AND = 263,
    OR = 264,
    NOT = 265,
    TRUE = 266,
    FALSE = 267,
    RETURN = 268,
    IF = 269,
    ELSE = 270,
    BREAK = 271,
    WHILE = 272,
    SC = 273,
    COMMA = 274,
    ASSIGN = 275,
    ID = 276,
    NUM = 277,
    STRING = 278,
    EQUAL = 279,
    NOT_EQUAL = 280,
    SMALLER_THAN = 281,
    GREATER_THAN = 282,
    SMALLER_EQ_THAN = 283,
    GREATER_EQ_THAN = 284,
    PLUS = 285,
    MINUS = 286,
    MULT = 287,
    DIV = 288,
    LPAREN = 289,
    RPAREN = 290,
    LBRACK = 291,
    RBRACK = 292,
    LBRACE = 293,
    RBRACE = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 210 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,    98,   101,   102,   105,   108,   112,   105,
     144,   148,   153,   157,   162,   169,   184,   201,   232,   272,
     276,   289,   293,   309,   349,   379,   417,   469,   513,   522,
     537,   604,   629,   629,   663,   682,   689,   695,   699,   703,
     707,   716,   789,   807,   815,   815,   830,   834,   838,   844,
     848,   887,   893,   899,   905,   911,   931,   942,   951,   965,
     977,   981,   985,   991,   999,  1007,  1014,  1021,  1028,  1035,
    1042,  1049,  1055
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "BYTE", "B", "BOOL",
  "AND", "OR", "NOT", "TRUE", "FALSE", "RETURN", "IF", "ELSE", "BREAK",
  "WHILE", "SC", "COMMA", "ASSIGN", "ID", "NUM", "STRING", "EQUAL",
  "NOT_EQUAL", "SMALLER_THAN", "GREATER_THAN", "SMALLER_EQ_THAN",
  "GREATER_EQ_THAN", "PLUS", "MINUS", "MULT", "DIV", "LPAREN", "RPAREN",
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "$accept", "Program", "$@1",
  "Funcs", "FuncDecl", "$@2", "$@3", "$@4", "RetType", "Formals",
  "FormalsList", "FormalDecl", "Statements", "Statement", "$@5",
  "ExpBoolValid", "OptionalElse", "ScopedStatment", "NewScope", "EndScope",
  "Call", "ExpList", "$@6", "Type", "Exp", "M", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-45)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,    14,    77,  -116,  -116,  -116,  -116,  -116,  -116,    77,
    -116,  -116,  -116,  -116,   -10,  -116,    -5,    17,  -116,  -116,
      39,     9,    27,    17,     1,    25,  -116,    46,    98,     2,
     318,  -116,    53,    38,    -3,  -116,    62,  -116,    55,    56,
      37,  -116,   321,  -116,  -116,  -116,    23,    79,  -116,   321,
    -116,   180,    54,  -116,  -116,   321,    52,   321,    98,  -116,
    -116,  -116,    18,  -116,   332,   321,  -116,   140,  -116,  -116,
    -116,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   206,  -116,   321,   100,    98,  -116,  -116,
     321,    67,   114,  -116,   321,   321,   342,   217,   126,   163,
     188,   170,    20,    20,  -116,  -116,  -116,   152,  -116,  -116,
      57,   232,    71,    58,  -116,   258,     3,  -116,   294,   332,
    -116,    98,  -116,  -116,  -116,    74,   321,  -116,  -116,    61,
      81,    91,  -116,  -116,   321,   284,    89,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,    11,    46,    47,    48,     3,     4,
       6,    10,     5,    39,     0,     7,     0,    12,     8,    13,
      14,     0,     0,     0,    16,     0,    15,     0,     0,     0,
       0,    71,     0,     0,     0,    39,     0,    19,     0,     0,
       0,    17,     0,    60,    61,    29,    55,    57,    59,     0,
      56,     0,     0,    34,    71,     0,    71,     0,     0,    71,
      20,    28,     0,    18,    62,     0,    58,     0,    71,    71,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,     0,    40,    40,    22,
       0,     0,     0,    49,     0,     0,    65,    66,    67,    68,
      69,    70,    51,    52,    53,    54,    39,     0,    32,    26,
       0,    43,     0,     0,     9,     0,     0,    50,    63,    64,
      72,     0,    35,    71,    41,     0,     0,    21,    23,     0,
       0,    36,    40,    39,     0,     0,     0,    24,    39,    71,
      38,    72,    45,    27,    25,    37,    31,    71,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -116,   101,  -116,  -116,  -116,  -116,  -116,  -116,
      90,  -116,    59,   -31,  -116,    34,  -116,  -115,    -9,   -81,
     -26,   -16,  -116,    11,   -30,   -53,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    13,    16,    22,    10,    18,
      19,    20,    36,    37,   123,   106,   139,   120,   121,   113,
      50,   110,   125,    39,   107,    52,   131
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    82,    38,    85,    14,    60,    88,   114,    40,   129,
      38,    15,    64,    11,     3,    94,    95,    55,   141,    67,
      11,     5,     6,   145,     7,    83,    58,    86,    21,    17,
      24,    56,    38,    57,    21,    92,    89,    27,    90,    41,
     130,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   140,    79,    80,    91,   111,    60,    56,    23,    65,
     115,    38,    25,    28,   118,   119,     5,     6,    29,     7,
     133,    53,    54,    61,    63,    30,    31,    62,    32,    33,
       4,     5,     6,    34,     7,    66,   146,    84,    81,   116,
     132,   126,   124,   134,   148,    38,   135,   127,   136,   137,
      35,    59,     5,     6,   111,     7,   138,   144,    68,    69,
      12,    30,    31,    26,    32,    33,   108,    87,   142,    34,
     147,     0,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,    35,   112,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    68,    69,
       0,   117,   -45,    74,    75,    76,    77,    78,    79,    80,
      68,    69,     0,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,    93,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,   122,    68,    69,
     -45,    75,    76,    77,    78,    79,    80,     0,    70,   -45,
      77,    78,    79,    80,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    68,    69,   -45,    76,    77,    78,
      79,    80,     0,     0,   109,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      68,    69,   -45,    73,    74,    75,    76,    77,    78,    79,
      80,   -44,     0,     0,     0,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,   143,    69,     0,     0,     0,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    42,    43,
      44,    42,    43,    44,     0,     0,    45,     0,     0,    46,
      47,    48,    46,    47,    48,     0,     0,     0,     0,     0,
       0,     0,    49,     0,     0,    49,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   -45,    72,    73,    74,
      75,    76,    77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      30,    54,    28,    56,    13,    36,    59,    88,     6,     6,
      36,    21,    42,     2,     0,    68,    69,    20,   133,    49,
       9,     4,     5,   138,     7,    55,    35,    57,    17,    34,
      21,    34,    58,    36,    23,    65,    18,    36,    20,    37,
      37,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   132,    32,    33,    36,    85,    87,    34,    19,    36,
      90,    87,    35,    38,    94,    95,     4,     5,    22,     7,
     123,    18,    34,    18,    37,    13,    14,    21,    16,    17,
       3,     4,     5,    21,     7,     6,   139,    35,    34,    22,
     121,    20,    35,    19,   147,   121,   126,    39,    37,    18,
      38,    39,     4,     5,   134,     7,    15,    18,     8,     9,
       9,    13,    14,    23,    16,    17,    82,    58,   134,    21,
     141,    -1,     8,     9,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    38,    37,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     8,     9,
      -1,    37,    26,    27,    28,    29,    30,    31,    32,    33,
       8,     9,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,     8,     9,
      27,    28,    29,    30,    31,    32,    33,    -1,    18,    29,
      30,    31,    32,    33,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     8,     9,    28,    29,    30,    31,
      32,    33,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       8,     9,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,     9,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    10,    11,
      12,    10,    11,    12,    -1,    -1,    18,    -1,    -1,    21,
      22,    23,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    34,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,     4,     5,     7,    43,    44,
      48,    63,    43,    45,    58,    21,    46,    34,    49,    50,
      51,    63,    47,    19,    21,    35,    50,    36,    38,    22,
      13,    14,    16,    17,    21,    38,    52,    53,    60,    63,
       6,    37,    10,    11,    12,    18,    21,    22,    23,    34,
      60,    64,    65,    18,    34,    20,    34,    36,    58,    39,
      53,    18,    21,    37,    64,    36,     6,    64,     8,     9,
      18,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    65,    64,    35,    65,    64,    52,    65,    18,
      20,    36,    64,    35,    65,    65,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    55,    64,    55,    18,
      61,    64,    37,    59,    59,    64,    22,    37,    64,    64,
      57,    58,    35,    54,    35,    62,    20,    39,    18,     6,
      37,    66,    53,    65,    19,    64,    37,    18,    15,    56,
      59,    57,    61,    18,    18,    57,    65,    66,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    45,    46,    47,    44,
      48,    48,    49,    49,    50,    50,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    54,    53,    53,    55,    56,    56,    57,    58,
      59,    60,    60,    61,    62,    61,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     0,     0,     0,    14,
       1,     1,     0,     1,     1,     3,     2,     5,     6,     1,
       2,     5,     3,     5,     6,     7,     4,     7,     2,     2,
       3,     8,     0,     9,     2,     2,     0,     2,     3,     0,
       0,     5,     3,     1,     0,     4,     1,     1,     1,     3,
       4,     3,     3,     3,     3,     1,     1,     1,     2,     1,
       1,     1,     2,     4,     4,     3,     3,     3,     3,     3,
       3,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {asmCmd.initializeProg();}
#line 1431 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1437 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1443 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1449 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "parser.ypp" /* yacc.c:1646  */
    {
				funcReturnDataType = (dynamic_cast<TokenClass*>((yyvsp[0])))->typeInfo;
			}
#line 1457 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "parser.ypp" /* yacc.c:1646  */
    {
				currentFuncId = (dynamic_cast<String*>((yyvsp[0])))->getString();
				verifyIdNotInSymbols(currentFuncId);
			}
#line 1466 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "parser.ypp" /* yacc.c:1646  */
    {
				//1. check if id is main. if so isMainexist=true;
				string id = (dynamic_cast<String*>((yyvsp[-3])))->getString();
				int size = (dynamic_cast<TokenClass*>((yyvsp[0])))->argList.size();
				if(id == "main" && funcReturnDataType.type == DATA_VOID && size == 0){
					isMainExist = true;
				}
				//2. take params (iterate), return type and create new Func, add it to symbol table;
				Func func(id, (dynamic_cast<TokenClass*>((yyvsp[0])))->argList, funcReturnDataType);
				symbolsTable.addFuncSymbol(func);
				currentFuncId = "";
				
				//RAN
				asmCmd.functionInit(func);
			}
#line 1486 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "parser.ypp" /* yacc.c:1646  */
    {
	//3. change funcReturnDataType to DATA_INVALID.
	funcReturnDataType.type = DATA_INVALID; 
	
	StatementClass* statement = dynamic_cast<StatementClass*>((yyvsp[-3]));
	TokenClass* m = dynamic_cast<TokenClass*>((yyvsp[-1]));
	codeBuff.bpatch(statement->nextList, m->transAux.quad);
	
	//RAN
	string id = (dynamic_cast<String*>((yyvsp[-10])))->getString();
	Func func = symbolsTable.getFunc(id);
	asmCmd.functionEnd(func, symbolsTable);

	
}
#line 1506 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "parser.ypp" /* yacc.c:1646  */
    { 
	(yyval) = (yyvsp[0]);
}
#line 1514 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_VOID));
}
#line 1522 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass();
}
#line 1530 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 157 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 1538 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 162 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();
	retToken->argList.push_back((dynamic_cast<TokenClass*>((yyvsp[0])))->typeInfo);
	(yyval) = retToken;
	delete (yyvsp[0]);
}
#line 1549 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();
	//1. add the first exp type to the list.
	retToken->argList.push_back((dynamic_cast<TokenClass*>((yyvsp[-2])))->typeInfo);
	//2. add the rest of the exp to the vector.
	TokenClass* list = dynamic_cast<TokenClass*>((yyvsp[0]));
	for (vector<TypeInfo>::iterator it = list->argList.begin(); it != list->argList.end(); ++it) {
		retToken->argList.push_back(*it);
   	}
	delete (yyvsp[-2]);
	delete (yyvsp[0]);
	(yyval) = retToken;
}
#line 1567 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[0])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	if(currentFuncId == s){
		errorDef(yylineno,s);
		exit(1);
	}
	//2. insert to symbol table (manage offset and all this shit).
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[-1]));
	symbolsTable.addArgSymbol(s,TypeInfo(token->typeInfo.type));
	asmStack.addNewVar(s, symbolsTable);
	(yyval) = new TokenClass(TypeInfo(token->typeInfo));
	delete (yyvsp[-1]);
	delete (yyvsp[0]);
}
#line 1588 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 201 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-3])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	if(currentFuncId == s){
		errorDef(yylineno,s);
		exit(1);
	}
	//2 check valid size > 0 and < 256
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-1]));
	int num = inpNum->getNum();
	if(num <= 0 || num >= 256){
		errorInvalidArraySize(yylineno, s);
		delete (yyvsp[-4]);
		delete (yyvsp[-3]);
		delete (yyvsp[-1]);
		exit(1);
	}
	//3. insert to symbol table (manage offset and all this shit).
	TypeInfo typeInfo;
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[-4]));
	typeInfo.type = getTypeAsArrType(token->typeInfo.type);
	typeInfo.size = num;
	symbolsTable.addArgSymbol(s,typeInfo);
	asmStack.addNewVar(s, symbolsTable);
	(yyval) = new TokenClass(typeInfo);
	delete (yyvsp[-4]);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
}
#line 1623 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-4])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	if(currentFuncId == s){
		errorDef(yylineno,s);
		exit(1);
	}
	//2 check valid size > 0
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-2]));
	int num = inpNum->getNum();
	//3. num > 255 : invalid byte size.
	if(num < 0 || num >= 256){
		errorByteTooLarge(yylineno,inpNum->getStr());
		delete (yyvsp[-5]);
		delete (yyvsp[-4]);
		delete (yyvsp[-2]);
		exit(1);
	}
	if(num <= 0){
		errorInvalidArraySize(yylineno,s);
		delete (yyvsp[-5]);
		delete (yyvsp[-4]);
		delete (yyvsp[-2]);
		exit(1);
	}
	//4. insert to symbol table (manage offset and all this shit).
	TypeInfo typeInfo;
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[-5]));
	typeInfo.type = getTypeAsArrType(token->typeInfo.type);
	typeInfo.size = num;
	symbolsTable.addArgSymbol(s,typeInfo);
	asmStack.addNewVar(s, symbolsTable);
	(yyval) = new TokenClass(typeInfo);
	delete (yyvsp[-5]);
	delete (yyvsp[-4]);
	delete (yyvsp[-2]);
}
#line 1666 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 272 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 1674 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 276 "parser.ypp" /* yacc.c:1646  */
    {
	StatementClass* leftStatements = dynamic_cast<StatementClass*>((yyvsp[-1]));
	StatementClass* rightStatement = dynamic_cast<StatementClass*>((yyvsp[0]));
	StatementClass* retStatement = new StatementClass();

	retStatement->start = leftStatements->start;
	codeBuff.bpatch(leftStatements->nextList, rightStatement->start);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::merge(rightStatement->nextList, CodeBuffer::makelist(codeBuff.emit("j ")));
	(yyval) = retStatement;
}
#line 1690 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 289 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-2]);
}
#line 1698 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 293 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-1])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	//2. insert to symbol table (manage offset and all this shit).
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[-2]));
	StatementClass* retStatement = new StatementClass();
	retStatement->start = codeBuff.genLabel();
	symbolsTable.addSymbol(s,TypeInfo(token->typeInfo.type));
	asmStack.addNewVar(s, symbolsTable);
	delete (yyvsp[-1]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1718 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 309 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-3])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	//2. check Type == exp type.
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-4]));
	TokenClass* token4 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	switch(token1->typeInfo.type){
		case DATA_BYTE:
			if(token4->typeInfo.type != DATA_BYTE){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_INT:
			verifyNumber(token4);
			break;
		case DATA_BOOL:
			verifyBool(token4);
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	//3. insert to symbol table (manage offset and all this shit).
	StatementClass* retStatement = new StatementClass();
	retStatement->start = token4->transAux.startLabel;

	symbolsTable.addSymbol(s,TypeInfo(token1->typeInfo.type));
	asmStack.addNewVar(s, symbolsTable, token4->transAux.assignedReg);
	
	mgr.freeReg(token4->transAux.assignedReg);
	delete (yyvsp[-4]);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1762 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 349 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-4])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	//2. check num < 0 || num >= 256: errorInvalidArraySize 
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-2]));
	int num = inpNum->getNum();
	if(num <= 0 || num >= 256){
		errorInvalidArraySize(yylineno, s);
		delete (yyvsp[-5]);
		delete (yyvsp[-4]);
		delete (yyvsp[-2]);
		exit(1);
	}
	//3. add to symbols(type-arr and size).
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-5]));
	token1->typeInfo.type = getTypeAsArrType(token1->typeInfo.type);
	symbolsTable.addSymbol(s,TypeInfo(token1->typeInfo.type, num));
	
	StatementClass* retStatement = new StatementClass();
	retStatement->start = codeBuff.genLabel();
	asmStack.addNewVar(s, symbolsTable);
	delete (yyvsp[-5]);
	delete (yyvsp[-4]);
	delete (yyvsp[-2]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1796 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 379 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-5])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	//2. check num < 0 : errorInvalidArraySize
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-3]));
	int num = inpNum->getNum();
	if(num <= 0){
		errorInvalidArraySize(yylineno, s);
		delete (yyvsp[-6]);
		delete (yyvsp[-5]);
		delete (yyvsp[-3]);
		exit(1);
	}
	//3. num > 255 : invalid byte size.
	if(num > 255){
		errorByteTooLarge(yylineno,inpNum->getStr());
		delete (yyvsp[-6]);
		delete (yyvsp[-5]);
		delete (yyvsp[-3]);
		exit(1);
	}
	//4. add to symbols(type-arr and size).
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-6]));
	token1->typeInfo.type = getTypeAsArrType(token1->typeInfo.type);
	symbolsTable.addSymbol(s,TypeInfo(token1->typeInfo.type, num));

	StatementClass* retStatement = new StatementClass();
	retStatement->start = codeBuff.genLabel();
	asmStack.addNewVar(s, symbolsTable);
	delete (yyvsp[-6]);
	delete (yyvsp[-5]);
	delete (yyvsp[-3]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1838 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 417 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-3])))->getString();
	//1. check id exists.
	verifyIdInSymbols(s);
	//2. check if not function:
	verifyIdIsntFunction(s);
	//3. check ID type.
	TypeInfo typeInfo = symbolsTable.getIdTypeInfo(s);
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	switch(typeInfo.type){
		case DATA_BYTE:
			if(token3->typeInfo.type != DATA_BYTE){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_INT:
			verifyNumber(token3);
			break;
		case DATA_BOOL:
			verifyBool(token3);
			break;
		case DATA_STRING:
			if(token3->typeInfo.type != DATA_STRING){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_ARR_BYTE:
		case DATA_ARR_INT:
		case DATA_ARR_BOOL:
			if(token3->typeInfo != typeInfo){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	StatementClass* retStatement = new StatementClass();
	retStatement->start = token3->transAux.startLabel;
	asmStack.updateVar(s, symbolsTable, token3->transAux.assignedReg, token3->typeInfo.id);
	
	mgr.freeReg(token3->transAux.assignedReg);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1894 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 469 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-6])))->getString();
	//1. check id exists.
	verifyIdInSymbols(s);
	//2. check if not function:
	verifyIdIsntFunction(s);
	//3. check exp is num.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-4]));
	verifyNumber(token3);
	TokenClass* token6 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	//4. check if assign can be done to this type.
	TypeInfo typeInfo = symbolsTable.getIdTypeInfo(s); //this is the ID array type.
	switch(typeInfo.type){
		case DATA_ARR_BYTE:
			if(token6->typeInfo.type != DATA_BYTE){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_ARR_INT:
			verifyNumber(token6);
			break;
		case DATA_ARR_BOOL:
			verifyBool(token6);
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	StatementClass* retStatement = new StatementClass();
	retStatement->start = token3->transAux.startLabel;
	string reg3 = token3->transAux.assignedReg;
	string reg6 = token6->transAux.assignedReg;
	asmStack.updateArrEntry(s, symbolsTable, reg3, reg6);
	mgr.freeReg(reg3);
	mgr.freeReg(reg6);
	delete (yyvsp[-6]);
	delete (yyvsp[-4]);
	delete (yyvsp[-1]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1942 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 513 "parser.ypp" /* yacc.c:1646  */
    {
	StatementClass* retStatement = new StatementClass();
	retStatement->start = (dynamic_cast<TokenClass*>((yyvsp[-1])))->transAux.startLabel;
	delete (yyvsp[-1]);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1955 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 522 "parser.ypp" /* yacc.c:1646  */
    {
	if(funcReturnDataType.type != DATA_VOID){
		errorMismatch(yylineno);
		exit(1);
	}
	StatementClass* retStatement = new StatementClass();
	retStatement->start = codeBuff.genLabel();

	Func func = symbolsTable.getFunc(currentFuncId);
	asmCmd.functionEnd(func, symbolsTable);
	// codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	// retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 1974 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 537 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token2 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	switch(funcReturnDataType.type){
		case DATA_VOID:
			errorMismatch(yylineno);
			exit(1);
			break;
		case DATA_BYTE:
			if(token2->typeInfo.type != DATA_BYTE){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_INT:
			if(token2->typeInfo.type != DATA_BYTE && token2->typeInfo.type != DATA_INT){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		case DATA_BOOL:
			if(token2->typeInfo.type != DATA_BOOL){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}

	//HW5 addition:
	StatementClass* retStatement = new StatementClass();
	retStatement->start = token2->transAux.startLabel;
	string reg = token2->transAux.assignedReg;
	if (token2->typeInfo.type == DATA_BOOL) {
		string trueLable = codeBuff.genLabel();		//generate true lable for BP purpose.
		codeBuff.emit("li $v0, 1");					//save 1 (true) into the reg as said in trueStream.
		codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
		vector<int> nextList = CodeBuffer::makelist(codeBuff.emit("j "));
		string falseLabel = codeBuff.genLabel();	//generate true lable for BP purpose.
		codeBuff.emit("li $v0, 0");					//save 1 (true) into the reg as said in trueStream.
		string endLable = codeBuff.genLabel();		//generate the rule's ending label.
		codeBuff.bpatch(token2->transAux.trueList, trueLable);
		codeBuff.bpatch(token2->transAux.falseList, falseLabel);
		codeBuff.bpatch(nextList, endLable);
		/*====== generated code: ====
		lable_<true>:
		li $v0, 1
		j lable_<end>
		lable_<false>:
		li $v0, 0
		lable_<end>:
		===========================*/
	}
	else{
		codeBuff.emit("move $v0, " + reg);
		mgr.freeReg(reg);
	}
	Func func = symbolsTable.getFunc(currentFuncId);
	asmCmd.functionEnd(func, symbolsTable);

	delete (yyvsp[-1]);
	// codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	// retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
}
#line 2045 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 604 "parser.ypp" /* yacc.c:1646  */
    {
	
	TokenClass* 	m1				= dynamic_cast<TokenClass*>((yyvsp[-6]));
	TokenClass* 	condition		= dynamic_cast<TokenClass*>((yyvsp[-4]));
	StatementClass* statement1 		= dynamic_cast<StatementClass*>((yyvsp[-3]));
	TokenClass* 	n 				= dynamic_cast<TokenClass*>((yyvsp[-2]));
	StatementClass* statement2 		= dynamic_cast<StatementClass*>((yyvsp[-1]));
	TokenClass* 	m2				= dynamic_cast<TokenClass*>((yyvsp[0]));
	StatementClass* retStatement	= new StatementClass();
	
	retStatement->start  = m1->transAux.quad;
	codeBuff.bpatch(condition->transAux.trueList, statement1->start);
	codeBuff.bpatch(condition->transAux.falseList, statement2->start);
	codeBuff.bpatch(n->transAux.nextList, m2->transAux.quad);
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retStatement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = retStatement;
	delete (yyvsp[-6]);
	delete (yyvsp[-4]);
	delete (yyvsp[-3]);
	delete (yyvsp[-2]);
	delete (yyvsp[-1]);
	delete (yyvsp[0]);
}
#line 2074 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 629 "parser.ypp" /* yacc.c:1646  */
    {
	++numOfWhileContaining;
	//HW5 addition:
	statementStack.push(new StatementClass()); 

}
#line 2085 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 634 "parser.ypp" /* yacc.c:1646  */
    {	
	--numOfWhileContaining;
	//HW5 addition:
	//set local vars for comfort:
	TokenClass* m1 				= dynamic_cast<TokenClass*>((yyvsp[-6]));
	TokenClass* conditionToken 	= dynamic_cast<TokenClass*>((yyvsp[-5]));
	TokenClass* m2 				= dynamic_cast<TokenClass*>((yyvsp[-3]));
	TokenClass* n 				= dynamic_cast<TokenClass*>((yyvsp[-1]));
	TokenClass* m3 				= dynamic_cast<TokenClass*>((yyvsp[0]));
	StatementClass* statement 	= statementStack.top();
	
	codeBuff.bpatch(conditionToken->transAux.trueList, m2->transAux.quad);
	statement->breakList = CodeBuffer::merge(conditionToken->transAux.falseList, statement->breakList);
	codeBuff.bpatch(statement->breakList, m3->transAux.quad);
	codeBuff.bpatch(n->transAux.nextList, m1->transAux.quad);
	statement->start  = m1->transAux.quad;						//set starting label using the first M marker.
	statement->breakList.clear();
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	statement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = statement;
	statementStack.pop();

	delete (yyvsp[-6]);
	delete (yyvsp[-5]);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	delete (yyvsp[0]);
}
#line 2118 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 663 "parser.ypp" /* yacc.c:1646  */
    {
	if(numOfWhileContaining == 0){
		errorUnexpectedBreak(yylineno);
		exit(1);
	}
	
	//HW5 addition:
	/*set the starting label:*/
	StatementClass* statement = new StatementClass();
	statement->start = codeBuff.genLabel();
	/*make a jump and save it in the break list:*/
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	statementStack.top()->breakList = CodeBuffer::merge(statementStack.top()->breakList, CodeBuffer::makelist(codeBuff.emit("j ")));
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	statement->nextList = CodeBuffer::makelist(codeBuff.emit("j "));
	(yyval) = statement;
}
#line 2140 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 682 "parser.ypp" /* yacc.c:1646  */
    { 
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	verifyBool(token1);
	(yyval) = token1;
}
#line 2150 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 689 "parser.ypp" /* yacc.c:1646  */
    {
	StatementClass* statement = new StatementClass(); 
	statement->start = codeBuff.genLabel();	//generate a lable at that location.
	(yyval) = statement;	
}
#line 2160 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 695 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 2168 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 699 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-1]);
}
#line 2176 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 703 "parser.ypp" /* yacc.c:1646  */
    {
	symbolsTable.addScope();
}
#line 2184 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 707 "parser.ypp" /* yacc.c:1646  */
    {
	//TODO: delete symbols from stack.
	endScope();
	asmStack.popScopeVars(symbolsTable);
	printScopeSymbols();
	symbolsTable.removeScope();
}
#line 2196 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 716 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-4])))->getString();
	verifyFunctionPresent(s);
	Func f = getFuncFromTable(s);
	TokenClass* token4 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	vector<string> tmpArgVec;
	convertTypeInfoVecToStringVec(f.argsTypes, tmpArgVec);
	if(f.argsTypes.size() != token4->argList.size()){
		errorPrototypeMismatch(yylineno, s, tmpArgVec);
		exit(1);
	}
	for(int i=0 ; i < f.argsTypes.size() ; ++i){
		if(f.argsTypes[i] != token4->argList[i]){
			if(f.argsTypes[i].type != DATA_INT || token4->argList[i].type != DATA_BYTE){
				errorPrototypeMismatch(yylineno, s, tmpArgVec);
				exit(1);
			}
		}
	}
	//start of HW5 part:
	TokenClass* retToken = new TokenClass(f.funcRetVal);
	/*start with jumping to the start of the func (at this point all args calculated): */
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	retToken->transAux.afterExp = CodeBuffer::makelist(codeBuff.emit("j "));
	//for each argument, if bool, calculate BP part:
	for (int i = 0; i < expListVec.size(); i++){
		if (expListVec[i]->typeInfo.type != DATA_BOOL){
			continue;
		}
		string reg = mgr.getReg();
		expListVec[i]->transAux.assignedReg = reg;
		stringstream trueStream, falseStream, nextStream;
		string trueLable = codeBuff.genLabel();			//generate true lable for BP purpose.
		trueStream << "li " << reg << ", 1";			//trueStream = set the reg the value of true.
		codeBuff.emit(trueStream.str());				//save 1 (true) into the reg as said in trueStream.
		if (i != (expListVec.size() - 1)){
			nextStream.clear();
			nextStream << "j " << expListVec[i+1]->transAux.startLabel;
			codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
			codeBuff.emit(nextStream.str());
		} 
		else {
			codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
			retToken->transAux.afterExp = CodeBuffer::merge(retToken->transAux.afterExp,CodeBuffer::makelist(codeBuff.emit("j ")));
		}
		codeBuff.bpatch(expListVec[i]->transAux.trueList, trueLable);

		/* EXACTLY THE SAME CODE ONLY WITH 0 TO THE REG */
		string falseLabel = codeBuff.genLabel();		//generate false lable for BP purpose.
		falseStream << "li " << reg << ", 0";			//falseStream = set the reg the value of false.
		
		codeBuff.emit(falseStream.str());
		if (i != (expListVec.size() - 1)){
			codeBuff.emit(nextStream.str());
		}
		else {
			codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
			retToken->transAux.afterExp = CodeBuffer::merge(retToken->transAux.afterExp,CodeBuffer::makelist(codeBuff.emit("j ")));
		}
		
		codeBuff.bpatch(expListVec[i]->transAux.falseList, falseLabel);
	}
	asmCmd.callFuncWithParams(f, expListVec, symbolsTable);
	for(int i = 0; i < expListVec.size(); i++){
		delete expListVec[i];
	} 
	expListVec.clear();
	retToken->transAux.startLabel = (dynamic_cast<TokenClass*>((yyvsp[-2])))->transAux.quad;
	delete (yyvsp[-4]);
	delete (yyvsp[-1]);
	(yyval) = retToken;
}
#line 2273 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 789 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-2])))->getString();
	verifyFunctionPresent(s);
	Func f = getFuncFromTable(s);
	vector<string> tmpArgVec;
	convertTypeInfoVecToStringVec(f.argsTypes, tmpArgVec);
	if(f.argsTypes.size() > 0){
		errorPrototypeMismatch(yylineno, s, tmpArgVec);
		exit(1);
	}
	TokenClass* token = new TokenClass(f.funcRetVal);
	token->transAux.startLabel = codeBuff.genLabel();
	asmCmd.callFunc(f);
	delete (yyvsp[-2]);
	(yyval) = token;
}
#line 2294 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 807 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();			//generate a returned token.
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[0]));	//cast and rename the input exp.
	expListVec.push_back(token1);
	retToken->argList.push_back(token1->typeInfo);			
	(yyval) = retToken;
}
#line 2306 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 815 "parser.ypp" /* yacc.c:1646  */
    {expListVec.push_back(dynamic_cast<TokenClass*>((yyvsp[0])));}
#line 2312 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 815 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();				//generate a returned token.
	//1. add the first exp type to the list.
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-3]));		//cast and rename the input exp.
	retToken->argList.push_back(token1->typeInfo);			
	//2. add the rest of the exp to the vector.
	TokenClass* token4 = dynamic_cast<TokenClass*>((yyvsp[0]));		//cast and rename the input exp list.
	for (vector<TypeInfo>::iterator it = token4->argList.begin(); it != token4->argList.end(); ++it) {
		retToken->argList.push_back(*it);
   	}
	delete (yyvsp[0]);
	(yyval) = retToken;
}
#line 2330 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 830 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_INT)); 
}
#line 2338 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 834 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BYTE)); 
}
#line 2346 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 838 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BOOL)); 
}
#line 2354 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 844 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-1]);
}
#line 2362 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 848 "parser.ypp" /* yacc.c:1646  */
    {	
	string idStr = (dynamic_cast<String*>((yyvsp[-3])))->getString();
	//1. verify id is in.
	verifyIdInSymbols(idStr);
	//2. get the array type.
	TypeInfo arrType = symbolsTable.getIdTypeInfo(idStr);
	//3. verify valid array type.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	if(token3->typeInfo.type != DATA_BYTE && token3->typeInfo.type != DATA_INT){
		errorMismatch(yylineno);
		exit(1);
	}
	//4. use array type to determine the returned type or print error.
	TokenClass* retExp;
	switch(arrType.type){
		case DATA_ARR_BYTE:
			retExp = new TokenClass(TypeInfo(DATA_BYTE));
			break;
		case DATA_ARR_INT:
			retExp = new TokenClass(TypeInfo(DATA_INT));
			break;
		case DATA_ARR_BOOL:
			retExp = new TokenClass(TypeInfo(DATA_BOOL));
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	string reg = mgr.getReg();
	string reg3 = token3->transAux.assignedReg;
	asmStack.getArrEntry(idStr, symbolsTable, reg3, reg);
	retExp->transAux.assignedReg = reg;
	checkBoolAndGenPrint(retExp, reg);	//will release register if bool value.
	mgr.freeReg(reg3);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	(yyval) = retExp;
}
#line 2405 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 887 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input left token.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));		//save the input right token.
	(yyval) = binOpAction(token1, token3, "+");					//operate usign + sign.
}
#line 2415 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 893 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input left token.		
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));		//save the input right token.		
	(yyval) = binOpAction(token1, token3, "-");					//operate usign - sign.
}
#line 2425 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 899 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input left token.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));		//save the input right token.
	(yyval) = binOpAction(token1, token3, "*");					//operate usign * sign.
}
#line 2435 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 905 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input left token.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));		//save the input right token.
	(yyval) = binOpAction(token1, token3, "/");					//operate usign / sign.
}
#line 2445 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 911 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[0])))->getString();	//check if id exists, exit if not.
	verifyIdInSymbols(s);									//get its type from symbol table.
	TypeInfo typeInfo = symbolsTable.getIdTypeInfo(s);		//make token out of type and return it.
	TokenClass* token = new TokenClass(typeInfo);	
	string reg;			
	token->transAux.startLabel = codeBuff.genLabel();		//generate a lable.
	if( typeInfo.type == DATA_ARR_BOOL ||
		typeInfo.type == DATA_ARR_INT  ||
		typeInfo.type == DATA_ARR_BYTE ){
		token->typeInfo.id = s;
	}else{
		reg = asmStack.loadVar(s, symbolsTable);			//assign a register.
		token->transAux.assignedReg = reg;					//save the assigned register.
		checkBoolAndGenPrint(token, reg);					//generate and print a boolean branch.
	}
	delete (yyvsp[0]);
	(yyval) = token;
}
#line 2469 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 931 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[0]));		//save the input token.
	string reg = mgr.getReg();								//assign a register.
	token->transAux.assignedReg = reg;						//save the assigned register.				
	stringstream getRetValStream;
	getRetValStream << "move " << reg << ", $v0";			//save call's return value inside the assigned reg.
	codeBuff.emit(getRetValStream.str());					//write the line to buffer.
	checkBoolAndGenPrint(token, reg);						//generate and print a boolean branch.
	(yyval) = token;												//save the generated token.
}
#line 2484 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 942 "parser.ypp" /* yacc.c:1646  */
    {
	Num* inpNum = dynamic_cast<Num*>((yyvsp[0]));
	int num = inpNum->getNum();
	TokenClass* token = new TokenClass(TypeInfo(DATA_INT));		//generate a returned token.
	saveInputNumIntoToken(token, num);							//save needed data into token.
	delete (yyvsp[0]);													//clean allocated memory.
	(yyval) = token;													//save the generated token.
}
#line 2497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 951 "parser.ypp" /* yacc.c:1646  */
    {
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-1]));
	int num = inpNum->getNum();
	if( num < 0 || num > 255){									//validate byte range.
		errorByteTooLarge(yylineno,inpNum->getStr());
		delete (yyvsp[-1]);
		exit(1);
	}
	TokenClass* token = new TokenClass(TypeInfo(DATA_BYTE));	//generate a returned token.
	saveInputNumIntoToken(token, num);							//save needed data into token.
	delete (yyvsp[-1]);													//clean allocated memory.
	(yyval) = token;													//save the generated token.
}
#line 2515 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 965 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token = new TokenClass(TypeInfo(DATA_STRING));	//generate a returned token.
	String* inputString = dynamic_cast<String*>((yyvsp[0]));			//save the input token.				
	
	string str = inputString->getString();
	token->transAux.startLabel = codeBuff.genLabel();			//generate a new lable.
	token->transAux.assignedReg = asmCmd.saveStringInDataSection(str);
	
	delete (yyvsp[0]);													//clean allocated memory.
	(yyval) = token;													//save the generated token.
}
#line 2531 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 977 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = basicBoolPrint(true);
}
#line 2539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 981 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = basicBoolPrint(false);
}
#line 2547 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 985 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token2 = dynamic_cast<TokenClass*>((yyvsp[0]));					//save the input token.
	TokenClass* resultToken = logicalOpAction(token2,token2,"NOT","");	
	(yyval) = resultToken;													//save the generated token.
}
#line 2557 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 991 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-3]));					//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-1]));				
	TokenClass* token4 = dynamic_cast<TokenClass*>((yyvsp[0]));				
	TokenClass* resultToken = logicalOpAction(token1, token4, "AND",token3->transAux.quad);	
	(yyval) = resultToken;													//save the generated token.
}
#line 2569 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 999 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-3]));				//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-1]));				
	TokenClass* token4 = dynamic_cast<TokenClass*>((yyvsp[0]));				
	TokenClass* resultToken = logicalOpAction(token1, token4, "OR", token3->transAux.quad);
	(yyval) = resultToken;												//save the generated token.
}
#line 2581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1007 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));			//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));	
	TokenClass* resultToken = relOpAction(token1,token3,"beq ");//validate its a number and act.
	(yyval) = resultToken;											//save the generated token.
}
#line 2592 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1014 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));			//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	TokenClass* resultToken = relOpAction(token1,token3,"bne ");//validate its a number and act.
	(yyval) = resultToken;											//save the generated token.
}
#line 2603 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1021 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	TokenClass* resultToken = relOpAction(token1,token3,"blt ");//validate its a number and act.
	(yyval) = resultToken;										//save the generated token.
}
#line 2614 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1028 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	TokenClass* resultToken = relOpAction(token1,token3,"bgt ");//validate its a number and act.
	(yyval) = resultToken;										//save the generated token.
}
#line 2625 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1035 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));		//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	TokenClass* resultToken = relOpAction(token1,token3,"ble ");//validate its a number and act.
	(yyval) = resultToken;										//save the generated token.
}
#line 2636 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1042 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));			//save the input tokens.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	TokenClass* resultToken = relOpAction(token1,token3,"bge ");//validate its a number and act.
	(yyval) = resultToken;											//save the generated token.
}
#line 2647 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1049 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token = new TokenClass();		//generate token.
	token->transAux.quad = codeBuff.genLabel();	//generate a lable at that location.
	(yyval) = token;									//save the token to be returned.
}
#line 2657 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1055 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token = new TokenClass();									//generate token.
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	token->transAux.nextList = CodeBuffer::makelist(codeBuff.emit("j "));	//generate a jump command and set into nextList to complete it later.
	(yyval) = token;																//save the token to be returned.
}
#line 2668 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2672 "parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1062 "parser.ypp" /* yacc.c:1906  */

/*========================================================
			section 3	-	c user routines
========================================================*/
TokenClass* basicBoolPrint(bool isTrue){
	TokenClass* token = new TokenClass(TypeInfo(DATA_BOOL));			//save the input token.
	token->transAux.startLabel = codeBuff.genLabel(); 					//generate starting point.
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	int jumpAddress = codeBuff.emit("j ");								//create a new jumping point.
	if(isTrue){
		token->transAux.trueList = CodeBuffer::makelist(jumpAddress);	//save it's address in the list.
	}
	else{
		token->transAux.falseList = CodeBuffer::makelist(jumpAddress);	//save it's address in the list.	
	}
	return token;														//save the generated token.
}

void checkBoolAndGenPrint(TokenClass* token, string reg){
	if (token->typeInfo.type == DATA_BOOL){	//in case its a bool data - generate a true/false BP infrastructure.
		stringstream branchStream;
		branchStream << "beq " << reg << ", 1, ";				
		token->transAux.trueList = CodeBuffer::makelist(codeBuff.emit(branchStream.str()));
		codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
		token->transAux.falseList = CodeBuffer::makelist(codeBuff.emit("j "));
		mgr.freeReg(reg);					//in this case no need to save the bool value in the reg, so release it.
		token->transAux.assignedReg = "";	//delete reg from token.
	}
}

void saveInputNumIntoToken(TokenClass* token, int num){
	token->transAux.startLabel = codeBuff.genLabel();	//generate starting point.
	string reg = mgr.getReg();
	token->transAux.assignedReg = reg;					//save the register name at the token.
	mgr.storeToRegImm(reg,num);
}

void relOpPrint(string op, TokenClass* resTok, string leftReg, string rightReg){
	resTok->transAux.startLabel = codeBuff.genLabel();
	stringstream command;
	command << op << leftReg << ", " << rightReg << ", ";
	resTok->transAux.trueList = CodeBuffer::makelist(codeBuff.emit(command.str()));
	codeBuff.emit("# input line number: " + toString(yylineno) + " :: parser.ypp line number: " + toString(1 + __LINE__));
	resTok->transAux.falseList = CodeBuffer::makelist(codeBuff.emit("j "));
	mgr.freeReg(leftReg);
	mgr.freeReg(rightReg);
}

TokenClass* logicalOpAction(TokenClass* exp1, TokenClass* exp2, string op, string quad){
	verifyBool(exp1,exp2);
	TokenClass* token = new TokenClass(TypeInfo(DATA_BOOL));
	/*use the same starting lable as the first bool.*/
	token->transAux.startLabel = exp1->transAux.startLabel;	
	if(op == "NOT"){
		/*switch all the places for true with false.*/
		token->transAux.trueList 	= exp1->transAux.falseList; 
		/*switch all the places for false with true.*/
		token->transAux.falseList  	= exp1->transAux.trueList;	
	}
	else if(op == "AND"){
		/*for AND op we need to merge false lists - one false jumps to "false code section".*/
		token->transAux.falseList = CodeBuffer::merge(exp1->transAux.falseList, exp2->transAux.falseList);
		/*for AND op we need all previus true (left-most) values to jump to M position.*/
		codeBuff.bpatch(exp1->transAux.trueList, quad);
		/*current trueList will have the same as right Exp list.*/
		token->transAux.trueList = exp2->transAux.trueList;
	}
	else if(op == "OR"){
		/*for OR op we need to merge true lists - one true jumps to "true code section".*/
		token->transAux.trueList = CodeBuffer::merge(exp1->transAux.trueList, exp2->transAux.trueList);
		/*for OR op we need all previus false (left-most) values to jump to M position.*/
		codeBuff.bpatch(exp1->transAux.falseList, quad);
		/*current falseList will have the same as right Exp list.*/
		token->transAux.falseList = exp2->transAux.falseList; 
	}
	if(exp1 != exp2){
		delete exp2;
	}
	delete exp1;
	return token;
}

TokenClass* relOpAction(TokenClass* exp1, TokenClass* exp2, string op){
	verifyNumber(exp1, exp2);
	TokenClass* retExp = new TokenClass(TypeInfo(DATA_BOOL));
	relOpPrint(op, retExp, exp1->transAux.assignedReg, exp2->transAux.assignedReg);
	if(exp1 != exp2){
		delete exp2;
	}
	delete exp1;
	return retExp;
}

TokenClass* binOpAction(TokenClass* exp1, TokenClass* exp2, string op){
	verifyNumber(exp1, exp2);
	TypeInfo retType(DATA_INT);
	bool isByte = false;
	if(exp1->typeInfo.type == DATA_BYTE && exp2->typeInfo.type == DATA_BYTE){
		retType.type = DATA_BYTE;
		isByte = true;
	}
	TokenClass* token = new TokenClass(retType);
	string leftReg = exp1->transAux.assignedReg;
	string rightReg = exp2->transAux.assignedReg; 
	
	if(op == "+"){
		arithMgr.add(leftReg, rightReg, isByte);
	}
	else if(op == "-"){
		arithMgr.sub(leftReg, rightReg, isByte);
	}
	else if(op == "*"){
		arithMgr.multiply(leftReg, rightReg, isByte);
	}
	else if(op == "/"){
		arithMgr.divide(leftReg, rightReg, isByte);	
	}
	token->transAux.assignedReg = leftReg;
	mgr.freeReg(rightReg);
	delete exp2;
	delete exp1;
	return token;
}

void verifyNumber(TokenClass* e){
	if(e->typeInfo.type != DATA_BYTE && e->typeInfo.type != DATA_INT){
		errorMismatch(yylineno);
		exit(1);
	}
}

void verifyNumber(TokenClass* e1, TokenClass* e2){
	verifyNumber(e1);
	verifyNumber(e2);
}

void verifyBool(TokenClass* e){
	if(e->typeInfo.type != DATA_BOOL){
		errorMismatch(yylineno);
		exit(1);
	}
}

void verifyBool(TokenClass* e1, TokenClass* e2){
	verifyBool(e1);
	verifyBool(e2);
}

void verifyIdNotInSymbols(string id){
	if(symbolsTable.isIdInTable(id)){
		errorDef(yylineno, id);
		exit(1);
	}
}

void verifyIdInSymbols(string id){
	if(!(symbolsTable.isIdInTable(id))){
		errorUndef(yylineno, id);
		exit(1);
	}
}

void verifyFunctionPresent(string id){
	if(!(symbolsTable.isFuncInTable(id))){
		errorUndefFunc(yylineno, id);
		exit(1);
	}
}

void verifyIdIsntFunction(string id){
	if(symbolsTable.isFuncInTable(id)){
		errorUndef(yylineno, id);
		exit(1);
	}
}

Func getFuncFromTable(string id){
	return symbolsTable.getFunc(id);
}

void convertTypeInfoVecToStringVec(vector<TypeInfo>& typeVec, vector<string>& outputVec){
	for(int i=0 ; i<typeVec.size() ; ++i){
		outputVec.push_back(typeVec[i].getAsStringWithArraySizes());
	}
}

void yyerror(const char*) {
	errorSyn(yylineno);
	exit(1);
}

void printFunctions(){
	/*vector<Func> funcsVec = symbolsTable.getFuncs();
	vector<string> argNameVec;
	for (vector<Func>::iterator it = funcsVec.begin(); it != funcsVec.end(); ++it) {
		convertTypeInfoVecToStringVec(it->argsTypes ,argNameVec);
		cout << it->id << " " << makeFunctionType(it->funcRetVal.getAsString(), argNameVec) << " 0" << endl;
		argNameVec.clear();
	}*/
}

void printScopeSymbols(){
	symbolsTable.printCurrentScopeSymbols();
}

DATA_TYPE getTypeAsArrType(DATA_TYPE type){
	DATA_TYPE arrType;
	switch(type){
		case DATA_BOOL:
			arrType = DATA_ARR_BOOL;
			break;
    	case DATA_BYTE:
    		arrType = DATA_ARR_BYTE;
    		break;
    	case DATA_INT:
    		arrType = DATA_ARR_INT;
    		break;
	}
	return arrType;
}

int main() {	
	//add "print" func to symbol table
    vector<TypeInfo> printArgs;
    printArgs.push_back(TypeInfo(DATA_STRING));
    string funcName = string("print");
    Func func(funcName, printArgs, TypeInfo(DATA_VOID));
	symbolsTable.addFuncSymbol(func);

    //add "printi" func to symbol table
    vector<TypeInfo> printiArgs;
    printiArgs.push_back(TypeInfo(DATA_INT));
    funcName = string("printi");
    func = Func(funcName, printiArgs, TypeInfo(DATA_VOID));
	symbolsTable.addFuncSymbol(func);
	
	int result = yyparse();
	if (result != 0) {
		errorSyn(yylineno);
		exit(1);
	}
	
	if (!isMainExist) {
	   errorMainMissing();
	   exit(1);
    }
    
	//end of global scope
	endScope();   
	printFunctions();
	mgr.print();
	
	return 0;
}
