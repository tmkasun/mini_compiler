la $s0,mydata
li $t0,0x10010000 # This is the starting address of starting data section, always datasegment start at this address
#we can give this as similarly
la $t0,mydata

lw $t1,0($t0) # load word word = 4 Bytes , with 0 offcet to $t0 base address
lw $t2,4($t0)


lb $v0,10
syscall

.data
mydata: .asciiz "abcdefghij"