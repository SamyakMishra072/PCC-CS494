#include <stdio.h>
#include <stdlib.h>

Node* adj2[MAXV];
int vis2[MAXV];

void dfs(int u) {
    vis2[u] = 1;
    printf("%d ", u);
    for (Node* p = adj2[u]; p; p = p->next) {
        if (!vis2[p->v]) dfs(p->v);
    }
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) adj2[i] = NULL, vis2[i] = 0;
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v); // reuse addEdge which adds to adj
        addEdge(v, u);
    }
    int start;
    scanf("%d", &start);
    printf("DFS: ");
    dfs(start);
    printf("\n");
    return 0;
}
