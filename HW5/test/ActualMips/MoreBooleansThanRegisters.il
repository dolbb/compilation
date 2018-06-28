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
#---------saving new uninitialzed variable c------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -4($fp)
#---------finished saving new variable -----------
# input line number: 2 :: parser.ypp line number: 305
j label_35
label_35:
#---------saving new uninitialzed variable d------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -8($fp)
subu $sp, $sp, 4 #push stack
sw $25, -12($fp)
subu $sp, $sp, 4 #push stack
sw $25, -16($fp)
subu $sp, $sp, 4 #push stack
sw $25, -20($fp)
subu $sp, $sp, 4 #push stack
sw $25, -24($fp)
subu $sp, $sp, 4 #push stack
sw $25, -28($fp)
subu $sp, $sp, 4 #push stack
sw $25, -32($fp)
subu $sp, $sp, 4 #push stack
sw $25, -36($fp)
subu $sp, $sp, 4 #push stack
sw $25, -40($fp)
subu $sp, $sp, 4 #push stack
sw $25, -44($fp)
subu $sp, $sp, 4 #push stack
sw $25, -48($fp)
subu $sp, $sp, 4 #push stack
sw $25, -52($fp)
subu $sp, $sp, 4 #push stack
sw $25, -56($fp)
subu $sp, $sp, 4 #push stack
sw $25, -60($fp)
subu $sp, $sp, 4 #push stack
sw $25, -64($fp)
subu $sp, $sp, 4 #push stack
sw $25, -68($fp)
subu $sp, $sp, 4 #push stack
sw $25, -72($fp)
subu $sp, $sp, 4 #push stack
sw $25, -76($fp)
subu $sp, $sp, 4 #push stack
sw $25, -80($fp)
subu $sp, $sp, 4 #push stack
sw $25, -84($fp)
subu $sp, $sp, 4 #push stack
sw $25, -88($fp)
subu $sp, $sp, 4 #push stack
sw $25, -92($fp)
subu $sp, $sp, 4 #push stack
sw $25, -96($fp)
subu $sp, $sp, 4 #push stack
sw $25, -100($fp)
subu $sp, $sp, 4 #push stack
sw $25, -104($fp)
subu $sp, $sp, 4 #push stack
sw $25, -108($fp)
subu $sp, $sp, 4 #push stack
sw $25, -112($fp)
subu $sp, $sp, 4 #push stack
sw $25, -116($fp)
subu $sp, $sp, 4 #push stack
sw $25, -120($fp)
subu $sp, $sp, 4 #push stack
sw $25, -124($fp)
subu $sp, $sp, 4 #push stack
sw $25, -128($fp)
subu $sp, $sp, 4 #push stack
sw $25, -132($fp)
subu $sp, $sp, 4 #push stack
sw $25, -136($fp)
subu $sp, $sp, 4 #push stack
sw $25, -140($fp)
subu $sp, $sp, 4 #push stack
sw $25, -144($fp)
subu $sp, $sp, 4 #push stack
sw $25, -148($fp)
subu $sp, $sp, 4 #push stack
sw $25, -152($fp)
subu $sp, $sp, 4 #push stack
sw $25, -156($fp)
subu $sp, $sp, 4 #push stack
sw $25, -160($fp)
subu $sp, $sp, 4 #push stack
sw $25, -164($fp)
subu $sp, $sp, 4 #push stack
sw $25, -168($fp)
subu $sp, $sp, 4 #push stack
sw $25, -172($fp)
subu $sp, $sp, 4 #push stack
sw $25, -176($fp)
subu $sp, $sp, 4 #push stack
sw $25, -180($fp)
subu $sp, $sp, 4 #push stack
sw $25, -184($fp)
subu $sp, $sp, 4 #push stack
sw $25, -188($fp)
subu $sp, $sp, 4 #push stack
sw $25, -192($fp)
subu $sp, $sp, 4 #push stack
sw $25, -196($fp)
subu $sp, $sp, 4 #push stack
sw $25, -200($fp)
subu $sp, $sp, 4 #push stack
sw $25, -204($fp)
subu $sp, $sp, 4 #push stack
sw $25, -208($fp)
subu $sp, $sp, 4 #push stack
sw $25, -212($fp)
subu $sp, $sp, 4 #push stack
sw $25, -216($fp)
subu $sp, $sp, 4 #push stack
sw $25, -220($fp)
subu $sp, $sp, 4 #push stack
sw $25, -224($fp)
subu $sp, $sp, 4 #push stack
sw $25, -228($fp)
subu $sp, $sp, 4 #push stack
sw $25, -232($fp)
subu $sp, $sp, 4 #push stack
sw $25, -236($fp)
subu $sp, $sp, 4 #push stack
sw $25, -240($fp)
subu $sp, $sp, 4 #push stack
sw $25, -244($fp)
subu $sp, $sp, 4 #push stack
sw $25, -248($fp)
subu $sp, $sp, 4 #push stack
sw $25, -252($fp)
subu $sp, $sp, 4 #push stack
sw $25, -256($fp)
subu $sp, $sp, 4 #push stack
sw $25, -260($fp)
subu $sp, $sp, 4 #push stack
sw $25, -264($fp)
subu $sp, $sp, 4 #push stack
sw $25, -268($fp)
subu $sp, $sp, 4 #push stack
sw $25, -272($fp)
subu $sp, $sp, 4 #push stack
sw $25, -276($fp)
subu $sp, $sp, 4 #push stack
sw $25, -280($fp)
subu $sp, $sp, 4 #push stack
sw $25, -284($fp)
subu $sp, $sp, 4 #push stack
sw $25, -288($fp)
subu $sp, $sp, 4 #push stack
sw $25, -292($fp)
subu $sp, $sp, 4 #push stack
sw $25, -296($fp)
subu $sp, $sp, 4 #push stack
sw $25, -300($fp)
subu $sp, $sp, 4 #push stack
sw $25, -304($fp)
subu $sp, $sp, 4 #push stack
sw $25, -308($fp)
subu $sp, $sp, 4 #push stack
sw $25, -312($fp)
subu $sp, $sp, 4 #push stack
sw $25, -316($fp)
subu $sp, $sp, 4 #push stack
sw $25, -320($fp)
subu $sp, $sp, 4 #push stack
sw $25, -324($fp)
subu $sp, $sp, 4 #push stack
sw $25, -328($fp)
subu $sp, $sp, 4 #push stack
sw $25, -332($fp)
subu $sp, $sp, 4 #push stack
sw $25, -336($fp)
subu $sp, $sp, 4 #push stack
sw $25, -340($fp)
subu $sp, $sp, 4 #push stack
sw $25, -344($fp)
subu $sp, $sp, 4 #push stack
sw $25, -348($fp)
subu $sp, $sp, 4 #push stack
sw $25, -352($fp)
subu $sp, $sp, 4 #push stack
sw $25, -356($fp)
subu $sp, $sp, 4 #push stack
sw $25, -360($fp)
subu $sp, $sp, 4 #push stack
sw $25, -364($fp)
subu $sp, $sp, 4 #push stack
sw $25, -368($fp)
subu $sp, $sp, 4 #push stack
sw $25, -372($fp)
subu $sp, $sp, 4 #push stack
sw $25, -376($fp)
subu $sp, $sp, 4 #push stack
sw $25, -380($fp)
subu $sp, $sp, 4 #push stack
sw $25, -384($fp)
subu $sp, $sp, 4 #push stack
sw $25, -388($fp)
subu $sp, $sp, 4 #push stack
sw $25, -392($fp)
subu $sp, $sp, 4 #push stack
sw $25, -396($fp)
subu $sp, $sp, 4 #push stack
sw $25, -400($fp)
subu $sp, $sp, 4 #push stack
sw $25, -404($fp)
subu $sp, $sp, 4 #push stack
sw $25, -408($fp)
subu $sp, $sp, 4 #push stack
sw $25, -412($fp)
subu $sp, $sp, 4 #push stack
sw $25, -416($fp)
subu $sp, $sp, 4 #push stack
sw $25, -420($fp)
subu $sp, $sp, 4 #push stack
sw $25, -424($fp)
subu $sp, $sp, 4 #push stack
sw $25, -428($fp)
subu $sp, $sp, 4 #push stack
sw $25, -432($fp)
subu $sp, $sp, 4 #push stack
sw $25, -436($fp)
subu $sp, $sp, 4 #push stack
sw $25, -440($fp)
subu $sp, $sp, 4 #push stack
sw $25, -444($fp)
subu $sp, $sp, 4 #push stack
sw $25, -448($fp)
subu $sp, $sp, 4 #push stack
sw $25, -452($fp)
subu $sp, $sp, 4 #push stack
sw $25, -456($fp)
subu $sp, $sp, 4 #push stack
sw $25, -460($fp)
subu $sp, $sp, 4 #push stack
sw $25, -464($fp)
subu $sp, $sp, 4 #push stack
sw $25, -468($fp)
subu $sp, $sp, 4 #push stack
sw $25, -472($fp)
subu $sp, $sp, 4 #push stack
sw $25, -476($fp)
subu $sp, $sp, 4 #push stack
sw $25, -480($fp)
subu $sp, $sp, 4 #push stack
sw $25, -484($fp)
subu $sp, $sp, 4 #push stack
sw $25, -488($fp)
subu $sp, $sp, 4 #push stack
sw $25, -492($fp)
subu $sp, $sp, 4 #push stack
sw $25, -496($fp)
subu $sp, $sp, 4 #push stack
sw $25, -500($fp)
subu $sp, $sp, 4 #push stack
sw $25, -504($fp)
subu $sp, $sp, 4 #push stack
sw $25, -508($fp)
subu $sp, $sp, 4 #push stack
sw $25, -512($fp)
subu $sp, $sp, 4 #push stack
sw $25, -516($fp)
subu $sp, $sp, 4 #push stack
sw $25, -520($fp)
subu $sp, $sp, 4 #push stack
sw $25, -524($fp)
subu $sp, $sp, 4 #push stack
sw $25, -528($fp)
subu $sp, $sp, 4 #push stack
sw $25, -532($fp)
subu $sp, $sp, 4 #push stack
sw $25, -536($fp)
subu $sp, $sp, 4 #push stack
sw $25, -540($fp)
subu $sp, $sp, 4 #push stack
sw $25, -544($fp)
subu $sp, $sp, 4 #push stack
sw $25, -548($fp)
subu $sp, $sp, 4 #push stack
sw $25, -552($fp)
subu $sp, $sp, 4 #push stack
sw $25, -556($fp)
subu $sp, $sp, 4 #push stack
sw $25, -560($fp)
subu $sp, $sp, 4 #push stack
sw $25, -564($fp)
subu $sp, $sp, 4 #push stack
sw $25, -568($fp)
subu $sp, $sp, 4 #push stack
sw $25, -572($fp)
subu $sp, $sp, 4 #push stack
sw $25, -576($fp)
subu $sp, $sp, 4 #push stack
sw $25, -580($fp)
subu $sp, $sp, 4 #push stack
sw $25, -584($fp)
subu $sp, $sp, 4 #push stack
sw $25, -588($fp)
subu $sp, $sp, 4 #push stack
sw $25, -592($fp)
subu $sp, $sp, 4 #push stack
sw $25, -596($fp)
subu $sp, $sp, 4 #push stack
sw $25, -600($fp)
subu $sp, $sp, 4 #push stack
sw $25, -604($fp)
subu $sp, $sp, 4 #push stack
sw $25, -608($fp)
subu $sp, $sp, 4 #push stack
sw $25, -612($fp)
subu $sp, $sp, 4 #push stack
sw $25, -616($fp)
subu $sp, $sp, 4 #push stack
sw $25, -620($fp)
subu $sp, $sp, 4 #push stack
sw $25, -624($fp)
subu $sp, $sp, 4 #push stack
sw $25, -628($fp)
subu $sp, $sp, 4 #push stack
sw $25, -632($fp)
subu $sp, $sp, 4 #push stack
sw $25, -636($fp)
subu $sp, $sp, 4 #push stack
sw $25, -640($fp)
subu $sp, $sp, 4 #push stack
sw $25, -644($fp)
subu $sp, $sp, 4 #push stack
sw $25, -648($fp)
subu $sp, $sp, 4 #push stack
sw $25, -652($fp)
subu $sp, $sp, 4 #push stack
sw $25, -656($fp)
subu $sp, $sp, 4 #push stack
sw $25, -660($fp)
subu $sp, $sp, 4 #push stack
sw $25, -664($fp)
subu $sp, $sp, 4 #push stack
sw $25, -668($fp)
subu $sp, $sp, 4 #push stack
sw $25, -672($fp)
subu $sp, $sp, 4 #push stack
sw $25, -676($fp)
subu $sp, $sp, 4 #push stack
sw $25, -680($fp)
subu $sp, $sp, 4 #push stack
sw $25, -684($fp)
subu $sp, $sp, 4 #push stack
sw $25, -688($fp)
subu $sp, $sp, 4 #push stack
sw $25, -692($fp)
subu $sp, $sp, 4 #push stack
sw $25, -696($fp)
subu $sp, $sp, 4 #push stack
sw $25, -700($fp)
subu $sp, $sp, 4 #push stack
sw $25, -704($fp)
subu $sp, $sp, 4 #push stack
sw $25, -708($fp)
subu $sp, $sp, 4 #push stack
sw $25, -712($fp)
subu $sp, $sp, 4 #push stack
sw $25, -716($fp)
subu $sp, $sp, 4 #push stack
sw $25, -720($fp)
subu $sp, $sp, 4 #push stack
sw $25, -724($fp)
subu $sp, $sp, 4 #push stack
sw $25, -728($fp)
subu $sp, $sp, 4 #push stack
sw $25, -732($fp)
subu $sp, $sp, 4 #push stack
sw $25, -736($fp)
subu $sp, $sp, 4 #push stack
sw $25, -740($fp)
subu $sp, $sp, 4 #push stack
sw $25, -744($fp)
subu $sp, $sp, 4 #push stack
sw $25, -748($fp)
subu $sp, $sp, 4 #push stack
sw $25, -752($fp)
subu $sp, $sp, 4 #push stack
sw $25, -756($fp)
subu $sp, $sp, 4 #push stack
sw $25, -760($fp)
subu $sp, $sp, 4 #push stack
sw $25, -764($fp)
subu $sp, $sp, 4 #push stack
sw $25, -768($fp)
subu $sp, $sp, 4 #push stack
sw $25, -772($fp)
subu $sp, $sp, 4 #push stack
sw $25, -776($fp)
subu $sp, $sp, 4 #push stack
sw $25, -780($fp)
subu $sp, $sp, 4 #push stack
sw $25, -784($fp)
subu $sp, $sp, 4 #push stack
sw $25, -788($fp)
subu $sp, $sp, 4 #push stack
sw $25, -792($fp)
subu $sp, $sp, 4 #push stack
sw $25, -796($fp)
subu $sp, $sp, 4 #push stack
sw $25, -800($fp)
subu $sp, $sp, 4 #push stack
sw $25, -804($fp)
#---------finished saving new variable -----------
# input line number: 3 :: parser.ypp line number: 375
j label_443
# input line number: 3 :: parser.ypp line number: 284
j label_443
label_443:
#---------saving new uninitialzed variable e------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -808($fp)
#---------finished saving new variable -----------
# input line number: 4 :: parser.ypp line number: 305
j label_453
# input line number: 4 :: parser.ypp line number: 284
j label_453
label_453:
#---------saving new uninitialzed variable f------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -812($fp)
#---------finished saving new variable -----------
# input line number: 5 :: parser.ypp line number: 305
j label_463
# input line number: 5 :: parser.ypp line number: 284
j label_463
label_463:
#---------saving new uninitialzed variable g------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -816($fp)
#---------finished saving new variable -----------
# input line number: 6 :: parser.ypp line number: 305
j label_473
# input line number: 6 :: parser.ypp line number: 284
j label_473
label_473:
#---------saving new uninitialzed variable h------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -820($fp)
#---------finished saving new variable -----------
# input line number: 7 :: parser.ypp line number: 305
j label_483
# input line number: 7 :: parser.ypp line number: 284
j label_483
label_483:
#---------saving new uninitialzed variable i------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -824($fp)
#---------finished saving new variable -----------
# input line number: 8 :: parser.ypp line number: 305
j label_493
# input line number: 8 :: parser.ypp line number: 284
j label_493
label_493:
#---------saving new uninitialzed variable j------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -828($fp)
#---------finished saving new variable -----------
# input line number: 9 :: parser.ypp line number: 305
j label_503
# input line number: 9 :: parser.ypp line number: 284
j label_503
label_503:
#---------saving new uninitialzed variable k------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -832($fp)
#---------finished saving new variable -----------
# input line number: 10 :: parser.ypp line number: 305
j label_513
# input line number: 10 :: parser.ypp line number: 284
j label_513
label_513:
#---------saving new uninitialzed variable l------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -836($fp)
#---------finished saving new variable -----------
# input line number: 11 :: parser.ypp line number: 305
j label_523
# input line number: 11 :: parser.ypp line number: 284
j label_523
label_523:
#---------saving new uninitialzed variable m------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -840($fp)
#---------finished saving new variable -----------
# input line number: 12 :: parser.ypp line number: 305
j label_533
# input line number: 12 :: parser.ypp line number: 284
j label_533
label_533:
#---------saving new uninitialzed variable n------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -844($fp)
#---------finished saving new variable -----------
# input line number: 13 :: parser.ypp line number: 305
j label_543
# input line number: 13 :: parser.ypp line number: 284
j label_543
label_543:
#---------saving new uninitialzed variable o------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -848($fp)
#---------finished saving new variable -----------
# input line number: 14 :: parser.ypp line number: 305
j label_553
# input line number: 14 :: parser.ypp line number: 284
j label_553
label_553:
#---------saving new uninitialzed variable p------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -852($fp)
#---------finished saving new variable -----------
# input line number: 15 :: parser.ypp line number: 305
j label_563
# input line number: 15 :: parser.ypp line number: 284
j label_563
label_563:
#---------saving new uninitialzed variable q------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -856($fp)
#---------finished saving new variable -----------
# input line number: 16 :: parser.ypp line number: 305
j label_573
# input line number: 16 :: parser.ypp line number: 284
j label_573
label_573:
#---------saving new uninitialzed variable r------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -860($fp)
#---------finished saving new variable -----------
# input line number: 17 :: parser.ypp line number: 305
j label_583
# input line number: 17 :: parser.ypp line number: 284
j label_583
label_583:
#---------saving new uninitialzed variable s------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -864($fp)
#---------finished saving new variable -----------
# input line number: 18 :: parser.ypp line number: 305
j label_593
# input line number: 18 :: parser.ypp line number: 284
j label_593
label_593:
#---------saving new uninitialzed variable t------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -868($fp)
#---------finished saving new variable -----------
# input line number: 19 :: parser.ypp line number: 305
j label_603
# input line number: 19 :: parser.ypp line number: 284
j label_603
label_603:
#---------saving new uninitialzed variable u------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -872($fp)
#---------finished saving new variable -----------
# input line number: 20 :: parser.ypp line number: 305
j label_613
# input line number: 20 :: parser.ypp line number: 284
j label_613
label_613:
#---------saving new uninitialzed variable v------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -876($fp)
#---------finished saving new variable -----------
# input line number: 21 :: parser.ypp line number: 305
j label_623
# input line number: 21 :: parser.ypp line number: 284
j label_623
label_623:
#---------saving new uninitialzed variable w------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -880($fp)
#---------finished saving new variable -----------
# input line number: 22 :: parser.ypp line number: 305
j label_633
# input line number: 22 :: parser.ypp line number: 284
j label_633
label_633:
#---------saving new uninitialzed variable x------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -884($fp)
#---------finished saving new variable -----------
# input line number: 23 :: parser.ypp line number: 305
j label_643
# input line number: 23 :: parser.ypp line number: 284
j label_643
label_643:
#---------saving new uninitialzed variable y------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -888($fp)
#---------finished saving new variable -----------
# input line number: 24 :: parser.ypp line number: 305
j label_653
# input line number: 24 :: parser.ypp line number: 284
j label_653
label_653:
#---------saving new uninitialzed variable z------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -892($fp)
#---------finished saving new variable -----------
# input line number: 25 :: parser.ypp line number: 305
j label_663
# input line number: 25 :: parser.ypp line number: 284
j label_663
label_663:
#---------saving new uninitialzed variable a------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -896($fp)
#---------finished saving new variable -----------
# input line number: 26 :: parser.ypp line number: 305
j label_673
# input line number: 26 :: parser.ypp line number: 284
j label_673
label_673:
addu $sp, $sp, 896 #popping 224 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
