/*
dotprod1.c - computes the dot product of 2 arrays
Author: Sam Johnson
Date: 5-16-13
*/

#include <stdio.h>
#define N 10

double dotprod(double [], double [], int);

int main(void){
	double x[N];
	double y[N];

	/* Populates the arrays defined above with all 1's */
	int i = 0;
	while(i<N){
		x[i] = 1;
		y[i] = 1;
		i++;	
	}
	/* Makes a call to the dotprod function which will compute the dot product of the provided arrays */
	double c = dotprod(x, y, N);
	printf("%.2f\n", c);
	return 0;	
}

/* This function computes the dot product of the arrays of size N, defined in the header */
double dotprod(double a[], double b[], int c){
	int n;
	double prod = 0.0;
	for(n=0; n<c; n++){
		prod += (a[n]*b[n]);
	}
	return prod;	
}
