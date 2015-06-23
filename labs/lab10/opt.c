#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
	int r, cval;
	while((r= getopt(argc, argv, "ab:c:")) != -1){
		switch(r){
			case 'a':
				printf("Do option a!\n");
				break;
                        case 'b':
                                printf("Do option b with %s!\n", optarg);
                                break;
                        case 'c':
				cval = atoi(optarg);
                                printf("Do option c with %d!\n", cval);
                                break;
			default:
				printf("Error: Unknown option!\n");

		}
	}
}
