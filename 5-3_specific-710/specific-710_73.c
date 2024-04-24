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
    char buffer[BUFSIZE];
    char *token;
    
    int fd, flag;
    char read_char;

    struct node *p, *q, *head;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    head = NULL;
    p = NULL;

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, &read_char, 1)) > 0) {
        if (read_char == '\n' || read_char == '\r' || read_char == '\0') {
            continue; // Skip newline and null characters
        }

        if (read_char == s[0]) { // Handle token separation
            if (p != NULL) {
                q = (struct node *)malloc(sizeof(struct node));
                q->data = strdup(buffer); // Store the token
                q->next = NULL;

                if (head == NULL) {
                    head = q;
                    p = q;
                } else {
                    p->next = q;
                    p = q;
                }
            }
            memset(buffer, 0, BUFSIZE); // Clear buffer for next token
        } else {
            strncat(buffer, &read_char, 1); // Append character to buffer
        }
    }

    p = head;
    while (p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}
