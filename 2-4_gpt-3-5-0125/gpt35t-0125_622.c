#include <stdio.h>
#include <unistd.h>

// Structure to hold fifo file name and client pid
typedef struct {
    char fifoName[20];
    int pid;
} ClientInfo;

int main() {
    ClientInfo client;

    // Original fifo file name
    strcpy(client.fifoName, "myfifo");

    // Get the pid of the client process
    client.pid = getpid();

    // Concatenate pid to the fifo file name
    char newFifoName[30];
    sprintf(newFifoName, "%s%d", client.fifoName, client.pid);

    // Print the new fifo file name
    printf("New FIFO file name: %s\n", newFifoName);

    return 0;
}
