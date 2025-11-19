
#include <stdio.h>

int arr[10][10], visited[10], n,i;

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for(i = 1; i <= n; i++)
    {
        if (arr[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

void BFS(int v)
{
    int queue[10], front = 0, rear = 0,i;

    printf("%d ", v);
    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear)
    {
        v = queue[front++];

        for (i = 1; i <= n; i++)
        {
            if (arr[v][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    DFS(start);

    printf("\nBFS Traversal: ");
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    BFS(start);

    return 0;
}


