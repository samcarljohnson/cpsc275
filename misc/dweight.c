/* 
dweight.c - computes the dimensiojnal weight of a  package.
author: Sam Johnson
date: 9-11-13
*/
#include <stdio.h>
#define INCHES_PER_POUND 166

int main(){
	int height, width, depth;
	printf("Enter the height (inches): ");
	scanf("%d", &height);
	printf("Enter the width (inches): ");
        scanf("%d", &width);
	printf("Enter the depth (inches): ");
        scanf("%d", &depth);
	int volume = height*width*depth;
	printf("Volume (cubic inches): %d\n", volume);

	int dweight = (volume +165)/166;
	printf("The dimensional weight of the box is: %d\n", dweight);

return 0;
}
