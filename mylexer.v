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
# Date: 01/05/18
# Time: 21:35:05
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

   13  "input"

   14  "print"

   15  ","

   16  ":"

   17  "?"

   18  "+="

   19  "-="

   20  "*="

   21  "/="

   22  "%="

   23  "&="

   24  "|="

   25  "^="

   26  "~="

   27  "<<="

   28  ">>="

   29  "||"

   30  "&&"

   31  "|"

   32  "^"

   33  "&"

   34  "=="

   35  "!="

   36  "<="

   37  ">="

   38  "<<"

   39  ">>"

   40  "<"

   41  ">"

   42  "++"

   43  "--"

   44  "+"

   45  "-"

   46  "*"

   47  "/"

   48  "%"

   49  "!"

   50  "~"

   51  "{"

   52  "}"

   53  "("

   54  ")"

   55  "["

   56  "]"

   57  "="

   58  ";"

   59  [0-9]+

   60  '([^\\]|\\([abfnrtv\\\'\"0]|[0-8]{1,3}|(x|X)[0-9a-fA-F]{1,2}))'

   61  ([a-zA-Z]|_)+([a-zA-Z]|[0-9]|_)*


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
	0x6e - 0x6f (2)    goto 24
	0x70               goto 33
	0x71 - 0x76 (6)    goto 24
	0x77               goto 34
	0x78 - 0x7a (3)    goto 24
	0x7b               goto 35
	0x7c               goto 36
	0x7d               goto 37
	0x7e               goto 38


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
	0x6e - 0x6f (2)    goto 24
	0x70               goto 33
	0x71 - 0x76 (6)    goto 24
	0x77               goto 34
	0x78 - 0x7a (3)    goto 24
	0x7b               goto 35
	0x7c               goto 36
	0x7d               goto 37
	0x7e               goto 38


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
	0x3d               goto 39

	match 49


state 7
	0x3d               goto 40

	match 48


state 8
	0x26               goto 41
	0x3d               goto 42

	match 33


state 9
	0x00 - 0x5b (92)   goto 43
	0x5c               goto 44
	0x5d - 0xff (163)  goto 43


state 10
	match 53


state 11
	match 54


state 12
	0x3d               goto 45

	match 46


state 13
	0x2b               goto 46
	0x3d               goto 47

	match 44


state 14
	match 15


state 15
	0x2d               goto 48
	0x3d               goto 49

	match 45


state 16
	0x2a               goto 50
	0x2f               goto 51
	0x3d               goto 52

	match 47


state 17
	0x30 - 0x39 (10)   goto 17

	match 59


state 18
	match 16


state 19
	match 58


state 20
	0x3c               goto 53
	0x3d               goto 54

	match 40


state 21
	0x3d               goto 55

	match 57


state 22
	0x3d               goto 56
	0x3e               goto 57

	match 41


state 23
	match 17


state 24
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 61


state 25
	match 55


state 26
	match 56


state 27
	0x3d               goto 58

	match 32


state 28
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x67 (7)    goto 24
	0x68               goto 59
	0x69 - 0x7a (18)   goto 24

	match 61


state 29
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6b (11)   goto 24
	0x6c               goto 60
	0x6d - 0x7a (14)   goto 24

	match 61


state 30
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6e (14)   goto 24
	0x6f               goto 61
	0x70 - 0x7a (11)   goto 24

	match 61


state 31
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x65 (5)    goto 24
	0x66               goto 62
	0x67 - 0x6d (7)    goto 24
	0x6e               goto 63
	0x6f - 0x7a (12)   goto 24

	match 61


state 32
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61               goto 64
	0x62 - 0x7a (25)   goto 24

	match 61


state 33
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x71 (17)   goto 24
	0x72               goto 65
	0x73 - 0x7a (8)    goto 24

	match 61


state 34
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x67 (7)    goto 24
	0x68               goto 66
	0x69 - 0x7a (18)   goto 24

	match 61


state 35
	match 51


state 36
	0x3d               goto 67
	0x7c               goto 68

	match 31


state 37
	match 52


state 38
	0x3d               goto 69

	match 50


state 39
	match 35


state 40
	match 22


state 41
	match 30


state 42
	match 23


state 43
	0x27               goto 70


state 44
	0x22               goto 43
	0x27               goto 43
	0x30               goto 71
	0x31 - 0x38 (8)    goto 71
	0x58               goto 72
	0x5c               goto 43
	0x61 - 0x62 (2)    goto 43
	0x66               goto 43
	0x6e               goto 43
	0x72               goto 43
	0x74               goto 43
	0x76               goto 43
	0x78               goto 72


state 45
	match 20


state 46
	match 42


state 47
	match 18


state 48
	match 43


state 49
	match 19


state 50
	0x00 - 0x29 (42)   goto 50
	0x2a               goto 73
	0x2b - 0xff (213)  goto 50


state 51
	0x00 - 0x09 (10)   goto 51
	0x0b - 0xff (245)  goto 51

	match 4


state 52
	match 21


state 53
	0x3d               goto 74

	match 38


state 54
	match 36


state 55
	match 34


state 56
	match 37


state 57
	0x3d               goto 75

	match 39


state 58
	match 25


state 59
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61               goto 76
	0x62 - 0x7a (25)   goto 24

	match 61


state 60
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x72 (18)   goto 24
	0x73               goto 77
	0x74 - 0x7a (7)    goto 24

	match 61


state 61
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x71 (17)   goto 24
	0x72               goto 78
	0x73 - 0x7a (8)    goto 24

	match 61


state 62
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 10


state 63
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6f (15)   goto 24
	0x70               goto 79
	0x71 - 0x73 (3)    goto 24
	0x74               goto 80
	0x75 - 0x7a (6)    goto 24

	match 61


state 64
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x68 (8)    goto 24
	0x69               goto 81
	0x6a - 0x7a (17)   goto 24

	match 61


state 65
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x68 (8)    goto 24
	0x69               goto 82
	0x6a - 0x7a (17)   goto 24

	match 61


state 66
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x68 (8)    goto 24
	0x69               goto 83
	0x6a - 0x7a (17)   goto 24

	match 61


state 67
	match 24


state 68
	match 29


state 69
	match 26


state 70
	match 60


state 71
	0x27               goto 70
	0x30 - 0x38 (9)    goto 84


state 72
	0x30 - 0x39 (10)   goto 85
	0x41 - 0x46 (6)    goto 85
	0x61 - 0x66 (6)    goto 85


state 73
	0x00 - 0x2e (47)   goto 50
	0x2f               goto 86
	0x30 - 0xff (208)  goto 50


state 74
	match 27


state 75
	match 28


state 76
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x71 (17)   goto 24
	0x72               goto 87
	0x73 - 0x7a (8)    goto 24

	match 61


state 77
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x64 (4)    goto 24
	0x65               goto 88
	0x66 - 0x7a (21)   goto 24

	match 61


state 78
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 9


state 79
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x74 (20)   goto 24
	0x75               goto 89
	0x76 - 0x7a (5)    goto 24

	match 61


state 80
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 6


state 81
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6d (13)   goto 24
	0x6e               goto 90
	0x6f - 0x7a (12)   goto 24

	match 61


state 82
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6d (13)   goto 24
	0x6e               goto 91
	0x6f - 0x7a (12)   goto 24

	match 61


state 83
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x6b (11)   goto 24
	0x6c               goto 92
	0x6d - 0x7a (14)   goto 24

	match 61


state 84
	0x27               goto 70
	0x30 - 0x38 (9)    goto 43


state 85
	0x27               goto 70
	0x30 - 0x39 (10)   goto 43
	0x41 - 0x46 (6)    goto 43
	0x61 - 0x66 (6)    goto 43


state 86
	match 5


state 87
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 7


state 88
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 11


state 89
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x73 (19)   goto 24
	0x74               goto 93
	0x75 - 0x7a (6)    goto 24

	match 61


state 90
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 12


state 91
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x73 (19)   goto 24
	0x74               goto 94
	0x75 - 0x7a (6)    goto 24

	match 61


state 92
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x64 (4)    goto 24
	0x65               goto 95
	0x66 - 0x7a (21)   goto 24

	match 61


state 93
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 13


state 94
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 14


state 95
	0x30 - 0x39 (10)   goto 24
	0x41 - 0x5a (26)   goto 24
	0x5f               goto 24
	0x61 - 0x7a (26)   goto 24

	match 8


#############################################################################
# Summary
#############################################################################

1 start state(s)
61 expression(s), 95 state(s)


#############################################################################
# End of File
#############################################################################
