#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 255

typedef struct linked_list {
    char my_data[MAX_STRING_LENGTH + 1]; // +1 for null terminator
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file_1> <input_file_2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_f;
    FILE *my_s;
    char my_buffer[MAX_STRING_LENGTH + 1]; // +1 for null terminator

    node_t *set_a = NULL;
    node_t *set_b = NULL;

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Cannot read from %s or %s\n", argv[1], argv[2]);
        exit(EXIT_FAILURE);
    }

    // Load data from the first file
    node_t **current_a = &set_a;
    while (fgets(my_buffer, sizeof(my_buffer), my_f) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = NULL;
        *current_a = new_node;
        current_a = &((*current_a)->next_it);
    }
    fclose(my_f);

    // Load data from the second file
    node_t **current_b = &set_b;
    while (fgets(my_buffer, sizeof(my_buffer), my_s) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(new_node->my_data, my_buffer);
        new_node->next_it = NULL;
        *current_b = new_node;
        current_b = &((*current_b)->next_it);
    }
    fclose(my_s);

    // Print and free the data in set_a
    int j = 0;
    node_t *current_node = set_a;
    while (current_node != NULL) {
        printf("Set A - No: %d, Var: %s", j++, current_node->my_data);
        node_t *temp = current_node;
        current_node = current_node->next_it;
        free(temp);
    }

    // Print and free the data in set_b
    j = 0;
    current_node = set_b;
    while (current_node != NULL) {
        printf("Set B - No: %d, Var: %s", j++, current_node->my_data);
        node_t *temp = current_node;
        current_node = current_node->next_it;
        free(temp);
    }

    return 0;
}
