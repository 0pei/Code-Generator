/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "compiler_hw3.y"

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    int ind = 0, addr = 0, sco = 0, declare = 0, load = 0, assign = 1;
    int boolNum = 0, cmpNum = 0, ifNum = 0, forNum = 0;
    char c;

    typedef struct NODE {
        char *name;
        char *type;
        int address;
        int lineno;
        char *elementType;
        struct NODE *next;
    } node;
    node *sym_ta[15] = { NULL };

    typedef struct NODE2 {
        int num;
        struct NODE2 *next;
    } node2;
    node2 *if_stack = NULL, *for_stack = NULL;

    /* Symbol table function - you can add new function if needed. */
    static void create()    { sco++; };
    static void insert(char *name, char *type, char *elementType, int vau);
    static node* lookup(char *name);
    static void dump(/* ... */);
    static void check_error(char *s1, char *s2, char*s3);
    static int is_lit(char *s);
    static char get_type0(char *s);
    static void store(char *s);
    static node2* push(node2 *init, int n);
    static node2* pop(node2 *init);

#line 130 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    SEMICOLON = 262,
    TRUE = 263,
    FALSE = 264,
    OR = 265,
    AND = 266,
    EQL = 267,
    NEQ = 268,
    LEQ = 269,
    GEQ = 270,
    INC = 271,
    DEC = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    MUL_ASSIGN = 275,
    QUO_ASSIGN = 276,
    REM_ASSIGN = 277,
    PRINT = 278,
    RETURN = 279,
    IF = 280,
    ELSE = 281,
    FOR = 282,
    WHILE = 283,
    CONTINUE = 284,
    BREAK = 285,
    VOID = 286,
    INT_LIT = 287,
    FLOAT_LIT = 288,
    STRING_LIT = 289,
    IDENT = 290
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define SEMICOLON 262
#define TRUE 263
#define FALSE 264
#define OR 265
#define AND 266
#define EQL 267
#define NEQ 268
#define LEQ 269
#define GEQ 270
#define INC 271
#define DEC 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define QUO_ASSIGN 276
#define REM_ASSIGN 277
#define PRINT 278
#define RETURN 279
#define IF 280
#define ELSE 281
#define FOR 282
#define WHILE 283
#define CONTINUE 284
#define BREAK 285
#define VOID 286
#define INT_LIT 287
#define FLOAT_LIT 288
#define STRING_LIT 289
#define IDENT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 67 "compiler_hw3.y"

    int i_val;
    float f_val;
    char *s_val;

#line 258 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  56
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    51,     2,     2,    36,     2,     2,
      40,    41,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    47,    48,    49,
      50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    97,    97,   101,   102,   103,   104,   108,   109,   113,
     114,   118,   133,   137,   138,   142,   143,   147,   148,   160,
     161,   162,   163,   164,   165,   169,   170,   174,   175,   176,
     180,   181,   182,   186,   187,   188,   192,   193,   208,   212,
     213,   214,   215,   219,   220,   224,   233,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   250,   251,   252,
     259,   259,   274,   278,   279,   280,   281,   282,   283,   287,
     293,   302,   306,   306,   310,   311,   315,   315,   323,   330,
     330,   337,   341,   348,   363,   363,   371,   371,   377,   385,
     389,   385,   404,   405,   409,   410,   411,   415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING",
  "SEMICOLON", "TRUE", "FALSE", "OR", "AND", "EQL", "NEQ", "LEQ", "GEQ",
  "INC", "DEC", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN",
  "REM_ASSIGN", "PRINT", "RETURN", "IF", "ELSE", "FOR", "WHILE",
  "CONTINUE", "BREAK", "VOID", "'+'", "'-'", "'*'", "'/'", "'%'", "'>'",
  "'<'", "'='", "'('", "')'", "'['", "']'", "'{'", "'}'", "'!'", "INT_LIT",
  "FLOAT_LIT", "STRING_LIT", "IDENT", "'\"'", "$accept", "Program",
  "TypeName", "Expression", "Expression1", "Expression2", "Expression3",
  "Expression4", "UnaryExpr", "cmp_op", "add_op", "mul_op", "unary_op",
  "PrimaryExpr", "Operand", "Literal", "BOOL_LIT", "IndexExpr",
  "ConversionExpr", "Statement", "DeclarationStmt", "AssignmentExpr",
  "$@1", "AssignmentStmt", "assign_op", "IncDecExpr", "IncDecStmt",
  "Block", "$@2", "StatementList", "IfStmt", "$@3", "IfStmt2", "$@4",
  "IfStmt3", "Condition", "WhileStmt", "$@5", "WhileStmt2", "$@6",
  "WhileStmt3", "ForStmt", "$@7", "$@8", "ForStmt2", "SimpleExpr",
  "PrintStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    45,    42,    47,    37,    62,    60,    61,
      40,    41,    91,    93,   123,   125,    33,   287,   288,   289,
     290,    34
};
# endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-96)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     109,   -84,   -84,   -84,   -84,   -84,   -84,   -17,   118,   -10,
     -84,   -84,   -84,     8,   -84,   -84,   -84,   -84,   -84,   -14,
      33,    11,   112,    25,    13,   -11,   -16,   -84,   118,     2,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,    42,   -84,    63,
     -84,   -84,   109,   -84,   -84,   -84,   -84,   118,    67,   -84,
     118,    38,    39,    -3,   109,    28,   -84,    27,   -84,   118,
     -84,   -84,    54,   118,   -84,   -84,   -84,   -84,   -84,   -84,
     118,   -84,   -84,   118,   -84,   -84,   -84,   118,   -84,   118,
     -84,   -84,   -84,     5,    41,   114,   -84,   -84,   -84,   118,
     -84,   118,   -84,    59,   -84,   -84,   118,   118,    25,   -84,
     -84,   -84,   -84,   -84,   -84,   118,    13,   -11,   -16,   -84,
      -6,    83,    68,   -84,    88,   -84,    67,   -84,    -1,    14,
      67,   -84,   -84,   -84,   118,    55,   -84,    91,   -15,    93,
      41,   -84,   -84,   -84,   -84,   -84,   -84,   -84,    51,    15,
     -84,   -84,    61,    41,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      47,     3,     4,     6,     5,    43,    44,     0,     0,     0,
      84,    30,    31,     0,    72,    32,    39,    40,    37,     0,
       0,     0,    60,     8,    10,    12,    14,    16,     0,    17,
      33,    36,    42,    34,    35,    74,    48,     0,    49,     0,
      50,    51,     2,    52,    53,    54,    55,     0,    83,    76,
       0,     0,     0,     0,    47,     0,     1,     0,    56,     0,
      69,    70,     0,     0,    19,    20,    22,    24,    23,    21,
       0,    25,    26,     0,    27,    28,    29,     0,    18,     0,
      62,    71,    75,     0,     0,    60,    94,    96,    89,     0,
      85,     0,    38,     0,    41,    57,     0,     0,     7,    64,
      65,    66,    67,    68,    63,     0,     9,    11,    13,    15,
       0,     0,    78,    77,     0,    86,    46,    73,     0,     0,
      61,    45,    97,    79,     0,     0,    58,     0,     0,     0,
       0,    87,    59,    82,    81,    80,    90,    88,     0,     0,
      92,    93,     0,     0,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -84,   -84,    95,    -8,    52,    57,    53,    60,   -25,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -40,
     -84,    75,   -84,   -84,   -84,    85,   -84,   -83,   -84,    84,
      12,   -84,   -84,   -84,   -84,   -81,   -84,   -84,   -84,   -84,
     -84,   -84,   -84,   -84,   -84,   -84,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    70,
      73,    77,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    62,    38,   105,    39,    40,    41,    54,    42,
      43,    84,   113,   128,   135,    49,    44,    51,    90,   125,
     131,    45,   114,   138,   142,    88,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   112,    82,    78,    59,    53,   126,    59,   115,    59,
       8,     1,     2,     3,     4,    59,     5,     6,    74,    75,
      76,    71,    72,    47,    59,    64,    65,    66,    67,    14,
      50,   140,   141,    56,    95,    55,    63,   121,    92,    83,
      11,    12,    85,   129,    79,   133,   111,   137,    13,    80,
      68,    69,   109,    82,    15,    16,    17,   127,    18,    19,
     144,    57,     1,     2,     3,     4,    96,     5,     6,    97,
      81,   110,    99,   100,   101,   102,   103,    59,    89,    94,
      91,    48,     7,   116,     8,    14,     9,    10,   118,   119,
     122,    11,    12,   104,   123,   124,   130,   120,   132,    13,
     136,   139,   143,    14,   117,    15,    16,    17,    52,    18,
      19,    98,     1,     2,     3,     4,    48,     5,     6,    58,
     106,   -95,    59,   107,    59,    86,     5,     6,    60,    61,
      60,    61,     7,   108,     8,    87,     9,    10,    93,     0,
     134,    11,    12,     0,     0,     0,     0,     0,     0,    13,
      11,    12,     0,    14,     0,    15,    16,    17,    13,    18,
      19,     0,     0,     0,    15,    16,    17,     0,    18,    19
};

static const yytype_int16 yycheck[] =
{
       8,    84,    42,    28,    10,    13,     7,    10,    89,    10,
      25,     3,     4,     5,     6,    10,     8,     9,    34,    35,
      36,    32,    33,    40,    10,    12,    13,    14,    15,    44,
      40,    16,    17,     0,     7,    49,    11,    43,    41,    47,
      32,    33,    50,   124,    42,   128,    41,   130,    40,     7,
      37,    38,    77,    93,    46,    47,    48,    43,    50,    51,
     143,    50,     3,     4,     5,     6,    39,     8,     9,    42,
       7,    79,    18,    19,    20,    21,    22,    10,    40,    51,
      41,    89,    23,    91,    25,    44,    27,    28,    96,    97,
       7,    32,    33,    39,    26,     7,    41,   105,     7,    40,
       7,    50,    41,    44,    45,    46,    47,    48,    13,    50,
      51,    59,     3,     4,     5,     6,   124,     8,     9,     7,
      63,     7,    10,    70,    10,    50,     8,     9,    16,    17,
      16,    17,    23,    73,    25,    50,    27,    28,    54,    -1,
     128,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      32,    33,    -1,    44,    -1,    46,    47,    48,    40,    50,
      51,    -1,    -1,    -1,    46,    47,    48,    -1,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    23,    25,    27,
      28,    32,    33,    40,    44,    46,    47,    48,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    60,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    75,    77,
      78,    79,    81,    82,    88,    93,    98,    40,    55,    87,
      40,    89,    54,    55,    80,    49,     0,    50,     7,    10,
      16,    17,    74,    11,    12,    13,    14,    15,    37,    38,
      61,    32,    33,    62,    34,    35,    36,    63,    60,    42,
       7,     7,    71,    55,    83,    55,    73,    77,    97,    40,
      90,    41,    41,    81,    51,     7,    39,    42,    56,    18,
      19,    20,    21,    22,    39,    76,    57,    58,    59,    60,
      55,    41,    79,    84,    94,    87,    55,    45,    55,    55,
      55,    43,     7,    26,     7,    91,     7,    43,    85,    87,
      41,    92,     7,    79,    82,    86,     7,    79,    95,    50,
      16,    17,    96,    41,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      74,    73,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    78,    80,    79,    81,    81,    83,    82,    84,    85,
      84,    86,    86,    87,    89,    88,    91,    90,    92,    94,
      95,    93,    96,    96,    97,    97,    97,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     4,     4,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     5,     6,
       0,     4,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     0,     4,     1,     2,     0,     4,     1,     0,
       4,     1,     1,     1,     0,     3,     0,     4,     2,     0,
       0,    12,     1,     1,     1,     1,     1,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 97 "compiler_hw3.y"
                    { ind = 0; dump(); }
#line 1552 "y.tab.c"
    break;

  case 3:
#line 101 "compiler_hw3.y"
                { (yyval.s_val) = "int";  }
#line 1558 "y.tab.c"
    break;

  case 4:
#line 102 "compiler_hw3.y"
                { (yyval.s_val) = "float"; }
#line 1564 "y.tab.c"
    break;

  case 5:
#line 103 "compiler_hw3.y"
                { (yyval.s_val) = "string"; }
#line 1570 "y.tab.c"
    break;

  case 6:
#line 104 "compiler_hw3.y"
                { (yyval.s_val) = "bool"; }
#line 1576 "y.tab.c"
    break;

  case 7:
#line 108 "compiler_hw3.y"
                                { load = 0; check_error((yyvsp[-2].s_val), "OR", (yyvsp[0].s_val)); (yyval.s_val) = (yyvsp[-2].s_val); codegen("ior\n"); }
#line 1582 "y.tab.c"
    break;

  case 9:
#line 113 "compiler_hw3.y"
                                  { load = 0; check_error((yyvsp[-2].s_val), "AND", (yyvsp[0].s_val)); (yyval.s_val) = (yyvsp[-2].s_val); codegen("iand\n"); }
#line 1588 "y.tab.c"
    break;

  case 11:
#line 118 "compiler_hw3.y"
                                     { 
        load = 0;
        (yyval.s_val) = "bool";
        if(strcmp((yyvsp[0].s_val), "int") == 0)
            codegen("isub\n");
        if(strcmp((yyvsp[-2].s_val), "float") == 0 && strcmp((yyvsp[0].s_val), "float") == 0)
            codegen("fcmpl\n");
        codegen("if%s L_cmp_%d\n", (yyvsp[-1].s_val), 2 * cmpNum);
        codegen("iconst_0\n");
        codegen("goto L_cmp_%d\n", 2 * cmpNum + 1);
        codegen("L_cmp_%d:\n", 2 * cmpNum);
        codegen("iconst_1\n");
        codegen("L_cmp_%d:\n", 2 * cmpNum + 1);
        cmpNum++;
    }
#line 1608 "y.tab.c"
    break;

  case 13:
#line 137 "compiler_hw3.y"
                                     { load = 0; check_error((yyvsp[-2].s_val), (yyvsp[-1].s_val), (yyvsp[0].s_val)); (yyval.s_val) = (yyvsp[-2].s_val); codegen("%c%s\n", get_type0((yyvsp[-2].s_val)), (yyvsp[-1].s_val)); }
#line 1614 "y.tab.c"
    break;

  case 15:
#line 142 "compiler_hw3.y"
                                   { load = 0; check_error((yyvsp[-2].s_val), (yyvsp[-1].s_val), (yyvsp[0].s_val)); (yyval.s_val) = (yyvsp[-2].s_val); codegen("%c%s\n", get_type0((yyvsp[-2].s_val)), (yyvsp[-1].s_val)); }
#line 1620 "y.tab.c"
    break;

  case 18:
#line 148 "compiler_hw3.y"
                         {
        load = 0;
        (yyval.s_val) = (yyvsp[0].s_val);
        if(strcmp((yyvsp[-1].s_val), "not") == 0) codegen("iconst_1\n");
        if (strcmp((yyvsp[-1].s_val), "neg") == 0)
            codegen("%cneg\n", get_type0((yyvsp[0].s_val)));
        else if (strcmp((yyvsp[-1].s_val), "not") == 0)
            codegen("ixor\n");
    }
#line 1634 "y.tab.c"
    break;

  case 19:
#line 160 "compiler_hw3.y"
            { (yyval.s_val) = "eq"; }
#line 1640 "y.tab.c"
    break;

  case 20:
#line 161 "compiler_hw3.y"
            { (yyval.s_val) = "ne"; }
#line 1646 "y.tab.c"
    break;

  case 21:
#line 162 "compiler_hw3.y"
            { (yyval.s_val) = "lt"; }
#line 1652 "y.tab.c"
    break;

  case 22:
#line 163 "compiler_hw3.y"
            { (yyval.s_val) = "le"; }
#line 1658 "y.tab.c"
    break;

  case 23:
#line 164 "compiler_hw3.y"
            { (yyval.s_val) = "gt"; }
#line 1664 "y.tab.c"
    break;

  case 24:
#line 165 "compiler_hw3.y"
            { (yyval.s_val) = "ge"; }
#line 1670 "y.tab.c"
    break;

  case 25:
#line 169 "compiler_hw3.y"
            { (yyval.s_val) = "add"; }
#line 1676 "y.tab.c"
    break;

  case 26:
#line 170 "compiler_hw3.y"
            { (yyval.s_val) = "sub"; }
#line 1682 "y.tab.c"
    break;

  case 27:
#line 174 "compiler_hw3.y"
            { (yyval.s_val) = "mul"; }
#line 1688 "y.tab.c"
    break;

  case 28:
#line 175 "compiler_hw3.y"
            { (yyval.s_val) = "div"; }
#line 1694 "y.tab.c"
    break;

  case 29:
#line 176 "compiler_hw3.y"
            { (yyval.s_val) = "rem"; }
#line 1700 "y.tab.c"
    break;

  case 30:
#line 180 "compiler_hw3.y"
            { (yyval.s_val) = ""; }
#line 1706 "y.tab.c"
    break;

  case 31:
#line 181 "compiler_hw3.y"
            { (yyval.s_val) = "neg"; }
#line 1712 "y.tab.c"
    break;

  case 32:
#line 182 "compiler_hw3.y"
            { (yyval.s_val) = "not"; }
#line 1718 "y.tab.c"
    break;

  case 33:
#line 186 "compiler_hw3.y"
                { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1724 "y.tab.c"
    break;

  case 34:
#line 187 "compiler_hw3.y"
                { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1730 "y.tab.c"
    break;

  case 36:
#line 192 "compiler_hw3.y"
                { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1736 "y.tab.c"
    break;

  case 37:
#line 193 "compiler_hw3.y"
            {
        (yyval.s_val) = (yyvsp[0].s_val);
        if(!lookup((yyvsp[0].s_val))) {
            printf("error:%d: undefined: %s\n", yylineno, (yyvsp[0].s_val));
            HAS_ERROR = TRUE;
        }
        else {
            if (strcmp(lookup((yyvsp[0].s_val))->type, "int") == 0 || strcmp(lookup((yyvsp[0].s_val))->type, "bool") == 0)
                codegen("iload %d\n", lookup((yyvsp[0].s_val))->address);
            else if (strcmp(lookup((yyvsp[0].s_val))->type, "float") == 0)
                codegen("fload %d\n", lookup((yyvsp[0].s_val))->address);
            else if (strcmp(lookup((yyvsp[0].s_val))->type, "string") == 0 || strcmp(lookup((yyvsp[0].s_val))->type, "array") == 0)
                codegen("aload %d\n", lookup((yyvsp[0].s_val))->address);
        }
    }
#line 1756 "y.tab.c"
    break;

  case 38:
#line 208 "compiler_hw3.y"
                            { (yyval.s_val) = (yyvsp[-1].s_val); }
#line 1762 "y.tab.c"
    break;

  case 39:
#line 212 "compiler_hw3.y"
              { (yyval.s_val) = "int"; codegen("ldc %d\n", (yyvsp[0].i_val)); }
#line 1768 "y.tab.c"
    break;

  case 40:
#line 213 "compiler_hw3.y"
                { (yyval.s_val) = "float"; codegen("ldc %f\n", (yyvsp[0].f_val)); }
#line 1774 "y.tab.c"
    break;

  case 41:
#line 214 "compiler_hw3.y"
                           { load = 0; (yyval.s_val) = "string"; codegen("ldc \"%s\"\n", (yyvsp[-1].s_val)); }
#line 1780 "y.tab.c"
    break;

  case 42:
#line 215 "compiler_hw3.y"
               { (yyval.s_val) = (yyvsp[0].s_val); }
#line 1786 "y.tab.c"
    break;

  case 43:
#line 219 "compiler_hw3.y"
           { (yyval.s_val) = "bool"; codegen("iconst_1\n"); }
#line 1792 "y.tab.c"
    break;

  case 44:
#line 220 "compiler_hw3.y"
            { (yyval.s_val) = "bool"; codegen("iconst_0\n"); }
#line 1798 "y.tab.c"
    break;

  case 45:
#line 224 "compiler_hw3.y"
                                     {
        load = 1;
        if(assign == 0)
            codegen("%caload\n", get_type0((yyvsp[-3].s_val)));
        (yyval.s_val) = (yyvsp[-3].s_val);
    }
#line 1809 "y.tab.c"
    break;

  case 46:
#line 233 "compiler_hw3.y"
                                  { codegen("%c2%c\n", get_type0((yyvsp[0].s_val)), get_type0((yyvsp[-2].s_val))); }
#line 1815 "y.tab.c"
    break;

  case 48:
#line 238 "compiler_hw3.y"
                      { load = 0; }
#line 1821 "y.tab.c"
    break;

  case 57:
#line 250 "compiler_hw3.y"
                               { insert((yyvsp[-1].s_val), (yyvsp[-2].s_val), "-", 0); }
#line 1827 "y.tab.c"
    break;

  case 58:
#line 251 "compiler_hw3.y"
                                              { insert((yyvsp[-3].s_val), (yyvsp[-4].s_val), "-", 1); }
#line 1833 "y.tab.c"
    break;

  case 59:
#line 252 "compiler_hw3.y"
                                                  {
        load = 1; 
        insert((yyvsp[-4].s_val), "array", (yyvsp[-5].s_val), 0);
    }
#line 1842 "y.tab.c"
    break;

  case 60:
#line 259 "compiler_hw3.y"
                 {
        assign = 0;
    }
#line 1850 "y.tab.c"
    break;

  case 61:
#line 261 "compiler_hw3.y"
                           { 
        assign = 1;
        if(lookup((yyvsp[-3].s_val)) && lookup((yyvsp[0].s_val))) check_error((yyvsp[-3].s_val), (yyvsp[-1].s_val), (yyvsp[0].s_val));
        if(is_lit((yyvsp[-3].s_val)) == 1) {
            printf("error:%d: cannot assign to %s\n", yylineno, (yyvsp[-3].s_val));
            HAS_ERROR = TRUE;
        }
        if(strcmp((yyvsp[-1].s_val), "=") != 0) codegen("%c%s\n", get_type0((yyvsp[0].s_val)), (yyvsp[-1].s_val));
        if(lookup((yyvsp[-3].s_val))) { declare = 0; store((yyvsp[-3].s_val)); }
    }
#line 1865 "y.tab.c"
    break;

  case 63:
#line 278 "compiler_hw3.y"
                    { (yyval.s_val) = "="; }
#line 1871 "y.tab.c"
    break;

  case 64:
#line 279 "compiler_hw3.y"
                    { (yyval.s_val) = "add"; }
#line 1877 "y.tab.c"
    break;

  case 65:
#line 280 "compiler_hw3.y"
                    { (yyval.s_val) = "sub"; }
#line 1883 "y.tab.c"
    break;

  case 66:
#line 281 "compiler_hw3.y"
                    { (yyval.s_val) = "mul"; }
#line 1889 "y.tab.c"
    break;

  case 67:
#line 282 "compiler_hw3.y"
                    { (yyval.s_val) = "div"; }
#line 1895 "y.tab.c"
    break;

  case 68:
#line 283 "compiler_hw3.y"
                    { (yyval.s_val) = "rem"; }
#line 1901 "y.tab.c"
    break;

  case 69:
#line 287 "compiler_hw3.y"
                     {
        codegen("ldc 1%s\n", (get_type0((yyvsp[-1].s_val)) == 'f')? ".0" : "");
        codegen("%cadd\n", get_type0((yyvsp[-1].s_val)));
        declare = 0;
        store((yyvsp[-1].s_val));
    }
#line 1912 "y.tab.c"
    break;

  case 70:
#line 293 "compiler_hw3.y"
                     {
        codegen("ldc 1%s\n", (get_type0((yyvsp[-1].s_val)) == 'f')? ".0" : "");
        codegen("%csub\n", get_type0((yyvsp[-1].s_val)));
        declare = 0;
        store((yyvsp[-1].s_val));
    }
#line 1923 "y.tab.c"
    break;

  case 72:
#line 306 "compiler_hw3.y"
          { create(); }
#line 1929 "y.tab.c"
    break;

  case 73:
#line 306 "compiler_hw3.y"
                                          { ind = 0; dump(); }
#line 1935 "y.tab.c"
    break;

  case 76:
#line 315 "compiler_hw3.y"
                   {
        codegen("ifeq L_if_%d\n", ifNum);
        if_stack = push(if_stack, ifNum);
        ifNum++;
    }
#line 1945 "y.tab.c"
    break;

  case 78:
#line 323 "compiler_hw3.y"
            { 
        codegen("goto L_if_exit_%d\n", if_stack->num);
        codegen("L_if_%d:\n", if_stack->num);
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
        ifNum++;
    }
#line 1957 "y.tab.c"
    break;

  case 79:
#line 330 "compiler_hw3.y"
                 { 
        codegen("goto L_if_exit_%d\n", if_stack->num);
        codegen("L_if_%d:\n", if_stack->num);
    }
#line 1966 "y.tab.c"
    break;

  case 81:
#line 337 "compiler_hw3.y"
             {
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
    }
#line 1975 "y.tab.c"
    break;

  case 82:
#line 341 "compiler_hw3.y"
            {
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
    }
#line 1984 "y.tab.c"
    break;

  case 83:
#line 348 "compiler_hw3.y"
                 {
        if(strcmp((yyvsp[0].s_val), "bool") != 0) { 
            if(is_lit((yyvsp[0].s_val)) == 0 && lookup((yyvsp[0].s_val))) {
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, lookup((yyvsp[0].s_val))->type);
                HAS_ERROR = TRUE;
            }
            else {
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, (yyvsp[0].s_val));
                HAS_ERROR = TRUE;
            }
        }
    }
#line 2001 "y.tab.c"
    break;

  case 84:
#line 363 "compiler_hw3.y"
            {
        codegen("L_for_begin_%d:\n", forNum);
        for_stack = push(for_stack, forNum);
        forNum++;
    }
#line 2011 "y.tab.c"
    break;

  case 86:
#line 371 "compiler_hw3.y"
                    {
        codegen("ifeq L_for_exit_%d\n", for_stack->num);
    }
#line 2019 "y.tab.c"
    break;

  case 88:
#line 377 "compiler_hw3.y"
                {
        codegen("goto L_for_begin_%d\n", for_stack->num);
        codegen("L_for_exit_%d:\n", for_stack->num);
        for_stack = pop(for_stack);
    }
#line 2029 "y.tab.c"
    break;

  case 89:
#line 385 "compiler_hw3.y"
                         {
        codegen("L_for_begin_%d:\n", forNum);
        for_stack = push(for_stack, forNum);
        forNum++;        
    }
#line 2039 "y.tab.c"
    break;

  case 90:
#line 389 "compiler_hw3.y"
                                    {
        codegen("ifeq L_for_exit_%d\n", for_stack->num);
    }
#line 2047 "y.tab.c"
    break;

  case 91:
#line 391 "compiler_hw3.y"
                               {
        codegen("%cload %d\n", get_type0((yyvsp[-3].s_val)), lookup((yyvsp[-3].s_val))->address);
        codegen("ldc 1%s\n", (get_type0((yyvsp[-3].s_val)) == 'f')? ".0" : "");
        codegen("%c%s\n", get_type0((yyvsp[-3].s_val)), (yyvsp[-2].s_val));
        declare = 0;
        store((yyvsp[-3].s_val));
        codegen("goto L_for_begin_%d\n", for_stack->num);
        codegen("L_for_exit_%d:\n", for_stack->num);
        for_stack = pop(for_stack);
    }
#line 2062 "y.tab.c"
    break;

  case 92:
#line 404 "compiler_hw3.y"
          { (yyval.s_val) = "add"; }
#line 2068 "y.tab.c"
    break;

  case 93:
#line 405 "compiler_hw3.y"
          { (yyval.s_val) = "sub"; }
#line 2074 "y.tab.c"
    break;

  case 97:
#line 415 "compiler_hw3.y"
                                         { 
        if(load == 1) codegen("%caload\n", get_type0((yyvsp[-2].s_val)));
        if(strcmp((yyvsp[-2].s_val), "bool") == 0 || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->type, "bool") == 0)) {
            codegen("ifne L_bool_%d\n", 2 * boolNum);
            codegen("ldc \"false\"\n");
            codegen("goto L_bool_%d\n", 2 * boolNum + 1);
            codegen("L_bool_%d:\n", 2 * boolNum);
            codegen("ldc \"true\"\n");
            codegen("L_bool_%d:\n", 2 * boolNum + 1);
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
            boolNum++;
        }
        else {
            codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            codegen("swap\n");
            if(strcmp((yyvsp[-2].s_val), "int") == 0 || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->type, "int") == 0) || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->elementType, "int") == 0))
                codegen("invokevirtual java/io/PrintStream/print(I)V\n");
            else if(strcmp((yyvsp[-2].s_val), "float") == 0 || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->type, "float") == 0) || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->elementType, "float") == 0))
                codegen("invokevirtual java/io/PrintStream/print(F)V\n");
            else if(strcmp((yyvsp[-2].s_val), "string") == 0 || (lookup((yyvsp[-2].s_val)) && strcmp(lookup((yyvsp[-2].s_val))->type, "string") == 0))
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
    }
#line 2104 "y.tab.c"
    break;


#line 2108 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 442 "compiler_hw3.y"


static void insert(char *name, char *type, char *elementType, int vau) {
    for(node *tn = sym_ta[sco]; tn; tn = tn->next) {
        if(strcmp(tn->name, name) == 0) {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, name, tn->lineno);
            HAS_ERROR = TRUE;
            return;
        }
    }
    node *new = malloc(sizeof(node));
    new->name = name;
    new->type = type;
    new->address = addr++;
    new->lineno = yylineno;
    new->elementType = elementType;
    new->next = NULL;
    if(sym_ta[sco]) {
        node *tn = sym_ta[sco];
        while(tn->next) tn = tn->next;
        tn->next = new;
    }
    else sym_ta[sco] = new;
    
    if(strcmp(type, "array") == 0)
        codegen("newarray %s\n", (strcmp(elementType, "int") == 0) ? "int" : "float");
    else if(vau == 0 && strcmp(type, "int") == 0)
        codegen("ldc 0\n");
    else if(vau == 0 && strcmp(type, "float") == 0)
        codegen("ldc 0.0\n");
    else if(vau == 0 && strcmp(type, "string") == 0)
        codegen("ldc \"\"\n");
    else if(vau == 0 && strcmp(type, "bool") == 0)
        codegen("iconst_0\n");
    declare = 1;
    store(name);
}

static node* lookup(char *name) {
    int s = sco;
    while (s >= 0) {
        node *tn = sym_ta[s--];
        while (tn) {
            if (strcmp(tn->name, name) == 0) return tn;    
            tn = tn->next;
        }
    }
    return NULL;
}

static void dump() {
    printf("> Dump symbol table (scope level: %d)\n", sco);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(node *tn = sym_ta[sco]; tn; tn = tn->next)
        printf("%-10d%-10s%-10s%-10d%-10d%s\n", ind++, tn->name, tn->type, tn->address, tn->lineno, tn->elementType);;
    sym_ta[sco--] = NULL;
}

static void check_error(char *s1, char *s2, char *s3) {
    int flag = -1;
    if(strcmp(s2, "rem") == 0)  { flag = 1; }
    if(strcmp(s2, "AND") == 0)  { flag = 2; }
    if(strcmp(s2, "OR") == 0)   { flag = 3; }
    switch(flag) {
        case 1:
            if((lookup(s1) && strcmp(lookup(s1)->type, "float") == 0) || (lookup(s3) && strcmp(lookup(s3)->type, "float") == 0)) {
                printf("error:%d: invalid operation: (operator REM not defined on float)\n", yylineno);
                HAS_ERROR = TRUE;
            }
            break;
        case 2:
            if(strcmp(s1, "int") == 0 || strcmp(s3, "int") == 0) {
                printf("error:%d: invalid operation: (operator AND not defined on int)\n", yylineno);
                HAS_ERROR = TRUE;
            }
            break;
        case 3:
            if(strcmp(s1, "int") == 0 || strcmp(s3, "int") == 0) {
                printf("error:%d: invalid operation: (operator OR not defined on int)\n", yylineno);
                HAS_ERROR = TRUE;
            }
            break;
        case -1:
            if(lookup(s1) && lookup(s3) && strcmp(lookup(s1)->type, lookup(s3)->type) != 0) {
                if(strcmp(s2, "add") == 0) s2 = "ADD";
                else if(strcmp(s2, "=") == 0) s2 = "ASSIGN";
                else if(strcmp(s2, "sub") == 0) s2 = "SUB";
                printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, s2, lookup(s1)->type, lookup(s3)->type);
                HAS_ERROR = TRUE;
            }
            if(!lookup(s1) && !lookup(s3) && strcmp(s1, s3) != 0 && strcmp(s1, "bool") != 0 && strcmp(s3, "bool") != 0) {
                if(strcmp(s2, "add") == 0) s2 = "ADD";
                else if(strcmp(s2, "=") == 0) s2 = "ASSIGN";
                else if(strcmp(s2, "sub") == 0) s2 = "SUB";
                printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, s2, s1, s3);
                HAS_ERROR = TRUE;
            }
    }
}

static int is_lit(char *s) {
    if(strcmp(s, "int") != 0 && strcmp(s, "float") != 0 && strcmp(s, "bool") != 0 && strcmp(s, "string") != 0) return 0;
    else return 1;
}

static char get_type0(char *s) {
    if(is_lit(s)) c = s[0];
    else if(lookup(s)) 
        c = (strcmp(lookup(s)->type, "array") == 0)? lookup(s)->elementType[0] : lookup(s)->type[0];
    return c;
}

static void store(char *n) {
    if((lookup(n) && strcmp(lookup(n)->type, "int") == 0) || (lookup(n) && strcmp(lookup(n)->type, "bool") == 0))
        codegen("istore %d\n", lookup(n)->address);
    else if(lookup(n) && strcmp(lookup(n)->type, "float") == 0)
        codegen("fstore %d\n", lookup(n)->address);
    else if(lookup(n) && strcmp(lookup(n)->type, "string") == 0)
        codegen("astore %d\n", lookup(n)->address);
    else if(lookup(n) && strcmp(lookup(n)->type, "array") == 0) {
        if(declare == 1) codegen("astore %d\n", lookup(n)->address);
        else { load = 0; codegen("%castore\n", lookup(n)->elementType[0]); }
    }
}

static node2* push(node2 *init, int n) {
    node2 *new = malloc(sizeof(node2));
    new->num = n;
    new->next = init;
    init = new;
    return init;
}

static node2* pop(node2 *init) {
    node2 *tmp = init;
    init = init->next;
    free(tmp);
    return init;
}

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

        printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    } 
    return 0;
}
