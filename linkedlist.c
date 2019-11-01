#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
void append(list l, int val) {
    node* n = (node*) malloc(sizeof(node));
    n->val = &val;
    node *curr = l.head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = n;
}

list create(int count, ...) {
    if (count < 1) {
        return (list) {};
    }
    va_list vaList;
    va_start(vaList, count);
    list l;
    node* ptr[count];
    for (int i = 0; i < count; i++) {
        node* n = (node*) malloc(sizeof(node));
        n->val = va_arg(vaList, int);
        ptr[i] = n;
        if (i > 0) {
            ptr[i-1]->next = ptr[i];
        }
    }
    va_end(vaList);
    l.head = ptr[0];
    return l;
}

list create_with_node(node* n) {
    list l;
    l.head = n;
    return l;
}

void append_with_node(list l, node* n) {
    node* curr = l.head;
    while(curr->next) {
        curr = curr->next;
    }
    curr->next = n;
}

void append_with_list(list origin, list second) {
    node* curr = origin.head;
    while(curr->next) {
        curr = curr->next;
    }
    curr->next = second.head;
}

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

list index_search_all(list l, int val) {
    node* curr = l.head;
    list indices = {};
    int c = 0;
    while(curr->next) {
        if (curr->val == val) {
            if (!indices.head) {
                indices = create(1, c);
            }
            else {
                append(indices, c);
            }
        }
        c++;
        curr = curr->next;
    }
    if (curr->val == val) {
        if (!indices.head) {
            indices = create(1, c);
        }
        else {
            append(indices, c);
        }
    }
    return indices;
}

int get(list l, int index) {
    node *curr = l.head;
    for (int i = 0; i < index; i++) {
        if (!curr->next) {
            printf("No index found, exiting...");
            exit(7);
        }
        curr = curr->next;
    }
    return curr->val;
}