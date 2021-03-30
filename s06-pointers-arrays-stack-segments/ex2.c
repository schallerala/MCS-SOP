#include <stdio.h>


int method_e () {
    return 42;
}

int method_d (int (*e)()) {
    return 12;
}


int d(int (*e)());

int main () {
    int (*f())();
    printf("res: %d\n", d(method_e));
    return 0;
}