.text 
la $a0,mydata
li $v0,4
syscall 
li $v0,10
syscall

.data
mydata: .asciiz "Hello World!"