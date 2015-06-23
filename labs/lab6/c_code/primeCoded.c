#include <stdio.h>

int isPrime(int n);

int main(){
	int i;
	for(i=2;i<100;i++){
		int x = isPrime(i);
		if(x == 1){
			printf("%d\n", i);
		}
	}
}
int isPrime(int n){
	int i;
	int r;
	for(i=2;i<n;i++){
		if((n%i)==0)
			return 0;
	}
	return 1;
}
