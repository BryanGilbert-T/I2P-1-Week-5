#include <stdio.h>

int main(void){
    int T;

    scanf("%d", &T);

    int N;

    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        int a[N];
        int sum;
        int max = a[0];
        for(int j = 0; j < N; j++){
            scanf("%d", &a[j]);
            a[j] = (j - 1 >= 0) ? a[j - 1] + a[j] : a[j];
        }

        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                sum = (i - 1 >= 0) ? a[j] - a[i - 1] : a[j];
                if(sum > max) max = sum;
                printf("sum: %d\n", sum);
            }
            printf("\nmax: %d\n\n", max);
        }
        printf("%d\n", max);
    }
    
    return 0;
}