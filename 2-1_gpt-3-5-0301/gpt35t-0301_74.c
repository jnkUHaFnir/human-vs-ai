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

int main(int argc, char const *argv[])
{
    const char s[2] = ",";
    char *token;
    int fd, flag;
    char buffer[BUFSIZE];

    struct node *p, *q, *head;
    int i, n;

    head = NULL;
    p = NULL;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        return -1;
    }

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, buffer, BUFSIZE)) > 0)
    {
        buffer[flag] = '\0'; // null-terminate buffer

        token = strtok(buffer, s);

        while(token != NULL)
        {
            // create a node and point the value to the node
            q = (struct node *)malloc(sizeof(struct node));
            if(q == NULL)
            {
                perror("malloc failed");
                exit(EXIT_FAILURE);
            }

            q->data = *token;
            q->next = NULL;

            if(head == NULL)
            {
                // first element
                head = q;
                p = q;
            }
            else
            {
                p->next = q;
                p = p->next;
            }

            token = strtok(NULL, s);
        }
    }

    p = head;
    while(p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }

    // free memory
    p = head;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}
