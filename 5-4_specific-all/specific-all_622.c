#include <stdio.h>
#include <unistd.h> // for getpid()

#define MAX_FILENAME_LENGTH 50 // Define a max length for the filename

int main() {
    pid_t client_pid = getpid(); // Get the client's PID
    char fifo_filename[MAX_FILENAME_LENGTH];

    // Define the base FIFO filename
    const char base_fifo_filename[] = "myfifo";

    // Create the full FIFO filename with the client's PID appended
    snprintf(fifo_filename, sizeof(fifo_filename), "%s%d", base_fifo_filename, client_pid);

    // Print the full FIFO filename
    printf("Full FIFO filename: %s\n", fifo_filename);

    return 0;
}
