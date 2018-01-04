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
* Date: 01/04/18
* Time: 19:42:15
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
	entered = false;
	tables.insert({curr_table, table_count++});
	curr_table = curr_table->getFather();
}

void declInsertEntry(Node * var_id, NodeValType val_type) {
	if (var_id->type == idt_t) {
		var_id->entry = new SymbolEntry(val_type, var_st);
		var_id->table->insert(string(var_id->data.string_v), var_id->entry);
		var_id->index = var_count++;
		var_id->val_type = val_type;
		return;
	}
	for (unsigned int i = 0; i < var_id->children.size(); ++i) {
		declInsertEntry(var_id->children[i], val_type);
	}
}

// void funcInsertEntry() {
// 	curr_table->insert("main", new SymbolEntry(int_vt, function_st));
// }

void outputTables() {
	for (auto it: tables) {
		it.first->output(it.second);
	}
}

void debug() {
	cout << "Debug Info:" << endl;
	cout << "entered: " << entered << endl;
	cout << "root table address: " << root_table << endl;
	cout << "curr table address: " << curr_table << endl;
}


#line 88 "myparser.cpp"
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
#line 64 ".\\myparser.y"

	// place any extra initialisation code here

#line 112 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 69 ".\\myparser.y"

	// place any extra cleanup code here

#line 126 "myparser.cpp"
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
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 104 ".\\myparser.y"
root_node = new Node(program_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 236 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 105 ".\\myparser.y"
root_node = new Node(program_t, yyattribute(1 - 1));
#line 249 "myparser.cpp"
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
#line 111 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "integer");
#line 262 "myparser.cpp"
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
#line 112 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "character");
#line 275 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 118 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 288 "myparser.cpp"
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
#line 119 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 301 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 123 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 3), yyattribute(2 - 3)); declInsertEntry(yyattribute(2 - 3), vt_converter[string(yyattribute(1 - 3)->data.string_v)]);
#line 314 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 124 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 2));
#line 327 "myparser.cpp"
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
#line 128 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(idt_list_t, yyattribute(1 - 3), yyattribute(3 - 3));
#line 340 "myparser.cpp"
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
#line 129 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 353 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 135 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, new Node(type_t, "integer"), yyattribute(5 - 5));
#line 366 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 136 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, new Node(type_t, "integer"), yyattribute(4 - 4));
#line 379 "myparser.cpp"
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
#line 142 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 3); (*(YYSTYPE YYFAR*)yyvalptr)->children.push_back(yyattribute(3 - 3));
#line 392 "myparser.cpp"
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
#line 143 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 405 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 147 ".\\myparser.y"
yyattribute(1 - 3)->val_type = yyattribute(1 - 3)->symbolCheck(string(yyattribute(1 - 3)->data.string_v))->val_type; (*(YYSTYPE YYFAR*)yyvalptr) = new Node(assign_expr_t, yyattribute(2 - 3)->data.op_v, yyattribute(1 - 3), yyattribute(3 - 3));
#line 418 "myparser.cpp"
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
#line 148 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 431 "myparser.cpp"
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
#line 152 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 444 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 156 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(ternary_expr_t, ternary_d, yyattribute(1 - 5), yyattribute(2 - 5), yyattribute(3 - 5));
#line 457 "myparser.cpp"
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
#line 157 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 470 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 161 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(logical_expr_t, or_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 483 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 496 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 166 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(logical_expr_t, and_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 509 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 167 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 522 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 171 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_or_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 535 "myparser.cpp"
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
#line 172 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 548 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 176 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_xor_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 561 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 177 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 574 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 181 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_and_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 587 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 182 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 600 "myparser.cpp"
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
#line 186 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, eq_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 613 "myparser.cpp"
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
#line 187 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, ne_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 626 "myparser.cpp"
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
#line 188 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 639 "myparser.cpp"
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
#line 192 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, le_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 652 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 193 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, ge_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 665 "myparser.cpp"
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
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, lt_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 678 "myparser.cpp"
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
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, gt_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 691 "myparser.cpp"
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
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 704 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 200 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, lshift_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 717 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 201 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, rshift_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 730 "myparser.cpp"
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
#line 202 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 743 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 206 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, add_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 756 "myparser.cpp"
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
#line 207 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, sub_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 769 "myparser.cpp"
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
#line 208 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 782 "myparser.cpp"
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
#line 212 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, mul_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 795 "myparser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 213 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, div_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 808 "myparser.cpp"
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
#line 214 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, mod_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 821 "myparser.cpp"
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
#line 215 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 834 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 219 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(unary_expr_t, yyattribute(1 - 2)->data.op_v, yyattribute(2 - 2));
#line 847 "myparser.cpp"
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
#line 220 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 860 "myparser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 224 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(post_expr_t, post_inc_d, yyattribute(1 - 2));
#line 873 "myparser.cpp"
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
#line 225 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(post_expr_t, post_dec_d, yyattribute(1 - 2));
#line 886 "myparser.cpp"
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
#line 226 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 899 "myparser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 230 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); (*(YYSTYPE YYFAR*)yyvalptr)->val_type = (*(YYSTYPE YYFAR*)yyvalptr)->symbolCheck(string((*(YYSTYPE YYFAR*)yyvalptr)->data.string_v))->val_type;
#line 912 "myparser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 231 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 925 "myparser.cpp"
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
#line 232 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 938 "myparser.cpp"
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
#line 236 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, assign_d);
#line 951 "myparser.cpp"
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
#line 237 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, addassign_d);
#line 964 "myparser.cpp"
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
#line 238 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, subassign_d);
#line 977 "myparser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 239 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, mulassign_d);
#line 990 "myparser.cpp"
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
#line 240 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, divassign_d);
#line 1003 "myparser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 241 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, modassign_d);
#line 1016 "myparser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 242 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, andassign_d);
#line 1029 "myparser.cpp"
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
#line 243 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, orassign_d);
#line 1042 "myparser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 244 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, xorassign_d);
#line 1055 "myparser.cpp"
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
#line 245 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, revassign_d);
#line 1068 "myparser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 246 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, lshiftassign_d);
#line 1081 "myparser.cpp"
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
#line 247 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, rshiftassign_d);
#line 1094 "myparser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 251 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pos_d);
#line 1107 "myparser.cpp"
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
#line 252 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, neg_d);
#line 1120 "myparser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 253 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, rev_d);
#line 1133 "myparser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 254 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, not_d);
#line 1146 "myparser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 255 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pre_inc_d);
#line 1159 "myparser.cpp"
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
#line 256 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pre_dec_d);
#line 1172 "myparser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 260 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1185 "myparser.cpp"
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
#line 261 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1198 "myparser.cpp"
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
#line 267 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1211 "myparser.cpp"
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
#line 268 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1224 "myparser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 269 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1237 "myparser.cpp"
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
#line 270 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1250 "myparser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 274 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(while_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1263 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 275 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(3 - 7), yyattribute(4 - 7), yyattribute(7 - 7), yyattribute(5 - 7));
#line 1276 "myparser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 276 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(3 - 6), yyattribute(4 - 6), yyattribute(6 - 6));
#line 1289 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 280 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 1302 "myparser.cpp"
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
#line 281 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(empty_stmt_t);
#line 1315 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 285 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 4), yyattribute(3 - 4)); returnScope();
#line 1328 "myparser.cpp"
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
#line 286 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1341 "myparser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 287 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1354 "myparser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 288 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); returnScope();
#line 1367 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 292 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_else_stmt_t, yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 1380 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 293 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1393 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 297 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 1406 "myparser.cpp"
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
#line 298 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1419 "myparser.cpp"
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
		{ "\'^\'", 94 },
		{ "\'{\'", 123 },
		{ "\'|\'", 124 },
		{ "\'}\'", 125 },
		{ "\'~\'", 126 },
		{ "error", 256 },
		{ "INT", 257 },
		{ "CHAR", 258 },
		{ "WHILE", 259 },
		{ "FOR", 260 },
		{ "IF", 261 },
		{ "NO_ELSE", 262 },
		{ "ELSE", 263 },
		{ "MAIN", 264 },
		{ "ADDASSIGN", 265 },
		{ "SUBASSIGN", 266 },
		{ "MULASSIGN", 267 },
		{ "DIVASSIGN", 268 },
		{ "MODASSIGN", 269 },
		{ "ANDASSIGN", 270 },
		{ "ORASSIGN", 271 },
		{ "XORASSIGN", 272 },
		{ "REVASSIGN", 273 },
		{ "LSHIFTASSIGN", 274 },
		{ "RSHIFTASSIGN", 275 },
		{ "OR", 276 },
		{ "AND", 277 },
		{ "EQ", 278 },
		{ "NE", 279 },
		{ "LE", 280 },
		{ "GE", 281 },
		{ "LT", 282 },
		{ "GT", 283 },
		{ "INC", 284 },
		{ "DEC", 285 },
		{ "LSHIFT", 286 },
		{ "RSHIFT", 287 },
		{ "INTVAL", 288 },
		{ "CHARVAL", 289 },
		{ "ID", 290 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: decl_list func",
		"program: func",
		"type: INT",
		"type: CHAR",
		"decl_list: decl_list decl",
		"decl_list: decl",
		"decl: type id_list \';\'",
		"decl: type \';\'",
		"id_list: id_list \',\' ID",
		"id_list: ID",
		"func: INT MAIN \'(\' \')\' compound_stmt",
		"func: MAIN \'(\' \')\' compound_stmt",
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
		"stmt: loop_stmt",
		"stmt: expr_stmt",
		"stmt: compound_stmt",
		"stmt: conditional_stmt",
		"loop_stmt: WHILE \'(\' expr \')\' stmt",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt expr \')\' stmt",
		"loop_stmt: FOR \'(\' expr_stmt expr_stmt \')\' stmt",
		"expr_stmt: expr \';\'",
		"expr_stmt: \';\'",
		"compound_stmt: \'{\' decl_list stmt_list \'}\'",
		"compound_stmt: \'{\' decl_list \'}\'",
		"compound_stmt: \'{\' stmt_list \'}\'",
		"compound_stmt: \'{\' \'}\'",
		"conditional_stmt: IF \'(\' expr \')\' stmt ELSE stmt",
		"conditional_stmt: IF \'(\' expr \')\' stmt",
		"stmt_list: stmt_list stmt",
		"stmt_list: stmt"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 2, 0 },
		{ 1, 1, 1 },
		{ 2, 1, 2 },
		{ 2, 1, 3 },
		{ 3, 2, 4 },
		{ 3, 1, 5 },
		{ 4, 3, 6 },
		{ 4, 2, 7 },
		{ 5, 3, 8 },
		{ 5, 1, 9 },
		{ 6, 5, 10 },
		{ 6, 4, 11 },
		{ 7, 3, 12 },
		{ 7, 1, 13 },
		{ 8, 3, 14 },
		{ 8, 1, 15 },
		{ 9, 1, 16 },
		{ 10, 5, 17 },
		{ 10, 1, 18 },
		{ 11, 3, 19 },
		{ 11, 1, 20 },
		{ 12, 3, 21 },
		{ 12, 1, 22 },
		{ 13, 3, 23 },
		{ 13, 1, 24 },
		{ 14, 3, 25 },
		{ 14, 1, 26 },
		{ 15, 3, 27 },
		{ 15, 1, 28 },
		{ 16, 3, 29 },
		{ 16, 3, 30 },
		{ 16, 1, 31 },
		{ 17, 3, 32 },
		{ 17, 3, 33 },
		{ 17, 3, 34 },
		{ 17, 3, 35 },
		{ 17, 1, 36 },
		{ 18, 3, 37 },
		{ 18, 3, 38 },
		{ 18, 1, 39 },
		{ 19, 3, 40 },
		{ 19, 3, 41 },
		{ 19, 1, 42 },
		{ 20, 3, 43 },
		{ 20, 3, 44 },
		{ 20, 3, 45 },
		{ 20, 1, 46 },
		{ 21, 2, 47 },
		{ 21, 1, 48 },
		{ 22, 2, 49 },
		{ 22, 2, 50 },
		{ 22, 1, 51 },
		{ 23, 1, 52 },
		{ 23, 1, 53 },
		{ 23, 3, 54 },
		{ 24, 1, 55 },
		{ 24, 1, 56 },
		{ 24, 1, 57 },
		{ 24, 1, 58 },
		{ 24, 1, 59 },
		{ 24, 1, 60 },
		{ 24, 1, 61 },
		{ 24, 1, 62 },
		{ 24, 1, 63 },
		{ 24, 1, 64 },
		{ 24, 1, 65 },
		{ 24, 1, 66 },
		{ 25, 1, 67 },
		{ 25, 1, 68 },
		{ 25, 1, 69 },
		{ 25, 1, 70 },
		{ 25, 1, 71 },
		{ 25, 1, 72 },
		{ 26, 1, 73 },
		{ 26, 1, 74 },
		{ 27, 1, 75 },
		{ 27, 1, 76 },
		{ 27, 1, 77 },
		{ 27, 1, 78 },
		{ 28, 5, 79 },
		{ 28, 7, 80 },
		{ 28, 6, 81 },
		{ 29, 2, 82 },
		{ 29, 1, 83 },
		{ 30, 4, 84 },
		{ 30, 3, 85 },
		{ 30, 3, 86 },
		{ 30, 2, 87 },
		{ 31, 7, 88 },
		{ 31, 5, 89 },
		{ 32, 2, 90 },
		{ 32, 1, 91 }
	};
	yyreduction = reduction;

	yytokenaction_size = 258;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 150, YYAT_SHIFT, 25 },
		{ 40, YYAT_SHIFT, 71 },
		{ 142, YYAT_ERROR, 0 },
		{ 8, YYAT_SHIFT, 13 },
		{ 43, YYAT_SHIFT, 86 },
		{ 41, YYAT_SHIFT, 84 },
		{ 45, YYAT_SHIFT, 88 },
		{ 150, YYAT_SHIFT, 26 },
		{ 15, YYAT_SHIFT, 18 },
		{ 125, YYAT_SHIFT, 96 },
		{ 150, YYAT_SHIFT, 27 },
		{ 146, YYAT_SHIFT, 150 },
		{ 150, YYAT_SHIFT, 28 },
		{ 145, YYAT_SHIFT, 149 },
		{ 125, YYAT_SHIFT, 97 },
		{ 124, YYAT_SHIFT, 96 },
		{ 145, YYAT_SHIFT, 88 },
		{ 56, YYAT_SHIFT, 96 },
		{ 140, YYAT_SHIFT, 144 },
		{ 125, YYAT_SHIFT, 98 },
		{ 124, YYAT_SHIFT, 97 },
		{ 45, YYAT_SHIFT, 89 },
		{ 56, YYAT_SHIFT, 97 },
		{ 15, YYAT_SHIFT, 19 },
		{ 138, YYAT_SHIFT, 101 },
		{ 124, YYAT_SHIFT, 98 },
		{ 150, YYAT_SHIFT, 29 },
		{ 56, YYAT_SHIFT, 98 },
		{ 7, YYAT_SHIFT, 1 },
		{ 7, YYAT_SHIFT, 2 },
		{ 131, YYAT_SHIFT, 104 },
		{ 131, YYAT_SHIFT, 105 },
		{ 131, YYAT_SHIFT, 106 },
		{ 131, YYAT_SHIFT, 107 },
		{ 137, YYAT_SHIFT, 108 },
		{ 7, YYAT_SHIFT, 3 },
		{ 130, YYAT_SHIFT, 104 },
		{ 130, YYAT_SHIFT, 105 },
		{ 130, YYAT_SHIFT, 106 },
		{ 130, YYAT_SHIFT, 107 },
		{ 62, YYAT_SHIFT, 104 },
		{ 62, YYAT_SHIFT, 105 },
		{ 62, YYAT_SHIFT, 106 },
		{ 62, YYAT_SHIFT, 107 },
		{ 123, YYAT_SHIFT, 94 },
		{ 122, YYAT_SHIFT, 94 },
		{ 123, YYAT_SHIFT, 95 },
		{ 122, YYAT_SHIFT, 95 },
		{ 54, YYAT_SHIFT, 94 },
		{ 136, YYAT_SHIFT, 110 },
		{ 54, YYAT_SHIFT, 95 },
		{ 135, YYAT_SHIFT, 90 },
		{ 135, YYAT_SHIFT, 91 },
		{ 134, YYAT_SHIFT, 90 },
		{ 134, YYAT_SHIFT, 91 },
		{ 133, YYAT_SHIFT, 90 },
		{ 133, YYAT_SHIFT, 91 },
		{ 132, YYAT_SHIFT, 90 },
		{ 132, YYAT_SHIFT, 91 },
		{ 129, YYAT_SHIFT, 102 },
		{ 129, YYAT_SHIFT, 103 },
		{ 61, YYAT_SHIFT, 102 },
		{ 61, YYAT_SHIFT, 103 },
		{ 59, YYAT_SHIFT, 99 },
		{ 59, YYAT_SHIFT, 100 },
		{ 120, YYAT_SHIFT, 109 },
		{ 142, YYAT_ERROR, 0 },
		{ 49, YYAT_SHIFT, 90 },
		{ 49, YYAT_SHIFT, 91 },
		{ 119, YYAT_SHIFT, 142 },
		{ 116, YYAT_SHIFT, 141 },
		{ 115, YYAT_SHIFT, 29 },
		{ 114, YYAT_SHIFT, 139 },
		{ 88, YYAT_SHIFT, 40 },
		{ 85, YYAT_SHIFT, 118 },
		{ 67, YYAT_SHIFT, 113 },
		{ 66, YYAT_SHIFT, 111 },
		{ 65, YYAT_SHIFT, 110 },
		{ 64, YYAT_SHIFT, 109 },
		{ 63, YYAT_SHIFT, 108 },
		{ 60, YYAT_SHIFT, 101 },
		{ 35, YYAT_SHIFT, 70 },
		{ 34, YYAT_SHIFT, 69 },
		{ 33, YYAT_SHIFT, 68 },
		{ 21, YYAT_SHIFT, 30 },
		{ 20, YYAT_SHIFT, 21 },
		{ 18, YYAT_SHIFT, 23 },
		{ 16, YYAT_SHIFT, 20 },
		{ 10, YYAT_SHIFT, 17 },
		{ 9, YYAT_SHIFT, 16 },
		{ 6, YYAT_ACCEPT, 0 },
		{ 3, YYAT_SHIFT, 10 },
		{ 1, YYAT_SHIFT, 9 },
		{ 150, YYAT_SHIFT, 31 },
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
		{ 41, YYAT_SHIFT, 32 },
		{ 41, YYAT_SHIFT, 2 },
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
		{ 142, YYAT_ERROR, 0 },
		{ 142, YYAT_ERROR, 0 },
		{ 142, YYAT_ERROR, 0 },
		{ 40, YYAT_SHIFT, 72 },
		{ 40, YYAT_SHIFT, 73 },
		{ 40, YYAT_SHIFT, 74 },
		{ 40, YYAT_SHIFT, 75 },
		{ 40, YYAT_SHIFT, 76 },
		{ 40, YYAT_SHIFT, 77 },
		{ 40, YYAT_SHIFT, 78 },
		{ 40, YYAT_SHIFT, 79 },
		{ 40, YYAT_SHIFT, 80 },
		{ 40, YYAT_SHIFT, 81 },
		{ 40, YYAT_SHIFT, 82 },
		{ -1, YYAT_ERROR, 0 },
		{ 43, YYAT_SHIFT, 87 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 150, YYAT_SHIFT, 33 },
		{ 150, YYAT_SHIFT, 34 },
		{ 150, YYAT_SHIFT, 35 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 142, YYAT_SHIFT, 92 },
		{ 8, YYAT_SHIFT, 14 },
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
		{ 150, YYAT_SHIFT, 36 },
		{ 150, YYAT_SHIFT, 37 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 150, YYAT_SHIFT, 38 },
		{ 150, YYAT_SHIFT, 39 },
		{ 150, YYAT_SHIFT, 40 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 7 },
		{ -172, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 51, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 90, 1, YYAT_ERROR, 0 },
		{ -229, 1, YYAT_ERROR, 0 },
		{ -56, 1, YYAT_ERROR, 0 },
		{ 49, 1, YYAT_ERROR, 0 },
		{ 47, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -36, 1, YYAT_ERROR, 0 },
		{ 46, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 20 },
		{ -204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ -41, 1, YYAT_DEFAULT, 41 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_DEFAULT, 88 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ 42, 1, YYAT_ERROR, 0 },
		{ 41, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -60, 1, YYAT_REDUCE, 53 },
		{ -120, 1, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -59, 1, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ -219, 1, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 5, 1, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ -20, 1, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -221, 1, YYAT_REDUCE, 49 },
		{ 42, 1, YYAT_REDUCE, 27 },
		{ -217, 1, YYAT_REDUCE, 29 },
		{ -240, 1, YYAT_REDUCE, 32 },
		{ -45, 1, YYAT_REDUCE, 23 },
		{ -199, 1, YYAT_REDUCE, 21 },
		{ -17, 1, YYAT_REDUCE, 25 },
		{ -49, 1, YYAT_DEFAULT, 150 },
		{ 34, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 88 },
		{ 0, 0, YYAT_DEFAULT, 115 },
		{ 0, 0, YYAT_DEFAULT, 88 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_DEFAULT, 88 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ -51, 1, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -217, 1, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 31, 1, YYAT_DEFAULT, 145 },
		{ 12, 1, YYAT_DEFAULT, 88 },
		{ 29, 1, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 11, 1, YYAT_ERROR, 0 },
		{ -212, 1, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 2, 1, YYAT_REDUCE, 38 },
		{ 1, 1, YYAT_REDUCE, 39 },
		{ -22, 1, YYAT_REDUCE, 41 },
		{ -28, 1, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ -219, 1, YYAT_REDUCE, 28 },
		{ -244, 1, YYAT_REDUCE, 30 },
		{ -250, 1, YYAT_REDUCE, 31 },
		{ -229, 1, YYAT_REDUCE, 33 },
		{ -231, 1, YYAT_REDUCE, 34 },
		{ -233, 1, YYAT_REDUCE, 35 },
		{ -235, 1, YYAT_REDUCE, 36 },
		{ -45, 1, YYAT_REDUCE, 24 },
		{ -90, 1, YYAT_REDUCE, 22 },
		{ -14, 1, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ -23, 1, YYAT_DEFAULT, 88 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ -57, 1, YYAT_DEFAULT, 150 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ -252, 1, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 150 },
		{ -33, 1, YYAT_DEFAULT, 20 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 89 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 105;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 150, 45 },
		{ 150, 46 },
		{ 150, 47 },
		{ 150, 42 },
		{ 150, 43 },
		{ 150, 64 },
		{ 150, 63 },
		{ 150, 65 },
		{ 150, 60 },
		{ 150, 61 },
		{ 150, 62 },
		{ 150, 49 },
		{ 150, 54 },
		{ 150, 56 },
		{ 150, 57 },
		{ 150, 59 },
		{ 150, 48 },
		{ 115, 45 },
		{ 150, 53 },
		{ 150, 58 },
		{ 150, 152 },
		{ 150, 55 },
		{ 150, 52 },
		{ 150, 44 },
		{ 150, 51 },
		{ 142, -1 },
		{ 142, -1 },
		{ 142, -1 },
		{ 142, 147 },
		{ 41, 8 },
		{ 149, 151 },
		{ 41, 12 },
		{ 21, 41 },
		{ 21, 5 },
		{ 144, 148 },
		{ 0, 6 },
		{ 141, 146 },
		{ 0, 7 },
		{ 0, 5 },
		{ 115, 140 },
		{ 0, 4 },
		{ 140, 145 },
		{ 140, 46 },
		{ 140, 47 },
		{ 140, 42 },
		{ 142, -1 },
		{ 142, -1 },
		{ 142, -1 },
		{ 142, -1 },
		{ 142, -1 },
		{ 139, 143 },
		{ 7, 8 },
		{ 106, 134 },
		{ 7, 12 },
		{ 41, 50 },
		{ 7, 11 },
		{ 107, -1 },
		{ 107, -1 },
		{ 107, 135 },
		{ 41, 85 },
		{ 105, 133 },
		{ 21, 66 },
		{ 110, -1 },
		{ 110, -1 },
		{ 110, -1 },
		{ 110, -1 },
		{ 110, -1 },
		{ 110, 138 },
		{ 98, -1 },
		{ 98, -1 },
		{ 98, 128 },
		{ 109, 137 },
		{ 109, 65 },
		{ 108, 136 },
		{ 108, 60 },
		{ 103, 131 },
		{ 103, 49 },
		{ 101, -1 },
		{ 101, 129 },
		{ 95, 125 },
		{ 95, 57 },
		{ 91, -1 },
		{ 91, 123 },
		{ 88, -1 },
		{ 88, 121 },
		{ 87, 120 },
		{ 87, 63 },
		{ 104, 132 },
		{ 102, 130 },
		{ 97, 127 },
		{ 96, 126 },
		{ 94, 124 },
		{ 90, 122 },
		{ 86, 119 },
		{ 85, 112 },
		{ 83, 117 },
		{ 70, 116 },
		{ 69, 115 },
		{ 68, 114 },
		{ 53, 93 },
		{ 40, 83 },
		{ 26, 67 },
		{ 20, 24 },
		{ 17, 22 },
		{ 8, 15 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 34, 7 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, -1 },
		{ 99, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 73, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 72, -1 },
		{ 29, 41 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 94, 140 },
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
		{ 76, -1 },
		{ 27, 150 },
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
		{ 78, 98 },
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
		{ 0, 85 },
		{ 0, -1 },
		{ 91, 140 },
		{ 68, 115 },
		{ 89, 140 },
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
		{ 87, 88 },
		{ 0, -1 },
		{ 67, 150 },
		{ 83, 142 },
		{ 73, 109 },
		{ 76, 140 },
		{ 0, -1 },
		{ 73, 91 },
		{ 63, 107 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, 95 },
		{ 59, 98 },
		{ 69, 98 },
		{ 68, 98 },
		{ 49, 91 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, 110 },
		{ 71, 103 },
		{ 58, 107 },
		{ 69, 107 },
		{ 42, 107 },
		{ 34, 107 },
		{ 40, 101 },
		{ 59, 110 },
		{ 58, 108 },
		{ 52, 142 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 10, 140 },
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
		{ 23, 150 },
		{ 34, 142 },
		{ 9, 150 },
		{ 18, 150 },
		{ 0, -1 },
		{ 7, 150 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 3, 150 },
		{ -7, -1 },
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
#line 301 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(const char YYFAR* text) {
	cerr << "Syntax error at: row(" << row_count << "), column(" << col_count << ")" << endl;
}

int main()
{
	tables.insert({root_table, table_count++});
	int n = 1;
	ifstream * in = new ifstream("code.c");
	ofstream * out = new ofstream("code.asm");
	mylexer lexer;
	myparser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			lexer.yyin = in;

			n = parser.yyparse();
			
			// cout << "Grammar Tree:" << endl;
			// root_node->traverse();
			// cout << endl;
			
			// outputTables();
			// cout << endl;
			
			Tree tree(root_node);
			tree.gen_label();

			tree.gen_code(*out);

			// root_node->traverse();
			// cout << endl;
		}
	}
	in->close();
	out->close();
	// system("pause");
	return n;
}

