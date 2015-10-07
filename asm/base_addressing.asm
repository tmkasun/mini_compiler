.text

la $t0,indata

lb $a0,0($t0)
li $v0,11
syscall

lb $a0,1($t0)
syscall

li $v0,10
syscall

.data
indata: .ascii "data"