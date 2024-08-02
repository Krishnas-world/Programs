#include <stdio.h>
#include <stdlib.h>

int col[30], count = 0;

void Nqueen(int n);
int place(int r);

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    Nqueen(n);
    printf("Total number of solutions: %d\n", count);
    return 0;
}

void Nqueen(int n) {
    int r = 1;
    col[r] = 0;
    while (r > 0) {
        col[r]++;
        while (col[r] <= n && !place(r))
            col[r]++;
        if (col[r] <= n) {
            if (r == n) {
                count++;
                printf("Solution #%d\n", count);
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++)
                        printf((j == col[i]) ? "Q " : "* ");
                    printf("\n");
                }
            } else {
                col[++r] = 0;
            }
        } else {
            r--;
        }
    }
}

int place(int r) {
    for (int i = 1; i < r; i++)
        if (col[i] == col[r] || abs(i - r) == abs(col[i] - col[r]))
            return 0;
    return 1;
}
