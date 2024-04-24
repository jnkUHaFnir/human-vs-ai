#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define MAX_BUF 1024

typedef struct fifo_name {
    char name[MAX_BUF];
    pid_t pid;
} fifo_name;

int main(int argc, char *argv[]) {
    fifo_name fn;
    sprintf(fn.name, "myfifo%d", getpid());
    fn.pid = getpid();
    printf("Fifo filename: %s\n", fn.name);
    return 0;
}
