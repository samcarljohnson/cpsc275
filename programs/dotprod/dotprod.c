/*
dotprod.c - computes the dot product of 2 arrays
Author: Sam Johnson
Date: 5-16-13
*/

#include <stdio.h>
#define N 4096

int main(){
	double prod;
	double x[N];
	double y[N];
	
	/* Populates the arrays defined above with all 1's */
	int i = 0;
	while(i<N){
		x[i] = 1;
		y[i] = 1;
		i++;	
	}
	
	/* Computes the dot product of the arrays of size N, defined in the header */
	int n;
	prod = 0.0;
	for(n=0; n<N; n++){
		prod += (x[n]*y[n]);
	}
	printf("%.2f\n", prod);
	return 0;	
}
