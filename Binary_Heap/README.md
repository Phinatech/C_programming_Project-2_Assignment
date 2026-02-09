# Job Scheduler - Max-Heap Implementation

## Project Structure

```
job_scheduler/
├── max_heap.h          # Header file with structures and function declarations
├── max_heap.c          # Implementation of Max-Heap operations
├── main.c              # Main program with job scheduler logic
├── Makefile            # Build automation file
└── README.md           # This file
```

## File Descriptions

### 1. max_heap.h (Header File)

Contains:
- **Job** structure definition (jobID, priority)
- MaxHeap structure definition (array, size, capacity)
- Function prototypes for all heap operations

### 2. max_heap.c (Implementation File)

Contains all Max-Heap function implementations:
- `createMaxHeap()` - Create and initialize heap
- `heapifyUp()` - Maintain heap property after insertion
- `heapifyDown()` - Maintain heap property after deletion
- `insert()` - Insert new job into heap
- `extractMax()` - Remove and return highest priority job
- `buildMaxHeap()` - Convert array to Max-Heap
- `printHeap()` - Display heap as array
- `printHeapTree()` - Display heap as tree structure
- `freeHeap()` - Free allocated memory

### 3. main.c (Main Program)

Contains:
- Job scheduler logic
- Demonstration of all 4 tasks:
  - Build binary tree and convert to Max-Heap
  - Assign unique job identifiers
  - Insert urgent job (priority 100)
  - Remove urgent job (priority 100)
- Verification of heap properties after each operation

### 4. Makefile (Build Automation)

Automates compilation process with targets:
- `make` or `make all` - Compile the program
- `make run` - Compile and run the program
- `make clean` - Remove compiled files
- `make rebuild` - Clean and recompile


## Compilation Instructions

### Method 1: Using Makefile (Recommended)

```bash
# Compile the program
make

# Compile and run
make run

# Clean compiled files
make clean

# Rebuild from scratch
make rebuild
```

### Method 2: Manual Compilation

```bash
# Compile implementation file
gcc -Wall -Wextra -std=c99 -c max_heap.c

# Compile main file
gcc -Wall -Wextra -std=c99 -c main.c

# Link object files
gcc -Wall -Wextra -std=c99 -o job_scheduler main.o max_heap.o

# Run
./job_scheduler
```

### Method 3: Single Command

```bash
gcc -Wall -Wextra -std=c99 -o job_scheduler main.c max_heap.c
./job_scheduler
```

## Program Output

The program demonstrates:
- Initial binary tree construction
- Conversion to Max-Heap with verification
- Insertion of Job L (priority 100) with heapify-up
- Deletion of Job L (priority 100) with heapify-down
- Tree and array visualization after each operation


## Assignment Requirements Compliance

- ✅ **Implementation in C** - All code in C
- ✅ **Array-based heap** - Uses array for internal storage
- ✅ **Proper heapify operations** - Both heapify-up and heapify-down implemented
- ✅ **Heap structure displayed** - Tree visualization after each operation
- ✅ **Task 1** - Binary tree built and converted to Max-Heap
- ✅ **Task 2** - Unique job IDs assigned (A-K, L)
- ✅ **Task 3** - Insertion of priority 100 with heapify-up
- ✅ **Task 4** - Deletion of priority 100 with heapify-down

## Example Usage in Other Projects

```c
// In another project file
#include "max_heap.h"

int main() {
    // Create a heap for any priority-based system
    MaxHeap *taskQueue = createMaxHeap(100);
    
    // Use all heap operations
    insert(taskQueue, 'X', 95);
    insert(taskQueue, 'Y', 80);
    
    Job highPriority = extractMax(taskQueue);
    
    freeHeap(taskQueue);
    return 0;
}
```

## Memory Management

All memory is properly managed:
- `createMaxHeap()` allocates memory
- `freeHeap()` deallocates memory
- No memory leaks


## Verification

Run the program to verify all requirements:

```bash
make run
```

Expected output includes:
- ✓ Valid Max-Heap after build
- ✓ Valid Max-Heap after insertion
- ✓ Valid Max-Heap after deletion
- ✓ All parent-child relationships verified


## Author Notes

This implementation demonstrates professional C programming practices:
- Clear separation of concerns
- Modular design
- Comprehensive documentation
- Build automation
- Memory safety