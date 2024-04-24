#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATA_LEN 255

typedef struct linked_list {
    char my_data[MAX_DATA_LEN+1];  // +1 for null terminator
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {  // Correcting the number of required arguments
        fprintf(stderr, "Usage: %s <input_file1> <input_file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_f;
    FILE *my_s;

    node_t *set_a = NULL;
    node_t *set_b = NULL;
    
    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    // Read and create linked list for set_a
    char my_buffer[MAX_DATA_LEN+1];
    while (fgets(my_buffer, sizeof(my_buffer), my_f) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        strncpy(new_node->my_data, my_buffer, MAX_DATA_LEN);
        new_node->my_data[MAX_DATA_LEN] = '\0'; // Ensure null termination
        new_node->next_it = NULL;

        if (set_a == NULL) {
            set_a = new_node;
        } else {
            node_t *temp = set_a;
            while (temp->next_it != NULL) {
                temp = temp->next_it;
            }
            temp->next_it = new_node;
        }
    }

    // Read and create linked list for set_b
    while (fgets(my_buffer, sizeof(my_buffer), my_s) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        strncpy(new_node->my_data, my_buffer, MAX_DATA_LEN);
        new_node->my_data[MAX_DATA_LEN] = '\0'; // Ensure null termination
        new_node->next_it = NULL;

        if (set_b == NULL) {
            set_b = new_node;
        } else {
            node_t *temp = set_b;
            while (temp->next_it != NULL) {
                temp = temp->next_it;
            }
            temp->next_it = new_node;
        }
    }

    // Close files after reading
    fclose(my_f);
    fclose(my_s);

    // Print set_a
    int idx_a = 0;
    node_t *temp_a = set_a;
    while (temp_a != NULL) {
        printf("Set A - No: %d, Var: %s", idx_a++, temp_a->my_data);
        node_t *next_node = temp_a->next_it;
        free(temp_a);
        temp_a = next_node;
    }

    // Print set_b
    int idx_b = 0;
    node_t *temp_b = set_b;
    while (temp_b != NULL) {
        printf("Set B - No: %d, Var: %s", idx_b++, temp_b->my_data);
        node_t *next_node = temp_b->next_it;
        free(temp_b);
        temp_b = next_node;
    }

    return 0;
}
