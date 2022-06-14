#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct node Node;
typedef struct priority_queue PriorityQueue;

/**
 * Insert an element in the priority queue.
 * @param queue Existing priority queue
 * @param element Data pointer to an existing element
 * @return 0 if no errors
 */
int push(PriorityQueue *queue, const void* element, const int priority);

/**
 * Return a copy of the most important element of the queue.
 * @param queue Existing priority queue
 * @param element Location for the copy of the element, must be allocated
 * @return 0 if no errors
 */
int front(PriorityQueue *queue, void *element);

/**
 * Return a copy of the most important element of the queue and
 * remove it from the queue.
 * @param queue Existing priority queue
 * @param element Location for the copy of the element, must be allocated
 * @return 0 if no errors
 */
int pop(PriorityQueue *queue, void *element);

/**
 * Traverse the whole queue and call cb for each element.
 * @param queue Existing priority queue
 * @param cb Callback function that receives a pointer to an element
 * @return 0 if no errors
 */
int traverse(PriorityQueue *queue, void (*cb)(void *element));

/**
 * Initialize a priority queue
 * @param element_size Size in bytes of an element to store in the queue
 * @return A pointer to a heap allocated new priority queue
 */
PriorityQueue *init(int element_size);