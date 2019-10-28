#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int size(list l) {
    if (!l.head) {
        return -1;
    }
    node* curr = l.head;
    int c = 1;
    while (curr->next) {
        curr = curr->next;
        c++;
    }
    return c;
}

node* get_ptr(list l, int index) {
    node *curr = l.head;
    for (int i = 0; i < index; i++) {
        if (!curr->next) {
            printf("No index found, exiting...");
            exit(7);
        }
        curr = curr->next;
    }
    return curr;
}

void append(list l, int val) {
    node* n = (node*) malloc(sizeof(node));
    n->val = val;
    get_ptr(l, size(l) - 1)->next = n;
}

void append_node(list l, node* n) {
    get_ptr(l, size(l) - 1)->next = n;
}

list create(int count, ...) {
    if (count < 1) {
        return (list) {};
    }
    va_list vaList;
    va_start(vaList, count);
    node* n = (node*) malloc(sizeof(node));
    n->val = va_arg(vaList, int);
    list l = {.head = n};
    for (int i = 0; i < count - 1; i++) {
        append(l, va_arg(vaList, int));
    }
    va_end(vaList);
    return l;
}

list create_with_node(node* n) {
    list l = {.head = n};
    return l;
}

int get(list l, int index) {
    return get_ptr(l, index)->val;
}

node* search(list l, int val) {
    node* curr = l.head;
    while(curr->next) {
        if (curr->val == val) {
            return curr;
        }
        curr = curr->next;
    }
    if (curr->val == val) {
        return curr;
    }
    return NULL;
}

int index_search(list l, int val) {
    int c = 0;
    node* curr = l.head;
    while(curr->next) {
        if (curr->val == val) {
            return c;
        }
        curr = curr->next;
        c++;
    }
    if (curr->val == val) {
        return c;
    }
    return -1;
}

list search_all(list l, int val) {
    node* curr = l.head;
    list indices = {};
    for (int i = 0; i < size(l); i++) {
        if (curr->val == val) {
            if (!indices.head) {
                indices = create_with_node(curr);
            }
            else {
                append_node(indices, curr);
            }
        }
        curr = curr->next;
    }
    return indices;
}

list index_search_all(list l, int val) {
    node* curr = l.head;
    list indices = {};
    for (int i = 0; i < size(l); i++) {
        if (curr->val == val) {
            if (!indices.head) {
                indices = create(1, i);
            }
            else {
                append(indices, i);
            }
        }
        curr = curr->next;
    }
    return indices;
}
