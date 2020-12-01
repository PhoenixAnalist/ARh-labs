#include <stdio.h>

extern "C" int summ(int key, int* data);

int main() {
    int N;
    scanf("%d", &N);

    int* data = (int*) malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i)
        data[i] = rand() % 50;

    printf("array values is: \n");

    for (int i = 0; i < N; ++i)
        printf("%d: %d\n", i, data[i]);

    printf("sum of array is %d\n", summ(N, data));
    free(data);
    return 0;
}
