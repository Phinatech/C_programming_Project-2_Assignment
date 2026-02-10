#include <stdio.h>
#include <stdlib.h>
#include "fiber_network.h"

// Display the adjacency matrix
void displayAdjacencyMatrix(int matrix[][MAX_HUBS], int numHubs, char hubs[]) {
    printf("\n ADJACENCY MATRIX (Installation Costs in Millions $)\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    // Print column headers
    printf("     ");
    for (int i = 0; i < numHubs; i++) {
        printf("  %c  ", hubs[i]);
    }
    printf("\n");
    
    printf("    ");
    for (int i = 0; i < numHubs; i++) {
        printf("─────");
    }
    printf("\n");
    
    // Print rows with data
    for (int i = 0; i < numHubs; i++) {
        printf("  %c │", hubs[i]);
        for (int j = 0; j < numHubs; j++) {
            if (matrix[i][j] == 0) {
                printf("  -  ");
            } else {
                printf(" %3d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("═══════════════════════════════════════════════════════════════\n");
}

// Find operation for Union-Find (with path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union operation for Union-Find (by rank)
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    // Attach smaller rank tree under root of higher rank tree
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function for sorting edges by cost
int compareEdges(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->cost - edge2->cost;
}

// Create a list of all edges from the adjacency matrix
void createEdgeList(int graph[][MAX_HUBS], int numHubs, Edge edges[], int *edgeCount) {
    *edgeCount = 0;
    for (int i = 0; i < numHubs; i++) {
        for (int j = i + 1; j < numHubs; j++) {
            if (graph[i][j] != 0) {
                edges[*edgeCount].src = i;
                edges[*edgeCount].dest = j;
                edges[*edgeCount].cost = graph[i][j];
                (*edgeCount)++;
            }
        }
    }
}

// Kruskal's Algorithm to find Minimum Spanning Tree
void kruskalMST(int graph[][MAX_HUBS], int numHubs, char hubs[]) {
    Edge edges[MAX_EDGES];
    Edge result[MAX_HUBS];  // MST will have at most numHubs-1 edges
    int edgeCount = 0;
    int resultCount = 0;
    
    printf("\n APPLYING KRUSKAL'S ALGORITHM\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    
    // Step 1: Create list of all edges
    createEdgeList(graph, numHubs, edges, &edgeCount);
    
    printf("➤ Step 1: Extracted %d fiber-optic connections from the network\n\n", edgeCount);
    
    printf("   All Available Connections:\n");
    printf("   ┌────────────────────────────────────────┐\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("   │ %c ←→ %c : $%d million%s│\n", 
               hubs[edges[i].src], 
               hubs[edges[i].dest], 
               edges[i].cost,
               edges[i].cost < 10 ? "           " : "          ");
    }
    printf("   └────────────────────────────────────────┘\n\n");
    
    // Step 2: Sort edges by cost (ascending)
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    
    printf("➤ Step 2: Sorted connections by installation cost (lowest first)\n\n");
    
    printf("   Sorted Connections:\n");
    printf("   ┌────────────────────────────────────────┐\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("   │ %c ←→ %c : $%d million%s│\n", 
               hubs[edges[i].src], 
               hubs[edges[i].dest], 
               edges[i].cost,
               edges[i].cost < 10 ? "           " : "          ");
    }
    printf("   └────────────────────────────────────────┘\n\n");
    
    // Step 3: Initialize Union-Find structure
    Subset *subsets = (Subset *)malloc(numHubs * sizeof(Subset));
    for (int i = 0; i < numHubs; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    
    printf("➤ Step 3: Selecting edges while avoiding cycles\n\n");
    printf("   Selection Process:\n");
    printf("   ┌──────────────────────────────────────────────────────┐\n");
    
    // Step 4: Process edges in sorted order
    int totalCost = 0;
    for (int i = 0; i < edgeCount && resultCount < numHubs - 1; i++) {
        int srcRoot = find(subsets, edges[i].src);
        int destRoot = find(subsets, edges[i].dest);
        
        // If including this edge doesn't create a cycle
        if (srcRoot != destRoot) {
            result[resultCount] = edges[i];
            totalCost += edges[i].cost;
            printf("   │ ✓ ACCEPT: %c ←→ %c ($%d million) - No cycle%s│\n", 
                   hubs[edges[i].src], 
                   hubs[edges[i].dest], 
                   edges[i].cost,
                   edges[i].cost < 10 ? "       " : "      ");
            unionSets(subsets, srcRoot, destRoot);
            resultCount++;
        } else {
            printf("   │ ✗ REJECT: %c ←→ %c ($%d million) - Creates cycle │\n", 
                   hubs[edges[i].src], 
                   hubs[edges[i].dest], 
                   edges[i].cost);
        }
    }
    printf("   └──────────────────────────────────────────────────────┘\n\n");
    
    // Display results
    printf("═══════════════════════════════════════════════════════════════\n");
    printf(" MINIMUM SPANNING TREE - SELECTED FIBER-OPTIC LINKS\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    
    printf("   Connections to Install:\n");
    printf("   ┌──────┬────────────────┬─────────────────────┐\n");
    printf("   │ Link │   Connection   │  Cost (Millions $)  │\n");
    printf("   ├──────┼────────────────┼─────────────────────┤\n");
    
    for (int i = 0; i < resultCount; i++) {
        printf("   │  %d   │   Hub %c ←→ %c   │        $%-13d│\n", 
               i + 1,
               hubs[result[i].src], 
               hubs[result[i].dest], 
               result[i].cost);
    }
    
    printf("   └──────┴────────────────┴─────────────────────┘\n\n");
    
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("💰 TOTAL INSTALLATION COST\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    printf("   Total Minimum Cost: $%d million\n\n", totalCost);
    
    printf("   Cost Breakdown:\n");
    for (int i = 0; i < resultCount; i++) {
        printf("   • Hub %c ←→ Hub %c: $%d million\n", 
               hubs[result[i].src], 
               hubs[result[i].dest], 
               result[i].cost);
    }
    
    printf("\n═══════════════════════════════════════════════════════════════\n");
    printf(" NETWORK DEPLOYMENT COMPLETE\n");
    printf("═══════════════════════════════════════════════════════════════\n\n");
    
    printf("   Network Statistics:\n");
    printf("   • Total Hubs Connected: %d\n", numHubs);
    printf("   • Fiber-Optic Links Installed: %d\n", resultCount);
    printf("   • Total Cost: $%d million\n", totalCost);
    printf("   • All hubs are interconnected\n");
    printf("   • No redundant connections\n");
    printf("   • Optimal cost achieved\n\n");
    
    free(subsets);
}
