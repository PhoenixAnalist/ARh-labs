#include <stdio.h>
#include <math.h>
#include <time.h>

struct KeyValue {
    int key;
    double value;
};

extern "C" void form(int key, int size, KeyValue* data);

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

    form(k, N, data);
