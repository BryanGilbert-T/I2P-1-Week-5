#include <stdio.h>

int fibonaci(int x);
int main(void){
    int x;

    scanf("%d", &x);
    fibonaci(50);
    return 0;
}

int fibonaci(int x){
    if(x == 0){
        return 0;
    }
    fibonaci(x - 1);
    printf("%d ", x);
    return 0;
}