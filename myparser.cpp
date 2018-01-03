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
* Date: 01/03/18
* Time: 08:53:30
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
		return;
	}
	for (unsigned int i = 0; i < var_id->children.size(); ++i) {
		declInsertEntry(var_id->children[i], val_type);
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
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
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
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(decl_t, yyattribute(1 - 3), yyattribute(2 - 3)); declInsertEntry(yyattribute(2 - 3), vt_converter[string(yyattribute(1 - 3)->data.string_v)]);
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
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(idt_list_t, yyattribute(1 - 3), yyattribute(3 - 3));
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
yyattribute(1 - 3)->val_type = yyattribute(1 - 3)->symbolCheck(string(yyattribute(1 - 3)->data.string_v))->val_type; (*(YYSTYPE YYFAR*)yyvalptr) = new Node(assign_expr_t, yyattribute(2 - 3)->data.op_v, yyattribute(1 - 3), yyattribute(3 - 3));
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
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(unary_expr_t, yyattribute(1 - 2)->data.op_v, yyattribute(2 - 2));
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
(*(YYSTYPE YYFAR*)yyvalptr) = yyattribute(1 - 1); (*(YYSTYPE YYFAR*)yyvalptr)->val_type = (*(YYSTYPE YYFAR*)yyvalptr)->symbolCheck(string((*(YYSTYPE YYFAR*)yyvalptr)->data.string_v))->val_type;
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
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(dowhile_stmt_t, yyattribute(5 - 6), yyattribute(2 - 6));
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
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 288 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 4), yyattribute(3 - 4)); returnScope();
#line 1352 "myparser.cpp"
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
#line 289 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1365 "myparser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 290 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t, yyattribute(2 - 3)); returnScope();
#line 1378 "myparser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 291 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(compound_stmt_t); returnScope();
#line 1391 "myparser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 295 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 7), yyattribute(5 - 7), yyattribute(7 - 7));
#line 1404 "myparser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 296 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(if_stmt_t, yyattribute(3 - 5), yyattribute(5 - 5));
#line 1417 "myparser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 300 ".\\myparser.y"
(*(YYSTYPE YYFAR*)yyvalptr) = new Node(stmt_list_t, yyattribute(1 - 2), yyattribute(2 - 2));
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
		"blocks: decl_list func",
		"blocks: func",
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
		"loop_stmt: DO stmt WHILE \'(\' expr \')\'",
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
		{ 31, 4, 86 },
		{ 31, 3, 87 },
		{ 31, 3, 88 },
		{ 31, 2, 89 },
		{ 32, 7, 90 },
		{ 32, 5, 91 },
		{ 33, 2, 92 },
		{ 33, 1, 93 }
	};
	yyreduction = reduction;

	yytokenaction_size = 259;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 157, YYAT_SHIFT, 26 },
		{ 42, YYAT_SHIFT, 74 },
		{ 147, YYAT_ERROR, 0 },
		{ 5, YYAT_SHIFT, 12 },
		{ 62, YYAT_SHIFT, 107 },
		{ 43, YYAT_SHIFT, 87 },
		{ 45, YYAT_SHIFT, 89 },
		{ 157, YYAT_SHIFT, 27 },
		{ 14, YYAT_SHIFT, 19 },
		{ 125, YYAT_SHIFT, 103 },
		{ 157, YYAT_SHIFT, 28 },
		{ 152, YYAT_SHIFT, 157 },
		{ 157, YYAT_SHIFT, 29 },
		{ 151, YYAT_SHIFT, 156 },
		{ 125, YYAT_SHIFT, 104 },
		{ 124, YYAT_SHIFT, 103 },
		{ 151, YYAT_SHIFT, 89 },
		{ 59, YYAT_SHIFT, 103 },
		{ 149, YYAT_SHIFT, 154 },
		{ 125, YYAT_SHIFT, 105 },
		{ 124, YYAT_SHIFT, 104 },
		{ 45, YYAT_SHIFT, 90 },
		{ 59, YYAT_SHIFT, 104 },
		{ 14, YYAT_SHIFT, 20 },
		{ 145, YYAT_SHIFT, 150 },
		{ 124, YYAT_SHIFT, 105 },
		{ 157, YYAT_SHIFT, 30 },
		{ 59, YYAT_SHIFT, 105 },
		{ 8, YYAT_SHIFT, 1 },
		{ 8, YYAT_SHIFT, 2 },
		{ 141, YYAT_SHIFT, 95 },
		{ 141, YYAT_SHIFT, 96 },
		{ 141, YYAT_SHIFT, 97 },
		{ 141, YYAT_SHIFT, 98 },
		{ 142, YYAT_SHIFT, 111 },
		{ 142, YYAT_SHIFT, 112 },
		{ 8, YYAT_SHIFT, 3 },
		{ 140, YYAT_SHIFT, 95 },
		{ 140, YYAT_SHIFT, 96 },
		{ 140, YYAT_SHIFT, 97 },
		{ 140, YYAT_SHIFT, 98 },
		{ 56, YYAT_SHIFT, 95 },
		{ 56, YYAT_SHIFT, 96 },
		{ 56, YYAT_SHIFT, 97 },
		{ 56, YYAT_SHIFT, 98 },
		{ 131, YYAT_SHIFT, 93 },
		{ 130, YYAT_SHIFT, 93 },
		{ 131, YYAT_SHIFT, 94 },
		{ 130, YYAT_SHIFT, 94 },
		{ 55, YYAT_SHIFT, 93 },
		{ 144, YYAT_SHIFT, 42 },
		{ 55, YYAT_SHIFT, 94 },
		{ 129, YYAT_SHIFT, 99 },
		{ 129, YYAT_SHIFT, 100 },
		{ 128, YYAT_SHIFT, 99 },
		{ 128, YYAT_SHIFT, 100 },
		{ 127, YYAT_SHIFT, 99 },
		{ 127, YYAT_SHIFT, 100 },
		{ 126, YYAT_SHIFT, 99 },
		{ 126, YYAT_SHIFT, 100 },
		{ 65, YYAT_SHIFT, 111 },
		{ 65, YYAT_SHIFT, 112 },
		{ 58, YYAT_SHIFT, 101 },
		{ 58, YYAT_SHIFT, 102 },
		{ 57, YYAT_SHIFT, 99 },
		{ 57, YYAT_SHIFT, 100 },
		{ 147, YYAT_ERROR, 0 },
		{ 139, YYAT_SHIFT, 113 },
		{ 138, YYAT_SHIFT, 110 },
		{ 137, YYAT_SHIFT, 106 },
		{ 136, YYAT_SHIFT, 147 },
		{ 135, YYAT_SHIFT, 109 },
		{ 120, YYAT_SHIFT, 146 },
		{ 119, YYAT_SHIFT, 30 },
		{ 118, YYAT_SHIFT, 144 },
		{ 117, YYAT_SHIFT, 143 },
		{ 88, YYAT_SHIFT, 122 },
		{ 71, YYAT_SHIFT, 118 },
		{ 69, YYAT_SHIFT, 116 },
		{ 68, YYAT_SHIFT, 114 },
		{ 66, YYAT_SHIFT, 113 },
		{ 64, YYAT_SHIFT, 110 },
		{ 63, YYAT_SHIFT, 109 },
		{ 60, YYAT_SHIFT, 106 },
		{ 37, YYAT_SHIFT, 73 },
		{ 36, YYAT_SHIFT, 72 },
		{ 34, YYAT_SHIFT, 70 },
		{ 22, YYAT_SHIFT, 31 },
		{ 21, YYAT_SHIFT, 22 },
		{ 19, YYAT_SHIFT, 24 },
		{ 17, YYAT_SHIFT, 21 },
		{ 11, YYAT_SHIFT, 18 },
		{ 10, YYAT_SHIFT, 17 },
		{ 157, YYAT_SHIFT, 32 },
		{ 6, YYAT_ACCEPT, 0 },
		{ 3, YYAT_SHIFT, 11 },
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
		{ 43, YYAT_SHIFT, 33 },
		{ 43, YYAT_SHIFT, 2 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 147, YYAT_ERROR, 0 },
		{ 147, YYAT_ERROR, 0 },
		{ 147, YYAT_ERROR, 0 },
		{ 147, YYAT_ERROR, 0 },
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
		{ 62, YYAT_SHIFT, 108 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 157, YYAT_SHIFT, 34 },
		{ 157, YYAT_SHIFT, 35 },
		{ 157, YYAT_SHIFT, 36 },
		{ 157, YYAT_SHIFT, 37 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 147, YYAT_SHIFT, 91 },
		{ 5, YYAT_SHIFT, 13 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 157, YYAT_SHIFT, 38 },
		{ 157, YYAT_SHIFT, 39 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 157, YYAT_SHIFT, 40 },
		{ 157, YYAT_SHIFT, 41 },
		{ 157, YYAT_SHIFT, 42 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ 0, 0, YYAT_DEFAULT, 8 },
		{ -169, 1, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 55, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ -56, 1, YYAT_ERROR, 0 },
		{ 94, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -229, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 52, 1, YYAT_ERROR, 0 },
		{ 50, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ -36, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ 49, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 21 },
		{ -202, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -35, 1, YYAT_ERROR, 0 },
		{ -38, 1, YYAT_DEFAULT, 43 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_REDUCE, 86 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 46, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ 45, 1, YYAT_ERROR, 0 },
		{ 44, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ -60, 1, YYAT_REDUCE, 54 },
		{ -120, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ -38, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 94 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 6, 1, YYAT_REDUCE, 41 },
		{ -240, 1, YYAT_REDUCE, 33 },
		{ -223, 1, YYAT_REDUCE, 38 },
		{ -223, 1, YYAT_REDUCE, 50 },
		{ -20, 1, YYAT_REDUCE, 44 },
		{ -195, 1, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ -59, 1, YYAT_REDUCE, 20 },
		{ -42, 1, YYAT_REDUCE, 24 },
		{ -13, 1, YYAT_REDUCE, 26 },
		{ -219, 1, YYAT_REDUCE, 30 },
		{ 42, 1, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ -46, 1, YYAT_DEFAULT, 157 },
		{ 37, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 119 },
		{ 0, 0, YYAT_DEFAULT, 144 },
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
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ -49, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_DEFAULT, 147 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ 0, 0, YYAT_REDUCE, 93 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 34, 1, YYAT_DEFAULT, 151 },
		{ 34, 1, YYAT_ERROR, 0 },
		{ 14, 1, YYAT_DEFAULT, 144 },
		{ 31, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ -22, 1, YYAT_REDUCE, 42 },
		{ -28, 1, YYAT_REDUCE, 43 },
		{ -229, 1, YYAT_REDUCE, 34 },
		{ -231, 1, YYAT_REDUCE, 35 },
		{ -233, 1, YYAT_REDUCE, 36 },
		{ -235, 1, YYAT_REDUCE, 37 },
		{ 3, 1, YYAT_REDUCE, 39 },
		{ 2, 1, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ -53, 1, YYAT_REDUCE, 23 },
		{ 12, 1, YYAT_ERROR, 0 },
		{ -209, 1, YYAT_REDUCE, 21 },
		{ -26, 1, YYAT_REDUCE, 25 },
		{ 29, 1, YYAT_REDUCE, 27 },
		{ -244, 1, YYAT_REDUCE, 31 },
		{ -251, 1, YYAT_REDUCE, 32 },
		{ -245, 1, YYAT_REDUCE, 29 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ -241, 1, YYAT_DEFAULT, 147 },
		{ -17, 1, YYAT_DEFAULT, 144 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ -57, 1, YYAT_DEFAULT, 157 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -23, 1, YYAT_DEFAULT, 151 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ -28, 1, YYAT_ERROR, 0 },
		{ -253, 1, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_DEFAULT, 157 },
		{ -33, 1, YYAT_DEFAULT, 21 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ 0, 0, YYAT_REDUCE, 91 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 108;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 157, 45 },
		{ 157, 47 },
		{ 157, 44 },
		{ 157, 61 },
		{ 157, 62 },
		{ 157, 60 },
		{ 157, 63 },
		{ 157, 64 },
		{ 157, 66 },
		{ 157, 65 },
		{ 157, 56 },
		{ 157, 57 },
		{ 157, 55 },
		{ 157, 59 },
		{ 157, 48 },
		{ 157, 58 },
		{ 157, 51 },
		{ 156, 158 },
		{ 157, 53 },
		{ 157, 49 },
		{ 157, 159 },
		{ 157, 52 },
		{ 157, 54 },
		{ 157, 46 },
		{ 157, 67 },
		{ 147, -1 },
		{ 147, -1 },
		{ 147, -1 },
		{ 147, 153 },
		{ 43, 5 },
		{ 119, 45 },
		{ 43, 16 },
		{ 22, 43 },
		{ 22, 9 },
		{ 113, -1 },
		{ 113, -1 },
		{ 113, -1 },
		{ 113, -1 },
		{ 113, -1 },
		{ 113, -1 },
		{ 113, 142 },
		{ 145, 151 },
		{ 145, 47 },
		{ 145, 44 },
		{ 145, 61 },
		{ 147, -1 },
		{ 147, -1 },
		{ 147, -1 },
		{ 147, -1 },
		{ 147, -1 },
		{ 150, 155 },
		{ 8, 5 },
		{ 119, 145 },
		{ 8, 16 },
		{ 43, 50 },
		{ 8, 15 },
		{ 105, -1 },
		{ 105, -1 },
		{ 105, 134 },
		{ 43, 88 },
		{ 146, 152 },
		{ 22, 68 },
		{ 0, 6 },
		{ 0, 7 },
		{ 144, 149 },
		{ 0, 8 },
		{ 0, 9 },
		{ 143, 148 },
		{ 0, 4 },
		{ 112, -1 },
		{ 112, 141 },
		{ 110, 139 },
		{ 110, 65 },
		{ 109, 138 },
		{ 109, 66 },
		{ 108, 137 },
		{ 108, 63 },
		{ 106, 135 },
		{ 106, 64 },
		{ 100, -1 },
		{ 100, 131 },
		{ 98, -1 },
		{ 98, 129 },
		{ 94, 125 },
		{ 94, 48 },
		{ 89, -1 },
		{ 89, 123 },
		{ 111, 140 },
		{ 107, 136 },
		{ 104, 133 },
		{ 103, 132 },
		{ 99, 130 },
		{ 97, 128 },
		{ 96, 127 },
		{ 95, 126 },
		{ 93, 124 },
		{ 88, 115 },
		{ 86, 121 },
		{ 73, 120 },
		{ 72, 119 },
		{ 70, 117 },
		{ 53, 92 },
		{ 42, 86 },
		{ 35, 71 },
		{ 27, 69 },
		{ 21, 25 },
		{ 18, 23 },
		{ 5, 14 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 61, 8 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 101, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 48, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 74, -1 },
		{ 28, 43 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 96, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, 157 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 77, -1 },
		{ 26, 157 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 79, 105 },
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
		{ 0, 88 },
		{ 0, -1 },
		{ 92, 145 },
		{ 0, -1 },
		{ 69, 119 },
		{ 90, 145 },
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
		{ 88, 89 },
		{ 0, -1 },
		{ 68, 157 },
		{ 77, 145 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 74, 94 },
		{ 62, 105 },
		{ 75, 98 },
		{ 74, 98 },
		{ 73, 98 },
		{ 63, 112 },
		{ 71, 100 },
		{ 60, 98 },
		{ 0, -1 },
		{ 0, -1 },
		{ 68, 105 },
		{ 67, 105 },
		{ 36, 100 },
		{ 63, 109 },
		{ 77, 147 },
		{ 62, 106 },
		{ 58, 110 },
		{ 55, 113 },
		{ 69, 112 },
		{ 52, 113 },
		{ 23, 147 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 22, 145 },
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
		{ 39, 157 },
		{ 56, 145 },
		{ 33, 147 },
		{ 32, 157 },
		{ 17, 157 },
		{ 0, -1 },
		{ 0, -1 },
		{ 22, 157 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -11, 157 },
		{ -8, -1 },
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

