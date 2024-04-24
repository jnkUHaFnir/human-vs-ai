#include <string.h>

// Function to check if the file is an .exe or .o file
int isExecutableOrObjectFile(const char* fpath) {
    const char* ext_exe = ".exe";
    const char* ext_o = ".o";

    // Get the length of the file path
    size_t path_len = strlen(fpath);

    // Check if the file path has enough characters to contain the extensions
    if (path_len >= strlen(ext_exe) && path_len >= strlen(ext_o)) {
        // Compare the endings of the file path with the target extensions
        if (strcmp(fpath + path_len - strlen(ext_exe), ext_exe) == 0 ||
            strcmp(fpath + path_len - strlen(ext_o), ext_o) == 0) {
            return 1; // File is .exe or .o
        }
    }

    return 0; // File is not .exe or .o
}
