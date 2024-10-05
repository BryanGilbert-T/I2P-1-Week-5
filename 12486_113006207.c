#include <stdio.h>

void hanoi(int n, char from, char temp, char to);
int main(){
    int n;
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char from, char temp, char to){
    if(n == 1){
        printf("move disk %d from rod %c to rod %c\n", 1, from, to);
    }
    else{
        hanoi(n - 1, from, to, temp);

        printf("move disk %d from rod %c to rod %c\n", n, from, to);

        hanoi(n - 1, temp, from, to);
    }

}
