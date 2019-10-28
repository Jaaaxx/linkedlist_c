#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list {
    struct node* head;
} list;
typedef struct node {
    int val;
    struct node *next;
} node;

void append(list l, int val);
list create(int count, ...);
int size(list l);
node* search(list l, int val);
int index_search(list l, int val);
list index_search_all(list l, int val);
int get(list l, int index);
#endif
