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

	int i = 0;
	while(i<N){
		x[i] = 1;
		y[i] = 1;
		i++;	
	}
	double c = dotprod(x, y, N);
	printf("%.2f\n", c);
	return 0;	
}

double dotprod(double a[], double b[], int c){
	int n;
	double prod = 0.0;
	for(n=0; n<c; n++){
		prod += (a[n]*b[n]);
	}
	return prod;	
}
