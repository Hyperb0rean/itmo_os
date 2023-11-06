#include "chan.h"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    hchan* ch = makechan(2);
    chansend(ch, 'a');
    chansend(ch, '\n');
    chansend(ch, 'a');

    char res = chanrecv(ch);
    write(1,&res, sizeof(char));
    res = chanrecv(ch);
    write(1,&res, sizeof(char));
    if(fork() != 0) {
        chansend(ch, '\n');
        res = chanrecv(ch);
        write(1,&res, sizeof(char));
    }
    else {
        res = chanrecv(ch);
        write(1,&res, sizeof(char));
    }
    
    return 0;
}