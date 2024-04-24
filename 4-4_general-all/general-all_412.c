#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int file_exists(const char *filename) {
    struct stat buffer;
    if (stat(filename, &buffer) == 0) {
        return 1; // File exists
    }
    return 0; // File does not exist
}

int check_file_locations(const char *filename) {
    char user_home_path[256];
    char etc_path[256];
    char user_home_filename[512];
    char etc_filename[512];

    sprintf(user_home_path, "%s/%s", getenv("HOME"), filename);
    sprintf(user_home_filename, "%s/%s", user_home_path, filename);

    snprintf(etc_path, sizeof(etc_path), "/etc/%s", filename);
    snprintf(etc_filename, sizeof(etc_filename), "/etc/%s", filename);

    if (file_exists(user_home_filename)) {
        printf("File found in user's home directory: %s\n", user_home_filename);
        return 1;
    } else if (file_exists(etc_filename)) {
        printf("File found in /etc directory: %s\n", etc_filename);
        return 1;
    } else {
        printf("File not found in user's home directory or /etc directory\n");
        return 0;
    }
}

int main() {
    const char *filename = "test.txt";
    check_file_locations(filename);
    return 0;
}
