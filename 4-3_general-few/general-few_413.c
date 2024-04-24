char sess_m[80] = "";
char sess_m[80] = "";
strcat(sess_m, "SESSION_MANAGER=");
strcat(sess_m, getenv("SESSION_MANAGER"));

char *envp[4];
envp[0] = "DISPLAY=:0.0";
envp[1] = sess_m;
envp[2] = "SESSION_MANAGER=value_here"; // Add a default value if getenv("SESSION_MANAGER") is NULL
envp[3] = NULL;

if (pid_tv == 0) {
    if (execve(argv_exec[0], argv_exec, envp) == -1) {
        perror("execve");
    }
}
