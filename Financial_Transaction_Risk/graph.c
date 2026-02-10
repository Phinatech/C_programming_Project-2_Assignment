#include <stdio.h>
#include <ctype.h>
#include "graph.h"

int node_to_index(char c) {
    c = (char)toupper((unsigned char)c);
    if (c < 'A' || c > 'J') return -1;
    return c - 'A';
}

char index_to_node(int i) {
    return (char)('A' + i);
}

void add_directed(Edge edges[], int *E, int u, int v, int w) {
    if (*E >= MAXE) return;
    edges[*E].u = u;
    edges[*E].v = v;
    edges[*E].w = w;
    (*E)++;
}

void add_undirected(Edge edges[], int *E, int u, int v, int w) {
    add_directed(edges, E, u, v, w);
    add_directed(edges, E, v, u, w);
}

void build_bank_graph(Edge edges[], int *E) {
    *E = 0;

    int A = node_to_index('A');
    int B = node_to_index('B');
    int C = node_to_index('C');
    int D = node_to_index('D');
    int ENode = node_to_index('E');
    int F = node_to_index('F');
    int G = node_to_index('G');
    int H = node_to_index('H');
    int I = node_to_index('I');
    int J = node_to_index('J');

    /* Edges clearly visible in the diagram */
    add_undirected(edges, E, A, B, 4);
    add_undirected(edges, E, A, D, 16);

    add_undirected(edges, E, B, C, 6);
    add_undirected(edges, E, B, D, 6);
    add_undirected(edges, E, B, J, 7);

    add_undirected(edges, E, C, G, 9);
    add_undirected(edges, E, G, H, 13);

    add_undirected(edges, E, J, F, 3);

    add_undirected(edges, E, D, ENode, 7);
    add_undirected(edges, E, ENode, F, 10);

    add_undirected(edges, E, F, I, 10);
    add_undirected(edges, E, ENode, I, 2);

    /* Optional edges (if your lecturer says they exist) */
    int wDJ, wFG;

    printf("Optional edges (enter 0 if NOT present).\n");
    printf("Enter weight for edge D-J: ");
    if (scanf("%d", &wDJ) == 1 && wDJ != 0)
        add_undirected(edges, E, D, J, wDJ);

    printf("Enter weight for edge F-G: ");
    if (scanf("%d", &wFG) == 1 && wFG != 0)
        add_undirected(edges, E, F, G, wFG);
}
