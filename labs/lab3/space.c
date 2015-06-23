/*
space.c - Places a set amount of spaces in between characters of an input array
Author: Sam Johnson / Jacobo Carbo
Date: 5-25-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 101

char* insert_space(char* ch, int i);

int main(void){
	int input_int;
	char input_string[MAX_STR_LEN], *is;
	is = input_string;
	
	scanf("%d\n%s", &input_int, is);
	char* string = insert_space(is, input_int);
	printf("%s\n", string);
	return 0;	
}

char* insert_space(char* ch, int i){
	/* The chunk below prints lengths for the newly allocated return */
	/* string and also the string passed to the function             */
	int length = (strlen(ch)-1)*(i+1)+2;
	char* final_string = (char*)malloc(length*sizeof(char));
	int length2 = strlen(ch);
	
	/* Loop Explanation: j iterates over "cpsc275" (length 7) and k */
	/* iterates over the new, long string (length 20)               */
	int j,k;
	for(j=0, k=0;j<(length2-1);j++){
		*(final_string+k) = *(ch+j);
		k++;
		/* Each time k is divisible by (i+1) it will need to print a new */
		/* character from "cpsc275" (EX: c=1, space=2, space=3. 3/3=0)   */
		while(k%(i+1) != 0){
			*(final_string+k) = ' ';
			k++;
		}
	}
	char* b = (ch+(length2-1));

	/* This adds the last letter without spaces after it and the null */
	/* character, but I can't get it to print correctly               */
	*(final_string+(length-2)) = *(ch+(length2-1));
	*(final_string+(length-1)) = '\0';
	return final_string;
}