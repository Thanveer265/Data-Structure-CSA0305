#include <stdio.h>
#define SIZE 10

void dfs(int adj[SIZE][SIZE], int visited[SIZE], int v, int n) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(adj, visited, i, n);
    }
}

int main() {
    int n, adj[SIZE][SIZE], visited[SIZE] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("DFS Traversal: ");
    dfs(adj, visited, 0, n);
    return 0;
}
