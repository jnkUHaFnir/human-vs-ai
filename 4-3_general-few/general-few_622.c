#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid(); // Get the client process id

    char fifoFileName[20] = "myfifo";
    char pidStr[10]; // Buffer to store the string representation of pid
    sprintf(pidStr, "%d", pid); // Convert pid to string

    strcat(fifoFileName, pidStr); // Append pid to the fifo filename

    printf("Fifo file name with pid appended: %s\n", fifoFileName);

    // Your code logic for server-client communication using this fifo filename goes here

    return 0;
}
