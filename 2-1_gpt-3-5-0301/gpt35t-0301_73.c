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
    char *token;

    printf("file name: %s\n", argv[1]);
    int fd, flag;

    char read_char;

    struct node *p = NULL, *q = NULL, *head = NULL;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    printf("\nREAD FROM FILE.\n");

    while((flag = read(fd, &read_char, 1)) > 0) {
        if(isspace(read_char)) { // skip white space
            continue;
        }

        if(q == NULL) { // create the first node
            q = (struct node *)malloc(sizeof(struct node));
            q->data = NULL;
            q->next = NULL; 
            head = q;
            p = q;
        }

        if(read_char == ',') {
            q->data = (char*) malloc(strlen(token)+1);
            strcpy(q->data, token);

            q->next = (struct node *) malloc(sizeof(struct node));
            q->next->data = NULL;
            q->next->next = NULL;

            p = q;
            q = q->next;
        } else {
            if(token == NULL) {
                token = &read_char;
            } else { 
                size_t len = strlen(token);
                char* temp = realloc(token, len+2);

                if(temp) {
                    token = temp;
                    token[len] = read_char; 
                    token[len+1] = '\0'; 
                } else {
                    free(token);
                }
            }
        }
    }

    if(q && token) { // handle last token
        q->data = (char*) malloc(strlen(token)+1);
        strcpy(q->data, token);
    } else if(token) { // handle file with only one token
        q = (struct node *)malloc(sizeof(struct node));
        q->data = (char*) malloc(strlen(token)+1);
        strcpy(q->data, token);
        head = q;
        p = q;
        q->next = NULL;
    }

    p = head;
    while(p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }

    // clean up memory
    p = head;
    while(p != NULL) {
        q = p;
        p = p->next;
        free(q->data);
        free(q);
    }

    close(fd);

    return 0;
}
