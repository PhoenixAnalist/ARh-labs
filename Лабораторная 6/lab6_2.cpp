#include <stdio.h>
#include <math.h>

extern "C" double funcc(double x);

int main() {
    double x;
    scanf("%le", &x);
    printf("funcc(%le) = %le\n", x, funcc(x));
}
