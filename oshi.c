#include <stdio.h>

int main(void){
    int T, N;
    
    scanf("%d", &T);
    scanf("%d", &N);

    int matrix[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum;
    for(int i = 0; i < T; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        sum = 0;

        for(int k = 0; k < N; k++){
            sum += matrix[k][y];
            sum += matrix[x][k];

            sum += ()? matrix[x+k][y+k] : 0;
            sum += (0 <= (x + k) && (x + k) < N && 0 <= (y - k) && (y - k) < N) ? matrix[x+k][y-k] : 0;

            sum += (0 <= (x + k) && (x + k) < N && 0 <= (y + k) && (y + k) < N) ? matrix[x-k][y+k] : 0;
            sum += (0 <= (x + k) && (x + k) < N && 0 <= (y - k) && (y - k) < N) ? matrix[x-k][y-k] : 0;
        }
        sum -= 3 * matrix[x][y];

        printf("%d\n", sum);
    }

    return 0;
}