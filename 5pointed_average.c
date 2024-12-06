#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    // Ask the user for the number of random numbers to generate
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);

    if (n < 5) {
        printf("You need at least 5 numbers to calculate the 5-point weighted moving average.\n");
        return 0;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate n random numbers between 1 and 100
    int arr[n];
    printf("Generated random numbers: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;  // Random number between 1 and 100
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Define the weights for the 5-point window
    int weights[] = {1, 2, 3, 2, 1};
    int weightSum = 1 + 2 + 3 + 2 + 1; // The sum of the weights is 9

    // Calculate the 5-point weighted moving average for each window
    printf("5-point weighted moving averages:\n");
    for (int i = 0; i <= n - 5; i++) {
        int weightedSum = 0;

        // Calculate the weighted sum for the window [i, i+1, i+2, i+3, i+4]
        for (int j = 0; j < 5; j++) {
            weightedSum += arr[i + j] * weights[j];
        }

        // Calculate and print the weighted moving average
        float weightedAverage = (float)weightedSum / weightSum;
        printf("For window %d to %d: Weighted Moving Average = %.2f\n", i + 1, i + 5, weightedAverage);
    }

    return 0;
}

