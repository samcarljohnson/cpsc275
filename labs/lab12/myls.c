/*
 * Authors: Sam Johnson and Suhas Maringanti
 * Date: 12-2-13
 * myls - simulates the ls system program!
 */

#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

int main(){
DIR *dptr = opendir(".");
if(dptr == NULL){
	printf("Couldn't properly open the directory");
	exit(0);
}
struct dirent *currentline = readdir(dptr);
while(currentline){
	if(currentline == NULL){
		//flag = 0;
		break;
	}
	struct stat info;
	stat(currentline->d_name, &info);
	
	if(currentline->d_name[0] == '.'){
		currentline = readdir(dptr);
		continue;
	}
		
	// File Type
	if(S_IFDIR & info.st_mode){
		printf("d");
	}
	else{
		printf("-");
	}

	// Next six are permissions
	if(S_IRUSR & info.st_mode){
		printf("r");
	}
        else{
                printf("-");
        }
	if(S_IWUSR & info.st_mode){
                printf("w");
        }
        else{
                printf("-");
        }
        if(S_IXUSR & info.st_mode){
                printf("x");
        }
        else{
                printf("-");
        }
        if(S_IRGRP & info.st_mode){
                printf("r");
        }
        else{
                printf("-");
        }
        if(S_IWGRP & info.st_mode){
                printf("w");
        }
        else{
                printf("-");
        }
        if(S_IXUSR & info.st_mode){
                printf("x");
        }
        else{
                printf("-");
        }
	
	// Hard Links
	printf("  %ld  ", info.st_nlink);

	// Owner ID
	printf("%s  ", (getpwuid(info.st_uid))->pw_name);

	// Group ID
	printf("%s  ", getgrgid(info.st_gid)->gr_name);

	// Size
        if(S_IFDIR & info.st_mode){
                printf(" ");
        }
        else{
                printf("%ld  ", info.st_size);
        }
	
	// Mod Time
	int len = strlen(ctime(&info.st_mtime));
	int i;
	for(i = 0; i < (len-1); i++){
		printf("%c", ctime(&info.st_mtime)[i]);
	}
	//printf("%s  ", ctime(&info.st_mtime));

        // File name
	printf(" %s\n", currentline->d_name);

	currentline = readdir(dptr);
		
}
}
