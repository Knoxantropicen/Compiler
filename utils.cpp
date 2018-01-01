#include "utils.h"

// symbol table

SfUnit::SfUnit(): const_e(false), volatile_e(false), type(default_d) {}
SfUnit::SfUnit(Descriptor init_type): const_e(false), volatile_e(false), type(init_type) {}

PtUnit::PtUnit(): const_e(false), volatile_e(false) {}

SfPtDimUnit::SfPtDimUnit(SfUnit init_sf, vector<PtUnit> init_pt, unsigned int init_dim): p_sf_type(init_sf), p_pt_type(init_pt), p_array_dim(init_dim) {}

SymbolEntry::SymbolEntry(SfUnit init_sf, vector<PtUnit> init_pt, SymbolType init_cate, SymbolTable * init_store): sf_type(init_sf), pt_type(init_pt), category(init_cate) {storage.type_table = init_store;}
SymbolEntry::SymbolEntry(SfUnit init_sf, vector<PtUnit> init_pt, SymbolType init_cate, vector<SfPtDimUnit> * init_store): sf_type(init_sf), pt_type(init_pt), category(init_cate) {
	storage.func_params = new vector<SfPtDimUnit>(); for (auto i: * init_store) storage.func_params->push_back(i);}
SymbolEntry::SymbolEntry(SfUnit init_sf, vector<PtUnit> init_pt, SymbolType init_cate, unsigned int init_store): sf_type(init_sf), pt_type(init_pt), category(init_cate) {storage.array_dim = init_store;}
SymbolEntry::SymbolEntry(SfUnit init_sf, vector<PtUnit> init_pt, SymbolType init_cate, string init_store): sf_type(init_sf), pt_type(init_pt), category(init_cate) {size_t len = init_store.length() + 1; storage.type_name = new char[len]; strcpy_s(storage.type_name, len, init_store.c_str());}

unordered_map<string, Descriptor> g_converter({
	{"void", void_d},
	{"integer", int_d},
	{"float", float_d},
	{"double", double_d},
	{"character", char_d},
	{"boolean", bool_d},
	{"string", string_d},
	{"auto", auto_d},
	{"struct", struct_d},
	{"union", union_d},
	{"enum", enum_d},
});

GIV::GIV(): g_sf(SfUnit()), g_pt(PtUnit()), g_cate(var_st), g_pt_list(vector<PtUnit>()), g_param_list(vector<SfPtDimUnit>()), g_dim(0), g_type_name("") {}

stack<GIV> giv_stack;
GIV giv;
bool entered = false;

unordered_map<Descriptor, string> d_converter({
	{default_d, ""},
	{void_d, "void"},
	{int_d, "int"},
	{float_d, "float"},
	{double_d, "double"},
	{char_d, "char"},
	{bool_d, "bool"},
	{string_d, "string"},
	{auto_d, "auto"},
	{struct_d, "struct"},
	{union_d, "union"},
	{enum_d, "enum"},
	{array_d, "array"},
});

unordered_map<SymbolType, string> st_converter({
	{var_st, "variable"},
	{array_st, "array"},
	{function_st, "function"},
	{type_name_st, "custom type"},
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

void SymbolTable::setSfPt(string id, SfUnit new_sf, vector<PtUnit> new_pt) {
	if (!find(id)) {
		cout << "Symbol not yet defined" << endl;
		system("pause");
		return;
	}
	table[id]->sf_type = new_sf;
	table[id]->pt_type = new_pt;
}

void SymbolTable::setTypeName(string id, string new_type_name) {
	if (!find(id)) {
		cout << "Symbol not yet defined" << endl;
		system("pause");
		return;
	}
	size_t len = new_type_name.length() + 1;
	delete table[id]->storage.type_name;
	table[id]->storage.type_name = new char[len];
	strcpy_s(table[id]->storage.type_name, len, new_type_name.c_str());
}

char * SymbolTable::getAnony() {
	char * name = new char[10];
	sprintf(name, "%d", anonymous_name_count++);
	return name;
}

void SymbolTable::output(unsigned int idx) const {
	cout << "Symbol Table " << idx << " :" << endl;
	for (auto it: table) {
		cout << "Symbol Name: " << it.first << " | Specifier Type: ";
		SymbolEntry * entry = it.second;
		if (entry->sf_type.const_e) cout << "const ";
		if (entry->sf_type.volatile_e) cout << "volatile ";
		cout << d_converter[entry->sf_type.type] << " | Pointer Type: ";
		for (auto pt_it: entry->pt_type) {
			cout << "* ";
			if (pt_it.const_e) cout << "const ";
			if (pt_it.volatile_e) cout << "volatile ";
		}
		cout << " | Symbol Type: " << st_converter[entry->category];
		cout << " | Extra Info: ";
		switch (entry->category) {
			case array_st:
				cout << "array dimension -- " << entry->storage.array_dim; break;
			case function_st:
				cout << "function parameter types -- ";
				// incompleted
				break;
			case var_st:
				if (entry->sf_type.type == struct_d || entry->sf_type.type == union_d || entry->sf_type.type == enum_d)
					cout << "custom type name -- " << string(entry->storage.type_name);
				break;
			case type_name_st:
				if (entry->storage.type_table) {
					cout << "symbol table address -- " << entry->storage.type_table;
				}
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
Node::Node(NodeType init_type, double double_data) : Node(init_type) { data.double_v = double_data; }
Node::Node(NodeType init_type, bool bool_data) : Node(init_type) { data.bool_v = bool_data; }

void Node::addBack(Node * child) {
	children.push_back(child);
}

void Node::addFront(Node * child) {
	children.push_front(child);
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
			if ((*it)->getType() == anony_idt_t) continue;
			children_ids.push_back((*it)->traverse());
		}
	}
	cout << node_id << ": " << term_table[type] << ", ";
	// find type output
	string bool_val;
	switch (type) {
	case type_sf_t:
	case type_qf_t:
		cout << data.string_v << ", "; break;
	case expr_t:
		cout << "op: " << data.string_v << ", "; break;
	case idt_t:
	case type_name_t:
		cout << "symbol: " << data.string_v << ", "; break;
	case ival_t:
		cout << "value: " << data.int_v << ", "; break;
	case dval_t:
		cout << "value: " << data.double_v << ", "; break;
	case bval_t:
		data.bool_v ? bool_val = "true" : bool_val = "false";
		cout << "value: " << bool_val << ", "; break;
	}
	cout << "Children: ";
	if (!children_ids.empty()) for (auto c_id: children_ids) cout << c_id << " ";
	cout << ", " << "Row: " << row << ", Col: " << col << endl;
	return node_id++;
}

const void Node::printTree(unsigned int depth) {
	return ;
}

unsigned int row_count = 1, col_count = 1;

// traverse

unsigned int node_id = 0;

unordered_map<NodeType, string> term_table({
	{blocks_t, "Execution Blocks"},
	{type_sf_t, "Type Specifier"},
	{idt_t, "ID Declaration"},
	{ival_t, "Const Declaration"},
	{dval_t, "Const Declaration"},
	{bval_t, "Const Declaration"},
	{sval_t, "Const Declaration"},
	{expr_t, "Expr"},
	{type_qf_t, "Type Qualifier"},
	{type_name_t, "Type Name"},
	{su_type_sf_t, "Custom Type Specifier"},
	{e_type_sf_t, "Enum Type Specifier"},
	{ptr_t, "Pointer"},
	{decl_t, "Var Declaration"},
	{type_t, "Type"},
	{idt_sf_t, "ID Specifier"},
	{decl_head_t, "Declaration Head"},
	{decl_list_t, "Declaration List"},
	{init_val_t, "Initial Values"},
	{param_list_t, "Parameter List"},
	{param_t, "Parameter"},
	{idt_list_t, "ID Declaration List"},
	{su_decl_list_t, "Custom Type Declaration List"},
	{su_decl_t, "Custom Type Declaration"},
	{e_decl_list_t, "Enum Type Declaration List"},
	{e_decl_t, "Enum Type Declaration"},
	{func_t, "Function Declaration"},
	{goto_stmt_t, "Goto Statement"},
	{break_stmt_t, "Break Statement"},
	{continue_stmt_t, "Continue Statement"},
	{return_stmt_t, "Return Statement"},
	{while_stmt_t, "While Statement"},
	{dowhile_stmt_t, "Do While Statement"},
	{for_stmt_t, "For Statement"},
	{if_stmt_t, "If Statement"},
	{switch_stmt_t, "Switch Statement"},
	{empty_stmt_t, "Empty Statement"},
	{label_stmt_t, "Label Statement"},
	{case_stmt_t, "Case Statement"},
	{default_stmt_t, "Default Statement"},
	{compound_stmt_t, "Compound Statement"},
	{stmt_decl_list_t, "Statement and Declaration List"},
});