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
	entered = false;
	tables.insert({curr_table, table_count++});
	curr_table = curr_table->getFather();
}

void declInsertEntry(Node * var_id, NodeValType val_type) {
	if (var_id->type == idt_t) {
		var_id->entry = new SymbolEntry(val_type, var_st);
		var_id->table->insert(string(var_id->data.string_v), var_id->entry);
		var_id->index = var_count++;
		var_id->val_type = val_type;
		return;
	}
	for (unsigned int i = 0; i < var_id->children.size(); ++i) {
		declInsertEntry(var_id->children[i], val_type);
	}
}

// void funcInsertEntry() {
// 	curr_table->insert("main", new SymbolEntry(int_vt, function_st));
// }

void outputTables() {
	for (auto it: tables) {
		it.first->output(it.second);
	}
}

void debug() {
	cout << "Debug Info:" << endl;
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
%token INT CHAR
%token WHILE FOR
%token IF
%nonassoc NO_ELSE
%nonassoc ELSE
%token MAIN
%token INPUT PRINT
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
	: decl_list func {root_node = new Node(program_t, $1, $2);}
	| func {root_node = new Node(program_t, $1);}
	;

// data type
	
type
	: INT {$$ = new Node(type_t, "integer");}
	| CHAR {$$ = new Node(type_t, "character");}
	;

// declaration

decl_list
	: decl_list decl {$$ = new Node(decl_list_t, $1, $2);}
	| decl {$$ = $1;}
	;

decl
	: type id_list ';' {$$ = new Node(decl_t, $1, $2); declInsertEntry($2, vt_converter[string($1->data.string_v)]);}
	| type ';' {$$ = new Node(decl_t, $1);}
	;
	
id_list
	: id_list ',' ID {$$ = new Node(idt_list_t, $1, $3);}
	| ID {$$ = $1;}
	;
	
// function (main)

func
	: INT MAIN '(' ')' compound_stmt {$$ = new Node(func_t, new Node(type_t, "integer"), $5);}
	| MAIN '(' ')' compound_stmt {$$ = new Node(func_t, new Node(type_t, "integer"), $4);}
	;

// expression

expr
	: expr ',' assign_expr {$$ = $1; $$->children.push_back($3);}
	| assign_expr {$$ = $1;}
	;
	
assign_expr
	: ID assign_op assign_expr {$1->val_type = $1->symbolCheck(string($1->data.string_v))->val_type; $$ = new Node(assign_expr_t, $2->data.op_v, $1, $3);}
	| const_expr {$$ = $1;}
	;
	
const_expr
	: ternary_expr {$$ = $1;}
	;

ternary_expr
	: or_expr '?' assign_expr ':' assign_expr {$$ = new Node(ternary_expr_t, ternary_d, $1, $2, $3);}
	| or_expr {$$ = $1;}
	;	
	
or_expr
	: or_expr OR and_expr {$$ = new Node(logical_expr_t, or_d, $1, $3);}
	| and_expr {$$ = $1;}
	;
	
and_expr
	: and_expr AND bit_or_expr {$$ = new Node(logical_expr_t, and_d, $1, $3);}
	| bit_or_expr {$$ = $1;}
	;

bit_or_expr
	: bit_or_expr '|' bit_xor_expr {$$ = new Node(calc_expr_t, bit_or_d, $1, $3);}
	| bit_xor_expr {$$ = $1;}
	;
	
bit_xor_expr
	: bit_xor_expr '^' bit_and_expr {$$ = new Node(calc_expr_t, bit_xor_d, $1, $3);}
	| bit_and_expr {$$ = $1;}
	;
	
bit_and_expr
	: bit_and_expr '&' equal_expr {$$ = new Node(calc_expr_t, bit_and_d, $1, $3);}
	| equal_expr {$$ = $1;}
	;
	
equal_expr
	: equal_expr EQ greater_less_expr {$$ = new Node(comp_expr_t, eq_d, $1, $3);}
	| equal_expr NE greater_less_expr {$$ = new Node(comp_expr_t, ne_d, $1, $3);}
	| greater_less_expr {$$ = $1;}
	;
	
greater_less_expr
	: greater_less_expr LE shift_expr {$$ = new Node(comp_expr_t, le_d, $1, $3);}
	| greater_less_expr GE shift_expr {$$ = new Node(comp_expr_t, ge_d, $1, $3);}
	| greater_less_expr LT shift_expr {$$ = new Node(comp_expr_t, lt_d, $1, $3);}
	| greater_less_expr GT shift_expr {$$ = new Node(comp_expr_t, gt_d, $1, $3);}
	| shift_expr {$$ = $1;}
	;
	
shift_expr
	: shift_expr LSHIFT add_sub_expr {$$ = new Node(calc_expr_t, lshift_d, $1, $3);}
	| shift_expr RSHIFT add_sub_expr {$$ = new Node(calc_expr_t, rshift_d, $1, $3);}
	| add_sub_expr {$$ = $1;}
	;
	
add_sub_expr
	: add_sub_expr '+' mul_div_mod_expr {$$ = new Node(calc_expr_t, add_d, $1, $3);}
	| add_sub_expr '-' mul_div_mod_expr {$$ = new Node(calc_expr_t, sub_d, $1, $3);}
	| mul_div_mod_expr {$$ = $1;}
	;
	
mul_div_mod_expr
	: mul_div_mod_expr '*' unary_expr {$$ = new Node(calc_expr_t, mul_d, $1, $3);}
	| mul_div_mod_expr '/' unary_expr {$$ = new Node(calc_expr_t, div_d, $1, $3);}
	| mul_div_mod_expr '%' unary_expr {$$ = new Node(calc_expr_t, mod_d, $1, $3);}
	| unary_expr {$$ = $1;}
	;
	
unary_expr
	: unary_op unary_expr {$$ = new Node(unary_expr_t, $1->data.op_v, $2);}
	| postfix_expr {$$ = $1;}
	;
	
postfix_expr
	: postfix_expr INC {$$ = new Node(post_expr_t, post_inc_d, $1);}
	| postfix_expr DEC {$$ = new Node(post_expr_t, post_dec_d, $1);}
	| basic_expr {$$ = $1;}
	;

basic_expr
	: ID {$$ = $1; $$->val_type = $$->symbolCheck(string($$->data.string_v))->val_type;}
	| val {$$ = $1;}
	| '(' expr ')' {$$ = $2;}
	;

assign_op
	: '=' {$$ = new Node(temp_expr_t, assign_d);}
	| ADDASSIGN {$$ = new Node(temp_expr_t, addassign_d);}
	| SUBASSIGN {$$ = new Node(temp_expr_t, subassign_d);}
	| MULASSIGN {$$ = new Node(temp_expr_t, mulassign_d);}
	| DIVASSIGN {$$ = new Node(temp_expr_t, divassign_d);}
	| MODASSIGN {$$ = new Node(temp_expr_t, modassign_d);}
	| ANDASSIGN {$$ = new Node(temp_expr_t, andassign_d);}
	| ORASSIGN {$$ = new Node(temp_expr_t, orassign_d);}
	| XORASSIGN {$$ = new Node(temp_expr_t, xorassign_d);}
	| REVASSIGN {$$ = new Node(temp_expr_t, revassign_d);}
	| LSHIFTASSIGN {$$ = new Node(temp_expr_t, lshiftassign_d);}
	| RSHIFTASSIGN {$$ = new Node(temp_expr_t, rshiftassign_d);}
	;

unary_op
	: '+' {$$ = new Node(temp_expr_t, pos_d);}
	| '-' {$$ = new Node(temp_expr_t, neg_d);}
	| '~' {$$ = new Node(temp_expr_t, rev_d);}
	| '!' {$$ = new Node(temp_expr_t, not_d);}
	| INC {$$ = new Node(temp_expr_t, pre_inc_d);}
	| DEC {$$ = new Node(temp_expr_t, pre_dec_d);}
	;

val
	: INTVAL {$$ = $1;}
	| CHARVAL {$$ = $1;}
	;
	
// statement

stmt
	: loop_stmt {if (entered) returnScope(); $$ = $1;}
	| expr_stmt {$$ = $1;}
	| compound_stmt {$$ = $1;}
	| conditional_stmt {if (entered) returnScope(); $$ = $1;}
	| io_stmt {$$ = $1;}
	;

loop_stmt
	: WHILE '(' expr ')' stmt {$$ = new Node(while_stmt_t, $3, $5);}
	| FOR '(' expr_stmt expr_stmt expr ')' stmt {$$ = new Node(for_stmt_t, $3, $4, $7, $5);}
	| FOR '(' expr_stmt expr_stmt ')' stmt {$$ = new Node(for_stmt_t, $3, $4, $6);}
	;

expr_stmt
	: expr ';' {$$ = $1;}
	| ';' {$$ = new Node(empty_stmt_t);}
	;
	
compound_stmt
	: '{' decl_list stmt_list '}' {$$ = new Node(compound_stmt_t, $2, $3); returnScope();}
	| '{' decl_list '}' {$$ = new Node(compound_stmt_t, $2); returnScope();}
	| '{' stmt_list '}' {$$ = new Node(compound_stmt_t, $2); returnScope();}
	| '{' '}' {$$ = new Node(compound_stmt_t); returnScope();}
	;
	
conditional_stmt
	: IF '(' expr ')' stmt ELSE stmt {$$ = new Node(if_else_stmt_t, $3, $5, $7);}
	| IF '(' expr ')' stmt %prec NO_ELSE {$$ = new Node(if_stmt_t, $3, $5);}
	;

io_stmt
	: INPUT '(' ID ')' ';' {$3->val_type = $3->symbolCheck(string($3->data.string_v))->val_type; $$ = new Node(input_stmt_t, $3);}
	| PRINT '(' ID ')' ';' {$3->val_type = $3->symbolCheck(string($3->data.string_v))->val_type; $$ = new Node(print_stmt_t, $3);}
	;
	
stmt_list
	: stmt_list stmt {$$ = new Node(stmt_list_t, $1, $2);}
	| stmt {$$ = $1;}
	;
	
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(const char YYFAR* text) {
	cerr << "Syntax error at: row(" << row_count << "), column(" << col_count << ")" << endl;
}

int main()
{
	tables.insert({root_table, table_count++});
	int n = 1;
	ifstream * in = new ifstream("code.c");
	ofstream * out = new ofstream("code.asm");
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = in;

			n = parser.yyparse();
			
			cout << "Grammar Tree:" << endl;
			root_node->traverse();
			cout << endl;
			
			outputTables();
			cout << endl;
			
			Tree tree(root_node);
			tree.gen_label();

			tree.gen_code(*out);
		}
	}
	in->close();
	out->close();
	system("pause");
	return n;
}
