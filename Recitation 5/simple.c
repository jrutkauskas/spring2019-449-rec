#include <stdio.h>
#include <stdlib.h>

int add(int* x, int* y); 

int main()
{
	
	int* x = malloc(sizeof(int));
	*x = 4;
	int* y = *x + 10;
	
	int sum = add(x,y);
	
	printf("Sum is: %d", sum);
	
	return 0;
}

int add(int* x, int* y)
{
	return *x + *y;
}

