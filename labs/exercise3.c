#include <stdio.h>
#include <limits.h>

int tadd_ok(int, int);

int main()
{
	int max = INT_MAX;
	printf("%d\n", tadd_ok((INT_MIN/2),(INT_MIN/2)));
	return 0;
}

int tadd_ok(int x, int y)
{
	if((INT_MAX-x)>y)
	{
		return 1;
	}
	else if((x<0 && y<0)&&((INT_MIN-x)>y))
	{
		return 1;
	}
	else
		return 0;
}