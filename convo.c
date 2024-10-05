#include <stdio.h>

int main(void){
    int H, W;
    int H2, W2;

    scanf("%d %d", &H, &W);
    int temp[H][W];

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            scanf("%d", &temp[i][j]);
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

    int H3 = H + padding * 2;
    int W3 = W + padding * 2;

    int input[H3][W3];

    for(int i = 0; i < H3; i++){
        for(int j = 0; j < W3; j++){
            if(i < padding || j < padding){
                input[i][j] = 0;
            }
            else if(i >= H3 - padding || j >= W3 - padding){
                input[i][j] = 0;
            }
            else{
                input[i][j] = temp[i-padding][j-padding];
            }
        }
    }

    for(int i = 0; i < H3 - H2 + 1; i += stride){
        for(int j = 0; j < W3 - W2 + 1; j += stride){
            int sum = 0;
            for(int m = 0; m < H2; m++){
                for(int n = 0; n < W2; n++){
                    sum += input[i + m][j + n] * convo[m][n];
                }
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}

