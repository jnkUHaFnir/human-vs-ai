#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

// Function to get the terminal size
int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

// Struct definition
struct level
{
    // ...
    char* level_data;
};

// Function to initialize struct level with the level_data array
void level_init(struct level* l)
{
    int size = get_terminal_size();
    l->level_data = (char*)malloc(size * sizeof(char));

    // Do other initialization tasks if needed
}

// Function to clean up the level struct
void level_cleanup(struct level* l)
{
    free(l->level_data);
}

int main()
{
    struct level my_level;
    level_init(&my_level);

    // Use my_level here...

    level_cleanup(&my_level);
    return 0;
}
