#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int file_exists(const char *filename) {
    struct stat buffer;
    int i = stat(filename, &buffer);
    if (i == 0) {
        return 1;
    }
    return 0;
}

int check_file_existence(const char *filename) {
    // Check in the user's home directory
    char home_file_path[256];
    const char *home_dir = getenv("HOME");
    if (home_dir) {
        snprintf(home_file_path, sizeof(home_file_path), "%s/%s", home_dir, filename);
        if (file_exists(home_file_path)) {
            return 1;
        }
    }

    // Check in /etc directory
    char etc_file_path[256];
    snprintf(etc_file_path, sizeof(etc_file_path), "/etc/%s", filename);
    if (file_exists(etc_file_path)) {
        return 1;
    }

    return 0;
}

int main() {
    const char *filename = "example.txt";

    if (check_file_existence(filename)) {
        printf("File exists in user's home directory or /etc directory\n");
    }
    else {
        printf("File does not exist in user's home directory or /etc directory\n");
    }

    return 0;
}
