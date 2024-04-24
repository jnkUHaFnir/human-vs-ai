#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define FIFO_NAME "myfifo"

void generate_fifo_name(pid_t client_pid, char *fifo_name) {
    snprintf(fifo_name, 50, "%s%d", FIFO_NAME, (int)client_pid);
}

int main() {
    pid_t client_pid = getpid(); // Get the client process ID
    char fifo_name[50];

    // Generate fifo file name
    generate_fifo_name(client_pid, fifo_name);

    // Print the generated fifo file name
    printf("Generated fifo file name: %s\n", fifo_name);

    return 0;
}
