#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int get_terminal_size() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_row * w.ws_col;
}

struct level {
    int size;
    char *level_data;
};

void init_level(struct level *lvl) {
    lvl->size = get_terminal_size();
    lvl->level_data = (char *)malloc(lvl->size * sizeof(char));
    
    if (lvl->level_data == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // You can initialize or manipulate lvl->level_data as needed here
}

void cleanup_level(struct level *lvl) {
    if (lvl->level_data != NULL) {
        free(lvl->level_data);
        lvl->level_data = NULL;
    }
}

int main() {
    struct level my_level;
    init_level(&my_level);
    
    // Use my_level.level_data as needed
    
    cleanup_level(&my_level);
    
    return 0;
}
