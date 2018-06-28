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
#---------finished saving new variable -----------
# input line number: 4 :: parser.ypp line number: 375
j label_73
label_73:
#---------saving new uninitialzed variable c------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 5 :: parser.ypp line number: 375
j label_121
# input line number: 5 :: parser.ypp line number: 284
j label_121
label_121:
#---------saving new uninitialzed variable d------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 6 :: parser.ypp line number: 375
j label_169
# input line number: 6 :: parser.ypp line number: 284
j label_169
label_169:
#---------saving new uninitialzed variable e------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 7 :: parser.ypp line number: 375
j label_217
# input line number: 7 :: parser.ypp line number: 284
j label_217
label_217:
#---------saving new uninitialzed variable f------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 8 :: parser.ypp line number: 375
j label_265
# input line number: 8 :: parser.ypp line number: 284
j label_265
label_265:
#---------saving new uninitialzed variable g------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 9 :: parser.ypp line number: 375
j label_313
# input line number: 9 :: parser.ypp line number: 284
j label_313
label_313:
#---------saving new uninitialzed variable h------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 10 :: parser.ypp line number: 375
j label_361
# input line number: 10 :: parser.ypp line number: 284
j label_361
label_361:
#---------saving new uninitialzed variable i------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 11 :: parser.ypp line number: 375
j label_409
# input line number: 11 :: parser.ypp line number: 284
j label_409
label_409:
#---------saving new uninitialzed variable j------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 12 :: parser.ypp line number: 375
j label_457
# input line number: 12 :: parser.ypp line number: 284
j label_457
label_457:
#---------saving new uninitialzed variable k------------
li $25, 0
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
#---------finished saving new variable -----------
# input line number: 13 :: parser.ypp line number: 375
j label_505
# input line number: 13 :: parser.ypp line number: 284
j label_505
label_505:
#---------saving new uninitialzed variable l------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -804($fp)
subu $sp, $sp, 4 #push stack
sw $25, -808($fp)
subu $sp, $sp, 4 #push stack
sw $25, -812($fp)
subu $sp, $sp, 4 #push stack
sw $25, -816($fp)
subu $sp, $sp, 4 #push stack
sw $25, -820($fp)
subu $sp, $sp, 4 #push stack
sw $25, -824($fp)
subu $sp, $sp, 4 #push stack
sw $25, -828($fp)
subu $sp, $sp, 4 #push stack
sw $25, -832($fp)
subu $sp, $sp, 4 #push stack
sw $25, -836($fp)
subu $sp, $sp, 4 #push stack
sw $25, -840($fp)
subu $sp, $sp, 4 #push stack
sw $25, -844($fp)
subu $sp, $sp, 4 #push stack
sw $25, -848($fp)
subu $sp, $sp, 4 #push stack
sw $25, -852($fp)
subu $sp, $sp, 4 #push stack
sw $25, -856($fp)
subu $sp, $sp, 4 #push stack
sw $25, -860($fp)
subu $sp, $sp, 4 #push stack
sw $25, -864($fp)
subu $sp, $sp, 4 #push stack
sw $25, -868($fp)
subu $sp, $sp, 4 #push stack
sw $25, -872($fp)
subu $sp, $sp, 4 #push stack
sw $25, -876($fp)
subu $sp, $sp, 4 #push stack
sw $25, -880($fp)
#---------finished saving new variable -----------
# input line number: 14 :: parser.ypp line number: 375
j label_553
# input line number: 14 :: parser.ypp line number: 284
j label_553
label_553:
#---------saving new uninitialzed variable m------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -884($fp)
subu $sp, $sp, 4 #push stack
sw $25, -888($fp)
subu $sp, $sp, 4 #push stack
sw $25, -892($fp)
subu $sp, $sp, 4 #push stack
sw $25, -896($fp)
subu $sp, $sp, 4 #push stack
sw $25, -900($fp)
subu $sp, $sp, 4 #push stack
sw $25, -904($fp)
subu $sp, $sp, 4 #push stack
sw $25, -908($fp)
subu $sp, $sp, 4 #push stack
sw $25, -912($fp)
subu $sp, $sp, 4 #push stack
sw $25, -916($fp)
subu $sp, $sp, 4 #push stack
sw $25, -920($fp)
subu $sp, $sp, 4 #push stack
sw $25, -924($fp)
subu $sp, $sp, 4 #push stack
sw $25, -928($fp)
subu $sp, $sp, 4 #push stack
sw $25, -932($fp)
subu $sp, $sp, 4 #push stack
sw $25, -936($fp)
subu $sp, $sp, 4 #push stack
sw $25, -940($fp)
subu $sp, $sp, 4 #push stack
sw $25, -944($fp)
subu $sp, $sp, 4 #push stack
sw $25, -948($fp)
subu $sp, $sp, 4 #push stack
sw $25, -952($fp)
subu $sp, $sp, 4 #push stack
sw $25, -956($fp)
subu $sp, $sp, 4 #push stack
sw $25, -960($fp)
#---------finished saving new variable -----------
# input line number: 15 :: parser.ypp line number: 375
j label_601
# input line number: 15 :: parser.ypp line number: 284
j label_601
label_601:
#---------saving new uninitialzed variable n------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -964($fp)
subu $sp, $sp, 4 #push stack
sw $25, -968($fp)
subu $sp, $sp, 4 #push stack
sw $25, -972($fp)
subu $sp, $sp, 4 #push stack
sw $25, -976($fp)
subu $sp, $sp, 4 #push stack
sw $25, -980($fp)
subu $sp, $sp, 4 #push stack
sw $25, -984($fp)
subu $sp, $sp, 4 #push stack
sw $25, -988($fp)
subu $sp, $sp, 4 #push stack
sw $25, -992($fp)
subu $sp, $sp, 4 #push stack
sw $25, -996($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1000($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1004($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1008($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1012($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1016($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1020($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1024($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1028($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1032($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1036($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1040($fp)
#---------finished saving new variable -----------
# input line number: 16 :: parser.ypp line number: 375
j label_649
# input line number: 16 :: parser.ypp line number: 284
j label_649
label_649:
#---------saving new uninitialzed variable o------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1044($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1048($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1052($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1056($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1060($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1064($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1068($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1072($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1076($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1080($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1084($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1088($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1092($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1096($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1100($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1104($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1108($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1112($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1116($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1120($fp)
#---------finished saving new variable -----------
# input line number: 17 :: parser.ypp line number: 375
j label_697
# input line number: 17 :: parser.ypp line number: 284
j label_697
label_697:
#---------saving new uninitialzed variable p------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1124($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1128($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1132($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1136($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1140($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1144($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1148($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1152($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1156($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1160($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1164($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1168($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1172($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1176($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1180($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1184($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1188($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1192($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1196($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1200($fp)
#---------finished saving new variable -----------
# input line number: 18 :: parser.ypp line number: 375
j label_745
# input line number: 18 :: parser.ypp line number: 284
j label_745
label_745:
#---------saving new uninitialzed variable q------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1204($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1208($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1212($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1216($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1220($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1224($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1228($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1232($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1236($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1240($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1244($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1248($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1252($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1256($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1260($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1264($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1268($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1272($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1276($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1280($fp)
#---------finished saving new variable -----------
# input line number: 19 :: parser.ypp line number: 375
j label_793
# input line number: 19 :: parser.ypp line number: 284
j label_793
label_793:
#---------saving new uninitialzed variable r------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1284($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1288($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1292($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1296($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1300($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1304($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1308($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1312($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1316($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1320($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1324($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1328($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1332($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1336($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1340($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1344($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1348($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1352($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1356($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1360($fp)
#---------finished saving new variable -----------
# input line number: 20 :: parser.ypp line number: 375
j label_841
# input line number: 20 :: parser.ypp line number: 284
j label_841
label_841:
#---------saving new uninitialzed variable s------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1364($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1368($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1372($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1376($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1380($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1384($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1388($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1392($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1396($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1400($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1404($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1408($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1412($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1416($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1420($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1424($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1428($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1432($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1436($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1440($fp)
#---------finished saving new variable -----------
# input line number: 21 :: parser.ypp line number: 375
j label_889
# input line number: 21 :: parser.ypp line number: 284
j label_889
label_889:
#---------saving new uninitialzed variable t------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, -1444($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1448($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1452($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1456($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1460($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1464($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1468($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1472($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1476($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1480($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1484($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1488($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1492($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1496($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1500($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1504($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1508($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1512($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1516($fp)
subu $sp, $sp, 4 #push stack
sw $25, -1520($fp)
#---------finished saving new variable -----------
# input line number: 22 :: parser.ypp line number: 375
j label_937
# input line number: 22 :: parser.ypp line number: 284
j label_937
label_937:
addu $sp, $sp, 1520 #popping 380 items
lw $ra, ($sp)
addu $sp, $sp, 4 #popping 1 items
lw $fp, ($sp)
addu $sp, $sp, 4 #popping 1 items
jr $ra
