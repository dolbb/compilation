.data
divErrorMessage: .asciiz "Error division by zero\n"
indexErrorMessage: .asciiz "Error index out of bounds\n"
.text
divErrorFunc:
jal printFunc
li $v0, 10
syscall
arrErrorFunc:
jal printFunc
li $v0, 10
syscall
#Initializtion-----------------------
printFunc:
lw $a0, 0($sp)
li $v0, 4
syscall
jr $ra
printiFunc:
lw $a0, 0($sp)
li $v0, 1
syscall
jr $ra
subu $sp, $sp, 4 #push stack
subu $sp, $sp, 4 #push stack
main:
j main2
#Finished Initializtion--------------
main2:
move $fp, $sp
sw $ra, ($sp)
label_27:
#---------saving new uninitialzed variable a------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -4($fp)
#---------finished saving new variable -----------
# input line number: 2 :: parser.ypp line number: 305
j label_35
label_35:
#---------saving new uninitialzed variable c------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -8($fp)
#---------finished saving new variable -----------
# input line number: 3 :: parser.ypp line number: 305
j label_45
# input line number: 3 :: parser.ypp line number: 284
j label_45
label_45:
#---------saving new uninitialzed variable d------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -12($fp)
#---------finished saving new variable -----------
# input line number: 4 :: parser.ypp line number: 305
j label_55
# input line number: 4 :: parser.ypp line number: 284
j label_55
label_55:
#---------saving new uninitialzed variable e------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -16($fp)
#---------finished saving new variable -----------
# input line number: 5 :: parser.ypp line number: 305
j label_65
# input line number: 5 :: parser.ypp line number: 284
j label_65
label_65:
#---------saving new uninitialzed variable f------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -20($fp)
#---------finished saving new variable -----------
# input line number: 6 :: parser.ypp line number: 305
j label_75
# input line number: 6 :: parser.ypp line number: 284
j label_75
label_75:
#---------saving new uninitialzed variable g------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -24($fp)
#---------finished saving new variable -----------
# input line number: 7 :: parser.ypp line number: 305
j label_85
# input line number: 7 :: parser.ypp line number: 284
j label_85
label_85:
#---------saving new uninitialzed variable h------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -28($fp)
#---------finished saving new variable -----------
# input line number: 8 :: parser.ypp line number: 305
j label_95
# input line number: 8 :: parser.ypp line number: 284
j label_95
label_95:
#---------saving new uninitialzed variable i------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -32($fp)
#---------finished saving new variable -----------
# input line number: 9 :: parser.ypp line number: 305
j label_105
# input line number: 9 :: parser.ypp line number: 284
j label_105
label_105:
#---------saving new uninitialzed variable j------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -36($fp)
#---------finished saving new variable -----------
# input line number: 10 :: parser.ypp line number: 305
j label_115
# input line number: 10 :: parser.ypp line number: 284
j label_115
label_115:
#---------saving new uninitialzed variable k------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -40($fp)
#---------finished saving new variable -----------
# input line number: 11 :: parser.ypp line number: 305
j label_125
# input line number: 11 :: parser.ypp line number: 284
j label_125
label_125:
#---------saving new uninitialzed variable l------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -44($fp)
#---------finished saving new variable -----------
# input line number: 12 :: parser.ypp line number: 305
j label_135
# input line number: 12 :: parser.ypp line number: 284
j label_135
label_135:
#---------saving new uninitialzed variable m------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -48($fp)
#---------finished saving new variable -----------
# input line number: 13 :: parser.ypp line number: 305
j label_145
# input line number: 13 :: parser.ypp line number: 284
j label_145
label_145:
#---------saving new uninitialzed variable n------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -52($fp)
#---------finished saving new variable -----------
# input line number: 14 :: parser.ypp line number: 305
j label_155
# input line number: 14 :: parser.ypp line number: 284
j label_155
label_155:
#---------saving new uninitialzed variable o------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -56($fp)
#---------finished saving new variable -----------
# input line number: 15 :: parser.ypp line number: 305
j label_165
# input line number: 15 :: parser.ypp line number: 284
j label_165
label_165:
#---------saving new uninitialzed variable p------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -60($fp)
#---------finished saving new variable -----------
# input line number: 16 :: parser.ypp line number: 305
j label_175
# input line number: 16 :: parser.ypp line number: 284
j label_175
label_175:
#---------saving new uninitialzed variable q------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -64($fp)
#---------finished saving new variable -----------
# input line number: 17 :: parser.ypp line number: 305
j label_185
# input line number: 17 :: parser.ypp line number: 284
j label_185
label_185:
#---------saving new uninitialzed variable r------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -68($fp)
#---------finished saving new variable -----------
# input line number: 18 :: parser.ypp line number: 305
j label_195
# input line number: 18 :: parser.ypp line number: 284
j label_195
label_195:
#---------saving new uninitialzed variable s------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -72($fp)
#---------finished saving new variable -----------
# input line number: 19 :: parser.ypp line number: 305
j label_205
# input line number: 19 :: parser.ypp line number: 284
j label_205
label_205:
#---------saving new uninitialzed variable t------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -76($fp)
#---------finished saving new variable -----------
# input line number: 20 :: parser.ypp line number: 305
j label_215
# input line number: 20 :: parser.ypp line number: 284
j label_215
label_215:
addu $sp, $sp, 76 #popping 19 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
