%{
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
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name mylexer

ws 			[ ]+
tab			\t+
nl			\n+
sincomment	\/\/.*
mulcomment	\/\*([^\*]*(\*[^\/])?)*\*\/
digit 		[0-9]
intval	 	{digit}+
doubleval	{digit}+(\.{digit}+)?
letter 		[a-zA-Z]
octdigit	[0-8]
hexdigit	[0-9a-fA-F]
charval	 	'([^\\]|\\([abfnrtv\\\'\"0]|{octdigit}{1,3}|(x|X){hexdigit}{1,2}))'
stringval	 \"([^\"]|\\\")*\"
boolval		(true|false)
id 			({letter}|_)+({letter}|{digit}|_)*


%%

%{
    YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here

{ws}			{moveRight;}
{tab}			{moveTab;}
{nl}			{moveDown;}
{sincomment}	{moveRight;}
{mulcomment}	{moveComment;}
"void"			{moveRight; return VOID;}
"int"			{moveRight; return INT;}
"float"			{moveRight; return FLOAT;}
"double"		{moveRight; return DOUBLE;}
"char"			{moveRight; return CHAR;}
"bool"			{moveRight; return BOOL;}
"string"		{moveRight; return STRING;}
"auto"			{moveRight; return AUTO;}
"struct"		{moveRight; return STRUCT;}
"union"			{moveRight; return UNION;}
"enum"			{moveRight; return ENUM;}
"const"			{moveRight; return CONST;}
"volatile"		{moveRight; return VOLATILE;}
"sizeof"		{moveRight; return SIZEOF;}
"goto"			{moveRight; return GOTO;}
"break"			{moveRight; return BREAK;}
"continue"		{moveRight; return CONTINUE;}
"return"		{moveRight; return RETURN;}
"while"			{moveRight; return WHILE;}
"do"			{moveRight; return DO;}
"for"			{moveRight; return FOR;}
"if"			{moveRight; return IF;}
"else"			{moveRight; return ELSE;}
"switch"		{moveRight; return SWITCH;}
"case"			{moveRight; return CASE;}
"default"		{moveRight; return DEFAULT;}
","				{moveRight; return ',';}
":"				{moveRight; return ':';}
"?"				{moveRight; return '?';}
"+=" 			{moveRight; return ADDASSIGN;}
"-="			{moveRight; return SUBASSIGN;}
"*="			{moveRight; return MULASSIGN;}
"/="			{moveRight; return DIVASSIGN;}
"%="			{moveRight; return MODASSIGN;}
"&="			{moveRight; return ANDASSIGN;}
"|="			{moveRight; return ORASSIGN;}
"^="			{moveRight; return XORASSIGN;}
"~="			{moveRight; return REVASSIGN;}
"<<="			{moveRight; return LSHIFTASSIGN;}
">>="			{moveRight; return RSHIFTASSIGN;}
"||"			{moveRight; return OR;}
"&&"			{moveRight; return AND;}
"|"				{moveRight; return '|';}
"^"				{moveRight; return '^';}
"&"				{moveRight; return '&';}
"=="			{moveRight; return EQ;}
"!="			{moveRight; return NE;}
"<="			{moveRight; return LE;}
">="			{moveRight; return GE;}
"<<"			{moveRight; return LSHIFT;}
">>"			{moveRight; return RSHIFT;}
"<"				{moveRight; return LT;}
">"				{moveRight; return GT;}
"++"			{moveRight; return INC;}
"--"			{moveRight; return DEC;}
"->"			{moveRight; return PT;}
"+"				{moveRight; return '+';}
"-"				{moveRight; return '-';}
"*"				{moveRight; return '*';}
"/"				{moveRight; return '/';}
"%"				{moveRight; return '%';}
"!"				{moveRight; return '!';}
"~"				{moveRight; return '~';}
"{"				{moveRight; if (!entered) { giv_stack.push(giv); giv = GIV(); SymbolTable * sub_table = new SymbolTable(); sub_table->setFather(curr_table); curr_table = sub_table; } else entered = false; return '{';}
"}"				{moveRight; return '}';}
"("				{moveRight; return '(';}
")"				{moveRight; return ')';}
"["				{moveRight; return '[';}
"]"				{moveRight; return ']';}
"="				{moveRight; return '=';}
";"				{moveRight; return ';';}
{intval}		{moveRight; yylval = new Node(ival_t, atoi(yytext)); return INTVAL;}
{doubleval}		{moveRight; yylval = new Node(dval_t, atof(yytext)); return DOUBLEVAL;}
{boolval}		{moveRight; yylval = new Node(bval_t, (strcmp(yytext, "true") == 0)); return BOOLVAL;}
{charval}		{moveRight; yylval = new Node(sval_t, yytext); return CHARVAL;}
{stringval} 	{moveRight; yylval = new Node(sval_t, yytext); return STRINGVAL;}
{id}			{moveRight; yylval = new Node(idt_t, yytext); return ID;}


%%

/////////////////////////////////////////////////////////////////////////////
// programs section