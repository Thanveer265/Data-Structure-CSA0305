#include <stdio.h>

struct Edge {
    int u, v, w;
};

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xr = find(parent, x), yr = find(parent, y);
    if (rank[xr] < rank[yr]) parent[xr] = yr;
    else if (rank[xr] > rank[yr]) parent[yr] = xr;
    else { parent[yr] = xr; rank[xr]++; }
}

void kruskal(int n, int m, struct Edge edges[]) {
    // Sort edges by weight
    for (int i = 0; i < m-1; i++)
        for (int j = 0; j < m-i-1; j++)
            if (edges[j].w > edges[j+1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }

    int parent[n], rank[n];
    for (int i = 0; i < n; i++) { parent[i] = i; rank[i] = 0; }

    int cost = 0, e = 0;
    printf("\nEdge \tWeight\n");
    for (int i = 0; i < m && e < n-1; i++) {
        int u = edges[i].u, v = edges[i].v;
        int setU = find(parent, u), setV = find(parent, v);

        if (setU != setV) {
            printf("%d - %d \t%d\n", u, v, edges[i].w);
            cost += edges[i].w;
            unionSet(parent, rank, setU, setV);
            e++;
        }
    }
    printf("Total cost of MST = %d\n", cost);
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[m];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal(n, m, edges);
    return 0;
}
