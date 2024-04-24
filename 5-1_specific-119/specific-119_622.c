#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define FIFO_FILENAME_MAX_LENGTH 50

// Function to construct the FIFO filename with PID
void construct_fifo_filename(char *fifo_filename) {
    char base_filename[] = "myfifo";
    pid_t pid = getpid();

    snprintf(fifo_filename, FIFO_FILENAME_MAX_LENGTH, "%s%d", base_filename, pid);
}

int main() {
    char fifo_filename[FIFO_FILENAME_MAX_LENGTH];

    // Construct the FIFO filename with the PID
    construct_fifo_filename(fifo_filename);

    printf("FIFO filename for the client process: %s\n", fifo_filename);

    return 0;
}
