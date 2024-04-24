char sess_m[80];
snprintf(sess_m, sizeof(sess_m), "SESSION_MANAGER=%s", getenv("SESSION_MANAGER"));
if(pid_tv==0) {
    if(execve(argv_exec[0], argv_exec, envp) == -1) {
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
}
