#include <stdio.h>

void original_while (int n) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        printf("%d low\n", low);
        ++low;
    }
}

void shorter_while (int n) {
    // as the value n is copied
    while (n-- > 0) {
        // do stuff n times
        printf("%d n\n", n);
    }
}

void for_alternative (int n) {
    for (int i = 0; i < n; i++) {
        // do stuff n times
        printf("%d i\n", i);
    }
}

void do_while_alternative (int n) {
    if (n <= 0) {
        return;
    }
    // as the value n is copied
    do {
        // do stuff n times
        printf("%d n\n", n);
    }
    while (--n > 0);
}


int main () {
    int n = 5;

    printf("Original while:\n");
    original_while(n);
    printf("Original shorter while:\n");
    shorter_while(n);
    printf("For alternative:\n");
    for_alternative(n);
    printf("Do while alternative:\n");
    do_while_alternative(n);
    printf("Do while alternative with n=0:\n");
    do_while_alternative(0);
}