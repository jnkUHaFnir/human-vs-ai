#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int file_exists(const char *filename) {
    struct stat buffer;

    // Check file in user's home directory
    char home_path[256];
    snprintf(home_path, sizeof(home_path), "%s/%s", getenv("HOME"), filename);
    
    if (stat(home_path, &buffer) == 0) {
        return 1;
    }

    // Check file in /etc directory
    char etc_path[256];
    snprintf(etc_path, sizeof(etc_path), "/etc/%s", filename);
    
    if (stat(etc_path, &buffer) == 0) {
        return 1;
    }

    return 0; // File not found in either location
}
