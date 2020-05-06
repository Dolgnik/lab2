.data
        format:
                .asciz "%hhi\n"
        array:
                .quad 132, -20, -3, 10, 210, 56, 73, 107, 115, 128
        array_end:

.text
.globl main
main:
        xorq %rax, %rax
        xorq %rcx, %rcx
        movb $0b01101011, %al
        leaq array, %rbx
again:
        orq %rax, (%rbx)
        cmpq $128, (%rbx)
        jl less
        incb %cl
less:
        addq $8, %rbx
        cmpq $array_end, %rbx
        jne again

        movq $format, %rdi
        movq %rcx, %rsi
       	xorq %rax, %rax
        call printf
        
	movq $1, %rax
        xorq %rbx, %rbx
        int $0x80
