#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 255

typedef struct linked_list {
    char my_data[MAX_LEN + 1]; // +1 for NULL terminator
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file1> <input_file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *my_f;
    FILE *my_s;
    char my_buffer[MAX_LEN + 1]; // Buffer to read strings
    node_t *set_a = NULL;
    node_t *set_b = NULL;

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f == NULL || my_s == NULL) {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
        return EXIT_FAILURE;
    }

    // Reading from first file
    while (fgets(my_buffer, MAX_LEN, my_f) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        strcpy(new_node->my_data, my_buffer);
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
    fclose(my_f);

    // Reading from second file
    while (fgets(my_buffer, MAX_LEN, my_s) != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        strcpy(new_node->my_data, my_buffer);
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
    fclose(my_s);

    // Print and free memory for set_a
    node_t *curr = set_a;
    while (curr != NULL) {
        printf("Var (A): %s", curr->my_data);
        node_t *temp = curr;
        curr = curr->next_it;
        free(temp);
    }

    // Print and free memory for set_b
    curr = set_b;
    while (curr != NULL) {
        printf("Var (B): %s", curr->my_data);
        node_t *temp = curr;
        curr = curr->next_it;
        free(temp);
    }

    return 0;
}
