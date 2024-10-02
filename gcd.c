#include <stdio.h>

int gcd(int x, int y);
int main(void){
    int x, y;

    scanf("%d %d", &x, &y);

    printf("%d\n", gcd(x, y));
    return 0;
}

int gcd(int x, int y){
    while(x!=y)
     {
          if(x>y)
              return gcd(x-y,y);
          else
             return gcd(x,y-x);
     }
     return x;
}