/* 
 * Both parent and child processes run the same program
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(void){
	pid_t pid;
	char* message;
	int i;
	
        printf("Fork program starting\n");
        pid = fork();
	switch(pid){
		case -1: exit(0);
		case 0: message = "This is the child";
			break;
		default: message = "This is the parent";
			break;
	}
        for(i = 0; i<N ; i++){
		puts(message);
	}
        exit(0);
}
