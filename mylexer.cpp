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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 12/06/17
* Time: 20:36:14
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: Saturday, November 4, 2017
****************************************************************************/
#include "myparser.h"
#include "utils.h"
using namespace std;

#define moveRight col_count += strlen(yytext)
#define moveTab col_count += 4 * strlen(yytext)
#define moveDown row_count += strlen(yytext); col_count = 1
#define moveComment for (size_t i = 0; i < strlen(yytext); ++i) { ++col_count; if (strncmp(yytext + i, "\n", 1) == 0) { ++row_count; col_count = 1; } }

#line 55 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 43 ".\\mylexer.l"

    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 151 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 52 ".\\mylexer.l"
moveRight;
#line 158 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 53 ".\\mylexer.l"
moveTab;
#line 165 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 54 ".\\mylexer.l"
moveDown;
#line 172 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 55 ".\\mylexer.l"
moveRight;
#line 179 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 56 ".\\mylexer.l"
moveComment;
#line 186 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 57 ".\\mylexer.l"
moveRight; return VOID;
#line 193 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 58 ".\\mylexer.l"
moveRight; return INT;
#line 200 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 59 ".\\mylexer.l"
moveRight; return FLOAT;
#line 207 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 60 ".\\mylexer.l"
moveRight; return DOUBLE;
#line 214 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 61 ".\\mylexer.l"
moveRight; return CHAR;
#line 221 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 62 ".\\mylexer.l"
moveRight; return BOOL;
#line 228 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 63 ".\\mylexer.l"
moveRight; return STRING;
#line 235 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 64 ".\\mylexer.l"
moveRight; return AUTO;
#line 242 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 65 ".\\mylexer.l"
moveRight; return STRUCT;
#line 249 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 66 ".\\mylexer.l"
moveRight; return UNION;
#line 256 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 67 ".\\mylexer.l"
moveRight; return ENUM;
#line 263 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 68 ".\\mylexer.l"
moveRight; return CONST;
#line 270 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 69 ".\\mylexer.l"
moveRight; return VOLATILE;
#line 277 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 70 ".\\mylexer.l"
moveRight; return SIZEOF;
#line 284 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 71 ".\\mylexer.l"
moveRight; return GOTO;
#line 291 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 72 ".\\mylexer.l"
moveRight; return BREAK;
#line 298 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 73 ".\\mylexer.l"
moveRight; return CONTINUE;
#line 305 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 74 ".\\mylexer.l"
moveRight; return RETURN;
#line 312 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 75 ".\\mylexer.l"
moveRight; return WHILE;
#line 319 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 76 ".\\mylexer.l"
moveRight; return DO;
#line 326 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 77 ".\\mylexer.l"
moveRight; return FOR;
#line 333 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 78 ".\\mylexer.l"
moveRight; return IF;
#line 340 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 79 ".\\mylexer.l"
moveRight; return ELSE;
#line 347 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 80 ".\\mylexer.l"
moveRight; return SWITCH;
#line 354 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 81 ".\\mylexer.l"
moveRight; return CASE;
#line 361 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 82 ".\\mylexer.l"
moveRight; return DEFAULT;
#line 368 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 83 ".\\mylexer.l"
moveRight; return ',';
#line 375 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 84 ".\\mylexer.l"
moveRight; return ':';
#line 382 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 85 ".\\mylexer.l"
moveRight; return '?';
#line 389 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 86 ".\\mylexer.l"
moveRight; return ADDASSIGN;
#line 396 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 87 ".\\mylexer.l"
moveRight; return SUBASSIGN;
#line 403 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 88 ".\\mylexer.l"
moveRight; return MULASSIGN;
#line 410 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 89 ".\\mylexer.l"
moveRight; return DIVASSIGN;
#line 417 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 90 ".\\mylexer.l"
moveRight; return MODASSIGN;
#line 424 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 91 ".\\mylexer.l"
moveRight; return ANDASSIGN;
#line 431 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 92 ".\\mylexer.l"
moveRight; return ORASSIGN;
#line 438 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 93 ".\\mylexer.l"
moveRight; return XORASSIGN;
#line 445 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 94 ".\\mylexer.l"
moveRight; return REVASSIGN;
#line 452 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 95 ".\\mylexer.l"
moveRight; return LSHIFTASSIGN;
#line 459 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 96 ".\\mylexer.l"
moveRight; return RSHIFTASSIGN;
#line 466 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 97 ".\\mylexer.l"
moveRight; return OR;
#line 473 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 98 ".\\mylexer.l"
moveRight; return AND;
#line 480 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 99 ".\\mylexer.l"
moveRight; return '|';
#line 487 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 100 ".\\mylexer.l"
moveRight; return '^';
#line 494 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 101 ".\\mylexer.l"
moveRight; return '&';
#line 501 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 102 ".\\mylexer.l"
moveRight; return EQ;
#line 508 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 103 ".\\mylexer.l"
moveRight; return NE;
#line 515 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 104 ".\\mylexer.l"
moveRight; return LE;
#line 522 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 105 ".\\mylexer.l"
moveRight; return GE;
#line 529 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 106 ".\\mylexer.l"
moveRight; return LSHIFT;
#line 536 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 107 ".\\mylexer.l"
moveRight; return RSHIFT;
#line 543 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 108 ".\\mylexer.l"
moveRight; return LT;
#line 550 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 109 ".\\mylexer.l"
moveRight; return GT;
#line 557 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 110 ".\\mylexer.l"
moveRight; return INC;
#line 564 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 111 ".\\mylexer.l"
moveRight; return DEC;
#line 571 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 112 ".\\mylexer.l"
moveRight; return PT;
#line 578 "mylexer.cpp"
		}
		break;
	case 62:
		{
#line 113 ".\\mylexer.l"
moveRight; return '+';
#line 585 "mylexer.cpp"
		}
		break;
	case 63:
		{
#line 114 ".\\mylexer.l"
moveRight; return '-';
#line 592 "mylexer.cpp"
		}
		break;
	case 64:
		{
#line 115 ".\\mylexer.l"
moveRight; return '*';
#line 599 "mylexer.cpp"
		}
		break;
	case 65:
		{
#line 116 ".\\mylexer.l"
moveRight; return '/';
#line 606 "mylexer.cpp"
		}
		break;
	case 66:
		{
#line 117 ".\\mylexer.l"
moveRight; return '%';
#line 613 "mylexer.cpp"
		}
		break;
	case 67:
		{
#line 118 ".\\mylexer.l"
moveRight; return '!';
#line 620 "mylexer.cpp"
		}
		break;
	case 68:
		{
#line 119 ".\\mylexer.l"
moveRight; return '~';
#line 627 "mylexer.cpp"
		}
		break;
	case 69:
		{
#line 120 ".\\mylexer.l"
moveRight; if (!entered) { giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; } else entered = false; return '{';
#line 634 "mylexer.cpp"
		}
		break;
	case 70:
		{
#line 121 ".\\mylexer.l"
moveRight; return '}';
#line 641 "mylexer.cpp"
		}
		break;
	case 71:
		{
#line 122 ".\\mylexer.l"
moveRight; return '(';
#line 648 "mylexer.cpp"
		}
		break;
	case 72:
		{
#line 123 ".\\mylexer.l"
moveRight; return ')';
#line 655 "mylexer.cpp"
		}
		break;
	case 73:
		{
#line 124 ".\\mylexer.l"
moveRight; return '[';
#line 662 "mylexer.cpp"
		}
		break;
	case 74:
		{
#line 125 ".\\mylexer.l"
moveRight; return ']';
#line 669 "mylexer.cpp"
		}
		break;
	case 75:
		{
#line 126 ".\\mylexer.l"
moveRight; return '=';
#line 676 "mylexer.cpp"
		}
		break;
	case 76:
		{
#line 127 ".\\mylexer.l"
moveRight; return ';';
#line 683 "mylexer.cpp"
		}
		break;
	case 77:
		{
#line 128 ".\\mylexer.l"
moveRight; yylval = new Node(ival_t, atoi(yytext)); return INTVAL;
#line 690 "mylexer.cpp"
		}
		break;
	case 78:
		{
#line 129 ".\\mylexer.l"
moveRight; yylval = new Node(dval_t, atof(yytext)); return DOUBLEVAL;
#line 697 "mylexer.cpp"
		}
		break;
	case 79:
		{
#line 130 ".\\mylexer.l"
moveRight; yylval = new Node(bval_t, (strcmp(yytext, "true") == 0)); return BOOLVAL;
#line 704 "mylexer.cpp"
		}
		break;
	case 80:
		{
#line 131 ".\\mylexer.l"
moveRight; yylval = new Node(sval_t, yytext); return CHARVAL;
#line 711 "mylexer.cpp"
		}
		break;
	case 81:
		{
#line 132 ".\\mylexer.l"
moveRight; yylval = new Node(sval_t, yytext); return STRINGVAL;
#line 718 "mylexer.cpp"
		}
		break;
	case 82:
		{
#line 133 ".\\mylexer.l"
moveRight; yylval = new Node(idt_t, yytext); return ID;
#line 725 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 346;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 95, 44 },
		{ 48, 98 },
		{ 51, 9 },
		{ 58, 16 },
		{ 74, 31 },
		{ 61, 17 },
		{ 77, 32 },
		{ 85, 36 },
		{ 91, 39 },
		{ 72, 30 },
		{ 62, 17 },
		{ 75, 31 },
		{ 73, 30 },
		{ 68, 23 },
		{ 69, 23 },
		{ 86, 36 },
		{ 78, 32 },
		{ 56, 14 },
		{ 76, 31 },
		{ 59, 16 },
		{ 60, 16 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 63, 17 },
		{ 52, 9 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 57, 14 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 79, 33 },
		{ 127, 93 },
		{ 80, 33 },
		{ 53, 131 },
		{ 128, 93 },
		{ 148, 123 },
		{ 49, 98 },
		{ 81, 34 },
		{ 88, 38 },
		{ 92, 40 },
		{ 96, 44 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 149, 123 },
		{ 82, 34 },
		{ 89, 38 },
		{ 93, 41 },
		{ 83, 34 },
		{ 90, 38 },
		{ 138, 111 },
		{ 139, 111 },
		{ 65, 21 },
		{ 66, 21 },
		{ 26, 1 },
		{ 94, 42 },
		{ 27, 1 },
		{ 28, 1 },
		{ 54, 10 },
		{ 97, 46 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 98, 49 },
		{ 36, 1 },
		{ 99, 53 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 53, 131 },
		{ 70, 28 },
		{ 37, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 40, 1 },
		{ 41, 1 },
		{ 42, 1 },
		{ 102, 61 },
		{ 0, 62 },
		{ 53, 54 },
		{ 43, 1 },
		{ 44, 1 },
		{ 45, 1 },
		{ 46, 1 },
		{ 53, 54 },
		{ 104, 65 },
		{ 105, 69 },
		{ 106, 71 },
		{ 107, 72 },
		{ 108, 73 },
		{ 109, 74 },
		{ 110, 75 },
		{ 111, 76 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 100, 54 },
		{ 64, 18 },
		{ 112, 77 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 103, 103 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 53, 130 },
		{ 101, 54 },
		{ 113, 78 },
		{ 114, 79 },
		{ 115, 80 },
		{ 53, 54 },
		{ 116, 81 },
		{ 117, 82 },
		{ 118, 83 },
		{ 119, 84 },
		{ 53, 54 },
		{ 53, 54 },
		{ 120, 86 },
		{ 121, 87 },
		{ 122, 88 },
		{ 53, 54 },
		{ 123, 89 },
		{ 124, 90 },
		{ 125, 91 },
		{ 126, 92 },
		{ 71, 29 },
		{ 129, 94 },
		{ 55, 13 },
		{ 53, 54 },
		{ 4, 4 },
		{ 5, 5 },
		{ 132, 102 },
		{ 53, 54 },
		{ 47, 6 },
		{ 53, 54 },
		{ 133, 106 },
		{ 53, 54 },
		{ 134, 107 },
		{ 101, 54 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 135, 108 },
		{ 136, 109 },
		{ 137, 110 },
		{ 50, 8 },
		{ 140, 112 },
		{ 141, 113 },
		{ 142, 114 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 143, 115 },
		{ 125, 116 },
		{ 144, 117 },
		{ 145, 119 },
		{ 25, 183 },
		{ 146, 121 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 25, 183 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 147, 122 },
		{ 84, 35 },
		{ 150, 124 },
		{ 151, 125 },
		{ 152, 126 },
		{ 153, 127 },
		{ 154, 128 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 130, 100 },
		{ 155, 129 },
		{ 3, 3 },
		{ 87, 37 },
		{ 156, 135 },
		{ 157, 138 },
		{ 158, 139 },
		{ 159, 140 },
		{ 160, 141 },
		{ 161, 144 },
		{ 162, 146 },
		{ 163, 147 },
		{ 164, 148 },
		{ 165, 149 },
		{ 166, 150 },
		{ 167, 152 },
		{ 168, 154 },
		{ 169, 155 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 131, 101 },
		{ 170, 158 },
		{ 171, 159 },
		{ 172, 160 },
		{ 173, 162 },
		{ 174, 163 },
		{ 175, 164 },
		{ 176, 165 },
		{ 177, 166 },
		{ 178, 168 },
		{ 179, 170 },
		{ 180, 171 },
		{ 181, 178 },
		{ 182, 179 },
		{ 183, 181 },
		{ 67, 22 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 183, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 300, 2 },
		{ 0, 181, 3 },
		{ 0, 160, 1 },
		{ 0, 134, 67 },
		{ 98, 0, 0 },
		{ 0, 153, 66 },
		{ 0, -33, 50 },
		{ -53, -5, 0 },
		{ 0, 0, 71 },
		{ 0, 0, 72 },
		{ 0, 128, 64 },
		{ 0, -23, 62 },
		{ 0, 0, 32 },
		{ 0, -39, 63 },
		{ 0, -34, 65 },
		{ 0, 91, 77 },
		{ 0, 0, 33 },
		{ 0, 0, 76 },
		{ 0, 21, 57 },
		{ 0, 284, 75 },
		{ 0, -45, 58 },
		{ 0, 0, 34 },
		{ 183, 0, 82 },
		{ 0, 0, 73 },
		{ 0, 0, 74 },
		{ 0, 44, 49 },
		{ 183, 70, 82 },
		{ 183, -99, 82 },
		{ 183, -90, 82 },
		{ 183, -92, 82 },
		{ 183, -52, 82 },
		{ 183, -34, 82 },
		{ 183, 176, 82 },
		{ 183, -92, 82 },
		{ 183, 209, 82 },
		{ 183, -41, 82 },
		{ 183, -103, 82 },
		{ 183, -45, 82 },
		{ 183, -35, 82 },
		{ 183, -20, 82 },
		{ 0, 0, 69 },
		{ 0, -58, 48 },
		{ 0, 0, 70 },
		{ 0, 27, 68 },
		{ 0, 0, 52 },
		{ 0, 0, 81 },
		{ 98, 62, 0 },
		{ 0, 0, 39 },
		{ 0, 0, 47 },
		{ 0, 0, 40 },
		{ 0, 59, 0 },
		{ 0, 80, 0 },
		{ 0, 0, 37 },
		{ 0, 0, 59 },
		{ 0, 0, 35 },
		{ 0, 0, 60 },
		{ 0, 0, 36 },
		{ 0, 0, 61 },
		{ -61, 70, 0 },
		{ -62, 103, 4 },
		{ 0, 0, 38 },
		{ 103, 0, 0 },
		{ 0, 59, 55 },
		{ 0, 0, 53 },
		{ 0, 0, 51 },
		{ 0, 0, 54 },
		{ 0, 60, 56 },
		{ 0, 0, 42 },
		{ 183, 6, 82 },
		{ 183, 12, 82 },
		{ 183, 23, 82 },
		{ 183, 10, 82 },
		{ 183, 29, 82 },
		{ 183, 17, 82 },
		{ 183, 36, 82 },
		{ 183, 52, 25 },
		{ 183, 55, 82 },
		{ 183, 54, 82 },
		{ 183, 65, 82 },
		{ 183, 63, 82 },
		{ 183, 61, 82 },
		{ 183, 60, 82 },
		{ 183, 0, 27 },
		{ 183, 63, 82 },
		{ 183, 64, 82 },
		{ 183, 59, 82 },
		{ 183, 69, 82 },
		{ 183, 79, 82 },
		{ 183, 68, 82 },
		{ 183, 81, 82 },
		{ 183, -48, 82 },
		{ 183, 83, 82 },
		{ 0, 0, 41 },
		{ 0, 0, 46 },
		{ 0, 0, 43 },
		{ -7, -30, 81 },
		{ 0, 0, 80 },
		{ 130, 251, 0 },
		{ 0, 228, 0 },
		{ -61, 146, 0 },
		{ 0, 101, 78 },
		{ 0, 0, 44 },
		{ 0, 0, 45 },
		{ 183, 86, 82 },
		{ 183, 91, 82 },
		{ 183, 114, 82 },
		{ 183, 111, 82 },
		{ 183, 99, 82 },
		{ 183, -36, 82 },
		{ 183, 118, 82 },
		{ 183, 118, 82 },
		{ 183, 116, 82 },
		{ 183, 135, 82 },
		{ 183, 130, 82 },
		{ 183, 149, 82 },
		{ 183, 0, 26 },
		{ 183, 136, 82 },
		{ 183, 0, 7 },
		{ 183, 132, 82 },
		{ 183, 185, 82 },
		{ 183, -44, 82 },
		{ 183, 172, 82 },
		{ 183, 188, 82 },
		{ 183, 179, 82 },
		{ 183, 191, 82 },
		{ 183, 195, 82 },
		{ 183, 200, 82 },
		{ 53, 111, 0 },
		{ 130, 2, 0 },
		{ 0, 0, 5 },
		{ 183, 0, 13 },
		{ 183, 0, 11 },
		{ 183, 204, 82 },
		{ 183, 0, 30 },
		{ 183, 0, 10 },
		{ 183, 196, 82 },
		{ 183, 208, 82 },
		{ 183, 197, 82 },
		{ 183, 207, 82 },
		{ 183, 0, 28 },
		{ 183, 0, 16 },
		{ 183, 200, 82 },
		{ 183, 0, 20 },
		{ 183, 203, 82 },
		{ 183, 207, 82 },
		{ 183, 209, 82 },
		{ 183, 221, 82 },
		{ 183, 222, 82 },
		{ 183, 0, 79 },
		{ 183, 212, 82 },
		{ 183, 0, 6 },
		{ 183, 207, 82 },
		{ 183, 223, 82 },
		{ 183, 0, 21 },
		{ 183, 0, 17 },
		{ 183, 221, 82 },
		{ 183, 224, 82 },
		{ 183, 232, 82 },
		{ 183, 0, 8 },
		{ 183, 224, 82 },
		{ 183, 233, 82 },
		{ 183, 233, 82 },
		{ 183, 221, 82 },
		{ 183, 234, 82 },
		{ 183, 0, 15 },
		{ 183, 234, 82 },
		{ 183, 0, 24 },
		{ 183, 223, 82 },
		{ 183, 225, 82 },
		{ 183, 0, 9 },
		{ 183, 0, 23 },
		{ 183, 0, 19 },
		{ 183, 0, 12 },
		{ 183, 0, 14 },
		{ 183, 0, 29 },
		{ 183, 234, 82 },
		{ 183, 242, 82 },
		{ 183, 0, 31 },
		{ 183, 243, 82 },
		{ 183, 0, 22 },
		{ 0, 153, 18 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 136 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section
