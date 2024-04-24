#include <stdio.h>
#include <stdlib.h>
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
    char *level_data;
};

int main()
{
    struct level my_level;
    int terminal_size = get_terminal_size();

    my_level.level_data = (char *)malloc(terminal_size * sizeof(char));
    if (my_level.level_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use my_level.level_data as needed

    free(my_level.level_data); // Don't forget to free the memory when done

    return 0;
}
