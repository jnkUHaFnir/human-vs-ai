#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char data[100];
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char read_char;
    int fd, flag;
    struct node *p, *q, *head;
    char file_buffer[BUFSIZE];
    
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    head = NULL;
    p = head;

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, &read_char, 1)) > 0) {
        if (read_char != ',') {
            strncat(file_buffer, &read_char, 1);
        } else {
            q = (struct node *)malloc(sizeof(struct node));
            strncpy(q->data, file_buffer, strlen(file_buffer));
            q->next = NULL;

            if (head == NULL) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = p->next;
            }
            memset(file_buffer, 0, sizeof(file_buffer));
        }
    }

    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free allocated memory
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }

    close(fd);
    return 0;
}
