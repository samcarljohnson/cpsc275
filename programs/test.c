#include <stdio.h>
#define true  1
#define false 0
#define N 10

int main(){



int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int *p = &a[0], *q = &a[N-1], temp;

while (p < q) {
   temp = *p;
   *p++ = *q;
   *q-- = temp;
}
int i;
for(i=0;i<N;i++){
	printf("%d\n", a[i]);
}

}