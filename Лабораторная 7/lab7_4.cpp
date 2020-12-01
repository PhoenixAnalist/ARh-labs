#include <stdio.h>
#include <time.h>

struct KeyValue {
    int key;
    double value;
};

extern "C" bool sum(int key, int size, KeyValue* data, double* result);

int main() {
    srand(time(NULL));
    int N, k;
    scanf("%d %d", &N, &k);

    KeyValue* data = (KeyValue*) malloc(sizeof(KeyValue) * N);

    for (int i = 0; i < N; ++i) {
        data[i].key = rand() % 20;
        data[i].value = rand() % 100;
    }

    for (int i = 0; i < N; ++i) {
        printf("%d: %le\n", data[i].key, data[i].value);
    }

    double result;
    if (!sum(k, N, data, &result)) {
        printf("Elements with key %d didn't exist\n", k);
    } else {
        printf("Sum of elemtnst is: %le\n", result);
    }

    free(data);
    return 0;
}
