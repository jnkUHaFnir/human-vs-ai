#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 256

typedef struct linked_list {
    char my_data[MAX_BUFFER_SIZE];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {  
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_f;
    FILE *my_s;

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
        exit(EXIT_FAILURE);
    }

    node_t *set_a = NULL;
    node_t *set_b = NULL;
    
    char my_buffer[MAX_BUFFER_SIZE];
    
    // Read from first file
    while (fgets(my_buffer, MAX_BUFFER_SIZE, my_f) != NULL) {
        // Allocate memory for a new node
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        // Copy data to the new node
        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = set_a;
        set_a = new_node;
    }
    
    fclose(my_f);

    // Read from second file
    while (fgets(my_buffer, MAX_BUFFER_SIZE, my_s) != NULL) {
        // Allocate memory for a new node
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        
        // Copy data to the new node
        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = set_b;
        set_b = new_node;
    }

    fclose(my_s);

    // Print contents of first file
    node_t *current = set_a;
    int j = 0;
    while (current != NULL) {
        printf("No: %d, Var: %s", j++, current->my_data);
        current = current->next_it;
    }

    // Free memory allocated for set_a
    current = set_a;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next_it;
        free(temp);
    }

    // Print contents of second file
    current = set_b;
    j = 0;
    while (current != NULL) {
        printf("No: %d, Var: %s", j++, current->my_data);
        current = current->next_it;
    }

    // Free memory allocated for set_b
    current = set_b;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next_it;
        free(temp);
    }

    return 0;
}
