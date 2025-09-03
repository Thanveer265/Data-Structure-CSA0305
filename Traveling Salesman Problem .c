#include <stdio.h>
#define V 4
#define INF 9999

int min(int a, int b) { return (a < b) ? a : b; }

int tsp(int graph[V][V], int start) {
    int visited[4] = {0}, cost = 0, count = 1, k = start;
    visited[start] = 1;

    while (count < V) {
        int minCost = INF, next = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[k][i] && graph[k][i] < minCost) {
                minCost = graph[k][i];
                next = i;
            }
        }
        visited[next] = 1;
        cost += minCost;
        k = next;
        count++;
    }
    cost += graph[k][start];
    return cost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    printf("TSP Minimum Cost = %d\n", tsp(graph, 0));
    return 0;
}
