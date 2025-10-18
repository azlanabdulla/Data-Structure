#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define Max 100
#define AC 10
#define BC 7
#define CC 4

struct state {
    int a, b, c;
};

struct Queue {
    struct state states[Max];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = 0;
}

bool isEmpty(struct Queue *q) {
    return q->front == q->rear;
}

void enqueue(struct Queue *q, struct state s) {
    if (q->rear < Max) {
        q->states[q->rear++] = s;
    }
}

struct state dequeue(struct Queue *q) {
    return q->states[q->front++];
}

bool visited[11][8][5];

struct state pour(struct state s, int from, int to) {
    struct state newstate = s;
    int *src, *dst;
    int srcCap, dstCap;

    if (from == 0) { src = &newstate.a; srcCap = AC; }
    else if (from == 1) { src = &newstate.b; srcCap = BC; }
    else { src = &newstate.c; srcCap = CC; }

    if (to == 0) { dst = &newstate.a; dstCap = AC; }
    else if (to == 1) { dst = &newstate.b; dstCap = BC; }
    else { dst = &newstate.c; dstCap = CC; }

    int amount = (*src < (dstCap - *dst)) ? *src : (dstCap - *dst);
    *src -= amount;
    *dst += amount;

    return newstate;
}

void printState(struct state s) {
    printf("(%d, %d, %d)\n", s.a, s.b, s.c);
}

int main() {
    struct Queue q;
    initQueue(&q);

    for (int i = 0; i <= AC; i++)
        for (int j = 0; j <= BC; j++)
            for (int k = 0; k <= CC; k++)
                visited[i][j][k] = false;

    struct state start = {0, 7, 4};
    enqueue(&q, start);
    visited[start.a][start.b][start.c] = true;

    printf("Exploring States:\n");
    printState(start);

    while (!isEmpty(&q)) {
        struct state cur = dequeue(&q);

        if (cur.a == 2 || cur.b == 2 || cur.c == 2) {
            printf("\nGoal Reached: A=%d, B=%d, C=%d\n", cur.a, cur.b, cur.c);
            return 0;
        }

        
        for (int from = 0; from < 3; from++) {
            for (int to = 0; to < 3; to++) {
                if (from != to) {
                    struct state next = pour(cur, from, to);
                    if (!visited[next.a][next.b][next.c]) {
                        visited[next.a][next.b][next.c] = true;
                        enqueue(&q, next);
                        printState(next); 
                    }
                }
            }
        }
    }

    printf("\nNo Solution Found\n");
    return 0;
}