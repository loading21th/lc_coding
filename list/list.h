#ifndef __LIST_H__
#define __LIST_H__


typedef struct node {
    struct node *next;
    int data;
} node_t;


typedef struct list {
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;


#endif
