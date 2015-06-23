#include <stdio.h>

int main(){
	int num;
printf("Enter a five digit number to separate: ");
scanf("%d", &num);

printf("%d   ", (((((num/10)/10)/10)/10)%10));
printf("%d   ", ((((num/10)/10))/10)%10);
printf("%d   ", (((num/10)/10)%10));
printf("%d   ", (((num/10)%10)));
printf("%d   \n", (num%10));
return 0;
}
