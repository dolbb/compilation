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
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
label_33:
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
_manyReturns_:
move $fp, $sp
sw $ra, ($sp)
label_42:
li $25, 1
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
label_50:
li $25, 2
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 7 :: parser.ypp line number: 284
j label_60
label_60:
li $25, 3
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 8 :: parser.ypp line number: 284
j label_70
label_70:
li $25, 4
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 9 :: parser.ypp line number: 284
j label_80
label_80:
li $25, 5
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 10 :: parser.ypp line number: 284
j label_90
label_90:
li $25, 6
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 11 :: parser.ypp line number: 284
j label_100
label_100:
li $25, 7
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 12 :: parser.ypp line number: 284
j label_110
label_110:
li $25, 8
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 13 :: parser.ypp line number: 284
j label_120
label_120:
li $25, 9
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 14 :: parser.ypp line number: 284
j label_130
label_130:
li $25, 10
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 15 :: parser.ypp line number: 284
j label_140
label_140:
li $25, 11
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 16 :: parser.ypp line number: 284
j label_150
label_150:
li $25, 12
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 17 :: parser.ypp line number: 284
j label_160
label_160:
li $25, 13
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 18 :: parser.ypp line number: 284
j label_170
label_170:
li $25, 14
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 19 :: parser.ypp line number: 284
j label_180
label_180:
li $25, 15
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 20 :: parser.ypp line number: 284
j label_190
label_190:
li $25, 16
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 21 :: parser.ypp line number: 284
j label_200
label_200:
li $25, 17
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 22 :: parser.ypp line number: 284
j label_210
label_210:
li $25, 18
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 23 :: parser.ypp line number: 284
j label_220
label_220:
li $25, 19
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 24 :: parser.ypp line number: 284
j label_230
label_230:
li $25, 20
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 25 :: parser.ypp line number: 284
j label_240
label_240:
li $25, 21
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 26 :: parser.ypp line number: 284
j label_250
label_250:
li $25, 22
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 27 :: parser.ypp line number: 284
j label_260
label_260:
li $25, 23
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 28 :: parser.ypp line number: 284
j label_270
label_270:
li $25, 24
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 29 :: parser.ypp line number: 284
j label_280
label_280:
li $25, 25
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 30 :: parser.ypp line number: 284
j label_290
label_290:
li $25, 26
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 31 :: parser.ypp line number: 284
j label_300
label_300:
li $25, 27
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 32 :: parser.ypp line number: 284
j label_310
label_310:
li $25, 28
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 33 :: parser.ypp line number: 284
j label_320
label_320:
li $25, 29
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 34 :: parser.ypp line number: 284
j label_330
label_330:
li $25, 30
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 35 :: parser.ypp line number: 284
j label_340
label_340:
li $25, 31
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 36 :: parser.ypp line number: 284
j label_350
label_350:
li $25, 32
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 37 :: parser.ypp line number: 284
j label_360
label_360:
li $25, 33
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 38 :: parser.ypp line number: 284
j label_370
label_370:
li $25, 34
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 39 :: parser.ypp line number: 284
j label_380
label_380:
li $25, 35
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 40 :: parser.ypp line number: 284
j label_390
label_390:
li $25, 36
move $v0, $25
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
# input line number: 41 :: parser.ypp line number: 284
j label_400
label_400:
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
