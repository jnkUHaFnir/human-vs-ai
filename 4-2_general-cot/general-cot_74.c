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
    char read_char;
    struct node *p, *q, *head;
    int fd, flag;
    char buffer[BUFSIZE];
    char *token;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("Error opening file");
        return -1;
    }

    // Initialize head node
    head = (struct node *)malloc(sizeof(struct node));
    head->data = NULL;
    head->next = NULL;
    p = head;

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, &read_char, 1)) > 0) {
        if (read_char == ',') {
            buffer[n] = '\0'; // Null terminate the buffer
            token = strdup(buffer); // Duplicate buffer to store token

            q = (struct node *)malloc(sizeof(struct node));
            q->data = token;
            q->next = NULL;

            p->next = q;
            p = p->next;

            n = 0; // Reset the buffer index for next token
        } else {
            buffer[n++] = read_char;
        }
    }

    // Print tokens stored in the linked list
    p = head->next; // Skip head node
    while(p) {
        printf("%s\n", p->data);
        struct node *temp = p;
        p = p->next;
        free(temp->data); // Free the token string memory
        free(temp); // Free the node memory
    }

    // Free the head node memory
    free(head);

    return 0;
}
