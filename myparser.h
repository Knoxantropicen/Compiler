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
* Date: 01/05/18
* Time: 21:35:05
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
#line 59 ".\\myparser.y"

	void yyerror(const char YYFAR* text);

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 74 ".\\myparser.y"

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
#define INPUT 265
#define PRINT 266
#define ADDASSIGN 267
#define SUBASSIGN 268
#define MULASSIGN 269
#define DIVASSIGN 270
#define MODASSIGN 271
#define ANDASSIGN 272
#define ORASSIGN 273
#define XORASSIGN 274
#define REVASSIGN 275
#define LSHIFTASSIGN 276
#define RSHIFTASSIGN 277
#define OR 278
#define AND 279
#define EQ 280
#define NE 281
#define LE 282
#define GE 283
#define LT 284
#define GT 285
#define INC 286
#define DEC 287
#define LSHIFT 288
#define RSHIFT 289
#define INTVAL 290
#define CHARVAL 291
#define ID 292
#endif
