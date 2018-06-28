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
li $25, 1
label_29:
li $24, 1
addu $25,$25,$24
label_32:
li $24, 1
addu $25,$25,$24
label_35:
li $24, 1
addu $25,$25,$24
label_38:
li $24, 1
addu $25,$25,$24
label_41:
li $24, 1
addu $25,$25,$24
label_44:
li $24, 1
addu $25,$25,$24
label_47:
li $24, 1
addu $25,$25,$24
label_50:
li $24, 1
addu $25,$25,$24
label_53:
li $24, 1
addu $25,$25,$24
label_56:
li $24, 1
addu $25,$25,$24
label_59:
li $24, 1
addu $25,$25,$24
label_62:
li $24, 1
addu $25,$25,$24
label_65:
li $24, 1
addu $25,$25,$24
label_68:
li $24, 1
addu $25,$25,$24
label_71:
li $24, 1
addu $25,$25,$24
label_74:
li $24, 1
addu $25,$25,$24
label_77:
li $24, 1
addu $25,$25,$24
label_80:
li $24, 1
addu $25,$25,$24
label_83:
li $24, 1
addu $25,$25,$24
label_86:
li $24, 1
addu $25,$25,$24
label_89:
li $24, 1
addu $25,$25,$24
label_92:
li $24, 1
addu $25,$25,$24
label_95:
li $24, 1
addu $25,$25,$24
label_98:
li $24, 1
addu $25,$25,$24
label_101:
li $24, 1
addu $25,$25,$24
label_104:
li $24, 1
addu $25,$25,$24
label_107:
li $24, 1
addu $25,$25,$24
label_110:
li $24, 1
addu $25,$25,$24
label_113:
li $24, 1
addu $25,$25,$24
label_116:
li $24, 1
addu $25,$25,$24
label_119:
li $24, 1
addu $25,$25,$24
label_122:
li $24, 1
addu $25,$25,$24
#---------saving new initialzed variable add------------
subu $sp, $sp, 4 #push stack
sw $25, -4($fp)
#---------finished saving new variable -----------
# input line number: 2 :: parser.ypp line number: 345
j 
label_131:
li $25, 1
label_133:
li $24, 1
mult $25,$24
mflo $25
label_137:
li $24, 1
mult $25,$24
mflo $25
label_141:
li $24, 1
mult $25,$24
mflo $25
label_145:
li $24, 1
mult $25,$24
mflo $25
label_149:
li $24, 1
mult $25,$24
mflo $25
label_153:
li $24, 1
mult $25,$24
mflo $25
label_157:
li $24, 1
mult $25,$24
mflo $25
label_161:
li $24, 1
mult $25,$24
mflo $25
label_165:
li $24, 1
mult $25,$24
mflo $25
label_169:
li $24, 1
mult $25,$24
mflo $25
label_173:
li $24, 1
mult $25,$24
mflo $25
label_177:
li $24, 1
mult $25,$24
mflo $25
label_181:
li $24, 1
mult $25,$24
mflo $25
label_185:
li $24, 1
mult $25,$24
mflo $25
label_189:
li $24, 1
mult $25,$24
mflo $25
label_193:
li $24, 1
mult $25,$24
mflo $25
label_197:
li $24, 1
mult $25,$24
mflo $25
label_201:
li $24, 1
mult $25,$24
mflo $25
label_205:
li $24, 1
mult $25,$24
mflo $25
label_209:
li $24, 1
mult $25,$24
mflo $25
label_213:
li $24, 1
mult $25,$24
mflo $25
label_217:
li $24, 1
mult $25,$24
mflo $25
label_221:
li $24, 1
mult $25,$24
mflo $25
label_225:
li $24, 1
mult $25,$24
mflo $25
label_229:
li $24, 1
mult $25,$24
mflo $25
label_233:
li $24, 1
mult $25,$24
mflo $25
label_237:
li $24, 1
mult $25,$24
mflo $25
label_241:
li $24, 1
mult $25,$24
mflo $25
label_245:
li $24, 1
mult $25,$24
mflo $25
label_249:
li $24, 1
mult $25,$24
mflo $25
label_253:
li $24, 1
mult $25,$24
mflo $25
label_257:
li $24, 1
mult $25,$24
mflo $25
#---------saving new initialzed variable mul------------
subu $sp, $sp, 4 #push stack
sw $25, -8($fp)
#---------finished saving new variable -----------
# input line number: 3 :: parser.ypp line number: 345
j 
# input line number: 3 :: parser.ypp line number: 284
j 
label_269:
li $25, 0
label_271:
li $24, 0
subu $25,$25,$24
label_274:
li $24, 0
subu $25,$25,$24
label_277:
li $24, 0
subu $25,$25,$24
label_280:
li $24, 0
subu $25,$25,$24
label_283:
li $24, 0
subu $25,$25,$24
label_286:
li $24, 0
subu $25,$25,$24
label_289:
li $24, 0
subu $25,$25,$24
label_292:
li $24, 0
subu $25,$25,$24
label_295:
li $24, 0
subu $25,$25,$24
label_298:
li $24, 0
subu $25,$25,$24
label_301:
li $24, 0
subu $25,$25,$24
label_304:
li $24, 0
subu $25,$25,$24
label_307:
li $24, 0
subu $25,$25,$24
label_310:
li $24, 0
subu $25,$25,$24
label_313:
li $24, 0
subu $25,$25,$24
label_316:
li $24, 0
subu $25,$25,$24
label_319:
li $24, 0
subu $25,$25,$24
label_322:
li $24, 0
subu $25,$25,$24
label_325:
li $24, 0
subu $25,$25,$24
label_328:
li $24, 0
subu $25,$25,$24
label_331:
li $24, 0
subu $25,$25,$24
label_334:
li $24, 0
subu $25,$25,$24
label_337:
li $24, 0
subu $25,$25,$24
label_340:
li $24, 0
subu $25,$25,$24
label_343:
li $24, 0
subu $25,$25,$24
label_346:
li $24, 0
subu $25,$25,$24
label_349:
li $24, 0
subu $25,$25,$24
label_352:
li $24, 0
subu $25,$25,$24
label_355:
li $24, 0
subu $25,$25,$24
label_358:
li $24, 0
subu $25,$25,$24
label_361:
li $24, 0
subu $25,$25,$24
label_364:
li $24, 0
subu $25,$25,$24
#---------saving new initialzed variable sub------------
subu $sp, $sp, 4 #push stack
sw $25, -12($fp)
#---------finished saving new variable -----------
# input line number: 4 :: parser.ypp line number: 345
j 
# input line number: 4 :: parser.ypp line number: 284
j 
label_375:
li $25, 1
label_377:
li $24, 1
bnez $24, label_383
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_383:
div $25,$24
mflo $25
label_386:
li $24, 1
bnez $24, label_392
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_392:
div $25,$24
mflo $25
label_395:
li $24, 1
bnez $24, label_401
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_401:
div $25,$24
mflo $25
label_404:
li $24, 1
bnez $24, label_410
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_410:
div $25,$24
mflo $25
label_413:
li $24, 1
bnez $24, label_419
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_419:
div $25,$24
mflo $25
label_422:
li $24, 1
bnez $24, label_428
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_428:
div $25,$24
mflo $25
label_431:
li $24, 1
bnez $24, label_437
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_437:
div $25,$24
mflo $25
label_440:
li $24, 1
bnez $24, label_446
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_446:
div $25,$24
mflo $25
label_449:
li $24, 1
bnez $24, label_455
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_455:
div $25,$24
mflo $25
label_458:
li $24, 1
bnez $24, label_464
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_464:
div $25,$24
mflo $25
label_467:
li $24, 1
bnez $24, label_473
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_473:
div $25,$24
mflo $25
label_476:
li $24, 1
bnez $24, label_482
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_482:
div $25,$24
mflo $25
label_485:
li $24, 1
bnez $24, label_491
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_491:
div $25,$24
mflo $25
label_494:
li $24, 1
bnez $24, label_500
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_500:
div $25,$24
mflo $25
label_503:
li $24, 1
bnez $24, label_509
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_509:
div $25,$24
mflo $25
label_512:
li $24, 1
bnez $24, label_518
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_518:
div $25,$24
mflo $25
label_521:
li $24, 1
bnez $24, label_527
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_527:
div $25,$24
mflo $25
label_530:
li $24, 1
bnez $24, label_536
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_536:
div $25,$24
mflo $25
label_539:
li $24, 1
bnez $24, label_545
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_545:
div $25,$24
mflo $25
label_548:
li $24, 1
bnez $24, label_554
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_554:
div $25,$24
mflo $25
label_557:
li $24, 1
bnez $24, label_563
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_563:
div $25,$24
mflo $25
label_566:
li $24, 1
bnez $24, label_572
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_572:
div $25,$24
mflo $25
label_575:
li $24, 1
bnez $24, label_581
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_581:
div $25,$24
mflo $25
label_584:
li $24, 1
bnez $24, label_590
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_590:
div $25,$24
mflo $25
label_593:
li $24, 1
bnez $24, label_599
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_599:
div $25,$24
mflo $25
label_602:
li $24, 1
bnez $24, label_608
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_608:
div $25,$24
mflo $25
label_611:
li $24, 1
bnez $24, label_617
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_617:
div $25,$24
mflo $25
label_620:
li $24, 1
bnez $24, label_626
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_626:
div $25,$24
mflo $25
label_629:
li $24, 1
bnez $24, label_635
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_635:
div $25,$24
mflo $25
label_638:
li $24, 1
bnez $24, label_644
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_644:
div $25,$24
mflo $25
label_647:
li $24, 1
bnez $24, label_653
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_653:
div $25,$24
mflo $25
label_656:
li $24, 1
bnez $24, label_662
la $23, divErrorMessage
sw $23, ($sp)
j divErrorFunc
label_662:
div $25,$24
mflo $25
#---------saving new initialzed variable div------------
subu $sp, $sp, 4 #push stack
sw $25, -16($fp)
#---------finished saving new variable -----------
# input line number: 5 :: parser.ypp line number: 345
j label_673
# input line number: 5 :: parser.ypp line number: 284
j label_673
label_673:
addu $sp, $sp, 16 #popping 4 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
