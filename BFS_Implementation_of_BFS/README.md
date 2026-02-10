# Enterprise Insider Threat Detection - BFS Implementation

## Project Structure

```
BFS_Implementation_of_BFS/
├── bfs_security.c    # BFS algorithm for threat detection
└── README.md         # This file
```

## Overview

This project implements Breadth-First Search (BFS) to detect potential insider threats in an enterprise network. It identifies immediate contacts (one-hop neighbors) of a suspected compromised workstation and determines the highest-risk peer based on data transfer times.

## File Description

### bfs_security.c

Contains:
- `bfs_one_hop_and_highest_risk()` - BFS traversal for immediate neighbors
- `node_to_index()` / `index_to_node()` - Node mapping utilities
- Queue implementation for BFS (enqueue, dequeue operations)
- `add_edge()` - Graph construction with weighted edges
- User input handling for suspected workstation

## Features

-  **User Input** - Accept suspected compromised workstation (A-G)
-  **BFS Traversal** - Discover immediate contacts (one-hop neighbors)
-  **Risk Analysis** - Identify highest-risk peer by transfer time
-  **Weighted Graph** - Edge weights represent data transfer times
-  **Interactive** - Handles missing edge weights via user input

## Compilation Instructions

### Single Command

```bash
gcc -Wall -Wextra -std=c99 -o bfs_security bfs_security.c
./bfs_security
```

### Alternative

```bash
gcc bfs_security.c -o bfs_security
./bfs_security
```

## Program Execution

The program will:
1. Prompt for missing edge weights (A-D and D-F)
2. Ask for suspected compromised workstation (A-G)
3. Run BFS to find all direct peers
4. Display transfer times for each connection
5. Identify the highest-risk peer

### Sample Run

```
Enter missing edge weight for A-D (minutes). Enter 0 if no edge: 8
Enter missing edge weight for D-F (minutes). Enter 0 if no edge: 8

Enter suspected compromised workstation (A-G): B

--------------------------------------------
Suspected compromised workstation: B
Running BFS to discover ONE-HOP neighbors...
--------------------------------------------
Direct peer found: B <--> A  | transfer time = 6 mins
Direct peer found: B <--> D  | transfer time = 5 mins
Direct peer found: B <--> C  | transfer time = 11 mins

 Highest-risk direct peer: C  (11 mins)
```

## Network Graph

The enterprise network consists of:
- **Nodes**: 7 workstations (A-G)
- **Edges**: Connections with transfer times (minutes)
- **Known connections**: A-B(6), B-D(5), B-C(11), C-D(17), C-G(25), D-E(22), E-F(10), F-G(22)
- **User-defined**: A-D and D-F (configurable)

## Algorithm Details

- **BFS Strategy**: Level-order traversal starting from suspected node
- **One-Hop Discovery**: Only explores immediate neighbors (level 1)
- **Risk Metric**: Higher transfer time = higher risk
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V) for queue and visited array

## Use Cases

This implementation can be applied to:
- Insider threat detection
- Network security analysis
- Data breach investigation
- Access pattern monitoring
- Lateral movement detection

## Author Notes

This implementation demonstrates:
- BFS graph traversal algorithm
- Security incident response
- Network topology analysis
- Risk-based prioritization
