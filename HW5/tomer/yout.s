.text
main: j label_1
label_1:
li $t0, 1
j label_6
label_4:
li $t0, 0
label_6:
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_10
label_10:
j label_15
label_12:
li $t0, 1
j label_17
label_15:
li $t0, 0
label_17:
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_21
label_21:
lw $t0, 0($sp)
beq $t0, 1, label_29
j label_25
label_25:
lw $t0, 4($sp)
beq $t0, 1, label_29
j label_40
label_29:
lw $t0, 4($sp)
beq $t0, 1, label_33
j label_40
label_33:
lw $t0, 0($sp)
beq $t0, 1, label_40
j label_37
label_37:
li $t0, 1
j label_42
label_40:
li $t0, 0
label_42:
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_46
label_46:
lw $t0, 4($sp)
beq $t0, 1, label_54
j label_50
label_50:
lw $t0, 8($sp)
beq $t0, 1, label_54
j label_65
label_54:
lw $t0, 8($sp)
beq $t0, 1, label_58
j label_65
label_58:
lw $t0, 8($sp)
beq $t0, 1, label_65
j label_62
label_62:
li $t0, 1
j label_67
label_65:
li $t0, 0
label_67:
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_71
label_71:
lw $t0, 8($sp)
beq $t0, 1, label_79
j label_75
label_75:
lw $t0, 8($sp)
beq $t0, 1, label_79
j label_90
label_79:
lw $t0, 8($sp)
beq $t0, 1, label_90
j label_83
label_83:
lw $t0, 8($sp)
beq $t0, 1, label_90
j label_87
label_87:
li $t0, 1
j label_92
label_90:
li $t0, 0
label_92:
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_96
label_96:
li $t0, 2
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_101
label_101:
li $t0, 10
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_106
label_106:
li $t0, 5
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_111
label_111:
label_112:
lw $t0, 8($sp)
li $t1, 1
bgt $t0, $t1, label_117
j label_151
label_117:
label_118:
lw $t0, 4($sp)
li $t1, 2
bgt $t0, $t1, label_123
j label_130
label_123:
j label_130
label_125:
li $t0, 2
sw $t0, 4($sp)
j label_118
j label_118
label_130:
lw $t0, 20($sp)
beq $t0, 1, label_138
j label_134
label_134:
lw $t0, 12($sp)
beq $t0, 1, label_138
j label_140
label_138:
j label_151
label_140:
li $t0, 8
sw $t0, 0($sp)
j label_144
label_144:
lw $t0, 8($sp)
li $t1, 1
sub $t0, $t0, $t1
sw $t0, 8($sp)
j label_112
j label_112
label_151:
li $t0, 9
subu $sp, $sp, 4
sw $t0, 0($sp)
j label_156
label_156:
jr $ra