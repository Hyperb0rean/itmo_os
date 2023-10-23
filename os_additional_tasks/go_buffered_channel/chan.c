#include "chan.h"

hchan* makechan(size_t buffer_size){
    hchan* chan = malloc(sizeof(hchan));
    chan->buffer_size = buffer_size;
    chan->recv_queue = create_queue();
    chan->send_queue = create_queue();
    int res = pipe(chan->fd);
    if (res != -1)
    {
        write(2, "created pipe\n", 14);
    }
    
    pthread_mutex_unlock(&chan->mutex);
    return chan;
}

int chansend(hchan* chan, int data){
    write(2, "send\n", 5);
    if(chan->send_queue->size > chan->buffer_size) return -1;
    pthread_mutex_lock(&chan->mutex);
    push(chan->send_queue, data);
    write(2, "push send\n", 10);
    write(2,&chan->send_queue->head->data,sizeof(int));
    write(chan->fd[1],&chan->send_queue->head->data,sizeof(int));
    pop(chan->send_queue);
    pthread_mutex_unlock(&chan->mutex);
    return 0;
}

int chanrecv(hchan* chan){
    write(2, "recv\n", 5);
    if(chan->recv_queue->size > chan->buffer_size) return -1;
    pthread_mutex_lock(&chan->mutex);
    push(chan->recv_queue, 0);
    write(2, "push recv\n", 10);
    read(chan->fd[0],&chan->recv_queue->tail->data,sizeof(int));
    int data = chan->recv_queue->head->data;
    write(2, &data, sizeof(int));
    pop(chan->recv_queue);
    pthread_mutex_unlock(&chan->mutex);
    write(2, &data, sizeof(int));
    return data;
}

int freech(hchan * const chan){
    close(chan->fd[0]);
    close(chan->fd[1]);
    if(!is_empty(chan->recv_queue) || !is_empty(chan->send_queue)){
        return -1;
    }
    free(chan->recv_queue);
    free(chan->send_queue);
    free(chan);
    return 0;
}