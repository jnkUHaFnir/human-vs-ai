#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

char* build_path(const char *base, const char *filename) {
    char *path = malloc(strlen(base) + strlen(filename) + 2); // Additional character for the slash and null terminator
    if (path) {
        strcpy(path, base);
        strcat(path, "/");
        strcat(path, filename);
    }
    return path;
}

int check_file_in_locations(char *filename) {
    char *path;
    char *home_directory;

    // Check in the user's home directory
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        home_directory = pw->pw_dir;
        path = build_path(home_directory, filename);
        if (path && file_exists(path)) {
            free(path);
            return 1; // File exists in user home directory
        }
        free(path); // If not found or memory allocation failed, free the memory
    }

    // Check in the /etc directory
    path = build_path("/etc", filename);
    if (path && file_exists(path)) {
        free(path);
        return 2; // File exists in /etc directory
    }
    free(path); // If not found or memory allocation failed, free the memory

    return 0; // File does not exist in either location
}

int main() {
    // Assume we're looking for this file
    char *filename = "example.conf";

    int result = check_file_in_locations(filename);
    if (result == 1) {
        printf("File found in user's home directory.\n");
    } else if (result == 2) {
        printf("File found in /etc directory.\n");
    } else {
        printf("File not found in any of the specified locations.\n");
    }

    return 0;
}
