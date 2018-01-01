/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 38 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 12/06/17
* Time: 20:36:14
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\myparser.y"

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


#line 156 "myparser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 132 ".\\myparser.y"

	// place any extra initialisation code here

#line 180 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 137 ".\\myparser.y"

	// place any extra cleanup code here

#line 194 "myparser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 177 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); cout << "Grammar Tree:" << endl; (*(YYSTYPE YYFAR*)yyvalptr)->traverse(); cout << endl; outputTables(); cout << endl;
#line 304 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 181 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(blocks_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 317 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 330 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 343 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 187 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 356 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 193 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "void");
#line 369 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "integer");
#line 382 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "float");
#line 395 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "double");
#line 408 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "character");
#line 421 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 198 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "boolean");
#line 434 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 199 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "string");
#line 447 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 200 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "auto");
#line 460 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 201 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 473 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 202 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 486 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 206 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_qf_t, "const"); giv.g_sf.const_e = true;
#line 499 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 207 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_qf_t, "volatile"); giv.g_sf.volatile_e = true;
#line 512 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 211 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_qf_t, "const"); giv.g_pt.const_e = true;
#line 525 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_qf_t, "volatile"); giv.g_pt.volatile_e = true;
#line 538 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 216 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_type_sf_t, yyattribute(1 - 5)->getCharP()); yyattribute(2 - 5)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 5));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 5)->getString()];
		customTypeInsertEntry(yyattribute(2 - 5)->getString(), yyattribute(4 - 5)->getTable());
#line 553 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 219 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_type_sf_t, yyattribute(1 - 4)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); char * anony_name = curr_table->getAnony(); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(new Node(anony_idt_t, anony_name)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 4)->getString()];
		anonyCustomTypeInsertEntry(anony_name, yyattribute(3 - 4)->getTable());
#line 568 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 222 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_type_sf_t, yyattribute(1 - 4)->getCharP()); yyattribute(2 - 4)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 4)->getString()];
		customTypeInsertEntry(yyattribute(2 - 4)->getString(), NULL);
#line 583 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 225 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_type_sf_t, yyattribute(1 - 3)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); char * anony_name = curr_table->getAnony(); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(new Node(anony_idt_t, anony_name));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 3)->getString()];
		anonyCustomTypeInsertEntry(anony_name, NULL);
#line 598 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 228 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_type_sf_t, yyattribute(1 - 2)->getCharP()); yyattribute(2 - 2)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
		giv.g_sf.type = g_converter[yyattribute(1 - 2)->getString()];
		customTypeInsertEntry(yyattribute(2 - 2)->getString(), NULL);
#line 613 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 234 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "struct");
#line 626 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 235 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_sf_t, "union");
#line 639 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 239 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 5); yyattribute(2 - 5)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 5)); 
		recrSetEnumTypeName(yyattribute(4 - 5), yyattribute(2 - 5)->getString());
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 5)->getString()];
		enumTypeInsertEntry(yyattribute(2 - 5), yyattribute(4 - 5));
#line 655 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 243 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 4); char * anony_name = curr_table->getAnony(); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(new Node(anony_idt_t, anony_name)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
		recrSetEnumTypeName(yyattribute(3 - 4), string(anony_name));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 4)->getString()];
		enumTypeInsertEntry((*(YYSTYPE YYFAR*)yyvalptr)->getChild(0), yyattribute(3 - 4));
#line 671 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 247 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 4); yyattribute(2 - 4)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 4)->getString()];
		enumTypeInsertEntry(yyattribute(2 - 4), NULL);
#line 686 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 250 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3); char * anony_name = curr_table->getAnony(); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(new Node(anony_idt_t, anony_name));
		returnScope(); giv.g_sf.type = g_converter[yyattribute(1 - 3)->getString()];
		enumTypeInsertEntry((*(YYSTYPE YYFAR*)yyvalptr)->getChild(0), NULL);
#line 701 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 253 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); yyattribute(2 - 2)->setType(type_name_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
		enumTypeInsertEntry(yyattribute(2 - 2), NULL);
#line 715 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 258 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(e_type_sf_t, "enum");
#line 728 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 262 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(idt_sf_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 741 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 263 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(idt_sf_t); yyattribute(2 - 2) = new Node(ptr_t, "pointer"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2)); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
#line 754 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 264 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(ptr_t, "pointer"); giv.g_pt = PtUnit();
#line 767 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 270 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 3)); giv.g_sf = SfUnit();
#line 780 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 271 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); giv.g_sf = SfUnit();
#line 793 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 275 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2)); // incomplete
		if (giv.g_sf.type == default_d) giv.g_sf.type = g_converter[yyattribute(2 - 2)->getString()]; else { cout << "Duplicate type!" << endl; system("pause");}
#line 807 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 277 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 820 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 278 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); giv.g_sf.type = g_converter[yyattribute(1 - 1)->getString()];
#line 833 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 279 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 846 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 283 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 859 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 284 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 872 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 288 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "="); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 885 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 289 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 898 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 293 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 2); (*(YYSTYPE YYFAR*)yyvalptr)->addFront(yyattribute(1 - 2)); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
		declInsertEntry(yyattribute(2 - 2));
#line 912 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 295 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); declInsertEntry(yyattribute(1 - 1));
#line 925 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 299 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 4)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4)); giv.g_cate = array_st; ++giv.g_dim;
#line 938 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 300 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 3)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); giv.g_cate = array_st; ++giv.g_dim;
#line 951 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 301 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 964 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 305 ".\\myparser.y"
giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;
#line 977 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 306 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 5)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 5));
		funcInsertEntry(yyattribute(1 - 5));
#line 991 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 308 ".\\myparser.y"
giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;
#line 1004 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 309 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 4)->getCharP()); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4));
		funcInsertEntry(yyattribute(1 - 4));
#line 1018 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 314 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); returnScope();
#line 1031 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 315 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1044 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 319 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(init_val_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1057 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 320 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1070 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 324 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3)); addParamList();
#line 1083 "myparser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 325 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); addParamList();
#line 1096 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 329 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 1109 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 330 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2)); giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
#line 1122 "myparser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 331 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 1));
#line 1135 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 335 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 1148 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 336 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1161 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 340 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 6));
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
#line 1175 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 342 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5));
#line 1188 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 343 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 6));
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
#line 1202 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 345 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5));
#line 1215 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 346 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit();
#line 1229 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 348 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(su_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 3));
#line 1242 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 352 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(e_decl_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1255 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 353 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1268 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 357 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(e_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
		enumVarInsertEntry(yyattribute(1 - 3));
#line 1282 "myparser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 359 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(e_decl_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 1));
		enumVarInsertEntry(yyattribute(1 - 1));
#line 1296 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 366 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 4));
		giv.g_pt_list.push_back(giv.g_pt); giv.g_pt = PtUnit(); funcSetEntry(yyattribute(3 - 4));
#line 1310 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 368 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
		funcSetEntry(yyattribute(2 - 3));
#line 1324 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 370 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
		funcSetEntry(yyattribute(1 - 2));
#line 1338 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 377 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ","); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1351 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 378 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1364 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 382 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1377 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 383 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1390 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 387 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1403 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 391 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "? :"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5));
#line 1416 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 392 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1429 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 396 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "||"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1442 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 397 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1455 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 401 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&&"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1468 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 402 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1481 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 406 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "|"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1494 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 407 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1507 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 411 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "^"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1520 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 412 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1533 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 416 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1546 "myparser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 417 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1559 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 421 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "=="); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1572 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 422 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "!="); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1585 "myparser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 423 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1598 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 427 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<="); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1611 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 428 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">="); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1624 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 429 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1637 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 430 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1650 "myparser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 431 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1663 "myparser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 435 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<<"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1676 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 436 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">>"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1689 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 437 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1702 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 441 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1715 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 442 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1728 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 443 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1741 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 447 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "*"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1754 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 448 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "/"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1767 "myparser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 449 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "%"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1780 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 450 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1793 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 454 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 1806 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 455 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "++"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 1819 "myparser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 456 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "--"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 1832 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 457 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "sizeof( )"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
#line 1845 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 458 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "sizeof( )"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
#line 1858 "myparser.cpp"
			}
		}
		break;
	case 118:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 459 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1871 "myparser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 463 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "( )"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 4));
#line 1884 "myparser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 464 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1897 "myparser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 468 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "[ ]"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
#line 1910 "myparser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 469 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "( )"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 4));
#line 1923 "myparser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 470 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "( )"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3));
#line 1936 "myparser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 471 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "."); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1949 "myparser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 472 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "->"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 1962 "myparser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 473 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "++"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2));
#line 1975 "myparser.cpp"
			}
		}
		break;
	case 127:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 474 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "--"); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2));
#line 1988 "myparser.cpp"
			}
		}
		break;
	case 128:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 475 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2001 "myparser.cpp"
			}
		}
		break;
	case 129:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 479 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2014 "myparser.cpp"
			}
		}
		break;
	case 130:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 480 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2027 "myparser.cpp"
			}
		}
		break;
	case 131:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 481 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 2040 "myparser.cpp"
			}
		}
		break;
	case 132:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 485 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "=");
#line 2053 "myparser.cpp"
			}
		}
		break;
	case 133:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 486 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+=");
#line 2066 "myparser.cpp"
			}
		}
		break;
	case 134:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 487 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-=");
#line 2079 "myparser.cpp"
			}
		}
		break;
	case 135:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 488 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "*=");
#line 2092 "myparser.cpp"
			}
		}
		break;
	case 136:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 489 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "/=");
#line 2105 "myparser.cpp"
			}
		}
		break;
	case 137:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 490 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "%=");
#line 2118 "myparser.cpp"
			}
		}
		break;
	case 138:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 491 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&=");
#line 2131 "myparser.cpp"
			}
		}
		break;
	case 139:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 492 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "|=");
#line 2144 "myparser.cpp"
			}
		}
		break;
	case 140:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 493 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "^=");
#line 2157 "myparser.cpp"
			}
		}
		break;
	case 141:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 494 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "~=");
#line 2170 "myparser.cpp"
			}
		}
		break;
	case 142:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 495 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<<=");
#line 2183 "myparser.cpp"
			}
		}
		break;
	case 143:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 496 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">>=");
#line 2196 "myparser.cpp"
			}
		}
		break;
	case 144:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 500 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "*");
#line 2209 "myparser.cpp"
			}
		}
		break;
	case 145:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 501 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&");
#line 2222 "myparser.cpp"
			}
		}
		break;
	case 146:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 502 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+");
#line 2235 "myparser.cpp"
			}
		}
		break;
	case 147:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 503 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-");
#line 2248 "myparser.cpp"
			}
		}
		break;
	case 148:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 504 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "~");
#line 2261 "myparser.cpp"
			}
		}
		break;
	case 149:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 505 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "!");
#line 2274 "myparser.cpp"
			}
		}
		break;
	case 150:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 509 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2287 "myparser.cpp"
			}
		}
		break;
	case 151:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 510 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2300 "myparser.cpp"
			}
		}
		break;
	case 152:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 511 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2313 "myparser.cpp"
			}
		}
		break;
	case 153:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 512 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2326 "myparser.cpp"
			}
		}
		break;
	case 154:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 513 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2339 "myparser.cpp"
			}
		}
		break;
	case 155:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 519 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2352 "myparser.cpp"
			}
		}
		break;
	case 156:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 520 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2365 "myparser.cpp"
			}
		}
		break;
	case 157:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 521 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2378 "myparser.cpp"
			}
		}
		break;
	case 158:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 522 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2391 "myparser.cpp"
			}
		}
		break;
	case 159:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 523 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2404 "myparser.cpp"
			}
		}
		break;
	case 160:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 524 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2417 "myparser.cpp"
			}
		}
		break;
	case 161:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 528 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(goto_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 3));
#line 2430 "myparser.cpp"
			}
		}
		break;
	case 162:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 529 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(break_stmt_t);
#line 2443 "myparser.cpp"
			}
		}
		break;
	case 163:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 530 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(continue_stmt_t);
#line 2456 "myparser.cpp"
			}
		}
		break;
	case 164:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 531 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(return_stmt_t);
#line 2469 "myparser.cpp"
			}
		}
		break;
	case 165:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 532 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(return_stmt_t);
#line 2482 "myparser.cpp"
			}
		}
		break;
	case 166:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 536 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(while_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 5));
#line 2495 "myparser.cpp"
			}
		}
		break;
	case 167:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 537 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(dowhile_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 6));
#line 2508 "myparser.cpp"
			}
		}
		break;
	case 168:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 538 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 7)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 7)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 7)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(6 - 7));
#line 2521 "myparser.cpp"
			}
		}
		break;
	case 169:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 539 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 6)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 6));
#line 2534 "myparser.cpp"
			}
		}
		break;
	case 170:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 543 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 2547 "myparser.cpp"
			}
		}
		break;
	case 171:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 544 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(empty_stmt_t);
#line 2560 "myparser.cpp"
			}
		}
		break;
	case 172:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 548 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(case_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 4)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(4 - 4));
#line 2573 "myparser.cpp"
			}
		}
		break;
	case 173:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 549 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(default_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 2586 "myparser.cpp"
			}
		}
		break;
	case 174:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 550 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(label_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 3));
#line 2599 "myparser.cpp"
			}
		}
		break;
	case 175:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 554 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 3)); returnScope();
#line 2612 "myparser.cpp"
			}
		}
		break;
	case 176:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 555 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); returnScope();
#line 2625 "myparser.cpp"
			}
		}
		break;
	case 177:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 559 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 7)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 7)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(7 - 7));
#line 2638 "myparser.cpp"
			}
		}
		break;
	case 178:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 560 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 5));
#line 2651 "myparser.cpp"
			}
		}
		break;
	case 179:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 561 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(switch_stmt_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(3 - 5)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(5 - 5));
#line 2664 "myparser.cpp"
			}
		}
		break;
	case 180:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 565 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 2677 "myparser.cpp"
			}
		}
		break;
	case 181:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 566 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(1 - 2)); (*(YYSTYPE YYFAR*)yyvalptr)->addBack(yyattribute(2 - 2));
#line 2690 "myparser.cpp"
			}
		}
		break;
	case 182:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 567 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2703 "myparser.cpp"
			}
		}
		break;
	case 183:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 568 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 2716 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "\'!\'", 33 },
		{ "\'%\'", 37 },
		{ "\'&\'", 38 },
		{ "\'(\'", 40 },
		{ "\')\'", 41 },
		{ "\'*\'", 42 },
		{ "\'+\'", 43 },
		{ "\',\'", 44 },
		{ "\'-\'", 45 },
		{ "\'.\'", 46 },
		{ "\'/\'", 47 },
		{ "\':\'", 58 },
		{ "\';\'", 59 },
		{ "\'=\'", 61 },
		{ "\'\?\'", 63 },
		{ "\'[\'", 91 },
		{ "\']\'", 93 },
		{ "\'^\'", 94 },
		{ "\'{\'", 123 },
		{ "\'|\'", 124 },
		{ "\'}\'", 125 },
		{ "\'~\'", 126 },
		{ "error", 256 },
		{ "VOID", 257 },
		{ "INT", 258 },
		{ "FLOAT", 259 },
		{ "DOUBLE", 260 },
		{ "CHAR", 261 },
		{ "BOOL", 262 },
		{ "STRING", 263 },
		{ "AUTO", 264 },
		{ "STRUCT", 265 },
		{ "UNION", 266 },
		{ "ENUM", 267 },
		{ "CONST", 268 },
		{ "VOLATILE", 269 },
		{ "SIZEOF", 270 },
		{ "GOTO", 271 },
		{ "BREAK", 272 },
		{ "CONTINUE", 273 },
		{ "RETURN", 274 },
		{ "WHILE", 275 },
		{ "DO", 276 },
		{ "FOR", 277 },
		{ "IF", 278 },
		{ "SWITCH", 279 },
		{ "CASE", 280 },
		{ "DEFAULT", 281 },
		{ "NO_ELSE", 282 },
		{ "ELSE", 283 },
		{ "ADDASSIGN", 284 },
		{ "SUBASSIGN", 285 },
		{ "MULASSIGN", 286 },
		{ "DIVASSIGN", 287 },
		{ "MODASSIGN", 288 },
		{ "ANDASSIGN", 289 },
		{ "ORASSIGN", 290 },
		{ "XORASSIGN", 291 },
		{ "REVASSIGN", 292 },
		{ "LSHIFTASSIGN", 293 },
		{ "RSHIFTASSIGN", 294 },
		{ "OR", 295 },
		{ "AND", 296 },
		{ "EQ", 297 },
		{ "NE", 298 },
		{ "LE", 299 },
		{ "GE", 300 },
		{ "LT", 301 },
		{ "GT", 302 },
		{ "INC", 303 },
		{ "DEC", 304 },
		{ "PT", 305 },
		{ "LSHIFT", 306 },
		{ "RSHIFT", 307 },
		{ "INTVAL", 308 },
		{ "DOUBLEVAL", 309 },
		{ "BOOLVAL", 310 },
		{ "CHARVAL", 311 },
		{ "STRINGVAL", 312 },
		{ "ID", 313 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: blocks",
		"blocks: blocks block",
		"blocks: block",
		"block: decl",
		"block: func",
		"type: VOID",
		"type: INT",
		"type: FLOAT",
		"type: DOUBLE",
		"type: CHAR",
		"type: BOOL",
		"type: STRING",
		"type: AUTO",
		"type: struct_union_type",
		"type: enum_type",
		"type_qf_for_sf: CONST",
		"type_qf_for_sf: VOLATILE",
		"type_qf_for_pt: CONST",
		"type_qf_for_pt: VOLATILE",
		"struct_union_type: struct_union ID \'{\' struct_union_decl_list \'}\'",
		"struct_union_type: struct_union \'{\' struct_union_decl_list \'}\'",
		"struct_union_type: struct_union ID \'{\' \'}\'",
		"struct_union_type: struct_union \'{\' \'}\'",
		"struct_union_type: struct_union ID",
		"struct_union: STRUCT",
		"struct_union: UNION",
		"enum_type: enum ID \'{\' enum_decl_list \'}\'",
		"enum_type: enum \'{\' enum_decl_list \'}\'",
		"enum_type: enum ID \'{\' \'}\'",
		"enum_type: enum \'{\' \'}\'",
		"enum_type: enum ID",
		"enum: ENUM",
		"pointer: pointer type_qf_for_pt",
		"pointer: pointer \'*\'",
		"pointer: \'*\'",
		"decl: decl_sf decl_list \';\'",
		"decl: decl_sf \';\'",
		"decl_sf: decl_sf type",
		"decl_sf: decl_sf type_qf_for_sf",
		"decl_sf: type",
		"decl_sf: type_qf_for_sf",
		"decl_list: decl_list \',\' decl_init",
		"decl_list: decl_init",
		"decl_init: decl_head \'=\' init_val",
		"decl_init: decl_head",
		"decl_head: pointer var_decl_head",
		"decl_head: var_decl_head",
		"var_decl_head: var_decl_head \'[\' const_expr \']\'",
		"var_decl_head: var_decl_head \'[\' \']\'",
		"var_decl_head: ID",
		"$$1:",
		"func_decl_head: ID \'(\' $$1 param_list \')\'",
		"$$2:",
		"func_decl_head: ID \'(\' $$2 \')\'",
		"init_val: \'{\' init_val_list \'}\'",
		"init_val: assign_expr",
		"init_val_list: init_val_list \',\' init_val",
		"init_val_list: init_val",
		"param_list: param_list \',\' param",
		"param_list: param",
		"param: decl_sf decl_init",
		"param: decl_sf pointer",
		"param: decl_sf",
		"struct_union_decl_list: struct_union_decl_list struct_union_decl",
		"struct_union_decl_list: struct_union_decl",
		"struct_union_decl: decl_sf pointer ID \'=\' const_expr \';\'",
		"struct_union_decl: decl_sf ID \'=\' const_expr \';\'",
		"struct_union_decl: decl_sf pointer ID \':\' const_expr \';\'",
		"struct_union_decl: decl_sf ID \':\' const_expr \';\'",
		"struct_union_decl: decl_sf pointer ID \';\'",
		"struct_union_decl: decl_sf ID \';\'",
		"enum_decl_list: enum_decl_list \',\' enum_decl",
		"enum_decl_list: enum_decl",
		"enum_decl: ID \'=\' const_expr",
		"enum_decl: ID",
		"func: decl_sf pointer func_decl_head compound_stmt",
		"func: decl_sf func_decl_head compound_stmt",
		"func: func_decl_head compound_stmt",
		"expr: expr \',\' assign_expr",
		"expr: assign_expr",
		"assign_expr: ID assign_op assign_expr",
		"assign_expr: const_expr",
		"const_expr: ternary_expr",
		"ternary_expr: or_expr \'\?\' ternary_expr \':\' ternary_expr",
		"ternary_expr: or_expr",
		"or_expr: or_expr OR and_expr",
		"or_expr: and_expr",
		"and_expr: and_expr AND bit_or_expr",
		"and_expr: bit_or_expr",
		"bit_or_expr: bit_or_expr \'|\' bit_xor_expr",
		"bit_or_expr: bit_xor_expr",
		"bit_xor_expr: bit_xor_expr \'^\' bit_and_expr",
		"bit_xor_expr: bit_and_expr",
		"bit_and_expr: bit_and_expr \'&\' equal_expr",
		"bit_and_expr: equal_expr",
		"equal_expr: equal_expr EQ greater_less_expr",
		"equal_expr: equal_expr NE greater_less_expr",
		"equal_expr: greater_less_expr",
		"greater_less_expr: greater_less_expr LE shift_expr",
		"greater_less_expr: greater_less_expr GE shift_expr",
		"greater_less_expr: greater_less_expr LT shift_expr",
		"greater_less_expr: greater_less_expr GT shift_expr",
		"greater_less_expr: shift_expr",
		"shift_expr: shift_expr LSHIFT addBack_sub_expr",
		"shift_expr: shift_expr RSHIFT addBack_sub_expr",
		"shift_expr: addBack_sub_expr",
		"addBack_sub_expr: addBack_sub_expr \'+\' mul_div_mod_expr",
		"addBack_sub_expr: addBack_sub_expr \'-\' mul_div_mod_expr",
		"addBack_sub_expr: mul_div_mod_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'*\' unary_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'/\' unary_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'%\' unary_expr",
		"mul_div_mod_expr: unary_expr",
		"unary_expr: unary_op cast_expr",
		"unary_expr: INC unary_expr",
		"unary_expr: DEC unary_expr",
		"unary_expr: SIZEOF \'(\' expr \')\'",
		"unary_expr: SIZEOF \'(\' type \')\'",
		"unary_expr: postfix_expr",
		"cast_expr: \'(\' type \')\' cast_expr",
		"cast_expr: unary_expr",
		"postfix_expr: postfix_expr \'[\' expr \']\'",
		"postfix_expr: postfix_expr \'(\' expr \')\'",
		"postfix_expr: postfix_expr \'(\' \')\'",
		"postfix_expr: postfix_expr \'.\' ID",
		"postfix_expr: postfix_expr PT ID",
		"postfix_expr: postfix_expr INC",
		"postfix_expr: postfix_expr DEC",
		"postfix_expr: basic_expr",
		"basic_expr: ID",
		"basic_expr: val",
		"basic_expr: \'(\' expr \')\'",
		"assign_op: \'=\'",
		"assign_op: ADDASSIGN",
		"assign_op: SUBASSIGN",
		"assign_op: MULASSIGN",
		"assign_op: DIVASSIGN",
		"assign_op: MODASSIGN",
		"assign_op: ANDASSIGN",
		"assign_op: ORASSIGN",
		"assign_op: XORASSIGN",
		"assign_op: REVASSIGN",
		"assign_op: LSHIFTASSIGN",
		"assign_op: RSHIFTASSIGN",
		"unary_op: \'*\'",
		"unary_op: \'&\'",
		"unary_op: \'+\'",
		"unary_op: \'-\'",
		"unary_op: \'~\'",
		"unary_op: \'!\'",
		"val: INTVAL",
		"val: DOUBLEVAL",
		"val: BOOLVAL",
		"val: CHARVAL",
		"val: STRINGVAL",
		"stmt: jmp_stmt",
		"stmt: loop_stmt",
		"stmt: expr_stmt",
		"stmt: label_stmt",
		"stmt: compound_stmt",
		"stmt: conditional_stmt",
		"jmp_stmt: GOTO ID \';\'",
		"jmp_stmt: BREAK \';\'",
		"jmp_stmt: CONTINUE \';\'",
		"jmp_stmt: RETURN expr \';\'",
		"jmp_stmt: RETURN \';\'",
		"loop_stmt: WHILE \'(\' expr \')\' stmt",
		"loop_stmt: DO stmt WHILE \'(\' expr \')\'",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt expr \')\' stmt",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt \')\' stmt",
		"expr_stmt: expr \';\'",
		"expr_stmt: \';\'",
		"label_stmt: CASE const_expr \':\' stmt",
		"label_stmt: DEFAULT \':\' stmt",
		"label_stmt: ID \':\' stmt",
		"compound_stmt: \'{\' stmt_decl_list \'}\'",
		"compound_stmt: \'{\' \'}\'",
		"conditional_stmt: IF \'(\' expr \')\' stmt ELSE stmt",
		"conditional_stmt: IF \'(\' expr \')\' stmt",
		"conditional_stmt: SWITCH \'(\' expr \')\' stmt",
		"stmt_decl_list: stmt_decl_list stmt",
		"stmt_decl_list: stmt_decl_list decl",
		"stmt_decl_list: stmt",
		"stmt_decl_list: decl"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 2, 2, 1 },
		{ 2, 1, 2 },
		{ 3, 1, 3 },
		{ 3, 1, 4 },
		{ 4, 1, 5 },
		{ 4, 1, 6 },
		{ 4, 1, 7 },
		{ 4, 1, 8 },
		{ 4, 1, 9 },
		{ 4, 1, 10 },
		{ 4, 1, 11 },
		{ 4, 1, 12 },
		{ 4, 1, 13 },
		{ 4, 1, 14 },
		{ 5, 1, 15 },
		{ 5, 1, 16 },
		{ 6, 1, 17 },
		{ 6, 1, 18 },
		{ 7, 5, 19 },
		{ 7, 4, 20 },
		{ 7, 4, 21 },
		{ 7, 3, 22 },
		{ 7, 2, 23 },
		{ 8, 1, 24 },
		{ 8, 1, 25 },
		{ 9, 5, 26 },
		{ 9, 4, 27 },
		{ 9, 4, 28 },
		{ 9, 3, 29 },
		{ 9, 2, 30 },
		{ 10, 1, 31 },
		{ 11, 2, 32 },
		{ 11, 2, 33 },
		{ 11, 1, 34 },
		{ 12, 3, 35 },
		{ 12, 2, 36 },
		{ 13, 2, 37 },
		{ 13, 2, 38 },
		{ 13, 1, 39 },
		{ 13, 1, 40 },
		{ 14, 3, 41 },
		{ 14, 1, 42 },
		{ 15, 3, 43 },
		{ 15, 1, 44 },
		{ 16, 2, 45 },
		{ 16, 1, 46 },
		{ 17, 4, 47 },
		{ 17, 3, 48 },
		{ 17, 1, 49 },
		{ 19, 0, 50 },
		{ 18, 5, 51 },
		{ 20, 0, 52 },
		{ 18, 4, 53 },
		{ 21, 3, 54 },
		{ 21, 1, 55 },
		{ 22, 3, 56 },
		{ 22, 1, 57 },
		{ 23, 3, 58 },
		{ 23, 1, 59 },
		{ 24, 2, 60 },
		{ 24, 2, 61 },
		{ 24, 1, 62 },
		{ 25, 2, 63 },
		{ 25, 1, 64 },
		{ 26, 6, 65 },
		{ 26, 5, 66 },
		{ 26, 6, 67 },
		{ 26, 5, 68 },
		{ 26, 4, 69 },
		{ 26, 3, 70 },
		{ 27, 3, 71 },
		{ 27, 1, 72 },
		{ 28, 3, 73 },
		{ 28, 1, 74 },
		{ 29, 4, 75 },
		{ 29, 3, 76 },
		{ 29, 2, 77 },
		{ 30, 3, 78 },
		{ 30, 1, 79 },
		{ 31, 3, 80 },
		{ 31, 1, 81 },
		{ 32, 1, 82 },
		{ 33, 5, 83 },
		{ 33, 1, 84 },
		{ 34, 3, 85 },
		{ 34, 1, 86 },
		{ 35, 3, 87 },
		{ 35, 1, 88 },
		{ 36, 3, 89 },
		{ 36, 1, 90 },
		{ 37, 3, 91 },
		{ 37, 1, 92 },
		{ 38, 3, 93 },
		{ 38, 1, 94 },
		{ 39, 3, 95 },
		{ 39, 3, 96 },
		{ 39, 1, 97 },
		{ 40, 3, 98 },
		{ 40, 3, 99 },
		{ 40, 3, 100 },
		{ 40, 3, 101 },
		{ 40, 1, 102 },
		{ 41, 3, 103 },
		{ 41, 3, 104 },
		{ 41, 1, 105 },
		{ 42, 3, 106 },
		{ 42, 3, 107 },
		{ 42, 1, 108 },
		{ 43, 3, 109 },
		{ 43, 3, 110 },
		{ 43, 3, 111 },
		{ 43, 1, 112 },
		{ 44, 2, 113 },
		{ 44, 2, 114 },
		{ 44, 2, 115 },
		{ 44, 4, 116 },
		{ 44, 4, 117 },
		{ 44, 1, 118 },
		{ 45, 4, 119 },
		{ 45, 1, 120 },
		{ 46, 4, 121 },
		{ 46, 4, 122 },
		{ 46, 3, 123 },
		{ 46, 3, 124 },
		{ 46, 3, 125 },
		{ 46, 2, 126 },
		{ 46, 2, 127 },
		{ 46, 1, 128 },
		{ 47, 1, 129 },
		{ 47, 1, 130 },
		{ 47, 3, 131 },
		{ 48, 1, 132 },
		{ 48, 1, 133 },
		{ 48, 1, 134 },
		{ 48, 1, 135 },
		{ 48, 1, 136 },
		{ 48, 1, 137 },
		{ 48, 1, 138 },
		{ 48, 1, 139 },
		{ 48, 1, 140 },
		{ 48, 1, 141 },
		{ 48, 1, 142 },
		{ 48, 1, 143 },
		{ 49, 1, 144 },
		{ 49, 1, 145 },
		{ 49, 1, 146 },
		{ 49, 1, 147 },
		{ 49, 1, 148 },
		{ 49, 1, 149 },
		{ 50, 1, 150 },
		{ 50, 1, 151 },
		{ 50, 1, 152 },
		{ 50, 1, 153 },
		{ 50, 1, 154 },
		{ 51, 1, 155 },
		{ 51, 1, 156 },
		{ 51, 1, 157 },
		{ 51, 1, 158 },
		{ 51, 1, 159 },
		{ 51, 1, 160 },
		{ 52, 3, 161 },
		{ 52, 2, 162 },
		{ 52, 2, 163 },
		{ 52, 3, 164 },
		{ 52, 2, 165 },
		{ 53, 5, 166 },
		{ 53, 6, 167 },
		{ 53, 7, 168 },
		{ 53, 6, 169 },
		{ 54, 2, 170 },
		{ 54, 1, 171 },
		{ 55, 4, 172 },
		{ 55, 3, 173 },
		{ 55, 3, 174 },
		{ 56, 3, 175 },
		{ 56, 2, 176 },
		{ 57, 7, 177 },
		{ 57, 5, 178 },
		{ 57, 5, 179 },
		{ 58, 2, 180 },
		{ 58, 2, 181 },
		{ 58, 1, 182 },
		{ 58, 1, 183 }
	};
	yyreduction = reduction;

	yytokenaction_size = 327;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 310, YYAT_SHIFT, 70 },
		{ 128, YYAT_SHIFT, 31 },
		{ 125, YYAT_SHIFT, 211 },
		{ 217, YYAT_SHIFT, 54 },
		{ 118, YYAT_SHIFT, 205 },
		{ 310, YYAT_SHIFT, 71 },
		{ 99, YYAT_SHIFT, 32 },
		{ 310, YYAT_SHIFT, 72 },
		{ 125, YYAT_SHIFT, 212 },
		{ 310, YYAT_SHIFT, 73 },
		{ 310, YYAT_SHIFT, 74 },
		{ 22, YYAT_SHIFT, 42 },
		{ 310, YYAT_SHIFT, 75 },
		{ 67, YYAT_SHIFT, 31 },
		{ 60, YYAT_SHIFT, 31 },
		{ 19, YYAT_SHIFT, 29 },
		{ 225, YYAT_SHIFT, 273 },
		{ 136, YYAT_SHIFT, 133 },
		{ 289, YYAT_SHIFT, 208 },
		{ 270, YYAT_SHIFT, 186 },
		{ 160, YYAT_SHIFT, 186 },
		{ 37, YYAT_SHIFT, 60 },
		{ 258, YYAT_SHIFT, 201 },
		{ 257, YYAT_SHIFT, 201 },
		{ 265, YYAT_SHIFT, 190 },
		{ 265, YYAT_SHIFT, 191 },
		{ 310, YYAT_SHIFT, 76 },
		{ 258, YYAT_SHIFT, 202 },
		{ 257, YYAT_SHIFT, 202 },
		{ 102, YYAT_SHIFT, 184 },
		{ 301, YYAT_SHIFT, 310 },
		{ 300, YYAT_SHIFT, 309 },
		{ 258, YYAT_SHIFT, 203 },
		{ 257, YYAT_SHIFT, 203 },
		{ 300, YYAT_SHIFT, 186 },
		{ 160, YYAT_SHIFT, 236 },
		{ 37, YYAT_SHIFT, 61 },
		{ 289, YYAT_ERROR, 0 },
		{ 26, YYAT_SHIFT, 1 },
		{ 26, YYAT_SHIFT, 2 },
		{ 26, YYAT_SHIFT, 3 },
		{ 26, YYAT_SHIFT, 4 },
		{ 26, YYAT_SHIFT, 5 },
		{ 26, YYAT_SHIFT, 6 },
		{ 26, YYAT_SHIFT, 7 },
		{ 26, YYAT_SHIFT, 8 },
		{ 26, YYAT_SHIFT, 9 },
		{ 26, YYAT_SHIFT, 10 },
		{ 26, YYAT_SHIFT, 11 },
		{ 26, YYAT_SHIFT, 12 },
		{ 26, YYAT_SHIFT, 13 },
		{ 114, YYAT_SHIFT, 201 },
		{ 261, YYAT_SHIFT, 196 },
		{ 125, YYAT_SHIFT, 213 },
		{ 261, YYAT_SHIFT, 197 },
		{ 151, YYAT_SHIFT, 54 },
		{ 114, YYAT_SHIFT, 202 },
		{ 252, YYAT_SHIFT, 192 },
		{ 252, YYAT_SHIFT, 193 },
		{ 252, YYAT_SHIFT, 194 },
		{ 252, YYAT_SHIFT, 195 },
		{ 114, YYAT_SHIFT, 203 },
		{ 251, YYAT_SHIFT, 192 },
		{ 251, YYAT_SHIFT, 193 },
		{ 251, YYAT_SHIFT, 194 },
		{ 251, YYAT_SHIFT, 195 },
		{ 98, YYAT_SHIFT, 170 },
		{ 298, YYAT_SHIFT, 307 },
		{ 270, YYAT_SHIFT, 291 },
		{ 98, YYAT_SHIFT, 171 },
		{ 110, YYAT_SHIFT, 192 },
		{ 110, YYAT_SHIFT, 193 },
		{ 110, YYAT_SHIFT, 194 },
		{ 110, YYAT_SHIFT, 195 },
		{ 230, YYAT_SHIFT, 277 },
		{ 230, YYAT_SHIFT, 278 },
		{ 129, YYAT_SHIFT, 219 },
		{ 230, YYAT_SHIFT, 279 },
		{ 296, YYAT_SHIFT, 306 },
		{ 129, YYAT_SHIFT, 220 },
		{ 142, YYAT_SHIFT, 171 },
		{ 208, YYAT_SHIFT, 1 },
		{ 208, YYAT_SHIFT, 2 },
		{ 208, YYAT_SHIFT, 3 },
		{ 208, YYAT_SHIFT, 4 },
		{ 208, YYAT_SHIFT, 5 },
		{ 208, YYAT_SHIFT, 6 },
		{ 208, YYAT_SHIFT, 7 },
		{ 208, YYAT_SHIFT, 8 },
		{ 208, YYAT_SHIFT, 9 },
		{ 208, YYAT_SHIFT, 10 },
		{ 208, YYAT_SHIFT, 11 },
		{ 295, YYAT_SHIFT, 305 },
		{ 310, YYAT_SHIFT, 78 },
		{ 26, YYAT_SHIFT, 14 },
		{ 256, YYAT_SHIFT, 199 },
		{ 256, YYAT_SHIFT, 200 },
		{ 225, YYAT_SHIFT, 274 },
		{ 136, YYAT_SHIFT, 223 },
		{ 255, YYAT_SHIFT, 199 },
		{ 255, YYAT_SHIFT, 200 },
		{ 289, YYAT_ERROR, 0 },
		{ 220, YYAT_SHIFT, 1 },
		{ 220, YYAT_SHIFT, 2 },
		{ 220, YYAT_SHIFT, 3 },
		{ 220, YYAT_SHIFT, 4 },
		{ 220, YYAT_SHIFT, 5 },
		{ 220, YYAT_SHIFT, 6 },
		{ 220, YYAT_SHIFT, 7 },
		{ 220, YYAT_SHIFT, 8 },
		{ 220, YYAT_SHIFT, 9 },
		{ 220, YYAT_SHIFT, 10 },
		{ 220, YYAT_SHIFT, 11 },
		{ 220, YYAT_SHIFT, 12 },
		{ 220, YYAT_SHIFT, 13 },
		{ 150, YYAT_SHIFT, 227 },
		{ 150, YYAT_SHIFT, 228 },
		{ 260, YYAT_SHIFT, 196 },
		{ 150, YYAT_SHIFT, 229 },
		{ 260, YYAT_SHIFT, 197 },
		{ 111, YYAT_SHIFT, 196 },
		{ 288, YYAT_SHIFT, 72 },
		{ 111, YYAT_SHIFT, 197 },
		{ 254, YYAT_SHIFT, 199 },
		{ 254, YYAT_SHIFT, 200 },
		{ 253, YYAT_SHIFT, 199 },
		{ 253, YYAT_SHIFT, 200 },
		{ 113, YYAT_SHIFT, 199 },
		{ 113, YYAT_SHIFT, 200 },
		{ 109, YYAT_SHIFT, 190 },
		{ 109, YYAT_SHIFT, 191 },
		{ 284, YYAT_SHIFT, 299 },
		{ 283, YYAT_SHIFT, 142 },
		{ 276, YYAT_SHIFT, 294 },
		{ 275, YYAT_SHIFT, 293 },
		{ 273, YYAT_SHIFT, 141 },
		{ 118, YYAT_SHIFT, 1 },
		{ 118, YYAT_SHIFT, 2 },
		{ 118, YYAT_SHIFT, 3 },
		{ 118, YYAT_SHIFT, 4 },
		{ 118, YYAT_SHIFT, 5 },
		{ 118, YYAT_SHIFT, 6 },
		{ 118, YYAT_SHIFT, 7 },
		{ 118, YYAT_SHIFT, 8 },
		{ 118, YYAT_SHIFT, 9 },
		{ 118, YYAT_SHIFT, 10 },
		{ 118, YYAT_SHIFT, 11 },
		{ 118, YYAT_SHIFT, 12 },
		{ 118, YYAT_SHIFT, 13 },
		{ 268, YYAT_SHIFT, 290 },
		{ 266, YYAT_SHIFT, 289 },
		{ 259, YYAT_SHIFT, 204 },
		{ 250, YYAT_SHIFT, 198 },
		{ 249, YYAT_SHIFT, 189 },
		{ 247, YYAT_SHIFT, 188 },
		{ 246, YYAT_SHIFT, 288 },
		{ 241, YYAT_SHIFT, 286 },
		{ 240, YYAT_SHIFT, 285 },
		{ 239, YYAT_SHIFT, 76 },
		{ 238, YYAT_SHIFT, 283 },
		{ 237, YYAT_SHIFT, 282 },
		{ 234, YYAT_SHIFT, 281 },
		{ 233, YYAT_SHIFT, 280 },
		{ 216, YYAT_SHIFT, 271 },
		{ 212, YYAT_SHIFT, 269 },
		{ 211, YYAT_SHIFT, 267 },
		{ 166, YYAT_SHIFT, 242 },
		{ 162, YYAT_SHIFT, 238 },
		{ 156, YYAT_SHIFT, 235 },
		{ 154, YYAT_SHIFT, 232 },
		{ 153, YYAT_SHIFT, 231 },
		{ 147, YYAT_SHIFT, 226 },
		{ 139, YYAT_SHIFT, 138 },
		{ 133, YYAT_SHIFT, 50 },
		{ 115, YYAT_SHIFT, 204 },
		{ 112, YYAT_SHIFT, 198 },
		{ 106, YYAT_SHIFT, 189 },
		{ 105, YYAT_SHIFT, 188 },
		{ 104, YYAT_SHIFT, 187 },
		{ 90, YYAT_SHIFT, 167 },
		{ 88, YYAT_SHIFT, 165 },
		{ 87, YYAT_SHIFT, 164 },
		{ 86, YYAT_SHIFT, 163 },
		{ 84, YYAT_SHIFT, 161 },
		{ 83, YYAT_SHIFT, 159 },
		{ 82, YYAT_SHIFT, 158 },
		{ 81, YYAT_SHIFT, 157 },
		{ 80, YYAT_SHIFT, 156 },
		{ 79, YYAT_SHIFT, 155 },
		{ 69, YYAT_SHIFT, 152 },
		{ 66, YYAT_SHIFT, 148 },
		{ 63, YYAT_SHIFT, 145 },
		{ 59, YYAT_SHIFT, 44 },
		{ 58, YYAT_SHIFT, 63 },
		{ 53, YYAT_SHIFT, 135 },
		{ 51, YYAT_SHIFT, 134 },
		{ 50, YYAT_SHIFT, 132 },
		{ 48, YYAT_SHIFT, 131 },
		{ 44, YYAT_SHIFT, 77 },
		{ 43, YYAT_SHIFT, 69 },
		{ 42, YYAT_SHIFT, 65 },
		{ 22, YYAT_SHIFT, 43 },
		{ 40, YYAT_SHIFT, 63 },
		{ 39, YYAT_SHIFT, 62 },
		{ 35, YYAT_SHIFT, 33 },
		{ 19, YYAT_SHIFT, 30 },
		{ 33, YYAT_SHIFT, 28 },
		{ 30, YYAT_SHIFT, 53 },
		{ 29, YYAT_SHIFT, 49 },
		{ 28, YYAT_REDUCE, 53 },
		{ 27, YYAT_ACCEPT, 0 },
		{ 20, YYAT_SHIFT, 33 },
		{ 14, YYAT_SHIFT, 28 },
		{ 0, YYAT_SHIFT, 14 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 128, YYAT_SHIFT, 1 },
		{ 128, YYAT_SHIFT, 2 },
		{ 128, YYAT_SHIFT, 3 },
		{ 128, YYAT_SHIFT, 4 },
		{ 128, YYAT_SHIFT, 5 },
		{ 128, YYAT_SHIFT, 6 },
		{ 128, YYAT_SHIFT, 7 },
		{ 128, YYAT_SHIFT, 8 },
		{ 128, YYAT_SHIFT, 9 },
		{ 128, YYAT_SHIFT, 10 },
		{ 128, YYAT_SHIFT, 11 },
		{ 128, YYAT_SHIFT, 12 },
		{ 128, YYAT_SHIFT, 13 },
		{ 217, YYAT_SHIFT, 55 },
		{ 217, YYAT_SHIFT, 56 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 310, YYAT_SHIFT, 79 },
		{ 310, YYAT_SHIFT, 80 },
		{ 310, YYAT_SHIFT, 81 },
		{ 310, YYAT_SHIFT, 82 },
		{ 310, YYAT_SHIFT, 83 },
		{ 310, YYAT_SHIFT, 84 },
		{ 310, YYAT_SHIFT, 85 },
		{ 310, YYAT_SHIFT, 86 },
		{ 310, YYAT_SHIFT, 87 },
		{ 310, YYAT_SHIFT, 88 },
		{ 310, YYAT_SHIFT, 89 },
		{ 310, YYAT_SHIFT, 90 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 289, YYAT_ERROR, 0 },
		{ 99, YYAT_SHIFT, 138 },
		{ 102, YYAT_SHIFT, 185 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 125, YYAT_SHIFT, 214 },
		{ 125, YYAT_SHIFT, 215 },
		{ 125, YYAT_SHIFT, 216 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 310, YYAT_SHIFT, 91 },
		{ 310, YYAT_SHIFT, 92 },
		{ 128, YYAT_SHIFT, 138 },
		{ -1, YYAT_ERROR, 0 },
		{ 217, YYAT_SHIFT, 138 },
		{ 310, YYAT_SHIFT, 93 },
		{ 310, YYAT_SHIFT, 94 },
		{ 310, YYAT_SHIFT, 95 },
		{ 310, YYAT_SHIFT, 96 },
		{ 310, YYAT_SHIFT, 97 },
		{ 310, YYAT_SHIFT, 98 },
		{ 151, YYAT_SHIFT, 55 },
		{ 151, YYAT_SHIFT, 56 },
		{ -1, YYAT_ERROR, 0 },
		{ 67, YYAT_SHIFT, 150 },
		{ 60, YYAT_SHIFT, 138 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 289, YYAT_SHIFT, 146 },
		{ 98, YYAT_SHIFT, 172 },
		{ 98, YYAT_SHIFT, 173 },
		{ 98, YYAT_SHIFT, 174 },
		{ 98, YYAT_SHIFT, 175 },
		{ 98, YYAT_SHIFT, 176 },
		{ 98, YYAT_SHIFT, 177 },
		{ 98, YYAT_SHIFT, 178 },
		{ 98, YYAT_SHIFT, 179 },
		{ 98, YYAT_SHIFT, 180 },
		{ 98, YYAT_SHIFT, 181 },
		{ 98, YYAT_SHIFT, 182 },
		{ 142, YYAT_SHIFT, 172 },
		{ 142, YYAT_SHIFT, 173 },
		{ 142, YYAT_SHIFT, 174 },
		{ 142, YYAT_SHIFT, 175 },
		{ 142, YYAT_SHIFT, 176 },
		{ 142, YYAT_SHIFT, 177 },
		{ 142, YYAT_SHIFT, 178 },
		{ 142, YYAT_SHIFT, 179 },
		{ 142, YYAT_SHIFT, 180 },
		{ 142, YYAT_SHIFT, 181 },
		{ 142, YYAT_SHIFT, 182 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 151, YYAT_SHIFT, 230 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -100, 1, YYAT_DEFAULT, 220 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -108, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_DEFAULT, 99 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -112, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_DEFAULT, 59 },
		{ -219, 1, YYAT_REDUCE, 1 },
		{ 210, 1, YYAT_ERROR, 0 },
		{ 168, 1, YYAT_REDUCE, 51 },
		{ 83, 1, YYAT_DEFAULT, 133 },
		{ 84, 1, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 166, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ -109, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ -23, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ 142, 1, YYAT_REDUCE, 45 },
		{ 111, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_DEFAULT, 59 },
		{ 75, 1, YYAT_DEFAULT, 220 },
		{ 76, 1, YYAT_REDUCE, 24 },
		{ 73, 1, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 220 },
		{ 156, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 135, 1, YYAT_REDUCE, 75 },
		{ 70, 1, YYAT_DEFAULT, 136 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 69, 1, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 102, 1, YYAT_REDUCE, 46 },
		{ 69, 1, YYAT_ERROR, 0 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_DEFAULT, 273 },
		{ 98, 1, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 65, 1, YYAT_DEFAULT, 220 },
		{ -29, 1, YYAT_DEFAULT, 220 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 64, 1, YYAT_DEFAULT, 220 },
		{ 0, 0, YYAT_REDUCE, 150 },
		{ 0, 0, YYAT_REDUCE, 146 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_REDUCE, 145 },
		{ 0, 0, YYAT_REDUCE, 147 },
		{ 0, 0, YYAT_REDUCE, 148 },
		{ 0, 0, YYAT_REDUCE, 172 },
		{ 0, 0, YYAT_REDUCE, 177 },
		{ 0, 0, YYAT_REDUCE, 149 },
		{ 148, 1, YYAT_ERROR, 0 },
		{ -126, 1, YYAT_ERROR, 0 },
		{ 127, 1, YYAT_ERROR, 0 },
		{ 126, 1, YYAT_ERROR, 0 },
		{ 125, 1, YYAT_DEFAULT, 283 },
		{ 143, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 142, 1, YYAT_ERROR, 0 },
		{ 141, 1, YYAT_ERROR, 0 },
		{ 140, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 121, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 151 },
		{ 0, 0, YYAT_REDUCE, 152 },
		{ 0, 0, YYAT_REDUCE, 153 },
		{ 0, 0, YYAT_REDUCE, 154 },
		{ 0, 0, YYAT_REDUCE, 155 },
		{ 8, 1, YYAT_REDUCE, 130 },
		{ -53, 1, YYAT_DEFAULT, 67 },
		{ 0, 0, YYAT_REDUCE, 184 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ -34, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 119, 1, YYAT_DEFAULT, 160 },
		{ -119, 1, YYAT_REDUCE, 87 },
		{ 52, 1, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 160 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ -168, 1, YYAT_REDUCE, 95 },
		{ -229, 1, YYAT_REDUCE, 98 },
		{ 77, 1, YYAT_REDUCE, 106 },
		{ 81, 1, YYAT_REDUCE, 91 },
		{ -179, 1, YYAT_REDUCE, 103 },
		{ 14, 1, YYAT_REDUCE, 109 },
		{ 136, 1, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 156 },
		{ 0, 0, YYAT_REDUCE, 158 },
		{ -121, 1, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 157 },
		{ 0, 0, YYAT_REDUCE, 161 },
		{ 0, 0, YYAT_REDUCE, 159 },
		{ 0, 0, YYAT_REDUCE, 183 },
		{ 0, 0, YYAT_REDUCE, 129 },
		{ 0, 0, YYAT_DEFAULT, 289 },
		{ -38, 1, YYAT_REDUCE, 119 },
		{ 0, 0, YYAT_REDUCE, 131 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ -41, 1, YYAT_REDUCE, 63 },
		{ 35, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ -140, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -27, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ -141, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_DEFAULT, 273 },
		{ 19, 1, YYAT_REDUCE, 130 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 130 },
		{ 78, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 57, 1, YYAT_ERROR, 0 },
		{ 13, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 45, 1, YYAT_DEFAULT, 220 },
		{ 128, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_DEFAULT, 208 },
		{ 109, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 163 },
		{ 0, 0, YYAT_REDUCE, 164 },
		{ 0, 0, YYAT_REDUCE, 166 },
		{ -24, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ -108, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 239 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 108, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 133 },
		{ 0, 0, YYAT_REDUCE, 134 },
		{ 0, 0, YYAT_REDUCE, 135 },
		{ 0, 0, YYAT_REDUCE, 136 },
		{ 0, 0, YYAT_REDUCE, 137 },
		{ 0, 0, YYAT_REDUCE, 138 },
		{ 0, 0, YYAT_REDUCE, 139 },
		{ 0, 0, YYAT_REDUCE, 140 },
		{ 0, 0, YYAT_REDUCE, 141 },
		{ 0, 0, YYAT_REDUCE, 142 },
		{ 0, 0, YYAT_REDUCE, 143 },
		{ 0, 0, YYAT_REDUCE, 144 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_REDUCE, 171 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 176 },
		{ 0, 0, YYAT_REDUCE, 182 },
		{ 0, 0, YYAT_REDUCE, 181 },
		{ -176, 1, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ 124, 1, YYAT_DEFAULT, 284 },
		{ -149, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ -150, 1, YYAT_ERROR, 0 },
		{ -39, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -155, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 16, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 132 },
		{ 121, 1, YYAT_ERROR, 0 },
		{ 120, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_REDUCE, 162 },
		{ 0, 0, YYAT_REDUCE, 165 },
		{ 119, 1, YYAT_DEFAULT, 300 },
		{ 119, 1, YYAT_ERROR, 0 },
		{ 99, 1, YYAT_DEFAULT, 283 },
		{ 116, 1, YYAT_DEFAULT, 300 },
		{ 115, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 174 },
		{ 0, 0, YYAT_REDUCE, 175 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 97, 1, YYAT_ERROR, 0 },
		{ -142, 1, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 29, 1, YYAT_REDUCE, 88 },
		{ 58, 1, YYAT_REDUCE, 90 },
		{ -237, 1, YYAT_REDUCE, 96 },
		{ -242, 1, YYAT_REDUCE, 97 },
		{ -181, 1, YYAT_REDUCE, 99 },
		{ -183, 1, YYAT_REDUCE, 100 },
		{ -207, 1, YYAT_REDUCE, 101 },
		{ -211, 1, YYAT_REDUCE, 102 },
		{ -14, 1, YYAT_REDUCE, 107 },
		{ -15, 1, YYAT_REDUCE, 108 },
		{ 113, 1, YYAT_REDUCE, 92 },
		{ 74, 1, YYAT_REDUCE, 104 },
		{ 9, 1, YYAT_REDUCE, 105 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ -273, 1, YYAT_REDUCE, 94 },
		{ 109, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 108, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 12, 1, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 75, 1, YYAT_ERROR, 0 },
		{ 74, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_DEFAULT, 288 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ -181, 1, YYAT_DEFAULT, 288 },
		{ 90, 1, YYAT_DEFAULT, 283 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 173 },
		{ 81, 1, YYAT_DEFAULT, 289 },
		{ -22, 1, YYAT_DEFAULT, 310 },
		{ 0, 0, YYAT_REDUCE, 123 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 33, 1, YYAT_ERROR, 0 },
		{ 19, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 167 },
		{ 26, 1, YYAT_DEFAULT, 300 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ -10, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_REDUCE, 179 },
		{ 0, 0, YYAT_REDUCE, 180 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 168 },
		{ 0, 0, YYAT_REDUCE, 170 },
		{ 0, 0, YYAT_DEFAULT, 310 },
		{ -33, 1, YYAT_DEFAULT, 59 },
		{ 0, 0, YYAT_REDUCE, 169 },
		{ 0, 0, YYAT_REDUCE, 178 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 166;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 118, 24 },
		{ 118, 16 },
		{ 44, 100 },
		{ 118, 18 },
		{ 118, 22 },
		{ 118, 15 },
		{ 118, 19 },
		{ 273, 292 },
		{ 118, 206 },
		{ 118, 99 },
		{ 220, 24 },
		{ 220, 16 },
		{ 239, 104 },
		{ 220, 18 },
		{ 220, 22 },
		{ 220, 15 },
		{ 220, 19 },
		{ 273, 144 },
		{ 155, 233 },
		{ 220, 128 },
		{ 128, 36 },
		{ 128, 34 },
		{ 99, 139 },
		{ 279, 296 },
		{ 279, 108 },
		{ 99, 37 },
		{ 99, 38 },
		{ 128, 217 },
		{ 26, 46 },
		{ 128, -1 },
		{ 220, 272 },
		{ 128, 218 },
		{ 128, 39 },
		{ 128, 40 },
		{ 309, 311 },
		{ 20, 35 },
		{ 239, 284 },
		{ 26, 21 },
		{ 26, 20 },
		{ 153, 67 },
		{ 128, -1 },
		{ 44, 122 },
		{ 20, 41 },
		{ 26, 25 },
		{ 155, 234 },
		{ 203, 264 },
		{ 203, -1 },
		{ 118, 207 },
		{ 44, 118 },
		{ 26, -1 },
		{ 153, -1 },
		{ 299, 308 },
		{ 153, 149 },
		{ 286, 302 },
		{ 26, 23 },
		{ 310, 312 },
		{ 310, 116 },
		{ 310, 119 },
		{ 310, 117 },
		{ 310, 121 },
		{ 310, 107 },
		{ 310, 120 },
		{ 289, 210 },
		{ 289, 304 },
		{ 289, 125 },
		{ 289, 123 },
		{ 208, 266 },
		{ 289, 124 },
		{ 289, 126 },
		{ 208, 18 },
		{ 208, 22 },
		{ 208, 15 },
		{ 208, 19 },
		{ 67, 151 },
		{ 200, 261 },
		{ 200, 114 },
		{ 60, 139 },
		{ 67, -1 },
		{ 67, -1 },
		{ 67, -1 },
		{ 60, 140 },
		{ 60, 39 },
		{ 60, 40 },
		{ 288, 303 },
		{ 288, 102 },
		{ 288, 105 },
		{ 284, 300 },
		{ 284, 103 },
		{ 284, 101 },
		{ 204, 265 },
		{ 204, 110 },
		{ 204, 113 },
		{ 0, 27 },
		{ 0, 26 },
		{ 0, 17 },
		{ 198, 259 },
		{ 198, 109 },
		{ 197, 258 },
		{ 197, 127 },
		{ 195, 256 },
		{ 195, 111 },
		{ 191, -1 },
		{ 191, 252 },
		{ 189, 250 },
		{ 189, 115 },
		{ 188, 249 },
		{ 188, 112 },
		{ 186, -1 },
		{ 186, 248 },
		{ 185, 247 },
		{ 185, 106 },
		{ 141, 224 },
		{ 141, 225 },
		{ 69, 153 },
		{ 69, 68 },
		{ 53, 136 },
		{ 53, 52 },
		{ 47, 129 },
		{ 47, 130 },
		{ 28, 47 },
		{ 28, 48 },
		{ 285, 301 },
		{ 283, 298 },
		{ 282, 297 },
		{ 277, 295 },
		{ 242, 287 },
		{ 229, 276 },
		{ 227, 275 },
		{ 217, 58 },
		{ 213, 270 },
		{ 211, 268 },
		{ 202, 263 },
		{ 201, 262 },
		{ 199, 260 },
		{ 196, 257 },
		{ 194, 255 },
		{ 193, 254 },
		{ 192, 253 },
		{ 190, 251 },
		{ 184, 246 },
		{ 183, 245 },
		{ 170, 244 },
		{ 167, 243 },
		{ 165, 241 },
		{ 164, 240 },
		{ 163, 239 },
		{ 161, 237 },
		{ 151, 57 },
		{ 142, 183 },
		{ 133, 222 },
		{ 132, 221 },
		{ 124, 209 },
		{ 92, 169 },
		{ 91, 168 },
		{ 89, 166 },
		{ 85, 162 },
		{ 83, 160 },
		{ 72, 154 },
		{ 63, 147 },
		{ 62, 143 },
		{ 59, 137 },
		{ 42, 66 },
		{ 41, 64 },
		{ 35, 59 },
		{ 29, 51 },
		{ 25, 45 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 91, 26 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 99 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 109, -1 },
		{ 25, 220 },
		{ 0, -1 },
		{ 100, -1 },
		{ 137, 53 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 145, 217 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 106, -1 },
		{ 136, 69 },
		{ 0, -1 },
		{ -10, 118 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, 220 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 88, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 104, -1 },
		{ 65, -1 },
		{ 0, -1 },
		{ 138, 273 },
		{ 126, 279 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 153 },
		{ 62, 128 },
		{ 0, -1 },
		{ 88, 153 },
		{ 0, -1 },
		{ 0, -1 },
		{ 127, 284 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 126, 284 },
		{ 0, -1 },
		{ 104, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 122, 279 },
		{ 0, -1 },
		{ 109, 203 },
		{ 108, 203 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 142 },
		{ 11, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 106, 289 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, 220 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 118, 279 },
		{ 121, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 217 },
		{ 0, -1 },
		{ 90, 273 },
		{ 100, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 141, -1 },
		{ 0, -1 },
		{ 26, 220 },
		{ 0, -1 },
		{ 14, 208 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 116, 284 },
		{ 0, -1 },
		{ 91, 239 },
		{ 114, 284 },
		{ 113, 284 },
		{ 0, -1 },
		{ 91, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 90, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 109, 186 },
		{ 106, 288 },
		{ 74, 188 },
		{ 77, 284 },
		{ 0, -1 },
		{ 69, 189 },
		{ 66, 198 },
		{ 98, 191 },
		{ 62, 204 },
		{ 96, 195 },
		{ 95, 195 },
		{ 94, 195 },
		{ 58, 200 },
		{ 91, 197 },
		{ 54, 203 },
		{ 57, 204 },
		{ 91, 200 },
		{ 32, 197 },
		{ 88, 203 },
		{ 87, 203 },
		{ 1, 289 },
		{ 50, 195 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, 72 },
		{ 0, -1 },
		{ 0, -1 },
		{ 100, 284 },
		{ 0, -1 },
		{ 99, 284 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 111, 151 },
		{ 0, -1 },
		{ 0, -1 },
		{ 6, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 95, 279 },
		{ 0, -1 },
		{ 94, 279 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -18, 284 },
		{ 0, -1 },
		{ 0, -1 },
		{ 74, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -14, 186 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 92, 279 },
		{ 0, -1 },
		{ -9, 288 },
		{ 0, -1 },
		{ 0, -1 },
		{ 72, 310 },
		{ 92, 284 },
		{ 56, 279 },
		{ 70, 310 },
		{ 2, 310 },
		{ 0, -1 },
		{ 50, 185 },
		{ 18, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 310 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -17, 310 },
		{ 4, 239 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 571 ".\\myparser.y"


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

