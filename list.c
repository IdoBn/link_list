//
//  list.c
//  test
//
//  Created by Ido Ben-Natan on 11/24/16.
//
//

#include "list.h"

List* make_list()
{
    List *list = NULL;
    list = (List *)malloc(sizeof(List));
    (*list).first = NULL;
    (*list).last = NULL;
    (*list).length = 0;
    (*list).sum = 0;
    
    return list;
}

void list_remove_all_elements(List *list)
{
    Node *pos = (*list).first;
    Node *prev = NULL;
    while(pos != NULL)
    {
        prev = pos;
        pos = (*pos).next;
        free(pos);
    }
    
    free(list);
}

Node *list_add_element(List *list, int num)
{
    Node *node = NULL;
    node = (Node *)malloc(sizeof(Node));
    (*node).value = num;
    
    if ((*list).first == NULL) {
        (*node).next = NULL;
        (*node).previouse = NULL;
        
        (*list).first = node;
        (*list).last  = node;
    } else {
        Node *last = (*list).last;
        (*node).next = NULL;
        (*node).previouse = last;
        
        (*last).next = node;
        (*list).last = node;
    }
    
    (*list).sum += num;
    ++((*list).length);
    
    return node;
}

void list_remove_element(List *list, Node *node)
{
    if (node == (*list).first) {
        (*list).first = (*node).next;
        (*(*list).first).previouse = NULL;
    } else if (node == (*list).last) {
        (*list).last = (*node).previouse;
        (*(*list).last).next = NULL;
    } else {
        Node *prev = (*node).previouse;
        Node *next = (*node).next;
        (*prev).next = next;
        (*next).previouse = prev;
    }
    
    free(node);
    
    (*list).sum -= (*node).value;
    --(*list).length;
}


int list_length(List *list)
{
    return (*list).length;
}

Node* list_get_first(List *list)
{
    return (*list).first;
}

Node* list_get_last(List *list)
{
    return (*list).last;
}

Node* list_get_next(Node *node)
{
    return (*node).next;
}

Node* list_get_previouse(Node *node)
{
    return (*node).previouse;
}

int list_get_element_value(Node *node)
{
    return (*node).value;
}

double list_get_element_value_average(List *list)
{
    return (double)(*list).sum / (*list).length;
}

void list_print(List *list)
{
    printf("[");
    if (!list)
        return;
    
    Node *pos = (*list).first;
    while (pos != NULL)
    {
        printf("%d", (*pos).value);
        pos = (*pos).next;
        
        if (pos != NULL) {
            printf(", ");
        }
    }
    
     printf("] (length = %d) (avg = %f)\n", list_length(list), list_get_element_value_average(list));
}
