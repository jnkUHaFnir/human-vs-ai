#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

node_t *read_file_to_list(FILE *file) {
    node_t *head = NULL;
    node_t *current = NULL;

    while (!feof(file)) {
        char my_buffer[256];
        if (fgets(my_buffer, 256, file)) {
            node_t *new_node = malloc(sizeof(node_t));
            strcpy(new_node->my_data, my_buffer);
            new_node->next_it = NULL;

            if (!head) {
                head = new_node;
                current = head;
            } else {
                current->next_it = new_node;
                current = new_node;
            }
        }
    }

    return head;
}

void free_list(node_t *head) {
    node_t *temp;
    while (head) {
        temp = head;
        head = head->next_it;
        free(temp);
    }
}

void print_and_free_list(node_t *head) {
    int j = 0;
    while (head) {
        printf("No: %d, Var: %s", j++, head->my_data);
        node_t *next_node = head->next_it;
        free(head);
        head = next_node;
    }
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Requiring 2 input file names to start!\n");
        exit(EXIT_FAILURE);
    }

    FILE *my_s, *my_f;
    my_f = fopen(argv[1], "r"); // first textfile to read
    my_s = fopen(argv[2], "r"); // second textfile to read

    if (my_f != NULL && my_s != NULL) {
        node_t *set_a = read_file_to_list(my_f);
        node_t *set_b = read_file_to_list(my_s);

        fclose(my_f);
        fclose(my_s);

        print_and_free_list(set_a);
        print_and_free_list(set_b);

    } else {
        fprintf(stderr, "Cannot read from %s and/or %s\n", argv[1], argv[2]);
        if (my_f) fclose(my_f);
        if (my_s) fclose(my_s);
    }

    return 0;
}
