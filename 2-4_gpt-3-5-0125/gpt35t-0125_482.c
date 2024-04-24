#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    FILE *my_f;
    FILE *my_s;
    
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <input_file_1> <input_file_2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    node_t *set_a = NULL;
    node_t *current_a = NULL;
    node_t *set_b = NULL;
    node_t *current_b = NULL;
    
    char my_buffer[256];

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Cannot read from %s or %s\n", argv[1], argv[2]);
        exit(EXIT_FAILURE);
    }

    // Read from first file
    while (fscanf(my_f, "%255s", my_buffer) == 1) {
        if (set_a == NULL) {
            set_a = malloc(sizeof(node_t));
            current_a = set_a;
        } else {
            current_a->next_it = malloc(sizeof(node_t));
            current_a = current_a->next_it;
        }
        strcpy(current_a->my_data, my_buffer);
    }

    fclose(my_f);

    // Read from second file
    while (fscanf(my_s, "%255s", my_buffer) == 1) {
        if (set_b == NULL) {
            set_b = malloc(sizeof(node_t));
            current_b = set_b;
        } else {
            current_b->next_it = malloc(sizeof(node_t));
            current_b = current_b->next_it;
        }
        strcpy(current_b->my_data, my_buffer);
    }

    fclose(my_s);

    current_a = set_a;
    int j = 0;
    while (current_a != NULL) {
        printf("No: %d, Var: %s\n", j++, current_a->my_data);
        node_t *temp = current_a;
        current_a = current_a->next_it;
        free(temp);
    }

    current_b = set_b;
    j = 0;
    while (current_b != NULL) {
        printf("No: %d, Var: %s\n", j++, current_b->my_data);
        node_t *temp = current_b;
        current_b = current_b->next_it;
        free(temp);
    }

    return 0;
}
