#include <stdio.h>
#define swap(t,x,y) t tmp_swap = x; x = y; y = tmp_swap;
int main() {
    int a=1;
    int b=2;
    swap(int,a,b);
    printf("%d %d\n", a, b);
}