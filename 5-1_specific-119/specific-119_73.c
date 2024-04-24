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
    char *data; // Change to char*
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char buffer[BUFSIZE];

    struct node *p, *q, *head;
    int fd, flag;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    head = NULL;
    p = head;

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, buffer, BUFSIZE)) > 0) {
        char *token = strtok(buffer, s);
        while(token != NULL) {
            if (head == NULL) {
                head = (struct node *)malloc(sizeof(struct node));
                head->data = strdup(token);
                head->next = NULL;
                p = head;
            } else {
                q = (struct node *)malloc(sizeof(struct node));
                q->data = strdup(token);
                q->next = NULL;
                p->next = q;
                p = p->next;
            }
            token = strtok(NULL, s);
        }
    }

    p = head;
    while(p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}
