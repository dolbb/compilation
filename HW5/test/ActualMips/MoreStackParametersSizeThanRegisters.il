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
#---------saving new uninitialzed variable array------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, 276($fp)
subu $sp, $sp, 4 #push stack
sw $25, 272($fp)
subu $sp, $sp, 4 #push stack
sw $25, 268($fp)
subu $sp, $sp, 4 #push stack
sw $25, 264($fp)
subu $sp, $sp, 4 #push stack
sw $25, 260($fp)
subu $sp, $sp, 4 #push stack
sw $25, 256($fp)
subu $sp, $sp, 4 #push stack
sw $25, 252($fp)
subu $sp, $sp, 4 #push stack
sw $25, 248($fp)
subu $sp, $sp, 4 #push stack
sw $25, 244($fp)
subu $sp, $sp, 4 #push stack
sw $25, 240($fp)
subu $sp, $sp, 4 #push stack
sw $25, 236($fp)
subu $sp, $sp, 4 #push stack
sw $25, 232($fp)
subu $sp, $sp, 4 #push stack
sw $25, 228($fp)
subu $sp, $sp, 4 #push stack
sw $25, 224($fp)
subu $sp, $sp, 4 #push stack
sw $25, 220($fp)
subu $sp, $sp, 4 #push stack
sw $25, 216($fp)
subu $sp, $sp, 4 #push stack
sw $25, 212($fp)
subu $sp, $sp, 4 #push stack
sw $25, 208($fp)
subu $sp, $sp, 4 #push stack
sw $25, 204($fp)
subu $sp, $sp, 4 #push stack
sw $25, 200($fp)
subu $sp, $sp, 4 #push stack
sw $25, 196($fp)
subu $sp, $sp, 4 #push stack
sw $25, 192($fp)
subu $sp, $sp, 4 #push stack
sw $25, 188($fp)
subu $sp, $sp, 4 #push stack
sw $25, 184($fp)
subu $sp, $sp, 4 #push stack
sw $25, 180($fp)
subu $sp, $sp, 4 #push stack
sw $25, 176($fp)
subu $sp, $sp, 4 #push stack
sw $25, 172($fp)
subu $sp, $sp, 4 #push stack
sw $25, 168($fp)
subu $sp, $sp, 4 #push stack
sw $25, 164($fp)
subu $sp, $sp, 4 #push stack
sw $25, 160($fp)
subu $sp, $sp, 4 #push stack
sw $25, 156($fp)
subu $sp, $sp, 4 #push stack
sw $25, 152($fp)
subu $sp, $sp, 4 #push stack
sw $25, 148($fp)
subu $sp, $sp, 4 #push stack
sw $25, 144($fp)
subu $sp, $sp, 4 #push stack
sw $25, 140($fp)
subu $sp, $sp, 4 #push stack
sw $25, 136($fp)
subu $sp, $sp, 4 #push stack
sw $25, 132($fp)
subu $sp, $sp, 4 #push stack
sw $25, 128($fp)
subu $sp, $sp, 4 #push stack
sw $25, 124($fp)
subu $sp, $sp, 4 #push stack
sw $25, 120($fp)
subu $sp, $sp, 4 #push stack
sw $25, 116($fp)
subu $sp, $sp, 4 #push stack
sw $25, 112($fp)
subu $sp, $sp, 4 #push stack
sw $25, 108($fp)
subu $sp, $sp, 4 #push stack
sw $25, 104($fp)
subu $sp, $sp, 4 #push stack
sw $25, 100($fp)
subu $sp, $sp, 4 #push stack
sw $25, 96($fp)
subu $sp, $sp, 4 #push stack
sw $25, 92($fp)
subu $sp, $sp, 4 #push stack
sw $25, 88($fp)
subu $sp, $sp, 4 #push stack
sw $25, 84($fp)
subu $sp, $sp, 4 #push stack
sw $25, 80($fp)
subu $sp, $sp, 4 #push stack
sw $25, 76($fp)
subu $sp, $sp, 4 #push stack
sw $25, 72($fp)
subu $sp, $sp, 4 #push stack
sw $25, 68($fp)
subu $sp, $sp, 4 #push stack
sw $25, 64($fp)
subu $sp, $sp, 4 #push stack
sw $25, 60($fp)
subu $sp, $sp, 4 #push stack
sw $25, 56($fp)
subu $sp, $sp, 4 #push stack
sw $25, 52($fp)
subu $sp, $sp, 4 #push stack
sw $25, 48($fp)
subu $sp, $sp, 4 #push stack
sw $25, 44($fp)
subu $sp, $sp, 4 #push stack
sw $25, 40($fp)
subu $sp, $sp, 4 #push stack
sw $25, 36($fp)
subu $sp, $sp, 4 #push stack
sw $25, 32($fp)
subu $sp, $sp, 4 #push stack
sw $25, 28($fp)
subu $sp, $sp, 4 #push stack
sw $25, 24($fp)
subu $sp, $sp, 4 #push stack
sw $25, 20($fp)
subu $sp, $sp, 4 #push stack
sw $25, 16($fp)
subu $sp, $sp, 4 #push stack
sw $25, 12($fp)
subu $sp, $sp, 4 #push stack
sw $25, 8($fp)
subu $sp, $sp, 4 #push stack
sw $25, 4($fp)
subu $sp, $sp, 4 #push stack
sw $25, 0($fp)
#---------finished saving new variable -----------
#---------saving new uninitialzed variable win------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, 636($fp)
subu $sp, $sp, 4 #push stack
sw $25, 632($fp)
subu $sp, $sp, 4 #push stack
sw $25, 628($fp)
subu $sp, $sp, 4 #push stack
sw $25, 624($fp)
subu $sp, $sp, 4 #push stack
sw $25, 620($fp)
subu $sp, $sp, 4 #push stack
sw $25, 616($fp)
subu $sp, $sp, 4 #push stack
sw $25, 612($fp)
subu $sp, $sp, 4 #push stack
sw $25, 608($fp)
subu $sp, $sp, 4 #push stack
sw $25, 604($fp)
subu $sp, $sp, 4 #push stack
sw $25, 600($fp)
subu $sp, $sp, 4 #push stack
sw $25, 596($fp)
subu $sp, $sp, 4 #push stack
sw $25, 592($fp)
subu $sp, $sp, 4 #push stack
sw $25, 588($fp)
subu $sp, $sp, 4 #push stack
sw $25, 584($fp)
subu $sp, $sp, 4 #push stack
sw $25, 580($fp)
subu $sp, $sp, 4 #push stack
sw $25, 576($fp)
subu $sp, $sp, 4 #push stack
sw $25, 572($fp)
subu $sp, $sp, 4 #push stack
sw $25, 568($fp)
subu $sp, $sp, 4 #push stack
sw $25, 564($fp)
subu $sp, $sp, 4 #push stack
sw $25, 560($fp)
subu $sp, $sp, 4 #push stack
sw $25, 556($fp)
subu $sp, $sp, 4 #push stack
sw $25, 552($fp)
subu $sp, $sp, 4 #push stack
sw $25, 548($fp)
subu $sp, $sp, 4 #push stack
sw $25, 544($fp)
subu $sp, $sp, 4 #push stack
sw $25, 540($fp)
subu $sp, $sp, 4 #push stack
sw $25, 536($fp)
subu $sp, $sp, 4 #push stack
sw $25, 532($fp)
subu $sp, $sp, 4 #push stack
sw $25, 528($fp)
subu $sp, $sp, 4 #push stack
sw $25, 524($fp)
subu $sp, $sp, 4 #push stack
sw $25, 520($fp)
subu $sp, $sp, 4 #push stack
sw $25, 516($fp)
subu $sp, $sp, 4 #push stack
sw $25, 512($fp)
subu $sp, $sp, 4 #push stack
sw $25, 508($fp)
subu $sp, $sp, 4 #push stack
sw $25, 504($fp)
subu $sp, $sp, 4 #push stack
sw $25, 500($fp)
subu $sp, $sp, 4 #push stack
sw $25, 496($fp)
subu $sp, $sp, 4 #push stack
sw $25, 492($fp)
subu $sp, $sp, 4 #push stack
sw $25, 488($fp)
subu $sp, $sp, 4 #push stack
sw $25, 484($fp)
subu $sp, $sp, 4 #push stack
sw $25, 480($fp)
subu $sp, $sp, 4 #push stack
sw $25, 476($fp)
subu $sp, $sp, 4 #push stack
sw $25, 472($fp)
subu $sp, $sp, 4 #push stack
sw $25, 468($fp)
subu $sp, $sp, 4 #push stack
sw $25, 464($fp)
subu $sp, $sp, 4 #push stack
sw $25, 460($fp)
subu $sp, $sp, 4 #push stack
sw $25, 456($fp)
subu $sp, $sp, 4 #push stack
sw $25, 452($fp)
subu $sp, $sp, 4 #push stack
sw $25, 448($fp)
subu $sp, $sp, 4 #push stack
sw $25, 444($fp)
subu $sp, $sp, 4 #push stack
sw $25, 440($fp)
subu $sp, $sp, 4 #push stack
sw $25, 436($fp)
subu $sp, $sp, 4 #push stack
sw $25, 432($fp)
subu $sp, $sp, 4 #push stack
sw $25, 428($fp)
subu $sp, $sp, 4 #push stack
sw $25, 424($fp)
subu $sp, $sp, 4 #push stack
sw $25, 420($fp)
subu $sp, $sp, 4 #push stack
sw $25, 416($fp)
subu $sp, $sp, 4 #push stack
sw $25, 412($fp)
subu $sp, $sp, 4 #push stack
sw $25, 408($fp)
subu $sp, $sp, 4 #push stack
sw $25, 404($fp)
subu $sp, $sp, 4 #push stack
sw $25, 400($fp)
subu $sp, $sp, 4 #push stack
sw $25, 396($fp)
subu $sp, $sp, 4 #push stack
sw $25, 392($fp)
subu $sp, $sp, 4 #push stack
sw $25, 388($fp)
subu $sp, $sp, 4 #push stack
sw $25, 384($fp)
subu $sp, $sp, 4 #push stack
sw $25, 380($fp)
subu $sp, $sp, 4 #push stack
sw $25, 376($fp)
subu $sp, $sp, 4 #push stack
sw $25, 372($fp)
subu $sp, $sp, 4 #push stack
sw $25, 368($fp)
subu $sp, $sp, 4 #push stack
sw $25, 364($fp)
subu $sp, $sp, 4 #push stack
sw $25, 360($fp)
subu $sp, $sp, 4 #push stack
sw $25, 356($fp)
subu $sp, $sp, 4 #push stack
sw $25, 352($fp)
subu $sp, $sp, 4 #push stack
sw $25, 348($fp)
subu $sp, $sp, 4 #push stack
sw $25, 344($fp)
subu $sp, $sp, 4 #push stack
sw $25, 340($fp)
subu $sp, $sp, 4 #push stack
sw $25, 336($fp)
subu $sp, $sp, 4 #push stack
sw $25, 332($fp)
subu $sp, $sp, 4 #push stack
sw $25, 328($fp)
subu $sp, $sp, 4 #push stack
sw $25, 324($fp)
subu $sp, $sp, 4 #push stack
sw $25, 320($fp)
subu $sp, $sp, 4 #push stack
sw $25, 316($fp)
subu $sp, $sp, 4 #push stack
sw $25, 312($fp)
subu $sp, $sp, 4 #push stack
sw $25, 308($fp)
subu $sp, $sp, 4 #push stack
sw $25, 304($fp)
subu $sp, $sp, 4 #push stack
sw $25, 300($fp)
subu $sp, $sp, 4 #push stack
sw $25, 296($fp)
subu $sp, $sp, 4 #push stack
sw $25, 292($fp)
subu $sp, $sp, 4 #push stack
sw $25, 288($fp)
subu $sp, $sp, 4 #push stack
sw $25, 284($fp)
subu $sp, $sp, 4 #push stack
sw $25, 280($fp)
#---------finished saving new variable -----------
_bigArray_:
move $fp, $sp
sw $ra, -------finished getting array entry -----------
label_368:
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
label_374:
addu $sp, $sp, 2560 #popping 640 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
