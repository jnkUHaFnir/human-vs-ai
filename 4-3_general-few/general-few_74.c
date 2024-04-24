#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char data;
    struct node *next;
};

int main(int argc, char const *argv[])
{
    const char s[2] = ",";
    char buffer[BUFSIZE]; // Buffer to read file content
    char *token;

    struct node *head = NULL;
    struct node *p = NULL, *q = NULL;

    int fd, flag;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        perror("Error opening file");
        return -1;
    }

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, buffer, BUFSIZE)) > 0)
    {
        token = strtok(buffer, s);

        while(token != NULL)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = *token;
            q->next = NULL;

            if (head == NULL) {
                head = q;
                p = q;
            } else {
                p->next = q;
                p = q;
            }

            token = strtok(NULL, s);
        }
    }

    p = head;
    while(p != NULL)
    {
        printf("%c\n", p->data);
        p = p->next;
    }

    // Free the allocated nodes
    p = head;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }

    close(fd);

    return 0;
}
