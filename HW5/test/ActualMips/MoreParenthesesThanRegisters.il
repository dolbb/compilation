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
li $25, 42
#---------saving new initialzed variable a------------
subu $sp, $sp, 4 #push stack
sw $25, -4($fp)
#---------finished saving new variable -----------
# input line number: 2 :: parser.ypp line number: 345
j label_35
label_35:
li $25, 42
#---------saving new initialzed variable c------------
subu $sp, $sp, 4 #push stack
sw $25, -8($fp)
#---------finished saving new variable -----------
# input line number: 3 :: parser.ypp line number: 345
j label_45
# input line number: 3 :: parser.ypp line number: 284
j label_45
label_45:
li $25, 42
#---------saving new initialzed variable d------------
subu $sp, $sp, 4 #push stack
sw $25, -12($fp)
#---------finished saving new variable -----------
# input line number: 4 :: parser.ypp line number: 345
j label_55
# input line number: 4 :: parser.ypp line number: 284
j label_55
label_55:
li $25, 42
#---------saving new initialzed variable e------------
subu $sp, $sp, 4 #push stack
sw $25, -16($fp)
#---------finished saving new variable -----------
# input line number: 5 :: parser.ypp line number: 345
j label_65
# input line number: 5 :: parser.ypp line number: 284
j label_65
label_65:
li $25, 42
#---------saving new initialzed variable f------------
subu $sp, $sp, 4 #push stack
sw $25, -20($fp)
#---------finished saving new variable -----------
# input line number: 6 :: parser.ypp line number: 345
j label_75
# input line number: 6 :: parser.ypp line number: 284
j label_75
label_75:
li $25, 42
#---------saving new initialzed variable g------------
subu $sp, $sp, 4 #push stack
sw $25, -24($fp)
#---------finished saving new variable -----------
# input line number: 7 :: parser.ypp line number: 345
j label_85
# input line number: 7 :: parser.ypp line number: 284
j label_85
label_85:
li $25, 42
#---------saving new initialzed variable h------------
subu $sp, $sp, 4 #push stack
sw $25, -28($fp)
#---------finished saving new variable -----------
# input line number: 8 :: parser.ypp line number: 345
j label_95
# input line number: 8 :: parser.ypp line number: 284
j label_95
label_95:
li $25, 42
#---------saving new initialzed variable i------------
subu $sp, $sp, 4 #push stack
sw $25, -32($fp)
#---------finished saving new variable -----------
# input line number: 9 :: parser.ypp line number: 345
j label_105
# input line number: 9 :: parser.ypp line number: 284
j label_105
label_105:
li $25, 42
#---------saving new initialzed variable j------------
subu $sp, $sp, 4 #push stack
sw $25, -36($fp)
#---------finished saving new variable -----------
# input line number: 10 :: parser.ypp line number: 345
j label_115
# input line number: 10 :: parser.ypp line number: 284
j label_115
label_115:
li $25, 42
#---------saving new initialzed variable k------------
subu $sp, $sp, 4 #push stack
sw $25, -40($fp)
#---------finished saving new variable -----------
# input line number: 11 :: parser.ypp line number: 345
j label_125
# input line number: 11 :: parser.ypp line number: 284
j label_125
label_125:
li $25, 42
#---------saving new initialzed variable l------------
subu $sp, $sp, 4 #push stack
sw $25, -44($fp)
#---------finished saving new variable -----------
# input line number: 12 :: parser.ypp line number: 345
j label_135
# input line number: 12 :: parser.ypp line number: 284
j label_135
label_135:
li $25, 100
#---------saving new initialzed variable m------------
subu $sp, $sp, 4 #push stack
sw $25, -48($fp)
#---------finished saving new variable -----------
# input line number: 13 :: parser.ypp line number: 345
j label_145
# input line number: 13 :: parser.ypp line number: 284
j label_145
label_145:
li $25, 42
#---------saving new initialzed variable n------------
subu $sp, $sp, 4 #push stack
sw $25, -52($fp)
#---------finished saving new variable -----------
# input line number: 14 :: parser.ypp line number: 345
j label_155
# input line number: 14 :: parser.ypp line number: 284
j label_155
label_155:
li $25, 42
#---------saving new initialzed variable o------------
subu $sp, $sp, 4 #push stack
sw $25, -56($fp)
#---------finished saving new variable -----------
# input line number: 15 :: parser.ypp line number: 345
j label_165
# input line number: 15 :: parser.ypp line number: 284
j label_165
label_165:
li $25, 42
#---------saving new initialzed variable p------------
subu $sp, $sp, 4 #push stack
sw $25, -60($fp)
#---------finished saving new variable -----------
# input line number: 16 :: parser.ypp line number: 345
j label_175
# input line number: 16 :: parser.ypp line number: 284
j label_175
label_175:
li $25, 42
#---------saving new initialzed variable q------------
subu $sp, $sp, 4 #push stack
sw $25, -64($fp)
#---------finished saving new variable -----------
# input line number: 17 :: parser.ypp line number: 345
j label_185
# input line number: 17 :: parser.ypp line number: 284
j label_185
label_185:
li $25, 42
#---------saving new initialzed variable r------------
subu $sp, $sp, 4 #push stack
sw $25, -68($fp)
#---------finished saving new variable -----------
# input line number: 18 :: parser.ypp line number: 345
j label_195
# input line number: 18 :: parser.ypp line number: 284
j label_195
label_195:
li $25, 42
#---------saving new initialzed variable s------------
subu $sp, $sp, 4 #push stack
sw $25, -72($fp)
#---------finished saving new variable -----------
# input line number: 19 :: parser.ypp line number: 345
j label_205
# input line number: 19 :: parser.ypp line number: 284
j label_205
label_205:
li $25, 42
#---------saving new initialzed variable t------------
subu $sp, $sp, 4 #push stack
sw $25, -76($fp)
#---------finished saving new variable -----------
# input line number: 20 :: parser.ypp line number: 345
j label_215
# input line number: 20 :: parser.ypp line number: 284
j label_215
label_215:
li $25, 42
#---------saving new initialzed variable u------------
subu $sp, $sp, 4 #push stack
sw $25, -80($fp)
#---------finished saving new variable -----------
# input line number: 21 :: parser.ypp line number: 345
j label_225
# input line number: 21 :: parser.ypp line number: 284
j label_225
label_225:
li $25, 42
#---------saving new initialzed variable v------------
subu $sp, $sp, 4 #push stack
sw $25, -84($fp)
#---------finished saving new variable -----------
# input line number: 22 :: parser.ypp line number: 345
j label_235
# input line number: 22 :: parser.ypp line number: 284
j label_235
label_235:
li $25, 42
#---------saving new initialzed variable w------------
subu $sp, $sp, 4 #push stack
sw $25, -88($fp)
#---------finished saving new variable -----------
# input line number: 23 :: parser.ypp line number: 345
j label_245
# input line number: 23 :: parser.ypp line number: 284
j label_245
label_245:
li $25, 42
#---------saving new initialzed variable x------------
subu $sp, $sp, 4 #push stack
sw $25, -92($fp)
#---------finished saving new variable -----------
# input line number: 24 :: parser.ypp line number: 345
j label_255
# input line number: 24 :: parser.ypp line number: 284
j label_255
label_255:
li $25, 42
#---------saving new initialzed variable y------------
subu $sp, $sp, 4 #push stack
sw $25, -96($fp)
#---------finished saving new variable -----------
# input line number: 25 :: parser.ypp line number: 345
j label_265
# input line number: 25 :: parser.ypp line number: 284
j label_265
label_265:
li $25, 42
#---------saving new initialzed variable z------------
subu $sp, $sp, 4 #push stack
sw $25, -100($fp)
#---------finished saving new variable -----------
# input line number: 26 :: parser.ypp line number: 345
j label_275
# input line number: 26 :: parser.ypp line number: 284
j label_275
label_275:
addu $sp, $sp, 100 #popping 25 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
