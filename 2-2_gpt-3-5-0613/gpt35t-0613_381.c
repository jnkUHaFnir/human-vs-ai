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
    // ...
    char* level_data;
};

int main()
{
    int size = get_terminal_size();

    struct level my_level;
    my_level.level_data = malloc(size * sizeof(char));

    // Check if allocation succeeded
    if (my_level.level_data == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Use my_level.level_data as needed

    // Don't forget to free the memory when you're done
    free(my_level.level_data);

    return 0;
}
