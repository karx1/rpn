#include <stdlib.h>
#include "ll.h"

ll_node_t* init_node(int data) {
    ll_node_t* new_node = (ll_node_t*) malloc(sizeof(ll_node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

ll_node_t* insert_front(int data, ll_node_t* top) {
    ll_node_t* new_node = init_node(data);
    new_node->next = top;
    return new_node;
}

ll_node_t* insert_back(int data, ll_node_t* bottom) {
    ll_node_t* new_node = init_node(data);
    bottom->next = new_node;
    return bottom;
}

ll_node_t* remove_front(ll_node_t* top) {
    ll_node_t* next = top->next;
    top->next = NULL;
    free(top);
    return next;
}
