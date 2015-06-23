#prime.s - Prints every prime number from 2-100
#author: Sam Johnson & Suhas Maringanti
#date: 10-27-13

.LC0:
	.string "%d\n" #sets the value of the string that printf uses
.globl main
.globl isprime

main:	
	pushl %ebp 	    #This and the next 2 lines setup the first stack frame
	movl %esp, %ebp
	subl $32, %esp
	movl $2, %ecx 	    #sets the first value to check to 2
	jmp .compareFirstLoop
.loopstart:
	movl %ecx, 12(%esp) #saves the value of %ecx
	call isprime 	    #calls isprime to check if %ecx is prime
	movl 12(%esp), %ecx #restores the correct value of %ecx
	cmpl $0, %eax 	    #checks the returned value for isprime
	je .notPrime	    #if the returned value is 0, jump to increment again
	movl %ecx, 8(%esp)  #this and the next 3 lines prepare and call printf	
	movl $.LC0, 4(%esp)
	movl $1, (%esp)
	call __printf_chk
	movl 12(%esp), %ecx #restores the correct value of %ecx
.notPrime:
	incl  %ecx
.compareFirstLoop:
	cmpl $99, %ecx	    #checks %ecx against the loop limit which is 99 
	js .loopstart 	    #loops again if %ecx is less than 100
	leave
	ret


isprime:
        pushl %ebp	    #this and the next 2 lines setup the second stack frame
        movl %esp, %ebp    
        subl $16, %esp
        movl $2, %ebx	    #sets the first value to divide the parameter by to 2
	pushl %esi	    #stores the value of %esi
        movl 20(%ebp), %esi #fetches the value of the parameter and puts it in %esi
        jmp .compareSecondLoop
.isPrimeLoopStart:
        movl %esi, %eax     #this and the next 2 lines gets the remainder of the division
        cltd
        idivl %ebx
        cmpl $0, %edx	    #if the remainder is not 0, loop again
        jne .isPrimeIncrement
        movl $0, %eax	    #set the return value to 0 meaning this isn't prime
        leave
        ret
.isPrimeIncrement:
        incl %ebx
.compareSecondLoop:
        cmpl %esi, %ebx     #checks and continues looping if %ebx is less than 
        js .isPrimeLoopStart
        movl $1, %eax       #returns 1 if the parameter makes it all the way through the loop
	popl %esi	    #pop %esi back to whoever was using it
        leave
        ret
