#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int adj[MAX][MAX];
    int visited[MAX];
    int V;
} Graph;

void bfs(Graph *g, int start) {
    int queue[MAX], front = 0, rear = 0;
    g->visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 0; i < g->V; i++)
            if (g->adj[node][i] && !g->visited[i]) {
                g->visited[i] = 1;
                queue[rear++] = i;
            }
    }
}

int main() {
    Graph g = {0};
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &g.V);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        g.adj[u][v] = g.adj[v][u] = 1;
    }

    printf("Enter start vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS: ");
    bfs(&g, start);
    printf("\n");

    return 0;
}
