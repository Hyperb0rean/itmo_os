#pragma once
#include <stdlib.h>


struct node {
    struct node* next;
    char data;
};

typedef struct queue 
{
    size_t size;
    struct node* head;
    struct node* tail;
} queue;

queue* create_queue();
int is_empty(queue const * const q);
int push(queue* const q, char data);
int pop(queue* const q) ;
char head(queue const * const q);
char tail(queue const * const q);