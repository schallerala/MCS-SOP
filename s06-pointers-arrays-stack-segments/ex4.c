#include <stdio.h>

typedef int (*mathFunc_t)(int, int); // definition of type mathFunc_t

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int compute(mathFunc_t f, int a, int b) {
    return f(a, b);
}

int main() {
    printf("%d\n", mult(add(2, 4), 8));
    printf("%d\n", compute(mult, compute(add, 2, 4), 8));
    return 0;
}