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
* Date: 01/02/18
* Time: 20:08:30
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
	if (var_id->getType() == idt_t) {
		var_id->setEntry(new SymbolEntry(val_type, var_st));
		var_id->getTable()->insert(var_id->getString(), var_id->getEntry());
		return;
	}
	for (int i = 0; i < var_id->getChildrenSize(); ++i) {
		declInsertEntry(var_id->getChild(i), val_type);
	}
}

void funcInsertEntry() {
	curr_table->insert("main", new SymbolEntry(int_vt, function_st));
}

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


#line 86 "myparser.cpp"
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
#line 62 ".\\myparser.y"

	// place any extra initialisation code here

#line 110 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 67 ".\\myparser.y"

	// place any extra cleanup code here

#line 124 "myparser.cpp"
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
#line 102 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); cout << "Grammar Tree:" << endl; (*(YYSTYPE YYFAR*)yyvalptr)->traverse(); cout << endl; outputTables(); cout << endl;
#line 234 "myparser.cpp"
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
#line 106 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(program_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 247 "myparser.cpp"
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
#line 107 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(program_t, yyattribute(1 - 1));
#line 260 "myparser.cpp"
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
#line 113 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "integer");
#line 273 "myparser.cpp"
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
#line 114 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(type_t, "character");
#line 286 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 120 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_group_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 299 "myparser.cpp"
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
#line 121 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 312 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 125 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 3), yyattribute(2 - 3)); declInsertEntry(yyattribute(2 - 3), vt_converter[yyattribute(1 - 3)->getString()]);
#line 325 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 126 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 2));
#line 338 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 130 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_list_t, yyattribute(1 - 3), yyattribute(3 - 3));
#line 351 "myparser.cpp"
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
#line 131 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 364 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 137 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, new Node(type_t, "integer"), yyattribute(5 - 5)); funcInsertEntry();
#line 377 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 138 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(func_t, new Node(type_t, "integer"), yyattribute(4 - 4)); funcInsertEntry();
#line 390 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 144 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(expr_t, comma_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 403 "myparser.cpp"
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
#line 145 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 416 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 149 ".\\myparser.y"
yyattribute(1 - 3)->setValType(yyattribute(1 - 3)->symbolCheck(yyattribute(1 - 3)->getString())->val_type); (*(YYSTYPE YYFAR*)yyvalptr) = new Node(assign_expr_t, yyattribute(2 - 3)->getOp(), yyattribute(1 - 3), yyattribute(3 - 3));
#line 429 "myparser.cpp"
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
#line 150 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 442 "myparser.cpp"
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
#line 154 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 455 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 158 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(ternary_expr_t, ternary_d, yyattribute(1 - 5), yyattribute(2 - 5), yyattribute(3 - 5));
#line 468 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 159 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 481 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 163 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(logical_expr_t, or_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 494 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 164 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 507 "myparser.cpp"
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
#line 168 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(logical_expr_t, and_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 520 "myparser.cpp"
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
#line 169 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 533 "myparser.cpp"
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
#line 173 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_or_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 546 "myparser.cpp"
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
#line 174 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 559 "myparser.cpp"
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
#line 178 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_xor_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 572 "myparser.cpp"
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
#line 179 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 585 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 183 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, bit_and_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 598 "myparser.cpp"
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
#line 184 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 611 "myparser.cpp"
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
#line 188 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, eq_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 624 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 189 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, ne_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 637 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 190 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 650 "myparser.cpp"
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
#line 194 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, le_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 663 "myparser.cpp"
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
#line 195 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, ge_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 676 "myparser.cpp"
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
#line 196 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, lt_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 689 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 197 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(comp_expr_t, gt_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 702 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 198 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 715 "myparser.cpp"
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
#line 202 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, lshift_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 728 "myparser.cpp"
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
#line 203 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, rshift_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 741 "myparser.cpp"
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
#line 204 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 754 "myparser.cpp"
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
#line 208 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, add_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 767 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 209 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, sub_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 780 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 210 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 793 "myparser.cpp"
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
#line 214 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, mul_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 806 "myparser.cpp"
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
#line 215 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, div_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 819 "myparser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 216 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(calc_expr_t, mod_d, yyattribute(1 - 3), yyattribute(3 - 3));
#line 832 "myparser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 217 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 845 "myparser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 221 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(unary_expr_t, yyattribute(1 - 2)->getOp(), yyattribute(2 - 2));
#line 858 "myparser.cpp"
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
#line 222 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 871 "myparser.cpp"
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
#line 226 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(post_expr_t, post_inc_d, yyattribute(1 - 2));
#line 884 "myparser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 227 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(post_expr_t, post_dec_d, yyattribute(1 - 2));
#line 897 "myparser.cpp"
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
#line 228 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 910 "myparser.cpp"
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
#line 232 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); (*(YYSTYPE YYFAR*)yyvalptr)->setValType((*(YYSTYPE YYFAR*)yyvalptr)->symbolCheck((*(YYSTYPE YYFAR*)yyvalptr)->getString())->val_type);
#line 923 "myparser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 233 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 936 "myparser.cpp"
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
#line 234 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(2 - 3);
#line 949 "myparser.cpp"
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
#line 238 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, assign_d);
#line 962 "myparser.cpp"
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
#line 239 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, addassign_d);
#line 975 "myparser.cpp"
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
#line 240 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, subassign_d);
#line 988 "myparser.cpp"
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
#line 241 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, mulassign_d);
#line 1001 "myparser.cpp"
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
#line 242 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, divassign_d);
#line 1014 "myparser.cpp"
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
#line 243 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, modassign_d);
#line 1027 "myparser.cpp"
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
#line 244 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, andassign_d);
#line 1040 "myparser.cpp"
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
#line 245 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, orassign_d);
#line 1053 "myparser.cpp"
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
#line 246 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, xorassign_d);
#line 1066 "myparser.cpp"
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
#line 247 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, revassign_d);
#line 1079 "myparser.cpp"
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
#line 248 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, lshiftassign_d);
#line 1092 "myparser.cpp"
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
#line 249 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, rshiftassign_d);
#line 1105 "myparser.cpp"
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
#line 253 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pos_d);
#line 1118 "myparser.cpp"
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
#line 254 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, neg_d);
#line 1131 "myparser.cpp"
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
#line 255 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, rev_d);
#line 1144 "myparser.cpp"
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
#line 256 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, not_d);
#line 1157 "myparser.cpp"
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
#line 257 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pre_inc_d);
#line 1170 "myparser.cpp"
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
#line 258 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(temp_expr_t, pre_dec_d);
#line 1183 "myparser.cpp"
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
#line 262 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1196 "myparser.cpp"
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
#line 263 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1209 "myparser.cpp"
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
#line 269 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1222 "myparser.cpp"
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
#line 270 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1235 "myparser.cpp"
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
#line 271 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1248 "myparser.cpp"
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
#line 272 ".\\myparser.y"
if (entered) returnScope(); (*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1261 "myparser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 276 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(while_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1274 "myparser.cpp"
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
#line 277 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(dowhile_stmt_t, yyattribute(2 - 6), yyattribute(5 - 6));
#line 1287 "myparser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 278 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(3 - 7), yyattribute(4 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 1300 "myparser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 279 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(for_stmt_t, yyattribute(3 - 6), yyattribute(4 - 6), yyattribute(6 - 6));
#line 1313 "myparser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 283 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 2);
#line 1326 "myparser.cpp"
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
#line 284 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(empty_stmt_t);
#line 1339 "myparser.cpp"
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
#line 288 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1352 "myparser.cpp"
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
#line 289 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); returnScope();
#line 1365 "myparser.cpp"
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
#line 293 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 1378 "myparser.cpp"
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
#line 294 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1391 "myparser.cpp"
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
#line 298 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 1404 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 299 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
#line 1417 "myparser.cpp"
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
#line 300 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1430 "myparser.cpp"
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
#line 301 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1);
#line 1443 "myparser.cpp"
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
		{ "DO", 260 },
		{ "FOR", 261 },
		{ "IF", 262 },
		{ "NO_ELSE", 263 },
		{ "ELSE", 264 },
		{ "MAIN", 265 },
		{ "ADDASSIGN", 266 },
		{ "SUBASSIGN", 267 },
		{ "MULASSIGN", 268 },
		{ "DIVASSIGN", 269 },
		{ "MODASSIGN", 270 },
		{ "ANDASSIGN", 271 },
		{ "ORASSIGN", 272 },
		{ "XORASSIGN", 273 },
		{ "REVASSIGN", 274 },
		{ "LSHIFTASSIGN", 275 },
		{ "RSHIFTASSIGN", 276 },
		{ "OR", 277 },
		{ "AND", 278 },
		{ "EQ", 279 },
		{ "NE", 280 },
		{ "LE", 281 },
		{ "GE", 282 },
		{ "LT", 283 },
		{ "GT", 284 },
		{ "INC", 285 },
		{ "DEC", 286 },
		{ "LSHIFT", 287 },
		{ "RSHIFT", 288 },
		{ "INTVAL", 289 },
		{ "CHARVAL", 290 },
		{ "ID", 291 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: blocks",
		"blocks: decl_group func",
		"blocks: func",
		"type: INT",
		"type: CHAR",
		"decl_group: decl_group decl",
		"decl_group: decl",
		"decl: type decl_list \';\'",
		"decl: type \';\'",
		"decl_list: decl_list \',\' ID",
		"decl_list: ID",
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
		{ 4, 2, 5 },
		{ 4, 1, 6 },
		{ 5, 3, 7 },
		{ 5, 2, 8 },
		{ 6, 3, 9 },
		{ 6, 1, 10 },
		{ 7, 5, 11 },
		{ 7, 4, 12 },
		{ 8, 3, 13 },
		{ 8, 1, 14 },
		{ 9, 3, 15 },
		{ 9, 1, 16 },
		{ 10, 1, 17 },
		{ 11, 5, 18 },
		{ 11, 1, 19 },
		{ 12, 3, 20 },
		{ 12, 1, 21 },
		{ 13, 3, 22 },
		{ 13, 1, 23 },
		{ 14, 3, 24 },
		{ 14, 1, 25 },
		{ 15, 3, 26 },
		{ 15, 1, 27 },
		{ 16, 3, 28 },
		{ 16, 1, 29 },
		{ 17, 3, 30 },
		{ 17, 3, 31 },
		{ 17, 1, 32 },
		{ 18, 3, 33 },
		{ 18, 3, 34 },
		{ 18, 3, 35 },
		{ 18, 3, 36 },
		{ 18, 1, 37 },
		{ 19, 3, 38 },
		{ 19, 3, 39 },
		{ 19, 1, 40 },
		{ 20, 3, 41 },
		{ 20, 3, 42 },
		{ 20, 1, 43 },
		{ 21, 3, 44 },
		{ 21, 3, 45 },
		{ 21, 3, 46 },
		{ 21, 1, 47 },
		{ 22, 2, 48 },
		{ 22, 1, 49 },
		{ 23, 2, 50 },
		{ 23, 2, 51 },
		{ 23, 1, 52 },
		{ 24, 1, 53 },
		{ 24, 1, 54 },
		{ 24, 3, 55 },
		{ 25, 1, 56 },
		{ 25, 1, 57 },
		{ 25, 1, 58 },
		{ 25, 1, 59 },
		{ 25, 1, 60 },
		{ 25, 1, 61 },
		{ 25, 1, 62 },
		{ 25, 1, 63 },
		{ 25, 1, 64 },
		{ 25, 1, 65 },
		{ 25, 1, 66 },
		{ 25, 1, 67 },
		{ 26, 1, 68 },
		{ 26, 1, 69 },
		{ 26, 1, 70 },
		{ 26, 1, 71 },
		{ 26, 1, 72 },
		{ 26, 1, 73 },
		{ 27, 1, 74 },
		{ 27, 1, 75 },
		{ 28, 1, 76 },
		{ 28, 1, 77 },
		{ 28, 1, 78 },
		{ 28, 1, 79 },
		{ 29, 5, 80 },
		{ 29, 6, 81 },
		{ 29, 7, 82 },
		{ 29, 6, 83 },
		{ 30, 2, 84 },
		{ 30, 1, 85 },
		{ 31, 3, 86 },
		{ 31, 2, 87 },
		{ 32, 7, 88 },
		{ 32, 5, 89 },
		{ 33, 2, 90 },
		{ 33, 2, 91 },
		{ 33, 1, 92 },
		{ 33, 1, 93 }
	};
	yyreduction = reduction;

	yytokenaction_size = 259;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 155, YYAT_SHIFT, 26 },
		{ 42, YYAT_SHIFT, 74 },
		{ 145, YYAT_ERROR, 0 },
		{ 8, YYAT_SHIFT, 12 },
		{ 59, YYAT_SHIFT, 106 },
		{ 67, YYAT_SHIFT, 112 },
		{ 44, YYAT_SHIFT, 87 },
		{ 155, YYAT_SHIFT, 27 },
		{ 14, YYAT_SHIFT, 19 },
		{ 138, YYAT_SHIFT, 96 },
		{ 155, YYAT_SHIFT, 28 },
		{ 150, YYAT_SHIFT, 155 },
		{ 155, YYAT_SHIFT, 29 },
		{ 149, YYAT_SHIFT, 154 },
		{ 138, YYAT_SHIFT, 97 },
		{ 137, YYAT_SHIFT, 96 },
		{ 149, YYAT_SHIFT, 87 },
		{ 54, YYAT_SHIFT, 96 },
		{ 147, YYAT_SHIFT, 152 },
		{ 138, YYAT_SHIFT, 98 },
		{ 137, YYAT_SHIFT, 97 },
		{ 44, YYAT_SHIFT, 88 },
		{ 54, YYAT_SHIFT, 97 },
		{ 14, YYAT_SHIFT, 20 },
		{ 143, YYAT_SHIFT, 148 },
		{ 137, YYAT_SHIFT, 98 },
		{ 155, YYAT_SHIFT, 30 },
		{ 54, YYAT_SHIFT, 98 },
		{ 9, YYAT_SHIFT, 1 },
		{ 9, YYAT_SHIFT, 2 },
		{ 123, YYAT_SHIFT, 99 },
		{ 123, YYAT_SHIFT, 100 },
		{ 123, YYAT_SHIFT, 101 },
		{ 123, YYAT_SHIFT, 102 },
		{ 136, YYAT_SHIFT, 89 },
		{ 136, YYAT_SHIFT, 90 },
		{ 9, YYAT_SHIFT, 3 },
		{ 122, YYAT_SHIFT, 99 },
		{ 122, YYAT_SHIFT, 100 },
		{ 122, YYAT_SHIFT, 101 },
		{ 122, YYAT_SHIFT, 102 },
		{ 55, YYAT_SHIFT, 99 },
		{ 55, YYAT_SHIFT, 100 },
		{ 55, YYAT_SHIFT, 101 },
		{ 55, YYAT_SHIFT, 102 },
		{ 125, YYAT_SHIFT, 104 },
		{ 124, YYAT_SHIFT, 104 },
		{ 125, YYAT_SHIFT, 105 },
		{ 124, YYAT_SHIFT, 105 },
		{ 58, YYAT_SHIFT, 104 },
		{ 142, YYAT_SHIFT, 42 },
		{ 58, YYAT_SHIFT, 105 },
		{ 135, YYAT_SHIFT, 91 },
		{ 135, YYAT_SHIFT, 92 },
		{ 134, YYAT_SHIFT, 91 },
		{ 134, YYAT_SHIFT, 92 },
		{ 133, YYAT_SHIFT, 91 },
		{ 133, YYAT_SHIFT, 92 },
		{ 132, YYAT_SHIFT, 91 },
		{ 132, YYAT_SHIFT, 92 },
		{ 65, YYAT_SHIFT, 110 },
		{ 65, YYAT_SHIFT, 111 },
		{ 49, YYAT_SHIFT, 91 },
		{ 49, YYAT_SHIFT, 92 },
		{ 48, YYAT_SHIFT, 89 },
		{ 48, YYAT_SHIFT, 90 },
		{ 145, YYAT_ERROR, 0 },
		{ 140, YYAT_SHIFT, 93 },
		{ 139, YYAT_SHIFT, 145 },
		{ 128, YYAT_SHIFT, 103 },
		{ 127, YYAT_SHIFT, 95 },
		{ 126, YYAT_SHIFT, 94 },
		{ 119, YYAT_SHIFT, 144 },
		{ 118, YYAT_SHIFT, 30 },
		{ 117, YYAT_SHIFT, 142 },
		{ 116, YYAT_SHIFT, 141 },
		{ 71, YYAT_SHIFT, 117 },
		{ 69, YYAT_SHIFT, 115 },
		{ 57, YYAT_SHIFT, 103 },
		{ 53, YYAT_SHIFT, 95 },
		{ 52, YYAT_SHIFT, 94 },
		{ 51, YYAT_SHIFT, 93 },
		{ 37, YYAT_SHIFT, 73 },
		{ 36, YYAT_SHIFT, 72 },
		{ 34, YYAT_SHIFT, 70 },
		{ 22, YYAT_SHIFT, 31 },
		{ 21, YYAT_SHIFT, 22 },
		{ 19, YYAT_SHIFT, 24 },
		{ 17, YYAT_SHIFT, 21 },
		{ 11, YYAT_SHIFT, 18 },
		{ 10, YYAT_SHIFT, 17 },
		{ 7, YYAT_ACCEPT, 0 },
		{ 3, YYAT_SHIFT, 11 },
		{ 155, YYAT_SHIFT, 32 },
		{ 1, YYAT_SHIFT, 10 },
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
		{ 67, YYAT_SHIFT, 33 },
		{ 67, YYAT_SHIFT, 2 },
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
		{ 145, YYAT_ERROR, 0 },
		{ 145, YYAT_ERROR, 0 },
		{ 145, YYAT_ERROR, 0 },
		{ 145, YYAT_ERROR, 0 },
		{ 42, YYAT_SHIFT, 75 },
		{ 42, YYAT_SHIFT, 76 },
		{ 42, YYAT_SHIFT, 77 },
		{ 42, YYAT_SHIFT, 78 },
		{ 42, YYAT_SHIFT, 79 },
		{ 42, YYAT_SHIFT, 80 },
		{ 42, YYAT_SHIFT, 81 },
		{ 42, YYAT_SHIFT, 82 },
		{ 42, YYAT_SHIFT, 83 },
		{ 42, YYAT_SHIFT, 84 },
		{ 42, YYAT_SHIFT, 85 },
		{ -1, YYAT_ERROR, 0 },
		{ 59, YYAT_SHIFT, 107 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 155, YYAT_SHIFT, 34 },
		{ 155, YYAT_SHIFT, 35 },
		{ 155, YYAT_SHIFT, 36 },
		{ 155, YYAT_SHIFT, 37 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 145, YYAT_SHIFT, 108 },
		{ 8, YYAT_SHIFT, 13 },
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
		{ 155, YYAT_SHIFT, 38 },
		{ 155, YYAT_SHIFT, 39 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 155, YYAT_SHIFT, 40 },
		{ 155, YYAT_SHIFT, 41 },
		{ 155, YYAT_SHIFT, 42 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 9 },
		{ -171, 1, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 52, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 91, 1, YYAT_ERROR, 0 },
		{ -56, 1, YYAT_ERROR, 0 },
		{ -229, 1, YYAT_ERROR, 0 },
		{ 50, 1, YYAT_ERROR, 0 },
		{ 48, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -36, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 47, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 21 },
		{ -204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -37, 1, YYAT_ERROR, 0 },
		{ -40, 1, YYAT_DEFAULT, 67 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 44, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ 43, 1, YYAT_ERROR, 0 },
		{ 42, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ -60, 1, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -215, 1, YYAT_REDUCE, 30 },
		{ -225, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ -197, 1, YYAT_REDUCE, 22 },
		{ -44, 1, YYAT_REDUCE, 24 },
		{ -15, 1, YYAT_REDUCE, 26 },
		{ -20, 1, YYAT_REDUCE, 44 },
		{ -240, 1, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 40, 1, YYAT_REDUCE, 28 },
		{ 6, 1, YYAT_REDUCE, 41 },
		{ -59, 1, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ -225, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ -120, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 36, 1, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ -183, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 118 },
		{ 0, 0, YYAT_DEFAULT, 142 },
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
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_DEFAULT, 145 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 91 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 34, 1, YYAT_DEFAULT, 149 },
		{ 34, 1, YYAT_ERROR, 0 },
		{ 14, 1, YYAT_DEFAULT, 142 },
		{ 31, 1, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -244, 1, YYAT_REDUCE, 31 },
		{ -251, 1, YYAT_REDUCE, 32 },
		{ 3, 1, YYAT_REDUCE, 39 },
		{ 2, 1, YYAT_REDUCE, 40 },
		{ -53, 1, YYAT_REDUCE, 23 },
		{ -24, 1, YYAT_REDUCE, 25 },
		{ 31, 1, YYAT_REDUCE, 27 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ -229, 1, YYAT_REDUCE, 34 },
		{ -231, 1, YYAT_REDUCE, 35 },
		{ -233, 1, YYAT_REDUCE, 36 },
		{ -235, 1, YYAT_REDUCE, 37 },
		{ -245, 1, YYAT_REDUCE, 29 },
		{ -22, 1, YYAT_REDUCE, 42 },
		{ -28, 1, YYAT_REDUCE, 43 },
		{ 10, 1, YYAT_ERROR, 0 },
		{ -211, 1, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ -241, 1, YYAT_DEFAULT, 145 },
		{ -17, 1, YYAT_DEFAULT, 142 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ -57, 1, YYAT_DEFAULT, 155 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -23, 1, YYAT_DEFAULT, 149 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_DEFAULT, 155 },
		{ -33, 1, YYAT_DEFAULT, 21 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 89 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 83;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 22, 43 },
		{ 67, 8 },
		{ 118, 44 },
		{ 67, 113 },
		{ 105, 138 },
		{ 105, 50 },
		{ 105, 65 },
		{ 105, 63 },
		{ 154, 156 },
		{ 105, 64 },
		{ 105, 60 },
		{ 0, 7 },
		{ 0, 5 },
		{ 148, 153 },
		{ 0, 9 },
		{ 0, 4 },
		{ 144, 150 },
		{ 0, 6 },
		{ 155, 157 },
		{ 155, 61 },
		{ 155, 62 },
		{ 155, 46 },
		{ 155, 68 },
		{ 22, 66 },
		{ 118, 143 },
		{ 142, 147 },
		{ 67, 114 },
		{ 141, 146 },
		{ 22, 67 },
		{ 145, 151 },
		{ 145, 59 },
		{ 145, 51 },
		{ 145, 52 },
		{ 145, 53 },
		{ 143, 149 },
		{ 143, 47 },
		{ 143, 45 },
		{ 143, 56 },
		{ 9, 8 },
		{ 106, 139 },
		{ 9, 15 },
		{ 104, 137 },
		{ 9, 16 },
		{ 107, -1 },
		{ 107, -1 },
		{ 107, 140 },
		{ 103, 136 },
		{ 103, 55 },
		{ 103, 49 },
		{ 102, 135 },
		{ 102, 58 },
		{ 98, -1 },
		{ 98, 131 },
		{ 95, 128 },
		{ 95, 48 },
		{ 94, 127 },
		{ 94, 57 },
		{ 93, -1 },
		{ 93, 126 },
		{ 92, 125 },
		{ 92, 54 },
		{ 90, -1 },
		{ 90, 123 },
		{ 87, -1 },
		{ 87, 121 },
		{ 101, 134 },
		{ 100, 133 },
		{ 99, 132 },
		{ 97, 130 },
		{ 96, 129 },
		{ 91, 124 },
		{ 89, 122 },
		{ 86, 120 },
		{ 73, 119 },
		{ 72, 118 },
		{ 70, 116 },
		{ 64, 109 },
		{ 42, 86 },
		{ 35, 71 },
		{ 27, 69 },
		{ 21, 25 },
		{ 18, 23 },
		{ 8, 14 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 10, 9 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 76, -1 },
		{ 35, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, -1 },
		{ -5, 67 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, 143 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 50, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 52, -1 },
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
		{ 54, 98 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, 143 },
		{ 0, -1 },
		{ 44, 118 },
		{ 65, 143 },
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
		{ 63, 87 },
		{ 55, 143 },
		{ 0, -1 },
		{ 53, 90 },
		{ 44, 103 },
		{ 50, 92 },
		{ 39, 105 },
		{ 44, 107 },
		{ 40, 95 },
		{ 37, 103 },
		{ 47, 98 },
		{ 46, 98 },
		{ 30, 105 },
		{ 48, 102 },
		{ 47, 102 },
		{ 46, 102 },
		{ 30, 92 },
		{ 29, 102 },
		{ 20, 105 },
		{ -17, -1 },
		{ 28, 145 },
		{ 32, 145 },
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
		{ -6, 143 },
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
		{ -1, 155 },
		{ 17, 143 },
		{ 26, 145 },
		{ -12, 155 },
		{ 18, 94 },
		{ 0, -1 },
		{ 0, -1 },
		{ -15, 155 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -20, 155 },
		{ -10, 118 },
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
#line 304 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

void myparser::yyerror(const char YYFAR* text) {
	cerr << "Syntax error at: row(" << row_count << "), column(" << col_count << ")" << endl;
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

