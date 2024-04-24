#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe_stdin[2], pipe_stdout[2], pipe_stderr[2];
    pipe(pipe_stdin);
    pipe(pipe_stdout);
    pipe(pipe_stderr);
  
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        close(pipe_stdin[1]);
        close(pipe_stdout[0]);
        close(pipe_stderr[0]);
      
        dup2(pipe_stdin[0], STDIN_FILENO);
        dup2(pipe_stdout[1], STDOUT_FILENO);
        dup2(pipe_stderr[1], STDERR_FILENO);
      
        execlp("your_command", "your_command", NULL);
      
        exit(EXIT_FAILURE); // should not reach here unless exec fails
    } else {
        // Parent process
        close(pipe_stdin[0]);
        close(pipe_stdout[1]);
        close(pipe_stderr[1]);
        
        // Now you can write to pipe_stdin[1] to send input to the child process
        // and read from pipe_stdout[0] and pipe_stderr[0] to get the output

        // Don't forget to close the file descriptors and wait for child process
        wait(NULL);
    }

    return 0;
}
