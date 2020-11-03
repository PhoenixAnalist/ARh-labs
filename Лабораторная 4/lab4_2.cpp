#include <stdio.h>

int main()
{
    int x = 20;
    int y;
    asm ( "imul $3, %0" : "=r" (y) : "0" (x) );
    asm ( "add $1, %0" : "=r" (y) : "0" (y) );
    printf("3*x+1 = %d", y);
}
