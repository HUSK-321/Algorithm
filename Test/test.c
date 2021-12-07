#include <stdio.h>
int main(){
    int *x, *y;
    x = (int *) malloc(sizeof(int));
    *x = 5;
    y = x;
    *y = 10;
    printf("%d\n", *x);
}