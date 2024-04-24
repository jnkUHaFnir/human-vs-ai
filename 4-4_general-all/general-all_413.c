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
    argv_exec[4] = "./gestore";    // the program I want to execute in a new window
    argv_exec[5] = NULL;

    // Initialize and copy SESSION_MANAGER value
    char sess_m[80];
    strcpy(sess_m, "SESSION_MANAGER=");
    
    char* session_manager = getenv("SESSION_MANAGER");
    if (session_manager != NULL) {
        strcat(sess_m, session_manager);
    } else {
        printf("SESSION_MANAGER variable is not defined\n");
        return 1;
    }

    char *envp[3];
    envp[0] = "DISPLAY=:0.0";
    envp[1] = sess_m;
    envp[2] = NULL;

    pid_t pid_tv = fork();
    if (pid_tv == 0) {
        if (execve(argv_exec[0], argv_exec, envp) == -1) {
            perror("execve");
        }
    } else if (pid_tv < 0) {
        perror("fork");
    }

    return 0;
}
