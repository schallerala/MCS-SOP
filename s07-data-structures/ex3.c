#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Queue {
    struct Node * head;
    struct Node * tail;
};

void printLinkedlist(struct Node * p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void enqueue (struct Queue * q, struct Node * newTail) {
    if (q->tail) {
        q->tail->next = newTail;
    }
    // if we don't have a tail, we neither have a head, unless external
    // change
    else {
        q->head = newTail;
    }

    // If we allow enqueuing a tail with multiple nodes, then we have
    // to look for the deepst tail
    // -- Possible improvement? --
    q->tail = newTail;
}

void enqueue_value (struct Queue * q, int value) {
    struct Node * newNode = malloc(sizeof(newNode));
    newNode->data = value;
    enqueue(q, newNode);
}

struct Node * dequeue (struct Queue * q) {
    struct Node * head = q->head;

    if (head) {
        q->head = head->next;
        head->next = 0;
    }

    return head;
}

int main () {
    struct Queue * q = malloc(sizeof(q));
    enqueue_value(q, 2);
    enqueue_value(q, 5);
    enqueue_value(q, 10);

    printLinkedlist(q->head);

    struct Node * node = dequeue(q);
    printf("Dequeued element: %d (next: %p)\n", node->data, node->next);

    struct Node last = { 15, 0 };
    enqueue(q, &last);

    printLinkedlist(q->head);
}