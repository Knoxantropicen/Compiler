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
# Date: 01/02/18
# Time: 21:29:31
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : blocks

    2  blocks : decl_group func
    3         | func

    4  type : INT
    5       | CHAR

    6  decl_group : decl_group decl
    7             | decl

    8  decl : type decl_list ';'
    9       | type ';'

   10  decl_list : decl_list ',' ID
   11            | ID

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

   87  compound_stmt : '{' stmt_decl_list '}'
   88                | '{' '}'

   89  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
   90                   | IF '(' expr ')' stmt

   91  stmt_decl_list : stmt_decl_list stmt
   92                 | stmt_decl_list decl
   93                 | stmt
   94                 | decl


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	type  goto 4
	program  goto 5
	decl_group  goto 6
	decl  goto 7
	blocks  goto 8
	func  goto 9


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
	decl : type . decl_list ';'
	decl : type . ';'

	';'  shift 12
	ID  shift 13

	decl_list  goto 14


state 5
	$accept : program . $end  (0)

	$end  accept


state 6
	blocks : decl_group . func
	decl_group : decl_group . decl

	INT  shift 1
	CHAR  shift 2
	MAIN  shift 3

	type  goto 4
	decl  goto 15
	func  goto 16


state 7
	decl_group : decl .  (7)

	.  reduce 7


state 8
	program : blocks .  (1)

	.  reduce 1


state 9
	blocks : func .  (3)

	.  reduce 3


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
	decl_list : ID .  (11)

	.  reduce 11


state 14
	decl : type decl_list . ';'
	decl_list : decl_list . ',' ID

	','  shift 19
	';'  shift 20


state 15
	decl_group : decl_group decl .  (6)

	.  reduce 6


state 16
	blocks : decl_group func .  (2)

	.  reduce 2


state 17
	func : INT MAIN '(' . ')' compound_stmt

	')'  shift 21


state 18
	func : MAIN '(' ')' . compound_stmt

	'{'  shift 22

	compound_stmt  goto 23


state 19
	decl_list : decl_list ',' . ID

	ID  shift 24


state 20
	decl : type decl_list ';' .  (8)

	.  reduce 8


state 21
	func : INT MAIN '(' ')' . compound_stmt

	'{'  shift 22

	compound_stmt  goto 25


state 22
	compound_stmt : '{' . '}'
	compound_stmt : '{' . stmt_decl_list '}'

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

	type  goto 4
	const_expr  goto 43
	assign_expr  goto 44
	decl  goto 45
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 50
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	stmt_decl_list  goto 67
	conditional_stmt  goto 68


state 23
	func : MAIN '(' ')' compound_stmt .  (13)

	.  reduce 13


state 24
	decl_list : decl_list ',' ID .  (10)

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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 69
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


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
	compound_stmt : '{' '}' .  (88)

	.  reduce 88


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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 71
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


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
	assign_expr : const_expr .  (17)

	.  reduce 17


state 44
	expr : assign_expr .  (15)

	.  reduce 15


state 45
	stmt_decl_list : decl .  (94)

	.  reduce 94


state 46
	stmt : compound_stmt .  (79)

	.  reduce 79


state 47
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 87
	';'  shift 88


state 48
	greater_less_expr : shift_expr .  (38)
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 89
	RSHIFT  shift 90
	.  reduce 38


state 49
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

	unary_op  goto 49
	basic_expr  goto 56
	unary_expr  goto 92
	val  goto 58
	postfix_expr  goto 59


state 50
	stmt_decl_list : stmt .  (93)

	.  reduce 93


state 51
	stmt : loop_stmt .  (77)

	.  reduce 77


state 52
	stmt : expr_stmt .  (78)

	.  reduce 78


state 53
	equal_expr : greater_less_expr .  (33)
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 33


state 54
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : add_sub_expr .  (41)

	'+'  shift 97
	'-'  shift 98
	.  reduce 41


state 55
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	add_sub_expr : mul_div_mod_expr .  (44)
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 99
	'*'  shift 100
	'/'  shift 101
	.  reduce 44


state 56
	postfix_expr : basic_expr .  (53)

	.  reduce 53


state 57
	mul_div_mod_expr : unary_expr .  (48)

	.  reduce 48


state 58
	basic_expr : val .  (55)

	.  reduce 55


state 59
	postfix_expr : postfix_expr . INC
	postfix_expr : postfix_expr . DEC
	unary_expr : postfix_expr .  (50)

	INC  shift 102
	DEC  shift 103
	.  reduce 50


state 60
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_and_expr .  (28)

	'&'  shift 104
	.  reduce 28


state 61
	bit_or_expr : bit_xor_expr .  (26)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 105
	.  reduce 26


state 62
	or_expr : and_expr .  (22)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 106
	.  reduce 22


state 63
	const_expr : ternary_expr .  (18)

	.  reduce 18


state 64
	equal_expr : equal_expr . EQ greater_less_expr
	bit_and_expr : equal_expr .  (30)
	equal_expr : equal_expr . NE greater_less_expr

	EQ  shift 107
	NE  shift 108
	.  reduce 30


state 65
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : bit_or_expr .  (24)

	'|'  shift 109
	.  reduce 24


state 66
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr
	ternary_expr : or_expr .  (20)
	or_expr : or_expr . OR and_expr

	'?'  shift 110
	OR  shift 111
	.  reduce 20


state 67
	stmt_decl_list : stmt_decl_list . stmt
	stmt_decl_list : stmt_decl_list . decl
	compound_stmt : '{' stmt_decl_list . '}'

	'!'  shift 26
	'('  shift 27
	'+'  shift 28
	'-'  shift 29
	';'  shift 30
	'{'  shift 22
	'}'  shift 112
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

	type  goto 4
	const_expr  goto 43
	assign_expr  goto 44
	decl  goto 113
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 114
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 68
	stmt : conditional_stmt .  (80)

	.  reduce 80


state 69
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 115
	','  shift 87


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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 116
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 71
	loop_stmt : DO stmt . WHILE '(' expr ')'

	WHILE  shift 117


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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	expr_stmt  goto 118
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 119
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


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

	const_expr  goto 43
	assign_expr  goto 120
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 87
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

	const_expr  goto 43
	assign_expr  goto 121
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 88
	expr_stmt : expr ';' .  (85)

	.  reduce 85


state 89
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

	unary_op  goto 49
	add_sub_expr  goto 122
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 90
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

	unary_op  goto 49
	add_sub_expr  goto 123
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 91
	basic_expr : ID .  (54)

	.  reduce 54


state 92
	unary_expr : unary_op unary_expr .  (49)

	.  reduce 49


state 93
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

	shift_expr  goto 124
	unary_op  goto 49
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 94
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

	shift_expr  goto 125
	unary_op  goto 49
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 95
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

	shift_expr  goto 126
	unary_op  goto 49
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 96
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

	shift_expr  goto 127
	unary_op  goto 49
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 97
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

	unary_op  goto 49
	mul_div_mod_expr  goto 128
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 98
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

	unary_op  goto 49
	mul_div_mod_expr  goto 129
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 99
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

	unary_op  goto 49
	basic_expr  goto 56
	unary_expr  goto 130
	val  goto 58
	postfix_expr  goto 59


state 100
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

	unary_op  goto 49
	basic_expr  goto 56
	unary_expr  goto 131
	val  goto 58
	postfix_expr  goto 59


state 101
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

	unary_op  goto 49
	basic_expr  goto 56
	unary_expr  goto 132
	val  goto 58
	postfix_expr  goto 59


state 102
	postfix_expr : postfix_expr INC .  (51)

	.  reduce 51


state 103
	postfix_expr : postfix_expr DEC .  (52)

	.  reduce 52


state 104
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	equal_expr  goto 133


state 105
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 134
	equal_expr  goto 64


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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	equal_expr  goto 64
	bit_or_expr  goto 135


state 107
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 136
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


state 108
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 137
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59


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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 138
	equal_expr  goto 64


state 110
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 139
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 111
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 140
	equal_expr  goto 64
	bit_or_expr  goto 65


state 112
	compound_stmt : '{' stmt_decl_list '}' .  (87)

	.  reduce 87


state 113
	stmt_decl_list : stmt_decl_list decl .  (92)

	.  reduce 92


state 114
	stmt_decl_list : stmt_decl_list stmt .  (91)

	.  reduce 91


state 115
	basic_expr : '(' expr ')' .  (56)

	.  reduce 56


state 116
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 141
	','  shift 87


state 117
	loop_stmt : DO stmt WHILE . '(' expr ')'

	'('  shift 142


state 118
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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	expr_stmt  goto 143
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 119
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 144
	','  shift 87


state 120
	assign_expr : ID assign_op assign_expr .  (16)

	.  reduce 16


state 121
	expr : expr ',' assign_expr .  (14)

	.  reduce 14


state 122
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	shift_expr : shift_expr LSHIFT add_sub_expr .  (39)
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr

	'+'  shift 97
	'-'  shift 98
	.  reduce 39


state 123
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : shift_expr RSHIFT add_sub_expr .  (40)

	'+'  shift 97
	'-'  shift 98
	.  reduce 40


state 124
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr
	greater_less_expr : greater_less_expr LE shift_expr .  (34)

	LSHIFT  shift 89
	RSHIFT  shift 90
	.  reduce 34


state 125
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr GE shift_expr .  (35)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 89
	RSHIFT  shift 90
	.  reduce 35


state 126
	shift_expr : shift_expr . LSHIFT add_sub_expr
	greater_less_expr : greater_less_expr LT shift_expr .  (36)
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 89
	RSHIFT  shift 90
	.  reduce 36


state 127
	greater_less_expr : greater_less_expr GT shift_expr .  (37)
	shift_expr : shift_expr . LSHIFT add_sub_expr
	shift_expr : shift_expr . RSHIFT add_sub_expr

	LSHIFT  shift 89
	RSHIFT  shift 90
	.  reduce 37


state 128
	add_sub_expr : add_sub_expr '+' mul_div_mod_expr .  (42)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 99
	'*'  shift 100
	'/'  shift 101
	.  reduce 42


state 129
	add_sub_expr : add_sub_expr '-' mul_div_mod_expr .  (43)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr

	'%'  shift 99
	'*'  shift 100
	'/'  shift 101
	.  reduce 43


state 130
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (47)

	.  reduce 47


state 131
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (45)

	.  reduce 45


state 132
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (46)

	.  reduce 46


state 133
	bit_and_expr : bit_and_expr '&' equal_expr .  (29)
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr

	EQ  shift 107
	NE  shift 108
	.  reduce 29


state 134
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (27)

	'&'  shift 104
	.  reduce 27


state 135
	and_expr : and_expr AND bit_or_expr .  (23)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 109
	.  reduce 23


state 136
	equal_expr : equal_expr EQ greater_less_expr .  (31)
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 31


state 137
	equal_expr : equal_expr NE greater_less_expr .  (32)
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr

	LE  shift 93
	GE  shift 94
	LT  shift 95
	GT  shift 96
	.  reduce 32


state 138
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (25)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 105
	.  reduce 25


state 139
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 145


state 140
	and_expr : and_expr . AND bit_or_expr
	or_expr : or_expr OR and_expr .  (21)

	AND  shift 106
	.  reduce 21


state 141
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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 146
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 142
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

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 147
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 143
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt

	'!'  shift 26
	'('  shift 27
	')'  shift 148
	'+'  shift 28
	'-'  shift 29
	'~'  shift 32
	INC  shift 38
	DEC  shift 39
	INTVAL  shift 40
	CHARVAL  shift 41
	ID  shift 42

	const_expr  goto 43
	assign_expr  goto 44
	expr  goto 149
	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 144
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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 150
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 145
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

	shift_expr  goto 48
	unary_op  goto 49
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 151
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66


state 146
	loop_stmt : WHILE '(' expr ')' stmt .  (81)

	.  reduce 81


state 147
	expr : expr . ',' assign_expr
	loop_stmt : DO stmt WHILE '(' expr . ')'

	')'  shift 152
	','  shift 87


state 148
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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 153
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 149
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 154
	','  shift 87


state 150
	conditional_stmt : IF '(' expr ')' stmt .  (90)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 155
	.  reduce 90


state 151
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (19)

	.  reduce 19


state 152
	loop_stmt : DO stmt WHILE '(' expr ')' .  (82)

	.  reduce 82


state 153
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (84)

	.  reduce 84


state 154
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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 156
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 155
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

	const_expr  goto 43
	assign_expr  goto 44
	compound_stmt  goto 46
	expr  goto 47
	shift_expr  goto 48
	unary_op  goto 49
	stmt  goto 157
	loop_stmt  goto 51
	expr_stmt  goto 52
	greater_less_expr  goto 53
	add_sub_expr  goto 54
	mul_div_mod_expr  goto 55
	basic_expr  goto 56
	unary_expr  goto 57
	val  goto 58
	postfix_expr  goto 59
	bit_and_expr  goto 60
	bit_xor_expr  goto 61
	and_expr  goto 62
	ternary_expr  goto 63
	equal_expr  goto 64
	bit_or_expr  goto 65
	or_expr  goto 66
	conditional_stmt  goto 68


state 156
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (83)

	.  reduce 83


state 157
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (89)

	.  reduce 89


##############################################################################
# Summary
##############################################################################

56 token(s), 34 nonterminal(s)
95 grammar rule(s), 158 state(s)


##############################################################################
# End of File
##############################################################################
