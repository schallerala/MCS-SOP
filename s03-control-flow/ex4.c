#include <stdio.h>

int N = 3;

int main() {
    int ctr, i; // line 4
    int res;
    i = N; // line 7
    res = N;
    printf("res N i\n");
    for (ctr = 0; ctr < N; ++ctr, --i) {
        res = N/i;
        printf("%3i%3i%3i\n",res, N, i);
    }
    return 0;
}