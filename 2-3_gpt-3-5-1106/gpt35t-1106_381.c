#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

struct level
{
    // other members of the struct
    char *level_data;
};

int main()
{
    // Dynamically allocate memory for level_data
    struct level my_level;
    my_level.level_data = (char*)malloc(get_terminal_size() * sizeof(char));

    // Use the level_data array
    // ...

    // Don't forget to free the memory when you're done using it
    free(my_level.level_data);

    return 0;
}
