#include <stdio.h>
#include <stdlib.h>

int* move(char command);

int main(void){
    int H, W;
    char D[10];
    char com;

    scanf("%d %d", &H, &W);
    scanf("%s", D);
    com = D[0];

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
        if(map[Sx][Sy] == '.' || map[Sx][Sy] == 'S'){
            map[Sx][Sy] = com;
        }
        int *movement;

        if(com == 'L'){
            if(map[Sx][Sy] == '\\'){
                com = 'U';
                movement = move(com);
            }
            if(map[Sx][Sy] == '/'){
                com = 'D';
                movement = move(com);
            }
            else{
                movement = move(com);
            }   
        }
        else if(com == 'R'){
            if(map[Sx][Sy] == '\\'){
                com = 'D';
                movement = move(com);
            }
            if(map[Sx][Sy] == '/'){
                com = 'U';
                movement = move(com);
            }
            else{
                movement = move(com);
            }   
        }
        else if(com == 'U'){
            if(map[Sx][Sy] == '\\'){
                com = 'L';
                movement = move(com);
            }
            if(map[Sx][Sy] == '/'){
                com = 'R';
                movement = move(com);
            }
            else{
                movement = move(com);
            }   
        }
        else if(com == 'D'){
            if(map[Sx][Sy] == '\\'){
                com = 'R';
                movement = move(com);
            }
            if(map[Sx][Sy] == '/'){
                com = 'L';
                movement = move(com);
            }
            else{
                movement = move(com);
            }   
        }

        Sx = Sx + movement[0];
        Sy = Sy + movement[1];

        if(Sx < 0 || Sx >= H || Sy < 0 || Sy >= W){
            printf("%d %d\n", Sx -= movement[0], Sy -= movement[1]);
            break;
        }
        if(map[Sx][Sy] == com){
            printf("Stuck QQ\n");
            break;
        }

        free(movement);
    }

/*
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
    */
    

    return 0;
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
        coordinate[0] = -1;
        coordinate[1] = 0;
    }
    else if(command == 'D'){
        coordinate[0] = 1;
        coordinate[1] = 0;
    }
    return coordinate;
}