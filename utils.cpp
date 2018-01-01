#include "utils.h"

// symbol table

SymbolEntry::SymbolEntry(Descriptor init_type, SymbolType init_cate, vector<Descriptor> * init_store): type(init_type), category(init_cate) {
	storage.func_params = new vector<Descriptor>(); for (auto i: * init_store) storage.func_params->push_back(i);}
SymbolEntry::SymbolEntry(Descriptor init_type, SymbolType init_cate, unsigned int init_store): type(init_type), category(init_cate) {storage.array_dim = init_store;}

GIV::GIV(): g_type(int_d), g_cate(var_st), g_param_list(vector<Descriptor>()), g_dim(0) {}

stack<GIV> giv_stack;
GIV giv;
bool entered = false;

unordered_map<Descriptor, string> d_converter({
	{void_d, "void"},
	{int_d, "int"},
	{char_d, "char"},
});

unordered_map<SymbolType, string> st_converter({
	{var_st, "variable"},
	{array_st, "array"},
	{function_st, "function"},
});

void SymbolTable::setFather(SymbolTable * father_table) {
	father = father_table;
}

SymbolTable * SymbolTable::getFather() {
	return father;
}

bool SymbolTable::find(string id) const {
	if (table.find(id) != table.end()) return true;
	else if (father != NULL && father->find(id)) return true;
	else return false;
}

void SymbolTable::insert(string id, SymbolEntry * entry) {
	if (find(id)) {
		cout << "Symbol already declared" << endl;
		system("pause");
		return;
	}
	table.insert({id, entry});
}

void SymbolTable::setType(string id, Descriptor new_type) {
	if (!find(id)) {
		cout << "Symbol not yet defined" << endl;
		system("pause");
		return;
	}
	table[id]->type = new_type;
}

void SymbolTable::output(unsigned int idx) const {
	cout << "Symbol Table " << idx << " :" << endl;
	for (auto it: table) {
		cout << "Symbol Name: " << it.first;
		SymbolEntry * entry = it.second;
		cout << " | Type: " << d_converter[entry->type];
		cout << " | Category: " << st_converter[entry->category];
		cout << " | Extra Info: ";
		switch (entry->category) {
			case array_st:
				cout << "array dimension -- " << entry->storage.array_dim; break;
			case function_st:
				cout << "function parameter types -- ";
				for (auto it: * entry->storage.func_params)
					cout << d_converter[it] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}

SymbolTable * root_table = new SymbolTable(), * curr_table = root_table;
unordered_map<SymbolTable *, unsigned int> tables;
unsigned int table_count = 0;

// grammar tree

Node::Node(NodeType init_type): type(init_type) { row = row_count; col = col_count; table = curr_table; }
Node::Node(NodeType init_type, char * string_data) : Node(init_type) { size_t len = strlen(string_data) + 1; data.string_v = new char[len]; strcpy_s(data.string_v, len, string_data); }
Node::Node(NodeType init_type, int int_data) : Node(init_type) { data.int_v = int_data; }

void Node::addBack(Node * child) {
	children.push_back(child);
}

NodeType Node::getType() const {
	return type;
}

void Node::setType(NodeType new_type) {
	type = new_type;
}

char * Node::getCharP() const {
	return data.string_v;
}

string Node::getString() const {
	return string(data.string_v);
}

SymbolTable * Node::getTable() const {
	return table;
}

SymbolEntry * Node::getEntry() const {
	return entry;
}

void Node::setTable(SymbolTable * new_table) {
	table = new_table;
}

void Node::setEntry(SymbolEntry * new_entry) {
	entry = new_entry;
}

Node * Node::getChild(unsigned int idx) const {
	return children[idx];
}

unsigned int Node::getChildrenSize() const {
	return children.size();
}

const unsigned int Node::traverse() {
	// add children ids
	vector<int> children_ids;
	if (!children.empty()) {
		for (auto it = children.begin(); it != children.end(); ++it) {
			children_ids.push_back((*it)->traverse());
		}
	}
	cout << node_id << ": " << term_table[type] << ", ";
	// find type output
	string bool_val;
	switch (type) {
	case type_t:
		cout << data.string_v << ", "; break;
	case expr_t:
		cout << "op: " << data.string_v << ", "; break;
	case idt_t:
		cout << "symbol: " << data.string_v << ", "; break;
	case ival_t:
		cout << "value: " << data.int_v << ", "; break;
	case cval_t:
		cout << "value: " << data.string_v << ", "; break;
	}
	cout << "Children: ";
	if (!children_ids.empty()) for (auto c_id: children_ids) cout << c_id << " ";
	cout << ", " << "Row: " << row << ", Col: " << col << endl;
	return node_id++;
}

unsigned int row_count = 1, col_count = 1;

// traverse

unsigned int node_id = 0;

unordered_map<NodeType, string> term_table({
	{blocks_t, "Execution Blocks"},
	{idt_t, "ID Declaration"},
	{ival_t, "Const Declaration"},
	{cval_t, "Const Declaration"},
	{expr_t, "Expr"},
	{decl_t, "Var Declaration"},
	{type_t, "Type"},
	{decl_head_t, "Declaration Head"},
	{decl_list_t, "Declaration List"},
	{init_val_t, "Initial Values"},
	{param_list_t, "Parameter List"},
	{param_t, "Parameter"},
	{idt_list_t, "ID Declaration List"},
	{func_t, "Function Declaration"},
	{return_stmt_t, "Return Statement"},
	{while_stmt_t, "While Statement"},
	{dowhile_stmt_t, "Do While Statement"},
	{for_stmt_t, "For Statement"},
	{if_stmt_t, "If Statement"},
	{empty_stmt_t, "Empty Statement"},
	{compound_stmt_t, "Compound Statement"},
	{stmt_decl_list_t, "Statement and Declaration List"},
});