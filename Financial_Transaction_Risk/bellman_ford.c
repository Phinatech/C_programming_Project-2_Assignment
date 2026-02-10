#include <stdio.h>
#include "bellman_ford.h"
#include "graph.h"

int bellman_ford(Edge edges[], int E, int src, int dist[], int parent[]) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        int changed = 0;

        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                changed = 1;
            }
        }

        if (!changed) break;
    }

    /* Negative cycle check */
    for (int j = 0; j < E; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 0; /* negative cycle detected */
        }
    }

    return 1; /* no negative cycle */
}

void print_path(int parent[], int src, int target) {
    if (target == src) {
        printf("%c", index_to_node(src));
        return;
    }
    if (parent[target] == -1) {
        printf("No path");
        return;
    }

    int stack[V];
    int top = 0;
    int cur = target;

    while (cur != -1) {
        stack[top++] = cur;
        if (cur == src) break;
        cur = parent[cur];
    }

    if (stack[top - 1] != src) {
        printf("No path");
        return;
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%c", index_to_node(stack[i]));
        if (i != 0) printf(" -> ");
    }
}