//
//  queue.h
//  test
//
//  Created by Ido Ben-Natan on 11/24/16.
//
//

#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"
#include <stdlib.h>

typedef struct {
    List *list;
} Queue;

Queue *make_queue();
void  push(Queue *queue, int num);
int   pop(Queue *queue);
int   top(Queue *queue);
void  delete_queue(Queue *queue);
int   queue_length(Queue *queue);
void  print_queue(Queue *queue);

#endif /* queue_h */
