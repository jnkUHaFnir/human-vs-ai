#include <sys/ioctl.h>
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
    int size;
    char *level_data;
};

void init_level(struct level *lvl)
{
    lvl->size = get_terminal_size();
    lvl->level_data = malloc(lvl->size * sizeof(char));
}

void cleanup_level(struct level *lvl)
{
    free(lvl->level_data);
}

int main()
{
    struct level my_level;
    init_level(&my_level);

    // Use my_level.level_data as needed

    cleanup_level(&my_level);

    return 0;
}
