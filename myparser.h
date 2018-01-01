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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 12/06/17
* Time: 20:36:14
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
#line 127 ".\\myparser.y"

	void yyerror(const char YYFAR* text);

#line 69 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#line 142 ".\\myparser.y"

#ifndef YYSTYPE
#define YYSTYPE Node *
#endif

#line 82 "myparser.h"
#define VOID 257
#define INT 258
#define FLOAT 259
#define DOUBLE 260
#define CHAR 261
#define BOOL 262
#define STRING 263
#define AUTO 264
#define STRUCT 265
#define UNION 266
#define ENUM 267
#define CONST 268
#define VOLATILE 269
#define SIZEOF 270
#define GOTO 271
#define BREAK 272
#define CONTINUE 273
#define RETURN 274
#define WHILE 275
#define DO 276
#define FOR 277
#define IF 278
#define SWITCH 279
#define CASE 280
#define DEFAULT 281
#define NO_ELSE 282
#define ELSE 283
#define ADDASSIGN 284
#define SUBASSIGN 285
#define MULASSIGN 286
#define DIVASSIGN 287
#define MODASSIGN 288
#define ANDASSIGN 289
#define ORASSIGN 290
#define XORASSIGN 291
#define REVASSIGN 292
#define LSHIFTASSIGN 293
#define RSHIFTASSIGN 294
#define OR 295
#define AND 296
#define EQ 297
#define NE 298
#define LE 299
#define GE 300
#define LT 301
#define GT 302
#define INC 303
#define DEC 304
#define PT 305
#define LSHIFT 306
#define RSHIFT 307
#define INTVAL 308
#define DOUBLEVAL 309
#define BOOLVAL 310
#define CHARVAL 311
#define STRINGVAL 312
#define ID 313
#endif
