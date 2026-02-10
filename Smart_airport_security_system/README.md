# Smart Airport Security Control System

An automated passenger risk assessment and screening system using Max-Heap data structure for priority-based security screening.

## Project Structure

```
airport_security/
├── airport_security.h       # Header file with structures and declarations
├── airport_security.c       # Implementation of security queue operations
├── airport_security_main.c  # Main program demonstrating the system
└── README.md                # This file
```

## Overview

This system demonstrates a real-world application of Max-Heap data structures in airport security. Passengers are automatically prioritized based on their risk assessment scores, ensuring that high-risk individuals are screened first.

## Features

### Automated Risk Assessment
- Each passenger receives a risk score from automated security checks
- System automatically organizes passengers by priority
- Highest-risk passengers are always screened first

### Dynamic Queue Management
- Handles new passenger arrivals in real-time
- Automatically reorganizes queue when priorities change
- Efficiently removes passengers after screening

### Visual Representation
- Clear table view of current queue status
- Tree structure visualization for understanding relationships
- Priority screening order display

## Compilation

### Using GCC directly:

```bash
gcc -Wall -Wextra -std=c99 -o airport_security airport_security_main.c airport_security.c
./airport_security
```

### Using individual compilation:

```bash
gcc -Wall -Wextra -std=c99 -c airport_security.c
gcc -Wall -Wextra -std=c99 -c airport_security_main.c
gcc -Wall -Wextra -std=c99 -o airport_security airport_security_main.o airport_security.o
./airport_security
```

## System Operations

### 1. Queue Creation and Initial Organization
- Registers all arriving passengers
- Builds Max-Heap structure to organize by risk level
- Ensures highest-risk passenger is at the root

### 2. Priority Extraction
- Generates screening order from highest to lowest risk
- Maintains queue integrity during extraction
- Provides clear visualization of screening sequence

### 3. Dynamic Passenger Addition
- Handles new high-risk passenger arrivals
- Automatically inserts at correct priority position
- Preserves Max-Heap property through heapify-up operation

### 4. Passenger Removal
- Removes passengers after screening/clearance
- Reorganizes remaining passengers efficiently
- Maintains proper risk-based ordering through heapify-down

## Data Structures

### Passenger Structure

```c
typedef struct {
    char name[50];      // Passenger full name
    int riskScore;      // Risk assessment score (0-100)
} Passenger;
```

### Security Queue (Max-Heap)

```c
typedef struct {
    Passenger *passengers;  // Array of passengers
    int size;              // Current number of passengers
    int capacity;          // Maximum queue capacity
} SecurityQueue;
```

## Key Functions

| Function | Purpose | Time Complexity |
|----------|---------|----------------|
| `createSecurityQueue()` | Initialize new queue | O(1) |
| `buildSecurityQueue()` | Organize all passengers | O(n) |
| `addPassenger()` | Add new passenger | O(log n) |
| `screenNextPassenger()` | Remove highest priority | O(log n) |
| `heapifyUp()` | Maintain order after insert | O(log n) |
| `heapifyDown()` | Maintain order after removal | O(log n) |

## Example Scenario

**Initial Passengers:**
- Alice Johnson (Risk: 45)
- Brian Lee (Risk: 23)
- Chen Wei (Risk: 78)
- Fatima Abbas (Risk: 34)
- Noah Smith (Risk: 89)
- Sofia Garcia (Risk: 56)

**After Organization:**
- Highest Priority: Noah Smith (Risk: 89)
- Queue maintains Max-Heap property

**New Arrival:**
- David Martinez (Risk: 98)
- System automatically places him at highest priority

**After Clearance:**
- David Martinez removed
- Noah Smith returns to highest priority
- Queue reorganizes automatically

## Max-Heap Property

For every passenger at position i:
- Risk score at i ≥ Risk score at position 2i + 1 (left child)
- Risk score at i ≥ Risk score at position 2i + 2 (right child)

This ensures:
- Highest-risk passenger is always at root (position 0)
- Quick O(1) access to next passenger to screen
- Efficient O(log n) insertion and removal

## Use Cases

This implementation can be applied to:
- Emergency Room Triage - Prioritize patients by severity
- Task Scheduling - Handle high-priority jobs first
- Network Traffic - Route critical packets first
- Customer Support - Address urgent issues first
- Resource Allocation - Assign resources to critical needs

## Memory Management

- All memory is properly allocated and freed
- No memory leaks
- `createSecurityQueue()` allocates memory
- `freeSecurityQueue()` releases memory

## Advantages of This Approach

### Efficiency
- O(1) access to highest-priority passenger
- O(log n) insertion and removal
- O(n) initial organization

### Flexibility
- Handles dynamic arrivals
- Adapts to changing priorities
- Scales to any queue size

### Clarity
- Clear visual representation
- Easy to understand operations
- Real-world context makes sense

