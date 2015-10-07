.text # .xxxx is assembler diractives
la $a0,indata # **Important fact is $a0 is kinda pointer it holds the starting memory adress of the 20 consegetive bytes allocated during programm startup by .space
li $a1,10
li $v0,8
syscall

la $a0,new_line
li $v0,4
syscall

la $a0,indata
syscall


li $v0,10
syscall

.data
indata: .space 20
new_line: .asciiz "\n"