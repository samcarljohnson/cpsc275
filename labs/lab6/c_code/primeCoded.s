	.globl	isPrime
	.type	isPrime, @function
isPrime:
	pushl	%ebx
	movl	8(%esp), %ebx
	movl	$1, %eax
	cmpl	$2, %ebx
	jle	.L2
	movl	%ebx, %edx
	shrl	$31, %edx
	leal	(%ebx,%edx), %ecx
	andl	$1, %ecx
	movb	$0, %al
	cmpl	%edx, %ecx
	je	.L2
	movl	$2, %ecx
	jmp	.L4
.L5:
	movl	%ebx, %eax
	movl	%ebx, %edx
	sarl	$31, %edx
	idivl	%ecx
	testl	%edx, %edx
	je	.L8
.L4:
	addl	$1, %ecx
	cmpl	%ebx, %ecx
	jne	.L5
	movl	$1, %eax
	jmp	.L2
.L8:
	movl	$0, %eax
.L2:
	popl	%ebx
	ret
.LC0:
	.string	"%d\n"
	.globl	main
main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	andl	$-16, %esp
	subl	$16, %esp
	movl	$2, %ebx
.L11:
	movl	%ebx, (%esp)
	call	isPrime
	cmpl	$1, %eax
	jne	.L10
	movl	%ebx, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.L10:
	addl	$1, %ebx
	cmpl	$100, %ebx
	jne	.L11
	movl	-4(%ebp), %ebx
	leave
	ret
