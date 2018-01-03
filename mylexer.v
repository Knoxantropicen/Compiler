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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 01/03/18
# Time: 16:41:04
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ ]+

    2  \t+

    3  \n+

    4  \/\/.*

    5  \/\*([^\*]*(\*[^\/])?)*\*\/

    6  "int"

    7  "char"

    8  "while"

    9  "for"

   10  "if"

   11  "else"

   12  "main"

   13  ","

   14  ":"

   15  "?"

   16  "+="

   17  "-="

   18  "*="

   19  "/="

   20  "%="

   21  "&="

   22  "|="

   23  "^="

   24  "~="

   25  "<<="

   26  ">>="

   27  "||"

   28  "&&"

   29  "|"

   30  "^"

   31  "&"

   32  "=="

   33  "!="

   34  "<="

   35  ">="

   36  "<<"

   37  ">>"

   38  "<"

   39  ">"

   40  "++"

   41  "--"

   42  "+"

   43  "-"

   44  "*"

   45  "/"

   46  "%"

   47  "!"

   48  "~"

   49  "{"

   50  "}"

   51  "("

   52  ")"

   53  "["

   54  "]"

   55  "="

   56  ";"

   57  [0-9]+

   58  '([^\\]|\\([abfnrtv\\\'\"0]|[0-8]{1,3}|(x|X)[0-9a-fA-F]{1,2}))'

   59  ([a-zA-Z]|_)+([a-zA-Z]|[0-9]|_)*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 5
	0x21               goto 6
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3a               goto 18
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f               goto 23
	0x41 - 0x5a (26)   goto 24
	0x5b               goto 25
	0x5d               goto 26
	0x5e               goto 27
	0x5f               goto 24
	0x61 - 0x62 (2)    goto 24
	0x63               goto 28
	0x64               goto 24
	0x65               goto 29
	0x66               goto 30
	0x67 - 0x68 (2)    goto 24
	0x69               goto 31
	0x6a - 0x6c (3)    goto 24
	0x6d               goto 32
	0x6e - 0x76 (9)    goto 24
	0x77               goto 33
	0x78 - 0x7a (3)    goto 24
	0x7b               goto 34
	0x7c               goto 35
	0x7d               goto 36
	0x7e               goto 37


state 2
	^INITIAL

	0x09               goto 3
	0x0a               goto 4
	0x20               goto 5
	0x21               goto 6
	0x25               goto 7
	0x26               goto 8
	0x27               goto 9
	0x28               goto 10
	0x29               goto 11
	0x2a               goto 12
	0x2b               goto 13
	0x2c               goto 14
	0x2d               goto 15
	0x2f               goto 16
	0x30 - 0x39 (10)   goto 17
	0x3a               goto 18
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f               goto 23
	0x41 - 0x5a (26)   goto 24
	0x5b               goto 25
	0x5d               goto 26
	0x5e               goto 27
	0x5f               goto 24
	0x61 - 0x62 (2)    goto 24
	0x63               goto 28
	0x64               goto 24
	0x65               goto 29
	0x66               goto 30
	0x67 - 0x68 (2)    goto 24
	0x69               goto 31
	0x6a - 0x6c (3)    goto 24
	0x6d               goto 32
	0x6e - 0x76 (9)    goto 24
	0x77               goto 33
	0x78 - 0x7a (3)    goto 24
	0x7b               goto 34
	0x7c               goto 35
	0x7d               goto 36
	0x7e               goto 37


state 3
	0x09               goto 3

	match 2


state 4
	0x0a               goto 4

	match 3


state 5
	0x20               goto 5

	match 1


state 6
	0x3d               goto 38

	match 47


state 7
	0x3d               goto 39

	match 46


state 8
	0x26               goto 40
	0x3d               goto 41

	match 31


state 9
	0x00 - 0x5b (92)   goto 42
	0x5c               goto 43
	0x5d - 0xff (163)  goto 42


state 10
	match 51


state 11
	match 52


state 12
	0x3d               goto 44

	match 44


state 13
	0x2b               goto 45
	0x3d               goto 46

	match 42


state 14
	match 13


state 15
	0x2d               goto 47
	0x3d               goto 48

	match 43


state 16
	0x2a               goto 49
	0x2f               goto 50
	0x3d               goto 51

	match 45


state 17
	0x30 - 0x39 (10)   goto 17

	match 57


state 18
	match 14


state 19
	match 56


state 20
	0x3c               goto 52
	0x3d               goto 53

	match 38


state 21
	0x3d               goto 54

	match 55


state 22
	0x3d               goto 55
	0x3e               goto 56

	match 39


state 23
	match 15


state 24
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 59


state 25
	match 53


state 26
	match 54


state 27
	0x3d               goto 57

	match 30


state 28
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x67 (7)    goto 24
	0x68               goto 58
	0x69 - 0x7a (18)   goto 24

	match 59


state 29
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6b (11)   goto 24
	0x6c               goto 59
	0x6d - 0x7a (14)   goto 24

	match 59


state 30
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6e (14)   goto 24
	0x6f               goto 60
	0x70 - 0x7a (11)   goto 24

	match 59


state 31
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x65 (5)    goto 24
	0x66               goto 61
	0x67 - 0x6d (7)    goto 24
	0x6e               goto 62
	0x6f - 0x7a (12)   goto 24

	match 59


state 32
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61               goto 63
	0x62 - 0x7a (25)   goto 24

	match 59


state 33
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x67 (7)    goto 24
	0x68               goto 64
	0x69 - 0x7a (18)   goto 24

	match 59


state 34
	match 49


state 35
	0x3d               goto 65
	0x7c               goto 66

	match 29


state 36
	match 50


state 37
	0x3d               goto 67

	match 48


state 38
	match 33


state 39
	match 20


state 40
	match 28


state 41
	match 21


state 42
	0x27               goto 68


state 43
	0x22               goto 42
	0x27               goto 42
	0x30               goto 69
	0x31 - 0x38 (8)    goto 69
	0x58               goto 70
	0x5c               goto 42
	0x61 - 0x62 (2)    goto 42
	0x66               goto 42
	0x6e               goto 42
	0x72               goto 42
	0x74               goto 42
	0x76               goto 42
	0x78               goto 70


state 44
	match 18


state 45
	match 40


state 46
	match 16


state 47
	match 41


state 48
	match 17


state 49
	0x00 - 0x29 (42)   goto 49
	0x2a               goto 71
	0x2b - 0xff (213)  goto 49


state 50
	0x00 - 0x09 (10)   goto 50
	0x0b - 0xff (245)  goto 50

	match 4


state 51
	match 19


state 52
	0x3d               goto 72

	match 36


state 53
	match 34


state 54
	match 32


state 55
	match 35


state 56
	0x3d               goto 73

	match 37


state 57
	match 23


state 58
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61               goto 74
	0x62 - 0x7a (25)   goto 24

	match 59


state 59
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x72 (18)   goto 24
	0x73               goto 75
	0x74 - 0x7a (7)    goto 24

	match 59


state 60
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x71 (17)   goto 24
	0x72               goto 76
	0x73 - 0x7a (8)    goto 24

	match 59


state 61
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 10


state 62
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x73 (19)   goto 24
	0x74               goto 77
	0x75 - 0x7a (6)    goto 24

	match 59


state 63
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x68 (8)    goto 24
	0x69               goto 78
	0x6a - 0x7a (17)   goto 24

	match 59


state 64
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x68 (8)    goto 24
	0x69               goto 79
	0x6a - 0x7a (17)   goto 24

	match 59


state 65
	match 22


state 66
	match 27


state 67
	match 24


state 68
	match 58


state 69
	0x27               goto 68
	0x30 - 0x38 (9)    goto 80


state 70
	0x30 - 0x39 (10)   goto 81
	0x41 - 0x46 (6)    goto 81
	0x61 - 0x66 (6)    goto 81


state 71
	0x00 - 0x2e (47)   goto 49
	0x2f               goto 82
	0x30 - 0xff (208)  goto 49


state 72
	match 25


state 73
	match 26


state 74
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x71 (17)   goto 24
	0x72               goto 83
	0x73 - 0x7a (8)    goto 24

	match 59


state 75
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x64 (4)    goto 24
	0x65               goto 84
	0x66 - 0x7a (21)   goto 24

	match 59


state 76
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 9


state 77
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 6


state 78
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6d (13)   goto 24
	0x6e               goto 85
	0x6f - 0x7a (12)   goto 24

	match 59


state 79
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6b (11)   goto 24
	0x6c               goto 86
	0x6d - 0x7a (14)   goto 24

	match 59


state 80
	0x27               goto 68
	0x30 - 0x38 (9)    goto 42


state 81
	0x27               goto 68
	0x30 - 0x39 (10)   goto 42
	0x41 - 0x46 (6)    goto 42
	0x61 - 0x66 (6)    goto 42


state 82
	match 5


state 83
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 7


state 84
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 11


state 85
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 12


state 86
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x64 (4)    goto 24
	0x65               goto 87
	0x66 - 0x7a (21)   goto 24

	match 59


state 87
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 8


#############################################################################
# Summary
#############################################################################

1 start state(s)
59 expression(s), 87 state(s)


#############################################################################
# End of File
#############################################################################
