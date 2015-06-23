/*
matvecmul2.c - computes the product of an N by N matrix by an N vector
Author: Sam Johnson
Date: 5-22-13
*/
#include <stdio.h>
#include <stdlib.h>
#define N 10

double matrixProduct(double *a, double *b, int);

int main(){
	double *a = (double*)malloc(N*N*sizeof(double));
	double *b= (double*)malloc(N*sizeof(double));
	
	/* Populates the 2D array with values in each row equal to the row number */
	int row;
	int col;
	for(row=0;row<N;row++){
		for(col=0;col<N;col++){
			*(a+col+(row*N)) = row+1;
		}
	}
	
	/* Populates the vector array with all 1's */
	double *pb = b;
	while(pb<(b+N)){
		*pb = 1.0;
		pb++;
	}
	
	/* Makes a call to the matrixProduct array which computes the dot product of the provided arrays */
	matrixProduct(a, b, N);
	return 0;
}

/* Computes the dot product of the 2D array and the vector array and prints the resulting vector array */
double matrixProduct(double *a, double *b, int c){
	double *result = (double*)malloc(N*sizeof(double));
	double row_product = 0.0;
	int row;
	int col;
	for(row=0; row<c; row++){
		for(col=0; col<c; col++){
			row_product += ((*(a+col+(row*c))) * (*(b+row)));
		}
		*(result+row) = row_product;
		printf("%f\n", row_product);
		row_product = 0.0;
	}
}
