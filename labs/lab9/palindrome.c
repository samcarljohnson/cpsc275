#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int pal = 1;
	int x, y;
	char* line = (char*)malloc(30);
	while(scanf("%s", line) != EOF){
		int length = strlen(line);
		if(length==7){
			int count = 6;
			for(x=0;x<3;x++){
				if(line[x]!=line[count])
					pal=0;
				count--;
			}
			if(pal)
				printf("%s\n", line);
			pal = 1;
		}
	}
	
}
