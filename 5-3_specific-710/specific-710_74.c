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
    const char *s = ",";
    char buffer[BUFSIZE];

    int fd, flag;
    char *token;
    struct node *head = NULL;
    struct node *p = NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, buffer, BUFSIZE)) > 0) {
        token = strtok(buffer, s);  

        while (token != NULL) {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = strdup(token); // Allocate memory and copy the token
            new_node->next = NULL;

            if (head == NULL) {
                head = new_node;
                p = head;
            } else {
                p->next = new_node;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free the allocated memory
    p = head;
    while (p != NULL) {
        struct node *current = p;
        p = p->next;
        free(current->data); // Free the strdup'd string
        free(current);
    }

    return 0;
}
