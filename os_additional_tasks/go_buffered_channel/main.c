#include "chan.h"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    hchan* ch = makechan(2);
    chansend(ch, 1);
    int res = chanrecv(ch);
    write(1,&res, 1);
    return 0;
}