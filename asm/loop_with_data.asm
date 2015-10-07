.text

la $t0,indata
li $v0,11 # Load the system call number to be invoked in the $v0 registry, in this case it is 11
addi $t1,$t0,10

startloop: # Loop starting lable
lb $a0,($t0)
syscall
addi $t0,$t0,0x01 # add imidiatly 0x01 to containing address of $t0 and save to $t0

beq $t0,$t1,endloop # Branch if equal , $t0 register value to 0x1001011
j startloop # Jump unconditionally to startloop lable
endloop: # Loop ending lable 

# Terminate the programm
li $v0,10
syscall

.data
indata: .asciiz  "Data in the data segment"