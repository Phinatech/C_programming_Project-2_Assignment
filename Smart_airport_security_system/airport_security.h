#ifndef AIRPORT_SECURITY_H
#define AIRPORT_SECURITY_H

// Structure to represent a passenger
typedef struct {
    char name[50];
    int riskScore;
} Passenger;

// Structure to represent the Max-Heap for security screening
typedef struct {
    Passenger *passengers;
    int size;
    int capacity;
} SecurityQueue;

// Function declarations
SecurityQueue* createSecurityQueue(int capacity);
void swap(Passenger *a, Passenger *b);
void heapifyUp(SecurityQueue *queue, int index);
void heapifyDown(SecurityQueue *queue, int index);
void addPassenger(SecurityQueue *queue, const char *name, int riskScore);
Passenger screenNextPassenger(SecurityQueue *queue);
void buildSecurityQueue(SecurityQueue *queue);
void displayQueue(SecurityQueue *queue, const char *message);
void displayQueueAsTree(SecurityQueue *queue, int index, int level);
void showScreeningOrder(SecurityQueue *queue);
void freeSecurityQueue(SecurityQueue *queue);

#endif // AIRPORT_SECURITY_H
