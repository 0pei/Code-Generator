/*	Definition section */
%{
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
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
}

/* Token without return */
%token INT FLOAT BOOL STRING SEMICOLON TRUE FALSE 
%token OR AND EQL NEQ LEQ GEQ INC DEC
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token PRINT RETURN IF ELSE FOR WHILE CONTINUE BREAK VOID 
%token '+' '-' '*' '/' '%' '>' '<' '=' '(' ')' '[' ']' '{' '}' '!'

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT IDENT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Expression Expression1 Expression2 Expression3 Expression4
%type <s_val> TypeName Literal BOOL_LIT UnaryExpr PrimaryExpr IndexExpr
%type <s_val> cmp_op add_op mul_op unary_op assign_op Operand ForStmt2

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : StatementList { ind = 0; dump(); }
;

TypeName
    : INT       { $$ = "int";  }
    | FLOAT     { $$ = "float"; }
    | STRING    { $$ = "string"; }
    | BOOL      { $$ = "bool"; }   
;

Expression
    : Expression OR Expression1 { load = 0; check_error($1, "OR", $3); $$ = $1; codegen("ior\n"); } 
    | Expression1
;

Expression1
    : Expression1 AND Expression2 { load = 0; check_error($1, "AND", $3); $$ = $1; codegen("iand\n"); }
    | Expression2
;

Expression2
    : Expression2 cmp_op Expression3 { 
        load = 0;
        $$ = "bool";
        if(strcmp($3, "int") == 0)
            codegen("isub\n");
        if(strcmp($1, "float") == 0 && strcmp($3, "float") == 0)
            codegen("fcmpl\n");
        codegen("if%s L_cmp_%d\n", $2, 2 * cmpNum);
        codegen("iconst_0\n");
        codegen("goto L_cmp_%d\n", 2 * cmpNum + 1);
        codegen("L_cmp_%d:\n", 2 * cmpNum);
        codegen("iconst_1\n");
        codegen("L_cmp_%d:\n", 2 * cmpNum + 1);
        cmpNum++;
    }
    | Expression3
;

Expression3 
    : Expression3 add_op Expression4 { load = 0; check_error($1, $2, $3); $$ = $1; codegen("%c%s\n", get_type0($1), $2); }
    | Expression4
;

Expression4 
    : Expression4 mul_op UnaryExpr { load = 0; check_error($1, $2, $3); $$ = $1; codegen("%c%s\n", get_type0($1), $2); }
    | UnaryExpr
;

UnaryExpr
    : PrimaryExpr
    | unary_op UnaryExpr {
        load = 0;
        $$ = $2;
        if(strcmp($1, "not") == 0) codegen("iconst_1\n");
        if (strcmp($1, "neg") == 0)
            codegen("%cneg\n", get_type0($2));
        else if (strcmp($1, "not") == 0)
            codegen("ixor\n");
    }
;

cmp_op
    : EQL   { $$ = "eq"; }
    | NEQ   { $$ = "ne"; }
    | '<'   { $$ = "lt"; }
    | LEQ   { $$ = "le"; }
    | '>'   { $$ = "gt"; }
    | GEQ   { $$ = "ge"; }
;

add_op
    : '+'   { $$ = "add"; }
    | '-'   { $$ = "sub"; }
;

mul_op
    : '*'   { $$ = "mul"; }
    | '/'   { $$ = "div"; }
    | '%'   { $$ = "rem"; }
;

unary_op
    : '+'   { $$ = ""; }
    | '-'   { $$ = "neg"; }
    | '!'   { $$ = "not"; }
;

PrimaryExpr
    : Operand   { $$ = $1; }
    | IndexExpr { $$ = $1; }
    | ConversionExpr
;

Operand
    : Literal   { $$ = $1; }
    | IDENT {
        $$ = $1;
        if(!lookup($1)) {
            printf("error:%d: undefined: %s\n", yylineno, $1);
            HAS_ERROR = TRUE;
        }
        else {
            if (strcmp(lookup($1)->type, "int") == 0 || strcmp(lookup($1)->type, "bool") == 0)
                codegen("iload %d\n", lookup($1)->address);
            else if (strcmp(lookup($1)->type, "float") == 0)
                codegen("fload %d\n", lookup($1)->address);
            else if (strcmp(lookup($1)->type, "string") == 0 || strcmp(lookup($1)->type, "array") == 0)
                codegen("aload %d\n", lookup($1)->address);
        }
    }
    | '(' Expression ')'    { $$ = $2; }
;

Literal
    : INT_LIT { $$ = "int"; codegen("ldc %d\n", $<i_val>1); }
    | FLOAT_LIT { $$ = "float"; codegen("ldc %f\n", $<f_val>1); }
    | '\"' STRING_LIT '\"' { load = 0; $$ = "string"; codegen("ldc \"%s\"\n", $<s_val>2); }
    | BOOL_LIT { $$ = $1; }
;

BOOL_LIT
    : TRUE { $$ = "bool"; codegen("iconst_1\n"); }
    | FALSE { $$ = "bool"; codegen("iconst_0\n"); }
;

IndexExpr
    : PrimaryExpr '[' Expression ']' {
        load = 1;
        if(assign == 0)
            codegen("%caload\n", get_type0($1));
        $$ = $1;
    }
;

ConversionExpr
    : '(' TypeName ')' Expression { codegen("%c2%c\n", get_type0($4), get_type0($2)); }  
;

Statement
    : /* empty */
    | DeclarationStmt { load = 0; }
    | AssignmentStmt
    | IncDecStmt
    | Block
    | IfStmt
    | WhileStmt
    | ForStmt
    | PrintStmt
    | Expression SEMICOLON
;

DeclarationStmt
    : TypeName IDENT SEMICOLON { insert($2, $1, "-", 0); }
    | TypeName IDENT '=' Expression SEMICOLON { insert($2, $1, "-", 1); }
    | TypeName IDENT '[' Expression ']' SEMICOLON {
        load = 1; 
        insert($2, "array", $1, 0);
    }
;

AssignmentExpr
    : Expression {
        assign = 0;
    } assign_op Expression { 
        assign = 1;
        if(lookup($1) && lookup($4)) check_error($1, $3, $4);
        if(is_lit($1) == 1) {
            printf("error:%d: cannot assign to %s\n", yylineno, $1);
            HAS_ERROR = TRUE;
        }
        if(strcmp($3, "=") != 0) codegen("%c%s\n", get_type0($4), $3);
        if(lookup($1)) { declare = 0; store($1); }
    }  
;

AssignmentStmt
    : AssignmentExpr SEMICOLON
;

assign_op
    : '='           { $$ = "="; }
    | ADD_ASSIGN    { $$ = "add"; }
    | SUB_ASSIGN    { $$ = "sub"; }
    | MUL_ASSIGN    { $$ = "mul"; }
    | QUO_ASSIGN    { $$ = "div"; }
    | REM_ASSIGN    { $$ = "rem"; }
;

IncDecExpr
    : Expression INC {
        codegen("ldc 1%s\n", (get_type0($1) == 'f')? ".0" : "");
        codegen("%cadd\n", get_type0($1));
        declare = 0;
        store($1);
    }
    | Expression DEC {
        codegen("ldc 1%s\n", (get_type0($1) == 'f')? ".0" : "");
        codegen("%csub\n", get_type0($1));
        declare = 0;
        store($1);
    }
;

IncDecStmt
    : IncDecExpr SEMICOLON
;

Block
    : '{' { create(); } StatementList '}' { ind = 0; dump(); }
;

StatementList
    : Statement
    | StatementList Statement
;

IfStmt
    : IF Condition {
        codegen("ifeq L_if_%d\n", ifNum);
        if_stack = push(if_stack, ifNum);
        ifNum++;
    } IfStmt2
;

IfStmt2
    : Block { 
        codegen("goto L_if_exit_%d\n", if_stack->num);
        codegen("L_if_%d:\n", if_stack->num);
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
        ifNum++;
    } 
    | Block ELSE { 
        codegen("goto L_if_exit_%d\n", if_stack->num);
        codegen("L_if_%d:\n", if_stack->num);
    } IfStmt3
;

IfStmt3
    : IfStmt {
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
    }
    | Block {
        codegen("L_if_exit_%d:\n", if_stack->num);
        if_stack = pop(if_stack);
    }
;

Condition
    : Expression {
        if(strcmp($1, "bool") != 0) { 
            if(is_lit($1) == 0 && lookup($1)) {
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, lookup($1)->type);
                HAS_ERROR = TRUE;
            }
            else {
                printf("error:%d: non-bool (type %s) used as for condition\n", yylineno + 1, $1);
                HAS_ERROR = TRUE;
            }
        }
    }
;

WhileStmt 
    : WHILE {
        codegen("L_for_begin_%d:\n", forNum);
        for_stack = push(for_stack, forNum);
        forNum++;
    } WhileStmt2
;

WhileStmt2
    : '(' Condition {
        codegen("ifeq L_for_exit_%d\n", for_stack->num);
    } WhileStmt3
;

WhileStmt3
    : ')' Block {
        codegen("goto L_for_begin_%d\n", for_stack->num);
        codegen("L_for_exit_%d:\n", for_stack->num);
        for_stack = pop(for_stack);
    }
;

ForStmt
    : FOR '(' SimpleExpr {
        codegen("L_for_begin_%d:\n", forNum);
        for_stack = push(for_stack, forNum);
        forNum++;        
    } SEMICOLON Condition SEMICOLON {
        codegen("ifeq L_for_exit_%d\n", for_stack->num);
    } IDENT ForStmt2 ')' Block {
        codegen("%cload %d\n", get_type0($9), lookup($9)->address);
        codegen("ldc 1%s\n", (get_type0($9) == 'f')? ".0" : "");
        codegen("%c%s\n", get_type0($9), $10);
        declare = 0;
        store($9);
        codegen("goto L_for_begin_%d\n", for_stack->num);
        codegen("L_for_exit_%d:\n", for_stack->num);
        for_stack = pop(for_stack);
    }
;

ForStmt2
    : INC { $$ = "add"; }
    | DEC { $$ = "sub"; }
;

SimpleExpr
    : AssignmentExpr
    | Expression
    | IncDecExpr
;

PrintStmt
    : PRINT '(' Expression ')' SEMICOLON { 
        if(load == 1) codegen("%caload\n", get_type0($3));
        if(strcmp($3, "bool") == 0 || (lookup($3) && strcmp(lookup($3)->type, "bool") == 0)) {
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
            if(strcmp($3, "int") == 0 || (lookup($3) && strcmp(lookup($3)->type, "int") == 0) || (lookup($3) && strcmp(lookup($3)->elementType, "int") == 0))
                codegen("invokevirtual java/io/PrintStream/print(I)V\n");
            else if(strcmp($3, "float") == 0 || (lookup($3) && strcmp(lookup($3)->type, "float") == 0) || (lookup($3) && strcmp(lookup($3)->elementType, "float") == 0))
                codegen("invokevirtual java/io/PrintStream/print(F)V\n");
            else if(strcmp($3, "string") == 0 || (lookup($3) && strcmp(lookup($3)->type, "string") == 0))
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
    }
;

%%

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