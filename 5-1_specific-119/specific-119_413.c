char sess_m[80];
snprintf(sess_m, sizeof(sess_m), "SESSION_MANAGER=%s", getenv("SESSION_MANAGER"));

char * envp[3];
envp[0] = "DISPLAY=:0.0";
envp[1] = sess_m;
envp[2] = NULL;
char *argv_exec[6];
argv_exec[0] = "/usr/bin/xfce4-terminal";
argv_exec[1] = "--geometry";
argv_exec[2] = "480x320";
argv_exec[3] = "-x";
argv_exec[4] = "./gestore";
argv_exec[5] = NULL;
