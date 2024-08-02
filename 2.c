#include <stdio.h>

#define INFI 99
#define MAX_VERTICES 10

int wt[MAX_VERTICES][MAX_VERTICES];
int edges[MAX_VERTICES - 1][2];
int n;

void prims(int source);

int main() {
    int source;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &wt[i][j]);

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    prims(source);
    return 0;
}

void prims(int source) {
    int visited[MAX_VERTICES] = {0};
    int lowcost[MAX_VERTICES], u[MAX_VERTICES], mincost = 0;

    visited[source] = 1;
    for (int i = 0; i < n; i++) {
        lowcost[i] = wt[source][i];
        u[i] = source;
    }

    for (int count = 1; count < n; count++) {
        int min = INFI, v = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && lowcost[i] < min) {
                min = lowcost[i];
                v = i;
            }

        if (v == -1) {
            printf("Graph is not connected.\n");
            return;
        }

        visited[v] = 1;
        mincost += lowcost[v];
        edges[count - 1][0] = u[v];
        edges[count - 1][1] = v;

        for (int i = 0; i < n; i++)
            if (!visited[i] && wt[v][i] < lowcost[i]) {
                lowcost[i] = wt[v][i];
                u[i] = v;
            }
    }

    printf("\nEdges of the Minimum Cost Spanning Tree:\n");
    for (int i = 0; i < n - 1; i++)
        printf("(%d, %d)\n", edges[i][0], edges[i][1]);

    printf("\nMinimum Cost Spanning Tree Weight: %d\n", mincost);
}
