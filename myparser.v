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
# Date: 01/03/18
# Time: 08:53:30
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : blocks

    2  blocks : decl_list func
    3         | func

    4  type : INT
    5       | CHAR

    6  decl_list : decl_list decl
    7            | decl

    8  decl : type id_list ';'
    9       | type ';'

   10  id_list : id_list ',' ID
   11          | ID

   12  func : INT MAIN '(' ')' compound_stmt
   13       | MAIN '(' ')' compound_stmt

   14  expr : expr ',' assign_expr
   15       | assign_expr

   16  assign_expr : ID assign_op assign_expr
   17              | const_expr

   18  const_expr : ternary_expr

   19  ternary_expr : or_expr '?' ternary_expr ':' ternary_expr
   20               | or_expr

   21  or_expr : or_expr OR and_expr
   22          | and_expr

   23  and_expr : and_expr AND bit_or_expr
   24           | bit_or_expr

   25  bit_or_expr : bit_or_expr '|' bit_xor_expr
   26              | bit_xor_expr

   27  bit_xor_expr : bit_xor_expr '^' bit_and_expr
   28               | bit_and_expr

   29  bit_and_expr : bit_and_expr '&' equal_expr
   30               | equal_expr

   31  equal_expr : equal_expr EQ greater_less_expr
   32             | equal_expr NE greater_less_expr
   33             | greater_less_expr

   34  greater_less_expr : greater_less_expr LE shift_expr
   35                    | greater_less_expr GE shift_expr
   36                    | greater_less_expr LT shift_expr
   37                    | greater_less_expr GT shift_expr
   38                    | shift_expr

   39  shift_expr : shift_expr LSHIFT add_sub_expr
   40             | shift_expr RSHIFT add_sub_expr
   41             | add_sub_expr

   42  add_sub_expr : add_sub_expr '+' mul_div_mod_expr
   43               | add_sub_expr '-' mul_div_mod_expr
   44               | mul_div_mod_expr

   45  mul_div_mod_expr : mul_div_mod_expr '*' unary_expr
   46                   | mul_div_mod_expr '/' unary_expr
   47                   | mul_div_mod_expr '%' unary_expr
   48                   | unary_expr

   49  unary_expr : unary_op unary_expr
   50             | postfix_expr

   51  postfix_expr : postfix_expr INC
   52               | postfix_expr DEC
   53               | basic_expr

   54  basic_expr : ID
   55             | val
   56             | '(' expr ')'

   57  assign_op : '='
   58            | ADDASSIGN
   59            | SUBASSIGN
   60            | MULASSIGN
   61            | DIVASSIGN
   62            | MODASSIGN
   63            | ANDASSIGN
   64            | ORASSIGN
   65            | XORASSIGN
   66            | REVASSIGN
   67            | LSHIFTASSIGN
   68            | RSHIFTASSIGN

   69  unary_op : '+'
   70           | '-'
   71           | '~'
   72           | '!'
   73           | INC
   74           | DEC

   75  val : INTVAL
   76      | CHARVAL

   77  stmt : loop_stmt
   78       | expr_stmt
   79       | compound_stmt
   80       | conditional_stmt

   81  loop_stmt : WHILE '(' expr ')' stmt
   82            | DO stmt WHILE '(' expr ')'
   83            | FOR '(' expr_stmt expr_stmt expr ')' stmt
   84            | FOR '(' expr_stmt expr_stmt ')' stmt

   85  expr_stmt : expr ';'
   86            | ';'

   87  compound_stmt : '{' decl_list stmt_list '}'
   88                | '{' decl_list '}'
   89                | '{' stmt_list '}'
   90                | '{' '}'

   91  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
   92                   | IF '(' expr ')' stmt

   93  stmt_list : stmt_list stmt
   94            | stmt


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	func  goto 4
	type  goto 5
	program  goto 6
	blocks  goto 7
	decl_list  goto 8
	decl  goto 9


state 1
	type : INT .  (4)
	func : INT . MAIN '(' ')' compound_stmt

	MAIN  shift 10
	.  reduce 4


state 2
	type : CHAR .  (5)

	.  reduce 5


state 3
	func : MAIN . '(' ')' compound_stmt

	'('  shift 11


state 4
	blocks : func .  (3)

	.  reduce 3


state 5
	decl : type . id_list ';'
	decl : type . ';'

	';'  shift 12
	ID  shift 13

	id_list  goto 14


state 6
	$accept : program . $end  (0)

	$end  accept


state 7
	program : blocks .  (1)

	.  reduce 1


state 8
	blocks : decl_list . func
	decl_list : decl_list . decl

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	func  goto 15
	type  goto 5
	decl  goto 16


state 9
	decl_list : decl .  (7)

	.  reduce 7


state 10
	func : INT MAIN . '(' ')' compound_stmt

	'('  shift 17


state 11
	func : MAIN '(' . ')' compound_stmt

	')'  shift 18


state 12
	decl : type ';' .  (9)

	.  reduce 9


state 13
	id_list : ID .  (11)

	.  reduce 11


state 14
	decl : type id_list . ';'
	id_list : id_list . ',' ID

	','  shift 19
	';'  shift 20


state 15
	blocks : decl_list func .  (2)

	.  reduce 2


state 16
	decl_list : decl_list decl .  (6)

	.  reduce 6


state 17
	func : INT MAIN '(' . ')' compound_stmt

	')'  shift 21


state 18
	func : MAIN '(' ')' . compound_stmt

	'{'  shift 22

	compound_stmt  goto 23


state 19
	id_list : id_list ',' . ID

	ID  shift 24


state 20
	decl : type id_list ';' .  (8)

	.  reduce 8


state 21
	func : INT MAIN '(' ')' . compound_stmt

	'{'  shift 22

	compound_stmt  goto 25


state 22
	compound_stmt : '{' . '}'
	compound_stmt : '{' . decl_list stmt_list '}'
	compound_stmt : '{' . stmt_list '}'
	compound_stmt : '{' . decl_list '}'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'}'  shift 31
	'~'  shift 32
	INT  shift 33
	CHAR  shift 2
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	type  goto 5
	decl_list  goto 43
	decl  goto 9
	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 50
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67
	stmt_list  goto 68


state 23
	func : MAIN '(' ')' compound_stmt .  (13)

	.  reduce 13


state 24
	id_list : id_list ',' ID .  (10)

	.  reduce 10


state 25
	func : INT MAIN '(' ')' compound_stmt .  (12)

	.  reduce 12


state 26
	unary_op : '!' .  (72)

	.  reduce 72


state 27
	basic_expr : '(' . expr ')'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 69
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 28
	unary_op : '+' .  (69)

	.  reduce 69


state 29
	unary_op : '-' .  (70)

	.  reduce 70


state 30
	expr_stmt : ';' .  (86)

	.  reduce 86


state 31
	compound_stmt : '{' '}' .  (90)

	.  reduce 90


state 32
	unary_op : '~' .  (71)

	.  reduce 71


state 33
	type : INT .  (4)

	.  reduce 4


state 34
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 70


state 35
	loop_stmt : DO . stmt WHILE '(' expr ')'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 71
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 36
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt

	'('  shift 72


state 37
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 73


state 38
	unary_op : INC .  (73)

	.  reduce 73


state 39
	unary_op : DEC .  (74)

	.  reduce 74


state 40
	val : INTVAL .  (75)

	.  reduce 75


state 41
	val : CHARVAL .  (76)

	.  reduce 76


state 42
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (54)

	'='  shift 74
	ADDASSIGN  shift 75
	SUBASSIGN  shift 76
	MULASSIGN  shift 77
	DIVASSIGN  shift 78
	MODASSIGN  shift 79
	ANDASSIGN  shift 80
	ORASSIGN  shift 81
	XORASSIGN  shift 82
	REVASSIGN  shift 83
	LSHIFTASSIGN  shift 84
	RSHIFTASSIGN  shift 85
	.  reduce 54

	assign_op  goto 86


state 43
	decl_list : decl_list . decl
	compound_stmt : '{' decl_list . stmt_list '}'
	compound_stmt : '{' decl_list . '}'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'}'  shift 87
	'~'  shift 32
	INT  shift 33
	CHAR  shift 2
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	type  goto 5
	decl  goto 16
	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 50
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67
	stmt_list  goto 88


state 44
	assign_expr : const_expr .  (17)

	.  reduce 17


state 45
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 89
	';'  shift 90


state 46
	stmt : compound_stmt .  (79)

	.  reduce 79


state 47
	expr : assign_expr .  (15)

	.  reduce 15


state 48
	mul_div_mod_expr : unary_expr .  (48)

	.  reduce 48


state 49
	basic_expr : val .  (55)

	.  reduce 55


state 50
	stmt_list : stmt .  (94)

	.  reduce 94


state 51
	postfix_expr : basic_expr .  (53)

	.  reduce 53


state 52
	stmt : loop_stmt .  (77)

	.  reduce 77


state 53
	unary_expr : unary_op . unary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 92
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58


state 54
	stmt : expr_stmt .  (78)

	.  reduce 78


state 55
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : add_sub_expr .  (41)

	'+'  shift 93
	'-'  shift 94
	.  reduce 41


state 56
	equal_expr : greater_less_expr .  (33)
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 95
	GE  shift 96
	LT  shift 97
	GT  shift 98
	.  reduce 33


state 57
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : shift_expr .  (38)

	LSHIFT  shift 99
	RSHIFT  shift 100
	.  reduce 38


state 58
	postfix_expr : postfix_expr . INC
	unary_expr : postfix_expr .  (50)
	postfix_expr : postfix_expr . DEC

	INC  shift 101
	DEC  shift 102
	.  reduce 50


state 59
	add_sub_expr : mul_div_mod_expr .  (44)
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 103
	'*'  shift 104
	'/'  shift 105
	.  reduce 44


state 60
	or_expr : and_expr .  (22)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 106
	.  reduce 22


state 61
	const_expr : ternary_expr .  (18)

	.  reduce 18


state 62
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr .  (20)
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr

	'?'  shift 107
	OR  shift 108
	.  reduce 20


state 63
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : bit_or_expr .  (24)

	'|'  shift 109
	.  reduce 24


state 64
	bit_or_expr : bit_xor_expr .  (26)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 110
	.  reduce 26


state 65
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : equal_expr .  (30)

	EQ  shift 111
	NE  shift 112
	.  reduce 30


state 66
	bit_xor_expr : bit_and_expr .  (28)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 113
	.  reduce 28


state 67
	stmt : conditional_stmt .  (80)

	.  reduce 80


state 68
	stmt_list : stmt_list . stmt
	compound_stmt : '{' stmt_list . '}'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'}'  shift 114
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 115
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 69
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 116
	','  shift 89


state 70
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 117
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 71
	loop_stmt : DO stmt . WHILE '(' expr ')'

	WHILE  shift 118


state 72
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	expr_stmt  goto 119
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 73
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 120
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 74
	assign_op : '=' .  (57)

	.  reduce 57


state 75
	assign_op : ADDASSIGN .  (58)

	.  reduce 58


state 76
	assign_op : SUBASSIGN .  (59)

	.  reduce 59


state 77
	assign_op : MULASSIGN .  (60)

	.  reduce 60


state 78
	assign_op : DIVASSIGN .  (61)

	.  reduce 61


state 79
	assign_op : MODASSIGN .  (62)

	.  reduce 62


state 80
	assign_op : ANDASSIGN .  (63)

	.  reduce 63


state 81
	assign_op : ORASSIGN .  (64)

	.  reduce 64


state 82
	assign_op : XORASSIGN .  (65)

	.  reduce 65


state 83
	assign_op : REVASSIGN .  (66)

	.  reduce 66


state 84
	assign_op : LSHIFTASSIGN .  (67)

	.  reduce 67


state 85
	assign_op : RSHIFTASSIGN .  (68)

	.  reduce 68


state 86
	assign_expr : ID assign_op . assign_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	assign_expr  goto 121
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 87
	compound_stmt : '{' decl_list '}' .  (88)

	.  reduce 88


state 88
	stmt_list : stmt_list . stmt
	compound_stmt : '{' decl_list stmt_list . '}'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'}'  shift 122
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 115
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 89
	expr : expr ',' . assign_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	assign_expr  goto 123
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 90
	expr_stmt : expr ';' .  (85)

	.  reduce 85


state 91
	basic_expr : ID .  (54)

	.  reduce 54


state 92
	unary_expr : unary_op unary_expr .  (49)

	.  reduce 49


state 93
	add_sub_expr : add_sub_expr '+' . mul_div_mod_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58
	mul_div_mod_expr  goto 124


state 94
	add_sub_expr : add_sub_expr '-' . mul_div_mod_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58
	mul_div_mod_expr  goto 125


state 95
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	shift_expr  goto 126
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 96
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	shift_expr  goto 127
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 97
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	shift_expr  goto 128
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 98
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	shift_expr  goto 129
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 99
	shift_expr : shift_expr LSHIFT . add_sub_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 130
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 100
	shift_expr : shift_expr RSHIFT . add_sub_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 131
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 101
	postfix_expr : postfix_expr INC .  (51)

	.  reduce 51


state 102
	postfix_expr : postfix_expr DEC .  (52)

	.  reduce 52


state 103
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 132
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58


state 104
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 133
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58


state 105
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 134
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	postfix_expr  goto 58


state 106
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	bit_or_expr  goto 135
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 107
	ternary_expr : or_expr '?' . ternary_expr ':' ternary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 136
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 108
	or_expr : or_expr OR . and_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 137
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 109
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	bit_xor_expr  goto 138
	equal_expr  goto 65
	bit_and_expr  goto 66


state 110
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	equal_expr  goto 65
	bit_and_expr  goto 139


state 111
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 140
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 112
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 141
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59


state 113
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	equal_expr  goto 142


state 114
	compound_stmt : '{' stmt_list '}' .  (89)

	.  reduce 89


state 115
	stmt_list : stmt_list stmt .  (93)

	.  reduce 93


state 116
	basic_expr : '(' expr ')' .  (56)

	.  reduce 56


state 117
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 143
	','  shift 89


state 118
	loop_stmt : DO stmt WHILE . '(' expr ')'

	'('  shift 144


state 119
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	expr_stmt  goto 145
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 120
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 146
	','  shift 89


state 121
	assign_expr : ID assign_op assign_expr .  (16)

	.  reduce 16


state 122
	compound_stmt : '{' decl_list stmt_list '}' .  (87)

	.  reduce 87


state 123
	expr : expr ',' assign_expr .  (14)

	.  reduce 14


state 124
	add_sub_expr : add_sub_expr '+' mul_div_mod_expr .  (42)
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 103
	'*'  shift 104
	'/'  shift 105
	.  reduce 42


state 125
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	add_sub_expr : add_sub_expr '-' mul_div_mod_expr .  (43)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 103
	'*'  shift 104
	'/'  shift 105
	.  reduce 43


state 126
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr LE shift_expr .  (34)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 99
	RSHIFT  shift 100
	.  reduce 34


state 127
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GE shift_expr .  (35)

	LSHIFT  shift 99
	RSHIFT  shift 100
	.  reduce 35


state 128
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr LT shift_expr .  (36)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 99
	RSHIFT  shift 100
	.  reduce 36


state 129
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GT shift_expr .  (37)

	LSHIFT  shift 99
	RSHIFT  shift 100
	.  reduce 37


state 130
	shift_expr : shift_expr LSHIFT add_sub_expr .  (39)
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr

	'+'  shift 93
	'-'  shift 94
	.  reduce 39


state 131
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	shift_expr : shift_expr RSHIFT add_sub_expr .  (40)
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr

	'+'  shift 93
	'-'  shift 94
	.  reduce 40


state 132
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (47)

	.  reduce 47


state 133
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (45)

	.  reduce 45


state 134
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (46)

	.  reduce 46


state 135
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : and_expr AND bit_or_expr .  (23)

	'|'  shift 109
	.  reduce 23


state 136
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 147


state 137
	and_expr : and_expr . AND bit_or_expr
	or_expr : or_expr OR and_expr .  (21)

	AND  shift 106
	.  reduce 21


state 138
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (25)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 110
	.  reduce 25


state 139
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (27)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 113
	.  reduce 27


state 140
	equal_expr : equal_expr EQ greater_less_expr .  (31)
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 95
	GE  shift 96
	LT  shift 97
	GT  shift 98
	.  reduce 31


state 141
	equal_expr : equal_expr NE greater_less_expr .  (32)
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 95
	GE  shift 96
	LT  shift 97
	GT  shift 98
	.  reduce 32


state 142
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : bit_and_expr '&' equal_expr .  (29)

	EQ  shift 111
	NE  shift 112
	.  reduce 29


state 143
	loop_stmt : WHILE '(' expr ')' . stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 148
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 144
	loop_stmt : DO stmt WHILE '(' . expr ')'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 149
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 145
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt

	'!'  shift 26
	'('  shift 27
	')'  shift 150
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 151
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 146
	conditional_stmt : IF '(' expr ')' . stmt
	conditional_stmt : IF '(' expr ')' . stmt ELSE stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 152
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 147
	ternary_expr : or_expr '?' ternary_expr ':' . ternary_expr

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 91

	unary_expr  goto 48
	val  goto 49
	basic_expr  goto 51
	unary_op  goto 53
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 153
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66


state 148
	loop_stmt : WHILE '(' expr ')' stmt .  (81)

	.  reduce 81


state 149
	expr : expr . ',' assign_expr
	loop_stmt : DO stmt WHILE '(' expr . ')'

	')'  shift 154
	','  shift 89


state 150
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' . stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 155
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 151
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 156
	','  shift 89


state 152
	conditional_stmt : IF '(' expr ')' stmt .  (92)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 157
	.  reduce 92


state 153
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (19)

	.  reduce 19


state 154
	loop_stmt : DO stmt WHILE '(' expr ')' .  (82)

	.  reduce 82


state 155
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (84)

	.  reduce 84


state 156
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' . stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 158
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 157
	conditional_stmt : IF '(' expr ')' stmt ELSE . stmt

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'~'  shift 32
	WHILE  shift 34
	DO  shift 35
	FOR  shift 36
	IF  shift 37
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	assign_expr  goto 47
	unary_expr  goto 48
	val  goto 49
	stmt  goto 159
	basic_expr  goto 51
	loop_stmt  goto 52
	unary_op  goto 53
	expr_stmt  goto 54
	add_sub_expr  goto 55
	greater_less_expr  goto 56
	shift_expr  goto 57
	postfix_expr  goto 58
	mul_div_mod_expr  goto 59
	and_expr  goto 60
	ternary_expr  goto 61
	or_expr  goto 62
	bit_or_expr  goto 63
	bit_xor_expr  goto 64
	equal_expr  goto 65
	bit_and_expr  goto 66
	conditional_stmt  goto 67


state 158
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (83)

	.  reduce 83


state 159
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (91)

	.  reduce 91


##############################################################################
# Summary
##############################################################################

56 token(s), 34 nonterminal(s)
95 grammar rule(s), 160 state(s)


##############################################################################
# End of File
##############################################################################
