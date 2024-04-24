#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

int file_exists(const char *filename) {
    struct stat buffer;
    char full_path[255];

    // Check in user's home directory
    const char *home_dir = getenv("HOME");
    if (home_dir != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", home_dir, filename);
        if (stat(full_path, &buffer) == 0) {
            return 1;
        }
    }

    // Check in /etc directory if not found in user's home directory
    if (stat("/etc", &buffer) == 0) {
        snprintf(full_path, sizeof(full_path), "/etc/%s", filename);
        if (stat(full_path, &buffer) == 0) {
            return 1;
        }
    }

    return 0;
}
