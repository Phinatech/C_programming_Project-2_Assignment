#ifndef GRAPH_H
#define GRAPH_H

#define V 10
#define MAXE 100

typedef struct {
    int u, v;
    int w;
} Edge;

/* Node mapping */
int node_to_index(char c);
char index_to_node(int i);

/* Edge helpers */
void add_directed(Edge edges[], int *E, int u, int v, int w);
void add_undirected(Edge edges[], int *E, int u, int v, int w);

/* Build the bank graph (with optional extra edges) */
void build_bank_graph(Edge edges[], int *E);

#endif