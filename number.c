#include <stdio.h>

int main(void){
    int T;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        long long N;
        long long K;
        scanf("%lld", &N);

        long long arr[N];
        long long sum = 1;

        for(int j = 0; j < N; j++){
            scanf("%lld", &arr[j]);
            sum += arr[j];
        }  
        scanf("%lld", &K);
        long long sum0 = K*(N*(N+1)) / 2;
        printf("%lld\n", sum0 - sum);

    }
    return 0;
}