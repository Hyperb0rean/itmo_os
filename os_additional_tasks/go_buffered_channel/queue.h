#pragma once
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

typedef struct queue 
{
    size_t size;
    struct node* head;
    struct node* tail;
} queue;

queue* create_queue();
int is_empty(queue const * const q);
int push(queue* const q, int data);
int pop(queue* const q) ;
int head(queue const * const q);
int tail(queue const * const q);