// File loading into a list of string
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct node {
    char* line;
    struct node* next;
};

typedef struct node node;

int main(int argc, char* argv[]) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    node head = {NULL, NULL}, *last = &head;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file\n");
        return -1;
    }

    while (fgets(line, sizeof line, file) != NULL) {
        node *n = malloc(sizeof(node));
        n->line = strdup(line);
        n->next = NULL;
        
        // handles the first node
        if (head.line == NULL) {
            head.line = n->line;
            head.next = n->next;
            last = &head;
        } else {
            last->next = n;
            last = n;
        }
    }

    fclose(file);

    // printing
    node *n = &head;
    while (n != NULL) {
        printf("%s", n->line);
        n = n->next;
    }

    // Cleanup
    n = head.next;
    while (n != NULL) {
        node* tmp = n;
        n = n->next;
        free(tmp->line);
        free(tmp);
    }

    return 0;
}
