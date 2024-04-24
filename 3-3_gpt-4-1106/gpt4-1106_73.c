#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 1024

struct node {
    char *data;
    struct node *next;
};

struct node *createNode(char *data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = strdup(data); // Duplicate the string to be safe
    new_node->next = NULL;
    return new_node;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    char buffer[BUFSIZE];
    int bytes_read;
    struct node *head = NULL, *p = NULL;

    // Read the whole file into the buffer
    while ((bytes_read = read(fd, buffer, BUFSIZE - 1)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the read content
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            if (head == NULL) {
                head = createNode(token);
                p = head;
            } else {
                p->next = createNode(token);
                p = p->next;
            }
            token = strtok(NULL, ",");
        }
    }

    close(fd);

    // Print and free the linked list
    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        struct node *tmp = p;
        p = p->next;
        free(tmp->data);
        free(tmp);
    }

    return 0;
}
