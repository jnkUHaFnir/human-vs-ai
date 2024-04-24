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

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    printf("file name: %s\n", argv[1]);
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    struct node *head = NULL, *p = NULL, *q = NULL;
    char buffer[BUFSIZE];
    int bytes_read;

    // Read the entire file content into the buffer
    bytes_read = read(fd, buffer, BUFSIZE - 1);
    if (bytes_read < 0) {
        perror("Error reading file");
        close(fd);
        return -1;
    }
    buffer[bytes_read] = '\0'; // Null-terminate the string

    close(fd); // Close the file descriptor since we've read the data
    
    printf("\nREAD FROM FILE.\n");

    token = strtok(buffer, s);  
    while (token != NULL) {
        // Allocate a new node and fill it with data
        q = malloc(sizeof(struct node));
        if (!q) {
            perror("Memory allocation failed");
            // Free list and exit
            while (head) {
                struct node *next = head->next;
                free(head->data);
                free(head);
                head = next;
            }
            return -1;
        }

        q->data = strdup(token); // Duplicate the token
        q->next = NULL;

        if (!head) {
            head = p = q;
        } else {
            p->next = q;
            p = q;
        }

        token = strtok(NULL, s);
    }

    // Display the linked list contents
    for (p = head; p != NULL; p = p->next) {
        printf("%s\n", p->data);
    }

    // Free up the linked list
    while (head) {
        q = head;
        head = head->next;
        free(q->data); // Free the duplicated string
        free(q);
    }

    return 0;
}
