#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct level
{
    // other members of struct level
    char *level_data; // Dynamically allocated
    size_t level_data_size;
};

int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

int main()
{
    struct level my_level;
    // Dynamically allocate memory for level_data
    my_level.level_data_size = get_terminal_size();
    my_level.level_data = malloc(my_level.level_data_size * sizeof(char));

    if(my_level.level_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use my_level.level_data as needed

    // Don't forget to free memory after use
    free(my_level.level_data);

    return 0;
}
