#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    pid_t pid_tv = fork();

    if (pid_tv == -1) {
        perror("fork");
        return 1;
    }

    if (pid_tv == 0) {
        char *argv_exec[6];
        argv_exec[0] = "/usr/bin/xfce4-terminal";
        argv_exec[1] = "--geometry";
        argv_exec[2] = "480x320";
        argv_exec[3] = "-x";
        argv_exec[4] = "./gestore";   // the program I want to execute in new window
        argv_exec[5] = NULL;

        char sess_m[80] = "";  // Initialize the array
        const char* sess_env = getenv("SESSION_MANAGER");
        if (sess_env) { // Ensure SESSION_MANAGER is not NULL
            strcat(sess_m, "SESSION_MANAGER=");
            strcat(sess_m, sess_env);
        } else {
            fprintf(stderr, "Session manager variable not defined.\n");
            return 1;
        }

        char *envp[3];
        envp[0] = "DISPLAY=:0.0";
        envp[1] = sess_m;
        envp[2] = NULL;

        if (execve(argv_exec[0], argv_exec, envp) == -1) { // Pass envp directly
            perror("execve");
            return 1;
        }
    }

    // Additional parent process code here

    return 0;
}
