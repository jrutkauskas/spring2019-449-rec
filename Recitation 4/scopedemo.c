#include <stdio.h>
int main() 
{
	int s;
	s = 4;
	{
		int s;
		s = 6;
		printf("%d\n", s);
	}
	return 0;
}


