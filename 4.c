#include <stdio.h>
#define INFI 99
void dijkstra(int, int);
int minVertex(int);
int dist[10], p[10], visit[10], wt[10][10], n;

int main()
{
    int i, j, s;
    printf("Enter the number of vertices");
    scanf("%d", &n);
    printf("Enter the weight matrix");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &wt[i][j]);
        }
    }
    printf("Enter the source vertex");
    scanf("%d", &s);
    s--;
    printf("Shortest path from %d is:", s + 1);
    dijkstra(s, n);
    return 0;
}

void dijkstra(int s, int n)
{
    int i, j, u;
    for (i = 0; i < n; i++)
    {
        dist[i] = wt[s][i];
        p[i] = (wt[s][i] == INFI ? -1 : s);
        visit[i] = 0;
    }
    dist[s] = 0;
    visit[s] = 0;
    for (i = 0; i < n; i++)
    {
        u = minVertex(n);
        if (u == -1)
        {
            break;
        }
        visit[u] = 1;

        for (j = 0; j < n; j++)
        {
            visit[u]=1;
            if (!visit[j]&&dist[u]+wt[u][j]<dist[j])
            {
                dist[j]=dist[u]+wt[u][j];
                p[j]=u;
            }
            
        }
    }

    for ( i = 0; i < n; i++)
    {
        if (i!=s && p[i]!=-1)
        {
            printf("Vertex %d -> length %d, path:%d", i+1,dist[i],i+1);
            for ( j = p[i]; j !=s ; j=p[j])
            {
                printf("<--%d", j+1);
            }
            printf("<--%d", s+1);
            
        }
        
    }
    
}

int minVertex(int n){
    int i, u=-1, min=INFI;
    for ( i = 0; i < n; i++)
    {
        if(!visit[i] && dist[i]<min){
            min=dist[i];
            u=i;
        }
        return u;
    }
    
}