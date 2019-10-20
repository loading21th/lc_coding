#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_node {
    struct list_node *next;
    int data;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;


#endif
