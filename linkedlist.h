#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list {
    struct node* head;
} list;
typedef struct node {
    int val;
    struct node *next;
} node;

list create_with_node(node* n);
void append_with_list(list fl, list al);
void append_with_node(list l, node* n);
void append(list l, int val);
list create(int count, ...);
int size(list l);
node* search(list l, int val);
int index_search(list l, int val);
list index_search_all(list l, int val);
int get(list l, int index);
#endif