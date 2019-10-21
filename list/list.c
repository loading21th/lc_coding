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


void list_deinit(list_t *list)
{
    free(list);
}


list_t *list_add_node_head(list_t *list, int data)
{
    if (NULL == list) {
        return list;
    }
    node_t *node = malloc(sizeof(node_t));
    if (NULL == node) {
        return NULL;
    }
    node->data = data;

    if (0 == list->size) {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    } else {
        node->next = list->head;
        list->head = node;
    }
    list->size++;
    
    return list;
}


list_t *list_del_node_head(list_t *list)
{
    if (NULL == list || 0 == list->size) {
        return NULL;
    }

    if (1 == list->size) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {
        node_t *node = list->head;
        list->head = list->head->next;
        free(node);
    }
    list->size--;

    return list;
}


list_t *list_add_node_tail(list_t *list, int data)
{
    if (NULL == list) {
        return list;
    }
    node_t *node = malloc(sizeof(node_t));
    if (NULL == node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;

    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;

    return list;
}


list_t *list_del_node_tail(list_t *list)
{
    if (NULL == list || 0 == list->size) {
        return NULL;
    }

    if (1 == list->size) {
        free(list->tail);
        list->head = NULL;
        list->tail = NULL;
    } else {
        node_t *node = list->head;
        node_t *pre  = node;
        while(node->next) {
            pre  = node;
            node = node->next;
        }
        pre->next = NULL;
        list->tail = pre;
        free(node);
    }
    list->size--;

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


size_t list_length(list_t *list)
{
    return list->size;
}


int main(int argc, char *argv[])
{
    list_t *list = list_init();
    list_add_node_tail(list, 1);
    list_add_node_tail(list, 2);
    list_add_node_tail(list, 3);
    list_add_node_tail(list, 4);
    list_add_node_tail(list, 5);
    list_add_node_tail(list, 6);
    list_del_node_tail(list);
    list_show(list);
    printf("list length = %zu\n", list_length(list));
    list_deinit(list);
}
