#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct CircularQueue {
    int arr[SIZE];
    int front;
    int rear;
};

struct CircularQueue cq;

void Enqueue(int item) {
    int next;
    if (cq.front == -1 && cq.rear == -1) {
        cq.front = cq.rear = 0;
        cq.arr[cq.rear] = item;
        printf("Inserted %d into the queue.\n", item);
        printf("Queue contents:");
        for (int i = cq.front; i <= cq.rear; i++) {
            printf(" %d", cq.arr[i]);
        }
        printf("\n");
        return;
    }
    next = (cq.rear + 1) % SIZE;
    if (next == cq.front) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        printf("Queue contents:");
        for (int i = cq.front; ; i = (i + 1) % SIZE) {
            printf(" %d", cq.arr[i]);
            if (i == cq.rear) break;
        }
        printf("\n");
        return;
    }
    cq.rear = next;
    cq.arr[cq.rear] = item;
    printf("Inserted %d into the queue.\n", item);
    printf("Queue contents:");
    for (int i = cq.front; ; i = (i + 1) % SIZE) {
        printf(" %d", cq.arr[i]);
        if (i == cq.rear) break;
    }
    printf("\n");
}

void Dequeue() {
    if (cq.front == -1 && cq.rear == -1) {
        printf("Queue Underflow! No elements to delete.\n");
        printf("Queue contents:\n");
        return;
    }
    if (cq.front == cq.rear) {
        printf("Deleted %d from the queue.\n", cq.arr[cq.front]);
        cq.front = cq.rear = -1;
        printf("Queue contents:\n");
        return;
    }
    printf("Deleted %d from the queue.\n", cq.arr[cq.front]);
    cq.front = (cq.front + 1) % SIZE;
    printf("Queue contents:");
    for (int i = cq.front; ; i = (i + 1) % SIZE) {
        printf(" %d", cq.arr[i]);
        if (i == cq.rear) break;
    }
    printf("\n");
}

void Display() {
    if (cq.front == -1 && cq.rear == -1) {
        printf("Queue contents:\n");
        return;
    }
    printf("Queue contents:");
    for (int i = cq.front; ; i = (i + 1) % SIZE) {
        printf(" %d", cq.arr[i]);
        if (i == cq.rear) break;
    }
    printf("\n");
}

int main() {
    int n, op, value;
    cq.front = cq.rear = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &value);
            Enqueue(value);
        } else if (op == 2) {
            Dequeue();
        } else if (op == 3) {
            Display();
        }
    }
    return 0;
}
