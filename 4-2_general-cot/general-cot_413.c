#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char sess_m[100]; // Allocate enough space, including the length of getenv result and "SESSION_MANAGER="
    sess_m[0] = '\0'; // Initialize to empty string before concatenation
    strcat(sess_m, "SESSION_MANAGER=");
    strcat(sess_m, getenv("SESSION_MANAGER"));

    char *argv_exec[] = {"/usr/bin/xfce4-terminal", "--geometry", "480x320", "-x", "./gestore", NULL};
    char *envp[] = {"DISPLAY=:0.0", sess_m, NULL};

    pid_t pid_tv = fork();
    if (pid_tv == 0) {
        if (execve(argv_exec[0], argv_exec, envp) == -1) {
            perror("execve");
            return 1;
        }
    }
    // Add wait or other handling for the parent process

    return 0;
}
