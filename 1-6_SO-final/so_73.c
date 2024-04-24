c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 1000
struct node {
    char *data;
    struct node *next;
};
int main(int argc, char const *argv[]) {
    if (argc != 2) {
    	printf("expected the file name as command line argument\n");
    	return -1;
    }
    
    printf("file name: %s\n", argv[1]);    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
    	return -1;
    }
    // list of token is intially empty 
    struct node *head = NULL, *last = NULL;
    printf("\nREAD FROM FILE.\n");
    
    size_t bufLen = BUFSIZE;
    char *line = malloc(bufLen);
    // read a line from the file
    while(getline(&line, &bufLen, fp) != -1)
    {
        // remove the trailing \n
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';
        // for each token in the line
        for (char *token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            // append token to list
            struct node *q = malloc(sizeof(struct node));
            q->data = strdup(token);
            q->next = NULL;
            if (last == NULL)
                head = last = q;
            else
            	last = last->next = q;
        }
    }
    for (struct node *p = head; p != NULL; p = p->next)
        printf("%s\n", p->data);
    return 0;
}