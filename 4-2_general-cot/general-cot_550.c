#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_to_child[2];
    int pipe_to_parent[2];
    pid_t pid;
    
    // Create pipes
    if (pipe(pipe_to_child) < 0 || pipe(pipe_to_parent) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        close(pipe_to_child[1]);
        dup2(pipe_to_child[0], STDIN_FILENO);
        close(pipe_to_child[0]);

        close(pipe_to_parent[0]);
        dup2(pipe_to_parent[1], STDOUT_FILENO);
        close(pipe_to_parent[1]);

        // Replace "custom_command" with your actual command
        execl("/path/to/custom_command", "custom_command", NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        close(pipe_to_child[0]);
        close(pipe_to_parent[1]);

        // Write to child
        FILE *to_child = fdopen(pipe_to_child[1], "w");
        fprintf(to_child, "input\n");
        fflush(to_child);

        // Read from child
        FILE *from_child = fdopen(pipe_to_parent[0], "r");
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), from_child) != NULL) {
            printf("Received: %s", buffer);
        }

        // Close file streams and pipes
        fclose(to_child);
        fclose(from_child);
        close(pipe_to_child[1]);
        close(pipe_to_parent[0]);
    }

    return 0;
}
