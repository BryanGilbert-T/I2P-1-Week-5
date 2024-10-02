#include <stdio.h>

int sum(int x);
int main(void){
    int x;

    scanf("%d", &x);
    printf("%d", sum(x));
    return 0;
}

int sum(int x){
    if(x == 0){
        return 0;
    }
    return (x % 10) + sum(x / 10);
}