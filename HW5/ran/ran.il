reg1 is x$25
reg2 is y$24
reg3 is z$23
.text
#---------saving new uninitialzed variable x------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, 0($fp)
#---------finished saving new variable -----------
#---------saving new uninitialzed variable y------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, 4($fp)
#---------finished saving new variable -----------
#---------saving new uninitialzed variable y------------
li $25, 0
subu $sp, $sp, 4 #push stack
sw $25, 4($fp)
#---------finished saving new variable -----------
li $25, 1
li $24, 2
li $23, 3
#---------updating variable x------------
sw $25, 0($fp)
#---------finished updating variable -----------
#---------updating variable y------------
sw $24, 4($fp)
#---------finished updating variable -----------
#---------updating variable z------------
sw $23, -4($fp)
#---------finished updating variable -----------
