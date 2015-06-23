#include <stdio.h>

int main(int argc, char *argv[]){
	int a = atoi(argv[1]);
	int b = atoi(argv[3]);
	switch(argv[2][0]){
		case '*': printf("%d\n", a*b);
			break;
                case '/': printf("%d\n", a/b);
                        break;
                case '+': printf("%d\n", a+b);
                        break;
                case '-': printf("%d\n", a-b);
                        break;
		default: printf("Please enter valid parameters...");
			break;



	}
}
