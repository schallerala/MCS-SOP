#include <stdio.h>
#define swap(t,x,y) do { t tmp_swap = x; x=y; y=tmp_swap; } while(0)
int main() {
    int a=1;
    int b=2;
    swap(int,a,b);
    if (a>b) swap(int,a,b);
    else a = b;
    printf("%d %d\n", a, b);
}