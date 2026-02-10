#include <stdio.h>
#include <string.h>
#include "airport_security.h"

int main() {
    printf("\n");
    printf("SMART AIRPORT SECURITY CONTROL SYSTEM\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("Automated passenger risk assessment and screening\n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    // Initial passengers arriving at security checkpoint
    printf(" Initial Passengers Arriving at Security Checkpoint:\n");
    printf("───────────────────────────────────────────────────────\n");
    
    char *passengerNames[] = {"Alice Johnson", "Brian Lee", "Chen Wei", 
                              "Fatima Abbas", "Noah Smith", "Sofia Garcia"};
    int riskScores[] = {45, 23, 78, 34, 89, 56};
    int numPassengers = 6;
    
    for (int i = 0; i < numPassengers; i++) {
        printf("✓ %s - Risk Score: %d\n", passengerNames[i], riskScores[i]);
    }
    
    // Create security queue
    SecurityQueue *queue = createSecurityQueue(20);
    
    printf("\n\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("TASK 1 & 2: Building Security Queue\n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    printf("➤ Step 1: Registering all passengers in the system...\n");
    
    // Add all passengers to the queue first (not yet organized)
    for (int i = 0; i < numPassengers; i++) {
        strcpy(queue->passengers[queue->size].name, passengerNames[i]);
        queue->passengers[queue->size].riskScore = riskScores[i];
        queue->size++;
    }
    
    displayQueue(queue, "Initial Queue (Before Risk-Based Ordering):");
    
    printf("\n➤ Step 2: Organizing passengers by risk level...\n");
    printf("   (Building Max-Heap structure)\n");
    
    buildSecurityQueue(queue);
    
    displayQueue(queue, "Security Queue After Risk-Based Organization:");
    
    printf("\n➤ Queue Structure Visualization:\n");
    printf("   (Tree view - highest risk at top)\n\n");
    displayQueueAsTree(queue, 0, 0);
    
    printf("\n\n Understanding the Queue:\n");
    printf("   • %s has the highest risk score (%d) and is at the root\n", 
           queue->passengers[0].name, queue->passengers[0].riskScore);
    printf("   • Every parent has a higher or equal risk score than their children\n");
    printf("   • This ensures quick access to the highest-risk passenger\n");
    
    printf("\n\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("TASK 3: Priority Screening Order\n");
    printf("═══════════════════════════════════════════════════════\n");
    
    showScreeningOrder(queue);
    
    printf("\n\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("TASK 4: New High-Risk Passenger Arrival\n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    printf("ALERT: New passenger detected with high risk score!\n");
    printf("───────────────────────────────────────────────────────\n");
    printf("Passenger: David Martinez\n");
    printf("Risk Score: 98\n");
    printf("Status: Flagged for immediate screening\n\n");
    
    printf("➤ Adding David Martinez to the security queue...\n");
    
    addPassenger(queue, "David Martinez", 98);
    
    displayQueue(queue, "Updated Security Queue:");
    
    printf("\n➤ Updated Queue Structure:\n\n");
    displayQueueAsTree(queue, 0, 0);
    
    printf("\n\n What happened:\n");
    printf("   • David Martinez (Risk: 98) was added to the queue\n");
    printf("   • The system automatically moved him to position 0 (highest priority)\n");
    printf("   • Other passengers were reorganized to maintain proper ordering\n");
    printf("   • David will now be screened first\n");
    
    printf("\n➤ Updated Screening Order:\n");
    showScreeningOrder(queue);
    
    printf("\n\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("TASK 5: Passenger Cleared from High-Risk List\n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    printf("CLEARED: David Martinez has been screened and cleared\n");
    printf("───────────────────────────────────────────────────────\n");
    printf("Reason: False positive - no actual threat detected\n");
    printf("Action: Removing from security queue\n\n");
    
    printf("➤ Removing David Martinez from the queue...\n");
    
    Passenger removed = screenNextPassenger(queue);
    printf("   Removed: %s (Risk Score: %d)\n", removed.name, removed.riskScore);
    
    displayQueue(queue, "\nSecurity Queue After Removal:");
    
    printf("\n➤ Reorganized Queue Structure:\n\n");
    displayQueueAsTree(queue, 0, 0);
    
    printf("\n\n What happened:\n");
    printf("   • David Martinez was removed from the top of the queue\n");
    printf("   • The system automatically reorganized remaining passengers\n");
    printf("   • %s (Risk: %d) is now the highest priority\n", 
           queue->passengers[0].name, queue->passengers[0].riskScore);
    printf("   • The queue maintains proper risk-based ordering\n");
    
    printf("\n➤ Final Screening Order:\n");
    showScreeningOrder(queue);
    
    printf("\n\n");
    printf("═══════════════════════════════════════════════════════\n");
    printf("SYSTEM SUMMARY\n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    printf("✓ Successfully processed %d passengers\n", numPassengers);
    printf("✓ Handled 1 high-risk arrival (Risk: 98)\n");
    printf("✓ Cleared 1 false positive from queue\n");
    printf("✓ Current queue size: %d passengers\n", queue->size);
    printf("✓ System maintains optimal risk-based ordering\n\n");
    
    printf(" All operations completed successfully.\n");
    printf("   Security queue is ready for continuous operation.\n\n");
    
    // Clean up
    freeSecurityQueue(queue);
    
    return 0;
}
