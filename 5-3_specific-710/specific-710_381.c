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
    // other members in the struct
    char *level_data;
};

void initialize_level(struct level *lvl)
{
    lvl->level_data = (char *)malloc(get_terminal_size() * sizeof(char));
    if (lvl->level_data == NULL) {
        // handle allocation failure
        printf("Memory allocation failed.");
        exit(1);
    }
}

void free_level(struct level *lvl)
{
    free(lvl->level_data);
    lvl->level_data = NULL;
}

int main()
{
    struct level my_level;
    initialize_level(&my_level);

    // Now you can access and use my_level.level_data as needed

    free_level(&my_level);

    return 0;
}
