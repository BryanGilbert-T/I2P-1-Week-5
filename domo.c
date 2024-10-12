#include <stdio.h>
#include <string.h>

void print(char str[1000], int length){
    int valid = 1;
    char result[1000000];

    int resultCounter = 0;

    int isInteger = 0;

    int integerTime = 1;
    int stringTime = 0;

    int integer = 0;
    for(int i = 0; i < length; i++){
        if(integerTime){
            // checking validity
            if(isalpha(str[i]) || str[i] == '0'){
                valid = 0;
                break;
            }
        }        
        else if(stringTime){
            // Checking Validity
            if(isInteger){
                if(isalpha(str[i]) || str[i + 1] != '\''){
                    valid = 0;
                    break;
                }
            }

            // Result
            for(int j = 0; j < integer; j++){
                result[resultCounter] = str[i];
                resultCounter++;
            }

            // Change time to integerTime
            integerTime = 1;
            stringTime = 0;

        }
        printf("%c", str[i]);
    }

    if(valid){
        printf("%s\n", result);
    }
    else{
        printf("Domo cannot crack this computer\n");
    }

}

int main(void){
    int alpha = 0;
    int integer = 1;

    char str[1000];

    while(scanf("%s", str) != EOF){
        print(str, strlen(str));

    }
    return 0;
}