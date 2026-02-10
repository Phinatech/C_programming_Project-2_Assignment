#ifndef FIBER_NETWORK_H
#define FIBER_NETWORK_H

#define MAX_HUBS 10
#define MAX_EDGES 50

// Structure to represent an edge (fiber-optic connection)
typedef struct {
    int src;        // Source hub
    int dest;       // Destination hub
    int cost;       // Installation cost in millions
} Edge;

// Structure to represent a subset for Union-Find
typedef struct {
    int parent;
    int rank;
} Subset;

// Function declarations
void displayAdjacencyMatrix(int matrix[][MAX_HUBS], int numHubs, char hubs[]);
int find(Subset subsets[], int i);
void unionSets(Subset subsets[], int x, int y);
int compareEdges(const void *a, const void *b);
void kruskalMST(int graph[][MAX_HUBS], int numHubs, char hubs[]);
void createEdgeList(int graph[][MAX_HUBS], int numHubs, Edge edges[], int *edgeCount);

#endif // FIBER_NETWORK_H