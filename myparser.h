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
* Date: 01/01/18
* Time: 22:52:19
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
#line 78 ".\\myparser.y"

	void yyerror(const char YYFAR* text);

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 93 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE Node *
#endif

#line 82 "myparser.h"
#define VOID 257
#define INT 258
#define CHAR 259
#define RETURN 260
#define WHILE 261
#define DO 262
#define FOR 263
#define IF 264
#define NO_ELSE 265
#define ELSE 266
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
