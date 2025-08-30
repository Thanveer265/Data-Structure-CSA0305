#include <stdio.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void bfs(int adj[SIZE][SIZE], int n, int start) {
    int visited[SIZE] = {0};
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[SIZE][SIZE];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("BFS Traversal: ");
    bfs(adj, n, 0);
    return 0;
}
