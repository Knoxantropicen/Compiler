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
// (name, type, category, storage)

enum SymbolType {	// category
	var_st, array_st, function_st,
};

enum Descriptor {	// basic type
	void_d,
	int_d,
	char_d,
};

union Storage {
	vector<Descriptor> * func_params;	// function parameter list
	unsigned int array_dim;	// array dimension
};

struct SymbolEntry {
	Descriptor type;
	SymbolType category;	// symbol category
	Storage storage;	// specific storage
	SymbolEntry(Descriptor, SymbolType, vector<Descriptor> *);
	SymbolEntry(Descriptor, SymbolType, unsigned int);
};

struct GIV { // global intermediate variables
	Descriptor g_type;
	SymbolType g_cate;
	vector<Descriptor> g_param_list;
	unsigned int g_dim;
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
	void setType(string, Descriptor);
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
	blocks_t,
	type_t,
	expr_t,
	idt_t,
	ival_t,
	cval_t,
	decl_t,
	decl_head_t,
	decl_list_t,
	init_val_t,
	param_list_t,
	param_t,
	idt_list_t,
	func_t,
	return_stmt_t,
	while_stmt_t,
	dowhile_stmt_t,
	for_stmt_t,
	if_stmt_t,
	empty_stmt_t,
	compound_stmt_t,
	stmt_decl_list_t,
};

union NodeData {
	int int_v;
	char * string_v;
};

class Node {
public:
	Node(NodeType);
	Node(NodeType, char *);
	Node(NodeType, int);
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