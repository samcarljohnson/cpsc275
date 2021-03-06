/*
matvecmul.c - computes the product of an N by N matrix by an N vector
Author: Sam Johnson
Date: 5-19-13
*/
#include <stdio.h>
#define N 10

int main(){
	double a[N][N];
	double x[N];
	double prod = 0.0;
	int n,i,c,j,k;
	
	/* Populates the 2D array with values in each row equal to the row number */
	for(n=0; n<N; n++){
		for(i=0; i<N; i++){
			a[n][i] = (n+1);			
		}
	}
	
	/* Populates the vector array with all 1's */
	for(c=0; c<N; c++){
		x[c] = 1.0;
	}

	/* Computes the dot product of the 2D array and the vector array and prints the resulting vector array */
	for(j=0; j<N; j++){
		for(k=0; k<N; k++){
			prod += (a[j][k]*x[k]);
		}
		printf("%f\n", prod);
		prod = 0.0;
	}
	return 0;
}
