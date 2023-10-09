#include "queue.h"

queue* create_queue() {
    //struct node* ficitve = malloc(sizeof(struct node));
    queue* q = malloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->size=0;
    return q;
}

int is_empty(queue const * const q) {
    return q->size <=0;
}

int push(queue* const q, int data)
{
    struct node* new = malloc(sizeof(struct node));
    if(!new) return -1;
    new->data = data;
    new->next = NULL;
    if(q->tail) {
        q->tail->next = new;
    }
    q->tail = new;
    return 0;
}

int pop(queue* const q) {
    if(is_empty(q)) return -1;
    struct node* old = q->head;
    q->head = old->next;
    free(old);
    return 0;
}

int head(queue const * const q){
    return q->head->data;
}

int tail(queue const * const q){
    return q->tail->data;
}
