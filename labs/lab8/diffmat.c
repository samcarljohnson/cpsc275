#include <stdio.h>
#include <stdlib.h>

void genmat(double *a[N], int n);
void matadd(double *a[N], double *b[N], double *c[N], int n);
void matmul(double *a[N], double *b[N], double *c[N], int n);
double diffmat(double *a[N], double *b[N], double *c[N], int n);
double matmul_block(double *a[N], double *b[N], double *c[N], int n, int i, int j);

int main(){
	double *a[N];
	double *b[N];
	double *c[N];
	int i;
	for(i=0;i<N;i++){
		a[i] = (double*)malloc(N*sizeof(double));
		b[i] = (double*)malloc(N*sizeof(double));
		c[i] = (double*)malloc(N*sizeof(double));
	}
	genmat(a, N);
	genmat(b, N);
	matmul(a, b, c, N);
	printf("%f\n", diffmat(a,b,c,N));

	for (i=0;i<p;i++){
		for(j=0;j<p;j++){

		}
	}
return 0;
}

double matmul_block(double *a[N], double *b[N], double *c[N], int n, int i, int j){
	
}

double diffmat(double *a[N], double *b[N], double *c[N], int n) 
{
	double x[n], y[n], z[n], sum;
	int i, j;

	// generate a random vector
	for (i = 0; i < n; i++)
		x[i] = (double)(rand()) / RAND_MAX; 

	// z = C*x
	for (i = 0; i < n; i++) {
		sum = 0.;
		for (j = 0; j < n; j++)
			sum += c[i][j] * x[j];
		z[i] = sum;
	}

	// y = B*x
	for (i = 0; i < n; i++) {
		sum = 0.;
		for (j = 0; j < n; j++)
			sum += b[i][j] * x[j];
		y[i] = sum;
	}

	// x = A*y
	for (i = 0; i < n; i++) {
		sum = 0.;
		for (j = 0; j < n; j++)
			sum += a[i][j] * y[j];
		x[i] = sum;
	}

	// compute the difference
	sum = 0.;
	for (i = 0; i < n; i++) 
		sum += abs(x[i] - z[i]);

	return sum;
}


void genmat(double *a[N], int n){
	int r,col;
	for(r=0;r<n;r++){
		for(col=0;col<n;col++){
			a[r][col] = (double) rand() / RAND_MAX;
		}

	}

}

void matadd(double *a[N], double *b[N], double *c[N], int n){
	int r, col;
	for(r=0;r<n;r++){
		for(col=0;col<n;col++){
			c[r][col] = a[r][col] + b[r][col];
		}
	}
}

void matmul(double *a[N], double *b[N], double *c[N], int n){
	int i, j, k; //i is row of first, r is col of first/row of second, col is col of second
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j] = 0.;
			for(k=0;k<n;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
