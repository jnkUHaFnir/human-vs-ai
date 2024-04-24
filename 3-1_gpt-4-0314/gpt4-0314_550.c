#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *in, *out;
  char buf[100];

  // Run your custom command
  if ((in = popen("your_custom_command", "r")) == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }

  // Get input from the command
  while (fgets(buf, sizeof(buf), in) != NULL) {
    printf("Output from command: %s", buf);
  }

  pclose(in);

  // Now we can write to the command
  if ((out = popen("your_custom_command", "w")) == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }

  // Send some input to the command
  fprintf(out, "your_input_here\n");
  fflush(out);

  pclose(out);
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int input_pipe[2], output_pipe[2];
  pid_t pid;

  // Create pipes for input and output
  if (pipe(input_pipe) != 0 || pipe(output_pipe) != 0) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  // Fork and run the custom command
  pid = fork();
  if (pid < 0) {
    perror("fork");
  }
  else if (pid == 0) { // Child process
    dup2(input_pipe[0], STDIN_FILENO);
    close(input_pipe[1]);

    dup2(output_pipe[1], STDOUT_FILENO);
    close(output_pipe[0]);

    execl("/bin/sh", "sh", "-c", "your_custom_command", (char *) 0);
    perror("execl");
    _exit(EXIT_FAILURE);
  }

  // Parent process
  close(input_pipe[0]);
  close(output_pipe[1]);

  FILE *out = fdopen(output_pipe[0], "r");
  FILE *in = fdopen(input_pipe[1], "w");

  char buf[100];

  // Read output from the command
  while (fgets(buf, sizeof(buf), out) != NULL) {
    printf("Output from command: %s", buf);
  }

  // Send input to the command
  fprintf(in, "your_input_here\n");
  fflush(in);

  fclose(in);
  fclose(out);
  waitpid(pid, NULL, 0);

  return 0;
}
