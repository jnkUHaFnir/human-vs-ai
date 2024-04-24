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

    q = head = (struct node *)malloc(sizeof(struct node));
    p = head;

    while((flag = read(fd, &read_char, 1))> 0) {
        if (read_char != ',') {
            buffer[strlen(buffer)] = read_char;
        } else {
            q->data = strdup(buffer);
            q->next = (struct node *)malloc(sizeof(struct node));
            q = q->next;
            memset(buffer, 0, BUFSIZE);
        }
    }

    p = head;
    while(p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    return 0;
}
