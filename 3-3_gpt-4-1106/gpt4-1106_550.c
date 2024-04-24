#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int inpipefd[2];
    int outpipefd[2];
    pid_t pid;
    
    // Create two pipes
    pipe(inpipefd); // Parent's output is child's input
    pipe(outpipefd); // Child's output is parent's input

    pid = fork();
    if (pid == 0) {
        // Child process
        close(STDIN_FILENO);  
        dup2(inpipefd[0], STDIN_FILENO);

        close(STDOUT_FILENO);
        dup2(outpipefd[1], STDOUT_FILENO);

        // Close fds not required by child. Also, we don't want
        // the exec'ed program to know these existed
        close(inpipefd[1]);
        close(outpipefd[0]);

        execlp("/path/to/your/command", "your_command", (char *)NULL);
        // If exec fails
        perror("exec");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        char buffer[4096];
        ssize_t bytes_read;

        // Close fds not required by parent
        close(inpipefd[0]);
        close(outpipefd[1]);

        // Write to the command's stdin
        write(inpipefd[1], "your input here\n", 16);

        // Read from command's stdout
        bytes_read = read(outpipefd[0], buffer, sizeof(buffer)-1);
        buffer[bytes_read] = '\0';
        printf("Output: %s\n", buffer);

        // Close fds when done
        close(inpipefd[1]);
        close(outpipefd[0]);

        // Wait for child process to terminate
        waitpid(pid, NULL, 0);
    } else {
        // Fork failed
        perror("fork");
        return 1;
    }

    return 0;
}
