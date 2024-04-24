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

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char read_char;
    
    struct node *p, *q, *head = NULL;

    // Open file
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    q = (struct node *)malloc(sizeof(struct node));
    head = p = q;

    printf("\nREAD FROM FILE.\n");

    char token[BUFSIZE];
    int token_idx = 0;

    while(read(fd, &read_char, 1) > 0) {
        if (read_char != ',') {
            token[token_idx++] = read_char;
        } else {
            token[token_idx] = '\0';

            q = (struct node *)malloc(sizeof(struct node));
            q->data = token[0];
            q->next = NULL;

            p->next = q;
            p = p->next;

            token_idx = 0;
        }
    }

    // Print tokens
    p = head->next; // Skip the dummy first node
    while(p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }

    // Free memory
    p = head;
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    close(fd);

    return 0;
}
