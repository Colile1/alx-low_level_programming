#include <stdio.h>

void print98(void)
{
	int a[5];
	int *p;

	a[2] = 98;
	p = a;
	*(p + 5) = 98;
	printf("a[2] = %d\n", a[2]); 
}

int main(void)
{
	print98();
	return (0);
}
