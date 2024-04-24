#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char *data;
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char delimiter = ',';
    char read_char;

    struct node *p, *q, *head;
    head = NULL;

    printf("file name: %s\n", argv[1]);
    int fd;
    char buf[BUFSIZE];
    int token_idx = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    memset(buf, 0, BUFSIZE);

    printf("\nREAD FROM FILE.\n");

    while (read(fd, &read_char, 1) > 0) {
        if (read_char == delimiter || read_char == '\n') {
            buf[token_idx] = '\0';

            q = (struct node *)malloc(sizeof(struct node));
            q->data = strdup(buf);
            q->next = NULL;

            if (head == NULL) {
                head = q;
            } else {
                p->next = q;
            }
            p = q;

            memset(buf, 0, BUFSIZE);
            token_idx = 0;

        } else {
            buf[token_idx++] = read_char;
        }
    }

    p = head;
    while (p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free the allocated memory
    p = head;
    while (p) {
        struct node *tmp = p;
        p = p->next;
        free(tmp->data);
        free(tmp);
    }

    close(fd);
    return 0;
}
