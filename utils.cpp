#include "utils.h"

// symbol table

SymbolEntry::SymbolEntry(NodeValType init_val_type, SymbolType init_cate): val_type(init_val_type), category(init_cate) {}

bool entered = false;

unordered_map<Operator, string> op_converter({
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
		exit(1);
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
unsigned int var_count = 1;

// grammar tree

Node::Node(NodeType init_type, Node * child1, Node * child2, Node * child3, Node * child4): type(init_type) { 
	row = row_count;
	col = col_count;
	index = 0;
	temp = 0;
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
		case assign_expr_t:
		case ternary_expr_t:
		case logical_expr_t:
		case calc_expr_t:
		case comp_expr_t:
		case unary_expr_t:
		case post_expr_t:
			cout << "op: " << op_converter[data.op_v] << ", "; break;
		case idt_t:
			cout << "symbol: " << data.string_v << "(" << val_type << "), "; break;
		case ival_t:
			cout << "value: " << data.int_v << ", "; break;
		case cval_t:
			cout << "value: " << data.string_v << ", "; break;
	}
	cout << "Children: ";
	if (!children_ids.empty()) for (auto c_id: children_ids) cout << c_id << " ";
	cout << ", " << "Row: " << row << ", Col: " << col;
	if (type >= assign_expr_t && type < ternary_expr_t) {
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
			val_type = children[0]->val_type;
			if (val_type != children.back()->val_type)
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
			else if (!checkID(children[0]) && (data.op_v == pre_inc_d || data.op_v == pre_dec_d))
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
			if (children[1]->val_type != bool_vt && children[1]->type != empty_stmt_t)
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

Tree::Tree(Node * node) : root(node), label_cnt(0), temp_cnt(0), temp_max(0) {
	code_global_v = "";
	code_local_v = "";
	code_main = "";
}

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
			Node * init = node->children[0], * cond = node->children[1], * stmt = node->children[2];
			init->label.next_lb = new_label();
			if (node->label.next_lb == "")
				node->label.next_lb = new_label();
			cond->label.true_lb = new_label();
			cond->label.false_lb = node->label.next_lb;

			if (node->children.size() == 3) {
				stmt->label.next_lb = init->label.next_lb;
				// node.code = init.code || init.next_lb: || cond.code || cond.true_lb: || stmt.code || goto init.next_lb
			}
			else { // size == 4
				Node * expr = node->children[3];
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

char * Tree::new_temp(Node * node) {
	char * temp_idx = new char[10];
	sprintf(temp_idx, "t%d", ++temp_cnt);
	temp_max = temp_max > temp_cnt ? temp_max : temp_cnt;
	node->temp = temp_cnt;
	return temp_idx;
}

void Tree::gen_code(ofstream & out) {
	gen_header_code(out);
	gen_code_recr(root);
	gen_data_code();
	out << code_global_v << endl;
	out << "\t.code" << endl << root->label.begin_lb << ":" << endl;
	out << "\tcall main" << endl << "\texit" << endl;
	out << "main proc" << endl;
	out << code_local_v << code_main;
	out << "main endp" << endl;
	out << "end " << root->label.begin_lb << endl;
}

void Tree::gen_header_code(ofstream & out) {
	out << "\t.586" << endl;
    out << "\t.model flat, stdcall" << endl;
	out << "\toption casemap :none" << endl;
	out << endl;
	out << "\tinclude \\masm32\\include\\windows.inc" << endl;
	out << "\tinclude \\masm32\\macros\\macros.asm" << endl;
	out << "\tinclude \\masm32\\include\\masm32.inc" << endl;
    out << "\tinclude \\masm32\\include\\gdi32.inc" << endl;
    out << "\tinclude \\masm32\\include\\user32.inc" << endl;
    out << "\tinclude \\masm32\\include\\kernel32.inc" << endl;
    out << "\tincludelib \\masm32\\lib\\masm32.lib" << endl;
    out << "\tincludelib \\masm32\\lib\\gdi32.lib" << endl;
    out << "\tincludelib \\masm32\\lib\\user32.lib" << endl;
    out << "\tincludelib \\masm32\\lib\\kernel32.lib" << endl;
	out << endl;
}

void Tree::gen_data_code() {
	for (unsigned int i = 1; i <= temp_max; ++i) {
		code_global_v += "\t\tt";
		code_global_v += to_string(i);
		code_global_v += " DWORD 0\n";
	}
}

void Tree::gen_code_recr(Node * node) {
	if (node->type == program_t) {
		code_global_v += "\t.data\n";
		if (node->children[0]->type == decl_list_t || node->children[0]->type == decl_t) {
			gen_decl_code(node->children[0], true);
		}
		gen_code_recr(node->children.back());
		return;
	}
	else if (node->type == decl_list_t || node->type == decl_t) {
		gen_decl_code(node, false);
		return;
	}
	for (auto child: node->children)
		gen_code_recr(child);
	switch (node->type) {
		case while_stmt_t: {
			Node * cond = node->children[0], * stmt = node->children[1];
			gen_label_code(node->label.begin_lb);
			gen_code_recr(cond);
			gen_label_code(cond->label.true_lb);
			gen_code_recr(stmt);
			code_main += "\tjmp ";
			code_main += node->label.begin_lb;
			code_main += "\n";
			gen_label_code(node->label.next_lb);
			break;
		}
		case for_stmt_t: {
			Node * init = node->children[0], * cond = node->children[1], * stmt = node->children[2];
			gen_code_recr(init);
			gen_label_code(init->label.next_lb);
			gen_code_recr(cond);
			gen_label_code(cond->label.true_lb);
			gen_code_recr(stmt);
			if (node->children.size() == 4)
				gen_code_recr(node->children[3]);
			code_main += "\tjmp ";
			code_main += init->label.next_lb;
			code_main += "\n";
			gen_label_code(node->label.next_lb);
			break;
		}
		case if_stmt_t: {
			Node * cond = node->children[0], * stmt = node->children[1];
			gen_code_recr(cond);
			gen_label_code(cond->label.true_lb);
			gen_code_recr(stmt);
			gen_label_code(node->label.next_lb);
			break;
		}
		case ternary_expr_t:
		case if_else_stmt_t: {
			Node * cond = node->children[0], * stmt1 = node->children[1], * stmt2 = node->children[2];
			gen_code_recr(cond);
			gen_label_code(cond->label.true_lb);
			gen_code_recr(stmt1);
			code_main += "\tjmp ";
			code_main += node->label.next_lb;
			code_main += "\n";
			gen_label_code(cond->label.false_lb);
			gen_code_recr(stmt2);
			gen_label_code(node->label.next_lb);
			break;
		}
		case assign_expr_t: {
			Node * idt = node->children[0], *val = node->children.back();
			for (unsigned int i = 1; i < node->children.size(); ++i) {
				gen_code_recr(node->children[i]);
			}
			switch (node->data.op_v) {
				case assign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case addassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tadd eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case subassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tsub eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case mulassign_d: {
					code_main += "\tmul eax, ";
					gen_val_code(idt);
					code_main += ", ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case divassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tdiv ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case modassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tdiv ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", edx\n";
					break;
				}
				case andassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tand eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case orassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tor eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case xorassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\txor eax, ";
					gen_val_code(val);
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case revassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(val);
					code_main += "\n\tnot eax\n";
					code_main += "\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case lshiftassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tmov ecx, ";
					gen_val_code(val);
					code_main += "\n\tshl eax, cl";
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
				case rshiftassign_d: {
					code_main += "\tmov eax, ";
					gen_val_code(idt);
					code_main += "\n\tmov ecx, ";
					gen_val_code(val);
					code_main += "\n\tshr eax, cl";
					code_main += "\n\tmov ";
					gen_val_code(idt);
					code_main += ", eax\n";
					break;
				}
			}
			break;
		}
		case logical_expr_t: {
			Node * cond1 = node->children[0], * cond2 = node->children[1];
			gen_code_recr(cond1);
			(node->data.op_v == or_d) ? gen_label_code(cond1->label.false_lb) : gen_label_code(cond1->label.true_lb);
			gen_code_recr(cond2);
			break;
		}
		case comp_expr_t: {
			Node * val1 = node->children[0], * val2 = node->children[1];
			code_main += "\tmov eax, ";
			gen_val_code(val1);
			code_main += "\n\tcmp eax, ";
			gen_val_code(val2);
			code_main += "\n\t";
			switch (node->data.op_v) {
				case eq_d:
					code_main += "je ";
					break;
				case ne_d:
					code_main += "jne ";
					break;
				case ge_d:
					code_main += "jge ";
					break;
				case le_d:
					code_main += "jle ";
					break;
				case gt_d:
					code_main += "jg ";
					break;
				case lt_d:
					code_main += "jl ";
					break;
			}
			code_main += node->label.true_lb;
			code_main += "\n\tjmp ";
			code_main += node->label.false_lb;
			code_main += "\n";
			break;
		}
		case unary_expr_t: {
			switch (node->data.op_v) {
				case neg_d: {
					code_main += "\tmov eax, ";
					gen_val_code(node->children[0]);
					code_main += "\n\tneg eax\n";
					code_main += "\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case rev_d: {
					code_main += "\tmov eax, ";
					gen_val_code(node->children[0]);
					code_main += "\n\tnot eax\n";
					code_main += "\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case not_d: {
					Node * cond = node->children[0];
					gen_code_recr(cond);
					break;
				}
				case pre_inc_d: {
					code_main += "\tinc ";
					gen_val_code(node->children[0]);
					code_main += "\n";
					break;
				}
				case pre_dec_d: {
					code_main += "\tdec ";
					gen_val_code(node->children[0]);
					code_main += "\n";
					break;
				}
			}
			break;
		}
		case calc_expr_t: {
			Node * val1 = node->children[0], * val2 = node->children[1];
			code_main += "\tmov eax, ";
			gen_val_code(val1);
			switch (node->data.op_v) {
				case bit_or_d: {
					code_main += "\n\tor eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case bit_xor_d: {
					code_main += "\n\txor eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case bit_and_d: {
					code_main += "\n\tand eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case lshift_d: {
					code_main += "\n\tmov ecx, ";
					gen_val_code(val2);
					code_main += "\n\tshl eax, cl";
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case rshift_d: {
					code_main += "\n\tmov ecx, ";
					gen_val_code(val2);
					code_main += "\n\tshr eax, cl";
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case add_d: {
					code_main += "\n\tadd eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case sub_d: {
					code_main += "\n\tsub eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case mul_d: {
					code_main += "\n\tmul eax, ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case div_d: {
					code_main += "\n\tdiv ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", eax\n";
					break;
				}
				case mod_d: {
					code_main += "\n\tdiv ";
					gen_val_code(val2);
					code_main += "\n\tmov ";
					code_main += new_temp(node);
					code_main += ", edx\n";
					break;
				}
			}
			break;
		}
		case post_expr_t: {
			Node * val = node->children[0], * idt = val;
			while (idt->type != idt_t) idt = idt->children[0];
			code_main += "\tmov eax, ";
			gen_val_code(val);
			code_main += "\n\tmov ";
			code_main += new_temp(node);
			code_main += ", eax\n";
			if (node->data.op_v == post_inc_d)
				code_main += "\tinc ";
			else // post_dec_d
				code_main += "\tdec ";
			gen_val_code(idt);
			code_main += "\n";
			break;
		}
	}
}

void Tree::gen_decl_code(Node * node, bool global) {
	if (node->type == idt_t) {
		if (global) {
			code_global_v += "\t\t$";
			code_global_v += to_string(node->index);
			if (node->val_type == int_vt)
				code_global_v += " DWORD 0\n";
			else if (node->val_type == char_vt)
				code_global_v += " BYTE 0\n";
			else
				node->typeError("Error type declaration");
			idx_map.insert({node->data.string_v, node->index});
		} else {
			code_local_v += "\tLOCAL $";
			code_local_v += to_string(node->index);
			if (node->val_type == int_vt)
				code_local_v += " :DWORD\n";
			else if (node->val_type == char_vt)
				code_local_v += " :BYTE\n";
			else
				node->typeError("Error type declaration");
			idx_map.insert({node->data.string_v, node->index});
		}
		return;
	}
	for (auto child: node->children) {
		gen_decl_code(child, global);
	}
}

void Tree::gen_label_code(string label) {
	code_main += label;
	code_main += ":\n";
}

void Tree::gen_val_code(Node * node) {
	if (node->temp != 0) {
		code_main += "t";
		code_main += to_string(node->temp);
		--temp_cnt;
	}
	else if (node->type == idt_t) {
		code_main += "$";
		code_main += to_string(idx_map[node->data.string_v]);
	}
	else if (node->type == ival_t) {
		code_main += to_string(node->data.int_v);
	}
	else if (node->type == cval_t) {
		code_main += node->data.string_v;
	}
	else {
		// node->typeError("Error value");
		node->typeError(to_string(node->type).c_str());
	}
}