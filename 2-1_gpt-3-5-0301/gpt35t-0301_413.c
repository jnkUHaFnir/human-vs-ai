char sess_m[80] = "SESSION_MANAGER=";
strcat(sess_m, getenv("SESSION_MANAGER"));
char sess_m[80];
snprintf(sess_m, sizeof(sess_m), "SESSION_MANAGER=%s", getenv("SESSION_MANAGER"));
