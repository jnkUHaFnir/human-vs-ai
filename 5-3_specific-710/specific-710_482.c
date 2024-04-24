#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    if(argc != 3) { // Ensure correct number of arguments
        fprintf(stderr, "Usage: %s <input_file1> <input_file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_f;
    FILE *my_s;

    // Open the input files
    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Error opening input files.\n");
        exit(EXIT_FAILURE);
    }

    node_t *set_a = NULL;
    node_t *set_b = NULL;
    node_t *temp;

    char my_buffer[256];
    int ch;
    
    // Read from first file
    while (fgets(my_buffer, sizeof(my_buffer), my_f) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = NULL;

        if (set_a == NULL) {
            set_a = new_node;
        } else {
            temp = set_a;
            while (temp->next_it != NULL) {
                temp = temp->next_it;
            }
            temp->next_it = new_node;
        }
    }

    // Read from second file
    while (fgets(my_buffer, sizeof(my_buffer), my_s) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = NULL;

        if (set_b == NULL) {
            set_b = new_node;
        } else {
            temp = set_b;
            while (temp->next_it != NULL) {
                temp = temp->next_it;
            }
            temp->next_it = new_node;
        }
    }

    // Close the input files
    fclose(my_f);
    fclose(my_s);

    // Print the content of linked list set_a
    temp = set_a;
    int j = 0;
    while(temp != NULL) {
        printf("No: %d, Var: %s", j++, temp->my_data);
        temp = temp->next_it;
    }

    // Free memory allocated for set_a
    while (set_a != NULL) {
        temp = set_a;
        set_a = set_a->next_it;
        free(temp);
    }

    // Print the content of linked list set_b
    temp = set_b;
    j = 0;
    while(temp != NULL) {
        printf("No: %d, Var: %s", j++, temp->my_data);
        temp = temp->next_it;
    }

    // Free memory allocated for set_b
    while (set_b != NULL) {
        temp = set_b;
        set_b = set_b->next_it;
        free(temp);
    }

    return 0;
}
