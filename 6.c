#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int wt[], int val[], int c, int v[21][21]) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (wt[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - wt[i]] + val[i]);
        }
    }
}

int main() {
    int n, c, val[21], wt[21], v[21][21];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the values of the items: ");
    for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
    printf("Enter the weights of the items: ");
    for (int i = 1; i <= n; i++) scanf("%d", &wt[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &c);

    knapsack(n, wt, val, c, v);
    int optimalValue = v[n][c];

    // Print the DP table
    printf("\nDP Table:\n");
    printf("   ");
    for (int j = 0; j <= c; j++) {
        printf("%4d", j);
    }
    printf("\n");
    for (int i = 0; i <= n; i++) {
        printf("%2d ", i);
        for (int j = 0; j <= c; j++) {
            printf("%4d", v[i][j]);
        }
        printf("\n");
    }

    // Print the optimal value
    printf("\nOptimal solution: %d\n", optimalValue);

    // Print the selected items
    printf("Selected items: ");
    int currentCapacity = c;
    for (int i = n; i > 0; i--) {
        if (optimalValue != v[i - 1][currentCapacity]) {
            printf("%d ", i);
            currentCapacity -= wt[i];
            optimalValue -= val[i];
        }
    }

    printf("\n");
    return 0;
}
