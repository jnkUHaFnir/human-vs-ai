#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char *data; // make it a char * because tokens are strings
    struct node *next;
};

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        printf("Please provide a file name as argument\n");
        return 1;
    }

    const char s[2] = ",";
    char *token;

    int fd;
    char buffer[BUFSIZE + 1]; // Use an array instead of a pointer, also added +1 for the null byte
    ssize_t bytesRead;

    struct node *p, *q, *head = NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file"); // Use perror to show the exact error message
        return 1;
    }

    printf("\nREAD FROM FILE.\n");

    bytesRead = read(fd, buffer, BUFSIZE);
    while (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Add null byte to the end, so strtok works correctly
        token = strtok(buffer, s);

        while (token != NULL) {
            // create a node and point the value to the node
            q = (struct node *) malloc(sizeof(struct node));
            q->data = strdup(token); // allocate new memory for token, because strtok uses the same buffer location
            q->next = NULL;

            // If it is the first node, set it as head
            if (head == NULL) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }

        bytesRead = read(fd, buffer, BUFSIZE);
    }

    // Close the file descriptor
    close(fd);

    // Print the linked list
    p = head;
    while (p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free the memory allocated for the linked list
    p = head;
    while (p) {
        struct node *nextNode = p->next;
        free(p->data);
        free(p);
        p = nextNode;
    }

    return 0;
}
