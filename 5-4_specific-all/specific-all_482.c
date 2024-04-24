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
    char my_buffer[256];
    
    node_t *set_a = NULL;
    node_t *set_b = NULL;
    
    my_f = fopen(argv[1], "r");
    my_s = fopen(argv[2], "r");

    if (my_f != NULL && my_s != NULL) {
        int i = 0;
        while (fgets(my_buffer, sizeof(my_buffer), my_f) != NULL) {
            node_t *new_node = malloc(sizeof(node_t));
            new_node->next_it = NULL;
            strcpy(new_node->my_data, my_buffer);
            
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

        printf("First File Copy Done!\n");

        int j = 0;
        node_t *temp = set_a;
        while (temp != NULL) {
            printf("No: %d, Var: %s", j++, temp->my_data);
            temp = temp->next_it;
        }
        
        // Repeat the same process for the second file (set_b)

        // Free the memory for set_a

    } else {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
    }

    return 0;
}
