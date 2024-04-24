char cmd[128];

if (fgets(cmd, 128, stdin) != NULL && strcmp(cmd, "exit\n") == 0) {
    // Do something
}
