/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 1 of your 30 day trial period.
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
* Date: 01/01/18
* Time: 22:52:19
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

void declInsertEntry(Node * var_id) {
	if (var_id->getType() == idt_t) {
		var_id->setEntry(new SymbolEntry(giv.g_type, giv.g_cate, giv.g_dim));
		var_id->getTable()->insert(var_id->getString(), var_id->getEntry());
		giv.g_cate = var_st;
		giv.g_dim = 0;
		return;
	}
	declInsertEntry(var_id->getChild(0));
}

void funcInsertEntry(Node * func_id) {
	func_id->setTable(curr_table->getFather());
	func_id->setEntry(new SymbolEntry(int_d, function_st, &giv.g_param_list));
	func_id->getTable()->insert(func_id->getString(), func_id->getEntry());
}

void funcSetEntry(Node * func_head) {
	Node * func_id = func_head->getChild(0);
	func_id->getTable()->setType(func_id->getString(), giv.g_type);
}

void addParamList() {
	giv.g_param_list.push_back(giv.g_type);
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
	cout << "giv.g_type: " << giv.g_type << endl;
	cout << "giv.g_cate: " << giv.g_cate << endl;
	cout << "giv.g_dim: " << giv.g_dim << endl;
	cout << "entered: " << entered << endl;
	cout << "root table address: " << root_table << endl;
	cout << "curr table address: " << curr_table << endl;
}


#line 107 "myparser.cpp"
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
#line 83 ".\\myparser.y"

	// place any extra initialisation code here

#line 131 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 88 ".\\myparser.y"

	// place any extra cleanup code here

#line 145 "myparser.cpp"
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
#line 123 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); cout << "Grammar Tree:" << endl; (*(YYSTYPE YYFAR*)yyvalptr)->traverse(); cout << endl; outputTables(); cout << endl;
#line 255 "myparser.cpp"
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
#line 127 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(blocks_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 268 "myparser.cpp"
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
#line 128 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 281 "myparser.cpp"
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
#line 132 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 294 "myparser.cpp"
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
#line 133 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 307 "myparser.cpp"
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
#line 139 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "void"); giv.g_type = void_d;
#line 320 "myparser.cpp"
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
#line 140 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "integer"); giv.g_type = int_d;
#line 333 "myparser.cpp"
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
#line 141 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "character"); giv.g_type = char_d;
#line 346 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 147 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 3), yyattribute(2 - 3));
#line 359 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 148 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 2));
#line 372 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 152 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_list_t, yyattribute(1 - 3), yyattribute(3 - 3));
#line 385 "myparser.cpp"
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
#line 153 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 398 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 157 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 411 "myparser.cpp"
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
#line 158 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 424 "myparser.cpp"
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
#line 162 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); declInsertEntry(yyattribute(1 - 1));
#line 437 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 166 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 4)->getCharP(), yyattribute(1 - 4), yyattribute(3 - 4)); giv.g_cate = array_st; ++giv.g_dim;
#line 450 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 167 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 3)->getCharP(), yyattribute(1 - 3)); giv.g_cate = array_st; ++giv.g_dim;
#line 463 "myparser.cpp"
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
#line 168 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 476 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 172 ".\\myparser.y"
giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;
#line 489 "myparser.cpp"
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
#line 173 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 5)->getCharP(), yyattribute(1 - 5), yyattribute(2 - 5));
		funcInsertEntry(yyattribute(1 - 5));
#line 503 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 175 ".\\myparser.y"
giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; entered = true;
#line 516 "myparser.cpp"
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
#line 176 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_head_t, yyattribute(1 - 4)->getCharP(), yyattribute(1 - 4));
		funcInsertEntry(yyattribute(1 - 4));
#line 530 "myparser.cpp"
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
#line 181 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); returnScope();
#line 543 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 556 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(init_val_t, yyattribute(1 - 3), yyattribute(3 - 3));
#line 569 "myparser.cpp"
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
#line 187 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 582 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 191 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_list_t, yyattribute(1 - 3), yyattribute(3 - 3)); addParamList();
#line 595 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 192 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); addParamList();
#line 608 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 621 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(param_t, yyattribute(1 - 1));
#line 634 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 203 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, yyattribute(1 - 3), yyattribute(2 - 3), yyattribute(3 - 3));
		funcSetEntry(yyattribute(2 - 3));
#line 648 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 205 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, new Node(type_t, "integer"), yyattribute(1 - 2), yyattribute(2 - 2)); giv.g_type = int_d; 
		funcSetEntry(yyattribute(1 - 2));
#line 662 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ",", yyattribute(1 - 3), yyattribute(3 - 3));
#line 675 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 688 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 217 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3); (*(YYSTYPE YYFAR*)yyvalptr)->addChild(yyattribute(1 - 3)); (*(YYSTYPE YYFAR*)yyvalptr)->addChild(yyattribute(3 - 3));
#line 701 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 218 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 714 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 222 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 727 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 226 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "? :", yyattribute(1 - 5), yyattribute(2 - 5), yyattribute(3 - 5));
#line 740 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 227 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 753 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 231 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "||", yyattribute(1 - 3), yyattribute(3 - 3));
#line 766 "myparser.cpp"
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
#line 232 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 779 "myparser.cpp"
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
#line 236 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&&", yyattribute(1 - 3), yyattribute(3 - 3));
#line 792 "myparser.cpp"
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
#line 237 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 805 "myparser.cpp"
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
#line 241 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "|", yyattribute(1 - 3), yyattribute(3 - 3));
#line 818 "myparser.cpp"
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
#line 242 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 831 "myparser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 246 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "^", yyattribute(1 - 3), yyattribute(3 - 3));
#line 844 "myparser.cpp"
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
#line 247 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 857 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 251 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&", yyattribute(1 - 3), yyattribute(3 - 3));
#line 870 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 252 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 883 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 256 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "==", yyattribute(1 - 3), yyattribute(3 - 3));
#line 896 "myparser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 257 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "!=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 909 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 258 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 922 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 262 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 935 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 263 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">=", yyattribute(1 - 3), yyattribute(3 - 3));
#line 948 "myparser.cpp"
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
#line 264 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<", yyattribute(1 - 3), yyattribute(3 - 3));
#line 961 "myparser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 265 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">", yyattribute(1 - 3), yyattribute(3 - 3));
#line 974 "myparser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 266 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 987 "myparser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 270 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<<", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1000 "myparser.cpp"
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
#line 271 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">>", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1013 "myparser.cpp"
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
#line 272 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1026 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 276 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1039 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 277 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1052 "myparser.cpp"
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
#line 278 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1065 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 282 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "*", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1078 "myparser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 283 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "/", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1091 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 284 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "%", yyattribute(1 - 3), yyattribute(3 - 3));
#line 1104 "myparser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 285 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1117 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 289 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2); (*(YYSTYPE YYFAR*)yyvalptr)->addChild(yyattribute(2 - 2));
#line 1130 "myparser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 290 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1143 "myparser.cpp"
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
#line 294 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "[ ]", yyattribute(1 - 4), yyattribute(3 - 4));
#line 1156 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 295 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "( )", yyattribute(1 - 4), yyattribute(3 - 4));
#line 1169 "myparser.cpp"
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
#line 296 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "( )", yyattribute(1 - 3));
#line 1182 "myparser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 297 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "++", yyattribute(1 - 2));
#line 1195 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 298 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "--", yyattribute(1 - 2));
#line 1208 "myparser.cpp"
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
#line 299 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1221 "myparser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 303 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1234 "myparser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 304 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1247 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 305 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 1260 "myparser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 309 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "=");
#line 1273 "myparser.cpp"
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
#line 310 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+=");
#line 1286 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 311 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-=");
#line 1299 "myparser.cpp"
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
#line 312 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "*=");
#line 1312 "myparser.cpp"
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
#line 313 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "/=");
#line 1325 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 314 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "%=");
#line 1338 "myparser.cpp"
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
#line 315 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "&=");
#line 1351 "myparser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 316 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "|=");
#line 1364 "myparser.cpp"
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
#line 317 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "^=");
#line 1377 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 318 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "~=");
#line 1390 "myparser.cpp"
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
#line 319 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "<<=");
#line 1403 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 320 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, ">>=");
#line 1416 "myparser.cpp"
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
#line 324 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "+");
#line 1429 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 325 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "-");
#line 1442 "myparser.cpp"
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
#line 326 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "~");
#line 1455 "myparser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 327 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "!");
#line 1468 "myparser.cpp"
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
#line 328 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "++");
#line 1481 "myparser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 329 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, "--");
#line 1494 "myparser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 333 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1507 "myparser.cpp"
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
#line 334 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1520 "myparser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 340 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1533 "myparser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 341 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1546 "myparser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 342 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1559 "myparser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 343 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1572 "myparser.cpp"
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
#line 344 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1585 "myparser.cpp"
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
#line 348 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(return_stmt_t);
#line 1598 "myparser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 349 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(return_stmt_t);
#line 1611 "myparser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 353 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(while_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1624 "myparser.cpp"
			}
		}
		break;
	case 106:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 354 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(dowhile_stmt_t, yyattribute(2 - 6), yyattribute(5 - 6));
#line 1637 "myparser.cpp"
			}
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 355 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(2 - 7), yyattribute(3 - 7), yyattribute(4 - 7), yyattribute(6 - 7));
#line 1650 "myparser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 356 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(2 - 6), yyattribute(3 - 6), yyattribute(5 - 6));
#line 1663 "myparser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 360 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 1676 "myparser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 361 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(empty_stmt_t);
#line 1689 "myparser.cpp"
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
#line 365 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1702 "myparser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 366 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); returnScope();
#line 1715 "myparser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 370 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 1728 "myparser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 371 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1741 "myparser.cpp"
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
#line 375 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 1754 "myparser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 376 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 1767 "myparser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 377 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1780 "myparser.cpp"
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
#line 378 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1793 "myparser.cpp"
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
		{ "CHAR", 259 },
		{ "RETURN", 260 },
		{ "WHILE", 261 },
		{ "DO", 262 },
		{ "FOR", 263 },
		{ "IF", 264 },
		{ "NO_ELSE", 265 },
		{ "ELSE", 266 },
		{ "ADDASSIGN", 267 },
		{ "SUBASSIGN", 268 },
		{ "MULASSIGN", 269 },
		{ "DIVASSIGN", 270 },
		{ "MODASSIGN", 271 },
		{ "ANDASSIGN", 272 },
		{ "ORASSIGN", 273 },
		{ "XORASSIGN", 274 },
		{ "REVASSIGN", 275 },
		{ "LSHIFTASSIGN", 276 },
		{ "RSHIFTASSIGN", 277 },
		{ "OR", 278 },
		{ "AND", 279 },
		{ "EQ", 280 },
		{ "NE", 281 },
		{ "LE", 282 },
		{ "GE", 283 },
		{ "LT", 284 },
		{ "GT", 285 },
		{ "INC", 286 },
		{ "DEC", 287 },
		{ "LSHIFT", 288 },
		{ "RSHIFT", 289 },
		{ "INTVAL", 290 },
		{ "CHARVAL", 291 },
		{ "ID", 292 },
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
		"type: CHAR",
		"decl: type decl_list \';\'",
		"decl: type \';\'",
		"decl_list: decl_list \',\' decl_init",
		"decl_list: decl_init",
		"decl_init: decl_head \'=\' init_val",
		"decl_init: decl_head",
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
		"param: type decl_init",
		"param: type",
		"func: type func_decl_head compound_stmt",
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
		"shift_expr: shift_expr LSHIFT add_sub_expr",
		"shift_expr: shift_expr RSHIFT add_sub_expr",
		"shift_expr: add_sub_expr",
		"add_sub_expr: add_sub_expr \'+\' mul_div_mod_expr",
		"add_sub_expr: add_sub_expr \'-\' mul_div_mod_expr",
		"add_sub_expr: mul_div_mod_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'*\' unary_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'/\' unary_expr",
		"mul_div_mod_expr: mul_div_mod_expr \'%\' unary_expr",
		"mul_div_mod_expr: unary_expr",
		"unary_expr: unary_op unary_expr",
		"unary_expr: postfix_expr",
		"postfix_expr: postfix_expr \'[\' expr \']\'",
		"postfix_expr: postfix_expr \'(\' expr \')\'",
		"postfix_expr: postfix_expr \'(\' \')\'",
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
		"unary_op: \'+\'",
		"unary_op: \'-\'",
		"unary_op: \'~\'",
		"unary_op: \'!\'",
		"unary_op: INC",
		"unary_op: DEC",
		"val: INTVAL",
		"val: CHARVAL",
		"stmt: jmp_stmt",
		"stmt: loop_stmt",
		"stmt: expr_stmt",
		"stmt: compound_stmt",
		"stmt: conditional_stmt",
		"jmp_stmt: RETURN expr \';\'",
		"jmp_stmt: RETURN \';\'",
		"loop_stmt: WHILE \'(\' expr \')\' stmt",
		"loop_stmt: DO stmt WHILE \'(\' expr \')\'",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt expr \')\' stmt",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt \')\' stmt",
		"expr_stmt: expr \';\'",
		"expr_stmt: \';\'",
		"compound_stmt: \'{\' stmt_decl_list \'}\'",
		"compound_stmt: \'{\' \'}\'",
		"conditional_stmt: IF \'(\' expr \')\' stmt ELSE stmt",
		"conditional_stmt: IF \'(\' expr \')\' stmt",
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
		{ 5, 3, 8 },
		{ 5, 2, 9 },
		{ 6, 3, 10 },
		{ 6, 1, 11 },
		{ 7, 3, 12 },
		{ 7, 1, 13 },
		{ 8, 1, 14 },
		{ 9, 4, 15 },
		{ 9, 3, 16 },
		{ 9, 1, 17 },
		{ 11, 0, 18 },
		{ 10, 5, 19 },
		{ 12, 0, 20 },
		{ 10, 4, 21 },
		{ 13, 3, 22 },
		{ 13, 1, 23 },
		{ 14, 3, 24 },
		{ 14, 1, 25 },
		{ 15, 3, 26 },
		{ 15, 1, 27 },
		{ 16, 2, 28 },
		{ 16, 1, 29 },
		{ 17, 3, 30 },
		{ 17, 2, 31 },
		{ 18, 3, 32 },
		{ 18, 1, 33 },
		{ 19, 3, 34 },
		{ 19, 1, 35 },
		{ 20, 1, 36 },
		{ 21, 5, 37 },
		{ 21, 1, 38 },
		{ 22, 3, 39 },
		{ 22, 1, 40 },
		{ 23, 3, 41 },
		{ 23, 1, 42 },
		{ 24, 3, 43 },
		{ 24, 1, 44 },
		{ 25, 3, 45 },
		{ 25, 1, 46 },
		{ 26, 3, 47 },
		{ 26, 1, 48 },
		{ 27, 3, 49 },
		{ 27, 3, 50 },
		{ 27, 1, 51 },
		{ 28, 3, 52 },
		{ 28, 3, 53 },
		{ 28, 3, 54 },
		{ 28, 3, 55 },
		{ 28, 1, 56 },
		{ 29, 3, 57 },
		{ 29, 3, 58 },
		{ 29, 1, 59 },
		{ 30, 3, 60 },
		{ 30, 3, 61 },
		{ 30, 1, 62 },
		{ 31, 3, 63 },
		{ 31, 3, 64 },
		{ 31, 3, 65 },
		{ 31, 1, 66 },
		{ 32, 2, 67 },
		{ 32, 1, 68 },
		{ 33, 4, 69 },
		{ 33, 4, 70 },
		{ 33, 3, 71 },
		{ 33, 2, 72 },
		{ 33, 2, 73 },
		{ 33, 1, 74 },
		{ 34, 1, 75 },
		{ 34, 1, 76 },
		{ 34, 3, 77 },
		{ 35, 1, 78 },
		{ 35, 1, 79 },
		{ 35, 1, 80 },
		{ 35, 1, 81 },
		{ 35, 1, 82 },
		{ 35, 1, 83 },
		{ 35, 1, 84 },
		{ 35, 1, 85 },
		{ 35, 1, 86 },
		{ 35, 1, 87 },
		{ 35, 1, 88 },
		{ 35, 1, 89 },
		{ 36, 1, 90 },
		{ 36, 1, 91 },
		{ 36, 1, 92 },
		{ 36, 1, 93 },
		{ 36, 1, 94 },
		{ 36, 1, 95 },
		{ 37, 1, 96 },
		{ 37, 1, 97 },
		{ 38, 1, 98 },
		{ 38, 1, 99 },
		{ 38, 1, 100 },
		{ 38, 1, 101 },
		{ 38, 1, 102 },
		{ 39, 3, 103 },
		{ 39, 2, 104 },
		{ 40, 5, 105 },
		{ 40, 6, 106 },
		{ 40, 7, 107 },
		{ 40, 6, 108 },
		{ 41, 2, 109 },
		{ 41, 1, 110 },
		{ 42, 3, 111 },
		{ 42, 2, 112 },
		{ 43, 7, 113 },
		{ 43, 5, 114 },
		{ 44, 2, 115 },
		{ 44, 2, 116 },
		{ 44, 1, 117 },
		{ 44, 1, 118 }
	};
	yyreduction = reduction;

	yytokenaction_size = 260;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 192, YYAT_SHIFT, 25 },
		{ 41, YYAT_SHIFT, 86 },
		{ 66, YYAT_SHIFT, 125 },
		{ 63, YYAT_SHIFT, 119 },
		{ 169, YYAT_SHIFT, 180 },
		{ 168, YYAT_SHIFT, 101 },
		{ 81, YYAT_SHIFT, 101 },
		{ 192, YYAT_SHIFT, 26 },
		{ 43, YYAT_SHIFT, 99 },
		{ 19, YYAT_SHIFT, 71 },
		{ 192, YYAT_SHIFT, 27 },
		{ 186, YYAT_SHIFT, 192 },
		{ 192, YYAT_SHIFT, 28 },
		{ 10, YYAT_SHIFT, 1 },
		{ 10, YYAT_SHIFT, 2 },
		{ 10, YYAT_SHIFT, 3 },
		{ 185, YYAT_SHIFT, 191 },
		{ 180, YYAT_ERROR, 0 },
		{ 155, YYAT_SHIFT, 122 },
		{ 185, YYAT_SHIFT, 101 },
		{ 154, YYAT_SHIFT, 122 },
		{ 81, YYAT_SHIFT, 140 },
		{ 64, YYAT_SHIFT, 122 },
		{ 155, YYAT_SHIFT, 123 },
		{ 19, YYAT_SHIFT, 72 },
		{ 154, YYAT_SHIFT, 123 },
		{ 192, YYAT_SHIFT, 29 },
		{ 64, YYAT_SHIFT, 123 },
		{ 155, YYAT_SHIFT, 124 },
		{ 153, YYAT_SHIFT, 108 },
		{ 154, YYAT_SHIFT, 124 },
		{ 153, YYAT_SHIFT, 109 },
		{ 64, YYAT_SHIFT, 124 },
		{ 158, YYAT_SHIFT, 113 },
		{ 158, YYAT_SHIFT, 114 },
		{ 158, YYAT_SHIFT, 115 },
		{ 158, YYAT_SHIFT, 116 },
		{ 157, YYAT_SHIFT, 113 },
		{ 157, YYAT_SHIFT, 114 },
		{ 157, YYAT_SHIFT, 115 },
		{ 157, YYAT_SHIFT, 116 },
		{ 54, YYAT_SHIFT, 113 },
		{ 54, YYAT_SHIFT, 114 },
		{ 54, YYAT_SHIFT, 115 },
		{ 54, YYAT_SHIFT, 116 },
		{ 137, YYAT_SHIFT, 1 },
		{ 137, YYAT_SHIFT, 2 },
		{ 137, YYAT_SHIFT, 3 },
		{ 10, YYAT_SHIFT, 4 },
		{ 76, YYAT_SHIFT, 136 },
		{ 162, YYAT_SHIFT, 106 },
		{ 162, YYAT_SHIFT, 107 },
		{ 76, YYAT_SHIFT, 137 },
		{ 66, YYAT_SHIFT, 126 },
		{ 168, YYAT_SHIFT, 179 },
		{ 152, YYAT_SHIFT, 108 },
		{ 51, YYAT_SHIFT, 108 },
		{ 152, YYAT_SHIFT, 109 },
		{ 51, YYAT_SHIFT, 109 },
		{ 161, YYAT_SHIFT, 106 },
		{ 161, YYAT_SHIFT, 107 },
		{ 160, YYAT_SHIFT, 106 },
		{ 160, YYAT_SHIFT, 107 },
		{ 159, YYAT_SHIFT, 106 },
		{ 159, YYAT_SHIFT, 107 },
		{ 156, YYAT_SHIFT, 111 },
		{ 156, YYAT_SHIFT, 112 },
		{ 53, YYAT_SHIFT, 111 },
		{ 53, YYAT_SHIFT, 112 },
		{ 50, YYAT_SHIFT, 106 },
		{ 50, YYAT_SHIFT, 107 },
		{ 183, YYAT_SHIFT, 189 },
		{ 177, YYAT_SHIFT, 117 },
		{ 175, YYAT_SHIFT, 184 },
		{ 174, YYAT_ERROR, 0 },
		{ 167, YYAT_SHIFT, 178 },
		{ 151, YYAT_SHIFT, 103 },
		{ 150, YYAT_SHIFT, 105 },
		{ 149, YYAT_SHIFT, 110 },
		{ 147, YYAT_SHIFT, 104 },
		{ 146, YYAT_SHIFT, 177 },
		{ 180, YYAT_SHIFT, 131 },
		{ 144, YYAT_SHIFT, 176 },
		{ 143, YYAT_SHIFT, 29 },
		{ 142, YYAT_SHIFT, 174 },
		{ 169, YYAT_SHIFT, 181 },
		{ 141, YYAT_SHIFT, 173 },
		{ 135, YYAT_SHIFT, 171 },
		{ 125, YYAT_SHIFT, 166 },
		{ 83, YYAT_SHIFT, 142 },
		{ 79, YYAT_SHIFT, 139 },
		{ 77, YYAT_SHIFT, 129 },
		{ 74, YYAT_SHIFT, 134 },
		{ 192, YYAT_SHIFT, 31 },
		{ 71, YYAT_SHIFT, 129 },
		{ 69, YYAT_SHIFT, 15 },
		{ 52, YYAT_SHIFT, 110 },
		{ 49, YYAT_SHIFT, 105 },
		{ 48, YYAT_SHIFT, 104 },
		{ 47, YYAT_SHIFT, 103 },
		{ 45, YYAT_SHIFT, 102 },
		{ 36, YYAT_SHIFT, 85 },
		{ 35, YYAT_SHIFT, 84 },
		{ 33, YYAT_SHIFT, 82 },
		{ 32, YYAT_SHIFT, 80 },
		{ 24, YYAT_SHIFT, 78 },
		{ 21, YYAT_SHIFT, 74 },
		{ 20, YYAT_SHIFT, 73 },
		{ 17, YYAT_SHIFT, 13 },
		{ 16, YYAT_SHIFT, 12 },
		{ 13, YYAT_SHIFT, 30 },
		{ 12, YYAT_REDUCE, 21 },
		{ 11, YYAT_ACCEPT, 0 },
		{ 9, YYAT_SHIFT, 16 },
		{ 4, YYAT_SHIFT, 12 },
		{ 0, YYAT_SHIFT, 4 },
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
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 63, YYAT_SHIFT, 1 },
		{ 63, YYAT_SHIFT, 2 },
		{ 63, YYAT_SHIFT, 3 },
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
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 41, YYAT_SHIFT, 87 },
		{ 41, YYAT_SHIFT, 88 },
		{ 41, YYAT_SHIFT, 89 },
		{ 41, YYAT_SHIFT, 90 },
		{ 41, YYAT_SHIFT, 91 },
		{ 41, YYAT_SHIFT, 92 },
		{ 41, YYAT_SHIFT, 93 },
		{ 41, YYAT_SHIFT, 94 },
		{ 41, YYAT_SHIFT, 95 },
		{ 41, YYAT_SHIFT, 96 },
		{ 41, YYAT_SHIFT, 97 },
		{ 180, YYAT_ERROR, 0 },
		{ 180, YYAT_ERROR, 0 },
		{ 180, YYAT_ERROR, 0 },
		{ 180, YYAT_ERROR, 0 },
		{ 180, YYAT_ERROR, 0 },
		{ 43, YYAT_SHIFT, 100 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 192, YYAT_SHIFT, 32 },
		{ 192, YYAT_SHIFT, 33 },
		{ 192, YYAT_SHIFT, 34 },
		{ 192, YYAT_SHIFT, 35 },
		{ 192, YYAT_SHIFT, 36 },
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
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 66, YYAT_SHIFT, 127 },
		{ 66, YYAT_SHIFT, 128 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 192, YYAT_SHIFT, 37 },
		{ 192, YYAT_SHIFT, 38 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 192, YYAT_SHIFT, 39 },
		{ 192, YYAT_SHIFT, 40 },
		{ 192, YYAT_SHIFT, 41 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -177, 1, YYAT_DEFAULT, 137 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 74, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 17 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -179, 1, YYAT_DEFAULT, 69 },
		{ -244, 1, YYAT_REDUCE, 1 },
		{ 112, 1, YYAT_ERROR, 0 },
		{ 70, 1, YYAT_REDUCE, 19 },
		{ -15, 1, YYAT_DEFAULT, 63 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 69, 1, YYAT_REDUCE, 18 },
		{ -15, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ -35, 1, YYAT_ERROR, 0 },
		{ 46, 1, YYAT_REDUCE, 14 },
		{ 15, 1, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 137 },
		{ 64, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 111 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 45, 1, YYAT_DEFAULT, 174 },
		{ 63, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 192 },
		{ 62, 1, YYAT_ERROR, 0 },
		{ 61, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 95 },
		{ 0, 0, YYAT_REDUCE, 96 },
		{ 0, 0, YYAT_REDUCE, 97 },
		{ 0, 0, YYAT_REDUCE, 98 },
		{ -60, 1, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ -55, 1, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 41, 1, YYAT_DEFAULT, 81 },
		{ 0, 0, YYAT_REDUCE, 102 },
		{ 5, 1, YYAT_REDUCE, 45 },
		{ -181, 1, YYAT_REDUCE, 41 },
		{ -27, 1, YYAT_REDUCE, 43 },
		{ -219, 1, YYAT_REDUCE, 57 },
		{ 13, 1, YYAT_REDUCE, 60 },
		{ 58, 1, YYAT_REDUCE, 47 },
		{ -213, 1, YYAT_REDUCE, 49 },
		{ -241, 1, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 0, 0, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ -122, 1, YYAT_DEFAULT, 192 },
		{ -15, 1, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -38, 1, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ 36, 1, YYAT_DEFAULT, 71 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ -198, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_DEFAULT, 180 },
		{ -1, 1, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 8, 1, YYAT_ERROR, 0 },
		{ -201, 1, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 49, 1, YYAT_DEFAULT, 185 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 143 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 112 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 0, 0, YYAT_DEFAULT, 177 },
		{ 47, 1, YYAT_DEFAULT, 175 },
		{ 0, 0, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_DEFAULT, 180 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -6, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ 45, 1, YYAT_DEFAULT, 185 },
		{ 44, 1, YYAT_ERROR, 0 },
		{ 24, 1, YYAT_DEFAULT, 174 },
		{ 41, 1, YYAT_DEFAULT, 185 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 22, 1, YYAT_ERROR, 0 },
		{ -200, 1, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 40, 1, YYAT_REDUCE, 46 },
		{ -47, 1, YYAT_REDUCE, 42 },
		{ -18, 1, YYAT_REDUCE, 44 },
		{ 12, 1, YYAT_REDUCE, 58 },
		{ -14, 1, YYAT_REDUCE, 59 },
		{ -17, 1, YYAT_REDUCE, 61 },
		{ -19, 1, YYAT_REDUCE, 62 },
		{ -215, 1, YYAT_REDUCE, 48 },
		{ -245, 1, YYAT_REDUCE, 50 },
		{ -249, 1, YYAT_REDUCE, 51 },
		{ -225, 1, YYAT_REDUCE, 53 },
		{ -227, 1, YYAT_REDUCE, 54 },
		{ -229, 1, YYAT_REDUCE, 55 },
		{ -238, 1, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 34, 1, YYAT_DEFAULT, 185 },
		{ -39, 1, YYAT_ERROR, 0 },
		{ -40, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_DEFAULT, 192 },
		{ -49, 1, YYAT_DEFAULT, 180 },
		{ 32, 1, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_DEFAULT, 192 },
		{ -220, 1, YYAT_DEFAULT, 174 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ -42, 1, YYAT_DEFAULT, 192 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 30, 1, YYAT_DEFAULT, 185 },
		{ 0, 0, YYAT_DEFAULT, 192 },
		{ -25, 1, YYAT_ERROR, 0 },
		{ -255, 1, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ 0, 0, YYAT_DEFAULT, 192 },
		{ -33, 1, YYAT_DEFAULT, 17 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ 0, 0, YYAT_REDUCE, 114 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 104;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 13, 68 },
		{ 63, 69 },
		{ 63, 121 },
		{ 180, 188 },
		{ 143, 45 },
		{ 137, 77 },
		{ 177, -1 },
		{ 177, -1 },
		{ 177, 187 },
		{ 180, 132 },
		{ 180, 67 },
		{ 180, 42 },
		{ 180, 43 },
		{ 180, 48 },
		{ 10, 22 },
		{ 10, 9 },
		{ 10, 7 },
		{ 137, 172 },
		{ 124, 165 },
		{ 124, 66 },
		{ 124, 65 },
		{ 10, 5 },
		{ 124, 56 },
		{ 124, 55 },
		{ 101, -1 },
		{ 175, 185 },
		{ 175, 44 },
		{ 143, 175 },
		{ 10, 6 },
		{ 191, 193 },
		{ 101, 148 },
		{ 131, 170 },
		{ 131, 169 },
		{ 13, 62 },
		{ 184, 190 },
		{ 63, 120 },
		{ 116, 162 },
		{ 116, 51 },
		{ 116, 64 },
		{ 13, 63 },
		{ 192, 194 },
		{ 192, 57 },
		{ 192, 58 },
		{ 192, 61 },
		{ 192, 46 },
		{ 192, 59 },
		{ 77, 138 },
		{ 77, 20 },
		{ 77, 21 },
		{ 0, 11 },
		{ 0, 10 },
		{ 0, 8 },
		{ 112, 158 },
		{ 112, 50 },
		{ 110, 156 },
		{ 110, 54 },
		{ 109, 155 },
		{ 109, 60 },
		{ 107, -1 },
		{ 107, 153 },
		{ 105, 151 },
		{ 105, 52 },
		{ 104, 150 },
		{ 104, 47 },
		{ 103, 149 },
		{ 103, 53 },
		{ 100, 147 },
		{ 100, 49 },
		{ 74, 135 },
		{ 74, 42 },
		{ 69, 19 },
		{ 69, 18 },
		{ 23, 76 },
		{ 23, 75 },
		{ 12, 23 },
		{ 12, 24 },
		{ 176, 186 },
		{ 174, 183 },
		{ 173, 182 },
		{ 126, 168 },
		{ 125, 167 },
		{ 123, 164 },
		{ 122, 163 },
		{ 115, 161 },
		{ 114, 160 },
		{ 113, 159 },
		{ 111, 157 },
		{ 108, 154 },
		{ 106, 152 },
		{ 99, 146 },
		{ 98, 145 },
		{ 85, 144 },
		{ 84, 143 },
		{ 82, 141 },
		{ 73, 133 },
		{ 71, 130 },
		{ 56, 118 },
		{ 41, 98 },
		{ 34, 83 },
		{ 32, 81 },
		{ 26, 79 },
		{ 17, 70 },
		{ 9, 17 },
		{ 5, 14 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 48, 10 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 92, 69 },
		{ 11, -1 },
		{ 0, -1 },
		{ 63, -1 },
		{ -5, 63 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 59, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 137 },
		{ 0, -1 },
		{ 0, -1 },
		{ 82, 175 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 81, 175 },
		{ 0, -1 },
		{ 60, 192 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, -1 },
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
		{ 64, 124 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -3, 192 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 64, 77 },
		{ 0, -1 },
		{ 88, 77 },
		{ 0, -1 },
		{ 81, 180 },
		{ 48, 177 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, 175 },
		{ 0, -1 },
		{ 51, 143 },
		{ 73, 175 },
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
		{ 71, 101 },
		{ 68, 177 },
		{ 43, 104 },
		{ 11, 180 },
		{ 0, -1 },
		{ 38, 110 },
		{ 38, 105 },
		{ 35, 103 },
		{ 58, 107 },
		{ 29, 116 },
		{ 56, 109 },
		{ 25, 124 },
		{ 27, 112 },
		{ 58, 112 },
		{ 24, 116 },
		{ 56, 116 },
		{ 55, 116 },
		{ 54, 116 },
		{ 7, 109 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 124 },
		{ 49, 124 },
		{ -14, -1 },
		{ 62, 175 },
		{ 61, 175 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 18, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 1, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -14, 175 },
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
		{ 40, 192 },
		{ 59, 175 },
		{ 7, 101 },
		{ 38, 192 },
		{ -13, 101 },
		{ 0, -1 },
		{ 0, -1 },
		{ -10, 100 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, 192 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -9, 192 },
		{ 2, 143 },
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
#line 381 ".\\myparser.y"


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

