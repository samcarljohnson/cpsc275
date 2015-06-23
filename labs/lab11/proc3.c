/* 
 * Both parent and child processes run the same program
 */
#include <unistd.h>
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
                case 0: execl("./child", "child", (char *) 0);
                        exit(1); // Will neve get here because there is nowhere to return
                default: printf("Process[%d]: parent in execution...\n", getpid());
                        sleep(2);
			if(wait(NULL)>0)
				printf("Process[%d]: parent terminating child...\n", getpid());
			printf("Process[%d]: parent terminating...\n", getpid());
			exit(0);
        }
}

