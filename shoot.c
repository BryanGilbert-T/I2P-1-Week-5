#include <stdio.h>
#include <stdlib.h>

int* move(char *command);
int* motion(char *command, char nowValue);
int main(void){
    int H, W;
    char D[10];

    scanf("%d %d", &H, &W);
    scanf("%s", D);

    char map[H][W + 1];

    int S[2];

    for(int i = 0; i < H; i++){
        scanf("%s", &map[i]);
    }


    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(map[i][j] == 'S'){
                S[0] = i;
                S[1] = j;
            } 
        }
    }
    
    printf("Sx: %d\nSy: %d\n", S[0], S[1]);

    return 0;
}


int* motion(char *command, char nowValue){
    if(command == "Left"){
        if(nowValue == '\\'){
            return move("Up");
        }
        if(nowValue == '/'){
            return move("Down");
        }
        return move("Left");
    }
    if(command == "Right"){
        if(nowValue == '\\'){
            return move("Down");
        }
        if(nowValue == '/'){
            return move("Up");
        }
        return move("Right");
    }
    if(command == "Up"){
        if(nowValue == '\\'){
            return move("Left");
        }
        if(nowValue == '/'){
            return move("Right");
        }
        return move("Up");
    }
    if(command == "Down"){
        if(nowValue == '\\'){
            return move("Right");
        }
        if(nowValue == '/'){
            return move("Left");
        }
        return move("Down");
    }
}

int* move(char *command){
    int *coordinate = malloc(2 * sizeof(int));
    if(command == "Left"){
        coordinate[0] = 0;
        coordinate[1] = -1;
    }
    else if(command == "Right"){
        coordinate[0] = 0;
        coordinate[1] = 1;
    }
    else if(command == "Up"){
        coordinate[0] = 1;
        coordinate[1] = 0;
    }
    else if(command == "Down"){
        coordinate[0] = -1;
        coordinate[1] = 0;
    }
    return coordinate;
}