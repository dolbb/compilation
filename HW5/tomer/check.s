.data
div_data: .asciiz "Error division by zero\n"
labal_data_1: .asciiz "funcByteTrue\n"
labal_data_2: .asciiz "funcHelper2-1\n"
labal_data_3: .asciiz "funcHelper2-2\n"
labal_data_4: .asciiz "funcHelper2-3\n"
labal_data_5: .asciiz "funcHelper2-4\n"
.text
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
funcByteTrue_:
move $fp, $sp
sw $ra, 0($sp)
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_35:
la $t0, labal_data_1
j label_38
label_38:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_43
label_43:
label_44:
j label_46
label_46:
li $v1, 1
j label_51
label_49:
li $v1, 0
label_51:
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
label_57:
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
funcHelper2_:
move $fp, $sp
sw $ra, 8($sp)
label_66:
lw $t0, 0($fp) #load
beq $t0, 1, label_70
j label_85
label_70:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_74:
la $t0, labal_data_2
j label_77
label_77:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_82
label_82:
j label_99
j label_99
label_85:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_89:
la $t0, labal_data_3
j label_92
label_92:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_97
label_97:
j label_99
label_99:
label_100:
lw $t0, 4($fp) #load
beq $t0, 1, label_104
j label_119
label_104:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_108:
la $t0, labal_data_4
j label_111
label_111:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_116
label_116:
j label_133
j label_133
label_119:
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
label_123:
la $t0, labal_data_5
j label_126
label_126:
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal print_
j label_131
label_131:
j label_133
label_133:
addu $sp, $sp, 8 #pop
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
main_:
move $fp, $sp
sw $ra, 0($sp)
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
jal funcByteTrue_
label_150:
move $t0, $v1
beq $t0, 1, label_163
j label_166
subu $sp, $sp, 4 #push
sw $fp, ($sp) #storeFP
subu $sp, $sp, 4 #push
jal funcByteTrue_
label_158:
move $t0, $v1
beq $t0, 1, label_169
j label_172
j label_175
label_163:
li $t0, 1
j label_158
label_166:
li $t0, 0
j label_158
label_169:
li $t1, 1
j label_175
label_172:
li $t1, 0
j label_175
label_175:
subu $sp, $sp, 4 #push
sw $t1, ($sp) #storeRegister
subu $sp, $sp, 4 #push
sw $t0, ($sp) #storeRegister
jal funcHelper2_
j label_182
label_182:
lw $ra, ($sp)
addu $sp, $sp, 4 #pop
lw $fp, ($sp)
addu $sp, $sp, 4 #pop
jr $ra
