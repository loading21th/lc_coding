#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_init()
{
    list_t *list = malloc(sizeof(list_t));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void list_uninit(list_t *list)
{
    free(list);
}

node_t *list_create_node(void)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        return NULL;
    }
    node->next = NULL;
    node->data = 0;
    return node;
}

list_t *list_append(list_t *list, int data)
{
    node_t *node = list_create_node();
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    if (!list->tail) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    return list;
}

void list_show(list_t *list)
{
    node_t *node = list->head;
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

int main(int argc, char *argv[])
{
    list_t *list = list_init();
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    list_append(list, 4);
    list_append(list, 5);
    list_append(list, 6);
    list_show(list);
    list_uninit(list);
}
