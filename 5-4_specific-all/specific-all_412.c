#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_exists(const char *filename) {
    struct stat buffer;

    // Check in user's home directory
    char home_dir[256];
    const char *user_home = getenv("HOME");
    if (user_home == NULL) {
        fprintf(stderr, "Error: HOME environment variable not set.\n");
        return 0;
    }
    snprintf(home_dir, sizeof(home_dir), "%s/%s", user_home, filename);

    if (stat(home_dir, &buffer) == 0) {
        return 1;
    }

    // Check in /etc directory
    char etc_dir[256];
    snprintf(etc_dir, sizeof(etc_dir), "/etc/%s", filename);

    if (stat(etc_dir, &buffer) == 0) {
        return 1;
    }

    return 0;
}

int main() {
    const char *filename = "example.txt";
    if (file_exists(filename)) {
        printf("File '%s' exists in user's home directory or /etc directory.\n", filename);
    } else {
        printf("File '%s' does not exist in user's home directory or /etc directory.\n", filename);
    }

    return 0;
}
