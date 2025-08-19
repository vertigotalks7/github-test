#define SIZE 5
#include <stdio.h>

struct Queue {
    int arr[SIZE];
    int front;
    int rear;
};

struct Queue q;

void displayQueue() {
    if (q.front == -1) {
        printf("Queue contents:\n");
    } else {
        printf("Queue contents: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

void enqueue(int item) {
    if (q.rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d.\n", item);
    } else {
        if (q.front == -1) q.front = 0;
        q.rear++;
        q.arr[q.rear] = item;
        printf("Inserted %d into the queue.\n", item);
    }
    displayQueue();
}

void dequeue() {
    if (q.front == -1) {
        printf("Queue Underflow! No elements.\n");
    } else {
        int deleted = q.arr[q.front];
        if (q.front == q.rear) {
            q.front = q.rear = -1;
        } else {
            q.front++;
        }
        printf("Deleted %d from the queue.\n", deleted);
    }
    displayQueue();
}

int main() {
    q.front = q.rear = -1;
    int operations;
    scanf("%d", &operations);

    for (int i = 0; i < operations; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int value;
            scanf("%d", &value);
            enqueue(value);
        } else if (op == 2) {
            dequeue();
        } else if (op == 3) {
            displayQueue();
        } else {
            printf("Invalid operation.\n");
        }
    }

    return 0;
}
