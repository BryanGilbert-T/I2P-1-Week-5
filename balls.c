#include <stdio.h>

int f(int, int);
int main(void){
    int n, k;

    scanf("%d %d", &n, &k);
    printf("%d", f(n, k));
    return 0;
}

int f(int n, int k){
    if(n == k){
        return 1;
    }
    if(k == 0){
        return 0;
    }
    return f(n-1, k-1) + k * f(n-1, k);
}