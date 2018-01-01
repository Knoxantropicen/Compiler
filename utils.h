#pragma once
#include <string>
#include <unordered_map>
#include <deque>
#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// symbol table
// (name, st_type, pt_type, category, storage)

enum SymbolType {	// category
	var_st, array_st, function_st, type_name_st,
};

enum Descriptor {	// basic unit of sf_type and pt_type
	default_d,
	void_d,
	int_d,
	float_d,
	double_d,
	char_d,
	bool_d,
	string_d,
	auto_d,
	struct_d,
	union_d,
	enum_d,
	array_d,
};

struct SfUnit {	// check if const/volatile exists and record basic type
	bool const_e;
	bool volatile_e;
	Descriptor type;
	SfUnit();
	SfUnit(Descriptor);
};

struct PtUnit {	// check if const/volatile exists
	bool const_e;
	bool volatile_e;
	PtUnit();
};

struct SfPtDimUnit { // parameter type in function
	SfUnit p_sf_type;
	vector<PtUnit> p_pt_type;
	unsigned int p_array_dim;
	SfPtDimUnit(SfUnit, vector<PtUnit>, unsigned int);
};

union Storage {
	class SymbolTable * type_table;	// struct/union type: corresponding symbol table for that type
	vector<SfPtDimUnit> * func_params;	// function parameter list
	unsigned int array_dim;	// array dimension
	char * type_name;	// struct/union/enum variable: corresponding type name
};

struct SymbolEntry {
	SfUnit sf_type;	// specifier type
	vector<PtUnit> pt_type;	// pointer type
	SymbolType category;	// symbol category
	Storage storage;	// specific storage
	SymbolEntry(SfUnit, vector<PtUnit>, SymbolType, SymbolTable *);
	SymbolEntry(SfUnit, vector<PtUnit>, SymbolType, vector<SfPtDimUnit> *);
	SymbolEntry(SfUnit, vector<PtUnit>, SymbolType, unsigned int);
	SymbolEntry(SfUnit, vector<PtUnit>, SymbolType, string);
};

struct GIV { // global intermediate variables
	SfUnit g_sf;
	PtUnit g_pt;
	SymbolType g_cate;
	vector<PtUnit> g_pt_list;
	vector<SfPtDimUnit> g_param_list;
	unsigned int g_dim;
	string g_type_name;
	GIV();
};

extern stack<GIV> giv_stack;
extern GIV giv;
extern bool entered; // check if already entered subscope before compound statement

extern unordered_map<string, Descriptor> g_converter;
extern unordered_map<Descriptor, string> d_converter;
extern unordered_map<SymbolType, string> st_converter;

class SymbolTable { // (name -- entry)
public:
	void setFather(SymbolTable *);
	SymbolTable * getFather();
	bool find(string) const;
	void insert(string, SymbolEntry *);
	void setSfPt(string, SfUnit, vector<PtUnit>);
	void setTypeName(string, string);
	char * getAnony(); // get anonymous type name and insert
	void output(unsigned int) const;
private:
	unordered_map<string, SymbolEntry *> table;
	SymbolTable * father;
	int anonymous_name_count;
};

extern SymbolTable * root_table, * curr_table;
extern unordered_map<SymbolTable *, unsigned int> tables;
extern unsigned int table_count;

// grammar tree

enum NodeType {
	blocks_t,
	type_sf_t,
	type_qf_t,
	type_t,
	type_name_t,
	expr_t,
	idt_t,
	ival_t,
	dval_t,
	bval_t,
	sval_t,
	su_type_sf_t,
	e_type_sf_t,
	ptr_t,
	decl_t,
	idt_sf_t,
	decl_head_t,
	decl_list_t,
	init_val_t,
	param_list_t,
	param_t,
	idt_list_t,
	su_decl_list_t,
	su_decl_t,
	e_decl_list_t,
	e_decl_t,
	func_t,
	goto_stmt_t,
	break_stmt_t,
	continue_stmt_t,
	return_stmt_t,
	while_stmt_t,
	dowhile_stmt_t,
	for_stmt_t,
	if_stmt_t,
	switch_stmt_t,
	empty_stmt_t,
	label_stmt_t,
	case_stmt_t,
	default_stmt_t,
	compound_stmt_t,
	stmt_decl_list_t,
	anony_idt_t,
};

union NodeData {
	int int_v;
	double double_v;
	bool bool_v;
	char * string_v;
};

class Node {
public:
	Node(NodeType);
	Node(NodeType, char *);
	Node(NodeType, int);
	Node(NodeType, double);
	Node(NodeType, bool);
	void addBack(Node *);	// add child
	void addFront(Node *);	// add child
	NodeType getType() const;
	void setType(NodeType);
	char * getCharP() const;	// be cautious
	string getString() const;	// be cautious
	SymbolTable * getTable() const;
	SymbolEntry * getEntry() const;
	void setTable(SymbolTable *);
	void setEntry(SymbolEntry *);
	Node * getChild(unsigned int) const;
	unsigned int getChildrenSize() const;
	const unsigned int traverse();
	const void printTree(unsigned int);
private:
	NodeType type;
	NodeData data;
	deque<Node *> children;
	SymbolTable * table;
	SymbolEntry * entry;
	unsigned int row, col;
};

extern unsigned int row_count, col_count;

// traverse

extern unsigned int node_id;
extern unordered_map<NodeType, string> term_table;