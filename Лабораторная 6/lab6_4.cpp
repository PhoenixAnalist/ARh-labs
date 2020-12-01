#include <stdio.h>
#include <math.h>

extern "C" bool ser(double eps, double* result);

int main() {
    double eps;
    scanf("%le", &eps);

    double res = 0;
    if (!ser(eps, &res))
        printf("the series does not converge\n");

    return 0;
}
