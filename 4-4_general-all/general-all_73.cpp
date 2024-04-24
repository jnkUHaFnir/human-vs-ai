#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char data;
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char buffer[BUFSIZE];
    int fd, flag;
    char *token;
    struct node *p, *q, *head;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    head = NULL;
    p = head;

    while((flag = read(fd, buffer, BUFSIZE)) > 0) {
        token = strtok(buffer, s);

        while(token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = *token;
            q->next = NULL;

            if (head == NULL) {
                head = q;
                p = head;
            } else {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    p = head;
    while(p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }

    // Free allocated memory
    p = head;
    while (p != NULL) {
        struct node *tmp = p;
        p = p->next;
        free(tmp);
    }

    close(fd);

    return 0;
}
