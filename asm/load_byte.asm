.text

lb $a0,0x10010000
li $v0,11
syscall
li $a0,0x10010001
syscall
li $v0,10
syscall

.data
indata: .ascii "data"