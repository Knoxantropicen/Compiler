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

void recrSetEnumTypeName(Node * node, string new_name) {
	if (node->getType() == e_decl_t) {
		curr_table->getFather()->setTypeName(node->getChild(0)->getString(), new_name);
		return;
	}
	for (unsigned int i = 0; i < node->getChildrenSize(); ++i)
		recrSetEnumTypeName(node->getChild(i), new_name);
}

void enumTypeInsertEntry(Node * type_name_node, Node * member_list_node) {
	if (member_list_node == NULL)
		type_name_node->setEntry(new SymbolEntry(SfUnit(enum_d), vector<PtUnit>(), type_name_st, new SymbolTable()));
	else 
		type_name_node->setEntry(new SymbolEntry(SfUnit(enum_d), vector<PtUnit>(), type_name_st, member_list_node->getTable()));
	curr_table->insert(type_name_node->getString(), type_name_node->getEntry());
}

void enumVarInsertEntry(Node * var_id) {
	var_id->setTable(curr_table->getFather());
	var_id->setEntry(new SymbolEntry(SfUnit(enum_d), vector<PtUnit>(), var_st, ""));
	var_id->getTable()->insert(var_id->getString(), var_id->getEntry());
}

void declInsertEntry(Node * var_id) {
	if (var_id->getType() == idt_t) {
		var_id->setEntry(new SymbolEntry(giv.g_sf, giv.g_pt_list, giv.g_cate, giv.g_dim));
		var_id->getTable()->insert(var_id->getString(), var_id->getEntry());
		giv.g_pt_list = vector<PtUnit>();
		giv.g_cate = var_st;
		giv.g_dim = 0;
		return;
	}
	declInsertEntry(var_id->getChild(0));
}

void customTypeInsertEntry(string name, SymbolTable * table) {	// store SymbolTable *
	curr_table->insert(name, new SymbolEntry(giv.g_sf, giv.g_pt_list, type_name_st, table));
	Descriptor d = giv.g_sf.type;
	giv.g_sf = SfUnit();
	giv.g_sf.type = d;
	giv.g_pt_list = vector<PtUnit>();
}

void anonyCustomTypeInsertEntry(char * anony_name, SymbolTable * table) {
	curr_table->insert(string(anony_name), new SymbolEntry(giv.g_sf, giv.g_pt_list, type_name_st, table));
	Descriptor d = giv.g_sf.type;
	giv.g_sf = SfUnit();
	giv.g_sf.type = d;
	giv.g_pt_list = vector<PtUnit>();
}

void funcInsertEntry(Node * func_id) {
	func_id->setTable(curr_table->getFather());
	func_id->setEntry(new SymbolEntry(SfUnit(), vector<PtUnit>(), function_st, &giv.g_param_list));
	func_id->getTable()->insert(func_id->getString(), func_id->getEntry());
}

void funcSetEntry(Node * func_head) {
	Node * func_id = func_head->getChild(0);
	func_id->getTable()->setSfPt(func_id->getString(), giv.g_sf, giv.g_pt_list);
	giv.g_sf = SfUnit();
	giv.g_pt_list = vector<PtUnit>();
}

void addParamList() {
	giv.g_param_list.push_back(SfPtDimUnit(giv.g_sf, giv.g_pt_list, giv.g_dim));
	giv.g_sf = SfUnit();
	giv.g_pt_list = vector<PtUnit>();
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
	cout << "giv.g_sf: " << giv.g_sf.const_e << " " << giv.g_sf.volatile_e << " " << d_converter[giv.g_sf.type] << endl;
	cout << "giv.g_pt: ";
	for (auto it: giv.g_pt_list) {
		cout << it.const_e << " " << it.volatile_e << " | ";
	}
	cout << endl << "giv.g_cate: " << giv.g_cate << endl;
	cout << "giv.g_dim: " << giv.g_dim << endl;
	cout << "giv.g_type_name: " << giv.g_type_name << endl;
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
%token VOID INT FLOAT DOUBLE CHAR BOOL STRING
%token AUTO
%token STRUCT UNION ENUM
%token CONST VOLATILE
%token SIZEOF
%token GOTO BREAK CONTINUE RETURN
%token WHILE DO FOR
%token IF SWITCH CASE DEFAULT
%nonassoc NO_ELSE
%nonassoc ELSE
%token ADDASSIGN SUBASSIGN MULASSIGN DIVASSIGN MODASSIGN
%token ANDASSIGN ORASSIGN XORASSIGN REVASSIGN
%token LSHIFTASSIGN RSHIFTASSIGN
%token OR AND
%token EQ NE LE GE LT GT
%token INC DEC
%token PT
%token LSHIFT RSHIFT
%token INTVAL DOUBLEVAL BOOLVAL CHARVAL STRINGVAL
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
	: VOID {$$ = new Node(type_sf_t, "void");}
	| INT {$$ = new Node(type_sf_t, "integer");}
	| FLOAT {$$ = new Node(type_sf_t, "float");}
	| DOUBLE {$$ = new Node(type_sf_t, "double");}
	| CHAR {$$ = new Node(type_sf_t, "character");}
	| BOOL {$$ = new Node(type_sf_t, "boolean");}
	| STRING {$$ = new Node(type_sf_t, "string");}
	| AUTO {$$ = new Node(type_sf_t, "auto");}
	| struct_union_type {$$ = $1;}
	| enum_type {$$ = $1;}
	;

type_qf_for_sf
	: CONST {$$ = new Node(type_qf_t, "const"); giv.g_sf.const_e = true;}
	| VOLATILE {$$ = new Node(type_qf_t, "volatile"); giv.g_sf.volatile_e = true;}
	;

type_qf_for_pt
	: CONST {$$ = new Node(type_qf_t, "const"); giv.g_pt.const_e = true;}
	| VOLATILE {$$ = new Node(type_qf_t, "volatile"); giv.g_pt.volatile_e = true;}
	;
	
struct_union_type
	: struct_union ID '{' struct_union_decl_list '}' {$$ = new Node(su_type_sf_t, $1->getCharP()); $2->setType(type_name_t); $$->addBack($1); $$->addBack($2); $$->addBack($4);
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		customTypeInsertEntry($2->getString(), $4->getTable());}
	| struct_union '{' struct_union_decl_list '}' {$$ = new Node(su_type_sf_t, $1->getCharP()); $$->addBack($1); char * anony_name = curr_table->getAnony(); $$->addBack(new Node(anony_idt_t, anony_name)); $$->addBack($3);
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		anonyCustomTypeInsertEntry(anony_name, $3->getTable());}
	| struct_union ID '{' '}' {$$ = new Node(su_type_sf_t, $1->getCharP()); $2->setType(type_name_t); $$->addBack($1); $$->addBack($2);
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		customTypeInsertEntry($2->getString(), NULL);}
	| struct_union '{' '}' {$$ = new Node(su_type_sf_t, $1->getCharP()); $$->addBack($1); char * anony_name = curr_table->getAnony(); $$->addBack(new Node(anony_idt_t, anony_name));
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		anonyCustomTypeInsertEntry(anony_name, NULL);}
	| struct_union ID {$$ = new Node(su_type_sf_t, $1->getCharP()); $2->setType(type_name_t); $$->addBack($1); $$->addBack($2);
		giv.g_sf.type = g_converter[$1->getString()];
		customTypeInsertEntry($2->getString(), NULL);}
	;
	
struct_union
	: STRUCT {$$ = new Node(type_sf_t, "struct");}
	| UNION {$$ = new Node(type_sf_t, "union");}
	;
	
enum_type
	: enum ID '{' enum_decl_list '}' {$$ = $1; $2->setType(type_name_t); $$->addBack($2); $$->addBack($4); 
		recrSetEnumTypeName($4, $2->getString());
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		enumTypeInsertEntry($2, $4);}
	| enum '{' enum_decl_list '}' {$$ = $1; char * anony_name = curr_table->getAnony(); $$->addBack(new Node(anony_idt_t, anony_name)); $$->addBack($3);
		recrSetEnumTypeName($3, string(anony_name));
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		enumTypeInsertEntry($$->getChild(0), $3);}
	| enum ID '{' '}' {$$ = $1; $2->setType(type_name_t); $$->addBack($2);
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		enumTypeInsertEntry($2, NULL);}
	| enum '{' '}' {$$ = $1; char * anony_name = curr_table->getAnony(); $$->addBack(new Node(anony_idt_t, anony_name));
		returnScope(); giv.g_sf.type = g_converter[$1->getString()];
		enumTypeInsertEntry($$->getChild(0), NULL);}
	| enum ID {$$ = $1; $2->setType(type_name_t); $$->addBack($2);
		enumTypeInsertEntry($2, NULL);}
	;

enum
	: ENUM {$$ = new Node(e_type_sf_t, "enum");}
	;
	
pointer
	: pointer type_qf_for_pt {$$ = new Node(idt_sf_t); $$->addBack($1); $$->addBack($2);}
	| pointer '*' {$$ = new Node(idt_sf_t); $2 = new Node(ptr_t, "pointer"); $$->addBack($1); $$->addBack($2); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();}
	| '*' {$$ = new Node(ptr_t, "pointer"); giv.g_pt = PtUnit();}
	;
	
// declaration

decl
	: decl_sf decl_list ';' {$$ = new Node(decl_t); $$->addBack($1); $$->addBack($2); giv.g_sf = SfUnit();}
	| decl_sf ';' {$$ = new Node(decl_t); $$->addBack($1); giv.g_sf = SfUnit();}
	;
	
decl_sf
	: decl_sf type {$$ = new Node(type_t); $$->addBack($1); $$->addBack($2); // incomplete
		if (giv.g_sf.type == default_d) giv.g_sf.type = g_converter[$2->getString()]; else { cout << "Duplicate type!" << endl; system("pause");}}
	| decl_sf type_qf_for_sf {$$ = new Node(type_t); $$->addBack($1); $$->addBack($2);}
	| type {$$ = $1; giv.g_sf.type = g_converter[$1->getString()];}
	| type_qf_for_sf {$$ = $1;}
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
	: pointer var_decl_head {$$ = $2; $$->addFront($1); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
		declInsertEntry($2);}
	| var_decl_head {$$ = $1; declInsertEntry($1);}
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
	: decl_sf decl_init {$$ = new Node(param_t); $$->addBack($1); $$->addBack($2);}
	| decl_sf pointer {$$ = new Node(param_t); $$->addBack($1); $$->addBack($2); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();}
	| decl_sf {$$ = new Node(param_t); $$->addBack($1);}
	;

struct_union_decl_list 
	: struct_union_decl_list struct_union_decl {$$ = new Node(su_decl_list_t); $$->addBack($1); $$->addBack($2);}
	| struct_union_decl {$$ = $1;}
	;

struct_union_decl
	: decl_sf pointer ID '=' const_expr ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($2); $$->addBack($3); $$->addBack($5);
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();}
	| decl_sf ID '=' const_expr ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($3);}
	| decl_sf pointer ID ':' const_expr ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($2); $$->addBack($3); $$->addBack($5);
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();}
	| decl_sf ID ':' const_expr ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($3);}
	| decl_sf pointer ID ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($2); $$->addBack($3);
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();}
	| decl_sf ID ';' {$$ = new Node(su_decl_t); $$->addBack($1); $$->addBack($2);}
	;
	
enum_decl_list
	: enum_decl_list ',' enum_decl {$$ = new Node(e_decl_list_t); $$->addBack($1); $$->addBack($3);}
	| enum_decl {$$ = $1;}
	;

enum_decl
	: ID '=' const_expr {$$ = new Node(e_decl_t); $$->addBack($1); $$->addBack($3);
		enumVarInsertEntry($1);}
	| ID {$$ = new Node(e_decl_t); $$->addBack($1);
		enumVarInsertEntry($1);}
	;
	
// function

func
	: decl_sf pointer func_decl_head compound_stmt {$$ = new Node(func_t); $$->addBack($1); $$->addBack($2); $$->addBack($3); $$->addBack($4);
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit(); funcSetEntry($3);}
	| decl_sf func_decl_head compound_stmt {$$ = new Node(func_t); $$->addBack($1); $$->addBack($2); $$->addBack($3);
		funcSetEntry($2);}
	| func_decl_head compound_stmt {$$ = new Node(func_t); $$->addBack($1); $$->addBack($2);
		funcSetEntry($1);}
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
	: unary_op cast_expr {$$ = $1; $$->addBack($2);}
	| INC unary_expr {$$ = new Node(expr_t, "++"); $$->addBack($2);}
	| DEC unary_expr {$$ = new Node(expr_t, "--"); $$->addBack($2);}
	| SIZEOF '(' expr ')' {$$ = new Node(expr_t, "sizeof( )"); $$->addBack($3);}
	| SIZEOF '(' type ')' {$$ = new Node(expr_t, "sizeof( )"); $$->addBack($3);}
	| postfix_expr {$$ = $1;}
	;
	
cast_expr
	: '(' type ')' cast_expr {$$ = new Node(expr_t, "( )"); $$->addBack($2); $$->addBack($4);}
	| unary_expr {$$ = $1;}
	;
	
postfix_expr
	: postfix_expr '[' expr ']' {$$ = new Node(expr_t, "[ ]"); $$->addBack($1); $$->addBack($3);}
	| postfix_expr '(' expr ')' {$$ = new Node(expr_t, "( )"); $$->addBack($1); $$->addBack($3);}
	| postfix_expr '(' ')' {$$ = new Node(expr_t, "( )"); $$->addBack($1);}
	| postfix_expr '.' ID {$$ = new Node(expr_t, "."); $$->addBack($1); $$->addBack($3);}
	| postfix_expr PT ID {$$ = new Node(expr_t, "->"); $$->addBack($1); $$->addBack($3);}
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
	: '*' {$$ = new Node(expr_t, "*");}
	| '&' {$$ = new Node(expr_t, "&");}
	| '+' {$$ = new Node(expr_t, "+");}
	| '-' {$$ = new Node(expr_t, "-");}
	| '~' {$$ = new Node(expr_t, "~");}
	| '!' {$$ = new Node(expr_t, "!");}
	;

val
	: INTVAL {$$ = $1;}
	| DOUBLEVAL {$$ = $1;}
	| BOOLVAL {$$ = $1;}
	| CHARVAL {$$ = $1;}
	| STRINGVAL {$$ = $1;}
	;
	
// statement

stmt
	: jmp_stmt {if (entered) returnScope(); $$ = $1;}
	| loop_stmt {if (entered) returnScope(); $$ = $1;}
	| expr_stmt {if (entered) returnScope(); $$ = $1;}
	| label_stmt {if (entered) returnScope(); $$ = $1;}
	| compound_stmt {$$ = $1;}
	| conditional_stmt {if (entered) returnScope(); $$ = $1;}
	;
	
jmp_stmt
	: GOTO ID ';' {$$ = new Node(goto_stmt_t); $$->addBack($2);}
	| BREAK ';' {$$ = new Node(break_stmt_t);}
	| CONTINUE ';' {$$ = new Node(continue_stmt_t);}
	| RETURN expr ';' {$$ = new Node(return_stmt_t);}
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
	
label_stmt
	: CASE const_expr ':' stmt {$$ = new Node(case_stmt_t); $$->addBack($2); $$->addBack($4);}
	| DEFAULT ':' stmt {$$ = new Node(default_stmt_t); $$->addBack($3);}
	| ID ':' stmt {$$ = new Node(label_stmt_t); $$->addBack($1); $$->addBack($3);}
	;
	
compound_stmt
	: '{' stmt_decl_list '}' {$$ = new Node(compound_stmt_t); $$->addBack($2); returnScope();}
	| '{' '}' {$$ = new Node(compound_stmt_t); returnScope();}
	;
	
conditional_stmt
	: IF '(' expr ')' stmt ELSE stmt {$$ = new Node(if_stmt_t); $$->addBack($3); $$->addBack($5); $$->addBack($7);}
	| IF '(' expr ')' stmt %prec NO_ELSE {$$ = new Node(if_stmt_t); $$->addBack($3); $$->addBack($5);}
	| SWITCH '(' expr ')' stmt {$$ = new Node(switch_stmt_t); $$->addBack($3); $$->addBack($5);}
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
