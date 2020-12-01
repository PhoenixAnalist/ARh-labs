#include <stdio.h>
#include <math.h>

extern "C" int fib(int N, int* result);

int main() {
    int x;
    scanf("%d", &x);

    int* fibs = (int*) malloc((x + 1) * sizeof(int));

    fib(x, fibs);

    for (int i = 0; i < (x + 1); ++i) {
        printf("fib(%d) = %d\n", i, fibs[i]);
    }

    free(fibs);
}
