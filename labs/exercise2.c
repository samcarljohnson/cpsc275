#include <stdio.h>
#include <limits.h>

int add_ok(unsigned int, unsigned int);

int main()
{
	printf("%d\n", add_ok((UINT_MAX/2),(UINT_MAX/2+1)));
	return 0;
}

int add_ok(unsigned int x, unsigned int y)
{
	if((UINT_MAX-x)>y)
	{
		return 1;
	}
	else
		return 0;
}