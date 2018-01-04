#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 1 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 01/04/18
# Time: 19:42:15
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : decl_list func
    2          | func

    3  type : INT
    4       | CHAR

    5  decl_list : decl_list decl
    6            | decl

    7  decl : type id_list ';'
    8       | type ';'

    9  id_list : id_list ',' ID
   10          | ID

   11  func : INT MAIN '(' ')' compound_stmt
   12       | MAIN '(' ')' compound_stmt

   13  expr : expr ',' assign_expr
   14       | assign_expr

   15  assign_expr : ID assign_op assign_expr
   16              | const_expr

   17  const_expr : ternary_expr

   18  ternary_expr : or_expr '?' ternary_expr ':' ternary_expr
   19               | or_expr

   20  or_expr : or_expr OR and_expr
   21          | and_expr

   22  and_expr : and_expr AND bit_or_expr
   23           | bit_or_expr

   24  bit_or_expr : bit_or_expr '|' bit_xor_expr
   25              | bit_xor_expr

   26  bit_xor_expr : bit_xor_expr '^' bit_and_expr
   27               | bit_and_expr

   28  bit_and_expr : bit_and_expr '&' equal_expr
   29               | equal_expr

   30  equal_expr : equal_expr EQ greater_less_expr
   31             | equal_expr NE greater_less_expr
   32             | greater_less_expr

   33  greater_less_expr : greater_less_expr LE shift_expr
   34                    | greater_less_expr GE shift_expr
   35                    | greater_less_expr LT shift_expr
   36                    | greater_less_expr GT shift_expr
   37                    | shift_expr

   38  shift_expr : shift_expr LSHIFT add_sub_expr
   39             | shift_expr RSHIFT add_sub_expr
   40             | add_sub_expr

   41  add_sub_expr : add_sub_expr '+' mul_div_mod_expr
   42               | add_sub_expr '-' mul_div_mod_expr
   43               | mul_div_mod_expr

   44  mul_div_mod_expr : mul_div_mod_expr '*' unary_expr
   45                   | mul_div_mod_expr '/' unary_expr
   46                   | mul_div_mod_expr '%' unary_expr
   47                   | unary_expr

   48  unary_expr : unary_op unary_expr
   49             | postfix_expr

   50  postfix_expr : postfix_expr INC
   51               | postfix_expr DEC
   52               | basic_expr

   53  basic_expr : ID
   54             | val
   55             | '(' expr ')'

   56  assign_op : '='
   57            | ADDASSIGN
   58            | SUBASSIGN
   59            | MULASSIGN
   60            | DIVASSIGN
   61            | MODASSIGN
   62            | ANDASSIGN
   63            | ORASSIGN
   64            | XORASSIGN
   65            | REVASSIGN
   66            | LSHIFTASSIGN
   67            | RSHIFTASSIGN

   68  unary_op : '+'
   69           | '-'
   70           | '~'
   71           | '!'
   72           | INC
   73           | DEC

   74  val : INTVAL
   75      | CHARVAL

   76  stmt : loop_stmt
   77       | expr_stmt
   78       | compound_stmt
   79       | conditional_stmt

   80  loop_stmt : WHILE '(' expr ')' stmt
   81            | FOR '(' expr_stmt expr_stmt expr ')' stmt
   82            | FOR '(' expr_stmt expr_stmt ')' stmt

   83  expr_stmt : expr ';'
   84            | ';'

   85  compound_stmt : '{' decl_list stmt_list '}'
   86                | '{' decl_list '}'
   87                | '{' stmt_list '}'
   88                | '{' '}'

   89  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
   90                   | IF '(' expr ')' stmt

   91  stmt_list : stmt_list stmt
   92            | stmt


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	func  goto 4
	decl  goto 5
	program  goto 6
	decl_list  goto 7
	type  goto 8


state 1
	type : INT .  (3)
	func : INT . MAIN '(' ')' compound_stmt

	MAIN  shift 9
	.  reduce 3


state 2
	type : CHAR .  (4)

	.  reduce 4


state 3
	func : MAIN . '(' ')' compound_stmt

	'('  shift 10


state 4
	program : func .  (2)

	.  reduce 2


state 5
	decl_list : decl .  (6)

	.  reduce 6


state 6
	$accept : program . $end  (0)

	$end  accept


state 7
	program : decl_list . func
	decl_list : decl_list . decl

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	func  goto 11
	decl  goto 12
	type  goto 8


state 8
	decl : type . id_list ';'
	decl : type . ';'

	';'  shift 13
	ID  shift 14

	id_list  goto 15


state 9
	func : INT MAIN . '(' ')' compound_stmt

	'('  shift 16


state 10
	func : MAIN '(' . ')' compound_stmt

	')'  shift 17


state 11
	program : decl_list func .  (1)

	.  reduce 1


state 12
	decl_list : decl_list decl .  (5)

	.  reduce 5


state 13
	decl : type ';' .  (8)

	.  reduce 8


state 14
	id_list : ID .  (10)

	.  reduce 10


state 15
	decl : type id_list . ';'
	id_list : id_list . ',' ID

	','  shift 18
	';'  shift 19


state 16
	func : INT MAIN '(' . ')' compound_stmt

	')'  shift 20


state 17
	func : MAIN '(' ')' . compound_stmt

	'{'  shift 21

	compound_stmt  goto 22


state 18
	id_list : id_list ',' . ID

	ID  shift 23


state 19
	decl : type id_list ';' .  (7)

	.  reduce 7


state 20
	func : INT MAIN '(' ')' . compound_stmt

	'{'  shift 21

	compound_stmt  goto 24


state 21
	compound_stmt : '{' . decl_list stmt_list '}'
	compound_stmt : '{' . '}'
	compound_stmt : '{' . stmt_list '}'
	compound_stmt : '{' . decl_list '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 30
	'~'  shift 31
	INT  shift 32
	CHAR  shift 2
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	decl  goto 5
	decl_list  goto 41
	type  goto 8
	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 50
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65
	stmt_list  goto 66


state 22
	func : MAIN '(' ')' compound_stmt .  (12)

	.  reduce 12


state 23
	id_list : id_list ',' ID .  (9)

	.  reduce 9


state 24
	func : INT MAIN '(' ')' compound_stmt .  (11)

	.  reduce 11


state 25
	unary_op : '!' .  (71)

	.  reduce 71


state 26
	basic_expr : '(' . expr ')'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 67
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 27
	unary_op : '+' .  (68)

	.  reduce 68


state 28
	unary_op : '-' .  (69)

	.  reduce 69


state 29
	expr_stmt : ';' .  (84)

	.  reduce 84


state 30
	compound_stmt : '{' '}' .  (88)

	.  reduce 88


state 31
	unary_op : '~' .  (70)

	.  reduce 70


state 32
	type : INT .  (3)

	.  reduce 3


state 33
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 68


state 34
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt

	'('  shift 69


state 35
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 70


state 36
	unary_op : INC .  (72)

	.  reduce 72


state 37
	unary_op : DEC .  (73)

	.  reduce 73


state 38
	val : INTVAL .  (74)

	.  reduce 74


state 39
	val : CHARVAL .  (75)

	.  reduce 75


state 40
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (53)

	'='  shift 71
	ADDASSIGN  shift 72
	SUBASSIGN  shift 73
	MULASSIGN  shift 74
	DIVASSIGN  shift 75
	MODASSIGN  shift 76
	ANDASSIGN  shift 77
	ORASSIGN  shift 78
	XORASSIGN  shift 79
	REVASSIGN  shift 80
	LSHIFTASSIGN  shift 81
	RSHIFTASSIGN  shift 82
	.  reduce 53

	assign_op  goto 83


state 41
	decl_list : decl_list . decl
	compound_stmt : '{' decl_list . stmt_list '}'
	compound_stmt : '{' decl_list . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 84
	'~'  shift 31
	INT  shift 32
	CHAR  shift 2
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	decl  goto 12
	type  goto 8
	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 50
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65
	stmt_list  goto 85


state 42
	const_expr : ternary_expr .  (17)

	.  reduce 17


state 43
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr
	ternary_expr : or_expr .  (19)

	'?'  shift 86
	OR  shift 87
	.  reduce 19


state 44
	stmt : compound_stmt .  (78)

	.  reduce 78


state 45
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 88
	';'  shift 89


state 46
	expr : assign_expr .  (14)

	.  reduce 14


state 47
	assign_expr : const_expr .  (16)

	.  reduce 16


state 48
	postfix_expr : basic_expr .  (52)

	.  reduce 52


state 49
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : shift_expr .  (37)

	LSHIFT  shift 90
	RSHIFT  shift 91
	.  reduce 37


state 50
	stmt_list : stmt .  (92)

	.  reduce 92


state 51
	stmt : conditional_stmt .  (79)

	.  reduce 79


state 52
	stmt : expr_stmt .  (77)

	.  reduce 77


state 53
	unary_expr : unary_op . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	unary_expr  goto 93
	val  goto 58
	postfix_expr  goto 59


state 54
	shift_expr : add_sub_expr .  (40)
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr

	'+'  shift 94
	'-'  shift 95
	.  reduce 40


state 55
	stmt : loop_stmt .  (76)

	.  reduce 76


state 56
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	add_sub_expr : mul_div_mod_expr .  (43)

	'%'  shift 96
	'*'  shift 97
	'/'  shift 98
	.  reduce 43


state 57
	mul_div_mod_expr : unary_expr .  (47)

	.  reduce 47


state 58
	basic_expr : val .  (54)

	.  reduce 54


state 59
	postfix_expr : postfix_expr . INC
	postfix_expr : postfix_expr . DEC
	unary_expr : postfix_expr .  (49)

	INC  shift 99
	DEC  shift 100
	.  reduce 49


state 60
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_and_expr .  (27)

	'&'  shift 101
	.  reduce 27


state 61
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : equal_expr .  (29)

	EQ  shift 102
	NE  shift 103
	.  reduce 29


state 62
	equal_expr : greater_less_expr .  (32)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 104
	GE  shift 105
	LT  shift 106
	GT  shift 107
	.  reduce 32


state 63
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : bit_or_expr .  (23)

	'|'  shift 108
	.  reduce 23


state 64
	or_expr : and_expr .  (21)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 109
	.  reduce 21


state 65
	bit_or_expr : bit_xor_expr .  (25)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 110
	.  reduce 25


state 66
	stmt_list : stmt_list . stmt
	compound_stmt : '{' stmt_list . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 111
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 112
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 67
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 113
	','  shift 88


state 68
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 114
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 69
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	expr_stmt  goto 115
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 70
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 116
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 71
	assign_op : '=' .  (56)

	.  reduce 56


state 72
	assign_op : ADDASSIGN .  (57)

	.  reduce 57


state 73
	assign_op : SUBASSIGN .  (58)

	.  reduce 58


state 74
	assign_op : MULASSIGN .  (59)

	.  reduce 59


state 75
	assign_op : DIVASSIGN .  (60)

	.  reduce 60


state 76
	assign_op : MODASSIGN .  (61)

	.  reduce 61


state 77
	assign_op : ANDASSIGN .  (62)

	.  reduce 62


state 78
	assign_op : ORASSIGN .  (63)

	.  reduce 63


state 79
	assign_op : XORASSIGN .  (64)

	.  reduce 64


state 80
	assign_op : REVASSIGN .  (65)

	.  reduce 65


state 81
	assign_op : LSHIFTASSIGN .  (66)

	.  reduce 66


state 82
	assign_op : RSHIFTASSIGN .  (67)

	.  reduce 67


state 83
	assign_expr : ID assign_op . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 117
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 84
	compound_stmt : '{' decl_list '}' .  (86)

	.  reduce 86


state 85
	stmt_list : stmt_list . stmt
	compound_stmt : '{' decl_list stmt_list . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 118
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 112
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 86
	ternary_expr : or_expr '?' . ternary_expr ':' ternary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	ternary_expr  goto 119
	or_expr  goto 43
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 87
	or_expr : or_expr OR . and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 120
	bit_xor_expr  goto 65


state 88
	expr : expr ',' . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 121
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 89
	expr_stmt : expr ';' .  (83)

	.  reduce 83


state 90
	shift_expr : shift_expr LSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	add_sub_expr  goto 122
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 91
	shift_expr : shift_expr RSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	add_sub_expr  goto 123
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 92
	basic_expr : ID .  (53)

	.  reduce 53


state 93
	unary_expr : unary_op unary_expr .  (48)

	.  reduce 48


state 94
	add_sub_expr : add_sub_expr '+' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	mul_div_mod_expr  goto 124
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 95
	add_sub_expr : add_sub_expr '-' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	mul_div_mod_expr  goto 125
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 96
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	unary_expr  goto 126
	val  goto 58
	postfix_expr  goto 59


state 97
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	unary_expr  goto 127
	val  goto 58
	postfix_expr  goto 59


state 98
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	unary_op  goto 53
	unary_expr  goto 128
	val  goto 58
	postfix_expr  goto 59


state 99
	postfix_expr : postfix_expr INC .  (50)

	.  reduce 50


state 100
	postfix_expr : postfix_expr DEC .  (51)

	.  reduce 51


state 101
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	equal_expr  goto 129
	greater_less_expr  goto 62


state 102
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	greater_less_expr  goto 130


state 103
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	greater_less_expr  goto 131


state 104
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 132
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 105
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 133
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 106
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 134
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 107
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 135
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 108
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_xor_expr  goto 136


state 109
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 137
	bit_xor_expr  goto 65


state 110
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 138
	equal_expr  goto 61
	greater_less_expr  goto 62


state 111
	compound_stmt : '{' stmt_list '}' .  (87)

	.  reduce 87


state 112
	stmt_list : stmt_list stmt .  (91)

	.  reduce 91


state 113
	basic_expr : '(' expr ')' .  (55)

	.  reduce 55


state 114
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 139
	','  shift 88


state 115
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	expr_stmt  goto 140
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 116
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 141
	','  shift 88


state 117
	assign_expr : ID assign_op assign_expr .  (15)

	.  reduce 15


state 118
	compound_stmt : '{' decl_list stmt_list '}' .  (85)

	.  reduce 85


state 119
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 142


state 120
	or_expr : or_expr OR and_expr .  (20)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 109
	.  reduce 20


state 121
	expr : expr ',' assign_expr .  (13)

	.  reduce 13


state 122
	shift_expr : shift_expr LSHIFT add_sub_expr .  (38)
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr

	'+'  shift 94
	'-'  shift 95
	.  reduce 38


state 123
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : shift_expr RSHIFT add_sub_expr .  (39)
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr

	'+'  shift 94
	'-'  shift 95
	.  reduce 39


state 124
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	add_sub_expr : add_sub_expr '+' mul_div_mod_expr .  (41)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr

	'%'  shift 96
	'*'  shift 97
	'/'  shift 98
	.  reduce 41


state 125
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	add_sub_expr : add_sub_expr '-' mul_div_mod_expr .  (42)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr

	'%'  shift 96
	'*'  shift 97
	'/'  shift 98
	.  reduce 42


state 126
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (46)

	.  reduce 46


state 127
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (44)

	.  reduce 44


state 128
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (45)

	.  reduce 45


state 129
	bit_and_expr : bit_and_expr '&' equal_expr .  (28)
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr

	EQ  shift 102
	NE  shift 103
	.  reduce 28


state 130
	equal_expr : equal_expr EQ greater_less_expr .  (30)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 104
	GE  shift 105
	LT  shift 106
	GT  shift 107
	.  reduce 30


state 131
	equal_expr : equal_expr NE greater_less_expr .  (31)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 104
	GE  shift 105
	LT  shift 106
	GT  shift 107
	.  reduce 31


state 132
	greater_less_expr : greater_less_expr LE shift_expr .  (33)
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 90
	RSHIFT  shift 91
	.  reduce 33


state 133
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GE shift_expr .  (34)

	LSHIFT  shift 90
	RSHIFT  shift 91
	.  reduce 34


state 134
	greater_less_expr : greater_less_expr LT shift_expr .  (35)
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 90
	RSHIFT  shift 91
	.  reduce 35


state 135
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GT shift_expr .  (36)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 90
	RSHIFT  shift 91
	.  reduce 36


state 136
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (24)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 110
	.  reduce 24


state 137
	and_expr : and_expr AND bit_or_expr .  (22)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 108
	.  reduce 22


state 138
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (26)

	'&'  shift 101
	.  reduce 26


state 139
	loop_stmt : WHILE '(' expr ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 143
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 140
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt

	'!'  shift 25
	'('  shift 26
	')'  shift 144
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	expr  goto 145
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 141
	conditional_stmt : IF '(' expr ')' . stmt
	conditional_stmt : IF '(' expr ')' . stmt ELSE stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 146
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 142
	ternary_expr : or_expr '?' ternary_expr ':' . ternary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 92

	ternary_expr  goto 147
	or_expr  goto 43
	basic_expr  goto 48
	shift_expr  goto 49
	unary_op  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 143
	loop_stmt : WHILE '(' expr ')' stmt .  (80)

	.  reduce 80


state 144
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 148
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 145
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 149
	','  shift 88


state 146
	conditional_stmt : IF '(' expr ')' stmt .  (90)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 150
	.  reduce 90


state 147
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (18)

	.  reduce 18


state 148
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (82)

	.  reduce 82


state 149
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 151
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 150
	conditional_stmt : IF '(' expr ')' stmt ELSE . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INC  shift 36
	DEC  shift 37
	INTVAL  shift 38
	CHARVAL  shift 39
	ID  shift 40

	ternary_expr  goto 42
	or_expr  goto 43
	compound_stmt  goto 44
	expr  goto 45
	assign_expr  goto 46
	const_expr  goto 47
	basic_expr  goto 48
	shift_expr  goto 49
	stmt  goto 152
	conditional_stmt  goto 51
	expr_stmt  goto 52
	unary_op  goto 53
	add_sub_expr  goto 54
	loop_stmt  goto 55
	mul_div_mod_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	equal_expr  goto 61
	greater_less_expr  goto 62
	bit_or_expr  goto 63
	and_expr  goto 64
	bit_xor_expr  goto 65


state 151
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (81)

	.  reduce 81


state 152
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (89)

	.  reduce 89


##############################################################################
# Summary
##############################################################################

55 token(s), 33 nonterminal(s)
93 grammar rule(s), 153 state(s)


##############################################################################
# End of File
##############################################################################
