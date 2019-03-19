#include <stdio.h>
char* yes = "yes";
char* no = "no";

char* all_greater_than_zero_string(int x, int y)
{
    if(x > 0 && y > 0)
        return yes;
    else
        return no;
}
int main()
{
    char* (*to_print)(int, int);
    to_print = &all_greater_than_zero_string;
    
    printf(to_print(3,3));
    return 0;
}