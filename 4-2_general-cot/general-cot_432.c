#include <stdio.h>
#include <string.h>

void die(const char* msg) {
    printf("%s", msg);
    exit(1);
}

void get_user(char* user) {
    char buf[1024];
    if (strlen(user) > sizeof(buf))
        die("error: user string too long\n");
    strncpy(buf, user, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0'; // Ensure null-termination

    // Continue with your code
    // ...
} 
