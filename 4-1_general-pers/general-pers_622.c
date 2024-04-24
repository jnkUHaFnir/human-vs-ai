#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
} FIFOInfo;

void createFIFOFileName(FIFOInfo *fifoInfo) {
    pid_t pid = getpid();
    snprintf(fifoInfo->filename, MAX_FILENAME_LENGTH, "myfifo%d", pid);
}

int main() {
    FIFOInfo fifoInfo;

    createFIFOFileName(&fifoInfo);

    printf("FIFO filename for the client process: %s\n", fifoInfo.filename);

    return 0;
}
