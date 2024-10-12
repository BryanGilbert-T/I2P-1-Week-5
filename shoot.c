#include <stdio.h>
#include <stdlib.h>

int* move(char command);
int* motion(char command, char nowValue);
int main(void){
    int H, W;
    char D[10];

    scanf("%d %d", &H, &W);
    scanf("%s", D);
    char command = D[0];

    char map[H][W + 1];

    int Sx, Sy;

    for(int i = 0; i < H; i++){
        scanf("%s", &map[i]);
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(map[i][j] == 'S'){
                Sx = i;
                Sy = j;
            } 
        }
    }



    while(1){
        int *movement = motion(command, map[Sx][Sy]);
        map[Sx][Sy] = command;
        Sx += movement[0];
        Sy += movement[1];
        if(Sx < 0 || Sx > H || Sy < 0 || Sy > W){
            printf("%d %d\n", Sy -= movement[1], Sx -= movement[0]);
            break;
        }
        if(map[Sx][Sy] == command){
            printf("Stuck QQ\n");
            break;
        }
        free(movement);
    }


    return 0;
}


int* motion(char command, char nowValue){
    if(command == 'L'){
        if(nowValue == '\\'){
            return move('U');
        }
        if(nowValue == '/'){
            return move('D');
        }
        return move('L');
    }
    if(command == 'R'){
        if(nowValue == '\\'){
            return move('D');
        }
        if(nowValue == '/'){
            return move('U');
        }
        return move('R');
    }
    if(command == 'U'){
        if(nowValue == '\\'){
            return move('L');
        }
        if(nowValue == '/'){
            return move('R');
        }
        return move('U');
    }
    if(command == 'D'){
        if(nowValue == '\\'){
            return move('R');
        }
        if(nowValue == '/'){
            return move('L');
        }
        return move('D');
    }
}

int* move(char command){
    int *coordinate = malloc(2 * sizeof(int));
    if(command == 'L'){
        coordinate[0] = 0;
        coordinate[1] = -1;
    }
    else if(command == 'R'){
        coordinate[0] = 0;
        coordinate[1] = 1;
    }
    else if(command == 'U'){
        coordinate[0] = 1;
        coordinate[1] = 0;
    }
    else if(command == 'D'){
        coordinate[0] = -1;
        coordinate[1] = 0;
    }
    return coordinate;
}