#include <stdio.h>

int fun(int x)
{
	if(x>10)
		return 50;
	else
		return 0;
}

int main()
{
	return fun(30);
}