#include <stdio.h>

int main(int argc, char *argv[]){
	int i;
	
	for(i = 0; i < atoi(argv[1]); i++){
		printf("%s\n", argv[2] );
	}
return 0;
}
