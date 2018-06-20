.data
div_data: .asciiz "Error division by zero\n"
array_out_of_bound: .asciiz "Error index out of bounds\n"
labal_data_1: .asciiz "val is true\n"
labal_data_2: .asciiz "\n"
.text
main:
li $25, 2
li $24, 9
#---------saving new uninitialzed variable x------------
li $23, 0
subu $sp, $sp, 4 #push stack
sw $23, -4($fp)
subu $sp, $sp, 4 #push stack
sw $23, -8($fp)
#---------finished saving new variable -----------
#---------saving new uninitialzed variable y------------
li $23, 0
subu $sp, $sp, 4 #push stack
sw $23, -12($fp)
subu $sp, $sp, 4 #push stack
sw $23, -16($fp)
subu $sp, $sp, 4 #push stack
sw $23, -20($fp)
#---------finished saving new variable -----------
#---------updating array entry y------------
li $23, 2
bgt $25,$23,array_out_of_bound
li $23, 0
blt $25,$23,array_out_of_bound
li $23, -12
li $22, -4
mult $25,$22
mflo $25
addu $23,$23,$25
addu $23,$23,$fp
sw $24, ($23)
#---------finished updating array entry -----------



