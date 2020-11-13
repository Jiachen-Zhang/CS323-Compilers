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
#line 1 "syntax.y" /* yacc.c:339  */

    #include"lex.yy.c"
    extern "C"
    {   int yylex(void);    }
    void yyerror(const char *s);
    int line_num = 1;
    AST *root;
    // int yydebug=1;

#line 76 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROE_INT = 258,
    ERROR_FLOAT = 259,
    ERROR_LEXEME = 260,
    INT = 261,
    CHAR = 262,
    FLOAT = 263,
    WHILE = 264,
    IF = 265,
    ELSE = 266,
    ID = 267,
    TYPE = 268,
    DOT = 269,
    COMMA = 270,
    ASSIGN = 271,
    STRUCT = 272,
    SEMI = 273,
    LP = 274,
    RP = 275,
    LC = 276,
    RC = 277,
    LB = 278,
    RB = 279,
    RETURN = 280,
    POUND = 281,
    QUOTE = 282,
    LITERAL = 283,
    INCLUDE = 284,
    PLUS = 285,
    MUL = 286,
    MINUS = 287,
    DIV = 288,
    NOT = 289,
    OR = 290,
    AND = 291,
    NE = 292,
    LT = 293,
    LE = 294,
    GT = 295,
    GE = 296,
    EQ = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define ERROE_INT 258
#define ERROR_FLOAT 259
#define ERROR_LEXEME 260
#define INT 261
#define CHAR 262
#define FLOAT 263
#define WHILE 264
#define IF 265
#define ELSE 266
#define ID 267
#define TYPE 268
#define DOT 269
#define COMMA 270
#define ASSIGN 271
#define STRUCT 272
#define SEMI 273
#define LP 274
#define RP 275
#define LC 276
#define RC 277
#define LB 278
#define RB 279
#define RETURN 280
#define POUND 281
#define QUOTE 282
#define LITERAL 283
#define INCLUDE 284
#define PLUS 285
#define MUL 286
#define MINUS 287
#define DIV 288
#define NOT 289
#define OR 290
#define AND 291
#define NE 292
#define LT 293
#define LE 294
#define GT 295
#define GE 296
#define EQ 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "syntax.y" /* yacc.c:355  */

    class AST *ast_node;

#line 206 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    47,    50,    54,    57,    60,    64,    67,
      72,    75,    79,    82,    87,    90,    94,    97,   100,   103,
     107,   110,   114,   119,   122,   125,   128,   132,   135,   137,
     140,   143,   146,   149,   152,   155,   160,   163,   167,   170,
     174,   177,   181,   184,   190,   193,   194,   197,   200,   203,
     206,   209,   212,   215,   218,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   257,   260,   263,
     266,   269,   272,   274,   277
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROE_INT", "ERROR_FLOAT",
  "ERROR_LEXEME", "INT", "CHAR", "FLOAT", "WHILE", "IF", "ELSE", "ID",
  "TYPE", "DOT", "COMMA", "ASSIGN", "STRUCT", "SEMI", "LP", "RP", "LC",
  "RC", "LB", "RB", "RETURN", "POUND", "QUOTE", "LITERAL", "INCLUDE",
  "PLUS", "MUL", "MINUS", "DIV", "NOT", "OR", "AND", "NE", "LT", "LE",
  "GT", "GE", "EQ", "UMINUS", "$accept", "Program", "ExtDefList", "ExtDef",
  "ExtDecList", "Specifier", "StructSpecifier", "VarDec", "FunDec",
  "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def",
  "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -69

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-69)))

#define YYTABLE_NINF -61

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      40,   -69,    -7,    17,   -69,    40,    10,   -69,    -1,   -69,
     -69,    25,   -69,    34,    -5,    45,    40,     6,   -69,    53,
      63,    40,   -69,    53,    49,    40,   -69,   -69,    53,    23,
      57,   -69,   -69,    54,   391,    47,    50,    73,   -69,   -69,
      66,   -69,   -69,    40,   -69,   -69,   -69,   -69,   -69,    71,
      74,    75,   422,   399,   422,   422,   -69,    37,   391,    44,
     422,   -69,   -69,    53,   -69,   422,   422,   361,   115,    91,
      86,   289,   260,   -69,    94,   -69,   -69,   422,    84,   422,
     -69,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   260,   -69,   144,   173,   -69,   -69,
     202,    41,   -69,   -69,   -69,   -69,   -69,   260,   -69,   260,
     231,   318,   347,   318,   347,   260,   260,   260,   260,   260,
     260,   260,   260,   391,   391,   422,   -69,   -69,   -69,   -69,
      87,   -69,   391,   -69
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,     0,     0,     2,     4,     0,    11,    13,     1,
       3,    14,     6,     0,     8,     0,    37,     0,     5,     0,
       0,    37,     7,     0,     0,    37,    18,    19,     0,     0,
      21,    14,     9,     0,    26,    42,     0,    40,    12,    36,
      22,    16,    17,     0,    15,    72,    69,    71,    70,     0,
       0,    68,     0,     0,     0,     0,    29,    37,    26,     0,
       0,    39,    38,     0,    20,     0,     0,     0,     0,     0,
       0,    59,    61,    23,     0,    25,    28,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,    41,     0,     0,    64,    65,
      74,     0,    58,    30,    31,    32,    24,    45,    67,    44,
       0,    54,    56,    55,    57,    47,    46,    52,    48,    49,
      50,    51,    53,     0,     0,     0,    62,    63,    66,    35,
      33,    73,     0,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -69,   -69,    92,   -69,    80,     4,   -69,   -17,   -69,    58,
     -69,    88,    48,   -68,    -9,   -69,    42,   -69,   -52,   -18
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    29,
      30,    56,    57,    58,    24,    25,    36,    37,    59,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    70,    71,    72,     6,     8,    35,    26,    94,     6,
      19,    40,    34,    96,    97,   100,    39,     9,    20,     1,
      16,    28,    11,     2,    41,   107,    27,   109,    12,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   126,    42,    17,    76,    35,    28,    74,    77,
       1,    61,    18,     1,     2,   129,   130,     2,    78,    73,
      79,   127,    80,    60,   133,    31,    21,    81,    62,    33,
      20,    38,    43,   100,    82,    83,    84,    85,    44,    86,
      87,    88,    89,    90,    91,    92,    93,   104,    63,    20,
      65,    77,   103,    66,    67,   106,   108,    10,   132,    32,
      78,    64,    79,    22,   105,    95,    75,   131,     0,    81,
       0,     0,     0,     0,     0,     0,    82,    83,    84,    85,
      77,    86,    87,    88,    89,    90,    91,    92,    93,    78,
       0,    79,     0,     0,     0,   102,     0,     0,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    77,
      86,    87,    88,    89,    90,    91,    92,    93,    78,     0,
      79,     0,     0,     0,   123,     0,     0,    81,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    77,    86,
      87,    88,    89,    90,    91,    92,    93,    78,     0,    79,
       0,     0,     0,   124,     0,     0,    81,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    77,    86,    87,
      88,    89,    90,    91,    92,    93,    78,   125,    79,     0,
       0,     0,     0,     0,     0,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    77,    86,    87,    88,
      89,    90,    91,    92,    93,    78,     0,    79,     0,     0,
       0,     0,     0,     0,    81,   128,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    77,    86,    87,    88,    89,
      90,    91,    92,    93,    78,     0,    79,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    77,    86,    87,    88,    89,    90,
      91,    92,    93,    78,     0,    79,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
     -60,     0,   -60,    77,    86,    87,    88,    89,    90,    91,
      92,    93,    78,     0,    79,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    85,    77,    86,    87,    88,    89,    90,    91,    92,
      93,    78,    98,    79,     0,     0,    45,    46,    47,    48,
      81,     0,     0,    51,     0,     0,     0,     0,     0,     0,
      52,    99,    86,    87,    88,    89,    90,    91,    92,    93,
       0,     0,     0,    54,     0,    55,    45,    46,    47,    48,
      49,    50,     0,    51,    45,    46,    47,    48,     0,     0,
      52,    51,    21,     0,     0,     0,    53,    69,    52,     0,
       0,     0,     0,    54,     0,    55,     0,    45,    46,    47,
      48,    54,     0,    55,    51,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     0,    55
};

static const yytype_int16 yycheck[] =
{
      52,    53,    54,    55,     0,    12,    23,     1,    60,     5,
      15,    28,    21,    65,    66,    67,    25,     0,    23,    13,
      21,    17,    12,    17,     1,    77,    20,    79,    18,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     1,    20,    19,     1,    63,    43,    57,     5,
      13,     1,    18,    13,    17,   123,   124,    17,    14,    22,
      16,    20,    18,    16,   132,    12,    21,    23,    18,     6,
      23,    22,    15,   125,    30,    31,    32,    33,    24,    35,
      36,    37,    38,    39,    40,    41,    42,     1,    15,    23,
      19,     5,     1,    19,    19,     1,    12,     5,    11,    19,
      14,    43,    16,    15,    18,    63,    58,   125,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
       5,    35,    36,    37,    38,    39,    40,    41,    42,    14,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,     5,
      35,    36,    37,    38,    39,    40,    41,    42,    14,    -1,
      16,    -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,     5,    35,
      36,    37,    38,    39,    40,    41,    42,    14,    -1,    16,
      -1,    -1,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,     5,    35,    36,
      37,    38,    39,    40,    41,    42,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,     5,    35,    36,    37,
      38,    39,    40,    41,    42,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,     5,    35,    36,    37,    38,
      39,    40,    41,    42,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,     5,    35,    36,    37,    38,    39,
      40,    41,    42,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,     5,    35,    36,    37,    38,    39,    40,
      41,    42,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    33,     5,    35,    36,    37,    38,    39,    40,    41,
      42,    14,     1,    16,    -1,    -1,     5,     6,     7,     8,
      23,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    32,    -1,    34,     5,     6,     7,     8,
       9,    10,    -1,    12,     5,     6,     7,     8,    -1,    -1,
      19,    12,    21,    -1,    -1,    -1,    25,    18,    19,    -1,
      -1,    -1,    -1,    32,    -1,    34,    -1,     5,     6,     7,
       8,    32,    -1,    34,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    17,    45,    46,    47,    49,    50,    12,     0,
      46,    12,    18,    48,    51,    52,    21,    19,    18,    15,
      23,    21,    55,    49,    58,    59,     1,    20,    49,    53,
      54,    12,    48,     6,    58,    51,    60,    61,    22,    58,
      51,     1,    20,    15,    24,     5,     6,     7,     8,     9,
      10,    12,    19,    25,    32,    34,    55,    56,    57,    62,
      16,     1,    18,    15,    53,    19,    19,    19,    62,    18,
      62,    62,    62,    22,    58,    56,     1,     5,    14,    16,
      18,    23,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    42,    62,    60,    62,    62,     1,    20,
      62,    63,    20,     1,     1,    18,     1,    62,    12,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    20,    20,    15,     1,    20,    24,    57,
      57,    63,    11,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     1,     4,     4,     4,     3,     3,
       3,     1,     2,     4,     5,     2,     0,     2,     2,     1,
       3,     3,     3,     5,     7,     5,     2,     0,     3,     3,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     4,     4,     3,     3,     4,     3,     1,     1,
       1,     1,     1,     3,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 43 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Program"); 
    root = new AST("Program", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node)); 
}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDefList-1");
    (yyval.ast_node) = new AST("ExtDefList", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDefList-2");
    (yyval.ast_node) = new AST("ExtDefList", SymbolType::NONTERMINAL, NULL, yylineno, 0);
}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDef-1");
    (yyval.ast_node) = new AST("ExtDef", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 57 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDef-2"); 
    (yyval.ast_node) = new AST("ExtDef", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 60 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDef-3");
    (yyval.ast_node) = new AST("ExtDef", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDecList"); 
    (yyval.ast_node) = new AST("ExtDecList", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 67 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ExtDecList");
    (yyval.ast_node) = new AST("ExtDecList", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Specifier");
    (yyval.ast_node) = new AST("Specifier", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Specifier");
    (yyval.ast_node) = new AST("Specifier", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 79 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("StructSpecifier"); 
    (yyval.ast_node) = new AST("StructSpecifier", SymbolType::NONTERMINAL, NULL, (yylsp[-4]).first_line, 5, (yyvsp[-4].ast_node), (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 82 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("StructSpecifier"); 
    (yyval.ast_node) = new AST("StructSpecifier", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("ID"); 
    (yyval.ast_node) = new AST("VarDec", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ID"); 
    (yyval.ast_node) = new AST("VarDec", SymbolType::NONTERMINAL, NULL, (yylsp[-3]).first_line, 4, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("FunDec");
    ERROR_TYPE_B((yylsp[-3]).last_line, "Missing closing parenthesis ')'");
}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 97 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("FunDec");
    (yyval.ast_node) = new AST("FunDec", SymbolType::NONTERMINAL, NULL, (yylsp[-3]).first_line, 4, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 100 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("FunDec");
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing closing parenthesis ')'");
}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 103 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("FunDec");
    (yyval.ast_node) = new AST("FunDec", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 107 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("VarList");
    (yyval.ast_node) = new AST("VarList", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 110 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("VarList"); 
    (yyval.ast_node) = new AST("VarList", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 114 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("ParamDec");
    (yyval.ast_node) = new AST("ParamDec", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("CompSt"); 
    (yyval.ast_node) = new AST("CompSt", SymbolType::NONTERMINAL, NULL, (yylsp[-3]).first_line, 4, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 122 "syntax.y" /* yacc.c:1646  */
    {
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing specifier");
}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("StmtList"); 
    (yyval.ast_node) = new AST("StmtList", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("StmtList"); 
    (yyval.ast_node) = new AST("StmtList", SymbolType::NONTERMINAL, NULL, yylineno, 0); 
}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 132 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt");
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "syntax.y" /* yacc.c:1646  */
    {
    ERROR_TYPE_B((yylsp[-1]).last_line, "Missing semicolon ';'");
}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 137 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt");
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 140 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt"); 
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing expression");
}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 143 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt"); 
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing semicolon ';'");
}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 146 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt"); 
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 149 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt");
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[-4]).first_line, 5, (yyvsp[-4].ast_node), (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 152 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt");
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[-6]).first_line, 7, (yyvsp[-6].ast_node), (yyvsp[-5].ast_node), (yyvsp[-4].ast_node), (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 155 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Stmt");
    (yyval.ast_node) = new AST("Stmt", SymbolType::NONTERMINAL, NULL, (yylsp[-4]).first_line, 5, (yyvsp[-4].ast_node), (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 160 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("DefList");
    (yyval.ast_node) = new AST("DefList", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("DefList");
    (yyval.ast_node) = new AST("DefList", SymbolType::NONTERMINAL, NULL, yylineno, 0);
}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 167 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Def");
    (yyval.ast_node) = new AST("Def", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 170 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Def");
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing semicolon ';'");
}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 174 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("DecList");
    (yyval.ast_node) = new AST("DecList", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 177 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("DecList");
    (yyval.ast_node) = new AST("DecList", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 181 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Dec");
    (yyval.ast_node) = new AST("Dec", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 184 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Dec");
    (yyval.ast_node) = new AST("Dec", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 194 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 197 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 200 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 206 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 209 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 212 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 215 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 218 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 221 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 224 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 227 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 230 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 233 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 236 "syntax.y" /* yacc.c:1646  */
    { 
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node)); 
}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-1]).first_line, 2, (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 242 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    ERROR_TYPE_B((yylsp[-3]).last_line, "Missing closing parenthesis ')'");
}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 245 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-3]).first_line, 4, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 248 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    ERROR_TYPE_B((yylsp[-2]).last_line, "Missing closing parenthesis ')'");
}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 251 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 254 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-3]).first_line, 4, (yyvsp[-3].ast_node), (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 257 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 260 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 263 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 266 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 269 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Exp");
    (yyval.ast_node) = new AST("Exp", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 272 "syntax.y" /* yacc.c:1646  */
    {
}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 274 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Args");
    (yyval.ast_node) = new AST("Args", SymbolType::NONTERMINAL, NULL, (yylsp[-2]).first_line, 3, (yyvsp[-2].ast_node), (yyvsp[-1].ast_node), (yyvsp[0].ast_node));
}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 277 "syntax.y" /* yacc.c:1646  */
    {
    DISPLAY_SYNTAX("Args");
    (yyval.ast_node) = new AST("Args", SymbolType::NONTERMINAL, NULL, (yylsp[0]).first_line, 1, (yyvsp[0].ast_node));
}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2206 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 282 "syntax.y" /* yacc.c:1906  */

void init() {
    root = NULL;
}

void yyerror(const char *s) {
  SYNTAX_ERROR();
}
int main(int argc, char **argv) {
    char *file_path;
    if ( argc < 2 ) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAIL;
    } else if( argc > 2 ){
        fprintf(stderr, "Too much arguments!\n");
        return EXIT_FAIL;
    }
    file_path = argv[1];
    if(!(yyin = fopen(file_path, "r"))){
        perror(argv[1]);
        return EXIT_FAIL;
    }
    init();
    yyparse();
    if (!syntax_error) {
        assert(root != NULL);
        root->print(0);
    }
    return EXIT_OK;
}
