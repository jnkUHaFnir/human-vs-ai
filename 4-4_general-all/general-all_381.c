#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

struct level
{
    // Other members of the struct
    char *level_data; // Use a pointer instead of fixed-size array
};

int main()
{
    struct level my_level;
    int size = get_terminal_size();
    
    my_level.level_data = (char *)malloc(size * sizeof(char));
    if(my_level.level_data == NULL)
    {
        // Handle memory allocation failure
        return 1;
    }

    // Now you can use my_level.level_data as you intended
    
    // Don't forget to free the memory when you're done with it
    free(my_level.level_data);

    return 0;
}
