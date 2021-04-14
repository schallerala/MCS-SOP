#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

void swap_ptr(struct node * head) {
    int headData = head->data;
    int nextData = head->next->data;

    head->data = nextData;
    head->next->data = headData;
}

void printLinkedlist(struct node * p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main () {
    struct node first = {1, 0};
    struct node second = {2, &first};
    struct node third = {3, &second};

    printLinkedlist(&third);

    swap_ptr(&third);

    printLinkedlist(&third);
}