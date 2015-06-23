#include <stdio.h>
#include <limits.h>

int is_little_endian();
int add_ok(unsigned int, unsigned int);

int main()
{
	printf("%d\n", is_little_endian());
	return 0;
}

int is_little_endian()
{
	unsigned int x = 1;
	char* one_byte = (char*)&x;
	int first_bit = one_byte[0];
	int result = (int)(first_bit);
	if(result != 0)
		return 1;
	else
		return 0;
}

int add_ok(unsigned int x, unsigned int y)
{
	if(((x+y)/2)>(ULONG_MAX/2))
	{
		
	}
}