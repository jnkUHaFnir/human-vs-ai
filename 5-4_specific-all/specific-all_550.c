#include <stdio.h>
#include <unistd.h>

int main() {
    int in_pipe[2]; // pipe for sending input
    int out_pipe[2]; // pipe for receiving output
    char buffer[100];

    if (pipe(in_pipe) == -1 || pipe(out_pipe) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // Child process
        close(in_pipe[1]); // Close write end of input pipe
        close(out_pipe[0]); // Close read end of output pipe

        dup2(in_pipe[0], 0); // Redirect stdin to read end of input pipe
        dup2(out_pipe[1], 1); // Redirect stdout to write end of output pipe

        char *args[] = {"/path/to/your/custom/command", NULL};
        execv(args[0], args); // Execute the custom command
    } else { // Parent process
        close(in_pipe[0]); // Close read end of input pipe
        close(out_pipe[1]); // Close write end of output pipe

        while (1) {
            printf("Enter a command: ");
            fgets(buffer, sizeof(buffer), stdin); // Get user input

            if (strcmp(buffer, "quit\n") == 0) {
                break;
            }

            write(in_pipe[1], buffer, strlen(buffer)); // Send user input to child process

            read(out_pipe[0], buffer, sizeof(buffer)); // Read output from child process
            printf("Output: %s", buffer);
        }
        
        close(in_pipe[1]); // Close write end of input pipe
        close(out_pipe[0]); // Close read end of output pipe
    }

    return 0;
}
