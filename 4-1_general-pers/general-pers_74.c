#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char *data; // Change 'char' to 'char *' to store a string
    struct node *next;
};

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    const char s[2] = ",";

    int fd;
    char buffer[BUFSIZE];
    int flag;

    // Initialize head of linked list
    struct node *head = NULL;
    struct node *p = NULL;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    while ((flag = read(fd, buffer, BUFSIZE)) > 0)
    {
        char *token = strtok(buffer, s);

        while (token != NULL)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL) {
                perror("Memory allocation failed");
                return -1;
            }

            newNode->data = strdup(token); // Allocate memory for token and copy it
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                p = head;
            } else {
                p->next = newNode;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    close(fd);

    p = head;
    printf("Tokens:\n");
    while (p != NULL) {
        printf("%s\n", p->data);
        struct node *temp = p;
        p = p->next;
        free(temp->data); // Free the memory allocated for token
        free(temp);       // Free the memory allocated for node
    }

    return 0;
}
