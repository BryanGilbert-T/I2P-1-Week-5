#include <stdio.h>

int main(){
    int d1,d2,gcd;
    scanf("%d %d", &d1, &d2);
    for(int i = 1; i<=d1 && i<=d2; i++){
        if(d1%i==0 && d2%i == 0)gcd=i;
    }
    printf("%d",gcd);
}