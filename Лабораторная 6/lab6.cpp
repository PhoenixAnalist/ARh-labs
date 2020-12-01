#include <stdio.h>

extern "C" int func(int x, int y);

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    printf("func(%d, %d) = %d\n", x, y, func(x, y));
}
