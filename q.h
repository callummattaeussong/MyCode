#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "tcb.h"

typedef struct queue
{
    struct TCB_t *head;
    
}queue;

void InitQueue(struct queue *head)
{
    head -> head = NULL;
    return;
}

void AddQueue(struct queue *head, struct TCB_t *item)
{
    if(head -> head != NULL)
    {
        if(head->head->next != NULL) // has more than one element
        {
            item->prev = head->head->prev;
            item->next = head->head;
            head->head->prev->next = item;
            head->head->prev = item;

        }
        else // has only one element
        {
            head->head->next = item;
            head->head->prev = item;
            item->next = head->head;
            item->prev = head->head;
        }
        
    }
    else //queue is empty
    {
        head->head = item;
        item->prev = NULL;
        item -> next = NULL;
        
    }
    return;
}   


struct TCB_t* DelQueue(struct queue *head)
{
    struct TCB_t* item = head->head;

    if(head->head != NULL) // if queue is empty
    {
        if(head->head->next != NULL) // if more than one, remove head
        {
            head->head->prev->next = head->head->next;
            head->head->next->prev = head->head->prev;
            head->head = head->head->next;
        }
        else // if only one, turn it into an empty list
        {
            head ->head = NULL;
        }
        
    }
    
    return item;
}

struct TCB_t* newItem()
{
    struct TCB_t* item = (struct TCB_t*)malloc(sizeof(struct TCB_t*));
    
    item->prev=NULL;
    item->next=NULL;
    
    return item;
}

void RotateQ(struct queue *head)
{
    AddQueue(head, DelQueue(head));
    return;
}
