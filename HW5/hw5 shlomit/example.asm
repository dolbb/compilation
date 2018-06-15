.data
data_Label_0: .asciiz "Error division by zero\n"
data_Label_1: .asciiz "val is true\n"
data_Label_2: .asciiz "\n"
.text
main:
jal label_143
li $v0, 10
syscall
label_4:

###### 	 print 	 ######
lw $a0, 0($sp)
li $v0, 4
syscall
jr $ra
label_10:

###### 	 printi 	 ######
lw $a0, 0($sp)
li $v0, 1
syscall
jr $ra
divByZero:
# register promoting from 7 to 8
la $8, data_Label_0
#### 	 Call Function print: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function print and save return adress at $ra
jal label_4
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function print from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
li $v0, 10
syscall
label_43:

 #________________________
 ########## Declaring Function printByValue##########
addiu $fp, $sp, -4 	# initialize the new function frame
######## 	 line 2: 	 ########
# If :: Condition Evaluation:
# register promoting from 7 to 8
#saving to $8 from val
lw $8,4($fp)
# register reducing from 8 to 7
bnez $8, label_54
j label_83
label_54:
# If :: statement:
######## 	 line 3: 	 ########
# register promoting from 7 to 8
la $8, data_Label_1
#### 	 Call Function print: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function print and save return adress at $ra
jal label_4
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function print from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
######## 	 line 4: 	 ########
j label_136
label_83:
# Else:
######## 	 line 5: 	 ########
# register promoting from 7 to 8
li $8, 42	# initialize $8 with value 42
#### 	 Call Function printi: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function printi and save return adress at $ra
jal label_10
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function printi from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
######## 	 line 6: 	 ########
# register promoting from 7 to 8
la $8, data_Label_2
#### 	 Call Function print: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function print and save return adress at $ra
jal label_4
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function print from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
######## 	 line 7: 	 ########
label_136:
######## 	 line 8: 	 ########
# remove all local variables:
addiu $sp, $fp, 4
jr $ra 	# jump back to the line after the calling line
######## 	 line 9: 	 ########
######## 	 line 10: 	 ########
label_143:

 #________________________
 ########## Declaring Function main##########
addiu $fp, $sp, -4 	# initialize the new function frame
######## 	 line 11: 	 ########
j label_148
label_148:
# register promoting from 7 to 8
li $8, 1	# initialize $8 with value 1
j label_156
# register reducing from 8 to 7
label_153:
# register promoting from 7 to 8
li $8, 0	# initialize $8 with value 0
label_156:
#### 	 Call Function printByValue: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function printByValue and save return adress at $ra
jal label_43
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function printByValue from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
######## 	 line 12: 	 ########
j label_186
label_181:
# register promoting from 7 to 8
li $8, 1	# initialize $8 with value 1
j label_189
# register reducing from 8 to 7
label_186:
# register promoting from 7 to 8
li $8, 0	# initialize $8 with value 0
label_189:
#### 	 Call Function printByValue: 	 ####
addiu $sp, $sp, -4# new space on stack for $ra(-1 words)
sw $ra, ($sp)#save register $ra on top of the stack.
addiu $sp, $sp, -4# new space on stack for $fp(-1 words)
sw $fp, ($sp)#save register $fp on top of the stack.
##### 	 save all registers: 	 #####
# num of params = 1
### 	 save non-parameter registers: 	 ###
### 	 save 1 parameter registers: 	 ###
addiu $sp, $sp, -4# new space on stack for $8(-1 words)
sw $8, ($sp)#save register $8 on top of the stack.
# jump to function printByValue and save return adress at $ra
jal label_43
# num of params = 1
# currReg reduced from 8 to 7
# register number = 7
addiu $sp, $sp, 4   # remove all params of function printByValue from stack (1 words)
# Call :: load all registers:
lw $fp, ($sp)# load register $fp
addiu $sp, $sp, 4   # remove $fp from stack (1 words)
lw $ra, ($sp)# load register $ra
addiu $sp, $sp, 4   # remove $ra from stack (1 words)
######## 	 line 13: 	 ########
# remove all local variables:
addiu $sp, $fp, 4
jr $ra 	# jump back to the line after the calling line
