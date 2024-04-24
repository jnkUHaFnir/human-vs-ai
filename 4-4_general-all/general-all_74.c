#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000

struct node {
    char *data; // Change data type to char*
    struct node *next;
};

int main(int argc, char const *argv[])
{
    const char s[2] = ",";
    char *token;

    int fd, flag;
    char buffer[BUFSIZE]; // Change buffer to array
    struct node *p, *q, *head;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return -1;
    }

    head = NULL; // Initialize head pointer

    printf("\nREAD FROM FILE.\n");

    while ((flag = read(fd, buffer, BUFSIZE)) > 0)
    {
        buffer[flag] = '\0'; // Null-terminate the buffer to use with strtok
        token = strtok(buffer, s);

        while (token != NULL)
        {
            q = (struct node *)malloc(sizeof(struct node));
            q->data = strdup(token); // Copy token to dynamically allocated memory

            q->next = NULL;

            if (head == NULL)
            {
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
    while (p)
    {
        printf("%s\n", p->data);
        p = p->next;
    }

    // Free allocated memory
    p = head;
    while (p)
    {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }

    close(fd);

    return 0;
}
