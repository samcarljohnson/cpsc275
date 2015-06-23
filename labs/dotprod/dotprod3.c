/*
dotprod1.c - computes the dot product of 2 arrays
Author: Sam Johnson
Date: 5-16-13
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

double dotprod(double *a, double *b, int);

int main(void){
	double *a;
	double *b;

	a = (double *) malloc(N * sizeof(double));
	b = (double *) malloc(N * sizeof(double));
	double *p = a;
	double *q = b;
	
	while(p<(a+N)){
		*(p) = 1.0;
		*(q) = 1.0;
		
		p++;
		q++;	
	}
	double c = dotprod(a, b, N);
	printf("%.2f\n", c);
	free(a);
	free(b);
	return 0;	
}

double dotprod(double *a, double *b, int c){
	double *p = a;
	double *q = b;
	
	int n;
	double prod = 0.0;
	for(n=0; p<(a+c); n++){
		prod += ((*p)*(*q));
		p++;
		q++;
	}
	return prod;	
}
