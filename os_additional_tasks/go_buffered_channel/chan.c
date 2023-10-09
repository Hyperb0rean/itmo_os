#include "chan.h"

hchan* makechan(size_t buffer_size){
    hchan* chan = malloc(sizeof(hchan));
    chan->buffer_size = buffer_size;
    chan->recv_queue = create_queue();
    chan->send_queue = create_queue();
    pipe(chan->fd);
    pthread_mutex_unlock(&chan->mutex);
    return chan;
}

int chansend(hchan* chan, int data){
    if(chan->send_queue->size > chan->buffer_size) return -1;
    pthread_mutex_lock(&chan->mutex);
    push(chan->send_queue, data);
    write(chan->fd[1],chan->send_queue->head,sizeof(int));
    pop(chan->send_queue);
    pthread_mutex_unlock(&chan->mutex);
    return 0;
}

int chanrecv(hchan* chan){
    if(chan->recv_queue->size > chan->buffer_size) return -1;
    pthread_mutex_lock(&chan->mutex);
    push(chan->recv_queue, 0);
    read(chan->fd[0],&chan->recv_queue->tail->data,sizeof(int));
    int data = chan->recv_queue->head;
    pop(chan->recv_queue);
    pthread_mutex_unlock(&chan->mutex);
    return data;
}

int freech(hchan * const chan){
    if(!is_empty(chan->recv_queue) || !is_empty(chan->send_queue)){
        return -1;
    }
    free(chan->recv_queue);
    free(chan->send_queue);
    free(chan);
    return 0;
}