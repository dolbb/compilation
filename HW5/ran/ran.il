reg1 is x$25
reg2 is y$24
reg3 is z$23
.text
li $25, 2
li $24, 9
li $23, 3
#---------saving new uninitialzed variable x------------
li $22, 0
subu $sp, $sp, 4 #push stack
sw $22, -4($fp)
subu $sp, $sp, 4 #push stack
sw $22, -8($fp)
subu $sp, $sp, 4 #push stack
sw $22, -12($fp)
#---------finished saving new variable -----------
#---------updating array entry x------------
li $22, 2
bgt $25,$22,array_out_of_bound
li $22, 0
blt $25,$22,array_out_of_bound
move $21,$25
li $22, -4
li $20, -4
mult $21,$20
mflo $21
addu $22,$22,$21
addu $22,$22,$fp
sw $24, ($22)
#---------finished updating array entry -----------
#----- jumping to functiontest
#--- store fp on stack ---
subu $sp, $sp, 4 #push stack
sw $fp, ($sp)
#--- finished storing fp on stack ---
subu $sp, $sp, 4 #push stack
#----- passing arguments to function -----
subu $sp, $sp, 4 #push stack
sw $23, ($sp)
li $21, 0
#---------getting array entry x------------
li $20, 2
bgt $21,$20,array_out_of_bound
li $20, 0
blt $21,$20,array_out_of_bound
move $19,$21
li $20, -4
li $18, -4
mult $19,$18
mflo $19
addu $20,$20,$19
addu $20,$20,$fp
lw $22, ($20)
#---------finished getting array entry -----------
subu $sp, $sp, 4 #push stack
sw $22, ($sp)
li $21, 1
#---------getting array entry x------------
li $20, 2
bgt $21,$20,array_out_of_bound
li $20, 0
blt $21,$20,array_out_of_bound
move $19,$21
li $20, -4
li $18, -4
mult $19,$18
mflo $19
addu $20,$20,$19
addu $20,$20,$fp
lw $22, ($20)
#---------finished getting array entry -----------
subu $sp, $sp, 4 #push stack
sw $22, ($sp)
li $21, 2
#---------getting array entry x------------
li $20, 2
bgt $21,$20,array_out_of_bound
li $20, 0
blt $21,$20,array_out_of_bound
move $19,$21
li $20, -4
li $18, -4
mult $19,$18
mflo $19
addu $20,$20,$19
addu $20,$20,$fp
lw $22, ($20)
#---------finished getting array entry -----------
subu $sp, $sp, 4 #push stack
sw $22, ($sp)
subu $sp, $sp, 4 #push stack
sw $25, ($sp)
#----- finished passing arguments to function ----
jal 
#----- finished jumping to function -----
