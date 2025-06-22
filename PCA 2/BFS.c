#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAXV];
int visited[MAXV];
int queue[MAXV], front = 0, rear = 0;

void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void addEdge(int u, int v) {
    Node* node = malloc(sizeof(Node));
    node->v = v;
    node->next = adj[u];
    adj[u] = node;
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;
    printf("BFS: ");
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        for (Node* p = adj[u]; p; p = p->next) {
            if (!visited[p->v]) {
                visited[p->v] = 1;
                enqueue(p->v);
            }
        }
    }
    printf("\n");
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) adj[i] = NULL, visited[i] = 0;
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    int start;
    scanf("%d", &start);
    bfs(start);
    return 0;
}
