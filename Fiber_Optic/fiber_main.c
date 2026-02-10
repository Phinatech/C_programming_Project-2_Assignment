#include <stdio.h>
#include <string.h>
#include "fiber_network.h"

int main() {
    printf("\n");
    printf("╔═══════════════════════════════════════════════════════════════╗\n");
    printf("║    SMART CITY FIBER-OPTIC NETWORK DEPLOYMENT SYSTEM          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════╝\n\n");
    
    printf(" National Telecommunications Authority\n");
    printf("   Fiber-Optic Backbone Network Optimization\n");
    printf("───────────────────────────────────────────────────────────────\n\n");
    
    // Define the hubs (vertices)
    char hubs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int numHubs = 7;
    
    // Initialize adjacency matrix
    int graph[MAX_HUBS][MAX_HUBS] = {0};
    
    // Populate the adjacency matrix based on the network diagram
    // From the image:
    // A-B: 6
    graph[0][1] = graph[1][0] = 6;
    
    // Based on the network diagram, the connections and costs are:
    
    // A-D: 8 (estimated from visual spacing)
    graph[0][3] = graph[3][0] = 8;
    
    // B-C: 11
    graph[1][2] = graph[2][1] = 11;
    
    // B-D: 5
    graph[1][3] = graph[3][1] = 5;
    
    // C-D: 17
    graph[2][3] = graph[3][2] = 17;
    
    // C-G: 25
    graph[2][6] = graph[6][2] = 25;
    
    // D-E: 22
    graph[3][4] = graph[4][3] = 22;
    
    // D-F: 8 (estimated from visual spacing)
    graph[3][5] = graph[5][3] = 8;
    
    // E-F: 10
    graph[4][5] = graph[5][4] = 10;
    
    // F-G: 22
    graph[5][6] = graph[6][5] = 22;
    
    printf("📍 Smart City Hubs: ");
    for (int i = 0; i < numHubs; i++) {
        printf("%c", hubs[i]);
        if (i < numHubs - 1) printf(", ");
    }
    printf("\n\n");
    
    printf(" Note: Based on the network diagram provided.\n");
    printf("   Edge weights A-D and D-F were estimated as 8 million each\n");
    printf("   (values not clearly visible in the provided diagram).\n\n");
    
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("TASK 1: Network Modeling - Adjacency Matrix\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    displayAdjacencyMatrix(graph, numHubs, hubs);
    
    printf("\n Matrix Interpretation:\n");
    printf("   • Rows and columns represent smart city hubs (A-G)\n");
    printf("   • Values represent installation costs in millions of dollars\n");
    printf("   • '-' indicates no direct fiber-optic connection\n");
    printf("   • Matrix is symmetric (undirected network)\n\n");
    
    printf("═══════════════════════════════════════════════════════════════\n");
    printf("TASK 2: Minimum Spanning Tree using Kruskal's Algorithm\n");
    printf("═══════════════════════════════════════════════════════════════\n");
    
    // Apply Kruskal's algorithm
    kruskalMST(graph, numHubs, hubs);
    
    return 0;
}
