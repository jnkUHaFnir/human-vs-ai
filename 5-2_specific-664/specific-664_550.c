#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int in_pipe[2]; // Pipe for parent to write to child
    int out_pipe[2]; // Pipe for child to write to parent
    char buffer[256];

    if (pipe(in_pipe) == -1 || pipe(out_pipe) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        close(in_pipe[1]); // Close write end of input pipe
        close(out_pipe[0]); // Close read end of output pipe

        dup2(in_pipe[0], STDIN_FILENO);
        dup2(out_pipe[1], STDOUT_FILENO);

        execl("/path/to/your/custom/command", "/path/to/your/custom/command", NULL);

        perror("execl"); // This will only run if execl fails
        exit(EXIT_FAILURE);
    } else { // Parent process
        close(in_pipe[0]); // Close read end of input pipe
        close(out_pipe[1]); // Close write end of output pipe

        // Write to child process
        write(in_pipe[1], "input_data\n", 11);

        // Read from child process
        int nbytes = read(out_pipe[0], buffer, sizeof(buffer));
        if (nbytes > 0) {
            buffer[nbytes] = '\0';
            printf("Output from child process: %s\n", buffer);
        }

        // Repeat as needed...

        // Close remaining pipe ends
        close(in_pipe[1]);
        close(out_pipe[0]);
    }

    return 0;
}
