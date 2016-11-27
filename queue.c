//
//  queue.c
//  test
//
//  Created by Ido Ben-Natan on 11/24/16.
//
//

#include "queue.h"

Queue *make_queue()
{
    Queue *queue = NULL;
    queue = (Queue *)malloc(sizeof(Queue));
    
    (*queue).list = make_list();
    
    return queue;
}


void push(Queue *queue, int num)
{
    list_add_element((*queue).list, num);
}

int pop(Queue *queue)
{
    int num = (*(*(*queue).list).last).value;
    list_remove_element((*queue).list, (*(*queue).list).last);
    return num;
}

int top(Queue *queue)
{
    return (*(*(*queue).list).last).value;
}

void delete_queue(Queue *queue)
{
    list_remove_all_elements((*queue).list);
    free(queue);
}

int queue_length(Queue *queue)
{
    return (*(*queue).list).length;
}

void print_queue(Queue *queue)
{
    printf("[");
    
    Node *pos = (*(*queue).list).last;
    while(pos != NULL)
    {
        printf("%d", (*pos).value);
        
        if ((*pos).previouse != NULL) {
            printf(", ");
        }
        
        pos = (*pos).previouse;
    }
    
    printf("]\n");
}
