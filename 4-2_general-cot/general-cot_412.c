#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int file_exists(const char *filename) {
    struct stat buffer;
    char *home = getenv("HOME"); // Get the user's home directory
    char home_filename[PATH_MAX];

    // Check in user's home directory
    snprintf(home_filename, PATH_MAX, "%s/%s", home, filename);
    if (stat(home_filename, &buffer) == 0) {
        return 1;
    }

    // Check in /etc directory if not found in the user's home directory
    if (stat(filename, &buffer) == 0) {
        return 1;
    }

    return 0;
}
