/* 
 * the child program that replaces proc3.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void){
        printf("Process[%d]: child in execution...\n", getpid());
	sleep(1);
	printf("Process[%d]: child in execution...\n", getpid());
	exit(0);
}

