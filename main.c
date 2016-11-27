//
//  main.c
//  test
//
//  Created by Ido Ben-Natan on 11/24/16.
//
//

#include "list.h"
#include "queue.h"

int main(void)
{
    /* testing out list */
    List *l = make_list();
    Node *n = list_add_element(l, 101);
    list_add_element(l, 2);
    Node *n2 = list_add_element(l, 3);
    
    list_print(l);
    
    list_remove_element(l, n);
    list_print(l);
    
    list_remove_element(l, n2);
    list_print(l);
    
    list_remove_all_elements(l);
    
    /* testing out queue */
    Queue *queue = make_queue();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    
    print_queue(queue);
    printf("top = %d\n", top(queue));
    print_queue(queue);
    printf("pop = %d\n", pop(queue));
    print_queue(queue);
    
    return 0;
}
