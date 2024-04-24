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
    // Other members of the struct
    char *level_data;
};

void initialize_level_data(struct level *lvl)
{
    int size = get_terminal_size();
    lvl->level_data = (char *)malloc(size * sizeof(char));
    if (lvl->level_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // or handle the error in a way suitable for your application
    }
}

void free_level_data(struct level *lvl)
{
    free(lvl->level_data);
}

int main()
{
    struct level my_level;

    initialize_level_data(&my_level);

    // Do something with my_level.level_data

    free_level_data(&my_level);

    return 0;
}
