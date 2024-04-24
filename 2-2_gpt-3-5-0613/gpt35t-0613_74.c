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
    char* data;
    struct node* next;
};

int main(int argc, char const* argv[]) {
    const char s[2] = ",";
    char* token;

    printf("file name: %s\n", argv[1]);
    int fd, flag;
    char buffer[BUFSIZE];

    struct node *p, *q, *head;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    // create the first node
    q = (struct node*)malloc(sizeof(struct node));
    q->data = NULL;
    q->next = NULL;
    p = q;
    head = q;

    printf("\nREAD FROM FILE.\n");
    while ((flag = read(fd, buffer, BUFSIZE)) > 0) {
        buffer[flag] = '\0'; // null-terminate the buffer
        token = strtok(buffer, s);

        while (token != NULL) {
            // create a node and point the value to the node
            q = (struct node*)malloc(sizeof(struct node));
            q->data = strdup(token);
            q->next = NULL;

            p->next = q;
            p = p->next;

            token = strtok(NULL, s);
        }
    }

    p = head->next; // skip the first node (empty)

    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // free the memory
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }

    close(fd);

    return 0;
}
