#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>

// Your function to determine the terminal size (returns the number of characters)
int get_terminal_size() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

// Modified structure to use a pointer
struct level {
    // Other members...
    char *level_data;
};

int main() {
    // Determine the terminal size
    int size = get_terminal_size();

    // Create a level and allocate memory for its data
    struct level lvl;
    lvl.level_data = (char *)malloc(sizeof(char) * size);
    if (lvl.level_data == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory for level data");
        return EXIT_FAILURE;
    }

    // Remember to free the allocated memory when you're done with it!
    free(lvl.level_data);
    
    return 0;
}
