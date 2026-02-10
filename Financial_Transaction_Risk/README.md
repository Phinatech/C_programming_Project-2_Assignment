# Financial Transaction Risk - Bellman-Ford Implementation

## Project Structure

```
Financial_Transaction_Risk/
├── graph.h           # Graph structure and node mapping
├── graph.c           # Graph construction and utilities
├── bellman_ford.h    # Bellman-Ford algorithm declarations
├── bellman_ford.c    # Bellman-Ford implementation
├── main.c            # Main program with transaction analysis
└── README.md         # This file
```

## Overview

This project implements the Bellman-Ford algorithm to detect negative-weight cycles in a financial transaction network. It analyzes transaction costs between bank branches and identifies potentially exploitable routes or unstable transaction patterns.

## File Descriptions

### 1. graph.h & graph.c

Contains:
- `Edge` structure definition (source, destination, weight)
- Node-to-index mapping functions
- Graph construction utilities
- `build_bank_graph()` - Creates the bank branch network

### 2. bellman_ford.h & bellman_ford.c

Contains:
- `bellman_ford()` - Detects negative cycles and computes shortest paths
- `print_path()` - Displays the transaction route
- Distance and parent tracking for path reconstruction

### 3. main.c

Contains:
- Transaction network initialization
- Bellman-Ford execution from source branch
- Results display with paths and cumulative costs
- Negative cycle detection reporting

## Compilation Instructions

### Manual Compilation

```bash
# Compile all source files
gcc -Wall -Wextra -std=c99 -c graph.c
gcc -Wall -Wextra -std=c99 -c bellman_ford.c
gcc -Wall -Wextra -std=c99 -c main.c

# Link object files
gcc -Wall -Wextra -std=c99 -o transaction_risk graph.o bellman_ford.o main.o

# Run
./transaction_risk
```

### Single Command

```bash
gcc -Wall -Wextra -std=c99 -o transaction_risk main.c graph.c bellman_ford.c
./transaction_risk
```

## Program Output

The program displays:
- Minimum cumulative transaction cost from source branch to all other branches
- Complete transaction path for each destination
- Negative-weight cycle detection (if present)
- Unreachable branches (if any)

## Algorithm Features

-  **Bellman-Ford Algorithm** - Handles negative edge weights
-  **Negative Cycle Detection** - Identifies exploitable transaction routes
-  **Path Reconstruction** - Shows complete transaction sequences
-  **Distance Tracking** - Computes minimum cumulative costs
-  **Graph Representation** - Edge-list based implementation

## Use Cases

This implementation can be applied to:
- Financial transaction risk analysis
- Currency arbitrage detection
- Network routing with negative costs
- Supply chain optimization
- Credit risk assessment

## Memory Management

- Static array allocation for edges and distances
- No dynamic memory allocation required
- Efficient O(V*E) time complexity

## Author Notes

This implementation demonstrates:
- Classic graph algorithm application
- Financial network modeling
- Negative cycle detection
- Modular C programming design
