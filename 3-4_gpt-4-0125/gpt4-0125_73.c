#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

struct node {
    char data;            // Storing character by character
    struct node *next;
};

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    struct node *head = NULL, *tail = NULL;

    char read_char;
    while (read(fd, &read_char, 1) > 0) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = read_char;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Print characters
    struct node *current = head;
    while (current != NULL) {
        printf("%c", current->data);
        struct node *temp = current;
        current = current->next;
        free(temp);  // Free memory as we go
    }

    close(fd);
    return 0;
}
