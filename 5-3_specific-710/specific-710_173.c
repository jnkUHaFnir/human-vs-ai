#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

int main() {
    char exe_path[PATH_MAX];
    char file_path[PATH_MAX];
    
    // Get the full path to the executable
    ssize_t len = readlink("/proc/self/exe", exe_path, sizeof(exe_path)-1);
    if (len != -1) {
        exe_path[len] = '\0';
        
        // Construct the full file path relative to the executable
        snprintf(file_path, sizeof(file_path), "%s/Desktop/folder/file", exe_path);
        
        // Open the file
        int fd = open(file_path, O_RDONLY);
        if (fd == -1) {
            perror("Error opening file");
            return 1;
        }
        
        // File opened successfully, do something with it
        
        close(fd);
    } else {
        perror("Error getting executable path");
        return 1;
    }

    return 0;
}
