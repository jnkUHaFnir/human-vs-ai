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
    char *token;

    int fd, flag;
    char buffer[BUFSIZE];
    char read_char;

    struct node *p, *q, *head;
    p = head = NULL;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    // Reading tokens from the file and creating a linked list
    while((flag = read(fd, &read_char, 1)) > 0) {
        token = strtok(&read_char, s);
        while (token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            strcpy(q->data, token);
            q->next = NULL;

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

    // Printing the token list
    p = head;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}
