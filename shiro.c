#include <stdio.h>
#include <limits.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        long long max_sum = LLONG_MIN;
        long long current_sum = 0; 

        for (int j = 0; j < N; j++) {
            long long value;
            scanf("%lld", &value);

            current_sum += value; 

            if (current_sum > max_sum) {
                max_sum = current_sum; 
            }

            if (current_sum < 0) {
                current_sum = 0; 
            }
        }

        printf("%lld\n", max_sum); 
    }

    return 0;
}