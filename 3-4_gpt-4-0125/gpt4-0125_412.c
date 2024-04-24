#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int file_exists(char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

int check_file_in_locations(char *filename) {
    char *homeDirectory = getenv("HOME"); // Get the HOME environment variable
    if (homeDirectory) {
        char fullPathToHome[1024]; // Assuming the path will not exceed 1024 characters
        snprintf(fullPathToHome, sizeof(fullPathToHome), "%s/%s", homeDirectory, filename); // Construct the full path in the home directory
        if (file_exists(fullPathToHome)) {
            printf("File found in home directory: %s\n", fullPathToHome);
            return 1; // File found in the home directory
        }
    }

    char fullPathToEtc[1024];
    snprintf(fullPathToEtc, sizeof(fullPathToEtc), "/etc/%s", filename); // Construct the full path in the /etc directory
    if (file_exists(fullPathToEtc)) {
        printf("File found in /etc directory: %s\n", fullPathToEtc);
        return 1; // File found in the /etc directory
    }

    printf("File not found in either location.\n");
    return 0; // File not found in either location
}

int main() {
    // Example usage
    char *filename = "somefile.conf";
    check_file_in_locations(filename);
    return 0;
}
