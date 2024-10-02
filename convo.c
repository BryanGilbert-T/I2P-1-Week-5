#include <stdio.h>

int main(void){
    int H, W;
    int H2, W2;

    scanf("%d %d", &H, &W);
    int input[H][W];

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &input[i][j]);
        }
    }

    scanf("%d %d", &H2, &W2);
    int convo[H2][W2];
    for(int i = 0; i < H2; i++){
        for(int j = 0; j < W2; j++){
            scanf("%d", &convo[i][j]);
        }
    }

    int stride, padding;
    scanf("%d %d", &stride, &padding);
    return 0;
}