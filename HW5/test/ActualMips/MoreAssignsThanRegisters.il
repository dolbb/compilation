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
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 4 :: parser.ypp line number: 465
j label_56
# input line number: 4 :: parser.ypp line number: 284
j label_56
label_56:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 5 :: parser.ypp line number: 465
j label_67
# input line number: 5 :: parser.ypp line number: 284
j label_67
label_67:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 6 :: parser.ypp line number: 465
j label_78
# input line number: 6 :: parser.ypp line number: 284
j label_78
label_78:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 7 :: parser.ypp line number: 465
j label_89
# input line number: 7 :: parser.ypp line number: 284
j label_89
label_89:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 8 :: parser.ypp line number: 465
j label_100
# input line number: 8 :: parser.ypp line number: 284
j label_100
label_100:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 9 :: parser.ypp line number: 465
j label_111
# input line number: 9 :: parser.ypp line number: 284
j label_111
label_111:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 10 :: parser.ypp line number: 465
j label_122
# input line number: 10 :: parser.ypp line number: 284
j label_122
label_122:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 11 :: parser.ypp line number: 465
j label_133
# input line number: 11 :: parser.ypp line number: 284
j label_133
label_133:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 12 :: parser.ypp line number: 465
j label_144
# input line number: 12 :: parser.ypp line number: 284
j label_144
label_144:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 13 :: parser.ypp line number: 465
j label_155
# input line number: 13 :: parser.ypp line number: 284
j label_155
label_155:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 14 :: parser.ypp line number: 465
j label_166
# input line number: 14 :: parser.ypp line number: 284
j label_166
label_166:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 15 :: parser.ypp line number: 465
j label_177
# input line number: 15 :: parser.ypp line number: 284
j label_177
label_177:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 16 :: parser.ypp line number: 465
j label_188
# input line number: 16 :: parser.ypp line number: 284
j label_188
label_188:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 17 :: parser.ypp line number: 465
j label_199
# input line number: 17 :: parser.ypp line number: 284
j label_199
label_199:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 18 :: parser.ypp line number: 465
j label_210
# input line number: 18 :: parser.ypp line number: 284
j label_210
label_210:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 19 :: parser.ypp line number: 465
j label_221
# input line number: 19 :: parser.ypp line number: 284
j label_221
label_221:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 20 :: parser.ypp line number: 465
j label_232
# input line number: 20 :: parser.ypp line number: 284
j label_232
label_232:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 21 :: parser.ypp line number: 465
j label_243
# input line number: 21 :: parser.ypp line number: 284
j label_243
label_243:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 22 :: parser.ypp line number: 465
j label_254
# input line number: 22 :: parser.ypp line number: 284
j label_254
label_254:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 23 :: parser.ypp line number: 465
j label_265
# input line number: 23 :: parser.ypp line number: 284
j label_265
label_265:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 24 :: parser.ypp line number: 465
j label_276
# input line number: 24 :: parser.ypp line number: 284
j label_276
label_276:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 25 :: parser.ypp line number: 465
j label_287
# input line number: 25 :: parser.ypp line number: 284
j label_287
label_287:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 26 :: parser.ypp line number: 465
j label_298
# input line number: 26 :: parser.ypp line number: 284
j label_298
label_298:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 27 :: parser.ypp line number: 465
j label_309
# input line number: 27 :: parser.ypp line number: 284
j label_309
label_309:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 28 :: parser.ypp line number: 465
j label_320
# input line number: 28 :: parser.ypp line number: 284
j label_320
label_320:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 29 :: parser.ypp line number: 465
j label_331
# input line number: 29 :: parser.ypp line number: 284
j label_331
label_331:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 30 :: parser.ypp line number: 465
j label_342
# input line number: 30 :: parser.ypp line number: 284
j label_342
label_342:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 31 :: parser.ypp line number: 465
j label_353
# input line number: 31 :: parser.ypp line number: 284
j label_353
label_353:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 32 :: parser.ypp line number: 465
j label_364
# input line number: 32 :: parser.ypp line number: 284
j label_364
label_364:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 33 :: parser.ypp line number: 465
j label_375
# input line number: 33 :: parser.ypp line number: 284
j label_375
label_375:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 34 :: parser.ypp line number: 465
j label_386
# input line number: 34 :: parser.ypp line number: 284
j label_386
label_386:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 35 :: parser.ypp line number: 465
j label_397
# input line number: 35 :: parser.ypp line number: 284
j label_397
label_397:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 36 :: parser.ypp line number: 465
j label_408
# input line number: 36 :: parser.ypp line number: 284
j label_408
label_408:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 37 :: parser.ypp line number: 465
j label_419
# input line number: 37 :: parser.ypp line number: 284
j label_419
label_419:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 38 :: parser.ypp line number: 465
j label_430
# input line number: 38 :: parser.ypp line number: 284
j label_430
label_430:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 39 :: parser.ypp line number: 465
j label_441
# input line number: 39 :: parser.ypp line number: 284
j label_441
label_441:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 40 :: parser.ypp line number: 465
j label_452
# input line number: 40 :: parser.ypp line number: 284
j label_452
label_452:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 41 :: parser.ypp line number: 465
j label_463
# input line number: 41 :: parser.ypp line number: 284
j label_463
label_463:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 42 :: parser.ypp line number: 465
j label_474
# input line number: 42 :: parser.ypp line number: 284
j label_474
label_474:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 43 :: parser.ypp line number: 465
j label_485
# input line number: 43 :: parser.ypp line number: 284
j label_485
label_485:
#---------loading variable c to register $25 ------------
lw $25, -8($fp)
#---------finished loading variable -----------
#---------updating variable a------------
sw $25, -4($fp)
#---------finished updating variable -----------
# input line number: 44 :: parser.ypp line number: 465
j label_496
# input line number: 44 :: parser.ypp line number: 284
j label_496
label_496:
addu $sp, $sp, 8 #popping 2 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
