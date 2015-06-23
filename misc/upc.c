/* 
upc.C - Computes a barcode's check digit
Author: Sam Johnson
Date: 9-9-13
*/

#include <stdio.h>

int main(){
	int first, second, third, checkDig, firstTotal, secondTotal;

	// 0, 13800, 15173, 5
	printf("Enter the first digit: ");
	scanf("%d", &first);
	printf("Enter the first group of five digits: ");
	scanf("%d", &second);
	printf("Enter the second group of five digits: ");
	scanf("%d", &third);
	firstTotal = (first) + ((((second/10)/10)/10)%10) + ((second%10)%10) + (((((third/10)/10)/10)/10)%10) + (((third/10)/10)%10) + (third%10);
	secondTotal = (((((second/10)/10)/10)/10)%10) + (((second/10)/10)%10) + (second%10) + ((((third/10)/10)/10)%10) + ((third/10)%10);
	checkDig = ((firstTotal*3)+secondTotal);
	checkDig = 9-((checkDig-1)%10);
	printf("The check digit is: %d\n", checkDig);
	

	

	return 0;
}
