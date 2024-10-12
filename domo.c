#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char str[1000];
    
    while(scanf("%s", str) != EOF){
        int index = 0;
        int jumlah = 0;
        int valid = 1;
        char output[1000000] = {'\0'};
        for(int i = 0; i < strlen(str);){
            //itung jumlah
            if(isdigit(str[i]) && str[i] != '0'){
                jumlah = str[i] - '0';
                i++;
            }
            else{
                valid = 0;
            }

            while(isdigit(str[i])){
                jumlah = (jumlah * 10) + (str[i] - '0');
                i++;
            }
            if(str[i] == '\''){
                i++;
                if(isalpha(str[i])){
                    valid = 0;
                }
                else{
                    for(int j = 0; j < jumlah; j++){
                        output[index++] = str[i];
                    }
                } 
                i++;
                if(str[i] != '\''){
                    valid = 0;
                }
                i++;
            }
            else{
                if(isalpha(str[i])){
                    for(int j = 0; j < jumlah; j++){
                        output[index++] = str[i];
                    }
                    i++;
                }
                else{
                    valid = 0;
                }
            }
        }
        if(valid){
            printf("%s\n", output);
        }
        else{
            printf("Domo cannot crack this computer\n");
        }
    }
    return 0;
}