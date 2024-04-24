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
    char *data;     // Change data type to char pointer to store strings
    struct node *next;
};

int main(int argc, char const *argv[])
{
    const char s[2] = ",";
    char buffer[BUFSIZE]; // Change buffer to char array, not pointer
    struct node *p, *q, *head;
    char *token;
    int fd, flag;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    // Initialize head pointer
    head = NULL;

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, buffer, BUFSIZE)) > 0) {
        buffer[flag] = '\0';  // Null-terminate buffer to make it a string
        token = strtok(buffer, s);

        while (token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = strdup(token); // Allocate memory for token and copy data

            // Insert node at the end of the linked list
            if (head == NULL) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    // Print tokens stored in the linked list
    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Clean up: free allocated memory and close file
    p = head;
    while (p != NULL) {
        q = p->next;
        free(p->data);
        free(p);
        p = q;
    }

    close(fd);

    return 0;
}
