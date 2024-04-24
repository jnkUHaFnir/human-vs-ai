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
    char data;
    struct node *next;
};

int main(int argc, char const *argv[]) {

    if(argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    const char s[2] = ",";
    char read_char;
    struct node *p, *q, *head = NULL;

    int fd, flag;
    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("Error opening file");
        return -1;
    }

    while(read(fd, &read_char, 1) > 0) {
        // Check for delimiter ',' and create a new node
        if(read_char != ',') {
            if (head == NULL) {
                head = (struct node*)malloc(sizeof(struct node));
                head->data = read_char;
                head->next = NULL;
                p = head;
            } else {
                q = (struct node*)malloc(sizeof(struct node));
                q->data = read_char;
                q->next = NULL;
                p->next = q;
                p = p->next;
            }
        }
    }

    p = head;
    while(p != NULL) {
        printf("%c\n", p->data);
        p = p->next;
    }

    // Free memory by deallocating nodes
    p = head;
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    close(fd);

    return 0;
}
