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
	if (child1) children.push_back(child1);
	if (child2) children.push_back(child2);
	if (child3) children.push_back(child3);
	if (child4) children.push_back(child4);
	val_type = void_vt;
	stmtTypeCheck();
	label.begin_lb = "";
	label.next_lb = "";
	label.true_lb = "";
	label.false_lb = "";
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
	cout << ", " << "Row: " << row << ", Col: " << col;
	if (type >= expr_t && type < ternary_expr_t) {
		if (label.true_lb != "" || label.false_lb != "")
			cout << ", Label: True " << label.true_lb << " False " << label.false_lb;
	}
	else {
		if (label.begin_lb != "" || label.next_lb != "")
			cout << ", Label: Begin " << label.begin_lb << " Next " << label.next_lb;
	}
	cout << endl;
	return node_id++;
}

void Node::exprTypeCheck() {
	switch (type) {
		case assign_expr_t:
			val_type = symbolCheck(string(children[0]->data.string_v))->val_type;
			if (val_type != children[1]->val_type)
				typeError("Types unequal in assignment");
			if (val_type != int_vt && data.op_v != assign_d)
				typeError("Invalid calculation on non-integer type");
			break;
		case ternary_expr_t:
			val_type = children[1]->val_type;
			if (val_type != children[2]->val_type)
				typeError("Types unequal in ternary expression");
			break;
		case logical_expr_t:
			val_type = bool_vt;
			if (children[0]->val_type != bool_vt || children[1]->val_type != bool_vt)
				typeError("Invalid logical expression");
			break;
		case calc_expr_t:
			val_type = int_vt;
			if (children[0]->val_type != int_vt || children[1]->val_type != int_vt)
				typeError("Invalid calculation on non-integer type");
			break;
		case comp_expr_t:
			val_type = bool_vt;
			if (children[0]->val_type != children[1]->val_type)
				typeError("Types unequal in comparement");
			break;
		case unary_expr_t:
			val_type = children[0]->val_type;
			if (val_type == bool_vt && data.op_v != not_d)
				typeError("Invalid calculation on non-integer type");
			else if (val_type == int_vt && data.op_v == not_d)
				typeError("Invalid logical operation on integer");
			else if (val_type == char_vt)
				typeError("Invalid unary operation");
			if (!checkID(children[0]))
				typeError("Expression is not assignable");
			break;
		case post_expr_t:
			val_type = children[0]->val_type;
			if (val_type != int_vt)
				typeError("Invalid calculation on non-interger type");
			if (!checkID(children[0]))
				typeError("Expression is not assignable");
			break;
	}
}

void Node::stmtTypeCheck() {
	switch (type) {
		case while_stmt_t:
		case if_stmt_t:
		case if_else_stmt_t:
			if (children[0]->val_type != bool_vt)
				typeError("Non-boolean condition");
			break;
		case for_stmt_t:
			if (children[1]->val_type != bool_vt)
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
	if (!node->children.empty()) return checkID(node->children[0]);
	return (node->type == idt_t);
}

unsigned int row_count = 1, col_count = 1;

Node * root_node;

// traverse

unsigned int node_id = 0;

unordered_map<NodeType, string> term_table({
	{program_t, "Program"},
	{type_t, "Type"},
	{expr_t, "Expression"},
	{assign_expr_t, "Expression"},
	{ternary_expr_t, "Expression"},
	{logical_expr_t, "Expression"},
	{comp_expr_t, "Expression"},
	{calc_expr_t, "Expression"},
	{unary_expr_t, "Expression"},
	{post_expr_t, "Expression"},
	{temp_expr_t, "Error! Temporary Expression"},
	{idt_t, "Identifier"},
	{ival_t, "Const Declaration"},
	{cval_t, "Const Declaration"},
	{decl_list_t, "Declaration List"},
	{decl_t, "Var Declaration"},
	{idt_list_t, "Identifier List"},
	{func_t, "Function Declaration"},
	{while_stmt_t, "While Statement"},
	{for_stmt_t, "For Statement"},
	{if_stmt_t, "If Statement"},
	{if_else_stmt_t, "If Else Statement"},
	{empty_stmt_t, "Empty Statement"},
	{compound_stmt_t, "Compound Statement"},
	{stmt_list_t, "Statement List"},
});

// tree

Tree::Tree(Node * node) : root(node), label_cnt(0) {}
ofstream out;

char * Tree::new_label() {
	char * lb_idx = new char[10];
	sprintf(lb_idx, "@%d", label_cnt++);
	return lb_idx;
}

void Tree::gen_label() {
	root->label.begin_lb = "_start";
	gen_label_recr(root);
}

void Tree::gen_label_recr(Node * node) {
	NodeType node_type = node->type;
	if (node_type >= logical_expr_t && node_type <= unary_expr_t) gen_expr_label(node);
	else if (node_type >= ternary_expr_t && node_type <= if_else_stmt_t) gen_stmt_label(node);
	for (auto child: node->children)
		gen_label_recr(child);
}

void Tree::gen_stmt_label(Node * node) {
	switch (node->type) {
		case while_stmt_t: {
			Node * cond = node->children[0], * stmt = node->children[1];
			node->label.begin_lb = new_label();
			cond->label.true_lb = new_label();
			if (node->label.next_lb == "")
				node->label.next_lb = new_label();
			cond->label.false_lb = node->label.next_lb;
			stmt->label.next_lb = node->label.begin_lb;
			// node.code = code.begin_lb: || cond.code || cond.true_lb: || stmt.code || goto node.begin_lb
			break;
		}
		case for_stmt_t: {
			Node * init = node->children[0], * cond = node->children[1];
			init->label.next_lb = new_label();
			if (node->label.next_lb == "")
				node->label.next_lb = new_label();

			if (node->children.size() == 3) {
				Node * stmt = node->children[2];
				cond->label.true_lb = new_label();
				cond->label.false_lb = node->label.next_lb;
				stmt->label.next_lb = init->label.next_lb;
				// node.code = init.code || init.next_lb: || cond.code || cond.true_lb: || stmt.code || goto init.next_lb
			}
			else { // size == 4
				Node * expr = node->children[2], * stmt = node->children[3];
				cond->label.true_lb = new_label();
				cond->label.false_lb = node->label.next_lb;
				expr->label.next_lb = init->label.next_lb;
				// node.code = init.code || init.next_lb: || cond.code || cond.true_lb: || stmt.code || expr.code || goto init.next_lb
			}
			break;
		}
		case if_stmt_t: {
			Node * cond = node->children[0], * stmt = node->children[1];
			cond->label.true_lb = new_label();
			if (node->label.next_lb == "") node->label.next_lb = new_label();
			cond->label.false_lb = stmt->label.next_lb = node->label.next_lb;
			// node.code = cond.code || cond.true_lb: || stmt.code
			break;
		}
		case ternary_expr_t:
		case if_else_stmt_t: {
			Node * cond = node->children[0], * stmt1 = node->children[1], * stmt2 = node->children[2];
			cond->label.true_lb = new_label();
			cond->label.false_lb = new_label();
			if (node->label.next_lb == "") node->label.next_lb = new_label();
			stmt1->label.next_lb = stmt2->label.next_lb = node->label.next_lb;
			// node.code = cond.code || cond.true_lb: || stmt1.code || goto node.next_lb || cond.false_lb: || stmt2.code
			break;
		}
	}
}

void Tree::gen_expr_label(Node * node) {
	switch (node->data.op_v) {
		case or_d: {
			Node * cond1 = node->children[0], * cond2 = node->children[1];
			cond1->label.true_lb = cond2->label.true_lb = node->label.true_lb;
			cond1->label.false_lb = new_label();
			cond2->label.false_lb = node->label.false_lb;
			// node.code = cond1.code || cond1.false_lb: || cond2.code
			break;
		}
		case and_d: {
			Node * cond1 = node->children[0], * cond2 = node->children[1];
			cond1->label.true_lb = new_label();
			cond1->label.false_lb = cond2->label.false_lb = node->label.false_lb;
			cond2->label.true_lb = node->label.true_lb;
			// node.code = cond1.code || cond1.true_lb: || cond2.code
			break;
		}
		case not_d: {
			Node * cond = node->children[0];
			cond->label.true_lb = node->label.false_lb;
			cond->label.false_lb = node->label.true_lb;
			// node.code = cond.code
			break;
		}
	}
}

void Tree::gen_header_code(ofstream & out) {
	out << "\t.586" << endl;
    out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap :none" << endl;
	out << endl;
	out << "\tinclude \\masm32\\include\\windows.inc" << endl;
	out << "\tinclude \\masm32\\include\\user32.inc" << endl;
	out << "\tinclude \\masm32\\include\\kernel32.inc" << endl;
	out << "\tinclude \\masm32\\include\\masm32.inc" << endl;
	out << endl;
	out << "\tincludelib \\masm32\\lib\\user32.lib" << endl;
	out << "\tincludelib \\masm32\\lib\\kernel32.lib" << endl;
	out << "\tincludelib \\masm32\\lib\\masm32.lib" << endl;
}