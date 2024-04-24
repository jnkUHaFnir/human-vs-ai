#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_FILENAME_LENGTH 50

int main() {
    pid_t pid = getpid(); // Get the pid of the current process

    char fifo_filename[MAX_FILENAME_LENGTH];
    sprintf(fifo_filename, "myfifo%d", (int)pid); // Append the pid to the fifo filename

    printf("FIFO Filename for Client with PID %d: %s\n", (int)pid, fifo_filename);

    // Now you can use fifo_filename in your code

    return 0;
}
