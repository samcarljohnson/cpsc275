#add.s - Adds individual bytes of an integer together and prints the result
#author - Sam Johnson & Suhas Maringanti
#date - 10-27-13

.LC0:
	.string	"Byte 3 = 0x%x\nByte 2 = 0x%x\nByte 1 = 0x%x\nByte 0 = 0x%x\nSum = 0x%x\n"
	.globl	main
main:
	pushl %ebp                  #this and the next two lines setup the stack frame
	movl %esp, %ebp
	andl $-16, %esp

	subl $36, %esp		    #allocates space on the stack
	movl $0x12345678, 28(%esp)  #stores an integer value on the stack

	movsbl 28(%esp), %ebx	    #this block of statements moves individual bytes to its own 4 byte location
	movl %ebx, 20(%esp)
	movsbl 29(%esp), %ebx
	movl %ebx, 16(%esp)
	movsbl 30(%esp), %ebx
	movl %ebx, 12(%esp)
	movsbl 31(%esp), %ebx
	movl %ebx, 8(%esp)

	movl 12(%esp), %eax	    #stores the values from memory above into registers
	movl 16(%esp), %ecx
	movl 20(%esp), %ebx
	movl 8(%esp), %edx
	addl %eax, %ecx		    #adds up all of the registers
	addl %ebx, %ecx
	addl %edx, %ecx 
	movl %ecx, 24(%esp)	    #places the sum onto the stack to be printed




	movl $.LC0, 4(%esp)
	movl $1, (%esp)
        call	__printf_chk	    #prints each individual byte from the integer and the sum of them
	leave
	ret
