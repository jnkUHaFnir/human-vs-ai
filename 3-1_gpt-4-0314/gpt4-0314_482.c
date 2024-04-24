#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct linked_list {
    char my_data[256];
    struct linked_list *next_it;
} node_t;

int main(int argc, char *argv[]) {
    FILE *my_s;
    FILE *my_f;
    bool mybool = true;
    int my_ch; // our char to read
    char my_buffer[256];
    bool check_all = true;

    node_t *set_a = malloc(sizeof(node_t));
    node_t *set_b = malloc(sizeof(node_t));
    my_f = fopen(argv[1], "r"); // first textfile to read
    my_s = fopen(argv[2], "r"); // second textfile to read

    if (my_f != NULL && my_s != NULL) {
        while (mybool != false && check_all != false) {
            int i = 0;
            while ((my_ch = fgetc(my_f)) != '\n' && my_ch != EOF) {
                my_buffer[i++] = my_ch;
            }
            my_buffer[i] = '\0';
            strcpy(set_a->my_data, my_buffer);
            if (feof(my_f)) {
                mybool = false;
            } else {
                set_a->next_it = malloc(sizeof(node_t));
                set_a = set_a->next_it;
            }
        }
        mybool = false;
        printf("First File Copy Done!\n");
        while (mybool != true && check_all != false) {
            int i = 0;
            while ((my_ch = fgetc(my_s)) != '\n' && my_ch != EOF) {
                my_buffer[i++] = my_ch;
            }
            my_buffer[i] = '\0';
            strcpy(set_b->my_data, my_buffer);
            if (feof(my_s)) {
                check_all = false;
            } else {
                set_b->next_it = malloc(sizeof(node_t));
                set_b = set_b->next_it;
            }
        }
        printf("Second File Copy Done!\n");
        fclose(my_f);
        fclose(my_s);
    } else {
        fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
    }

    while (set_a != NULL) {
        int j = 0;
        printf("No: %d, Var: %s\n", j++, set_a->my_data);
        node_t *set_c = set_a;
        set_a = set_a->next_it;
        free(set_c);
    }
    while (set_b != NULL) {
        int j = 0;
        printf("No: %d, Var: %s\n", j++, set_b->my_data);
        node_t *set_c = set_b;
        set_b = set_b->next_it;
        free(set_c);
    }
    return 0;
}
