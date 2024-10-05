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
        findHigh(arr, length);
    }
    return 0;
}

int findHigh(int *arr, int length){
    int prefixSum[length];
    for(int i = 0; i < length; i++){
        prefixSum[i] = (i - 1 >= 0) ? prefixSum[i - 1] + arr[i] : arr[i];
    }

    printf("\n\n");
    return 0;
}