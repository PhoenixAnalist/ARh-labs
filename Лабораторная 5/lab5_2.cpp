#include stdio.h
#include math.h

double calc(double x) {
    return sin(2  x) + cos(3  x);
}

int main() {
    double x;
    scanf(%le, &x);

    double y = calc(x);
    printf(sin(%le) + cos(%le) = %len, 2  x, 3  x, y);
    return 0;
}
