#include "kernel/types.h"
#include "kernel/syscall.h"
#include "user/user.h"

int
main(void) 
{
    int p[2];
    char buffer[5];

    pipe(p);
    int pid = fork();
    if (pid == 0) {
        read(p[0], buffer, sizeof(buffer));
        printf("%d: got %s\n", getpid(), buffer);
        write(p[1], "pong", sizeof(buffer));
    } else if(pid > 0) {
        write(p[1], "ping", 5);
        read(p[0], buffer, sizeof(buffer));
        printf("%d: got %s\n", getpid(), buffer);
    }
    else {
        prinf("fork error\n");
    }

    exit(0);
}