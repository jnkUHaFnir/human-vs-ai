#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

struct level
{
    // other members of the struct ...
    char *level_data; // change to a pointer
};

void init_level(struct level *lvl)
{
    int size = get_terminal_size();

    lvl->level_data = (char *)malloc(size * sizeof(char));
    if (lvl->level_data == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1); // or handle the error accordingly
    }
}

void cleanup_level(struct level *lvl)
{
    free(lvl->level_data);
}

int main()
{
    struct level my_level;
    init_level(&my_level);

    // use my_level.level_data as needed

    cleanup_level(&my_level);

    return 0;
}
