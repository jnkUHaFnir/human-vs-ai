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
    char data[BUFSIZE];
    struct node *next;
};

int main(int argc, char const *argv[]) {
    const char s[2] = ",";
    char read_char;
    struct node *p, *q, *head;
    int fd, flag;
    char buffer[BUFSIZE];
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("File open error");
        return -1;
    }

    head = NULL;
    p = NULL;

    while ((flag = read(fd, &read_char, 1)) > 0) {
        if (read_char != ',') {
            strncat(buffer, &read_char, 1);
        } else {
            q = (struct node *)malloc(sizeof(struct node));
            strcpy(q->data, buffer);
            q->next = NULL;

            if (head == NULL) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = p->next;
            }

            memset(buffer, 0, BUFSIZE);  // Reset the buffer
        }
    }

    // Print the tokens
    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free the allocated memory
    p = head;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }

    close(fd);

    return 0;
}
