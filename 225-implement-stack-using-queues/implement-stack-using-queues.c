#include <stdlib.h>
#include <stdbool.h>

#define SIZE 101

typedef struct {
    int data[SIZE];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % SIZE;
    q->size++;
}

int dequeue(Queue* q) {
    int x = q->data[q->front];
    q->front = (q->front + 1) % SIZE;
    q->size--;
    return x;
}

int peekQueue(Queue* q) {
    return q->data[q->front];
}

MyStack* myStackCreate() {
    MyStack* obj = malloc(sizeof(MyStack));
    initQueue(&obj->q1);
    initQueue(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);

    while (!isQueueEmpty(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    if (isQueueEmpty(&obj->q1)) {
        return -1;
    }
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    if (isQueueEmpty(&obj->q1)) {
        return -1;
    }
    return peekQueue(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}