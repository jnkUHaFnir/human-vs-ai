#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int file_exists(char *filename)
{
    struct stat buffer;
    if (stat(filename, &buffer) == 0) {
        return 1; // File exists
    }
    return 0; // File does not exist
}

int main() {
    char *home_dir = getenv("HOME");
    char *etc_dir = "/etc/";
    char *filename = "example.txt";
    char filepath[256];

    // Check in user's home directory
    snprintf(filepath, sizeof(filepath), "%s/%s", home_dir, filename);
    if (file_exists(filepath)) {
        printf("File found in user's home directory: %s\n", filepath);
    } else {
        // Check in /etc directory
        snprintf(filepath, sizeof(filepath), "%s%s", etc_dir, filename);
        if (file_exists(filepath)) {
            printf("File found in /etc directory: %s\n", filepath);
        } else {
            printf("File not found in user's home directory or /etc directory.\n");
        }
    }

    return 0;
}
