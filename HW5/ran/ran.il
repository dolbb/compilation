.data
div_data: .asciiz "Error division by zero\n"
labal_data_1: .asciiz "val is true\n"
labal_data_2: .asciiz "\n"
.text
j main
div_text:
subu $sp, $sp, 4 #push
subu $sp, $sp, 4 #push
la $v1, div_data
subu $sp, $sp, 4 #push
sw $v1, ($sp)
jal print_
li $v0 10
syscall
printi_:
lw $a0,0($sp)
li $v0,1
syscall
addu $sp, $sp, 8 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
print_:
lw $a0,0($sp)
li $v0,4
syscall
addu $sp, $sp, 8 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
main:
subu $sp, $sp, 4 #push
subu $sp, $sp, 4 #push
j main_
printByValue_:
move $fp, $sp
sw $ra, 4($sp)
label_32:
lw $t0, 0($fp) #load
beq $t0, 1, label_36
j label_50
label_36:
label_37:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_41:
la $t0, labal_data_1
j label_44
label_44:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_78
j label_78
label_50:
label_51:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_55:
li $t0, 42
j label_58
label_58:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal printi_
j label_63
label_63:
label_64:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_68:
la $t0, labal_data_2
j label_71
label_71:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_76
label_76:
j label_78
label_78:
addu $sp, $sp, 4 #pop
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
ran_:
move $fp, $sp
sw $ra, 0($sp)
label_88:
li $t0, 2
subu $sp, $sp, 4 #push
sw $t0, -4($fp) #store
j label_93
label_93:
label_94:
lw $t0, -4($fp) #load
move $v1, $t0
addu $sp, $sp, 4 #pop
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
label_103:
addu $sp, $sp, 4 #pop
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
main_:
move $fp, $sp
sw $ra, 0($sp)
label_113:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_117:
j label_120
j label_126
label_120:
li $t0, 1
j label_126
label_123:
li $t0, 0
j label_126
label_126:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal printByValue_
j label_131
label_131:
label_132:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_136:
j label_142
j label_145
label_139:
li $t0, 1
j label_145
label_142:
li $t0, 0
j label_145
label_145:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal printByValue_
j label_150
label_150:
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
