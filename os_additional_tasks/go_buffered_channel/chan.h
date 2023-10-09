#pragma once
#include <unistd.h>
#include <pthread.h>
#include "queue.h"




typedef struct hchan
{
    size_t buffer_size;
    queue* recv_queue;
    queue* send_queue;
    pthread_mutex_t mutex;
    int fd[2];

} hchan;

hchan* makechan(size_t buffer_size);

int chansend(hchan* chan, int data);

int chanrecv(hchan* chan);

int freech(hchan* chan);