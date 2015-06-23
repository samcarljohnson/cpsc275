.LC0:
	.string	"x y z = %d %d %d\n"
	.globl	main
main:
	pushl	%ebp
	movl	%esp, %ebp
	
	subl	$32, %esp
	movl	$30, 16(%esp)
	movl	$20, 12(%esp)
	movl	$10, 8(%esp)
	movl	$.LC0, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
	leave
	ret
