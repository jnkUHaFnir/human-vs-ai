#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    char fifoName[256]; // Adjust the size as needed
    pid_t pid = getpid(); // Get the current process PID

    // Create the unique FIFO name by appending PID to base name
    sprintf(fifoName, "myfifo%d", pid);

    // Now, you have the unique name in fifoName
    printf("FIFO name: %s\n", fifoName);

    // Create FIFO
    if (mkfifo(fifoName, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    // Your code for reading or writing to the FIFO

    // Don't forget to remove the FIFO file when done
    unlink(fifoName);

    return 0;
}
