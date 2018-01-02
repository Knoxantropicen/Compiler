#include "utils.h"

// symbol table

SymbolEntry::SymbolEntry(NodeValType init_val_type, SymbolType init_cate): val_type(init_val_type), category(init_cate) {}

bool entered = false;

unordered_map<Operator, string> op_converter({
	{comma_d, ","},
	{ternary_d, "?:"},
	{or_d, "||"}, {and_d, "&&"},
	{bit_or_d, "|"}, {bit_xor_d, "^"}, {bit_and_d, "&"},
	{eq_d, "=="}, {ne_d, "!="},
	{le_d, "<="}, {ge_d, ">="},
	{lt_d, "<"}, {gt_d, ">"},
	{lshift_d, "<<"}, {rshift_d, ">>"},
	{add_d, "+"}, {sub_d, "-"},
	{mul_d, "*"}, {div_d, "/"}, {mod_d, "%"},
	{post_inc_d, "++"}, {post_dec_d, "--"},
	{assign_d, "="},
	{addassign_d, "+="}, {subassign_d, "-="},
	{mulassign_d, "*="}, {divassign_d, "/="}, {modassign_d, "%="},
	{andassign_d, "&="}, {orassign_d, "|="}, {xorassign_d, "^="}, {revassign_d, "~="},
	{lshiftassign_d, "<<="}, {rshiftassign_d, ">>="},
	{pos_d, "+"}, {neg_d, "-"}, {rev_d, "~"}, {not_d, "!"},
	{pre_inc_d, "++"}, {pre_dec_d, "--"},
});

unordered_map<SymbolType, string> st_translator({
	{var_st, "variable"},
	{function_st, "function"},
});

unordered_map<string, NodeValType> vt_converter({
	{"integer", int_vt},
	{"character", char_vt},
});

unordered_map<NodeValType, string> vt_translator({
	{int_vt, "integer"},
	{char_vt, "character"},
});

void SymbolTable::setFather(SymbolTable * father_table) {
	father = father_table;
}

SymbolTable * SymbolTable::getFather() {
	return father;
}

SymbolEntry * SymbolTable::find(string id) {
	SymbolEntry * target_entry;
	if (table.find(id) != table.end()) return table[id];
	else if (father != NULL && (target_entry = father->find(id))) return target_entry;
	else return NULL;
}

void SymbolTable::insert(string id, SymbolEntry * entry) {
	if (find(id)) {
		cout << "Symbol already declared" << endl;
		system("pause");
		return;
	}
	table.insert({id, entry});
}

void SymbolTable::output(unsigned int idx) const {
	cout << "Symbol Table " << idx << " :" << endl;
	for (auto it: table) {
		cout << "Symbol Name: " << it.first;
		SymbolEntry * entry = it.second;
		cout << " | Value Type: " << vt_translator[entry->val_type];
		cout << " | Category: " << st_translator[entry->category];
		cout << endl;
	}
	cout << endl;
}

SymbolTable * root_table = new SymbolTable(), * curr_table = root_table;
unordered_map<SymbolTable *, unsigned int> tables;
unsigned int table_count = 0;

// grammar tree

Node::Node(NodeType init_type, Node * child1, Node * child2, Node * child3, Node * child4): type(init_type) { 
	row = row_count;
	col = col_count;
	table = curr_table;
	if (child1) addChild(child1);
	if (child2) addChild(child2);
	if (child3) addChild(child3);
	if (child4) addChild(child4);
	val_type = void_vt;
	stmtTypeCheck();
}
Node::Node(NodeType init_type, int int_data, Node * child1, Node * child2, Node * child3, Node * child4) : Node(init_type, child1, child2, child3, child4) {
	data.int_v = int_data;
	val_type = int_vt;
}
Node::Node(NodeType init_type, char * string_data, Node * child1, Node * child2, Node * child3, Node * child4) : Node(init_type, child1, child2, child3, child4) {
	size_t len = strlen(string_data) + 1;
	data.string_v = new char[len];
	strcpy_s(data.string_v, len, string_data);
	if (type == cval_t) val_type = char_vt;
}
Node::Node(NodeType init_type, Operator op, Node * child1, Node * child2, Node * child3, Node * child4) : Node(init_type, child1, child2, child3, child4) {
	data.op_v = op;
	exprTypeCheck();
}

void Node::addChild(Node * child) {
	children.push_back(child);
}

NodeType Node::getType() const {
	return type;
}

void Node::setType(NodeType new_type) {
	type = new_type;
}

NodeValType Node::getValType() const {
	return val_type;
}

void Node::setValType(NodeValType new_val_type) {
	val_type = new_val_type;
}

int Node::getInt() const {
	return data.int_v;
}

string Node::getString() const {
	return string(data.string_v);
}

Operator Node::getOp() const {
	return data.op_v;
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

unsigned int Node::traverse() const {
	// add children ids
	vector<int> children_ids;
	if (!children.empty()) {
		for (auto it = children.begin(); it != children.end(); ++it) {
			children_ids.push_back((*it)->traverse());
		}
	}
	cout << node_id << ": " << term_table[type] << ", ";
	// find type output
	switch (type) {
	case type_t:
		cout << data.string_v << ", "; break;
	case expr_t:
	case assign_expr_t:
	case ternary_expr_t:
	case logical_expr_t:
	case calc_expr_t:
	case comp_expr_t:
	case unary_expr_t:
	case post_expr_t:
		cout << "op: " << op_converter[data.op_v] << ", "; break;
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

void Node::exprTypeCheck() {
	switch (type) {
	case assign_expr_t:
		val_type = symbolCheck(getChild(0)->getString())->val_type;
		if (val_type != getChild(1)->getValType())
			typeError("Types unequal in assignment");
		if (val_type != int_vt && getOp() != assign_d)
			typeError("Invalid calculation on non-integer type");
		break;
	case ternary_expr_t:
		val_type = getChild(1)->getValType();
		if (val_type != getChild(2)->getValType())
			typeError("Types unequal in ternary expression");
		break;
	case logical_expr_t:
		val_type = bool_vt;
		if (getChild(0)->getValType() != bool_vt || getChild(1)->getValType() != bool_vt)
			typeError("Invalid logical expression");
		break;
	case calc_expr_t:
		val_type = int_vt;
		if (getChild(0)->getValType() != int_vt || getChild(1)->getValType() != int_vt)
			typeError("Invalid calculation on non-integer type");
		break;
	case comp_expr_t:
		val_type = bool_vt;
		if (getChild(0)->getValType() != getChild(1)->getValType())
			typeError("Types unequal in comparement");
		break;
	case unary_expr_t:
		val_type = getChild(0)->getValType();
		if (val_type == bool_vt && getOp() != not_d)
			typeError("Invalid calculation on non-integer type");
		else if (val_type == int_vt && getOp() == not_d)
			typeError("Invalid logical operation on integer");
		else if (val_type == char_vt)
			typeError("Invalid unary operation");
		if (!checkID(getChild(0)))
			typeError("Expression is not assignable");
		break;
	case post_expr_t:
		val_type = getChild(0)->getValType();
		if (val_type != int_vt)
			typeError("Invalid calculation on non-interger type");
		if (!checkID(getChild(0)))
			typeError("Expression is not assignable");
		break;
	}
}

void Node::stmtTypeCheck() {
	switch (type) {
	case while_stmt_t:
	case dowhile_stmt_t:
	case if_stmt_t:
		if (getChild(0)->getValType() != bool_vt)
			typeError("Non-boolean condition");
		break;
	case for_stmt_t:
		if (getChild(1)->getValType() != bool_vt)
			typeError("Non-boolean condition");
		break;
	}
}

SymbolEntry * Node::symbolCheck(string id_name) const {
	SymbolEntry * target_entry = table->find(id_name);
	if (target_entry) return target_entry;
	else {
		string error_text = "Symbol '";
		error_text += id_name;
		error_text += "' not defined";
		typeError(error_text.c_str());
	}
	return NULL;
}

void Node::typeError(const char * text) const {
	cerr << "Type Error at: row(" << row << "), column(" << col << ")" << endl;
	cerr << "Error Description: " << text << endl;
	system("pause");
	exit(1);
}

bool Node::checkID(Node * node) const {
	if (node->getChildrenSize() > 0) return checkID(node->getChild(0));
	return (node->getType() == idt_t);
}

unsigned int row_count = 1, col_count = 1;

// traverse

unsigned int node_id = 0;

unordered_map<NodeType, string> term_table({
	{program_t, "Program"},
	{type_t, "Type"},
	{expr_t, "Expression"},
	{assign_expr_t, "Expression"},
	{ternary_expr_t, "Expression"},
	{logical_expr_t, "Expression"},
	{calc_expr_t, "Expression"},
	{comp_expr_t, "Expression"},
	{unary_expr_t, "Expression"},
	{post_expr_t, "Expression"},
	{temp_expr_t, "Error! Temporary Expression"},
	{idt_t, "ID Declaration"},
	{ival_t, "Const Declaration"},
	{cval_t, "Const Declaration"},
	{decl_group_t, "Declaration Group"},
	{decl_t, "Var Declaration"},
	{decl_list_t, "Declaration List"},
	{idt_list_t, "ID Declaration List"},
	{func_t, "Function Declaration"},
	{while_stmt_t, "While Statement"},
	{dowhile_stmt_t, "Do While Statement"},
	{for_stmt_t, "For Statement"},
	{if_stmt_t, "If Statement"},
	{empty_stmt_t, "Empty Statement"},
	{compound_stmt_t, "Compound Statement"},
	{stmt_decl_list_t, "Statement and Declaration List"},
});