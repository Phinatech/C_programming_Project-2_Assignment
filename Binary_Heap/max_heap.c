#include <stdio.h>
#include <stdlib.h>
#include "max_heap.h"

// Create a new Max-Heap
MaxHeap* createMaxHeap(int capacity) {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Job*)malloc(capacity * sizeof(Job));
    return heap;
}

// Swap two jobs
void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (used after insertion)
void heapifyUp(MaxHeap *heap, int index) {
    if (index == 0) return;
    
    int parent = (index - 1) / 2;
    
    if (heap->array[index].priority > heap->array[parent].priority) {
        swap(&heap->array[index], &heap->array[parent]);
        heapifyUp(heap, parent);
    }
}

// Heapify down (used after deletion)
void heapifyDown(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < heap->size && heap->array[left].priority > heap->array[largest].priority) {
        largest = left;
    }
    
    if (right < heap->size && heap->array[right].priority > heap->array[largest].priority) {
        largest = right;
    }
    
    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapifyDown(heap, largest);
    }
}

// Insert a job into the heap
void insert(MaxHeap *heap, char jobID, int priority) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }
    
    // Insert at the end
    heap->array[heap->size].jobID = jobID;
    heap->array[heap->size].priority = priority;
    
    // Heapify up to maintain Max-Heap property
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract the maximum element (root)
Job extractMax(MaxHeap *heap) {
    Job max = heap->array[0];
    
    // Move last element to root
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    
    // Heapify down to maintain Max-Heap property
    heapifyDown(heap, 0);
    
    return max;
}

// Build Max-Heap from existing array
void buildMaxHeap(MaxHeap *heap) {
    // Start from the last non-leaf node and heapify down
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
}

// Print heap as array
void printHeap(MaxHeap *heap, const char *message) {
    printf("\n%s\n", message);
    printf("========================================\n");
    printf("Array representation:\n");
    printf("Index: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%3d ", i);
    }
    printf("\nJob:   ");
    for (int i = 0; i < heap->size; i++) {
        printf("%3c ", heap->array[i].jobID);
    }
    printf("\nPrio:  ");
    for (int i = 0; i < heap->size; i++) {
        printf("%3d ", heap->array[i].priority);
    }
    printf("\n");
}

// Print heap as tree structure
void printHeapTree(MaxHeap *heap, int index, int level) {
    if (index >= heap->size) return;
    
    // Print right subtree
    printHeapTree(heap, 2 * index + 2, level + 1);
    
    // Print current node
    for (int i = 0; i < level; i++) {
        printf("        ");
    }
    printf("[%c:%d]\n", heap->array[index].jobID, heap->array[index].priority);
    
    // Print left subtree
    printHeapTree(heap, 2 * index + 1, level + 1);
}

// Free heap memory
void freeHeap(MaxHeap *heap) {
    free(heap->array);
    free(heap);
}
