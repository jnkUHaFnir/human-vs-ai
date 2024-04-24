#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define FIFO_NAME "myfifo"

typedef struct {
    char originalName[255];
    pid_t clientPid;
} FifoInfo;

void constructFifoName(FifoInfo *info, char *newFifoName) {
    sprintf(newFifoName, "%s%d", info->originalName, (int)info->clientPid);
}

int main() {
    FifoInfo fifoInfo;
    fifoInfo.clientPid = getpid();
    strncpy(fifoInfo.originalName, FIFO_NAME, sizeof(fifoInfo.originalName));

    char newFifoName[255];
    constructFifoName(&fifoInfo, newFifoName);

    printf("New fifo filename: %s\n", newFifoName);

    return 0;
}
