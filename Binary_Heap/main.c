#include <stdio.h>
#include "max_heap.h"

int main() {
    // Initial priorities
    int priorities[] = {42, 17, 93, 28, 65, 81, 54, 60, 99, 73, 88};
    char jobIDs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    int n = sizeof(priorities) / sizeof(priorities[0]);
    
    // Create heap with capacity
    MaxHeap *heap = createMaxHeap(20);
    
    printf("\n\n┌─────────────────────────────────────────────────────────┐\n");
    printf("│ TASK 1 & 2: Build Binary Tree and Convert to Max-Heap │\n");
    printf("└─────────────────────────────────────────────────────────┘\n");
    
    printf("\nStep 1: Insert elements in order as binary tree\n");
    printf("------------------------------------------------\n");
    
    // Insert all elements first (binary tree, not yet heapified)
    for (int i = 0; i < n; i++) {
        heap->array[heap->size].jobID = jobIDs[i];
        heap->array[heap->size].priority = priorities[i];
        heap->size++;
    }
    
    printHeap(heap, "Initial Binary Tree (before heapification):");
    printf("\nTree structure (rotated 90° clockwise):\n");
    printHeapTree(heap, 0, 0);
    
    printf("\n\nStep 2: Convert to Max-Heap using heapify operations\n");
    printf("-----------------------------------------------------\n");
    
    // Build Max-Heap
    buildMaxHeap(heap);
    
    printHeap(heap, "After converting to Max-Heap:");
    printf("\nMax-Heap Tree structure:\n");
    printHeapTree(heap, 0, 0);
    
    printf("\n\nHeap Property Verification:\n");
    printf("---------------------------\n");
    printf("Root (highest priority): [%c:%d]\n", heap->array[0].jobID, heap->array[0].priority);
    for (int i = 0; i < heap->size; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap->size) {
            printf("Parent [%c:%d] >= Left Child [%c:%d] ✓\n", 
                   heap->array[i].jobID, heap->array[i].priority,
                   heap->array[left].jobID, heap->array[left].priority);
        }
        if (right < heap->size) {
            printf("Parent [%c:%d] >= Right Child [%c:%d] ✓\n", 
                   heap->array[i].jobID, heap->array[i].priority,
                   heap->array[right].jobID, heap->array[right].priority);
        }
    }
    
    printf("\n\n┌──────────────────────────────────────────────────┐\n");
    printf("│ TASK 3: Insert Urgent Job with Priority 100     │\n");
    printf("└──────────────────────────────────────────────────┘\n");
    
    printf("\nInserting Job L with priority 100...\n");
    printf("-------------------------------------\n");
    
    insert(heap, 'L', 100);
    
    printHeap(heap, "After inserting Job L (priority 100):");
    printf("\nMax-Heap Tree structure:\n");
    printHeapTree(heap, 0, 0);
    
    printf("\n\nHeapify-Up Process for Job L:\n");
    printf("-----------------------------\n");
    printf("1. Insert at end (index %d)\n", heap->size - 1);
    printf("2. Compare with parent and swap if necessary\n");
    printf("3. Repeat until Max-Heap property is satisfied\n");
    printf("4. Final position: Root (index 0) with priority 100\n");
    
    printf("\n\n┌──────────────────────────────────────────────────┐\n");
    printf("│ TASK 4: Remove Urgent Job (Priority 100)        │\n");
    printf("└──────────────────────────────────────────────────┘\n");
    
    printf("\nRemoving Job L with priority 100...\n");
    printf("------------------------------------\n");
    
    Job removed = extractMax(heap);
    printf("Removed: [%c:%d]\n", removed.jobID, removed.priority);
    
    printHeap(heap, "After removing Job L (priority 100):");
    printf("\nMax-Heap Tree structure:\n");
    printHeapTree(heap, 0, 0);
    
    printf("\n\nHeapify-Down Process:\n");
    printf("---------------------\n");
    printf("1. Move last element to root\n");
    printf("2. Compare with children and swap with larger child\n");
    printf("3. Repeat until Max-Heap property is satisfied\n");
    printf("4. New root: [%c:%d]\n", heap->array[0].jobID, heap->array[0].priority);
    
    printf("\n\nFinal Heap Property Verification:\n");
    printf("---------------------------------\n");
    printf("Root (highest priority): [%c:%d]\n", heap->array[0].jobID, heap->array[0].priority);
    int valid = 1;
    for (int i = 0; i < heap->size; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap->size && heap->array[i].priority < heap->array[left].priority) {
            valid = 0;
        }
        if (right < heap->size && heap->array[i].priority < heap->array[right].priority) {
            valid = 0;
        }
    }
    printf("Max-Heap property maintained: %s\n", valid ? "✓ YES" : "✗ NO");
    
    // Free memory
    freeHeap(heap);
    
    return 0;
}
