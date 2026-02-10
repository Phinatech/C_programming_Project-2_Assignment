#include <stdio.h>
#include <ctype.h>

#define N 7

/* ---------- Helper: node letter <-> index ---------- */
int node_to_index(char node) {
    node = (char)toupper((unsigned char)node);
    if (node < 'A' || node > 'G') return -1;
    return node - 'A';
}

char index_to_node(int idx) {
    return (char)('A' + idx);
}

/* ---------- Simple Queue for BFS ---------- */
typedef struct {
    int data[N];
    int front;
    int back;
} Queue;

void q_init(Queue *q) {
    q->front = 0;
    q->back = 0;
}

int q_empty(Queue *q) {
    return q->front == q->back;
}

void q_push(Queue *q, int x) {
    if (q->back < N) {
        q->data[q->back++] = x;
    }
}

int q_pop(Queue *q) {
    return q->data[q->front++];
}

/* ---------- Graph utility (undirected) ---------- */
void add_edge(int g[N][N], int u, int v, int w) {
    if (w > 0) {                 /* only add if positive weight */
        g[u][v] = w;
        g[v][u] = w;
    }
}

void bfs_one_hop_and_highest_risk(int g[N][N], int start) {
    int visited[N] = {0};
    Queue q;

    q_init(&q);
    visited[start] = 1;
    q_push(&q, start);

    printf("\n--------------------------------------------\n");
    printf("Suspected compromised workstation: %c\n", index_to_node(start));
    printf("Running BFS to discover ONE-HOP neighbors...\n");
    printf("--------------------------------------------\n");

    int bestNeighbor = -1;
    int bestWeight = -1;

    while (!q_empty(&q)) {
        int u = q_pop(&q);

        /* We only process neighbors of the start node for this task */
        if (u != start) break;

        for (int v = 0; v < N; v++) {
            if (g[u][v] > 0 && !visited[v]) {
                visited[v] = 1;
                q_push(&q, v); /* BFS discovery step (level 1) */

                printf("Direct peer found: %c <--> %c  | transfer time = %d mins\n",
                       index_to_node(u), index_to_node(v), g[u][v]);

                if (g[u][v] > bestWeight) {
                    bestWeight = g[u][v];
                    bestNeighbor = v;
                }
            }
        }
    }

    if (bestNeighbor == -1) {
        printf("\nNo direct peers found for workstation %c.\n", index_to_node(start));
    } else {
        printf("\n✅ Highest-risk direct peer: %c  (%d mins)\n",
               index_to_node(bestNeighbor), bestWeight);
    }
}

/* ---------- Main ---------- */
int main(void) {
    int g[N][N] = {0};

    /* Known edges from the diagram */
    add_edge(g, node_to_index('A'), node_to_index('B'), 6);
    add_edge(g, node_to_index('B'), node_to_index('D'), 5);
    add_edge(g, node_to_index('B'), node_to_index('C'), 11);
    add_edge(g, node_to_index('C'), node_to_index('D'), 17);
    add_edge(g, node_to_index('C'), node_to_index('G'), 25);
    add_edge(g, node_to_index('D'), node_to_index('E'), 22);
    add_edge(g, node_to_index('E'), node_to_index('F'), 10);
    add_edge(g, node_to_index('F'), node_to_index('G'), 22);

    /* Ask user for the missing weights (rubric-safe) */
    int wAD, wDF;
    printf("Enter missing edge weight for A-D (minutes). Enter 0 if no edge: ");
    if (scanf("%d", &wAD) != 1) {
        printf("Input error.\n");
        return 1;
    }
    printf("Enter missing edge weight for D-F (minutes). Enter 0 if no edge: ");
    if (scanf("%d", &wDF) != 1) {
        printf("Input error.\n");
        return 1;
    }
    add_edge(g, node_to_index('A'), node_to_index('D'), wAD);
    add_edge(g, node_to_index('D'), node_to_index('F'), wDF);

    /* 1) Accept suspected workstation input */
    char input;
    printf("\nEnter suspected compromised workstation (A-G): ");
    if (scanf(" %c", &input) != 1) {
        printf("Input error.\n");
        return 1;
    }

    int start = node_to_index(input);
    if (start == -1) {
        printf("Invalid workstation. Please enter a letter between A and G.\n");
        return 1;
    }

    /* 2 & 3) BFS one-hop discovery + highest risk */
    bfs_one_hop_and_highest_risk(g, start);

    return 0;
}


