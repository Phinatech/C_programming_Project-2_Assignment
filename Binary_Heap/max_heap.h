

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// Structure to represent a job
typedef struct {
    char jobID;
    int priority;
} Job;

// Structure to represent the Max-Heap
typedef struct {
    Job *array;
    int size;
    int capacity;
} MaxHeap;

// Function prototypes
MaxHeap* createMaxHeap(int capacity);
void swap(Job *a, Job *b);
void heapifyUp(MaxHeap *heap, int index);
void heapifyDown(MaxHeap *heap, int index);
void insert(MaxHeap *heap, char jobID, int priority);
Job extractMax(MaxHeap *heap);
void printHeap(MaxHeap *heap, const char *message);
void printHeapTree(MaxHeap *heap, int index, int level);
void buildMaxHeap(MaxHeap *heap);
void freeHeap(MaxHeap *heap);

#endif // MAX_HEAP_H
