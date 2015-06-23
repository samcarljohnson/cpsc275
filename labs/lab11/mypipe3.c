/* 
 * Pipes 3 processes
 * authors: Sam Johnson, Jack Wallace
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This is the main function
int main(void){
        int fd[2]; // File descriptors. 0 for input 1 for output

	//creates the first pipe between who and wc
        if (pipe(fd) == -1){
                perror("Pipe");
                exit(1);
        }

	// creates the first child process
        switch(fork()){
                case -1: perror("Fork");
                        exit(2);
                case 0:
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			
			// creates the second pipe between cut and wc
			if (pipe(fd) == -1){
                		perror("Pipe");
                		exit(1);
        		}
			// creates the second child process: the grandchild
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
                default:
                        dup2(fd[0], STDIN_FILENO);
                        close(fd[0]);
                        close(fd[1]);
                        execl("/usr/bin/cut", "cut", "-c", "4-10", (char *) 0);
                        exit(4);
        }
}

