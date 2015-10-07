.text
li $s0,0x00000001
li $s1,0x00000002
add $t0,$s0,$s1

li $v0,10 # Load imidiate integer 10 to the $v0 register 10 is end of programm systemcall
syscall



.data