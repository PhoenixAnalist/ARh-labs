#include <stdio.h>

int main(void)
{
    unsigned int x = 3;
    unsigned int y = 1;
    bool flag = false;
    printf("x = %d\ny = %d\n", x,y);
    asm ( "sub %[Src],%[Dest]\n\t"
        : [Dest]"+r" (x)
        : [Src]"r" (y)
        : "cc" );
    asm ( "jno nooverflow;"\
          "mov $0x1,%0;"\
          "nooverflow :"\
          : "=r" (flag) : "0" (flag) );
    printf("x-y = %d\n", x);


        if (flag==true)
        {
            printf("Incorrect result\n");
        }
        else
        {
            printf("Correct result\n");
        }
    return 0;
}
