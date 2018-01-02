#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

// symbol table
// (name, type, category, storage)

enum SymbolType {	// category
	var_st, function_st,
};

enum Operator {
	comma_d,
	ternary_d,
	or_d, and_d,
	bit_or_d, bit_xor_d, bit_and_d,
	eq_d, ne_d,
	le_d, ge_d,
	lt_d, gt_d,
	lshift_d, rshift_d,
	add_d, sub_d,
	mul_d, div_d, mod_d,
	post_inc_d, post_dec_d,
	assign_d,
	addassign_d, subassign_d,
	mulassign_d, divassign_d, modassign_d,
	andassign_d, orassign_d, xorassign_d, revassign_d,
	lshiftassign_d, rshiftassign_d,
	pos_d, neg_d, rev_d, not_d,
	pre_inc_d, pre_dec_d,
};

enum NodeValType {
	void_vt,
	int_vt,
	char_vt,
	bool_vt,
};

struct SymbolEntry {
	NodeValType val_type;	// symbol value type (int, char)
	SymbolType category;	// symbol category (var, func)
	SymbolEntry(NodeValType, SymbolType);
};

extern bool entered; // check if already entered subscope before compound statement

extern unordered_map<Operator, string> op_converter;
extern unordered_map<SymbolType, string> st_translator;
extern unordered_map<string, NodeValType> vt_converter;

class SymbolTable { // (name -- entry)
public:
	void setFather(SymbolTable *);
	SymbolTable * getFather();
	SymbolEntry * find(string);
	void insert(string, SymbolEntry *);
	void output(unsigned int) const;
private:
	unordered_map<string, SymbolEntry *> table;
	SymbolTable * father;
};

extern SymbolTable * root_table, * curr_table;
extern unordered_map<SymbolTable *, unsigned int> tables;
extern unsigned int table_count;

// grammar tree

enum NodeType {
	program_t,
	type_t,
	expr_t,
	assign_expr_t,
	ternary_expr_t,
	logical_expr_t,
	calc_expr_t,
	comp_expr_t,
	unary_expr_t,
	post_expr_t,
	temp_expr_t,
	idt_t,
	ival_t,
	cval_t,
	decl_group_t,
	decl_t,
	decl_list_t,
	idt_list_t,
	func_t,
	while_stmt_t,
	dowhile_stmt_t,
	for_stmt_t,
	if_stmt_t,
	empty_stmt_t,
	compound_stmt_t,
	stmt_decl_list_t,
};

union NodeData {
	int int_v;	// integer value
	char * string_v;	// character value, id name, type name
	Operator op_v;	// operator
};

union Label {
	struct {
		string begin_lb;
		string next_lb;
	};
	struct {
		string true_lb;
		string false_lb;
	};
};

class Node {
public:
	Node(NodeType, Node * child1 = NULL, Node * child2 = NULL, Node * child3 = NULL, Node * child4 = NULL);
	Node(NodeType, int, Node * child1 = NULL, Node * child2 = NULL, Node * child3 = NULL, Node * child4 = NULL);
	Node(NodeType, char *, Node * child1 = NULL, Node * child2 = NULL, Node * child3 = NULL, Node * child4 = NULL);
	Node(NodeType, Operator, Node * child1 = NULL, Node * child2 = NULL, Node * child3 = NULL, Node * child4 = NULL);
	unsigned int traverse() const;
	SymbolEntry * symbolCheck(string) const;
	void addChild(Node *);
	void exprTypeCheck();
	void stmtTypeCheck();
	void typeError(const char *) const;
	bool checkID(Node *) const;
	NodeType type;
	NodeValType val_type;
	NodeData data;
	vector<Node *> children;
	SymbolTable * table;
	SymbolEntry * entry;
	unsigned int row, col;
};

extern unsigned int row_count, col_count;

// traverse

extern unsigned int node_id;
extern unordered_map<NodeType, string> term_table;

// tree
class Tree {
public:
	Tree(Node *);
	void gen_label();
private:
	Node * root;
};