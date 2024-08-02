#include <stdio.h>

int main() {
    int n, max_qty, i, j = 0;
    float max, sum = 0;
    int weights[20], values[20];

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and values of each item:\n");
    for (i = 0; i < n; i++) scanf("%d %d", &weights[i], &values[i]);

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &max_qty);

    while (max_qty > 0) {
        max = 0;
        for (i = 0; i < n; i++) {
            float ratio = (float)values[i] / weights[i];
            if (ratio > max) {
                max = ratio;
                j = i;
            }
        }
        if (weights[j] > max_qty) {
            printf("Item %d: %d units added\n", j + 1, max_qty);
            sum += max_qty * max;
            break;
        } else {
            printf("Item %d: %d units added\n", j + 1, weights[j]);
            max_qty -= weights[j];
            sum += values[j];
            values[j] = 0;
        }
    }

    printf("Total profit: %.2f\n", sum);
    return 0;
}
