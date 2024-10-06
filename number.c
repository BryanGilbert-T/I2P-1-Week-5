#include <stdio.h>

int selection(int *arr, long long length, long long k);
int main(void){
    int T;
    long long N, K, K2;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%lld", &N);
        int arr[N];
        for(int j = 0; j < N; j++){
            scanf("%d", &arr[j]);
        }
        scanf("%lld", &K);
        K2 = K;
        
        while(selection(arr, N, K)){
            K = K + K2;
        }
        printf("%lld\n", K);
    }
    
    return 0;
}

int selection(int *arr, long long length, long long k){
    for(long long i = 0; i < length; i++){
        if(k == arr[i]){
            return 1;
        }
        if(k == arr[length - i - 1]){
            return 1;
        }
    }
    return 0;
}