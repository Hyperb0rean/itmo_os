#include "chan.h"
#include "sys/wait.h"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    hchan* ch = makechan(2);
    chansend(ch, 'a');
    chansend(ch, '\n');

    char res = chanrecv(ch);
    write(1,&res, sizeof(char));
    res = chanrecv(ch);
    write(1,&res, sizeof(char));


    int stat;
    pid_t parent = 0;
    pid_t pid = fork();
    if(pid != 0) {
        chansend(ch, 'b');
        waitpid(parent, &stat, 0);
        res = chanrecv(ch);
        write(1,&res, sizeof(char));
    }
    else {
        res = chanrecv(ch);
        write(1,&res, sizeof(char));
        chansend(ch, '\n');
        waitpid(pid, &stat, 0);
    }
    
    return 0;
}