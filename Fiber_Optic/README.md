# Smart City Fiber-Optic Network - Kruskal's MST Implementation

## Project Structure

```
Fiber_Optic/
├── fiber_network.h    # Structures and function declarations
├── fiber_network.c    # Kruskal's algorithm implementation
├── fiber_main.c       # Main program with network setup
└── README.md          # This file
```

## Overview

This project implements Kruskal's Minimum Spanning Tree algorithm to optimize fiber-optic cable installation costs for a smart city network. It connects 7 city hubs (A-G) with minimum total cost while ensuring all hubs are interconnected.

## File Descriptions

### 1. fiber_network.h

Contains:
- `Edge` structure (source, destination, cost)
- `Subset` structure for Union-Find operations
- Function prototypes for Kruskal's algorithm
- Constants: MAX_HUBS (10), MAX_EDGES (50)

### 2. fiber_network.c

Contains Kruskal's algorithm implementation:
- `kruskalMST()` - Main MST algorithm with Union-Find
- `find()` - Find operation with path compression
- `unionSets()` - Union operation by rank
- `createEdgeList()` - Convert adjacency matrix to edge list
- `compareEdges()` - Sort edges by cost
- `displayAdjacencyMatrix()` - Display network topology

### 3. fiber_main.c

Contains:
- Smart city hub definitions (A-G)
- Adjacency matrix initialization
- Network topology with installation costs
- Kruskal's algorithm execution

## Compilation Instructions

### Manual Compilation

```bash
# Compile source files
gcc -Wall -Wextra -std=c99 -c fiber_network.c
gcc -Wall -Wextra -std=c99 -c fiber_main.c

# Link object files
gcc -Wall -Wextra -std=c99 -o fiber_optic fiber_main.o fiber_network.o

# Run
./fiber_optic
```

### Single Command

```bash
gcc -Wall -Wextra -std=c99 -o fiber_optic fiber_main.c fiber_network.c
./fiber_optic
```

## Program Output

The program displays:
- **Task 1**: Adjacency matrix showing all hub connections and costs
- **Task 2**: Kruskal's algorithm execution with:
  - All available connections
  - Sorted connections by cost
  - Edge selection process (accept/reject with cycle detection)
  - Final MST with selected fiber-optic links
  - Total installation cost breakdown
  - Network statistics

## Use Cases

This implementation can be applied to:
- Fiber-optic network deployment
- Telecommunications infrastructure
- Smart city connectivity
- Power grid optimization
- Transportation network planning

## Algorithm Complexity

- **Time Complexity**: O(E log E) - dominated by edge sorting
- **Space Complexity**: O(V + E) - adjacency matrix and edge list
- **Union-Find**: Nearly O(1) amortized with path compression

## Network Details

- **Hubs**: 7 smart city locations (A, B, C, D, E, F, G)
- **Connections**: 10 possible fiber-optic links
- **Cost Range**: $5M - $25M per connection
- **MST Edges**: 6 connections (V-1 for V vertices)

## Author Notes

This implementation demonstrates:
- Kruskal's greedy MST algorithm
- Union-Find data structure
- Smart city infrastructure optimization
- Real-world network deployment planning
