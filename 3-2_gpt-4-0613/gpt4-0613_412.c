#include <stdlib.h>
#include <string.h>

int file_exists_in_home_or_etc(char *filename) {
    char *home_path;
    char full_path[1024];

    // first check in the user's home directory
    home_path = getenv("HOME");
    if(home_path != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", home_path, filename);
        if(file_exists(full_path)) {
            return 1;
        }
    }

    // then check in /etc
    snprintf(full_path, sizeof(full_path), "/etc/%s", filename);
    if(file_exists(full_path)) {
      return 1;
    }

    // file does not exist in either locations
    return 0;
}
