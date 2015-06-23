/* 
 * Both parent and child processes run the same program
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int fd[2]; // File descriptors. 0 for input 1 for output

	if (pipe(fd) == -1){
		perror("Pipe");
		exit(1);
	}
        
	
	switch(fork()){
                case -1: perror("Fork");
			exit(2);
                case 0:
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execl("/usr/bin/who", "who", (char *) 0);        
			exit(3);
                default: 
                        dup2(fd[0], STDIN_FILENO);
                        close(fd[0]);
                        close(fd[1]);
                        execl("/usr/bin/wc", "wc", (char *) 0);
                        exit(4);
        }
}

