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

	int i = 0;
	while(i<N){
		x[i] = 1;
		y[i] = 1;
		i++;	
	}
	
	int n;
	prod = 0.0;
	for(n=0; n<N; n++){
		prod += (x[n]*y[n]);
	}
	printf("%.2f", prod);
	return 0;	
}
