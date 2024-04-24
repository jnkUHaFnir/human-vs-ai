#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_FILENAME_LENGTH 50

typedef struct {
    char originalFilename[MAX_FILENAME_LENGTH];
    pid_t clientPid;
    char newFilename[MAX_FILENAME_LENGTH + 6]; // 6 extra characters for pid
} FifoInfo;

int main() {
    FifoInfo fifoInfo;

    // Original fifo filename
    printf("Enter the original fifo filename: ");
    scanf("%s", fifoInfo.originalFilename);

    // Get the pid of the client process
    fifoInfo.clientPid = getpid();

    // Append pid to the fifo filename
    snprintf(fifoInfo.newFilename, sizeof(fifoInfo.newFilename), "%s%d", fifoInfo.originalFilename, fifoInfo.clientPid);

    printf("Original fifo filename: %s\n", fifoInfo.originalFilename);
    printf("Client PID: %d\n", fifoInfo.clientPid);
    printf("New fifo filename: %s\n", fifoInfo.newFilename);

    return 0;
}
