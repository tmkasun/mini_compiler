.text # This is the programm section 
la $a0,mydata # $a0 holds the address of the first charater which is generated by mydata lable during program startup
li $v0,4 # load imidiate value 4 to $v0 register which is the number of the system call which is needed to be invoked
syscall # Call system call 4
li $v0,10 # Load imidiate integer 10 to the $v0 register 10 is end of programm systemcall
syscall

.data # This is the data section where you load the data required for process
mydata: .asciiz "Hello World!"