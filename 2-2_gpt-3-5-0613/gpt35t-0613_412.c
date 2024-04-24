#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int file_exists(char *filename) {
    struct stat buffer;
    char full_path[256];

    // Check if file exists in user's home directory
    snprintf(full_path, sizeof(full_path), "%s/%s", getenv("HOME"), filename);
    if (stat(full_path, &buffer) == 0) {
        return 1;
    }

    // Check if file exists in /etc directory
    snprintf(full_path, sizeof(full_path), "/etc/%s", filename);
    if (stat(full_path, &buffer) == 0) {
        return 1;
    }

    return 0;
}
