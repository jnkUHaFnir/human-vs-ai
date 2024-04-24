#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file1> <input_file2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *my_f;
    FILE *my_s;

    node_t *set_a = NULL;
    node_t *set_b = NULL;

    char my_buffer[256];

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f != NULL && my_s != NULL) {
        node_t **set_current = &set_a;

        while (fgets(my_buffer, sizeof(my_buffer), my_f) != NULL) {
            node_t *new_node = malloc(sizeof(node_t));
            if (new_node == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strcpy(new_node->my_data, my_buffer);
            new_node->next_it = NULL;

            *set_current = new_node;
            set_current = &(new_node->next_it);
        }
        printf("First File Copy Done!\n");

        set_current = &set_b;

        while (fgets(my_buffer,sizeof(my_buffer), my_s) != NULL) {
            node_t *new_node = malloc(sizeof(node_t));
            if (new_node == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            strcpy(new_node->my_data, my_buffer);
            new_node->next_it = NULL;

            *set_current = new_node;
            set_current = &(new_node->next_it);
        }
        printf("Second File Copy Done!\n");

        // Print the strings
        node_t *current = set_a;
        int j = 0;
        while (current != NULL) {
            printf("No: %d, Var: %s", j++, current->my_data);
            current = current->next_it;
        }

        current = set_b;
        j = 0;
        while (current != NULL) {
            printf("No: %d, Var: %s", j++, current->my_data);
            current = current->next_it;
        }

        // Free memory
        current = set_a;
        while (current != NULL) {
            node_t *temp = current;
            current = current->next_it;
            free(temp);
        }

        current = set_b;
        while (current != NULL) {
            node_t *temp = current;
            current = current->next_it;
            free(temp);
        }
    } else {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
        exit(EXIT_FAILURE);
    }

    return 0;
}
