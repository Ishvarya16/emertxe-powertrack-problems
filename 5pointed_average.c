#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    if (n < 5) {
        printf("You need at least 5 numbers to calculate the 5-point weighted moving average.\n");
        return 0;
    }

    
    srand(time(0));

    
    int arr[n];
    printf("Generated random numbers: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;  
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    int weights[] = {1, 2, 3, 2, 1};
    int weightSum = 1 + 2 + 3 + 2 + 1;

    
    printf("5-point weighted moving averages:\n");
    for (int i = 0; i <= n - 5; i++) {
        int weightedSum = 0;

        
        for (int j = 0; j < 5; j++) {
            weightedSum += arr[i + j] * weights[j];
        }

        
        float weightedAverage = (float)weightedSum / weightSum;
        printf("For window %d to %d: Weighted Moving Average = %.2f\n", i + 1, i + 5, weightedAverage);
    }

    return 0;
}

