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

    int fd, flag;
    char read_char;
    struct node *p, *q, *head;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        return -1;
    }

    head = (struct node *)malloc(sizeof(struct node));
    head->data = NULL;
    head->next = NULL;
    p = head;

    while((flag = read(fd, buffer, BUFSIZE)) > 0) {
        buffer[flag] = '\0'; // Null-terminate the buffer
        char *token = strtok(buffer, s);
        
        while(token != NULL) {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = strdup(token);
            q->next = NULL;
            
            p->next = q;
            p = p->next;

            token = strtok(NULL, s);
        }
    }

    p = head->next; // Skip the dummy head node
    while(p) {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}
