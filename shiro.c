#include <stdio.h>

int findHigh(int *arr, int length);
int main(void){
    int T;
    scanf("%d", &T);
    int length;
    for(int i = 0; i < T; i++){
        scanf("%d", &length);
        int arr[length];
        for(int i = 0; i < length; i++){
            scanf("%d", &arr[i]);
        }
        printf("max: %d\n", findHigh(arr, length));
    }
    return 0;
}

int findHigh(int *arr, int length){
    int prefixSum[length];
    for(int i = 0; i < length; i++){
        prefixSum[i] = (i - 1 >= 0) ? prefixSum[i - 1] + arr[i] : arr[i];
    }

    int max = prefixSum[0];
    int big;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            big = prefixSum[j] - prefixSum[i - 1];
            if(big > max){
                max = big;
            }
        }
    }

    return max;
}