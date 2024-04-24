#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int file_exists(const char *filename) {
    struct stat buffer;

    // Check if file exists in user's home directory
    char home_dir[256];
    snprintf(home_dir, sizeof(home_dir), "%s/%s", getenv("HOME"), filename);
    int home_dir_exists = stat(home_dir, &buffer);
    if (home_dir_exists == 0) {
        return 1;
    }

    // Check if file exists in /etc directory
    int etc_exists = stat(filename, &buffer);
    if (etc_exists == 0) {
        return 1;
    }

    return 0;
}

int main() {
    const char *filename = "example.txt";

    if(file_exists(filename)) {
        printf("%s exists!\n", filename);
    } else {
        printf("%s does not exist.\n", filename);
    }

    return 0;
}
