#include <stdio.h>
#include <stdlib.h>

/**
 * Express a directed graph
 */

// 1. modifiy the struct
struct LinkedNode {
    struct GraphNode * target;
    struct LinkedNode * next;
};

struct GraphNode {
    int data;
    struct LinkedNode * directed_relations;
};

// 2. modifiy the newNode function
struct GraphNode * new_graph_node (int data) {
    struct GraphNode * newNode = malloc(sizeof(newNode));
    newNode->data = data;
    newNode->directed_relations = 0;
    return newNode;
}

struct LinkedNode * new_linked_node (struct GraphNode * g) {
    struct LinkedNode * newNode = malloc(sizeof(newNode));
    newNode->target = g;
    newNode->next = 0;
    return newNode;
}

// 3. add function connect:
//      allows to connect two arbitrary nodes in your graph
void connect (struct GraphNode * source, struct GraphNode * target) {
    // should maybe also check if the target is not in the directed_relations list
    struct LinkedNode * last_relation = source->directed_relations;
    struct LinkedNode * new_relation_target = new_linked_node(target);
    if (last_relation) {
        while (last_relation->next) {
            last_relation = last_relation->next;
        }

        last_relation->next = new_relation_target;
    }
    // no directed_relations yet
    else {
        source->directed_relations = new_relation_target;
    }
}

void print_relations (struct GraphNode * node) {
    int data = node->data;
    printf("%d", data);
    if ( ! node->directed_relations) {
        // has no directed relation
        printf(" has no directed relations\n");
    }

    struct LinkedNode * r = node->directed_relations;
    printf(" relations:");
    while (r) {
        printf(" %d", r->target->data);
        r = r->next;
    }
    printf("\n");
}

/*
 * Example graph to build:
 *
 *              5
 *            / |
 *           /  |
 *          /   |
 *         v    v
 *         2-+  1  +-->4
 *         \ +--+--+ / ^
 *          \   |   / /
 *           \  |  / /
 *            \ | / /
 *             vvv /
 *              3
 */

int main () {
    struct GraphNode * top = new_graph_node(5);
    struct GraphNode * left = new_graph_node(2);
    struct GraphNode * middle = new_graph_node(1);
    struct GraphNode * right = new_graph_node(4);
    struct GraphNode * bottom = new_graph_node(3);

    connect(top, left);
    connect(top, middle);

    connect(left, right);
    connect(left, bottom);

    connect(middle, bottom);

    connect(right, bottom);

    connect(bottom, right);

    print_relations(top);
    print_relations(left);
    print_relations(middle);
    print_relations(right);
    print_relations(bottom);
}