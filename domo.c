#include <stdio.h>
#include <ctype.h>

int main(void){
    char str[100];
    int counter;

    char integer;
    char alpha;
    while(scanf("%s", str) != 0){
        for(int i = 0; str[i] != '\0'; i++){
            
            printf("%c", str[i]);
        }
    }
    printf("done");
    return 0;
}