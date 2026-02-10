#include <stdio.h>
#include "graph.h"
#include "bellman_ford.h"

int main(void) {
    Edge edges[MAXE];
    int E = 0;

    /* Build the graph */
    build_bank_graph(edges, &E);

    int src = node_to_index('A'); /* Branch A is the source */

    int dist[V], parent[V];
    int ok = bellman_ford(edges, E, src, dist, parent);

    printf("\n=========================================\n");
    printf("Bellman–Ford Results (Source: Branch A)\n");
    printf("=========================================\n");

    if (!ok) {
        printf("Negative-weight cycle detected!\n");
        printf("This indicates an unstable/exploitable transaction route.\n");
        return 0;
    }

    for (int v = 0; v < V; v++) {
        printf("\nBranch %c:\n", index_to_node(v));
        if (dist[v] == INF) {
            printf("  Minimum cumulative cost: INF (unreachable)\n");
            printf("  Path: No path\n");
        } else {
            printf("  Minimum cumulative cost: %d\n", dist[v]);
            printf("  Path: ");
            print_path(parent, src, v);
            printf("\n");
        }
    }

    return 0;
}