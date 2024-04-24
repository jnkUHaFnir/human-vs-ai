#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *argv_exec[6];
    argv_exec[0] = "/usr/bin/xfce4-terminal";
    argv_exec[1] = "--geometry";
    argv_exec[2] = "480x320";
    argv_exec[3] = "-x";
    argv_exec[4] = "./gestore";  // the program to execute in the new window
    argv_exec[5] = NULL;

    char sess_m[80];
    strcpy(sess_m, "SESSION_MANAGER=");
    strcat(sess_m, getenv("SESSION_MANAGER"));

    char *envp[3];
    envp[0] = "DISPLAY=:0.0";
    envp[1] = sess_m;
    envp[2] = NULL;

    pid_t pid_tv = fork();
    if (pid_tv == -1) {
        perror("fork failed");
        return 1;
    } else if (pid_tv == 0) {
        if (execve(argv_exec[0], argv_exec, envp) == -1) {
            perror("execve failed");
            return 1;
        }
    }
    return 0;
}
