#include <stdio.h>
#define INF 999

void prims(int n, int graph[20][20]) {
    int parent[20], key[20], mstSet[20];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n-1; count++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    int cost = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        cost += graph[i][parent[i]];
    }
    printf("Total cost of MST = %d\n", cost);
}

int main() {
    int n, graph[20][20];
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prims(n, graph);
    return 0;
}
