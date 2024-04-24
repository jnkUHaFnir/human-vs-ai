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
    char *data;
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char *token;

    printf("file name: %s\n", argv[1]);
    int fd, flag;
    char buffer[BUFSIZE];

    char *print_tokens;
    int token_idx;

    char read_char;

    struct node *p = NULL, *q = NULL, *head = NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    // create the first node
    q = (struct node *)malloc(sizeof(struct node));
    q->data = NULL;
    q->next = NULL;

    p = q; // update p to point to the head node

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, &read_char, 1)) > 0) {
        token = strtok(&read_char, s);

        while (token != NULL) {
            // create a node and point the value to the node
            q->next = (struct node *)malloc(sizeof(struct node));
            q = q->next;
            q->data = strdup(token); // allocate memory for token and copy its value
            q->next = NULL;

            token = strtok(NULL, s);
        }
    }

    p = head;
    while (p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // free memory allocated for each node
    p = head;
    while (p) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }

    return 0;
}
