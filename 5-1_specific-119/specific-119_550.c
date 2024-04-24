#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_to_child[2];
    int pipe_to_parent[2];
    pid_t pid;

    if (pipe(pipe_to_child) < 0 || pipe(pipe_to_parent) < 0) {
        perror("Pipe creation failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        close(pipe_to_child[1]);
        close(pipe_to_parent[0]);

        dup2(pipe_to_child[0], 0);
        dup2(pipe_to_parent[1], 1);

        execl("/path/to/your/custom/command", "command_name", (char *)NULL);
    } else {
        // Parent process
        close(pipe_to_child[0]);
        close(pipe_to_parent[1]);

        char input[100];
        while (1) {
            printf("Enter input: ");
            fgets(input, sizeof(input), stdin);

            if (strcmp(input, "quit\n") == 0) {
                break;
            }

            write(pipe_to_child[1], input, strlen(input));

            char output[100];
            ssize_t bytes_read = read(pipe_to_parent[0], output, sizeof(output)-1);
            if (bytes_read > 0) {
                output[bytes_read] = '\0';
                printf("Output: %s", output);
            }
        }
    }

    return 0;
}
