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
# Time: 22:52:19
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

   58  shift_expr : shift_expr LSHIFT add_sub_expr
   59             | shift_expr RSHIFT add_sub_expr
   60             | add_sub_expr

   61  add_sub_expr : add_sub_expr '+' mul_div_mod_expr
   62               | add_sub_expr '-' mul_div_mod_expr
   63               | mul_div_mod_expr

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

	func_decl_head  goto 5
	func  goto 6
	decl  goto 7
	block  goto 8
	type  goto 9
	blocks  goto 10
	program  goto 11


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
	func_decl_head : ID . '(' $$2 ')'
	func_decl_head : ID . '(' $$1 param_list ')'

	'('  shift 12


state 5
	func : func_decl_head . compound_stmt

	'{'  shift 13

	compound_stmt  goto 14


state 6
	block : func .  (5)

	.  reduce 5


state 7
	block : decl .  (4)

	.  reduce 4


state 8
	blocks : block .  (3)

	.  reduce 3


state 9
	func : type . func_decl_head compound_stmt
	decl : type . decl_list ';'
	decl : type . ';'

	';'  shift 15
	ID  shift 16

	func_decl_head  goto 17
	decl_init  goto 18
	decl_list  goto 19
	decl_head  goto 20
	var_decl_head  goto 21


state 10
	program : blocks .  (1)
	blocks : blocks . block

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	ID  shift 4
	.  reduce 1

	func_decl_head  goto 5
	func  goto 6
	decl  goto 7
	block  goto 22
	type  goto 9


state 11
	$accept : program . $end  (0)

	$end  accept


state 12
	func_decl_head : ID '(' . $$2 ')'
	func_decl_head : ID '(' . $$1 param_list ')'
	$$1 : .  (19)
	$$2 : .  (21)

	')'  reduce 21
	.  reduce 19

	$$1  goto 23
	$$2  goto 24


state 13
	compound_stmt : '{' . stmt_decl_list '}'
	compound_stmt : '{' . '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'}'  shift 30
	'~'  shift 31
	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 62
	stmt_decl_list  goto 63
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67
	decl  goto 68
	type  goto 69


state 14
	func : func_decl_head compound_stmt .  (32)

	.  reduce 32


state 15
	decl : type ';' .  (10)

	.  reduce 10


state 16
	func_decl_head : ID . '(' $$2 ')'
	func_decl_head : ID . '(' $$1 param_list ')'
	var_decl_head : ID .  (18)

	'('  shift 12
	.  reduce 18


state 17
	func : type func_decl_head . compound_stmt

	'{'  shift 13

	compound_stmt  goto 70


state 18
	decl_list : decl_init .  (12)

	.  reduce 12


state 19
	decl : type decl_list . ';'
	decl_list : decl_list . ',' decl_init

	','  shift 71
	';'  shift 72


state 20
	decl_init : decl_head . '=' init_val
	decl_init : decl_head .  (14)

	'='  shift 73
	.  reduce 14


state 21
	var_decl_head : var_decl_head . '[' ']'
	decl_head : var_decl_head .  (15)
	var_decl_head : var_decl_head . '[' const_expr ']'

	'['  shift 74
	.  reduce 15


state 22
	blocks : blocks block .  (2)

	.  reduce 2


state 23
	func_decl_head : ID '(' $$1 . param_list ')'

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3

	param  goto 75
	param_list  goto 76
	type  goto 77


state 24
	func_decl_head : ID '(' $$2 . ')'

	')'  shift 78


state 25
	unary_op : '!' .  (94)

	.  reduce 94


state 26
	basic_expr : '(' . expr ')'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 79
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 27
	unary_op : '+' .  (91)

	.  reduce 91


state 28
	unary_op : '-' .  (92)

	.  reduce 92


state 29
	expr_stmt : ';' .  (111)

	.  reduce 111


state 30
	compound_stmt : '{' '}' .  (113)

	.  reduce 113


state 31
	unary_op : '~' .  (93)

	.  reduce 93


state 32
	jmp_stmt : RETURN . expr ';'
	jmp_stmt : RETURN . ';'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 80
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 81
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 33
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 82


state 34
	loop_stmt : DO . stmt WHILE '(' expr ')'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 83
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 35
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt

	'('  shift 84


state 36
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 85


state 37
	unary_op : INC .  (95)

	.  reduce 95


state 38
	unary_op : DEC .  (96)

	.  reduce 96


state 39
	val : INTVAL .  (97)

	.  reduce 97


state 40
	val : CHARVAL .  (98)

	.  reduce 98


state 41
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (76)

	'='  shift 86
	ADDASSIGN  shift 87
	SUBASSIGN  shift 88
	MULASSIGN  shift 89
	DIVASSIGN  shift 90
	MODASSIGN  shift 91
	ANDASSIGN  shift 92
	ORASSIGN  shift 93
	XORASSIGN  shift 94
	REVASSIGN  shift 95
	LSHIFTASSIGN  shift 96
	RSHIFTASSIGN  shift 97
	.  reduce 76

	assign_op  goto 98


state 42
	const_expr : ternary_expr .  (37)

	.  reduce 37


state 43
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr .  (39)
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr

	'?'  shift 99
	OR  shift 100
	.  reduce 39


state 44
	expr : assign_expr .  (34)

	.  reduce 34


state 45
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 101
	';'  shift 102


state 46
	stmt : compound_stmt .  (102)

	.  reduce 102


state 47
	bit_or_expr : bit_xor_expr .  (45)
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr

	'^'  shift 103
	.  reduce 45


state 48
	or_expr : and_expr .  (41)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 104
	.  reduce 41


state 49
	and_expr : bit_or_expr .  (43)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 105
	.  reduce 43


state 50
	greater_less_expr : shift_expr .  (57)
	shift_expr : shift_expr . RSHIFT add_sub_expr
	shift_expr : shift_expr . LSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 57


state 51
	shift_expr : add_sub_expr .  (60)
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr

	'+'  shift 108
	'-'  shift 109
	.  reduce 60


state 52
	bit_xor_expr : bit_and_expr .  (47)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 110
	.  reduce 47


state 53
	bit_and_expr : equal_expr .  (49)
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr

	EQ  shift 111
	NE  shift 112
	.  reduce 49


state 54
	greater_less_expr : greater_less_expr . LE shift_expr
	equal_expr : greater_less_expr .  (52)
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 113
	GE  shift 114
	LT  shift 115
	GT  shift 116
	.  reduce 52


state 55
	basic_expr : val .  (77)

	.  reduce 77


state 56
	unary_expr : unary_op . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 118
	basic_expr  goto 65
	postfix_expr  goto 66


state 57
	stmt : jmp_stmt .  (99)

	.  reduce 99


state 58
	stmt : loop_stmt .  (100)

	.  reduce 100


state 59
	stmt : conditional_stmt .  (103)

	.  reduce 103


state 60
	mul_div_mod_expr : unary_expr .  (67)

	.  reduce 67


state 61
	stmt : expr_stmt .  (101)

	.  reduce 101


state 62
	stmt_decl_list : stmt .  (118)

	.  reduce 118


state 63
	compound_stmt : '{' stmt_decl_list . '}'
	stmt_decl_list : stmt_decl_list . decl
	stmt_decl_list : stmt_decl_list . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'}'  shift 119
	'~'  shift 31
	VOID  shift 1
	INT  shift 2
	CHAR  shift 3
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 120
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67
	decl  goto 121
	type  goto 69


state 64
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	add_sub_expr : mul_div_mod_expr .  (63)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 122
	'*'  shift 123
	'/'  shift 124
	.  reduce 63


state 65
	postfix_expr : basic_expr .  (75)

	.  reduce 75


state 66
	postfix_expr : postfix_expr . '[' expr ']'
	postfix_expr : postfix_expr . '(' ')'
	postfix_expr : postfix_expr . DEC
	unary_expr : postfix_expr .  (69)
	postfix_expr : postfix_expr . '(' expr ')'
	postfix_expr : postfix_expr . INC

	'('  shift 125
	'['  shift 126
	INC  shift 127
	DEC  shift 128
	.  reduce 69


state 67
	assign_expr : const_expr .  (36)

	.  reduce 36


state 68
	stmt_decl_list : decl .  (119)

	.  reduce 119


state 69
	decl : type . decl_list ';'
	decl : type . ';'

	';'  shift 15
	ID  shift 129

	decl_init  goto 18
	decl_list  goto 19
	decl_head  goto 20
	var_decl_head  goto 21


state 70
	func : type func_decl_head compound_stmt .  (31)

	.  reduce 31


state 71
	decl_list : decl_list ',' . decl_init

	ID  shift 129

	decl_init  goto 130
	decl_head  goto 20
	var_decl_head  goto 21


state 72
	decl : type decl_list ';' .  (9)

	.  reduce 9


state 73
	decl_init : decl_head '=' . init_val

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'{'  shift 131
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 132
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67
	init_val  goto 133


state 74
	var_decl_head : var_decl_head '[' . ']'
	var_decl_head : var_decl_head '[' . const_expr ']'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	']'  shift 134
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	ternary_expr  goto 42
	or_expr  goto 43
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 135


state 75
	param_list : param .  (28)

	.  reduce 28


state 76
	func_decl_head : ID '(' $$1 param_list . ')'
	param_list : param_list . ',' param

	')'  shift 136
	','  shift 137


state 77
	param : type .  (30)
	param : type . decl_init

	ID  shift 129
	.  reduce 30

	decl_init  goto 138
	decl_head  goto 20
	var_decl_head  goto 21


state 78
	func_decl_head : ID '(' $$2 ')' .  (22)

	.  reduce 22


state 79
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 139
	','  shift 101


state 80
	jmp_stmt : RETURN ';' .  (105)

	.  reduce 105


state 81
	expr : expr . ',' assign_expr
	jmp_stmt : RETURN expr . ';'

	','  shift 101
	';'  shift 140


state 82
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 141
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 83
	loop_stmt : DO stmt . WHILE '(' expr ')'

	WHILE  shift 142


state 84
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	expr_stmt  goto 143
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 85
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 144
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 86
	assign_op : '=' .  (79)

	.  reduce 79


state 87
	assign_op : ADDASSIGN .  (80)

	.  reduce 80


state 88
	assign_op : SUBASSIGN .  (81)

	.  reduce 81


state 89
	assign_op : MULASSIGN .  (82)

	.  reduce 82


state 90
	assign_op : DIVASSIGN .  (83)

	.  reduce 83


state 91
	assign_op : MODASSIGN .  (84)

	.  reduce 84


state 92
	assign_op : ANDASSIGN .  (85)

	.  reduce 85


state 93
	assign_op : ORASSIGN .  (86)

	.  reduce 86


state 94
	assign_op : XORASSIGN .  (87)

	.  reduce 87


state 95
	assign_op : REVASSIGN .  (88)

	.  reduce 88


state 96
	assign_op : LSHIFTASSIGN .  (89)

	.  reduce 89


state 97
	assign_op : RSHIFTASSIGN .  (90)

	.  reduce 90


state 98
	assign_expr : ID assign_op . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 145
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 99
	ternary_expr : or_expr '?' . ternary_expr ':' ternary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	ternary_expr  goto 146
	or_expr  goto 43
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 100
	or_expr : or_expr OR . and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	bit_xor_expr  goto 47
	and_expr  goto 147
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 101
	expr : expr ',' . assign_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 148
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 102
	expr_stmt : expr ';' .  (110)

	.  reduce 110


state 103
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 149
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 104
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	bit_xor_expr  goto 47
	bit_or_expr  goto 150
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 105
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	bit_xor_expr  goto 151
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 106
	shift_expr : shift_expr LSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	add_sub_expr  goto 152
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 107
	shift_expr : shift_expr RSHIFT . add_sub_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	add_sub_expr  goto 153
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 108
	add_sub_expr : add_sub_expr '+' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 154
	basic_expr  goto 65
	postfix_expr  goto 66


state 109
	add_sub_expr : add_sub_expr '-' . mul_div_mod_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 155
	basic_expr  goto 65
	postfix_expr  goto 66


state 110
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 50
	add_sub_expr  goto 51
	equal_expr  goto 156
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 111
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 50
	add_sub_expr  goto 51
	greater_less_expr  goto 157
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 112
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 50
	add_sub_expr  goto 51
	greater_less_expr  goto 158
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 113
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 159
	add_sub_expr  goto 51
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 114
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 160
	add_sub_expr  goto 51
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 115
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 161
	add_sub_expr  goto 51
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 116
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	shift_expr  goto 162
	add_sub_expr  goto 51
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 117
	basic_expr : ID .  (76)

	.  reduce 76


state 118
	unary_expr : unary_op unary_expr .  (68)

	.  reduce 68


state 119
	compound_stmt : '{' stmt_decl_list '}' .  (112)

	.  reduce 112


state 120
	stmt_decl_list : stmt_decl_list stmt .  (116)

	.  reduce 116


state 121
	stmt_decl_list : stmt_decl_list decl .  (117)

	.  reduce 117


state 122
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 163
	basic_expr  goto 65
	postfix_expr  goto 66


state 123
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 164
	basic_expr  goto 65
	postfix_expr  goto 66


state 124
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	val  goto 55
	unary_op  goto 56
	unary_expr  goto 165
	basic_expr  goto 65
	postfix_expr  goto 66


state 125
	postfix_expr : postfix_expr '(' . ')'
	postfix_expr : postfix_expr '(' . expr ')'

	'!'  shift 25
	'('  shift 26
	')'  shift 166
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 167
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 126
	postfix_expr : postfix_expr '[' . expr ']'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 168
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 127
	postfix_expr : postfix_expr INC .  (73)

	.  reduce 73


state 128
	postfix_expr : postfix_expr DEC .  (74)

	.  reduce 74


state 129
	var_decl_head : ID .  (18)

	.  reduce 18


state 130
	decl_list : decl_list ',' decl_init .  (11)

	.  reduce 11


state 131
	init_val : '{' . init_val_list '}'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'{'  shift 131
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 132
	init_val_list  goto 169
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67
	init_val  goto 170


state 132
	init_val : assign_expr .  (24)

	.  reduce 24


state 133
	decl_init : decl_head '=' init_val .  (13)

	.  reduce 13


state 134
	var_decl_head : var_decl_head '[' ']' .  (17)

	.  reduce 17


state 135
	var_decl_head : var_decl_head '[' const_expr . ']'

	']'  shift 171


state 136
	func_decl_head : ID '(' $$1 param_list ')' .  (20)

	.  reduce 20


state 137
	param_list : param_list ',' . param

	VOID  shift 1
	INT  shift 2
	CHAR  shift 3

	param  goto 172
	type  goto 77


state 138
	param : type decl_init .  (29)

	.  reduce 29


state 139
	basic_expr : '(' expr ')' .  (78)

	.  reduce 78


state 140
	jmp_stmt : RETURN expr ';' .  (104)

	.  reduce 104


state 141
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 173
	','  shift 101


state 142
	loop_stmt : DO stmt WHILE . '(' expr ')'

	'('  shift 174


state 143
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	expr_stmt  goto 175
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 144
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 176
	','  shift 101


state 145
	assign_expr : ID assign_op assign_expr .  (35)

	.  reduce 35


state 146
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 177


state 147
	or_expr : or_expr OR and_expr .  (40)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 104
	.  reduce 40


state 148
	expr : expr ',' assign_expr .  (33)

	.  reduce 33


state 149
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (46)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 110
	.  reduce 46


state 150
	bit_or_expr : bit_or_expr . '|' bit_xor_expr
	and_expr : and_expr AND bit_or_expr .  (42)

	'|'  shift 105
	.  reduce 42


state 151
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (44)

	'^'  shift 103
	.  reduce 44


state 152
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr
	shift_expr : shift_expr LSHIFT add_sub_expr .  (58)

	'+'  shift 108
	'-'  shift 109
	.  reduce 58


state 153
	shift_expr : shift_expr RSHIFT add_sub_expr .  (59)
	add_sub_expr : add_sub_expr . '+' mul_div_mod_expr
	add_sub_expr : add_sub_expr . '-' mul_div_mod_expr

	'+'  shift 108
	'-'  shift 109
	.  reduce 59


state 154
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	add_sub_expr : add_sub_expr '+' mul_div_mod_expr .  (61)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 122
	'*'  shift 123
	'/'  shift 124
	.  reduce 61


state 155
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr
	add_sub_expr : add_sub_expr '-' mul_div_mod_expr .  (62)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr

	'%'  shift 122
	'*'  shift 123
	'/'  shift 124
	.  reduce 62


state 156
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : bit_and_expr '&' equal_expr .  (48)

	EQ  shift 111
	NE  shift 112
	.  reduce 48


state 157
	greater_less_expr : greater_less_expr . LE shift_expr
	equal_expr : equal_expr EQ greater_less_expr .  (50)
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 113
	GE  shift 114
	LT  shift 115
	GT  shift 116
	.  reduce 50


state 158
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	greater_less_expr : greater_less_expr . LT shift_expr
	equal_expr : equal_expr NE greater_less_expr .  (51)
	greater_less_expr : greater_less_expr . GT shift_expr

	LE  shift 113
	GE  shift 114
	LT  shift 115
	GT  shift 116
	.  reduce 51


state 159
	greater_less_expr : greater_less_expr LE shift_expr .  (53)
	shift_expr : shift_expr . RSHIFT add_sub_expr
	shift_expr : shift_expr . LSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 53


state 160
	greater_less_expr : greater_less_expr GE shift_expr .  (54)
	shift_expr : shift_expr . RSHIFT add_sub_expr
	shift_expr : shift_expr . LSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 54


state 161
	greater_less_expr : greater_less_expr LT shift_expr .  (55)
	shift_expr : shift_expr . RSHIFT add_sub_expr
	shift_expr : shift_expr . LSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 55


state 162
	greater_less_expr : greater_less_expr GT shift_expr .  (56)
	shift_expr : shift_expr . RSHIFT add_sub_expr
	shift_expr : shift_expr . LSHIFT add_sub_expr

	LSHIFT  shift 106
	RSHIFT  shift 107
	.  reduce 56


state 163
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (66)

	.  reduce 66


state 164
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (64)

	.  reduce 64


state 165
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (65)

	.  reduce 65


state 166
	postfix_expr : postfix_expr '(' ')' .  (72)

	.  reduce 72


state 167
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '(' expr . ')'

	')'  shift 178
	','  shift 101


state 168
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '[' expr . ']'

	','  shift 101
	']'  shift 179


state 169
	init_val : '{' init_val_list . '}'
	init_val_list : init_val_list . ',' init_val

	','  shift 180
	'}'  shift 181


state 170
	init_val_list : init_val .  (26)

	.  reduce 26


state 171
	var_decl_head : var_decl_head '[' const_expr ']' .  (16)

	.  reduce 16


state 172
	param_list : param_list ',' param .  (27)

	.  reduce 27


state 173
	loop_stmt : WHILE '(' expr ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 182
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 174
	loop_stmt : DO stmt WHILE '(' . expr ')'

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 183
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 175
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt

	'!'  shift 25
	'('  shift 26
	')'  shift 184
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 185
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 176
	conditional_stmt : IF '(' expr ')' . stmt
	conditional_stmt : IF '(' expr ')' . stmt ELSE stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 186
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 177
	ternary_expr : or_expr '?' ternary_expr ':' . ternary_expr

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 117

	ternary_expr  goto 187
	or_expr  goto 43
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66


state 178
	postfix_expr : postfix_expr '(' expr ')' .  (71)

	.  reduce 71


state 179
	postfix_expr : postfix_expr '[' expr ']' .  (70)

	.  reduce 70


state 180
	init_val_list : init_val_list ',' . init_val

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	'{'  shift 131
	'~'  shift 31
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 132
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	unary_expr  goto 60
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67
	init_val  goto 188


state 181
	init_val : '{' init_val_list '}' .  (23)

	.  reduce 23


state 182
	loop_stmt : WHILE '(' expr ')' stmt .  (106)

	.  reduce 106


state 183
	expr : expr . ',' assign_expr
	loop_stmt : DO stmt WHILE '(' expr . ')'

	')'  shift 189
	','  shift 101


state 184
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 190
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 185
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 191
	','  shift 101


state 186
	conditional_stmt : IF '(' expr ')' stmt .  (115)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 192
	.  reduce 115


state 187
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (38)

	.  reduce 38


state 188
	init_val_list : init_val_list ',' init_val .  (25)

	.  reduce 25


state 189
	loop_stmt : DO stmt WHILE '(' expr ')' .  (107)

	.  reduce 107


state 190
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (109)

	.  reduce 109


state 191
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 193
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


state 192
	conditional_stmt : IF '(' expr ')' stmt ELSE . stmt

	'!'  shift 25
	'('  shift 26
	'+'  shift 27
	'-'  shift 28
	';'  shift 29
	'{'  shift 13
	'~'  shift 31
	RETURN  shift 32
	WHILE  shift 33
	DO  shift 34
	FOR  shift 35
	IF  shift 36
	INC  shift 37
	DEC  shift 38
	INTVAL  shift 39
	CHARVAL  shift 40
	ID  shift 41

	ternary_expr  goto 42
	or_expr  goto 43
	assign_expr  goto 44
	expr  goto 45
	compound_stmt  goto 46
	bit_xor_expr  goto 47
	and_expr  goto 48
	bit_or_expr  goto 49
	shift_expr  goto 50
	add_sub_expr  goto 51
	bit_and_expr  goto 52
	equal_expr  goto 53
	greater_less_expr  goto 54
	val  goto 55
	unary_op  goto 56
	jmp_stmt  goto 57
	loop_stmt  goto 58
	conditional_stmt  goto 59
	unary_expr  goto 60
	expr_stmt  goto 61
	stmt  goto 194
	mul_div_mod_expr  goto 64
	basic_expr  goto 65
	postfix_expr  goto 66
	const_expr  goto 67


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
