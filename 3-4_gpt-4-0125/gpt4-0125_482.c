#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

node_t* read_file_to_linked_list(FILE *file) {
    char my_buffer[256];
    int my_ch, i = 0;
    node_t *head = NULL, *current = NULL;

    while ((my_ch = fgetc(file)) != EOF) {
        if (my_ch != '\n' && i < 255) { // Assuming you want to read till end-of-line or buffer capacity
            my_buffer[i++] = my_ch;
        } else {
            my_buffer[i] = '\0'; // Null terminate the string
            // Create a new node
            node_t *new_node = malloc(sizeof(node_t));
            if (!new_node) {
                perror("Failed to allocate memory for new node");
                exit(EXIT_FAILURE);
            }
            strcpy(new_node->my_data, my_buffer);
            new_node->next_it = NULL;

            if (!head) {
                head = new_node;
            } else {
                current->next_it = new_node;
            }
            current = new_node;
            i = 0; // Reset buffer index
        }
    }
    // For the case when the file does not end with a newline
    if(i > 0) {
        my_buffer[i] = '\0'; // Null-terminate the string
        node_t *new_node = malloc(sizeof(node_t));
        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = NULL;
        if (!head) {
            head = new_node;
        } else {
            current->next_it = new_node;
        }
    }

    return head;
}

void free_linked_list(node_t* head) {
    while (head) {
        node_t *temp = head;
        head = head->next_it;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Requiring 2 input files!\n");
        return EXIT_FAILURE;
    }

    FILE *my_f = fopen(argv[1], "r"); // First text file to read
    FILE *my_s = fopen(argv[2], "r"); // Second text file to read

    if (!my_f || !my_s) {
        fprintf(stderr, "Cannot read from files\n");
        return EXIT_FAILURE;
    }

    node_t *set_a = read_file_to_linked_list(my_f);
    node_t *set_b = read_file_to_linked_list(my_s);

    fclose(my_f);
    fclose(my_s);
    
    // Example of how to free and print - modify as needed
    node_t *temp;
    int j = 1;
    printf("First File Contents:\n");
    for (temp = set_a; temp != NULL; temp = temp->next_it, j++) {
        printf("No: %d, Var: %s\n", j, temp->my_data);
    }
    free_linked_list(set_a);
    
    j = 1;
    printf("Second File Contents:\n");
    for (temp = set_b; temp != NULL; temp = temp->next_it, j++) {
        printf("No: %d, Var: %s\n", j, temp->my_data);
    }
    free_linked_list(set_b);

    return 0;
}
