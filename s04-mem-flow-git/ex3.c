#include <stdio.h>

void swap1(int i, int j) {
    int temp;
    temp = i;
    i = j;
    j = temp;
}
void swap2(int *i, int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
int main(){
    int i;
    int j;
    i=1; j=2;
    swap1(i,j);
    printf("(%d,%d)\n", i, j);
    swap2(&i,&j);
    printf("(%d,%d)\n", i, j);
}