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
#line 1 "parser.ypp" /* yacc.c:339  */

	#include <iostream>
	#include <map>
	#include <string>
	#include <vector>
	#include "parser.hpp"
	#include "output.hpp"
	#include "compiler.hpp"

	#ifndef YYERROR_VERBOSE
	#define YYERROR_VERBOSE 0 
	#endif

	using namespace std;
	using namespace output;
	
		unsigned int _breakables = 0;
	
	//example: bool isA = isVarExists(_TablesStack.back(), "a");
	bool isVarExists(const string& name);
	//example: bool isFunA = isFunExists(_FunctionsStack, "funcA");
	bool isFunExists(const string& name);
	VariableType getVariableType(string name);
	VariableType getFunctionReturnType(string name);
	vector<VariableType>& getFunctionArgsTypes(string name);
	void declareVariable(VariableType type, string name);
	void declareArgument(VariableType type, string name);
	void declareFunction(VariableType type, string name);
	void openScope();
	void closeScope();
	void closeGlobalScope();
	
	void assertIfMainUndefined();
	void assert_unexpected_break();
	void assertIfDefined(string name);
	void assertIfUndefined(string name);
	bool isNumericType(VariableType type);
	void assertIfNotBool(VariableType type);
	void assertIfNotNumeric(VariableType type);
	void assertIfTypeNotMatch(VariableType type1, VariableType type2);
	bool isNumericType(VariableType type);
	void assertUnexpectedBreak();
	void assertIfByteTooLarge(string value);
	void assertIfDefault();
	void assertFuncUndefined(string name);
	
	bool is_assignable(VariableType src, VariableType dst);
	bool is_assignable(vector<VariableType> srcs, vector<VariableType> dsts);
	FunctionEntry& getFunction(string name); //@@@@@@@@
	
	//void declarePrint() ;
	//void declarePrinti() ;

	
	extern int yylex();
	int yyerror(const char * message);
	extern int yylineno;
	
	


#line 128 "parser.tab.cpp" /* yacc.c:339  */

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
    RETURN = 258,
    LPAREN = 259,
    RPAREN = 260,
    LBRACE = 261,
    RBRACE = 262,
    SC = 263,
    COLON = 264,
    ASSIGN = 265,
    OR = 266,
    AND = 267,
    RELOP = 268,
    RELEQ = 269,
    PLUS = 270,
    MINUS = 271,
    MULT = 272,
    DIV = 273,
    NOT = 274,
    INT = 275,
    BYTE = 276,
    VOID = 277,
    COMMA = 278,
    TRUE = 279,
    FALSE = 280,
    IF = 281,
    ELSE = 282,
    WHILE = 283,
    BREAK = 284,
    BOOL = 285,
    SWITCH = 286,
    CASE = 287,
    DEFAULT = 288,
    NUM = 289,
    ID = 290,
    STRING = 291,
    B = 292
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

#line 217 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   114,   115,   117,   117,   122,   129,   137,
     138,   141,   142,   145,   152,   160,   163,   166,   166,   170,
     178,   187,   196,   199,   208,   219,   224,   224,   231,   231,
     231,   236,   244,   244,   252,   252,   261,   266,   274,   280,
     286,   291,   297,   305,   314,   325,   327,   335,   337,   340,
     343,   348,   361,   362,   364,   365,   367,   368,   369,   371,
     374,   387,   400,   413,   426,   436,   443,   444,   450,   451,
     452,   453,   457,   462,   467,   472,   478
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RETURN", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SC", "COLON", "ASSIGN", "OR", "AND", "RELOP", "RELEQ", "PLUS",
  "MINUS", "MULT", "DIV", "NOT", "INT", "BYTE", "VOID", "COMMA", "TRUE",
  "FALSE", "IF", "ELSE", "WHILE", "BREAK", "BOOL", "SWITCH", "CASE",
  "DEFAULT", "NUM", "ID", "STRING", "B", "$accept", "Program", "Funcs",
  "FuncDecl", "$@1", "FuncHeader", "FormalsParen", "FormalsList",
  "FormalDecl", "VarDecl", "Statements", "Statement", "$@2", "$@3", "$@4",
  "$@5", "$@6", "IfStatement", "$@7", "SwitchExpMarker",
  "SwitchCasesMarker", "WhileCondMarker", "WhileStatementMarker",
  "IfCondMarker", "IfStatementMarker", "ElseStatementMarker",
  "MarkerStart", "CaseList", "CaseStatement", "CaseDec", "Call",
  "ExpParen", "ExpList", "Type", "Exp", "Next", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -49

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-49)))

#define YYTABLE_NINF -41

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -49,     6,    71,   -49,   -49,   -49,   -23,   -49,   -49,    71,
     -49,   -19,   -49,   -49,    27,   -49,     3,    35,   -49,    41,
      30,    19,   110,   -49,   -11,   -49,   125,   -49,   -49,    42,
     -49,    10,     5,    37,   -49,    29,    33,    53,    34,   -49,
     139,   -49,   139,   -49,   -49,    25,    60,   -49,   -49,   219,
     110,   -49,   -49,    66,   132,   139,   -49,   -49,   139,   -49,
     -49,   -49,    75,   -49,   -49,   166,   -49,   -49,   -49,   -49,
     -49,   139,   139,   139,   139,   139,   139,    77,    78,   139,
     -49,     2,   249,   230,   241,   -49,   139,   -49,   139,   139,
      59,    72,     9,     9,   -49,   -49,   -49,   139,   180,   -49,
     139,   -49,   -49,   110,   194,   256,   262,   208,   -49,   249,
     -49,   -49,   -49,   -49,   -49,   -49,    88,   110,   110,    -3,
     -49,   -49,    68,   101,    15,   -49,    97,    -5,   -49,   103,
     -49,    97,   -49,   105,   -49,   -49
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      43,     0,     4,     1,    56,    57,     0,    58,     2,     4,
       5,     0,     8,     3,     0,     7,     0,     0,    10,     0,
      11,     0,    40,     9,     0,    13,     0,    17,    28,     0,
      36,     0,     0,    40,    16,    25,     0,     0,     0,    12,
       0,    23,     0,    69,    70,    66,    64,    68,    65,     0,
      40,    38,    31,     0,     0,     0,    51,    19,     0,     6,
      15,    42,     0,    22,    14,     0,    71,    67,    24,    76,
      76,     0,     0,     0,     0,     0,     0,    40,     0,     0,
      53,     0,    54,     0,     0,    26,     0,    59,     0,     0,
      74,    75,    60,    61,    62,    63,    18,     0,     0,    52,
       0,    21,    20,    40,     0,    73,    72,     0,    32,    55,
      27,    41,    29,    37,    34,    39,     0,    40,    40,     0,
      35,    30,     0,     0,     0,    45,    47,     0,    50,     0,
      44,    46,    48,     0,    33,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   106,   -49,   -49,   -49,   -49,    95,   -49,   -49,
     -48,   -32,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    -4,   -49,
     -22,   -49,   -49,   146,   -37,    51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     8,     9,    14,    10,    17,    19,    20,    32,
      33,    34,    50,   103,    51,   115,   113,    35,   117,    53,
     116,    78,   118,    36,   114,    85,     2,   124,   125,   126,
      48,    56,    81,    38,    49,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    60,    77,    65,   132,    66,     3,    99,    18,     4,
       5,    37,    12,    57,    54,    58,    15,    82,    83,     7,
      55,    84,   129,     4,     5,   100,    75,    76,    37,   122,
     123,    16,   133,     7,    90,    91,    92,    93,    94,    95,
      26,    22,    98,    27,    59,    60,    23,   122,   123,   104,
      52,   105,   106,    24,    25,    37,    61,     4,     5,    62,
     107,    63,    67,   109,    54,    28,    29,     7,    30,    64,
      79,   110,    31,    72,    73,    74,    75,    76,   131,    86,
      26,    37,    97,    27,    96,   120,   121,    73,    74,    75,
      76,     4,     5,     6,   119,    37,    37,     4,     5,    60,
      26,     7,   127,    27,    37,    28,    29,     7,    30,    37,
     128,   134,    31,    26,   135,    13,    27,     4,     5,    39,
     130,    89,     0,   -40,     0,    28,    29,     7,    30,    40,
       4,     5,    31,    41,     0,     0,    40,    80,    28,    29,
       7,    30,     0,    40,    42,    31,     0,     0,    11,    43,
      44,    42,     0,     0,     0,    11,    43,    44,    42,    45,
      46,    47,    21,    43,    44,     0,    45,    46,    47,     0,
      21,    87,     0,    45,    46,    47,     0,    69,    70,    71,
      72,    73,    74,    75,    76,   108,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,   111,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,   112,     0,     0,     0,     0,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    68,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,   101,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,   102,
       0,     0,    69,    70,    71,    72,    73,    74,    75,    76,
      69,    70,    71,    72,    73,    74,    75,    76,    70,    71,
      72,    73,    74,    75,    76,    71,    72,    73,    74,    75,
      76
};

static const yytype_int16 yycheck[] =
{
      22,    33,    50,    40,     9,    42,     0,     5,     5,    20,
      21,    33,    35,     8,     4,    10,    35,    54,    55,    30,
      10,    58,     7,    20,    21,    23,    17,    18,    50,    32,
      33,     4,    37,    30,    71,    72,    73,    74,    75,    76,
       3,     6,    79,     6,     7,    77,     5,    32,    33,    86,
       8,    88,    89,    23,    35,    77,    27,    20,    21,    26,
      97,     8,    37,   100,     4,    28,    29,    30,    31,    35,
       4,   103,    35,    14,    15,    16,    17,    18,   126,     4,
       3,   103,     4,     6,     7,   117,   118,    15,    16,    17,
      18,    20,    21,    22,     6,   117,   118,    20,    21,   131,
       3,    30,    34,     6,   126,    28,    29,    30,    31,   131,
       9,     8,    35,     3,     9,     9,     6,    20,    21,    24,
     124,    70,    -1,    26,    -1,    28,    29,    30,    31,     4,
      20,    21,    35,     8,    -1,    -1,     4,     5,    28,    29,
      30,    31,    -1,     4,    19,    35,    -1,    -1,     2,    24,
      25,    19,    -1,    -1,    -1,     9,    24,    25,    19,    34,
      35,    36,    16,    24,    25,    -1,    34,    35,    36,    -1,
      24,     5,    -1,    34,    35,    36,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,     5,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,     5,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,     5,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,     8,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,     8,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      11,    12,    13,    14,    15,    16,    17,    18,    12,    13,
      14,    15,    16,    17,    18,    13,    14,    15,    16,    17,
      18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    64,     0,    20,    21,    22,    30,    40,    41,
      43,    71,    35,    40,    42,    35,     4,    44,     5,    45,
      46,    71,     6,     5,    23,    35,     3,     6,    28,    29,
      31,    35,    47,    48,    49,    55,    61,    68,    71,    45,
       4,     8,    19,    24,    25,    34,    35,    36,    68,    72,
      50,    52,     8,    57,     4,    10,    69,     8,    10,     7,
      49,    27,    26,     8,    35,    72,    72,    37,     8,    11,
      12,    13,    14,    15,    16,    17,    18,    48,    59,     4,
       5,    70,    72,    72,    72,    63,     4,     5,    73,    73,
      72,    72,    72,    72,    72,    72,     7,     4,    72,     5,
      23,     8,     8,    51,    72,    72,    72,    72,     5,    72,
      49,     5,     5,    54,    62,    53,    58,    56,    60,     6,
      49,    49,    32,    33,    65,    66,    67,    34,     9,     7,
      66,    48,     9,    37,     8,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    42,    41,    43,    43,    44,
      44,    45,    45,    46,    47,    48,    48,    50,    49,    49,
      49,    49,    49,    49,    49,    49,    51,    49,    52,    53,
      49,    49,    54,    49,    56,    55,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    69,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     6,     2,     2,     3,
       2,     1,     3,     2,     2,     2,     1,     0,     4,     2,
       4,     4,     2,     2,     3,     1,     0,     5,     0,     0,
       9,     2,     0,    11,     0,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     1,     2,     1,     3,     4,
       2,     2,     3,     2,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     1,     1,
       1,     2,     4,     4,     3,     3,     0
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
#line 107 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfMainUndefined();
	CODE.bpatch((yyvsp[-1]).main_list, getFunction("main").implementation);	
	CODE.printDataBuffer();
	CODE.printCodeBuffer();
}
#line 1426 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "parser.ypp" /* yacc.c:1646  */
    {openScope(); }
#line 1432 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "parser.ypp" /* yacc.c:1646  */
    {
	emit_callee_retvoid();
	closeScope(); 
}
#line 1441 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "parser.ypp" /* yacc.c:1646  */
    {
	string name = (yyvsp[0]).name;
	assertIfDefined(name);
	declareFunction((yyvsp[-1]).type,name); 
	CODE.emit("\n #________________________\n ########## Declaring Function " + name + "##########"); // $$$$$$$$$$$
	emit_callee_begin();
}
#line 1453 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfDefined((yyvsp[0]).name);
	declareFunction(VAR_TYPE_VOID, (yyvsp[0]).name); 
	CODE.emit("\n #________________________\n ########## Declaring Function " + (yyvsp[0]).name + "##########"); // $$$$$$$$$$$
	emit_callee_begin();
}
#line 1464 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 145 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfDefined((yyvsp[0]).name);
	declareArgument((yyvsp[-1]).type,(yyvsp[0]).name);
}
#line 1473 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfDefined((yyvsp[0]).name); 	
	(yyval).type = (yyvsp[-1]).type;
	(yyval).name = (yyvsp[0]).name; 
	emit_stack_new((yyval).name); 
}
#line 1484 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 160 "parser.ypp" /* yacc.c:1646  */
    {
	 (yyval).break_list = CODE.merge((yyvsp[-1]).break_list, (yyvsp[0]).break_list); 
}
#line 1492 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 163 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1498 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 166 "parser.ypp" /* yacc.c:1646  */
    {openScope(); }
#line 1504 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 166 "parser.ypp" /* yacc.c:1646  */
    {
	closeScope(); 
	(yyval) = (yyvsp[-1]); 
}
#line 1513 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "parser.ypp" /* yacc.c:1646  */
    {
	declareVariable((yyvsp[-1]).type,(yyvsp[-1]).name); // emit_stack_new is called inside VarDecl
	CODE.emit("# assign default value:");
	compile_constantNumber(); 
	//puts the register value of last line into the variable in memory
	compile_assign((yyvsp[-1]).name); 
	
}
#line 1526 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "parser.ypp" /* yacc.c:1646  */
    {
	if(!is_assignable((yyvsp[-1]).type, (yyvsp[-3]).type)){
		errorMismatch(yylineno);
		exit(1);
	}
	declareVariable((yyvsp[-3]).type,(yyvsp[-3]).name); // emit_stack_new is called inside VarDecl
	compile_assign((yyvsp[-3]).name, (yyvsp[-1]));
	
}
#line 1540 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 187 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfUndefined((yyvsp[-3]).name);
	if(!is_assignable((yyvsp[-1]).type, getVariableType((yyvsp[-3]).name))){
		errorMismatch(yylineno);
		exit(1);
	}

	compile_assign((yyvsp[-3]).name, (yyvsp[-1]));
}
#line 1554 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).type = (yyvsp[-1]).type;
}
#line 1562 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 199 "parser.ypp" /* yacc.c:1646  */
    {

	if(getReturnType() != VAR_TYPE_VOID){
		errorMismatch(yylineno);
		exit(1);
	 }
	
	emit_callee_retvoid ();		
}
#line 1576 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 208 "parser.ypp" /* yacc.c:1646  */
    {
	if(!is_assignable((yyvsp[-1]).type, getReturnType())){
		   errorMismatch(yylineno
		   );
		   exit(1);
	 }

	
		emit_compute_bool((yyvsp[-1])); // if not bool doing nothing
		emit_callee_retval ();	
}
#line 1592 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 219 "parser.ypp" /* yacc.c:1646  */
    {							
	(yyval) = (yyvsp[0]);	
	CODE.emit("# There is no \"else\"!");
	CODE.bpatch((yyval).false_list, CODE.next());	
}
#line 1602 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 224 "parser.ypp" /* yacc.c:1646  */
    {openScope();}
#line 1608 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "parser.ypp" /* yacc.c:1646  */
    {
	closeScope();
	CODE.bpatch((yyval).false_list, (yyvsp[-2]).label);	
	CODE.bpatch(CODE.makelist((yyvsp[-2]).bufferIndex), CODE.next());
	(yyval).break_list = CODE.merge((yyvsp[-4]).break_list, (yyvsp[0]).break_list);
}
#line 1619 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 231 "parser.ypp" /* yacc.c:1646  */
    {_breakables++; }
#line 1625 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 231 "parser.ypp" /* yacc.c:1646  */
    {assertIfNotBool((yyvsp[-1]).type /* = Exp*/); openScope();}
#line 1631 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 231 "parser.ypp" /* yacc.c:1646  */
    {
	closeScope();
	_breakables--;
	emit_while((yyvsp[-6]).label, (yyvsp[-4]) /* =Exp*/, (yyvsp[-1]).label, (yyvsp[0]) /* =Statement*/);
}
#line 1641 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "parser.ypp" /* yacc.c:1646  */
    {
	my_assert(_breakables >= 0);
	if(_breakables == 0){
		assertUnexpectedBreak();
	}
	(yyval) = comp_break();
}
#line 1653 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 244 "parser.ypp" /* yacc.c:1646  */
    {assertIfNotNumeric( (yyvsp[-1]).type /* = Exp*/); openScope(); _breakables++; }
#line 1659 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "parser.ypp" /* yacc.c:1646  */
    {
	closeScope();
	_breakables --;
	
	emit_switch((yyvsp[-2]) /* = CaseList */, (yyvsp[-4]).bufferIndex /* = SwitchCasesMarker */); 
}
#line 1670 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 252 "parser.ypp" /* yacc.c:1646  */
    {assertIfNotBool((yyvsp[-2]).type); openScope(); }
#line 1676 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 252 "parser.ypp" /* yacc.c:1646  */
    {
	closeScope(); 
	CODE.bpatch((yyvsp[-4]).true_list, (yyvsp[-2]).label); // = Exp, IfStatementMarker
	(yyval) = (yyvsp[0]); // = Statement
	(yyval).false_list = (yyvsp[-4]).false_list; // = Exp
	
}
#line 1688 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "parser.ypp" /* yacc.c:1646  */
    {
	CODE.emit("# Switch :: Expression Evaluation:");
}
#line 1696 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 266 "parser.ypp" /* yacc.c:1646  */
    {
	CODE.emit("# Switch :: Jump to Coparison of expression to cases:");
	reg_ReduceAndGetName(); // Exp not relevant inside the list
	(yyval).bufferIndex = compile_jump();
	CODE.emit("# Switch :: CaseList block:");
}
#line 1707 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 274 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).label = CODE.next(); 
	CODE.emit("# While :: Condition Evaluation:");
}
#line 1716 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 280 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).label = CODE.next(); 
	CODE.emit("# While :: statement:");
}
#line 1725 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 286 "parser.ypp" /* yacc.c:1646  */
    {
	CODE.emit("# If :: Condition Evaluation:");
}
#line 1733 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 291 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).label = CODE.next(); 
	CODE.emit("# If :: statement:");
}
#line 1742 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 297 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).bufferIndex = compile_jump();
	(yyval).label = CODE.next(); 
	CODE.emit("# Else:");
}
#line 1752 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 305 "parser.ypp" /* yacc.c:1646  */
    { 
	(yyval).main_list = emit_main();
	declarePrint();
	emit_print(); 
	declarePrinti();
	emit_printi();
	emit_divError();
}
#line 1765 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-1]);
	(yyval).break_list = CODE.merge((yyval).break_list, (yyvsp[0]).break_list);
	if((yyvsp[0]).default_label == ""){ 						// CaseStatement is of "case" type
		(yyval).case_list.push_back((yyvsp[0]).case_list.back());
	} else {											// CaseStatement is of "default" type
		(yyval).default_label = (yyvsp[0]).default_label;
	}
}
#line 1779 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 325 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1785 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 329 "parser.ypp" /* yacc.c:1646  */
    {
	 (yyval) = (yyvsp[0]);
	 (yyval).case_list = (yyvsp[-1]).case_list;
	 (yyval).default_label = (yyvsp[-1]).default_label;
}
#line 1795 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 335 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1801 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 337 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = comp_case((yyvsp[-1]).num);
}
#line 1809 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 340 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = comp_case((yyvsp[-2]).num, true);
}
#line 1817 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 343 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfDefault();  
	(yyval) = comp_default(); 
}
#line 1826 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 348 "parser.ypp" /* yacc.c:1646  */
    {
	string name = (yyvsp[-1]).name;
	assertFuncUndefined(name); 
	FunctionEntry& func = getFunction(name);
	(yyval).type = func.returnType;
	if( !is_assignable((yyvsp[0]).argTypes, func.argTypes)){
		errorPrototypeMismatch(yylineno, name, func.argTypesNames);
		exit(1);
	}
	
	emit_caller(name); 		
}
#line 1843 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 361 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1849 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 364 "parser.ypp" /* yacc.c:1646  */
    {(yyval).argTypes.push_back((yyvsp[0]).type); emit_compute_bool((yyvsp[0]));}
#line 1855 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 365 "parser.ypp" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-2]); (yyval).argTypes.push_back((yyvsp[0]).type); emit_compute_bool((yyvsp[0]));}
#line 1861 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 367 "parser.ypp" /* yacc.c:1646  */
    {(yyval).type = VAR_TYPE_INT; }
#line 1867 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 368 "parser.ypp" /* yacc.c:1646  */
    {(yyval).type = VAR_TYPE_BYTE; }
#line 1873 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 369 "parser.ypp" /* yacc.c:1646  */
    {(yyval).type = VAR_TYPE_BOOL; }
#line 1879 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 371 "parser.ypp" /* yacc.c:1646  */
    {
	 (yyval) = (yyvsp[-1]);
}
#line 1887 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 374 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	if((yyvsp[-2]).type == VAR_TYPE_INT || (yyvsp[0]).type == VAR_TYPE_INT){
		(yyval).type = VAR_TYPE_INT;
		 compile_plus();		
	}
	else{
		(yyval).type = VAR_TYPE_BYTE;
		 compile_plus(true);		
	}
	
}
#line 1905 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 387 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	
	if((yyvsp[-2]).type == VAR_TYPE_INT || (yyvsp[0]).type == VAR_TYPE_INT){
		(yyval).type = VAR_TYPE_INT;
		 compile_minus();		
	}
	else{
		(yyval).type = VAR_TYPE_BYTE;
		 compile_minus(true);		
	}
}
#line 1923 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 400 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	
	if((yyvsp[-2]).type == VAR_TYPE_INT || (yyvsp[0]).type == VAR_TYPE_INT){
		(yyval).type = VAR_TYPE_INT;
		 compile_mul();		
	}
	else{
		(yyval).type = VAR_TYPE_BYTE;
		 compile_mul(true);		
	}
}
#line 1941 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 413 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	
	if((yyvsp[-2]).type == VAR_TYPE_INT || (yyvsp[0]).type == VAR_TYPE_INT){
		(yyval).type = VAR_TYPE_INT;
		 compile_div();		
	}
	else{
		(yyval).type = VAR_TYPE_BYTE;
		 compile_div(true);		
	}
}
#line 1959 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 426 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfUndefined((yyvsp[0]).name);
	(yyval).type = getVariableType((yyvsp[0]).name);
	compile_read_var((yyvsp[0]).name);	
	
	if((yyval).type == VAR_TYPE_BOOL){
		(yyval) = compile_registerBoolJump();
	}

}
#line 1974 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 436 "parser.ypp" /* yacc.c:1646  */
    {
	emit_caller_retval();
	(yyval).type = (yyvsp[0]).type;
	if((yyval).type == VAR_TYPE_BOOL){
		(yyval) = compile_registerBoolJump();
	}
}
#line 1986 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 443 "parser.ypp" /* yacc.c:1646  */
    { (yyval).type = VAR_TYPE_INT;  compile_constantNumber((yyvsp[0]).num); }
#line 1992 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 444 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfByteTooLarge((yyvsp[-1]).name); // תזכורת: עם כל הגועל שבדבר, ה"שם" של מספר הוא הכתיבה שלו כמחרוזת
	(yyval) = (yyvsp[-1]);
	(yyval).type = VAR_TYPE_BYTE; 
	 compile_constantNumber((yyvsp[-1]).num); 
}
#line 2003 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "parser.ypp" /* yacc.c:1646  */
    { (yyval).type = VAR_TYPE_STRING;  compile_constString((yyvsp[0]).str); }
#line 2009 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 451 "parser.ypp" /* yacc.c:1646  */
    {   (yyval) = compile_constantBoolJump(true); }
#line 2015 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 452 "parser.ypp" /* yacc.c:1646  */
    { (yyval) = compile_constantBoolJump(false); }
#line 2021 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 453 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotBool((yyvsp[0]).type);
	(yyval) = compile_not((yyvsp[0])); 
}
#line 2030 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 457 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotBool((yyvsp[-3]).type);
	assertIfNotBool((yyvsp[0]).type);
	(yyval) = compile_and((yyvsp[-3]), (yyvsp[0]), (yyvsp[-1]).label); 
}
#line 2040 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 462 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotBool((yyvsp[-3]).type);
	assertIfNotBool((yyvsp[0]).type);
	(yyval) = compile_or((yyvsp[-3]),(yyvsp[0]), (yyvsp[-1]).label);
}
#line 2050 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 467 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	(yyval) = compile_relop((yyvsp[-1]).relop);
}
#line 2060 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 472 "parser.ypp" /* yacc.c:1646  */
    {
	assertIfNotNumeric((yyvsp[-2]).type);
	assertIfNotNumeric((yyvsp[0]).type);
	(yyval) = compile_relop((yyvsp[-1]).relop);
}
#line 2070 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 478 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval).label = CODE.next();
}
#line 2078 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2082 "parser.tab.cpp" /* yacc.c:1646  */
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
#line 483 "parser.ypp" /* yacc.c:1906  */
 // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void assertIfMainUndefined() {

	if(getFunctionReturnType("main") == VAR_TYPE_VOID && getFunctionArgsTypes("main").size() == 0){ //covers the case of undefined
		return;
	}
	errorMainMissing();
	exit(1);
}

void assert_unexpected_break() {
	errorUnexpectedBreak(yylineno);
	exit(1);
}

void assertIfDefined(string name) {
	if (isVarExists(name) || (isFunExists(name))) {
		output::errorDef(yylineno, name.c_str());
		exit(1);
	}
}

void assertIfUndefined(string name) {
	if (getVariableType(name) == VAR_TYPE_UNDEFINED) {
		errorUndef(yylineno, name.c_str());
		exit(1);
	}
}


void assertFuncUndefined(string name) { 
	if (getFunctionReturnType(name) == VAR_TYPE_UNDEFINED) {
		errorUndefFunc(yylineno, name.c_str());
		exit(1);
	}
}


void assertIfNotBool(VariableType type) {
	if (type != VAR_TYPE_BOOL) {
		errorMismatch(yylineno);
		exit(1);
	}
}

void assertIfNotNumeric(VariableType type) {
	if (!isNumericType(type)) {
		errorMismatch(yylineno);
		exit(1);
	}
}


void assertIfTypeNotMatch(VariableType type1, VariableType type2) {
	if (type1 == VAR_TYPE_UNDEFINED || type2 == VAR_TYPE_UNDEFINED
		|| ((type1 == VAR_TYPE_BOOL) != (type2 == VAR_TYPE_BOOL))
		|| (isNumericType(type1) != isNumericType(type2))) {

		errorMismatch(yylineno);
		exit(1);
	}
}

bool isNumericType(VariableType type) {
	return type == VAR_TYPE_BYTE
		|| type == VAR_TYPE_INT;
}

void assertUnexpectedBreak(){
	errorUnexpectedBreak(yylineno);
	exit(1);
}

void assertIfByteTooLarge(string value) {
	int i = atoi(value.c_str());
	if (i > MAX_BYTE )
	{
		errorByteTooLarge(yylineno, value);
		exit(1);
	}
}

void assertIfDefault() {
	if (isDefault()){
		output::errorTooManyDefaults(yylineno);
		exit(1);
	}
	else{
		setIsDefault();
	}
}


bool is_assignable(VariableType src, VariableType dst){
	 if(src == dst) 
		 return true;
	 if(src == VAR_TYPE_BYTE && dst == VAR_TYPE_INT) 
		 return true;
	 return false;
}
 
 bool is_assignable(vector<VariableType> srcs, vector<VariableType> dsts){
	 int len = dsts.size();
	 if(srcs.size() != len) 
		 return false;
	 for(int i=0; i<len; i++){
		 if(!is_assignable(srcs[i], dsts[i]))
			 return false;
	 }
	 return true;
 }

 int main()
{
	//yydebug = 1;
	return yyparse();
}


int yyerror(const char * message)
{
	errorSyn(yylineno);
	exit(1);
}
