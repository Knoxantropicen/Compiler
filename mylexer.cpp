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
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 01/05/18
* Time: 21:35:05
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
#line 40 ".\\mylexer.l"

    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 151 "mylexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 49 ".\\mylexer.l"
moveRight;
#line 158 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 50 ".\\mylexer.l"
moveTab;
#line 165 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 51 ".\\mylexer.l"
moveDown;
#line 172 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 52 ".\\mylexer.l"
moveRight;
#line 179 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 53 ".\\mylexer.l"
moveComment;
#line 186 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 54 ".\\mylexer.l"
moveRight; return INT;
#line 193 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 55 ".\\mylexer.l"
moveRight; return CHAR;
#line 200 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 56 ".\\mylexer.l"
moveRight; return WHILE;
#line 207 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 57 ".\\mylexer.l"
moveRight; return FOR;
#line 214 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 58 ".\\mylexer.l"
moveRight; return IF;
#line 221 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 59 ".\\mylexer.l"
moveRight; return ELSE;
#line 228 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 60 ".\\mylexer.l"
moveRight; return MAIN;
#line 235 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 61 ".\\mylexer.l"
moveRight; return INPUT;
#line 242 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 62 ".\\mylexer.l"
moveRight; return PRINT;
#line 249 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 63 ".\\mylexer.l"
moveRight; return ',';
#line 256 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 64 ".\\mylexer.l"
moveRight; return ':';
#line 263 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 65 ".\\mylexer.l"
moveRight; return '?';
#line 270 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 66 ".\\mylexer.l"
moveRight; return ADDASSIGN;
#line 277 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 67 ".\\mylexer.l"
moveRight; return SUBASSIGN;
#line 284 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 68 ".\\mylexer.l"
moveRight; return MULASSIGN;
#line 291 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 69 ".\\mylexer.l"
moveRight; return DIVASSIGN;
#line 298 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 70 ".\\mylexer.l"
moveRight; return MODASSIGN;
#line 305 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 71 ".\\mylexer.l"
moveRight; return ANDASSIGN;
#line 312 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 72 ".\\mylexer.l"
moveRight; return ORASSIGN;
#line 319 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 73 ".\\mylexer.l"
moveRight; return XORASSIGN;
#line 326 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 74 ".\\mylexer.l"
moveRight; return REVASSIGN;
#line 333 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 75 ".\\mylexer.l"
moveRight; return LSHIFTASSIGN;
#line 340 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 76 ".\\mylexer.l"
moveRight; return RSHIFTASSIGN;
#line 347 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 77 ".\\mylexer.l"
moveRight; return OR;
#line 354 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 78 ".\\mylexer.l"
moveRight; return AND;
#line 361 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 79 ".\\mylexer.l"
moveRight; return '|';
#line 368 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 80 ".\\mylexer.l"
moveRight; return '^';
#line 375 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 81 ".\\mylexer.l"
moveRight; return '&';
#line 382 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 82 ".\\mylexer.l"
moveRight; return EQ;
#line 389 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 83 ".\\mylexer.l"
moveRight; return NE;
#line 396 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 84 ".\\mylexer.l"
moveRight; return LE;
#line 403 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 85 ".\\mylexer.l"
moveRight; return GE;
#line 410 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 86 ".\\mylexer.l"
moveRight; return LSHIFT;
#line 417 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 87 ".\\mylexer.l"
moveRight; return RSHIFT;
#line 424 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 88 ".\\mylexer.l"
moveRight; return LT;
#line 431 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 89 ".\\mylexer.l"
moveRight; return GT;
#line 438 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 90 ".\\mylexer.l"
moveRight; return INC;
#line 445 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 91 ".\\mylexer.l"
moveRight; return DEC;
#line 452 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 92 ".\\mylexer.l"
moveRight; return '+';
#line 459 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 93 ".\\mylexer.l"
moveRight; return '-';
#line 466 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 94 ".\\mylexer.l"
moveRight; return '*';
#line 473 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 95 ".\\mylexer.l"
moveRight; return '/';
#line 480 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 96 ".\\mylexer.l"
moveRight; return '%';
#line 487 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 97 ".\\mylexer.l"
moveRight; return '!';
#line 494 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 98 ".\\mylexer.l"
moveRight; return '~';
#line 501 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 99 ".\\mylexer.l"
moveRight; if (!entered) { SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; } else entered = false; return '{';
#line 508 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 100 ".\\mylexer.l"
moveRight; return '}';
#line 515 "mylexer.cpp"
		}
		break;
	case 53:
		{
#line 101 ".\\mylexer.l"
moveRight; return '(';
#line 522 "mylexer.cpp"
		}
		break;
	case 54:
		{
#line 102 ".\\mylexer.l"
moveRight; return ')';
#line 529 "mylexer.cpp"
		}
		break;
	case 55:
		{
#line 103 ".\\mylexer.l"
moveRight; return '[';
#line 536 "mylexer.cpp"
		}
		break;
	case 56:
		{
#line 104 ".\\mylexer.l"
moveRight; return ']';
#line 543 "mylexer.cpp"
		}
		break;
	case 57:
		{
#line 105 ".\\mylexer.l"
moveRight; return '=';
#line 550 "mylexer.cpp"
		}
		break;
	case 58:
		{
#line 106 ".\\mylexer.l"
moveRight; return ';';
#line 557 "mylexer.cpp"
		}
		break;
	case 59:
		{
#line 107 ".\\mylexer.l"
moveRight; yylval = new Node(ival_t, atoi(yytext)); return INTVAL;
#line 564 "mylexer.cpp"
		}
		break;
	case 60:
		{
#line 108 ".\\mylexer.l"
moveRight; yylval = new Node(cval_t, yytext); return CHARVAL;
#line 571 "mylexer.cpp"
		}
		break;
	case 61:
		{
#line 109 ".\\mylexer.l"
moveRight; yylval = new Node(idt_t, yytext); return ID;
#line 578 "mylexer.cpp"
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

	yytransitionmax = 279;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 4, 1 },
		{ 67, 36 },
		{ 41, 8 },
		{ 46, 13 },
		{ 48, 15 },
		{ 50, 16 },
		{ 56, 22 },
		{ 57, 22 },
		{ 53, 20 },
		{ 54, 20 },
		{ 51, 16 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 43, 84 },
		{ 49, 15 },
		{ 47, 13 },
		{ 5, 1 },
		{ 6, 1 },
		{ 52, 16 },
		{ 42, 8 },
		{ 59, 28 },
		{ 7, 1 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 60, 29 },
		{ 16, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 23, 1 },
		{ 43, 44 },
		{ 62, 31 },
		{ 79, 63 },
		{ 61, 30 },
		{ 45, 12 },
		{ 43, 44 },
		{ 80, 63 },
		{ 64, 32 },
		{ 65, 33 },
		{ 63, 31 },
		{ 68, 36 },
		{ 66, 34 },
		{ 4, 4 },
		{ 69, 38 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 71, 44 },
		{ 70, 43 },
		{ 5, 5 },
		{ 73, 50 },
		{ 0, 51 },
		{ 25, 1 },
		{ 74, 53 },
		{ 26, 1 },
		{ 27, 1 },
		{ 75, 57 },
		{ 76, 59 },
		{ 77, 60 },
		{ 78, 61 },
		{ 28, 1 },
		{ 39, 6 },
		{ 29, 1 },
		{ 30, 1 },
		{ 81, 64 },
		{ 82, 65 },
		{ 31, 1 },
		{ 83, 66 },
		{ 40, 7 },
		{ 3, 3 },
		{ 32, 1 },
		{ 86, 73 },
		{ 87, 76 },
		{ 33, 1 },
		{ 88, 77 },
		{ 89, 79 },
		{ 90, 81 },
		{ 91, 82 },
		{ 92, 83 },
		{ 72, 44 },
		{ 34, 1 },
		{ 55, 21 },
		{ 44, 9 },
		{ 43, 44 },
		{ 35, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 43, 44 },
		{ 43, 44 },
		{ 93, 89 },
		{ 94, 91 },
		{ 95, 92 },
		{ 43, 44 },
		{ 58, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 43, 44 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 43, 44 },
		{ 0, 0 },
		{ 43, 44 },
		{ 0, 0 },
		{ 43, 44 },
		{ 0, 0 },
		{ 72, 44 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 24, 95 },
		{ 0, 0 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 24, 95 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 43, 85 },
		{ 0, 0 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 17, 17 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 84, 71 },
		{ 0, 0 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 85, 72 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 },
		{ 43, 85 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 95, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 91, 2 },
		{ 0, 58, 3 },
		{ 0, 48, 1 },
		{ 0, 31, 49 },
		{ 0, 38, 48 },
		{ 0, -34, 33 },
		{ -43, 21, 0 },
		{ 0, 0, 53 },
		{ 0, 0, 54 },
		{ 0, -1, 46 },
		{ 0, -38, 44 },
		{ 0, 0, 15 },
		{ 0, -39, 45 },
		{ 0, -35, 47 },
		{ 0, 199, 59 },
		{ 0, 0, 16 },
		{ 0, 0, 58 },
		{ 0, -50, 40 },
		{ 0, 51, 57 },
		{ 0, -53, 41 },
		{ 0, 0, 17 },
		{ 95, 0, 61 },
		{ 0, 0, 55 },
		{ 0, 0, 56 },
		{ 0, 64, 32 },
		{ 95, -76, 61 },
		{ 95, -70, 61 },
		{ 95, -52, 61 },
		{ 95, -45, 61 },
		{ 95, -34, 61 },
		{ 95, -50, 61 },
		{ 95, -37, 61 },
		{ 0, 0, 51 },
		{ 0, -58, 31 },
		{ 0, 0, 52 },
		{ 0, 8, 50 },
		{ 0, 0, 35 },
		{ 0, 0, 22 },
		{ 0, 0, 30 },
		{ 0, 0, 23 },
		{ 0, 40, 0 },
		{ 0, 22, 0 },
		{ 0, 0, 20 },
		{ 0, 0, 42 },
		{ 0, 0, 18 },
		{ 0, 0, 43 },
		{ 0, 0, 19 },
		{ -50, 39, 0 },
		{ -51, 72, 4 },
		{ 0, 0, 21 },
		{ 0, 23, 38 },
		{ 0, 0, 36 },
		{ 0, 0, 34 },
		{ 0, 0, 37 },
		{ 0, 26, 39 },
		{ 0, 0, 25 },
		{ 95, -9, 61 },
		{ 95, -26, 61 },
		{ 95, -24, 61 },
		{ 95, 0, 10 },
		{ 95, -54, 61 },
		{ 95, -10, 61 },
		{ 95, -9, 61 },
		{ 95, -7, 61 },
		{ 0, 0, 24 },
		{ 0, 0, 29 },
		{ 0, 0, 26 },
		{ 0, 0, 60 },
		{ 84, 209, 0 },
		{ 0, 170, 0 },
		{ -50, 55, 0 },
		{ 0, 0, 27 },
		{ 0, 0, 28 },
		{ 95, -11, 61 },
		{ 95, 4, 61 },
		{ 95, 0, 9 },
		{ 95, -11, 61 },
		{ 95, 0, 6 },
		{ 95, -3, 61 },
		{ 95, -2, 61 },
		{ 95, 1, 61 },
		{ 43, -35, 0 },
		{ 84, 176, 0 },
		{ 0, 0, 5 },
		{ 95, 0, 7 },
		{ 95, 0, 11 },
		{ 95, 5, 61 },
		{ 95, 0, 12 },
		{ 95, 6, 61 },
		{ 95, 22, 61 },
		{ 95, 0, 13 },
		{ 95, 0, 14 },
		{ 0, 95, 8 }
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
		0
	};
	yybackup = backup;
}
#line 111 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section
