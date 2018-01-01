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
# Date: 01/01/18
# Time: 21:22:37
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : blocks

    2  blocks : blocks block
    3         | block

    4  block : decl
    5        | func

    6  type : VOID
    7       | INT
    8       | CHAR

    9  decl : type decl_list ';'
   10       | type ';'

   11  decl_list : decl_list ',' decl_init
   12            | decl_init

   13  decl_init : decl_head '=' init_val
   14            | decl_head

   15  decl_head : var_decl_head

   16  var_decl_head : var_decl_head '[' const_expr ']'
   17                | var_decl_head '[' ']'
   18                | ID

   19  $$1 :

   20  func_decl_head : ID '(' $$1 param_list ')'

   21  $$2 :

   22  func_decl_head : ID '(' $$2 ')'

   23  init_val : '{' init_val_list '}'
   24           | assign_expr

   25  init_val_list : init_val_list ',' init_val
   26                | init_val

   27  param_list : param_list ',' param
   28             | param

   29  param : type decl_init
   30        | type

   31  func : type func_decl_head compound_stmt
   32       | func_decl_head compound_stmt

   33  expr : expr ',' assign_expr
   34       | assign_expr

   35  assign_expr : ID assign_op assign_expr
   36              | const_expr

   37  const_expr : ternary_expr

   38  ternary_expr : or_expr '?' ternary_expr ':' ternary_expr
   39               | or_expr

   40  or_expr : or_expr OR and_expr
   41          | and_expr

   42  and_expr : and_expr AND bit_or_expr
   43           | bit_or_expr

   44  bit_or_expr : bit_or_expr '|' bit_xor_expr
   45              | bit_xor_expr

   46  bit_xor_expr : bit_xor_expr '^' bit_and_expr
   47               | bit_and_expr

   48  bit_and_expr : bit_and_expr '&' equal_expr
   49               | equal_expr

   50  equal_expr : equal_expr EQ greater_less_expr
   51             | equal_expr NE greater_less_expr
   52             | greater_less_expr

   53  greater_less_expr : greater_less_expr LE shift_expr
   54                    | greater_less_expr GE shift_expr
   55                    | greater_less_expr LT shift_expr
   56                    | greater_less_expr GT shift_expr
   57                    | shift_expr

   58  shift_expr : shift_expr LSHIFT addBack_sub_expr
   59             | shift_expr RSHIFT addBack_sub_expr
   60             | addBack_sub_expr

   61  addBack_sub_expr : addBack_sub_expr '+' mul_div_mod_expr
   62                   | addBack_sub_expr '-' mul_div_mod_expr
   63                   | mul_div_mod_expr

   64  mul_div_mod_expr : mul_div_mod_expr '*' unary_expr
   65                   | mul_div_mod_expr '/' unary_expr
   66                   | mul_div_mod_expr '%' unary_expr
   67                   | unary_expr

   68  unary_expr : unary_op unary_expr
   69             | postfix_expr

   70  postfix_expr : postfix_expr '[' expr ']'
   71               | postfix_expr '(' expr ')'
   72               | postfix_expr '(' ')'
   73               | postfix_expr INC
   74               | postfix_expr DEC
   75               | basic_expr

   76  basic_expr : ID
   77             | val
   78             | '(' expr ')'

   79  assign_op : '='
   80            | ADDASSIGN
   81            | SUBASSIGN
   82            | MULASSIGN
   83            | DIVASSIGN
   84            | MODASSIGN
   85            | ANDASSIGN
   86            | ORASSIGN
   87            | XORASSIGN
   88            | REVASSIGN
   89            | LSHIFTASSIGN
   90            | RSHIFTASSIGN

   91  unary_op : '+'
   92           | '-'
   93           | '~'
   94           | '!'
   95           | INC
   96           | DEC

   97  val : INTVAL
   98      | CHARVAL

   99  stmt : jmp_stmt
  100       | loop_stmt
  101       | expr_stmt
  102       | compound_stmt
  103       | conditional_stmt

  104  jmp_stmt : RETURN expr ';'
  105           | RETURN ';'

  106  loop_stmt : WHILE '(' expr ')' stmt
  107            | DO stmt WHILE '(' expr ')'
  108            | FOR '(' expr_stmt expr_stmt expr ')' stmt
  109            | FOR '(' expr_stmt expr_stmt ')' stmt

  110  expr_stmt : expr ';'
  111            | ';'

  112  compound_stmt : '{' stmt_decl_list '}'
  113                | '{' '}'

  114  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
  115                   | IF '(' expr ')' stmt

  116  stmt_decl_list : stmt_decl_list stmt
  117                 | stmt_decl_list decl
  118                 | stmt
  119                 | decl


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	ID  shift 4

	block  goto 5
	blocks  goto 6
	program  goto 7
	decl  goto 8
	func  goto 9
	type  goto 10
	func_decl_head  goto 11


state 1
	type : VOID .  (6)

	.  reduce 6


state 2
	type : INT .  (7)

	.  reduce 7


state 3
	type : CHAR .  (8)

	.  reduce 8


state 4
	func_decl_head : ID . '(' $$1 param_list ')'
	func_decl_head : ID . '(' $$2 ')'

	'('  shift 12


state 5
	blocks : block .  (3)

	.  reduce 3


state 6
	program : blocks .  (1)
	blocks : blocks . block

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	ID  shift 4
	.  reduce 1

	block  goto 13
	decl  goto 8
	func  goto 9
	type  goto 10
	func_decl_head  goto 11


state 7
	$accept : program . $end  (0)

	$end  accept


state 8
	block : decl .  (4)

	.  reduce 4


state 9
	block : func .  (5)

	.  reduce 5


state 10
	decl : type . decl_list ';'
	decl : type . ';'
	func : type . func_decl_head compound_stmt

	';'  shift 14
	ID  shift 15

	decl_head  goto 16
	decl_list  goto 17
	decl_init  goto 18
	var_decl_head  goto 19
	func_decl_head  goto 20


state 11
	func : func_decl_head . compound_stmt

	'{'  shift 21

	compound_stmt  goto 22


state 12
	func_decl_head : ID '(' . $$1 param_list ')'
	func_decl_head : ID '(' . $$2 ')'
	$$1 : .  (19)
	$$2 : .  (21)

	')'  reduce 21
	.  reduce 19

	$$2  goto 23
	$$1  goto 24


state 13
	blocks : blocks block .  (2)

	.  reduce 2


state 14
	decl : type ';' .  (10)

	.  reduce 10


state 15
	func_decl_head : ID . '(' $$1 param_list ')'
	var_decl_head : ID .  (18)
	func_decl_head : ID . '(' $$2 ')'

	'('  shift 12
	.  reduce 18


state 16
	decl_init : decl_head . '=' init_val
	decl_init : decl_head .  (14)

	'='  shift 25
	.  reduce 14


state 17
	decl : type decl_list . ';'
	decl_list : decl_list . ',' decl_init

	','  shift 26
	';'  shift 27


state 18
	decl_list : decl_init .  (12)

	.  reduce 12


state 19
	decl_head : var_decl_head .  (15)
	var_decl_head : var_decl_head . '[' const_expr ']'
	var_decl_head : var_decl_head . '[' ']'

	'['  shift 28
	.  reduce 15


state 20
	func : type func_decl_head . compound_stmt

	'{'  shift 21

	compound_stmt  goto 29


state 21
	compound_stmt : '{' . '}'
	compound_stmt : '{' . stmt_decl_list '}'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'}'  shift 35
	'~'  shift 36
	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	decl  goto 48
	type  goto 49
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	stmt_decl_list  goto 68
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 72
	unary_op  goto 73
	unary_expr  goto 74


state 22
	func : func_decl_head compound_stmt .  (32)

	.  reduce 32


state 23
	func_decl_head : ID '(' $$2 . ')'

	')'  shift 75


state 24
	func_decl_head : ID '(' $$1 . param_list ')'

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3

	type  goto 76
	param  goto 77
	param_list  goto 78


state 25
	decl_init : decl_head '=' . init_val

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'{'  shift 79
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	init_val  goto 80
	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 81
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 26
	decl_list : decl_list ',' . decl_init

	ID  shift 82

	decl_head  goto 16
	decl_init  goto 83
	var_decl_head  goto 19


state 27
	decl : type decl_list ';' .  (9)

	.  reduce 9


state 28
	var_decl_head : var_decl_head '[' . const_expr ']'
	var_decl_head : var_decl_head '[' . ']'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	']'  shift 84
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	const_expr  goto 86
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 29
	func : type func_decl_head compound_stmt .  (31)

	.  reduce 31


state 30
	unary_op : '!' .  (94)

	.  reduce 94


state 31
	basic_expr : '(' . expr ')'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 87
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 32
	unary_op : '+' .  (91)

	.  reduce 91


state 33
	unary_op : '-' .  (92)

	.  reduce 92


state 34
	expr_stmt : ';' .  (111)

	.  reduce 111


state 35
	compound_stmt : '{' '}' .  (113)

	.  reduce 113


state 36
	unary_op : '~' .  (93)

	.  reduce 93


state 37
	jmp_stmt : RETURN . expr ';'
	jmp_stmt : RETURN . ';'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 88
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 89
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 38
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 90


state 39
	loop_stmt : DO . stmt WHILE '(' expr ')'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 91
	unary_op  goto 73
	unary_expr  goto 74


state 40
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt

	'('  shift 92


state 41
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 93


state 42
	unary_op : INC .  (95)

	.  reduce 95


state 43
	unary_op : DEC .  (96)

	.  reduce 96


state 44
	val : INTVAL .  (97)

	.  reduce 97


state 45
	val : CHARVAL .  (98)

	.  reduce 98


state 46
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (76)

	'='  shift 94
	ADDASSIGN  shift 95
	SUBASSIGN  shift 96
	MULASSIGN  shift 97
	DIVASSIGN  shift 98
	MODASSIGN  shift 99
	ANDASSIGN  shift 100
	ORASSIGN  shift 101
	XORASSIGN  shift 102
	REVASSIGN  shift 103
	LSHIFTASSIGN  shift 104
	RSHIFTASSIGN  shift 105
	.  reduce 76

	assign_op  goto 106


state 47
	assign_expr : const_expr .  (36)

	.  reduce 36


state 48
	stmt_decl_list : decl .  (119)

	.  reduce 119


state 49
	decl : type . decl_list ';'
	decl : type . ';'

	';'  shift 14
	ID  shift 82

	decl_head  goto 16
	decl_list  goto 17
	decl_init  goto 18
	var_decl_head  goto 19


state 50
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : equal_expr .  (49)
	equal_expr : equal_expr . EQ greater_less_expr

	EQ  shift 107
	NE  shift 108
	.  reduce 49


state 51
	stmt : compound_stmt .  (102)

	.  reduce 102


state 52
	or_expr : and_expr .  (41)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 109
	.  reduce 41


state 53
	const_expr : ternary_expr .  (37)

	.  reduce 37


state 54
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	equal_expr : greater_less_expr .  (52)
	greater_less_expr : greater_less_expr . LT shift_expr

	LE  shift 110
	GE  shift 111
	LT  shift 112
	GT  shift 113
	.  reduce 52


state 55
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_and_expr .  (47)

	'&'  shift 114
	.  reduce 47


state 56
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	greater_less_expr : shift_expr .  (57)
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 115
	RSHIFT  shift 116
	.  reduce 57


state 57
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 117
	';'  shift 118


state 58
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr .  (39)
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr

	'?'  shift 119
	OR  shift 120
	.  reduce 39


state 59
	shift_expr : addBack_sub_expr .  (60)
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr

	'+'  shift 121
	'-'  shift 122
	.  reduce 60


state 60
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : bit_or_expr .  (43)

	'|'  shift 123
	.  reduce 43


state 61
	bit_or_expr : bit_xor_expr .  (45)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 124
	.  reduce 45


state 62
	expr : assign_expr .  (34)

	.  reduce 34


state 63
	addBack_sub_expr : mul_div_mod_expr .  (63)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 125
	'*'  shift 126
	'/'  shift 127
	.  reduce 63


state 64
	basic_expr : val .  (77)

	.  reduce 77


state 65
	postfix_expr : basic_expr .  (75)

	.  reduce 75


state 66
	postfix_expr : postfix_expr . INC
	postfix_expr : postfix_expr . '(' ')'
	postfix_expr : postfix_expr . DEC
	postfix_expr : postfix_expr . '[' expr ']'
	postfix_expr : postfix_expr . '(' expr ')'
	unary_expr : postfix_expr .  (69)

	'('  shift 128
	'['  shift 129
	INC  shift 130
	DEC  shift 131
	.  reduce 69


state 67
	stmt : jmp_stmt .  (99)

	.  reduce 99


state 68
	compound_stmt : '{' stmt_decl_list . '}'
	stmt_decl_list : stmt_decl_list . decl
	stmt_decl_list : stmt_decl_list . stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'}'  shift 132
	'~'  shift 36
	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	decl  goto 133
	type  goto 49
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 134
	unary_op  goto 73
	unary_expr  goto 74


state 69
	stmt : loop_stmt .  (100)

	.  reduce 100


state 70
	stmt : expr_stmt .  (101)

	.  reduce 101


state 71
	stmt : conditional_stmt .  (103)

	.  reduce 103


state 72
	stmt_decl_list : stmt .  (118)

	.  reduce 118


state 73
	unary_expr : unary_op . unary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 135


state 74
	mul_div_mod_expr : unary_expr .  (67)

	.  reduce 67


state 75
	func_decl_head : ID '(' $$2 ')' .  (22)

	.  reduce 22


state 76
	param : type . decl_init
	param : type .  (30)

	ID  shift 82
	.  reduce 30

	decl_head  goto 16
	decl_init  goto 136
	var_decl_head  goto 19


state 77
	param_list : param .  (28)

	.  reduce 28


state 78
	param_list : param_list . ',' param
	func_decl_head : ID '(' $$1 param_list . ')'

	')'  shift 137
	','  shift 138


state 79
	init_val : '{' . init_val_list '}'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'{'  shift 79
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	init_val  goto 139
	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	init_val_list  goto 140
	assign_expr  goto 81
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 80
	decl_init : decl_head '=' init_val .  (13)

	.  reduce 13


state 81
	init_val : assign_expr .  (24)

	.  reduce 24


state 82
	var_decl_head : ID .  (18)

	.  reduce 18


state 83
	decl_list : decl_list ',' decl_init .  (11)

	.  reduce 11


state 84
	var_decl_head : var_decl_head '[' ']' .  (17)

	.  reduce 17


state 85
	basic_expr : ID .  (76)

	.  reduce 76


state 86
	var_decl_head : var_decl_head '[' const_expr . ']'

	']'  shift 141


state 87
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 142
	','  shift 117


state 88
	jmp_stmt : RETURN ';' .  (105)

	.  reduce 105


state 89
	expr : expr . ',' assign_expr
	jmp_stmt : RETURN expr . ';'

	','  shift 117
	';'  shift 143


state 90
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 144
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 91
	loop_stmt : DO stmt . WHILE '(' expr ')'

	WHILE  shift 145


state 92
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	expr_stmt  goto 146
	unary_op  goto 73
	unary_expr  goto 74


state 93
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 147
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 94
	assign_op : '=' .  (79)

	.  reduce 79


state 95
	assign_op : ADDASSIGN .  (80)

	.  reduce 80


state 96
	assign_op : SUBASSIGN .  (81)

	.  reduce 81


state 97
	assign_op : MULASSIGN .  (82)

	.  reduce 82


state 98
	assign_op : DIVASSIGN .  (83)

	.  reduce 83


state 99
	assign_op : MODASSIGN .  (84)

	.  reduce 84


state 100
	assign_op : ANDASSIGN .  (85)

	.  reduce 85


state 101
	assign_op : ORASSIGN .  (86)

	.  reduce 86


state 102
	assign_op : XORASSIGN .  (87)

	.  reduce 87


state 103
	assign_op : REVASSIGN .  (88)

	.  reduce 88


state 104
	assign_op : LSHIFTASSIGN .  (89)

	.  reduce 89


state 105
	assign_op : RSHIFTASSIGN .  (90)

	.  reduce 90


state 106
	assign_expr : ID assign_op . assign_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 148
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 107
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	greater_less_expr  goto 149
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 108
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	greater_less_expr  goto 150
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 109
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	bit_or_expr  goto 151
	bit_xor_expr  goto 61
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 110
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	shift_expr  goto 152
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 111
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	shift_expr  goto 153
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 112
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	shift_expr  goto 154
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 113
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	shift_expr  goto 155
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 114
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 156
	greater_less_expr  goto 54
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 115
	shift_expr : shift_expr LSHIFT . addBack_sub_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	addBack_sub_expr  goto 157
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 116
	shift_expr : shift_expr RSHIFT . addBack_sub_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	addBack_sub_expr  goto 158
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 117
	expr : expr ',' . assign_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 159
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 118
	expr_stmt : expr ';' .  (110)

	.  reduce 110


state 119
	ternary_expr : or_expr '?' . ternary_expr ':' ternary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 160
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 120
	or_expr : or_expr OR . and_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	and_expr  goto 161
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 121
	addBack_sub_expr : addBack_sub_expr '+' . mul_div_mod_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	mul_div_mod_expr  goto 162
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 122
	addBack_sub_expr : addBack_sub_expr '-' . mul_div_mod_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	mul_div_mod_expr  goto 163
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 123
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	bit_xor_expr  goto 164
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 124
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	greater_less_expr  goto 54
	bit_and_expr  goto 165
	shift_expr  goto 56
	addBack_sub_expr  goto 59
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 125
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 166


state 126
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 167


state 127
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 168


state 128
	postfix_expr : postfix_expr '(' . ')'
	postfix_expr : postfix_expr '(' . expr ')'

	'!'  shift 30
	'('  shift 31
	')'  shift 169
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 170
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 129
	postfix_expr : postfix_expr '[' . expr ']'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 171
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 130
	postfix_expr : postfix_expr INC .  (73)

	.  reduce 73


state 131
	postfix_expr : postfix_expr DEC .  (74)

	.  reduce 74


state 132
	compound_stmt : '{' stmt_decl_list '}' .  (112)

	.  reduce 112


state 133
	stmt_decl_list : stmt_decl_list decl .  (117)

	.  reduce 117


state 134
	stmt_decl_list : stmt_decl_list stmt .  (116)

	.  reduce 116


state 135
	unary_expr : unary_op unary_expr .  (68)

	.  reduce 68


state 136
	param : type decl_init .  (29)

	.  reduce 29


state 137
	func_decl_head : ID '(' $$1 param_list ')' .  (20)

	.  reduce 20


state 138
	param_list : param_list ',' . param

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3

	type  goto 76
	param  goto 172


state 139
	init_val_list : init_val .  (26)

	.  reduce 26


state 140
	init_val : '{' init_val_list . '}'
	init_val_list : init_val_list . ',' init_val

	','  shift 173
	'}'  shift 174


state 141
	var_decl_head : var_decl_head '[' const_expr ']' .  (16)

	.  reduce 16


state 142
	basic_expr : '(' expr ')' .  (78)

	.  reduce 78


state 143
	jmp_stmt : RETURN expr ';' .  (104)

	.  reduce 104


state 144
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 175
	','  shift 117


state 145
	loop_stmt : DO stmt WHILE . '(' expr ')'

	'('  shift 176


state 146
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	expr_stmt  goto 177
	unary_op  goto 73
	unary_expr  goto 74


state 147
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 178
	','  shift 117


state 148
	assign_expr : ID assign_op assign_expr .  (35)

	.  reduce 35


state 149
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	equal_expr : equal_expr EQ greater_less_expr .  (50)

	LE  shift 110
	GE  shift 111
	LT  shift 112
	GT  shift 113
	.  reduce 50


state 150
	equal_expr : equal_expr NE greater_less_expr .  (51)
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr

	LE  shift 110
	GE  shift 111
	LT  shift 112
	GT  shift 113
	.  reduce 51


state 151
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : and_expr AND bit_or_expr .  (42)

	'|'  shift 123
	.  reduce 42


state 152
	greater_less_expr : greater_less_expr LE shift_expr .  (53)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 115
	RSHIFT  shift 116
	.  reduce 53


state 153
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	greater_less_expr : greater_less_expr GE shift_expr .  (54)
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 115
	RSHIFT  shift 116
	.  reduce 54


state 154
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	greater_less_expr : greater_less_expr LT shift_expr .  (55)
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 115
	RSHIFT  shift 116
	.  reduce 55


state 155
	greater_less_expr : greater_less_expr GT shift_expr .  (56)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 115
	RSHIFT  shift 116
	.  reduce 56


state 156
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : bit_and_expr '&' equal_expr .  (48)
	equal_expr : equal_expr . EQ greater_less_expr

	EQ  shift 107
	NE  shift 108
	.  reduce 48


state 157
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr
	shift_expr : shift_expr LSHIFT addBack_sub_expr .  (58)

	'+'  shift 121
	'-'  shift 122
	.  reduce 58


state 158
	shift_expr : shift_expr RSHIFT addBack_sub_expr .  (59)
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr

	'+'  shift 121
	'-'  shift 122
	.  reduce 59


state 159
	expr : expr ',' assign_expr .  (33)

	.  reduce 33


state 160
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 179


state 161
	or_expr : or_expr OR and_expr .  (40)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 109
	.  reduce 40


state 162
	addBack_sub_expr : addBack_sub_expr '+' mul_div_mod_expr .  (61)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 125
	'*'  shift 126
	'/'  shift 127
	.  reduce 61


state 163
	addBack_sub_expr : addBack_sub_expr '-' mul_div_mod_expr .  (62)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 125
	'*'  shift 126
	'/'  shift 127
	.  reduce 62


state 164
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (44)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 124
	.  reduce 44


state 165
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (46)

	'&'  shift 114
	.  reduce 46


state 166
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (66)

	.  reduce 66


state 167
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (64)

	.  reduce 64


state 168
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (65)

	.  reduce 65


state 169
	postfix_expr : postfix_expr '(' ')' .  (72)

	.  reduce 72


state 170
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '(' expr . ')'

	')'  shift 180
	','  shift 117


state 171
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '[' expr . ']'

	','  shift 117
	']'  shift 181


state 172
	param_list : param_list ',' param .  (27)

	.  reduce 27


state 173
	init_val_list : init_val_list ',' . init_val

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'{'  shift 79
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	init_val  goto 182
	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 81
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 174
	init_val : '{' init_val_list '}' .  (23)

	.  reduce 23


state 175
	loop_stmt : WHILE '(' expr ')' . stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 183
	unary_op  goto 73
	unary_expr  goto 74


state 176
	loop_stmt : DO stmt WHILE '(' . expr ')'

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 184
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 177
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt

	'!'  shift 30
	'('  shift 31
	')'  shift 185
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 186
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 178
	conditional_stmt : IF '(' expr ')' . stmt
	conditional_stmt : IF '(' expr ')' . stmt ELSE stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 187
	unary_op  goto 73
	unary_expr  goto 74


state 179
	ternary_expr : or_expr '?' ternary_expr ':' . ternary_expr

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	'~'  shift 36
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 85

	equal_expr  goto 50
	and_expr  goto 52
	ternary_expr  goto 188
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	unary_op  goto 73
	unary_expr  goto 74


state 180
	postfix_expr : postfix_expr '(' expr ')' .  (71)

	.  reduce 71


state 181
	postfix_expr : postfix_expr '[' expr ']' .  (70)

	.  reduce 70


state 182
	init_val_list : init_val_list ',' init_val .  (25)

	.  reduce 25


state 183
	loop_stmt : WHILE '(' expr ')' stmt .  (106)

	.  reduce 106


state 184
	expr : expr . ',' assign_expr
	loop_stmt : DO stmt WHILE '(' expr . ')'

	')'  shift 189
	','  shift 117


state 185
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' . stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 190
	unary_op  goto 73
	unary_expr  goto 74


state 186
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 191
	','  shift 117


state 187
	conditional_stmt : IF '(' expr ')' stmt .  (115)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 192
	.  reduce 115


state 188
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (38)

	.  reduce 38


state 189
	loop_stmt : DO stmt WHILE '(' expr ')' .  (107)

	.  reduce 107


state 190
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (109)

	.  reduce 109


state 191
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' . stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 193
	unary_op  goto 73
	unary_expr  goto 74


state 192
	conditional_stmt : IF '(' expr ')' stmt ELSE . stmt

	'!'  shift 30
	'('  shift 31
	'+'  shift 32
	'-'  shift 33
	';'  shift 34
	'{'  shift 21
	'~'  shift 36
	RETURN  shift 37
	WHILE  shift 38
	DO  shift 39
	FOR  shift 40
	IF  shift 41
	INC  shift 42
	DEC  shift 43
	INTVAL  shift 44
	CHARVAL  shift 45
	ID  shift 46

	const_expr  goto 47
	equal_expr  goto 50
	compound_stmt  goto 51
	and_expr  goto 52
	ternary_expr  goto 53
	greater_less_expr  goto 54
	bit_and_expr  goto 55
	shift_expr  goto 56
	expr  goto 57
	or_expr  goto 58
	addBack_sub_expr  goto 59
	bit_or_expr  goto 60
	bit_xor_expr  goto 61
	assign_expr  goto 62
	mul_div_mod_expr  goto 63
	val  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	jmp_stmt  goto 67
	loop_stmt  goto 69
	expr_stmt  goto 70
	conditional_stmt  goto 71
	stmt  goto 194
	unary_op  goto 73
	unary_expr  goto 74


state 193
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (108)

	.  reduce 108


state 194
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (114)

	.  reduce 114


##############################################################################
# Summary
##############################################################################

59 token(s), 45 nonterminal(s)
120 grammar rule(s), 195 state(s)


##############################################################################
# End of File
##############################################################################
