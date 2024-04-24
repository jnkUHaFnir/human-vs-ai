    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    typedef struct linked_list {
        char *data;
        struct linked_list *next_it;
    } node_t;
	int main(int argc, char *argv[]) {	
		/*
		if (argc != 4) {
			fprintf(stderr, "Requiring 2 input 1 output file name to start!\n");
			exit(EXIT_FAILURE);
		}*/
	
		FILE *my_s;
		FILE *my_f;
		// FILE *my_o;
		bool mybool = true;
		int c; // our char to read
		char buffer[256];
		bool check_all = true;
	
		node_t *set_a = NULL;
        node_t **tail_a = &set_a;
		node_t *set_b = NULL;
        node_t **tail_b = &set_b;
		my_f = fopen(argv[1], "r"); // first textfile to read
		my_s = fopen(argv[2], "r"); // second textfile to read
	
		if (my_f != NULL && my_s != NULL) {
            size_t i = 0;
			while ((c = fgetc(my_f)) != EOF) {
                if (c == '\n' && i > 0) {
                    buffer[i] = '\0';
                    /* allocate a new node */
                    *tail_a = malloc(sizeof(**tailp));
                    (*tail_a)->next = NULL;
                    (*tail_a)->data = strdup(buffer);
                    tail_a = &(*tail_a)->next;
                    i = 0;
                } else {
                    if (i < sizeof(buffer) - 1) {
                        buffer[i++] = c;
                    }
                }
            }
			printf("First File Copy Done!\n");
            size_t i = 0;
			while ((c = fgetc(my_s)) != EOF) {
                if (c == '\n' && i > 0) {
                    buffer[i] = '\0';
                    /* allocate a new node */
                    *tail_b = malloc(sizeof(**tail_b));
                    (*tail_b)->next = NULL;
                    (*tail_b)->data = strdup(buffer);
                    tail_b = &(*tail_b)->next;
                    i = 0;
                } else {
                    if (i < sizeof(buffer) - 1) {
                        buffer[i++] = c;
                    }
                }
            }
			printf("Second File Copy Done!\n");
		} else {
			fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
		}
	
        int j;
        node_t *np, *next;
		for (np = set_a, j = 0; np != NULL; np = next) {
			printf("No: %d, Var: %s", j++, np->data);
			next = np->next_it;
            free(np->data);
			free(np);
		}
		for (np = set_b, j = 0; np != NULL; np = next) {
			printf("No: %d, Var: %s", j++, np->data);
			next = np->next_it;
            free(np->data);
			free(np);
		}
		return 0;
	}