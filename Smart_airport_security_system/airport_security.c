#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airport_security.h"

// Create a new security queue (Max-Heap)
SecurityQueue* createSecurityQueue(int capacity) {
    SecurityQueue *queue = (SecurityQueue*)malloc(sizeof(SecurityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->passengers = (Passenger*)malloc(capacity * sizeof(Passenger));
    return queue;
}

// Swap two passengers in the queue
void swap(Passenger *a, Passenger *b) {
    Passenger temp = *a;
    *a = *b;
    *b = temp;
}

// Move a passenger up the queue if their risk is higher (heapify up)
void heapifyUp(SecurityQueue *queue, int index) {
    if (index == 0) return;  // Already at the front of the queue
    
    int parent = (index - 1) / 2;
    
    // If this passenger has higher risk than their parent, move them up
    if (queue->passengers[index].riskScore > queue->passengers[parent].riskScore) {
        swap(&queue->passengers[index], &queue->passengers[parent]);
        heapifyUp(queue, parent);
    }
}

// Move a passenger down the queue to maintain proper ordering (heapify down)
void heapifyDown(SecurityQueue *queue, int index) {
    int highest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    // Check if left passenger has higher risk
    if (left < queue->size && 
        queue->passengers[left].riskScore > queue->passengers[highest].riskScore) {
        highest = left;
    }
    
    // Check if right passenger has higher risk
    if (right < queue->size && 
        queue->passengers[right].riskScore > queue->passengers[highest].riskScore) {
        highest = right;
    }
    
    // If a passenger with higher risk was found, swap and continue
    if (highest != index) {
        swap(&queue->passengers[index], &queue->passengers[highest]);
        heapifyDown(queue, highest);
    }
}

// Add a new passenger to the security queue
void addPassenger(SecurityQueue *queue, const char *name, int riskScore) {
    if (queue->size == queue->capacity) {
        printf("⚠️  Security queue is full! Cannot add more passengers.\n");
        return;
    }
    
    // Add passenger at the end of the queue
    strcpy(queue->passengers[queue->size].name, name);
    queue->passengers[queue->size].riskScore = riskScore;
    
    // Move them to their correct position based on risk
    heapifyUp(queue, queue->size);
    queue->size++;
}

// Screen the next highest-risk passenger
Passenger screenNextPassenger(SecurityQueue *queue) {
    Passenger nextPassenger = queue->passengers[0];
    
    // Move the last passenger to the front
    queue->passengers[0] = queue->passengers[queue->size - 1];
    queue->size--;
    
    // Reorganize the queue to maintain proper order
    heapifyDown(queue, 0);
    
    return nextPassenger;
}

// Organize all passengers in the queue by risk level
void buildSecurityQueue(SecurityQueue *queue) {
    // Start from the middle and work backwards to organize everyone
    for (int i = (queue->size / 2) - 1; i >= 0; i--) {
        heapifyDown(queue, i);
    }
}

// Display the current security queue
void displayQueue(SecurityQueue *queue, const char *message) {
    printf("\n%s\n", message);
    printf("═══════════════════════════════════════════════════════\n");
    
    if (queue->size == 0) {
        printf("Queue is empty - no passengers waiting for screening.\n");
        return;
    }
    
    printf("Position | Passenger Name      | Risk Score\n");
    printf("---------+---------------------+-----------\n");
    for (int i = 0; i < queue->size; i++) {
        printf("   %-6d| %-20s| %d\n", 
               i, 
               queue->passengers[i].name, 
               queue->passengers[i].riskScore);
    }
    printf("═══════════════════════════════════════════════════════\n");
}

// Show the queue structure as a tree
void displayQueueAsTree(SecurityQueue *queue, int index, int level) {
    if (index >= queue->size) return;
    
    // Show right branch first (appears at top when printed)
    displayQueueAsTree(queue, 2 * index + 2, level + 1);
    
    // Print current passenger with proper indentation
    for (int i = 0; i < level; i++) {
        printf("          ");
    }
    printf("┌─ %s (Risk: %d)\n", 
           queue->passengers[index].name, 
           queue->passengers[index].riskScore);
    
    // Show left branch
    displayQueueAsTree(queue, 2 * index + 1, level + 1);
}

// Display the complete screening order
void showScreeningOrder(SecurityQueue *queue) {
    if (queue->size == 0) {
        printf("\nNo passengers in queue.\n");
        return;
    }
    
    printf("\n📋 SCREENING ORDER (Highest Risk First):\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    // Create a temporary copy so we don't modify the original queue
    SecurityQueue *tempQueue = createSecurityQueue(queue->capacity);
    for (int i = 0; i < queue->size; i++) {
        tempQueue->passengers[i] = queue->passengers[i];
        tempQueue->size++;
    }
    
    int order = 1;
    while (tempQueue->size > 0) {
        Passenger next = screenNextPassenger(tempQueue);
        printf("%d. %-20s (Risk Score: %d)\n", order++, next.name, next.riskScore);
    }
    
    printf("═══════════════════════════════════════════════════════\n");
    
    freeSecurityQueue(tempQueue);
}

// Clean up memory
void freeSecurityQueue(SecurityQueue *queue) {
    free(queue->passengers);
    free(queue);
}
