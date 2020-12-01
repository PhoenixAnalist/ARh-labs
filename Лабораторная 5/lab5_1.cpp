#include <stdio.h>

int main() {
    int N = 0;
    for (size_t power: {2, 4, 6, 7, 8, 9}) {
        N = pow(10, power);
        float sumN = 0;
        float sum2N = 0;

        for (size_t i = 0; i < N; ++i)
            sumN += (1 / float(N));

        for (size_t i = 0; i < 2*N; ++i)
            sum2N += (1 / float(N));

        printf("sum of 10^%ld numbers: %f\n", power, sumN);
        printf("sum of 2*10^%ld numbers: %f\n", power, sum2N);
    }

    return 0;
}
