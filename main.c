#include "priority-queue.h"
#include <stdio.h>

typedef struct point {
    float x;
    float y;
} Point;

void display_element(void *element) {
    Point *p = (Point*)element;
    printf("(%g,%g)\n", p->x, p->y);
}

int main() {
    PriorityQueue *queue = init(sizeof(Point));
    push(queue, &(Point){.x = 4, .y = 4}, 4);
    push(queue, &(Point){.x = 3, .y = 3}, 3);
    push(queue, &(Point){.x = 5, .y = 5}, 5);
    push(queue, &(Point){.x = 1, .y = 1}, 1);
    push(queue, &(Point){.x = 2, .y = 2}, 2);

    traverse(queue, display_element);

    printf("---\n");

    Point p;
    pop(queue, &p); display_element(&p);
    pop(queue, &p); display_element(&p);
    pop(queue, &p); display_element(&p);

    printf("---\n");
    traverse(queue, display_element);
}