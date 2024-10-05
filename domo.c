#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkValidity(char *chr, int length);
void print(char *inp, int length);
int main(void){
    char str[100];
    int valid;
    while(scanf("%s", str) != 0){
        valid = checkValidity(str, strlen(str));
        if(valid){
            print(str, strlen(str));
        }
        else{
            printf("Domo cannot crack this computer");
        }
        printf("\n");
    }
    return 0;
}


int checkValidity(char *chr, int length){
    int counter = 1;
    int isInt = 0;
    for(int i = 0; i < length; i++){
        if(counter == 1){
            // Check if its not number
            // If its number check if its 0
            // if any of those conditions are true return 0;
            if(!isdigit(chr[i]) || chr[i] == '0'){
                return 0;
            }

            //check if the next alpha supposed to be number
            if(chr[i + 1] == '\''){
                i += 1;
                isInt = 1;
            }
            counter = 0;
            i += 1;
        }
        if(i >= length){
            return 0;
        }
        if(counter == 0){
            if(isInt){
                // if its supposed to be int
                // but its not or the next int is not '
                // return 0;
                if(!isdigit(chr[i]) || chr[i + 1] != '\''){
                    return 0;
                }
                else{
                    i += 1;
                }
                isInt = 0;
            }
            else{
                if(!isalpha(chr[i])){
                    return 0;
                }
            }
            counter = 1;
        }
    }
    return 1;
}

void print(char *inp, int length){
    int iteration;
    char mvp;
    for(int i = 0; i < length; i++){
        iteration = inp[i] - '0';
        mvp = inp[i + 1];
        if(inp[i + 1] == '\''){
            i += 2;
            mvp = inp[i];
        }
        i += 1;
        for(int j = 0; j < iteration; j++){
            printf("%c", mvp);
        }
    }
}