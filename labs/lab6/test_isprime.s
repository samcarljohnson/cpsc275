#This works!!!!!
.LC0:
	.string "One means this is a prime number: %d\n"
	.globl main

main:
        pushl %ebp
        movl %esp, %ebp
        subl $16, %esp
        movl $2, %ebx
	movl $13, %ecx
        jmp .compareSecondLoop
        .isPrimeLoopStart:
                movl %ecx, %eax
                cltd
                idivl %ebx
                cmpl $0, %edx
                jne .isPrimeIncrement
                movl $0, %eax
		
		movl %eax, 8(%esp)
		movl $.LC0, 4(%esp)
		movl $1, (%esp)
                call __printf_chk

		leave
		ret
        .isPrimeIncrement:
                incl %ebx
        .compareSecondLoop:
                cmpl %ecx, %ebx
                js .isPrimeLoopStart
                movl $1, %eax

                movl %eax, 8(%esp)
                movl $.LC0, 4(%esp)
                movl $1, (%esp)
                call __printf_chk

                leave
		ret
