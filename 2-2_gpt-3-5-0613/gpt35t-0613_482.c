#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {  
    /*
    if (argc != 3) {
        fprintf(stderr, "Require 2 input file names!\n");
        exit(EXIT_FAILURE);
    }
    */

    FILE *my_f;
    FILE *my_s;
    bool mybool = true;
    int my_ch;
    char my_buffer[256];
    bool check_all = true;

    node_t *set_a = malloc(sizeof(node_t));
    node_t *current_a = set_a;
    set_a->next_it = NULL;

    node_t *set_b = malloc(sizeof(node_t));
    node_t *current_b = set_b;
    set_b->next_it = NULL;

    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f != NULL && my_s != NULL) {
        while (mybool && check_all && fgets(my_buffer, sizeof(my_buffer), my_f)) {
            strcpy(current_a->my_data, my_buffer);
            if (feof(my_f)) {
                mybool = false;
            } else {
                current_a->next_it = malloc(sizeof(node_t));
                current_a = current_a->next_it;
                current_a->next_it = NULL;
            }
        }
        printf("First File Copy Done!\n");
        while (!feof(my_s) && fgets(my_buffer, sizeof(my_buffer), my_s)) {
            strcpy(current_b->my_data, my_buffer);
            if (feof(my_s)) {
                check_all = false;
            } else {
                current_b->next_it = malloc(sizeof(node_t));
                current_b = current_b->next_it;
                current_b->next_it = NULL;
            }
        }
        printf("Second File Copy Done!\n");
    } else {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
    }

    int j = 0;
    current_a = set_a;
    while (current_a != NULL) {
        printf("No: %d, Var: %s", j++, current_a->my_data);
        node_t *set_c = current_a;
        current_a = current_a->next_it;
        free(set_c);
    }

    j = 0;
    current_b = set_b;
    while (current_b != NULL) {
        printf("No: %d, Var: %s", j++, current_b->my_data);
        node_t *set_c = current_b;
        current_b = current_b->next_it;
        free(set_c);
    }
    
    return 0;
}
