#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct level
{
    int rows;
    int cols;
    char *level_data;
};

int get_terminal_size(int *rows, int *cols)
{
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        perror("ioctl");
        return -1;
    }

    *rows = w.ws_row;
    *cols = w.ws_col;

    return 0;
}

struct level *init_level()
{
    struct level *lvl = malloc(sizeof(struct level));
    if (!lvl) {
        return NULL;
    }

    if (get_terminal_size(&lvl->rows, &lvl->cols) != 0) {
        free(lvl);
        return NULL;
    }

    lvl->level_data = malloc(lvl->rows * lvl->cols * sizeof(char));
    if (!lvl->level_data) {
        free(lvl);
        return NULL;
    }

    // Initialize level_data if necessary
    // for (int i = 0; i < lvl->rows * lvl->cols; i++) {
    //     lvl->level_data[i] = ...;
    // }

    return lvl;
}

void free_level(struct level *lvl)
{
    if (lvl) {
        free(lvl->level_data);
        free(lvl);
    }
}

int main()
{
    struct level *lvl = init_level();
    if (!lvl) {
        fprintf(stderr, "Failed to initialize level structure.\n");
        return EXIT_FAILURE;
    }

    // Use lvl for something...

    free_level(lvl);
    return EXIT_SUCCESS;
}
