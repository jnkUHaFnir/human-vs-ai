#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct level
{
    char *level_data;
};

int get_terminal_size()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

int main() {
    struct level mylevel;

    int size = get_terminal_size();
    mylevel.level_data = malloc(size * sizeof(char));

    // make sure to free the allocated memory when not needed.
    free(mylevel.level_data);

    return 0;
}
