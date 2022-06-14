#include <stdlib.h>
#include <string.h>

typedef struct node {
    void *data;
    int priority;
    struct node * next;
} Node;

typedef struct priority_queue {
    size_t element_size;
    Node *head;
    Node *tail;
} PriorityQueue;

static Node * create_node(const void* element, const int priority, size_t size) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->data = malloc(size);
    if (node->data == NULL) {free(node); return NULL;};
    memcpy(node->data, element, size);
    node->priority = priority;
    return node;
}

int push(PriorityQueue *queue, const void* element, const int priority) {
    if (queue == NULL) return 1;

    Node *node = create_node(element, priority, queue->element_size);

    // Traverse queue until priority lower than new element
    Node *walk = queue->head, *prev = NULL;
    while (walk != NULL && walk->priority >= node->priority) {
        prev = walk;
        walk = walk->next;
    };

    // Insert new element in the queue at the right position
    if (queue->tail == NULL) // Priority queue empty
        queue->head = queue->tail = node;
    else if (walk == NULL) // At the end of the queue
        queue->tail = queue->tail->next = node;
    else if (prev != NULL) { // Somewhere in the middle
        node->next = prev->next;
        prev->next = node;
    }
    else { // Front
        node->next = queue->head;
        queue->head = node;
    }
    return 0;
}

int front(PriorityQueue *queue, void *element) {
    if (queue == NULL) return 1;
    if (queue->head == NULL) return 2;
    memcpy(element, queue->head->data, queue->element_size);
    return 0;
}

int pop(PriorityQueue *queue, void *element) {
    if (front(queue, element)) return 1;
    Node *node = queue->head;
    queue->head = queue->head->next;
    free(node->data);
    free(node);
    return 0;
}

int traverse(PriorityQueue *queue, void (*cb)(void *element)) {
    if (queue == NULL) return 1;
    Node *walk = queue->head;
    while (walk != NULL) {
        cb(walk->data);
        walk = walk->next;
    }
    return 0;
}

PriorityQueue *init(int element_size) {
    PriorityQueue *queue = calloc(sizeof(PriorityQueue), 1);
    if (queue != NULL) queue->element_size = element_size;
    return queue;
}