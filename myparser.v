#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 38 of your 30 day trial period.
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
# Date: 12/06/17
# Time: 20:36:14
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
    8       | FLOAT
    9       | DOUBLE
   10       | CHAR
   11       | BOOL
   12       | STRING
   13       | AUTO
   14       | struct_union_type
   15       | enum_type

   16  type_qf_for_sf : CONST
   17                 | VOLATILE

   18  type_qf_for_pt : CONST
   19                 | VOLATILE

   20  struct_union_type : struct_union ID '{' struct_union_decl_list '}'
   21                    | struct_union '{' struct_union_decl_list '}'
   22                    | struct_union ID '{' '}'
   23                    | struct_union '{' '}'
   24                    | struct_union ID

   25  struct_union : STRUCT
   26               | UNION

   27  enum_type : enum ID '{' enum_decl_list '}'
   28            | enum '{' enum_decl_list '}'
   29            | enum ID '{' '}'
   30            | enum '{' '}'
   31            | enum ID

   32  enum : ENUM

   33  pointer : pointer type_qf_for_pt
   34          | pointer '*'
   35          | '*'

   36  decl : decl_sf decl_list ';'
   37       | decl_sf ';'

   38  decl_sf : decl_sf type
   39          | decl_sf type_qf_for_sf
   40          | type
   41          | type_qf_for_sf

   42  decl_list : decl_list ',' decl_init
   43            | decl_init

   44  decl_init : decl_head '=' init_val
   45            | decl_head

   46  decl_head : pointer var_decl_head
   47            | var_decl_head

   48  var_decl_head : var_decl_head '[' const_expr ']'
   49                | var_decl_head '[' ']'
   50                | ID

   51  $$1 :

   52  func_decl_head : ID '(' $$1 param_list ')'

   53  $$2 :

   54  func_decl_head : ID '(' $$2 ')'

   55  init_val : '{' init_val_list '}'
   56           | assign_expr

   57  init_val_list : init_val_list ',' init_val
   58                | init_val

   59  param_list : param_list ',' param
   60             | param

   61  param : decl_sf decl_init
   62        | decl_sf pointer
   63        | decl_sf

   64  struct_union_decl_list : struct_union_decl_list struct_union_decl
   65                         | struct_union_decl

   66  struct_union_decl : decl_sf pointer ID '=' const_expr ';'
   67                    | decl_sf ID '=' const_expr ';'
   68                    | decl_sf pointer ID ':' const_expr ';'
   69                    | decl_sf ID ':' const_expr ';'
   70                    | decl_sf pointer ID ';'
   71                    | decl_sf ID ';'

   72  enum_decl_list : enum_decl_list ',' enum_decl
   73                 | enum_decl

   74  enum_decl : ID '=' const_expr
   75            | ID

   76  func : decl_sf pointer func_decl_head compound_stmt
   77       | decl_sf func_decl_head compound_stmt
   78       | func_decl_head compound_stmt

   79  expr : expr ',' assign_expr
   80       | assign_expr

   81  assign_expr : ID assign_op assign_expr
   82              | const_expr

   83  const_expr : ternary_expr

   84  ternary_expr : or_expr '?' ternary_expr ':' ternary_expr
   85               | or_expr

   86  or_expr : or_expr OR and_expr
   87          | and_expr

   88  and_expr : and_expr AND bit_or_expr
   89           | bit_or_expr

   90  bit_or_expr : bit_or_expr '|' bit_xor_expr
   91              | bit_xor_expr

   92  bit_xor_expr : bit_xor_expr '^' bit_and_expr
   93               | bit_and_expr

   94  bit_and_expr : bit_and_expr '&' equal_expr
   95               | equal_expr

   96  equal_expr : equal_expr EQ greater_less_expr
   97             | equal_expr NE greater_less_expr
   98             | greater_less_expr

   99  greater_less_expr : greater_less_expr LE shift_expr
  100                    | greater_less_expr GE shift_expr
  101                    | greater_less_expr LT shift_expr
  102                    | greater_less_expr GT shift_expr
  103                    | shift_expr

  104  shift_expr : shift_expr LSHIFT addBack_sub_expr
  105             | shift_expr RSHIFT addBack_sub_expr
  106             | addBack_sub_expr

  107  addBack_sub_expr : addBack_sub_expr '+' mul_div_mod_expr
  108                   | addBack_sub_expr '-' mul_div_mod_expr
  109                   | mul_div_mod_expr

  110  mul_div_mod_expr : mul_div_mod_expr '*' unary_expr
  111                   | mul_div_mod_expr '/' unary_expr
  112                   | mul_div_mod_expr '%' unary_expr
  113                   | unary_expr

  114  unary_expr : unary_op cast_expr
  115             | INC unary_expr
  116             | DEC unary_expr
  117             | SIZEOF '(' expr ')'
  118             | SIZEOF '(' type ')'
  119             | postfix_expr

  120  cast_expr : '(' type ')' cast_expr
  121            | unary_expr

  122  postfix_expr : postfix_expr '[' expr ']'
  123               | postfix_expr '(' expr ')'
  124               | postfix_expr '(' ')'
  125               | postfix_expr '.' ID
  126               | postfix_expr PT ID
  127               | postfix_expr INC
  128               | postfix_expr DEC
  129               | basic_expr

  130  basic_expr : ID
  131             | val
  132             | '(' expr ')'

  133  assign_op : '='
  134            | ADDASSIGN
  135            | SUBASSIGN
  136            | MULASSIGN
  137            | DIVASSIGN
  138            | MODASSIGN
  139            | ANDASSIGN
  140            | ORASSIGN
  141            | XORASSIGN
  142            | REVASSIGN
  143            | LSHIFTASSIGN
  144            | RSHIFTASSIGN

  145  unary_op : '*'
  146           | '&'
  147           | '+'
  148           | '-'
  149           | '~'
  150           | '!'

  151  val : INTVAL
  152      | DOUBLEVAL
  153      | BOOLVAL
  154      | CHARVAL
  155      | STRINGVAL

  156  stmt : jmp_stmt
  157       | loop_stmt
  158       | expr_stmt
  159       | label_stmt
  160       | compound_stmt
  161       | conditional_stmt

  162  jmp_stmt : GOTO ID ';'
  163           | BREAK ';'
  164           | CONTINUE ';'
  165           | RETURN expr ';'
  166           | RETURN ';'

  167  loop_stmt : WHILE '(' expr ')' stmt
  168            | DO stmt WHILE '(' expr ')'
  169            | FOR '(' expr_stmt expr_stmt expr ')' stmt
  170            | FOR '(' expr_stmt expr_stmt ')' stmt

  171  expr_stmt : expr ';'
  172            | ';'

  173  label_stmt : CASE const_expr ':' stmt
  174             | DEFAULT ':' stmt
  175             | ID ':' stmt

  176  compound_stmt : '{' stmt_decl_list '}'
  177                | '{' '}'

  178  conditional_stmt : IF '(' expr ')' stmt ELSE stmt
  179                   | IF '(' expr ')' stmt
  180                   | SWITCH '(' expr ')' stmt

  181  stmt_decl_list : stmt_decl_list stmt
  182                 | stmt_decl_list decl
  183                 | stmt
  184                 | decl


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 14

	enum_type  goto 15
	type_qf_for_sf  goto 16
	block  goto 17
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 20
	decl  goto 21
	struct_union  goto 22
	func  goto 23
	type  goto 24
	func_decl_head  goto 25
	blocks  goto 26
	program  goto 27


state 1
	type : VOID .  (6)

	.  reduce 6


state 2
	type : INT .  (7)

	.  reduce 7


state 3
	type : FLOAT .  (8)

	.  reduce 8


state 4
	type : DOUBLE .  (9)

	.  reduce 9


state 5
	type : CHAR .  (10)

	.  reduce 10


state 6
	type : BOOL .  (11)

	.  reduce 11


state 7
	type : STRING .  (12)

	.  reduce 12


state 8
	type : AUTO .  (13)

	.  reduce 13


state 9
	struct_union : STRUCT .  (25)

	.  reduce 25


state 10
	struct_union : UNION .  (26)

	.  reduce 26


state 11
	enum : ENUM .  (32)

	.  reduce 32


state 12
	type_qf_for_sf : CONST .  (16)

	.  reduce 16


state 13
	type_qf_for_sf : VOLATILE .  (17)

	.  reduce 17


state 14
	func_decl_head : ID . '(' $$2 ')'
	func_decl_head : ID . '(' $$1 param_list ')'

	'('  shift 28


state 15
	type : enum_type .  (15)

	.  reduce 15


state 16
	decl_sf : type_qf_for_sf .  (41)

	.  reduce 41


state 17
	blocks : block .  (3)

	.  reduce 3


state 18
	type : struct_union_type .  (14)

	.  reduce 14


state 19
	enum_type : enum . ID
	enum_type : enum . ID '{' enum_decl_list '}'
	enum_type : enum . '{' enum_decl_list '}'
	enum_type : enum . ID '{' '}'
	enum_type : enum . '{' '}'

	'{'  shift 29
	ID  shift 30


state 20
	decl_sf : decl_sf . type
	decl : decl_sf . decl_list ';'
	decl_sf : decl_sf . type_qf_for_sf
	decl : decl_sf . ';'
	func : decl_sf . pointer func_decl_head compound_stmt
	func : decl_sf . func_decl_head compound_stmt

	'*'  shift 31
	';'  shift 32
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 33

	enum_type  goto 15
	type_qf_for_sf  goto 34
	struct_union_type  goto 18
	enum  goto 19
	pointer  goto 35
	struct_union  goto 22
	type  goto 36
	decl_list  goto 37
	decl_init  goto 38
	decl_head  goto 39
	var_decl_head  goto 40
	func_decl_head  goto 41


state 21
	block : decl .  (4)

	.  reduce 4


state 22
	struct_union_type : struct_union . '{' struct_union_decl_list '}'
	struct_union_type : struct_union . '{' '}'
	struct_union_type : struct_union . ID '{' struct_union_decl_list '}'
	struct_union_type : struct_union . ID '{' '}'
	struct_union_type : struct_union . ID

	'{'  shift 42
	ID  shift 43


state 23
	block : func .  (5)

	.  reduce 5


state 24
	decl_sf : type .  (40)

	.  reduce 40


state 25
	func : func_decl_head . compound_stmt

	'{'  shift 44

	compound_stmt  goto 45


state 26
	program : blocks .  (1)
	blocks : blocks . block

	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 14
	.  reduce 1

	enum_type  goto 15
	type_qf_for_sf  goto 16
	block  goto 46
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 20
	decl  goto 21
	struct_union  goto 22
	func  goto 23
	type  goto 24
	func_decl_head  goto 25


state 27
	$accept : program . $end  (0)

	$end  accept


state 28
	func_decl_head : ID '(' . $$2 ')'
	func_decl_head : ID '(' . $$1 param_list ')'
	$$1 : .  (51)
	$$2 : .  (53)

	')'  reduce 53
	.  reduce 51

	$$1  goto 47
	$$2  goto 48


state 29
	enum_type : enum '{' . enum_decl_list '}'
	enum_type : enum '{' . '}'

	'}'  shift 49
	ID  shift 50

	enum_decl_list  goto 51
	enum_decl  goto 52


state 30
	enum_type : enum ID .  (31)
	enum_type : enum ID . '{' enum_decl_list '}'
	enum_type : enum ID . '{' '}'

	'{'  shift 53
	.  reduce 31


state 31
	pointer : '*' .  (35)

	.  reduce 35


state 32
	decl : decl_sf ';' .  (37)

	.  reduce 37


state 33
	func_decl_head : ID . '(' $$2 ')'
	func_decl_head : ID . '(' $$1 param_list ')'
	var_decl_head : ID .  (50)

	'('  shift 28
	.  reduce 50


state 34
	decl_sf : decl_sf type_qf_for_sf .  (39)

	.  reduce 39


state 35
	pointer : pointer . type_qf_for_pt
	decl_head : pointer . var_decl_head
	pointer : pointer . '*'
	func : decl_sf pointer . func_decl_head compound_stmt

	'*'  shift 54
	CONST  shift 55
	VOLATILE  shift 56
	ID  shift 33

	type_qf_for_pt  goto 57
	var_decl_head  goto 58
	func_decl_head  goto 59


state 36
	decl_sf : decl_sf type .  (38)

	.  reduce 38


state 37
	decl_list : decl_list . ',' decl_init
	decl : decl_sf decl_list . ';'

	','  shift 60
	';'  shift 61


state 38
	decl_list : decl_init .  (43)

	.  reduce 43


state 39
	decl_init : decl_head . '=' init_val
	decl_init : decl_head .  (45)

	'='  shift 62
	.  reduce 45


state 40
	var_decl_head : var_decl_head . '[' ']'
	decl_head : var_decl_head .  (47)
	var_decl_head : var_decl_head . '[' const_expr ']'

	'['  shift 63
	.  reduce 47


state 41
	func : decl_sf func_decl_head . compound_stmt

	'{'  shift 44

	compound_stmt  goto 64


state 42
	struct_union_type : struct_union '{' . struct_union_decl_list '}'
	struct_union_type : struct_union '{' . '}'

	'}'  shift 65
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	struct_union_decl_list  goto 66
	enum  goto 19
	decl_sf  goto 67
	struct_union  goto 22
	type  goto 24
	struct_union_decl  goto 68


state 43
	struct_union_type : struct_union ID . '{' struct_union_decl_list '}'
	struct_union_type : struct_union ID . '{' '}'
	struct_union_type : struct_union ID .  (24)

	'{'  shift 69
	.  reduce 24


state 44
	compound_stmt : '{' . '}'
	compound_stmt : '{' . stmt_decl_list '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'}'  shift 77
	'~'  shift 78
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 99
	decl  goto 100
	struct_union  goto 22
	type  goto 24
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	stmt_decl_list  goto 118
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 122
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 45
	func : func_decl_head compound_stmt .  (78)

	.  reduce 78


state 46
	blocks : blocks block .  (2)

	.  reduce 2


state 47
	func_decl_head : ID '(' $$1 . param_list ')'

	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 128
	struct_union  goto 22
	type  goto 24
	param_list  goto 129
	param  goto 130


state 48
	func_decl_head : ID '(' $$2 . ')'

	')'  shift 131


state 49
	enum_type : enum '{' '}' .  (30)

	.  reduce 30


state 50
	enum_decl : ID . '=' const_expr
	enum_decl : ID .  (75)

	'='  shift 132
	.  reduce 75


state 51
	enum_type : enum '{' enum_decl_list . '}'
	enum_decl_list : enum_decl_list . ',' enum_decl

	','  shift 133
	'}'  shift 134


state 52
	enum_decl_list : enum_decl .  (73)

	.  reduce 73


state 53
	enum_type : enum ID '{' . enum_decl_list '}'
	enum_type : enum ID '{' . '}'

	'}'  shift 135
	ID  shift 50

	enum_decl_list  goto 136
	enum_decl  goto 52


state 54
	pointer : pointer '*' .  (34)

	.  reduce 34


state 55
	type_qf_for_pt : CONST .  (18)

	.  reduce 18


state 56
	type_qf_for_pt : VOLATILE .  (19)

	.  reduce 19


state 57
	pointer : pointer type_qf_for_pt .  (33)

	.  reduce 33


state 58
	decl_head : pointer var_decl_head .  (46)
	var_decl_head : var_decl_head . '[' ']'
	var_decl_head : var_decl_head . '[' const_expr ']'

	'['  shift 63
	.  reduce 46


state 59
	func : decl_sf pointer func_decl_head . compound_stmt

	'{'  shift 44

	compound_stmt  goto 137


state 60
	decl_list : decl_list ',' . decl_init

	'*'  shift 31
	ID  shift 138

	pointer  goto 139
	decl_init  goto 140
	decl_head  goto 39
	var_decl_head  goto 40


state 61
	decl : decl_sf decl_list ';' .  (36)

	.  reduce 36


state 62
	decl_init : decl_head '=' . init_val

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 141
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	init_val  goto 143
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 144
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 63
	var_decl_head : var_decl_head '[' . ']'
	var_decl_head : var_decl_head '[' . const_expr ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	']'  shift 145
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 147
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 64
	func : decl_sf func_decl_head compound_stmt .  (77)

	.  reduce 77


state 65
	struct_union_type : struct_union '{' '}' .  (23)

	.  reduce 23


state 66
	struct_union_type : struct_union '{' struct_union_decl_list . '}'
	struct_union_decl_list : struct_union_decl_list . struct_union_decl

	'}'  shift 148
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 67
	struct_union  goto 22
	type  goto 24
	struct_union_decl  goto 149


state 67
	decl_sf : decl_sf . type
	decl_sf : decl_sf . type_qf_for_sf
	struct_union_decl : decl_sf . pointer ID '=' const_expr ';'
	struct_union_decl : decl_sf . pointer ID ':' const_expr ';'
	struct_union_decl : decl_sf . ID '=' const_expr ';'
	struct_union_decl : decl_sf . ID ':' const_expr ';'
	struct_union_decl : decl_sf . pointer ID ';'
	struct_union_decl : decl_sf . ID ';'

	'*'  shift 31
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 150

	enum_type  goto 15
	type_qf_for_sf  goto 34
	struct_union_type  goto 18
	enum  goto 19
	pointer  goto 151
	struct_union  goto 22
	type  goto 36


state 68
	struct_union_decl_list : struct_union_decl .  (65)

	.  reduce 65


state 69
	struct_union_type : struct_union ID '{' . struct_union_decl_list '}'
	struct_union_type : struct_union ID '{' . '}'

	'}'  shift 152
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	struct_union_decl_list  goto 153
	enum  goto 19
	decl_sf  goto 67
	struct_union  goto 22
	type  goto 24
	struct_union_decl  goto 68


state 70
	unary_op : '!' .  (150)

	.  reduce 150


state 71
	unary_op : '&' .  (146)

	.  reduce 146


state 72
	basic_expr : '(' . expr ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 154
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 73
	unary_op : '*' .  (145)

	.  reduce 145


state 74
	unary_op : '+' .  (147)

	.  reduce 147


state 75
	unary_op : '-' .  (148)

	.  reduce 148


state 76
	expr_stmt : ';' .  (172)

	.  reduce 172


state 77
	compound_stmt : '{' '}' .  (177)

	.  reduce 177


state 78
	unary_op : '~' .  (149)

	.  reduce 149


state 79
	unary_expr : SIZEOF . '(' expr ')'
	unary_expr : SIZEOF . '(' type ')'

	'('  shift 155


state 80
	jmp_stmt : GOTO . ID ';'

	ID  shift 156


state 81
	jmp_stmt : BREAK . ';'

	';'  shift 157


state 82
	jmp_stmt : CONTINUE . ';'

	';'  shift 158


state 83
	jmp_stmt : RETURN . expr ';'
	jmp_stmt : RETURN . ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 159
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 160
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 84
	loop_stmt : WHILE . '(' expr ')' stmt

	'('  shift 161


state 85
	loop_stmt : DO . stmt WHILE '(' expr ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 162
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 86
	loop_stmt : FOR . '(' expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR . '(' expr_stmt expr_stmt ')' stmt

	'('  shift 163


state 87
	conditional_stmt : IF . '(' expr ')' stmt
	conditional_stmt : IF . '(' expr ')' stmt ELSE stmt

	'('  shift 164


state 88
	conditional_stmt : SWITCH . '(' expr ')' stmt

	'('  shift 165


state 89
	label_stmt : CASE . const_expr ':' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 166
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 90
	label_stmt : DEFAULT . ':' stmt

	':'  shift 167


state 91
	unary_expr : INC . unary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 168


state 92
	unary_expr : DEC . unary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 169


state 93
	val : INTVAL .  (151)

	.  reduce 151


state 94
	val : DOUBLEVAL .  (152)

	.  reduce 152


state 95
	val : BOOLVAL .  (153)

	.  reduce 153


state 96
	val : CHARVAL .  (154)

	.  reduce 154


state 97
	val : STRINGVAL .  (155)

	.  reduce 155


state 98
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (130)
	label_stmt : ID . ':' stmt

	':'  shift 170
	'='  shift 171
	ADDASSIGN  shift 172
	SUBASSIGN  shift 173
	MULASSIGN  shift 174
	DIVASSIGN  shift 175
	MODASSIGN  shift 176
	ANDASSIGN  shift 177
	ORASSIGN  shift 178
	XORASSIGN  shift 179
	REVASSIGN  shift 180
	LSHIFTASSIGN  shift 181
	RSHIFTASSIGN  shift 182
	.  reduce 130

	assign_op  goto 183


state 99
	decl_sf : decl_sf . type
	decl : decl_sf . decl_list ';'
	decl_sf : decl_sf . type_qf_for_sf
	decl : decl_sf . ';'

	'*'  shift 31
	';'  shift 32
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 138

	enum_type  goto 15
	type_qf_for_sf  goto 34
	struct_union_type  goto 18
	enum  goto 19
	pointer  goto 139
	struct_union  goto 22
	type  goto 36
	decl_list  goto 37
	decl_init  goto 38
	decl_head  goto 39
	var_decl_head  goto 40


state 100
	stmt_decl_list : decl .  (184)

	.  reduce 184


state 101
	assign_expr : const_expr .  (82)

	.  reduce 82


state 102
	ternary_expr : or_expr .  (85)
	or_expr : or_expr . OR and_expr
	ternary_expr : or_expr . '?' ternary_expr ':' ternary_expr

	'?'  shift 184
	OR  shift 185
	.  reduce 85


state 103
	expr : assign_expr .  (80)

	.  reduce 80


state 104
	expr : expr . ',' assign_expr
	expr_stmt : expr . ';'

	','  shift 186
	';'  shift 187


state 105
	or_expr : and_expr .  (87)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 188
	.  reduce 87


state 106
	and_expr : bit_or_expr .  (89)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 189
	.  reduce 89


state 107
	stmt : compound_stmt .  (160)

	.  reduce 160


state 108
	const_expr : ternary_expr .  (83)

	.  reduce 83


state 109
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr
	bit_and_expr : equal_expr .  (95)

	EQ  shift 190
	NE  shift 191
	.  reduce 95


state 110
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	greater_less_expr : greater_less_expr . GE shift_expr
	equal_expr : greater_less_expr .  (98)

	LE  shift 192
	GE  shift 193
	LT  shift 194
	GT  shift 195
	.  reduce 98


state 111
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr
	shift_expr : addBack_sub_expr .  (106)
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr

	'+'  shift 196
	'-'  shift 197
	.  reduce 106


state 112
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr
	bit_or_expr : bit_xor_expr .  (91)

	'^'  shift 198
	.  reduce 91


state 113
	greater_less_expr : shift_expr .  (103)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 199
	RSHIFT  shift 200
	.  reduce 103


state 114
	addBack_sub_expr : mul_div_mod_expr .  (109)
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr

	'%'  shift 201
	'*'  shift 202
	'/'  shift 203
	.  reduce 109


state 115
	bit_and_expr : bit_and_expr . '&' equal_expr
	bit_xor_expr : bit_and_expr .  (93)

	'&'  shift 204
	.  reduce 93


state 116
	stmt : jmp_stmt .  (156)

	.  reduce 156


state 117
	stmt : expr_stmt .  (158)

	.  reduce 158


state 118
	stmt_decl_list : stmt_decl_list . stmt
	compound_stmt : '{' stmt_decl_list . '}'
	stmt_decl_list : stmt_decl_list . decl

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'}'  shift 205
	'~'  shift 78
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 99
	decl  goto 206
	struct_union  goto 22
	type  goto 24
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 207
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 119
	stmt : loop_stmt .  (157)

	.  reduce 157


state 120
	stmt : conditional_stmt .  (161)

	.  reduce 161


state 121
	stmt : label_stmt .  (159)

	.  reduce 159


state 122
	stmt_decl_list : stmt .  (183)

	.  reduce 183


state 123
	postfix_expr : basic_expr .  (129)

	.  reduce 129


state 124
	unary_expr : unary_op . cast_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 208
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	cast_expr  goto 209
	unary_expr  goto 210


state 125
	postfix_expr : postfix_expr . PT ID
	postfix_expr : postfix_expr . '(' expr ')'
	postfix_expr : postfix_expr . '.' ID
	postfix_expr : postfix_expr . '(' ')'
	postfix_expr : postfix_expr . DEC
	postfix_expr : postfix_expr . INC
	unary_expr : postfix_expr .  (119)
	postfix_expr : postfix_expr . '[' expr ']'

	'('  shift 211
	'.'  shift 212
	'['  shift 213
	INC  shift 214
	DEC  shift 215
	PT  shift 216
	.  reduce 119


state 126
	basic_expr : val .  (131)

	.  reduce 131


state 127
	mul_div_mod_expr : unary_expr .  (113)

	.  reduce 113


state 128
	param : decl_sf . pointer
	param : decl_sf .  (63)
	decl_sf : decl_sf . type
	decl_sf : decl_sf . type_qf_for_sf
	param : decl_sf . decl_init

	'*'  shift 31
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13
	ID  shift 138
	.  reduce 63

	enum_type  goto 15
	type_qf_for_sf  goto 34
	struct_union_type  goto 18
	enum  goto 19
	pointer  goto 217
	struct_union  goto 22
	type  goto 36
	decl_init  goto 218
	decl_head  goto 39
	var_decl_head  goto 40


state 129
	func_decl_head : ID '(' $$1 param_list . ')'
	param_list : param_list . ',' param

	')'  shift 219
	','  shift 220


state 130
	param_list : param .  (60)

	.  reduce 60


state 131
	func_decl_head : ID '(' $$2 ')' .  (54)

	.  reduce 54


state 132
	enum_decl : ID '=' . const_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 221
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 133
	enum_decl_list : enum_decl_list ',' . enum_decl

	ID  shift 50

	enum_decl  goto 222


state 134
	enum_type : enum '{' enum_decl_list '}' .  (28)

	.  reduce 28


state 135
	enum_type : enum ID '{' '}' .  (29)

	.  reduce 29


state 136
	enum_type : enum ID '{' enum_decl_list . '}'
	enum_decl_list : enum_decl_list . ',' enum_decl

	','  shift 133
	'}'  shift 223


state 137
	func : decl_sf pointer func_decl_head compound_stmt .  (76)

	.  reduce 76


state 138
	var_decl_head : ID .  (50)

	.  reduce 50


state 139
	pointer : pointer . type_qf_for_pt
	decl_head : pointer . var_decl_head
	pointer : pointer . '*'

	'*'  shift 54
	CONST  shift 55
	VOLATILE  shift 56
	ID  shift 138

	type_qf_for_pt  goto 57
	var_decl_head  goto 58


state 140
	decl_list : decl_list ',' decl_init .  (42)

	.  reduce 42


state 141
	init_val : '{' . init_val_list '}'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 141
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	init_val  goto 224
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 144
	and_expr  goto 105
	bit_or_expr  goto 106
	init_val_list  goto 225
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 142
	assign_expr : ID . assign_op assign_expr
	basic_expr : ID .  (130)

	'='  shift 171
	ADDASSIGN  shift 172
	SUBASSIGN  shift 173
	MULASSIGN  shift 174
	DIVASSIGN  shift 175
	MODASSIGN  shift 176
	ANDASSIGN  shift 177
	ORASSIGN  shift 178
	XORASSIGN  shift 179
	REVASSIGN  shift 180
	LSHIFTASSIGN  shift 181
	RSHIFTASSIGN  shift 182
	.  reduce 130

	assign_op  goto 183


state 143
	decl_init : decl_head '=' init_val .  (44)

	.  reduce 44


state 144
	init_val : assign_expr .  (56)

	.  reduce 56


state 145
	var_decl_head : var_decl_head '[' ']' .  (49)

	.  reduce 49


state 146
	basic_expr : ID .  (130)

	.  reduce 130


state 147
	var_decl_head : var_decl_head '[' const_expr . ']'

	']'  shift 226


state 148
	struct_union_type : struct_union '{' struct_union_decl_list '}' .  (21)

	.  reduce 21


state 149
	struct_union_decl_list : struct_union_decl_list struct_union_decl .  (64)

	.  reduce 64


state 150
	struct_union_decl : decl_sf ID . '=' const_expr ';'
	struct_union_decl : decl_sf ID . ':' const_expr ';'
	struct_union_decl : decl_sf ID . ';'

	':'  shift 227
	';'  shift 228
	'='  shift 229


state 151
	pointer : pointer . type_qf_for_pt
	pointer : pointer . '*'
	struct_union_decl : decl_sf pointer . ID '=' const_expr ';'
	struct_union_decl : decl_sf pointer . ID ':' const_expr ';'
	struct_union_decl : decl_sf pointer . ID ';'

	'*'  shift 54
	CONST  shift 55
	VOLATILE  shift 56
	ID  shift 230

	type_qf_for_pt  goto 57


state 152
	struct_union_type : struct_union ID '{' '}' .  (22)

	.  reduce 22


state 153
	struct_union_type : struct_union ID '{' struct_union_decl_list . '}'
	struct_union_decl_list : struct_union_decl_list . struct_union_decl

	'}'  shift 231
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 67
	struct_union  goto 22
	type  goto 24
	struct_union_decl  goto 149


state 154
	expr : expr . ',' assign_expr
	basic_expr : '(' expr . ')'

	')'  shift 232
	','  shift 186


state 155
	unary_expr : SIZEOF '(' . expr ')'
	unary_expr : SIZEOF '(' . type ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	enum_type  goto 15
	struct_union_type  goto 18
	enum  goto 19
	struct_union  goto 22
	type  goto 233
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 234
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 156
	jmp_stmt : GOTO ID . ';'

	';'  shift 235


state 157
	jmp_stmt : BREAK ';' .  (163)

	.  reduce 163


state 158
	jmp_stmt : CONTINUE ';' .  (164)

	.  reduce 164


state 159
	jmp_stmt : RETURN ';' .  (166)

	.  reduce 166


state 160
	expr : expr . ',' assign_expr
	jmp_stmt : RETURN expr . ';'

	','  shift 186
	';'  shift 236


state 161
	loop_stmt : WHILE '(' . expr ')' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 237
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 162
	loop_stmt : DO stmt . WHILE '(' expr ')'

	WHILE  shift 238


state 163
	loop_stmt : FOR '(' . expr_stmt expr_stmt expr ')' stmt
	loop_stmt : FOR '(' . expr_stmt expr_stmt ')' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	expr_stmt  goto 239
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 164
	conditional_stmt : IF '(' . expr ')' stmt
	conditional_stmt : IF '(' . expr ')' stmt ELSE stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 240
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 165
	conditional_stmt : SWITCH '(' . expr ')' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 241
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 166
	label_stmt : CASE const_expr . ':' stmt

	':'  shift 242


state 167
	label_stmt : DEFAULT ':' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 243
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 168
	unary_expr : INC unary_expr .  (115)

	.  reduce 115


state 169
	unary_expr : DEC unary_expr .  (116)

	.  reduce 116


state 170
	label_stmt : ID ':' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 244
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 171
	assign_op : '=' .  (133)

	.  reduce 133


state 172
	assign_op : ADDASSIGN .  (134)

	.  reduce 134


state 173
	assign_op : SUBASSIGN .  (135)

	.  reduce 135


state 174
	assign_op : MULASSIGN .  (136)

	.  reduce 136


state 175
	assign_op : DIVASSIGN .  (137)

	.  reduce 137


state 176
	assign_op : MODASSIGN .  (138)

	.  reduce 138


state 177
	assign_op : ANDASSIGN .  (139)

	.  reduce 139


state 178
	assign_op : ORASSIGN .  (140)

	.  reduce 140


state 179
	assign_op : XORASSIGN .  (141)

	.  reduce 141


state 180
	assign_op : REVASSIGN .  (142)

	.  reduce 142


state 181
	assign_op : LSHIFTASSIGN .  (143)

	.  reduce 143


state 182
	assign_op : RSHIFTASSIGN .  (144)

	.  reduce 144


state 183
	assign_expr : ID assign_op . assign_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 245
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 184
	ternary_expr : or_expr '?' . ternary_expr ':' ternary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 246
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 185
	or_expr : or_expr OR . and_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	and_expr  goto 247
	bit_or_expr  goto 106
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 186
	expr : expr ',' . assign_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 248
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 187
	expr_stmt : expr ';' .  (171)

	.  reduce 171


state 188
	and_expr : and_expr AND . bit_or_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	bit_or_expr  goto 249
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 189
	bit_or_expr : bit_or_expr '|' . bit_xor_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 250
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 190
	equal_expr : equal_expr EQ . greater_less_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	greater_less_expr  goto 251
	addBack_sub_expr  goto 111
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 191
	equal_expr : equal_expr NE . greater_less_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	greater_less_expr  goto 252
	addBack_sub_expr  goto 111
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 192
	greater_less_expr : greater_less_expr LE . shift_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 111
	shift_expr  goto 253
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 193
	greater_less_expr : greater_less_expr GE . shift_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 111
	shift_expr  goto 254
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 194
	greater_less_expr : greater_less_expr LT . shift_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 111
	shift_expr  goto 255
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 195
	greater_less_expr : greater_less_expr GT . shift_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 111
	shift_expr  goto 256
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 196
	addBack_sub_expr : addBack_sub_expr '+' . mul_div_mod_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	mul_div_mod_expr  goto 257
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 197
	addBack_sub_expr : addBack_sub_expr '-' . mul_div_mod_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	mul_div_mod_expr  goto 258
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 198
	bit_xor_expr : bit_xor_expr '^' . bit_and_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 259
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 199
	shift_expr : shift_expr LSHIFT . addBack_sub_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 260
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 200
	shift_expr : shift_expr RSHIFT . addBack_sub_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	addBack_sub_expr  goto 261
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 201
	mul_div_mod_expr : mul_div_mod_expr '%' . unary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 262


state 202
	mul_div_mod_expr : mul_div_mod_expr '*' . unary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 263


state 203
	mul_div_mod_expr : mul_div_mod_expr '/' . unary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 264


state 204
	bit_and_expr : bit_and_expr '&' . equal_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	equal_expr  goto 265
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 205
	compound_stmt : '{' stmt_decl_list '}' .  (176)

	.  reduce 176


state 206
	stmt_decl_list : stmt_decl_list decl .  (182)

	.  reduce 182


state 207
	stmt_decl_list : stmt_decl_list stmt .  (181)

	.  reduce 181


state 208
	cast_expr : '(' . type ')' cast_expr
	basic_expr : '(' . expr ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	enum_type  goto 15
	struct_union_type  goto 18
	enum  goto 19
	struct_union  goto 22
	type  goto 266
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 154
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 209
	unary_expr : unary_op cast_expr .  (114)

	.  reduce 114


state 210
	cast_expr : unary_expr .  (121)

	.  reduce 121


state 211
	postfix_expr : postfix_expr '(' . expr ')'
	postfix_expr : postfix_expr '(' . ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 267
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 268
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 212
	postfix_expr : postfix_expr '.' . ID

	ID  shift 269


state 213
	postfix_expr : postfix_expr '[' . expr ']'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 270
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 214
	postfix_expr : postfix_expr INC .  (127)

	.  reduce 127


state 215
	postfix_expr : postfix_expr DEC .  (128)

	.  reduce 128


state 216
	postfix_expr : postfix_expr PT . ID

	ID  shift 271


state 217
	pointer : pointer . type_qf_for_pt
	param : decl_sf pointer .  (62)
	decl_head : pointer . var_decl_head
	pointer : pointer . '*'

	'*'  shift 54
	CONST  shift 55
	VOLATILE  shift 56
	ID  shift 138
	.  reduce 62

	type_qf_for_pt  goto 57
	var_decl_head  goto 58


state 218
	param : decl_sf decl_init .  (61)

	.  reduce 61


state 219
	func_decl_head : ID '(' $$1 param_list ')' .  (52)

	.  reduce 52


state 220
	param_list : param_list ',' . param

	VOID  shift 1
	INT  shift 2
	FLOAT  shift 3
	DOUBLE  shift 4
	CHAR  shift 5
	BOOL  shift 6
	STRING  shift 7
	AUTO  shift 8
	STRUCT  shift 9
	UNION  shift 10
	ENUM  shift 11
	CONST  shift 12
	VOLATILE  shift 13

	enum_type  goto 15
	type_qf_for_sf  goto 16
	struct_union_type  goto 18
	enum  goto 19
	decl_sf  goto 128
	struct_union  goto 22
	type  goto 24
	param  goto 272


state 221
	enum_decl : ID '=' const_expr .  (74)

	.  reduce 74


state 222
	enum_decl_list : enum_decl_list ',' enum_decl .  (72)

	.  reduce 72


state 223
	enum_type : enum ID '{' enum_decl_list '}' .  (27)

	.  reduce 27


state 224
	init_val_list : init_val .  (58)

	.  reduce 58


state 225
	init_val_list : init_val_list . ',' init_val
	init_val : '{' init_val_list . '}'

	','  shift 273
	'}'  shift 274


state 226
	var_decl_head : var_decl_head '[' const_expr ']' .  (48)

	.  reduce 48


state 227
	struct_union_decl : decl_sf ID ':' . const_expr ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 275
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 228
	struct_union_decl : decl_sf ID ';' .  (71)

	.  reduce 71


state 229
	struct_union_decl : decl_sf ID '=' . const_expr ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 276
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 230
	struct_union_decl : decl_sf pointer ID . '=' const_expr ';'
	struct_union_decl : decl_sf pointer ID . ':' const_expr ';'
	struct_union_decl : decl_sf pointer ID . ';'

	':'  shift 277
	';'  shift 278
	'='  shift 279


state 231
	struct_union_type : struct_union ID '{' struct_union_decl_list '}' .  (20)

	.  reduce 20


state 232
	basic_expr : '(' expr ')' .  (132)

	.  reduce 132


state 233
	unary_expr : SIZEOF '(' type . ')'

	')'  shift 280


state 234
	expr : expr . ',' assign_expr
	unary_expr : SIZEOF '(' expr . ')'

	')'  shift 281
	','  shift 186


state 235
	jmp_stmt : GOTO ID ';' .  (162)

	.  reduce 162


state 236
	jmp_stmt : RETURN expr ';' .  (165)

	.  reduce 165


state 237
	expr : expr . ',' assign_expr
	loop_stmt : WHILE '(' expr . ')' stmt

	')'  shift 282
	','  shift 186


state 238
	loop_stmt : DO stmt WHILE . '(' expr ')'

	'('  shift 283


state 239
	loop_stmt : FOR '(' expr_stmt . expr_stmt expr ')' stmt
	loop_stmt : FOR '(' expr_stmt . expr_stmt ')' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	expr_stmt  goto 284
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 240
	expr : expr . ',' assign_expr
	conditional_stmt : IF '(' expr . ')' stmt
	conditional_stmt : IF '(' expr . ')' stmt ELSE stmt

	')'  shift 285
	','  shift 186


state 241
	expr : expr . ',' assign_expr
	conditional_stmt : SWITCH '(' expr . ')' stmt

	')'  shift 286
	','  shift 186


state 242
	label_stmt : CASE const_expr ':' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 287
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 243
	label_stmt : DEFAULT ':' stmt .  (174)

	.  reduce 174


state 244
	label_stmt : ID ':' stmt .  (175)

	.  reduce 175


state 245
	assign_expr : ID assign_op assign_expr .  (81)

	.  reduce 81


state 246
	ternary_expr : or_expr '?' ternary_expr . ':' ternary_expr

	':'  shift 288


state 247
	or_expr : or_expr OR and_expr .  (86)
	and_expr : and_expr . AND bit_or_expr

	AND  shift 188
	.  reduce 86


state 248
	expr : expr ',' assign_expr .  (79)

	.  reduce 79


state 249
	and_expr : and_expr AND bit_or_expr .  (88)
	bit_or_expr : bit_or_expr . '|' bit_xor_expr

	'|'  shift 189
	.  reduce 88


state 250
	bit_xor_expr : bit_xor_expr . '^' bit_and_expr
	bit_or_expr : bit_or_expr '|' bit_xor_expr .  (90)

	'^'  shift 198
	.  reduce 90


state 251
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	equal_expr : equal_expr EQ greater_less_expr .  (96)
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 192
	GE  shift 193
	LT  shift 194
	GT  shift 195
	.  reduce 96


state 252
	greater_less_expr : greater_less_expr . LT shift_expr
	greater_less_expr : greater_less_expr . GT shift_expr
	greater_less_expr : greater_less_expr . LE shift_expr
	equal_expr : equal_expr NE greater_less_expr .  (97)
	greater_less_expr : greater_less_expr . GE shift_expr

	LE  shift 192
	GE  shift 193
	LT  shift 194
	GT  shift 195
	.  reduce 97


state 253
	greater_less_expr : greater_less_expr LE shift_expr .  (99)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 199
	RSHIFT  shift 200
	.  reduce 99


state 254
	greater_less_expr : greater_less_expr GE shift_expr .  (100)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 199
	RSHIFT  shift 200
	.  reduce 100


state 255
	greater_less_expr : greater_less_expr LT shift_expr .  (101)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 199
	RSHIFT  shift 200
	.  reduce 101


state 256
	greater_less_expr : greater_less_expr GT shift_expr .  (102)
	shift_expr : shift_expr . RSHIFT addBack_sub_expr
	shift_expr : shift_expr . LSHIFT addBack_sub_expr

	LSHIFT  shift 199
	RSHIFT  shift 200
	.  reduce 102


state 257
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	addBack_sub_expr : addBack_sub_expr '+' mul_div_mod_expr .  (107)
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr

	'%'  shift 201
	'*'  shift 202
	'/'  shift 203
	.  reduce 107


state 258
	mul_div_mod_expr : mul_div_mod_expr . '*' unary_expr
	addBack_sub_expr : addBack_sub_expr '-' mul_div_mod_expr .  (108)
	mul_div_mod_expr : mul_div_mod_expr . '%' unary_expr
	mul_div_mod_expr : mul_div_mod_expr . '/' unary_expr

	'%'  shift 201
	'*'  shift 202
	'/'  shift 203
	.  reduce 108


state 259
	bit_xor_expr : bit_xor_expr '^' bit_and_expr .  (92)
	bit_and_expr : bit_and_expr . '&' equal_expr

	'&'  shift 204
	.  reduce 92


state 260
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr
	shift_expr : shift_expr LSHIFT addBack_sub_expr .  (104)
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr

	'+'  shift 196
	'-'  shift 197
	.  reduce 104


state 261
	shift_expr : shift_expr RSHIFT addBack_sub_expr .  (105)
	addBack_sub_expr : addBack_sub_expr . '-' mul_div_mod_expr
	addBack_sub_expr : addBack_sub_expr . '+' mul_div_mod_expr

	'+'  shift 196
	'-'  shift 197
	.  reduce 105


state 262
	mul_div_mod_expr : mul_div_mod_expr '%' unary_expr .  (112)

	.  reduce 112


state 263
	mul_div_mod_expr : mul_div_mod_expr '*' unary_expr .  (110)

	.  reduce 110


state 264
	mul_div_mod_expr : mul_div_mod_expr '/' unary_expr .  (111)

	.  reduce 111


state 265
	bit_and_expr : bit_and_expr '&' equal_expr .  (94)
	equal_expr : equal_expr . EQ greater_less_expr
	equal_expr : equal_expr . NE greater_less_expr

	EQ  shift 190
	NE  shift 191
	.  reduce 94


state 266
	cast_expr : '(' type . ')' cast_expr

	')'  shift 289


state 267
	postfix_expr : postfix_expr '(' ')' .  (124)

	.  reduce 124


state 268
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '(' expr . ')'

	')'  shift 290
	','  shift 186


state 269
	postfix_expr : postfix_expr '.' ID .  (125)

	.  reduce 125


state 270
	expr : expr . ',' assign_expr
	postfix_expr : postfix_expr '[' expr . ']'

	','  shift 186
	']'  shift 291


state 271
	postfix_expr : postfix_expr PT ID .  (126)

	.  reduce 126


state 272
	param_list : param_list ',' param .  (59)

	.  reduce 59


state 273
	init_val_list : init_val_list ',' . init_val

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'{'  shift 141
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	init_val  goto 292
	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 144
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 274
	init_val : '{' init_val_list '}' .  (55)

	.  reduce 55


state 275
	struct_union_decl : decl_sf ID ':' const_expr . ';'

	';'  shift 293


state 276
	struct_union_decl : decl_sf ID '=' const_expr . ';'

	';'  shift 294


state 277
	struct_union_decl : decl_sf pointer ID ':' . const_expr ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 295
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 278
	struct_union_decl : decl_sf pointer ID ';' .  (70)

	.  reduce 70


state 279
	struct_union_decl : decl_sf pointer ID '=' . const_expr ';'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	const_expr  goto 296
	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 280
	unary_expr : SIZEOF '(' type ')' .  (118)

	.  reduce 118


state 281
	unary_expr : SIZEOF '(' expr ')' .  (117)

	.  reduce 117


state 282
	loop_stmt : WHILE '(' expr ')' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 297
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 283
	loop_stmt : DO stmt WHILE '(' . expr ')'

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 298
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 284
	loop_stmt : FOR '(' expr_stmt expr_stmt . expr ')' stmt
	loop_stmt : FOR '(' expr_stmt expr_stmt . ')' stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	')'  shift 299
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 142

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 300
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 285
	conditional_stmt : IF '(' expr ')' . stmt
	conditional_stmt : IF '(' expr ')' . stmt ELSE stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 301
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 286
	conditional_stmt : SWITCH '(' expr ')' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 302
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 287
	label_stmt : CASE const_expr ':' stmt .  (173)

	.  reduce 173


state 288
	ternary_expr : or_expr '?' ternary_expr ':' . ternary_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	or_expr  goto 102
	and_expr  goto 105
	bit_or_expr  goto 106
	ternary_expr  goto 303
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 289
	cast_expr : '(' type ')' . cast_expr

	'!'  shift 70
	'&'  shift 71
	'('  shift 208
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	'~'  shift 78
	SIZEOF  shift 79
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 146

	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	cast_expr  goto 304
	unary_expr  goto 210


state 290
	postfix_expr : postfix_expr '(' expr ')' .  (123)

	.  reduce 123


state 291
	postfix_expr : postfix_expr '[' expr ']' .  (122)

	.  reduce 122


state 292
	init_val_list : init_val_list ',' init_val .  (57)

	.  reduce 57


state 293
	struct_union_decl : decl_sf ID ':' const_expr ';' .  (69)

	.  reduce 69


state 294
	struct_union_decl : decl_sf ID '=' const_expr ';' .  (67)

	.  reduce 67


state 295
	struct_union_decl : decl_sf pointer ID ':' const_expr . ';'

	';'  shift 305


state 296
	struct_union_decl : decl_sf pointer ID '=' const_expr . ';'

	';'  shift 306


state 297
	loop_stmt : WHILE '(' expr ')' stmt .  (167)

	.  reduce 167


state 298
	expr : expr . ',' assign_expr
	loop_stmt : DO stmt WHILE '(' expr . ')'

	')'  shift 307
	','  shift 186


state 299
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 308
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 300
	expr : expr . ',' assign_expr
	loop_stmt : FOR '(' expr_stmt expr_stmt expr . ')' stmt

	')'  shift 309
	','  shift 186


state 301
	conditional_stmt : IF '(' expr ')' stmt .  (179)
	conditional_stmt : IF '(' expr ')' stmt . ELSE stmt

	ELSE  shift 310
	.  reduce 179


state 302
	conditional_stmt : SWITCH '(' expr ')' stmt .  (180)

	.  reduce 180


state 303
	ternary_expr : or_expr '?' ternary_expr ':' ternary_expr .  (84)

	.  reduce 84


state 304
	cast_expr : '(' type ')' cast_expr .  (120)

	.  reduce 120


state 305
	struct_union_decl : decl_sf pointer ID ':' const_expr ';' .  (68)

	.  reduce 68


state 306
	struct_union_decl : decl_sf pointer ID '=' const_expr ';' .  (66)

	.  reduce 66


state 307
	loop_stmt : DO stmt WHILE '(' expr ')' .  (168)

	.  reduce 168


state 308
	loop_stmt : FOR '(' expr_stmt expr_stmt ')' stmt .  (170)

	.  reduce 170


state 309
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 311
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 310
	conditional_stmt : IF '(' expr ')' stmt ELSE . stmt

	'!'  shift 70
	'&'  shift 71
	'('  shift 72
	'*'  shift 73
	'+'  shift 74
	'-'  shift 75
	';'  shift 76
	'{'  shift 44
	'~'  shift 78
	SIZEOF  shift 79
	GOTO  shift 80
	BREAK  shift 81
	CONTINUE  shift 82
	RETURN  shift 83
	WHILE  shift 84
	DO  shift 85
	FOR  shift 86
	IF  shift 87
	SWITCH  shift 88
	CASE  shift 89
	DEFAULT  shift 90
	INC  shift 91
	DEC  shift 92
	INTVAL  shift 93
	DOUBLEVAL  shift 94
	BOOLVAL  shift 95
	CHARVAL  shift 96
	STRINGVAL  shift 97
	ID  shift 98

	const_expr  goto 101
	or_expr  goto 102
	assign_expr  goto 103
	expr  goto 104
	and_expr  goto 105
	bit_or_expr  goto 106
	compound_stmt  goto 107
	ternary_expr  goto 108
	equal_expr  goto 109
	greater_less_expr  goto 110
	addBack_sub_expr  goto 111
	bit_xor_expr  goto 112
	shift_expr  goto 113
	mul_div_mod_expr  goto 114
	bit_and_expr  goto 115
	jmp_stmt  goto 116
	expr_stmt  goto 117
	loop_stmt  goto 119
	conditional_stmt  goto 120
	label_stmt  goto 121
	stmt  goto 312
	basic_expr  goto 123
	unary_op  goto 124
	postfix_expr  goto 125
	val  goto 126
	unary_expr  goto 127


state 311
	loop_stmt : FOR '(' expr_stmt expr_stmt expr ')' stmt .  (169)

	.  reduce 169


state 312
	conditional_stmt : IF '(' expr ')' stmt ELSE stmt .  (178)

	.  reduce 178


##############################################################################
# Summary
##############################################################################

81 token(s), 59 nonterminal(s)
185 grammar rule(s), 313 state(s)


##############################################################################
# End of File
##############################################################################
