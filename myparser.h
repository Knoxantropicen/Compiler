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
* Date: 01/02/18
* Time: 20:08:30
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
#define DO 260
#define FOR 261
#define IF 262
#define NO_ELSE 263
#define ELSE 264
#define MAIN 265
#define ADDASSIGN 266
#define SUBASSIGN 267
#define MULASSIGN 268
#define DIVASSIGN 269
#define MODASSIGN 270
#define ANDASSIGN 271
#define ORASSIGN 272
#define XORASSIGN 273
#define REVASSIGN 274
#define LSHIFTASSIGN 275
#define RSHIFTASSIGN 276
#define OR 277
#define AND 278
#define EQ 279
#define NE 280
#define LE 281
#define GE 282
#define LT 283
#define GT 284
#define INC 285
#define DEC 286
#define LSHIFT 287
#define RSHIFT 288
#define INTVAL 289
#define CHARVAL 290
#define ID 291
#endif
