//
//  list.h
//  test
//
//  Created by Ido Ben-Natan on 11/24/16.
//
//

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
    Node *next;
    Node *previouse;
    int  value;
};

struct List {
    Node *first;
    Node *last;
    int  length;
    int  sum;
};



List*  make_list();
void   list_remove_all_elements(List *list);
Node*  list_add_element(List *list, int num);
void   list_remove_element(List *list, Node *node);
int    list_length(List *list);
Node*  list_get_first(List *list);
Node*  list_get_last(List *list);
Node*  list_get_next(Node *node);
Node*  list_get_previouse(Node *node);
int    list_get_element_value(Node *node);
double list_get_element_value_average(List *list);
void   list_print(List *list);


#endif
