// Question2/Student.c
// ------------------------------------------------------------
// CS Lab - Design Circular Queue (RING BUFFER / QUEUE PRACTICE)
//
// Task:
// Implement the circular queue functions declared in Student.h.
//
// You are designing a fixed-size queue with capacity k.
// The queue supports enqueue/dequeue in O(1) time using a circular array.
//
// Recommended invariants (simple + robust):
// - Use an integer `size` to track how many elements are currently stored.
// - Queue is empty  <=> size == 0
// - Queue is full   <=> size == capacity
// - `head` points to the current front element
// - `tail` points to the next insertion position
// - Wrap indices using modulo: (idx + 1) % capacity
//
// Examples (k = 3):
//   enQueue(1) -> true    queue: [1]
//   enQueue(2) -> true    queue: [1,2]
//   enQueue(3) -> true    queue: [1,2,3]
//   enQueue(4) -> false   (full)
//   Rear()     -> 3
//   isFull()   -> true
//   deQueue()  -> true    queue: [2,3]
//   enQueue(4) -> true    queue: [2,3,4]
//   Rear()     -> 4
//   Front()    -> 2
//
// Return values rules:
// - Front / Rear should return -1 if the queue is empty.
//
// How to run tests (from the folder containing the Makefile):
//   make run2
// ------------------------------------------------------------

#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!q) 
        return NULL;
    
    q->data = (int*)malloc(k*sizeof(int));
    q->capacity = k;
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL)
        return false;
    if (myCircularQueueIsFull(obj))
        return false;
    else
    {
        obj->size+=1;
        obj->data[obj->tail] = value;
        obj->tail = (obj->tail+1)%obj->capacity;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL)
        return false;
    if (myCircularQueueIsEmpty(obj))
        return false;
    else
    {
        obj->size-=1;
        obj->head = (obj->head+1)%obj->capacity;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj == NULL)
        return -1;
    if(myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj == NULL)
        return -1;
    if(myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[(obj->tail+(obj->capacity-1))%obj->capacity];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj == NULL)
        return true;
    if (obj->size == 0)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj == NULL)
        return false;
    if (obj->size == obj->capacity)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(!obj) 
        return;
    free(obj->data);
    free(obj);
}
