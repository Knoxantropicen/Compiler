%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: Saturday, December 2, 2017
****************************************************************************/

#include "mylexer.h"
#include "utils.h"
using namespace std;

void returnScope() {
	if (!giv_stack.empty()) { 
		giv = giv_stack.top();
		giv_stack.pop();
	}
	entered = false;
	tables.insert({curr_table, table_count++});
	curr_table = curr_table->getFather();
}

void declInsertEntry(Node * var_id) {
	if (var_id->getType() == idt_t) {
		var_id->setEntry(new SymbolEntry(giv.g_type, giv.g_cate, giv.g_dim));
		var_id->getTable()->insert(var_id->getString(), var_id->getEntry());
		giv.g_cate = var_st;
		giv.g_dim = 0;
		return;
	}
	declInsertEntry(var_id->getChild(0));
}

void funcInsertEntry(Node * func_id) {
	func_id->setTable(curr_table->getFather());
	func_id->setEntry(new SymbolEntry(int_d, function_st, &giv.g_param_list));
	func_id->getTable()->insert(func_id->getString(), func_id->getEntry());
}

void funcSetEntry(Node * func_head) {
	Node * func_id = func_head->getChild(0);
	func_id->getTable()->setType(func_id->getString(), giv.g_type);
}

void addParamList() {
	giv.g_param_list.push_back(giv.g_type);
	giv.g_cate = var_st;
	giv.g_dim = 0;
}

void outputTables() {
	for (auto it: tables) {
		it.first->output(it.second);
	}
}

void debug() {
	cout << "Debug Info:" << endl;
	cout << "giv_stack -- size: " << giv_stack.size() << endl;
	cout << "giv.g_type: " << giv.g_type << endl;
	cout << "giv.g_cate: " << giv.g_cate << endl;
	cout << "giv.g_dim: " << giv.g_dim << endl;
	cout << "entered: " << entered << endl;
	cout << "root table address: " << root_table << endl;
	cout << "curr table address: " << curr_table << endl;
}

%}


/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name myparser

// class definition
{
	void yyerror(const char YYFAR* text);
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE Node *
#endif
}

// place any declarations here
%token VOID INT CHAR
%token RETURN
%token WHILE DO FOR
%token IF
%nonassoc NO_ELSE
%nonassoc ELSE
%token ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN
%token ANDASSIGN ORASSIGN XORASSIGN REVASSIGN
%token LSHIFTASSIGN RSHIFTASSIGN
%token OR AND
%token EQ NE LE GE LT GT
%token INC DEC
%token LSHIFT RSHIFT
%token INTVAL CHARVAL
%token ID

%start program
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

program
	: blocks {$$ = $1; cout << "Grammar Tree:" << endl; $$->traverse(); cout << endl; outputTables(); cout << endl;}
	;

blocks
	: blocks block {$$ = new Node(blocks_t); $$->addBack($1); $$->addBack($2);}
	| block {$$ = $1;}
	;

block
	: decl {$$ = $1;}
	| func {$$ = $1;}
	;

// data type
	
type
	: VOID {$$ = new Node(type_t, "void"); giv.g_type = void_d;}
	| INT {$$ = new Node(type_t, "integer"); giv.g_type = int_d;}
	| CHAR {$$ = new Node(type_t, "character"); giv.g_type = char_d;}
	;

// declaration

decl
	: type decl_list ';' {$$ = new Node(decl_t); $$->addBack($1); $$->addBack($2);}
	| type ';' {$$ = new Node(decl_t); $$->addBack($1);}
	;
	
decl_list
	: decl_list ',' decl_init {$$ = new Node(decl_list_t); $$->addBack($1); $$->addBack($3);}
	| decl_init {$$ = $1;}
	;
	
decl_init
	: decl_head '=' init_val {$$ = new Node(expr_t, "="); $$->addBack($1); $$->addBack($3);}
	| decl_head {$$ = $1;}
	;
	
decl_head
	: var_decl_head {$$ = $1; declInsertEntry($1);}
	;
	
var_decl_head
	: var_decl_head '[' const_expr ']' {$$ = new Node(decl_head_t, $1->getCharP()); $$->addBack($1); $$->addBack($3); giv.g_cate = array_st; ++giv.g_dim;}
	| var_decl_head '[' ']' {$$ = new Node(decl_head_t, $1->getCharP()); $$->addBack($1); giv.g_cate = array_st; ++giv.g_dim;}
	| ID {$$ = $1;}
	;

func_decl_head
	: ID '(' {giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;}
		param_list ')' {$$ = new Node(decl_head_t, $1->getCharP()); $$->addBack($1); $$->addBack($2);
		funcInsertEntry($1);}
	| ID '(' {giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;}
		 ')' {$$ = new Node(decl_head_t, $1->getCharP()); $$->addBack($1);
		funcInsertEntry($1);}
	;

init_val
	: '{' init_val_list '}' {$$ = $2; returnScope();}
	| assign_expr {$$ = $1;}
	;
	
init_val_list
	: init_val_list ',' init_val {$$ = new Node(init_val_t); $$->addBack($1); $$->addBack($3);}
	| init_val {$$ = $1;}
	;
	
param_list
	: param_list ',' param {$$ = new Node(param_list_t); $$->addBack($1); $$->addBack($3); addParamList();}
	| param {$$ = $1; addParamList();}
	;
	
param
	: type decl_init {$$ = new Node(param_t); $$->addBack($1); $$->addBack($2);}
	| type {$$ = new Node(param_t); $$->addBack($1);}
	;

// function

func
	: type func_decl_head compound_stmt {$$ = new Node(func_t); $$->addBack($1); $$->addBack($2); $$->addBack($3);
		funcSetEntry($2);}
	| func_decl_head compound_stmt {$$ = new Node(func_t); $$->addBack(new Node(type_t, "integer")); giv.g_type = int_d; 
		$$->addBack($1); $$->addBack($2); funcSetEntry($1);}
	;

// expression

expr
	: expr ',' assign_expr {$$ = new Node(expr_t, ","); $$->addBack($1); $$->addBack($3);}
	| assign_expr {$$ = $1;}
	;
	
assign_expr
	: ID assign_op assign_expr {$$ = $2; $$->addBack($1); $$->addBack($3);}
	| const_expr {$$ = $1;}
	;
	
const_expr
	: ternary_expr {$$ = $1;}
	;

ternary_expr
	: or_expr '?' ternary_expr ':' ternary_expr {$$ = new Node(expr_t, "? :"); $$->addBack($1); $$->addBack($2); $$->addBack($3);}
	| or_expr {$$ = $1;}
	;	
	
or_expr
	: or_expr OR and_expr {$$ = new Node(expr_t, "||"); $$->addBack($1); $$->addBack($3);}
	| and_expr {$$ = $1;}
	;
	
and_expr
	: and_expr AND bit_or_expr {$$ = new Node(expr_t, "&&"); $$->addBack($1); $$->addBack($3);}
	| bit_or_expr {$$ = $1;}
	;

bit_or_expr
	: bit_or_expr '|' bit_xor_expr {$$ = new Node(expr_t, "|"); $$->addBack($1); $$->addBack($3);}
	| bit_xor_expr {$$ = $1;}
	;
	
bit_xor_expr
	: bit_xor_expr '^' bit_and_expr {$$ = new Node(expr_t, "^"); $$->addBack($1); $$->addBack($3);}
	| bit_and_expr {$$ = $1;}
	;
	
bit_and_expr
	: bit_and_expr '&' equal_expr {$$ = new Node(expr_t, "&"); $$->addBack($1); $$->addBack($3);}
	| equal_expr {$$ = $1;}
	;
	
equal_expr
	: equal_expr EQ greater_less_expr {$$ = new Node(expr_t, "=="); $$->addBack($1); $$->addBack($3);}
	| equal_expr NE greater_less_expr {$$ = new Node(expr_t, "!="); $$->addBack($1); $$->addBack($3);}
	| greater_less_expr {$$ = $1;}
	;
	
greater_less_expr
	: greater_less_expr LE shift_expr {$$ = new Node(expr_t, "<="); $$->addBack($1); $$->addBack($3);}
	| greater_less_expr GE shift_expr {$$ = new Node(expr_t, ">="); $$->addBack($1); $$->addBack($3);}
	| greater_less_expr LT shift_expr {$$ = new Node(expr_t, "<"); $$->addBack($1); $$->addBack($3);}
	| greater_less_expr GT shift_expr {$$ = new Node(expr_t, ">"); $$->addBack($1); $$->addBack($3);}
	| shift_expr {$$ = $1;}
	;
	
shift_expr
	: shift_expr LSHIFT addBack_sub_expr {$$ = new Node(expr_t, "<<"); $$->addBack($1); $$->addBack($3);}
	| shift_expr RSHIFT addBack_sub_expr {$$ = new Node(expr_t, ">>"); $$->addBack($1); $$->addBack($3);}
	| addBack_sub_expr {$$ = $1;}
	;
	
addBack_sub_expr
	: addBack_sub_expr '+' mul_div_mod_expr {$$ = new Node(expr_t, "+"); $$->addBack($1); $$->addBack($3);}
	| addBack_sub_expr '-' mul_div_mod_expr {$$ = new Node(expr_t, "-"); $$->addBack($1); $$->addBack($3);}
	| mul_div_mod_expr {$$ = $1;}
	;
	
mul_div_mod_expr
	: mul_div_mod_expr '*' unary_expr {$$ = new Node(expr_t, "*"); $$->addBack($1); $$->addBack($3);}
	| mul_div_mod_expr '/' unary_expr {$$ = new Node(expr_t, "/"); $$->addBack($1); $$->addBack($3);}
	| mul_div_mod_expr '%' unary_expr {$$ = new Node(expr_t, "%"); $$->addBack($1); $$->addBack($3);}
	| unary_expr {$$ = $1;}
	;
	
unary_expr
	: unary_op unary_expr {$$ = $1; $$->addBack($2);}
	| postfix_expr {$$ = $1;}
	;
	
postfix_expr
	: postfix_expr '[' expr ']' {$$ = new Node(expr_t, "[ ]"); $$->addBack($1); $$->addBack($3);}
	| postfix_expr '(' expr ')' {$$ = new Node(expr_t, "( )"); $$->addBack($1); $$->addBack($3);}
	| postfix_expr '(' ')' {$$ = new Node(expr_t, "( )"); $$->addBack($1);}
	| postfix_expr INC {$$ = new Node(expr_t, "++"); $$->addBack($1);}
	| postfix_expr DEC {$$ = new Node(expr_t, "--"); $$->addBack($1);}
	| basic_expr {$$ = $1;}
	;

basic_expr
	: ID {$$ = $1;}
	| val {$$ = $1;}
	| '(' expr ')' {$$ = $2;}
	;

assign_op
	: '=' {$$ = new Node(expr_t, "=");}
	| ADDASSIGN {$$ = new Node(expr_t, "+=");}
	| SUBASSIGN {$$ = new Node(expr_t, "-=");}
	| MULASSIGN {$$ = new Node(expr_t, "*=");}
	| DIVASSIGN {$$ = new Node(expr_t, "/=");}
	| MODASSIGN {$$ = new Node(expr_t, "%=");}
	| ANDASSIGN {$$ = new Node(expr_t, "&=");}
	| ORASSIGN {$$ = new Node(expr_t, "|=");}
	| XORASSIGN {$$ = new Node(expr_t, "^=");}
	| REVASSIGN {$$ = new Node(expr_t, "~=");}
	| LSHIFTASSIGN {$$ = new Node(expr_t, "<<=");}
	| RSHIFTASSIGN {$$ = new Node(expr_t, ">>=");}
	;

unary_op
	: '+' {$$ = new Node(expr_t, "+");}
	| '-' {$$ = new Node(expr_t, "-");}
	| '~' {$$ = new Node(expr_t, "~");}
	| '!' {$$ = new Node(expr_t, "!");}
	| INC {$$ = new Node(expr_t, "++");}
	| DEC {$$ = new Node(expr_t, "--");}
	;

val
	: INTVAL {$$ = $1;}
	| CHARVAL {$$ = $1;}
	;
	
// statement

stmt
	: jmp_stmt {if (entered) returnScope(); $$ = $1;}
	| loop_stmt {if (entered) returnScope(); $$ = $1;}
	| expr_stmt {if (entered) returnScope(); $$ = $1;}
	| compound_stmt {$$ = $1;}
	| conditional_stmt {if (entered) returnScope(); $$ = $1;}
	;
	
jmp_stmt
	: RETURN expr ';' {$$ = new Node(return_stmt_t);}
	| RETURN ';' {$$ = new Node(return_stmt_t);}
	;

loop_stmt
	: WHILE '(' expr ')' stmt {$$ = new Node(while_stmt_t); $$->addBack($3); $$->addBack($5);}
	| DO stmt WHILE '(' expr ')' {$$ = new Node(dowhile_stmt_t); $$->addBack($2); $$->addBack($5);}
	| FOR '(' expr_stmt expr_stmt expr ')' stmt {$$ = new Node(for_stmt_t); $$->addBack($2); $$->addBack($3); $$->addBack($4); $$->addBack($6);}
	| FOR '(' expr_stmt expr_stmt ')' stmt {$$ = new Node(for_stmt_t); $$->addBack($2); $$->addBack($3); $$->addBack($5);}
	;

expr_stmt
	: expr ';' {$$ = $1;}
	| ';' {$$ = new Node(empty_stmt_t);}
	;
	
compound_stmt
	: '{' stmt_decl_list '}' {$$ = new Node(compound_stmt_t); $$->addBack($2); returnScope();}
	| '{' '}' {$$ = new Node(compound_stmt_t); returnScope();}
	;
	
conditional_stmt
	: IF '(' expr ')' stmt ELSE stmt {$$ = new Node(if_stmt_t); $$->addBack($3); $$->addBack($5); $$->addBack($7);}
	| IF '(' expr ')' stmt %prec NO_ELSE {$$ = new Node(if_stmt_t); $$->addBack($3); $$->addBack($5);}
	;
	
stmt_decl_list
	: stmt_decl_list stmt {$$ = new Node(stmt_decl_list_t); $$->addBack($1); $$->addBack($2);}
	| stmt_decl_list decl {$$ = new Node(stmt_decl_list_t); $$->addBack($1); $$->addBack($2);}
	| stmt {$$ = $1;}
	| decl {$$ = $1;}
	;
	
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(const char YYFAR* text) {
	cout << "Syntax error at: row(" << row_count << "), column(" << col_count << ")" << endl;
}

int main()
{
	tables.insert({root_table, table_count++});
	int n = 1;
	ifstream in("code.c");
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = &in;
			n = parser.yyparse();
		}
	}
	system("pause");
	return n;
}
