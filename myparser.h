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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 01/03/18
* Time: 11:32:54
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 57 ".\\myparser.y"

	void yyerror(const char YYFAR* text);

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 72 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE Node *
#endif

#line 82 "myparser.h"
#define INT 257
#define CHAR 258
#define WHILE 259
#define FOR 260
#define IF 261
#define NO_ELSE 262
#define ELSE 263
#define MAIN 264
#define ADDASSIGN 265
#define SUBASSIGN 266
#define MULASSIGN 267
#define DIVASSIGN 268
#define MODASSIGN 269
#define ANDASSIGN 270
#define ORASSIGN 271
#define XORASSIGN 272
#define REVASSIGN 273
#define LSHIFTASSIGN 274
#define RSHIFTASSIGN 275
#define OR 276
#define AND 277
#define EQ 278
#define NE 279
#define LE 280
#define GE 281
#define LT 282
#define GT 283
#define INC 284
#define DEC 285
#define LSHIFT 286
#define RSHIFT 287
#define INTVAL 288
#define CHARVAL 289
#define ID 290
#endif
