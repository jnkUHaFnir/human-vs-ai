#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int check_file_in_directories(const char *filename) {
    char home_path[PATH_MAX];
    const char *directories[] = {NULL, "/etc"};

    // Get the user's home directory
    if ((directories[0] = getenv("HOME")) == NULL) {
        fprintf(stderr, "Error: HOME environment variable not set\n");
        return -1;
    }

    for (int i = 0; i < 2; i++) {
        char full_path[PATH_MAX];
        snprintf(full_path, PATH_MAX, "%s/%s", directories[i], filename);
        
        if (file_exists(full_path)) {
            printf("File %s found in %s directory\n", filename, directories[i]);
            return 1;
        }
    }

    printf("File %s not found in user's home directory or /etc directory\n", filename);
    return 0;
}

int main() {
    const char *filename = "example.txt";
    check_file_in_directories(filename);

    return 0;
}
