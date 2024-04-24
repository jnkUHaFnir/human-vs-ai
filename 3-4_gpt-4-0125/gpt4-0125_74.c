#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct node {
    char *data;
    struct node *next;
};

struct node* add_to_list(struct node* head, char *data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = strdup(data);  // Make a copy of the data
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return head;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    printf("File name: %s\n", argv[1]);
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    char buffer[1024];  // Adjust buffer size as needed
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("Error reading file");
        close(fd);
        return -1;
    }

    // Null-terminate the buffer
    buffer[bytes_read] = '\0';

    // Tokenize and build list
    struct node* head = NULL;
    char delimiter[] = ",";
    char *token = strtok(buffer, delimiter);

    while (token != NULL) {
        head = add_to_list(head, token);
        token = strtok(NULL, delimiter);
    }

    // Print list content and free memory
    struct node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        struct node* temp = current;
        current = current->next;
        free(temp->data);  // Free the strdup'ed string
        free(temp);
    }

    close(fd);
    return 0;
}
