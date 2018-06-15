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

	using namespace std;
	using namespace output;

	/*	external data:			*/
	extern int yylex();
	extern int yylineno;
	void yyerror(const char*);
	
	/*	global data:			*/
	SymbolsTable symbolsTable; 	/* symbols data is stored here 	*/
	int numOfWhileContaining = 0;	/* field for when a break occures	*/
	bool isMainExist = false;
	TypeInfo funcReturnDataType; //this holds the current expected return type of a function
	string currentFuncId;
	
	/*	local functions:		*/
	TokenClass* logicalOpAction(TokenClass* exp1, TokenClass* exp2);
	TokenClass* relOpAction(TokenClass* exp1, TokenClass* exp2);
	TokenClass* binOpAction(TokenClass* exp1, TokenClass* exp2);
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

#line 105 "parser.tab.cpp" /* yacc.c:339  */

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

#line 196 "parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

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
       0,    84,    84,    87,    88,    91,    94,    98,    91,   116,
     120,   125,   129,   134,   141,   156,   172,   202,   241,   242,
     245,   246,   255,   286,   309,   340,   383,   423,   424,   431,
     463,   464,   464,   468,   475,   482,   483,   485,   486,   490,
     497,   522,   537,   545,   561,   565,   569,   575,   579,   615,
     621,   627,   633,   639,   650,   654,   659,   671,   676,   680,
     684,   689,   695,   701,   707,   713,   719,   725,   731
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
  "LBRACK", "RBRACK", "LBRACE", "RBRACE", "$accept", "Program", "Funcs",
  "FuncDecl", "$@1", "$@2", "$@3", "RetType", "Formals", "FormalsList",
  "FormalDecl", "Statements", "Statement", "$@4", "ExpBoolValid",
  "OptionalElse", "ScopedStatment", "NewScope", "EndScope", "Call",
  "ExpList", "Type", "Exp", YY_NULLPTR
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

#define YYPACT_NINF -87

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-87)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     102,   -87,   -87,   -87,   -87,     5,   -87,   102,   -87,   -87,
     -87,   -87,   -87,   -10,   -87,   -18,    71,   -87,   -87,    -2,
      13,    -7,    71,    16,    19,   -87,    37,    87,     0,    59,
      26,    43,    32,   -16,   -87,    51,   -87,    55,    58,    48,
     -87,   301,   -87,   -87,   -87,    17,    80,   -87,   301,   -87,
     169,   301,   -87,   301,   301,   297,   301,    87,   -87,   -87,
     -87,    -5,   -87,   322,   301,   -87,   129,   301,   301,   -87,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     -87,   141,   -87,   195,   -87,    52,   221,    89,    87,   -87,
     -87,   301,    66,   103,   -87,   312,   322,   332,   206,   115,
     152,   177,   159,   -11,   -11,   -87,   -87,    81,    87,   -87,
     -87,   -87,   -87,   301,    79,    63,   247,     3,   -87,   -87,
     -87,   -87,   -87,   -87,   301,   -87,   -87,    73,   105,   -87,
     -87,   273,   106,   -87,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    10,    44,    45,    46,     0,     2,     3,     5,     9,
       1,     4,    38,     0,     6,     0,    11,     7,    12,    13,
       0,     0,     0,    15,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,    18,     0,     0,     0,
      16,     0,    58,    59,    28,    53,    55,    57,     0,    54,
       0,     0,    33,     0,     0,     0,     0,     0,    39,    19,
      27,     0,    17,    60,     0,    56,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    31,     0,    41,     0,    42,     0,    39,     8,
      21,     0,     0,     0,    47,    61,    62,    63,    64,    65,
      66,    67,    68,    49,    50,    51,    52,    35,     0,    34,
      38,    25,    40,     0,     0,     0,     0,     0,    48,    38,
      30,    39,    32,    43,     0,    20,    22,     0,     0,    36,
      37,     0,     0,    23,    26,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   132,   -87,   -87,   -87,   -87,   -87,   -87,   130,
     -87,    94,   -34,   -87,   110,   -87,   -86,    -4,   -85,   -25,
      62,     7,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    12,    15,    21,     8,    17,    18,
      19,    35,    36,   110,    80,   120,   107,   108,    89,    49,
      85,    38,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    59,    37,   115,    54,    10,    39,     9,    13,   127,
      37,    14,    63,    90,     9,    91,    16,    22,    55,    66,
      56,    78,    79,    20,   122,    83,    86,    87,    24,    20,
      57,    92,    37,   129,    23,    93,   130,    40,    95,    96,
     128,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    55,    26,    64,    59,     2,     3,    27,     4,    28,
      51,    52,   116,    37,    29,    30,    53,    31,    32,    41,
      42,    43,    33,    60,   121,     2,     3,    44,     4,    61,
      45,    46,    47,    37,    86,    62,    65,   112,   117,    34,
      58,     2,     3,    48,     4,   131,   119,    67,    68,   124,
      29,    30,   125,    31,    32,     1,     2,     3,    33,     4,
     132,    67,    68,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,   133,   135,    34,   114,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    67,    68,    11,
     118,    -1,    73,    74,    75,    76,    77,    78,    79,    67,
      68,    88,    25,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    82,    94,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   123,   109,    67,    68,    -1,
      74,    75,    76,    77,    78,    79,     0,    69,    -1,    76,
      77,    78,    79,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    67,    68,    -1,    75,    76,    77,    78,
      79,     0,     0,   111,     0,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    67,
      68,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
     113,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    41,    42,    43,
       0,    41,    42,    43,     0,     0,     0,     0,    45,    46,
      47,    68,    45,    46,    47,     0,     0,     0,     0,     0,
       0,    48,    84,     0,     0,    48,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79
};

static const yytype_int8 yycheck[] =
{
      29,    35,    27,    88,    20,     0,     6,     0,    12,     6,
      35,    21,    41,    18,     7,    20,    34,    19,    34,    48,
      36,    32,    33,    16,   110,    54,    55,    56,    35,    22,
      34,    36,    57,   119,    21,    64,   121,    37,    67,    68,
      37,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    34,    36,    36,    88,     4,     5,    38,     7,    22,
      34,    18,    91,    88,    13,    14,    34,    16,    17,    10,
      11,    12,    21,    18,   108,     4,     5,    18,     7,    21,
      21,    22,    23,   108,   113,    37,     6,    35,    22,    38,
      39,     4,     5,    34,     7,   124,    15,     8,     9,    20,
      13,    14,    39,    16,    17,     3,     4,     5,    21,     7,
      37,     8,     9,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    18,    18,    38,    37,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     8,     9,     7,
      37,    26,    27,    28,    29,    30,    31,    32,    33,     8,
       9,    57,    22,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    53,    35,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   113,    35,     8,     9,    27,
      28,    29,    30,    31,    32,    33,    -1,    18,    29,    30,
      31,    32,    33,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     8,     9,    28,    29,    30,    31,    32,
      33,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     8,
       9,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    10,    11,    12,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    21,    22,
      23,     9,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    34,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    41,    42,    43,    47,    61,
       0,    42,    44,    57,    21,    45,    34,    48,    49,    50,
      61,    46,    19,    21,    35,    49,    36,    38,    22,    13,
      14,    16,    17,    21,    38,    51,    52,    59,    61,     6,
      37,    10,    11,    12,    18,    21,    22,    23,    34,    59,
      62,    34,    18,    34,    20,    34,    36,    57,    39,    52,
      18,    21,    37,    62,    36,     6,    62,     8,     9,    18,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      54,    62,    54,    62,    35,    60,    62,    62,    51,    58,
      18,    20,    36,    62,    35,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    56,    57,    35,
      53,    18,    35,    19,    37,    58,    62,    22,    37,    15,
      55,    52,    56,    60,    20,    39,    18,     6,    37,    56,
      58,    62,    37,    18,    18,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    44,    45,    46,    43,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    53,    52,    52,    54,    55,    55,    56,    57,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,     0,     0,    13,     1,
       1,     0,     1,     1,     3,     2,     5,     6,     1,     2,
       5,     3,     5,     6,     7,     4,     7,     2,     2,     3,
       5,     0,     5,     2,     2,     0,     2,     3,     0,     0,
       4,     3,     1,     3,     1,     1,     1,     3,     4,     3,
       3,     3,     3,     1,     1,     1,     2,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3
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
#line 84 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1409 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1415 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1421 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "parser.ypp" /* yacc.c:1646  */
    {
				funcReturnDataType = (dynamic_cast<TokenClass*>((yyvsp[0])))->typeInfo;
			}
#line 1429 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "parser.ypp" /* yacc.c:1646  */
    {
				currentFuncId = (dynamic_cast<String*>((yyvsp[0])))->getString();
				verifyIdNotInSymbols(currentFuncId);
			}
#line 1438 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 98 "parser.ypp" /* yacc.c:1646  */
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
			}
#line 1455 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 110 "parser.ypp" /* yacc.c:1646  */
    {
	//3. change funcReturnDataType to DATA_INVALID.
	funcReturnDataType.type = DATA_INVALID; 
}
#line 1464 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 116 "parser.ypp" /* yacc.c:1646  */
    { 
	(yyval) = (yyvsp[0]);
}
#line 1472 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 120 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_VOID));
}
#line 1480 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass();
}
#line 1488 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 129 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 1496 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();
	retToken->argList.push_back((dynamic_cast<TokenClass*>((yyvsp[0])))->typeInfo);
	(yyval) = retToken;
	delete (yyvsp[0]);
}
#line 1507 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.ypp" /* yacc.c:1646  */
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
#line 1525 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 156 "parser.ypp" /* yacc.c:1646  */
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
	(yyval) = new TokenClass(TypeInfo(token->typeInfo));
	delete (yyvsp[-1]);
	delete (yyvsp[0]);
}
#line 1545 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 172 "parser.ypp" /* yacc.c:1646  */
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
	(yyval) = new TokenClass(typeInfo);
	delete (yyvsp[-4]);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
}
#line 1579 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "parser.ypp" /* yacc.c:1646  */
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
	(yyval) = new TokenClass(typeInfo);
	delete (yyvsp[-5]);
	delete (yyvsp[-4]);
	delete (yyvsp[-2]);
}
#line 1621 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 241 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1627 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 242 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1633 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 245 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1639 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 246 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-1])))->getString();
	//1. check id doesnt exist.
	verifyIdNotInSymbols(s);
	//2. insert to symbol table (manage offset and all this shit).
	TokenClass* token = dynamic_cast<TokenClass*>((yyvsp[-2]));
	symbolsTable.addSymbol(s,TypeInfo(token->typeInfo.type));
}
#line 1652 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 255 "parser.ypp" /* yacc.c:1646  */
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
	symbolsTable.addSymbol(s,TypeInfo(token1->typeInfo.type));
	delete (yyvsp[-4]);
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
}
#line 1687 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 286 "parser.ypp" /* yacc.c:1646  */
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
	delete (yyvsp[-5]);
	delete (yyvsp[-4]);
	delete (yyvsp[-2]);
}
#line 1714 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 309 "parser.ypp" /* yacc.c:1646  */
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
	delete (yyvsp[-6]);
	delete (yyvsp[-5]);
	delete (yyvsp[-3]);
}
#line 1749 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 340 "parser.ypp" /* yacc.c:1646  */
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
		case DATA_ARR_STRING:
			if(token3->typeInfo != typeInfo){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
}
#line 1796 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 383 "parser.ypp" /* yacc.c:1646  */
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
		case DATA_ARR_STRING:
			if(token6->typeInfo.type != DATA_STRING){
				errorMismatch(yylineno);
				exit(1);
			}
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	delete (yyvsp[-6]);
	delete (yyvsp[-4]);
	delete (yyvsp[-1]);
}
#line 1840 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 423 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1846 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 424 "parser.ypp" /* yacc.c:1646  */
    {
	if(funcReturnDataType.type != DATA_VOID){
		errorMismatch(yylineno);
		exit(1);
	}
}
#line 1857 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 431 "parser.ypp" /* yacc.c:1646  */
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
	delete (yyvsp[-1]);
}
#line 1893 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 463 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1899 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 464 "parser.ypp" /* yacc.c:1646  */
    {++numOfWhileContaining;}
#line 1905 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 464 "parser.ypp" /* yacc.c:1646  */
    {	
	--numOfWhileContaining;
}
#line 1913 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 468 "parser.ypp" /* yacc.c:1646  */
    {
	if(numOfWhileContaining == 0){
		errorUnexpectedBreak(yylineno);
		exit(1);
	}
}
#line 1924 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 475 "parser.ypp" /* yacc.c:1646  */
    { 
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	verifyBool(token1);
	(yyval) = token1;
}
#line 1934 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 482 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1940 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 483 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1946 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 485 "parser.ypp" /* yacc.c:1646  */
    {}
#line 1952 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 486 "parser.ypp" /* yacc.c:1646  */
    {
	symbolsTable.addScope();
}
#line 1960 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 490 "parser.ypp" /* yacc.c:1646  */
    {
	endScope();
	printScopeSymbols();
	symbolsTable.removeScope();
}
#line 1970 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 497 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[-3])))->getString();
	verifyFunctionPresent(s);
	Func f = getFuncFromTable(s);
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[-1]));
	vector<string> tmpArgVec;
	convertTypeInfoVecToStringVec(f.argsTypes, tmpArgVec);

	if(f.argsTypes.size() != token3->argList.size()){
		errorPrototypeMismatch(yylineno, s, tmpArgVec);
		exit(1);
	}
	for(int i=0 ; i < f.argsTypes.size() ; ++i){
		if(f.argsTypes[i] != token3->argList[i]){
			if(f.argsTypes[i].type != DATA_INT || token3->argList[i].type != DATA_BYTE){
				errorPrototypeMismatch(yylineno, s, tmpArgVec);
				exit(1);
			}
		}
	}
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	(yyval) = new TokenClass(f.funcRetVal);
}
#line 1999 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 522 "parser.ypp" /* yacc.c:1646  */
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
	delete (yyvsp[-2]);
	(yyval) = new TokenClass(f.funcRetVal);
}
#line 2017 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 537 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[0]));
	retToken->argList.push_back(token1->typeInfo);
	(yyval) = retToken;
	delete (yyvsp[0]);
}
#line 2029 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 545 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* retToken = new TokenClass();
	//1. add the first exp type to the list.
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	retToken->argList.push_back(token1->typeInfo);
	//2. add the rest of the exp to the vector.
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	for (vector<TypeInfo>::iterator it = token3->argList.begin(); it != token3->argList.end(); ++it) {
		retToken->argList.push_back(*it);
   	}
	delete (yyvsp[-2]);
	delete (yyvsp[0]);
	(yyval) = retToken;
}
#line 2048 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 561 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_INT)); 
}
#line 2056 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 565 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BYTE)); 
}
#line 2064 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 569 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BOOL)); 
}
#line 2072 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 575 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[-1]);
}
#line 2080 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 579 "parser.ypp" /* yacc.c:1646  */
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
		case DATA_ARR_STRING:
			retExp = new TokenClass(TypeInfo(DATA_STRING));
			break;
		default:
			errorMismatch(yylineno);
			exit(1);
	}
	delete (yyvsp[-3]);
	delete (yyvsp[-1]);
	(yyval) = retExp;
}
#line 2120 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 615 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = binOpAction(token1,token3);
}
#line 2130 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 621 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = binOpAction(token1,token3);
}
#line 2140 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 627 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = binOpAction(token1,token3);
}
#line 2150 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 633 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = binOpAction(token1,token3);
}
#line 2160 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 639 "parser.ypp" /* yacc.c:1646  */
    {
	string s = (dynamic_cast<String*>((yyvsp[0])))->getString();
	//1. check if id exists, exit if not.
	verifyIdInSymbols(s);
	//2. get its type from symbol table.
	TypeInfo type = symbolsTable.getIdTypeInfo(s);
	//3. make token out of type and return it.
	(yyval) = new TokenClass(type);
	delete (yyvsp[0]);
}
#line 2175 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 650 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = (yyvsp[0]);
}
#line 2183 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 654 "parser.ypp" /* yacc.c:1646  */
    {
	delete (yyvsp[0]);
	(yyval) = new TokenClass(TypeInfo(DATA_INT));
}
#line 2192 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 659 "parser.ypp" /* yacc.c:1646  */
    {
	Num* inpNum = dynamic_cast<Num*>((yyvsp[-1]));
	int num = inpNum->getNum();
	if( num < 0 || num > 255){
		errorByteTooLarge(yylineno,inpNum->getStr());
		delete (yyvsp[-1]);
		exit(1);
	}
	delete (yyvsp[-1]);
	(yyval) = new TokenClass(TypeInfo(DATA_BYTE));
}
#line 2208 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 671 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_STRING));
	delete (yyvsp[0]);
}
#line 2217 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 676 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BOOL));
}
#line 2225 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 680 "parser.ypp" /* yacc.c:1646  */
    {
	(yyval) = new TokenClass(TypeInfo(DATA_BOOL));
}
#line 2233 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 684 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token2 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = logicalOpAction(token2,token2);
}
#line 2242 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 689 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = logicalOpAction(token1,token3);
}
#line 2252 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 695 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = logicalOpAction(token1,token3);
}
#line 2262 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 701 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2272 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 707 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2282 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 713 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2292 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 719 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2302 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 725 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2312 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 731 "parser.ypp" /* yacc.c:1646  */
    {
	TokenClass* token1 = dynamic_cast<TokenClass*>((yyvsp[-2]));
	TokenClass* token3 = dynamic_cast<TokenClass*>((yyvsp[0]));
	(yyval) = relOpAction(token1,token3);
}
#line 2322 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2326 "parser.tab.cpp" /* yacc.c:1646  */
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
#line 737 "parser.ypp" /* yacc.c:1906  */

/*========================================
	section 3	-	c user routines
========================================*/

TokenClass* logicalOpAction(TokenClass* exp1, TokenClass* exp2){
	verifyBool(exp1,exp2);
	if(exp1 != exp2){
		delete exp2;
	}
	delete exp1;
	return new TokenClass(TypeInfo(DATA_BOOL));
}

TokenClass* relOpAction(TokenClass* exp1, TokenClass* exp2){
	verifyNumber(exp1, exp2);
	if(exp1 != exp2){
		delete exp2;
	}
	delete exp1;
	return new TokenClass(TypeInfo(DATA_BOOL));
}

TokenClass* binOpAction(TokenClass* exp1, TokenClass* exp2){
	verifyNumber(exp1, exp2);
	TypeInfo retType(DATA_INT);
	if(exp1->typeInfo.type == DATA_BYTE && exp2->typeInfo.type == DATA_BYTE){
		retType.type = DATA_BYTE;
	}
	if(exp1 != exp2){
		delete exp2;
	}
	delete exp1;
	return new TokenClass(retType);
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
	vector<Func> funcsVec = symbolsTable.getFuncs();
	vector<string> argNameVec;
	for (vector<Func>::iterator it = funcsVec.begin(); it != funcsVec.end(); ++it) {
		convertTypeInfoVecToStringVec(it->argsTypes ,argNameVec);
		cout << it->id << " " << makeFunctionType(it->funcRetVal.getAsString(), argNameVec) << " 0" << endl;
		argNameVec.clear();
	}
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
	
	return 0;
}
