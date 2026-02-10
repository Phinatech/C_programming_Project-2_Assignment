#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "graph.h"

#define INF 1000000000

int bellman_ford(Edge edges[], int E, int src, int dist[], int parent[]);
void print_path(int parent[], int src, int target);

#endif
