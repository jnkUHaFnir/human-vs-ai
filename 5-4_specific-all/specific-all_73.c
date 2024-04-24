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
    char data;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    const char s[2] = ",";
    char buffer[BUFSIZE];
    char *token;

    int fd, flag;
    char read_char;

    struct node *p = NULL, *q = NULL, *head = NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, buffer, BUFSIZE)) > 0) {
        token = strtok(buffer, s);
        while (token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = *token;
            q->next = NULL;

            if (!head) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    p = head;
    while (p) {
        printf("%c\n", p->data);
        p = p->next;
    }

    return 0;
}
