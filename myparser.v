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
# Date: 01/05/18
# Time: 21:35:05
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

   18  ternary_expr : or_expr '?' assign_expr ':' assign_expr
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
   80       | io_stmt

   81  loop_stmt : WHILE '(' expr ')' stmt
   82            | FOR '(' expr_stmt expr_stmt expr ')' stmt
   83            | FOR '(' expr_stmt expr_stmt ')' stmt

   84  expr_stmt : expr ';'
   85            | ';'

   86  compound_stmt : '{' decl_list stmt_list '}'
   87                | '{' decl_list '}'
   88                | '{' stmt_list '}'
   89                | '{' '}'

   90  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
   91                   | IF '(' expr ')' stmt

   92  io_stmt : INPUT '(' ID ')' ';'
   93          | PRINT '(' ID ')' ';'

   94  stmt_list : stmt_list stmt
   95            | stmt


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	program  goto 4
	decl_list  goto 5
	func  goto 6
	type  goto 7
	decl  goto 8


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
	$accept : program . $end  (0)

	$end  accept


state 5
	program : decl_list . func
	decl_list : decl_list . decl

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	func  goto 11
	type  goto 7
	decl  goto 12


state 6
	program : func .  (2)

	.  reduce 2


state 7
	decl : type . id_list ';'
	decl : type . ';'

	';'  shift 13
	ID  shift 14

	id_list  goto 15


state 8
	decl_list : decl .  (6)

	.  reduce 6


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
	compound_stmt : '{' . decl_list '}'
	compound_stmt : '{' . decl_list stmt_list '}'
	compound_stmt : '{' . '}'
	compound_stmt : '{' . stmt_list '}'

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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	decl_list  goto 43
	type  goto 7
	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	decl  goto 8
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 51
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68
	stmt_list  goto 69


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
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 70
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 27
	unary_op : '+' .  (68)

	.  reduce 68


state 28
	unary_op : '-' .  (69)

	.  reduce 69


state 29
	expr_stmt : ';' .  (85)

	.  reduce 85


state 30
	compound_stmt : '{' '}' .  (89)

	.  reduce 89


state 31
	unary_op : '~' .  (70)

	.  reduce 70


state 32
	type : INT .  (3)

	.  reduce 3


state 33
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 71


state 34
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt

	'('  shift 72


state 35
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 73


state 36
	io_stmt : INPUT . '(' ID ')' ';'

	'('  shift 74


state 37
	io_stmt : PRINT . '(' ID ')' ';'

	'('  shift 75


state 38
	unary_op : INC .  (72)

	.  reduce 72


state 39
	unary_op : DEC .  (73)

	.  reduce 73


state 40
	val : INTVAL .  (74)

	.  reduce 74


state 41
	val : CHARVAL .  (75)

	.  reduce 75


state 42
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (53)

	'='  shift 76
	ADDASSIGN  shift 77
	SUBASSIGN  shift 78
	MULASSIGN  shift 79
	DIVASSIGN  shift 80
	MODASSIGN  shift 81
	ANDASSIGN  shift 82
	ORASSIGN  shift 83
	XORASSIGN  shift 84
	REVASSIGN  shift 85
	LSHIFTASSIGN  shift 86
	RSHIFTASSIGN  shift 87
	.  reduce 53

	assign_op  goto 88


state 43
	decl_list : decl_list . decl
	compound_stmt : '{' decl_list . '}'
	compound_stmt : '{' decl_list . stmt_list '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 89
	'~'  shift 31
	INT  shift 32
	CHAR  shift 2
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	type  goto 7
	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	decl  goto 12
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 51
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68
	stmt_list  goto 90


state 44
	stmt : compound_stmt .  (78)

	.  reduce 78


state 45
	assign_expr : const_expr .  (16)

	.  reduce 16


state 46
	expr : assign_expr .  (14)

	.  reduce 14


state 47
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 91
	';'  shift 92


state 48
	const_expr : ternary_expr .  (17)

	.  reduce 17


state 49
	equal_expr : greater_less_expr .  (32)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 32


state 50
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	add_sub_expr : mul_div_mod_expr .  (43)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 97
	'*'  shift 98
	'/'  shift 99
	.  reduce 43


state 51
	stmt_list : stmt .  (95)

	.  reduce 95


state 52
	stmt : expr_stmt .  (77)

	.  reduce 77


state 53
	stmt : loop_stmt .  (76)

	.  reduce 76


state 54
	stmt : conditional_stmt .  (79)

	.  reduce 79


state 55
	mul_div_mod_expr : unary_expr .  (47)

	.  reduce 47


state 56
	basic_expr : val .  (54)

	.  reduce 54


state 57
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : add_sub_expr .  (40)
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr

	'+'  shift 100
	'-'  shift 101
	.  reduce 40


state 58
	unary_expr : unary_op . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	unary_expr  goto 103
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 59
	unary_expr : postfix_expr .  (49)
	postfix_expr : postfix_expr . INC
	postfix_expr : postfix_expr . DEC

	INC  shift 104
	DEC  shift 105
	.  reduce 49


state 60
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : shift_expr .  (37)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 37


state 61
	postfix_expr : basic_expr .  (52)

	.  reduce 52


state 62
	and_expr : bit_or_expr .  (23)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 108
	.  reduce 23


state 63
	bit_xor_expr : bit_and_expr .  (27)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 109
	.  reduce 27


state 64
	ternary_expr : or_expr .  (19)
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr . '?' assign_expr ':' assign_expr

	'?'  shift 110
	OR  shift 111
	.  reduce 19


state 65
	equal_expr : equal_expr . NE greater_less_expr
	equal_expr : equal_expr . EQ greater_less_expr
	bit_and_expr : equal_expr .  (29)

	EQ  shift 112
	NE  shift 113
	.  reduce 29


state 66
	bit_or_expr : bit_xor_expr .  (25)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 114
	.  reduce 25


state 67
	or_expr : and_expr .  (21)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 115
	.  reduce 21


state 68
	stmt : io_stmt .  (80)

	.  reduce 80


state 69
	stmt_list : stmt_list . stmt
	compound_stmt : '{' stmt_list . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 116
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 117
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 70
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 118
	','  shift 91


state 71
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 119
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 72
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	expr_stmt  goto 120
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 73
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 121
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 74
	io_stmt : INPUT '(' . ID ')' ';'

	ID  shift 122


state 75
	io_stmt : PRINT '(' . ID ')' ';'

	ID  shift 123


state 76
	assign_op : '=' .  (56)

	.  reduce 56


state 77
	assign_op : ADDASSIGN .  (57)

	.  reduce 57


state 78
	assign_op : SUBASSIGN .  (58)

	.  reduce 58


state 79
	assign_op : MULASSIGN .  (59)

	.  reduce 59


state 80
	assign_op : DIVASSIGN .  (60)

	.  reduce 60


state 81
	assign_op : MODASSIGN .  (61)

	.  reduce 61


state 82
	assign_op : ANDASSIGN .  (62)

	.  reduce 62


state 83
	assign_op : ORASSIGN .  (63)

	.  reduce 63


state 84
	assign_op : XORASSIGN .  (64)

	.  reduce 64


state 85
	assign_op : REVASSIGN .  (65)

	.  reduce 65


state 86
	assign_op : LSHIFTASSIGN .  (66)

	.  reduce 66


state 87
	assign_op : RSHIFTASSIGN .  (67)

	.  reduce 67


state 88
	assign_expr : ID assign_op . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 124
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 89
	compound_stmt : '{' decl_list '}' .  (87)

	.  reduce 87


state 90
	stmt_list : stmt_list . stmt
	compound_stmt : '{' decl_list stmt_list . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 21
	'}'  shift 125
	'~'  shift 31
	WHILE  shift 33
	FOR  shift 34
	IF  shift 35
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 117
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 91
	expr : expr ',' . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 126
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 92
	expr_stmt : expr ';' .  (84)

	.  reduce 84


state 93
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 127
	basic_expr  goto 61


state 94
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 128
	basic_expr  goto 61


state 95
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 129
	basic_expr  goto 61


state 96
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 130
	basic_expr  goto 61


state 97
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	unary_expr  goto 131
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 98
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	unary_expr  goto 132
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 99
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	unary_expr  goto 133
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 100
	add_sub_expr : add_sub_expr '+' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 134
	unary_expr  goto 55
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 101
	add_sub_expr : add_sub_expr '-' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 135
	unary_expr  goto 55
	val  goto 56
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 102
	basic_expr : ID .  (53)

	.  reduce 53


state 103
	unary_expr : unary_op unary_expr .  (48)

	.  reduce 48


state 104
	postfix_expr : postfix_expr INC .  (50)

	.  reduce 50


state 105
	postfix_expr : postfix_expr DEC .  (51)

	.  reduce 51


state 106
	shift_expr : shift_expr LSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 136
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 107
	shift_expr : shift_expr RSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 137
	unary_op  goto 58
	postfix_expr  goto 59
	basic_expr  goto 61


state 108
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_and_expr  goto 63
	equal_expr  goto 65
	bit_xor_expr  goto 138


state 109
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	equal_expr  goto 139


state 110
	ternary_expr : or_expr '?' . assign_expr ':' assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 140
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 111
	or_expr : or_expr OR . and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 141


state 112
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 142
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61


state 113
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 143
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61


state 114
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_and_expr  goto 144
	equal_expr  goto 65


state 115
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 102

	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 145
	bit_and_expr  goto 63
	equal_expr  goto 65
	bit_xor_expr  goto 66


state 116
	compound_stmt : '{' stmt_list '}' .  (88)

	.  reduce 88


state 117
	stmt_list : stmt_list stmt .  (94)

	.  reduce 94


state 118
	basic_expr : '(' expr ')' .  (55)

	.  reduce 55


state 119
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 146
	','  shift 91


state 120
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	expr_stmt  goto 147
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 121
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 148
	','  shift 91


state 122
	io_stmt : INPUT '(' ID . ')' ';'

	')'  shift 149


state 123
	io_stmt : PRINT '(' ID . ')' ';'

	')'  shift 150


state 124
	assign_expr : ID assign_op assign_expr .  (15)

	.  reduce 15


state 125
	compound_stmt : '{' decl_list stmt_list '}' .  (86)

	.  reduce 86


state 126
	expr : expr ',' assign_expr .  (13)

	.  reduce 13


state 127
	greater_less_expr : greater_less_expr LE shift_expr .  (33)
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 33


state 128
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GE shift_expr .  (34)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 34


state 129
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr LT shift_expr .  (35)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 35


state 130
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GT shift_expr .  (36)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 36


state 131
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (46)

	.  reduce 46


state 132
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (44)

	.  reduce 44


state 133
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (45)

	.  reduce 45


state 134
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	add_sub_expr : add_sub_expr '+' mul_div_mod_expr .  (41)

	'%'  shift 97
	'*'  shift 98
	'/'  shift 99
	.  reduce 41


state 135
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	add_sub_expr : add_sub_expr '-' mul_div_mod_expr .  (42)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 97
	'*'  shift 98
	'/'  shift 99
	.  reduce 42


state 136
	shift_expr : shift_expr LSHIFT add_sub_expr .  (38)
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr

	'+'  shift 100
	'-'  shift 101
	.  reduce 38


state 137
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	shift_expr : shift_expr RSHIFT add_sub_expr .  (39)

	'+'  shift 100
	'-'  shift 101
	.  reduce 39


state 138
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (24)

	'^'  shift 114
	.  reduce 24


state 139
	equal_expr : equal_expr . NE greater_less_expr
	equal_expr : equal_expr . EQ greater_less_expr
	bit_and_expr : bit_and_expr '&' equal_expr .  (28)

	EQ  shift 112
	NE  shift 113
	.  reduce 28


state 140
	ternary_expr : or_expr '?' assign_expr . ':' assign_expr

	':'  shift 151


state 141
	and_expr : and_expr . AND bit_or_expr
	or_expr : or_expr OR and_expr .  (20)

	AND  shift 115
	.  reduce 20


state 142
	equal_expr : equal_expr EQ greater_less_expr .  (30)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 30


state 143
	equal_expr : equal_expr NE greater_less_expr .  (31)
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 31


state 144
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (26)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 109
	.  reduce 26


state 145
	and_expr : and_expr AND bit_or_expr .  (22)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 108
	.  reduce 22


state 146
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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 152
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 147
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt

	'!'  shift 25
	'('  shift 26
	')'  shift 153
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 154
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 148
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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 155
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 149
	io_stmt : INPUT '(' ID ')' . ';'

	';'  shift 156


state 150
	io_stmt : PRINT '(' ID ')' . ';'

	';'  shift 157


state 151
	ternary_expr : or_expr '?' assign_expr ':' . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 45
	assign_expr  goto 158
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67


state 152
	loop_stmt : WHILE '(' expr ')' stmt .  (81)

	.  reduce 81


state 153
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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 159
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 154
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 160
	','  shift 91


state 155
	conditional_stmt : IF '(' expr ')' stmt .  (91)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 161
	.  reduce 91


state 156
	io_stmt : INPUT '(' ID ')' ';' .  (92)

	.  reduce 92


state 157
	io_stmt : PRINT '(' ID ')' ';' .  (93)

	.  reduce 93


state 158
	ternary_expr : or_expr '?' assign_expr ':' assign_expr .  (18)

	.  reduce 18


state 159
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (83)

	.  reduce 83


state 160
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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 162
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 161
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
	INPUT  shift 36
	PRINT  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	compound_stmt  goto 44
	const_expr  goto 45
	assign_expr  goto 46
	expr  goto 47
	ternary_expr  goto 48
	greater_less_expr  goto 49
	mul_div_mod_expr  goto 50
	stmt  goto 163
	expr_stmt  goto 52
	loop_stmt  goto 53
	conditional_stmt  goto 54
	unary_expr  goto 55
	val  goto 56
	add_sub_expr  goto 57
	unary_op  goto 58
	postfix_expr  goto 59
	shift_expr  goto 60
	basic_expr  goto 61
	bit_or_expr  goto 62
	bit_and_expr  goto 63
	or_expr  goto 64
	equal_expr  goto 65
	bit_xor_expr  goto 66
	and_expr  goto 67
	io_stmt  goto 68


state 162
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (82)

	.  reduce 82


state 163
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (90)

	.  reduce 90


##############################################################################
# Summary
##############################################################################

57 token(s), 34 nonterminal(s)
96 grammar rule(s), 164 state(s)


##############################################################################
# End of File
##############################################################################
