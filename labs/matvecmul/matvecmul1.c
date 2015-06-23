/*
matvecmul1.c - computes the product of an N by N matrix by an N vector
Author: Sam Johnson
Date: 5-19-13
*/
#include <stdio.h>
#define N 10

double matrixProduct(double [][N], double [], int);

int main(){
	double a[N][N];
	double x[N];
	double b[N];
	int n,i,c,j,k;
	for(n=0; n<N; n++){
		for(i=0; i<N; i++){
			a[n][i] = (n+1);			
		}
	}
	for(c=0; c<N; c++){
		x[c] = 1.0;
	}
	matrixProduct(a, x, N);
	return 0;
}

double matrixProduct(a[][N], x[], N){
	double prod = 0.0;	
	for(j=0; j<N; j++){
		for(k=0; k<N; k++){
			prod += (a[j][k]*x[k]);
		}
		b[j] = prod;
		printf("%f\n", prod);
		prod = 0.0;
	}
}
