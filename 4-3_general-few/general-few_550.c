#include <unistd.h>
#include <stdio.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process - set up stdin and stdout redirection
        dup2(fd[0], 0);  // Redirect stdin to read end of the pipe
        close(fd[1]);    // Close unused write end of the pipe

        execl("/path/to/your/custom/command", "custom_command", NULL);
        perror("exec");
    } else {
        // Parent process - communicate with the child
        close(fd[0]);  // Close unused read end of the pipe

        // Write data to the child process
        const char* input = "input\n";
        write(fd[1], input, strlen(input));

        // Read output from the child process
        char output_buf[100];
        read(fd[0], output_buf, sizeof(output_buf));

        printf("Child process output: %s\n", output_buf);

        close(fd[1]);  // Close write end of the pipe

        wait(NULL);  // Wait for child process to finish
    }

    return 0;
}
