    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    typedef struct linked_list {
        char *data;
        struct linked_list *next;
    } node_t;
    node_t *load_lines(const char *filename) {
        node_t *head = NULL;
        FILE *fp = fopen(filename, "r");
        if (fp != NULL) {
		    char buffer[256];
            size_t i = 0;
            int c;
            node_t **tailp = &head;
			while ((c = fgetc(fp)) != EOF) {
                if (c == '\n' && i > 0) {
                    buffer[i] = '\0';
                    /* allocate a new node */
                    *tailp = malloc(sizeof(**tailp));
                    (*tailp)->next = NULL;
                    (*tailp)->data = strdup(buffer);
                    tailp = &(*tailp)->next;
                    i = 0;
                } else {
                    if (i < sizeof(buffer) - 1) {
                        buffer[i++] = c;
                    }
                }
            }
            fclose(fp);
        }
        return head;
    }
    void print_word(node_t *np) {
        int j = 0;
		while (np != NULL) {
			printf("No: %d, Var: %s", j++, np->data);
            np = np->next;
		}
    }
    void free_words(node_t *np) {
		while (np != NULL) {
			node_t *next = np->next;
            free(np->data);
			free(np);
            np = next;
		}
    }
    
	int main(int argc, char *argv[]) {	
		/*
		if (argc != 4) {
			fprintf(stderr, "Requiring 2 input 1 output file name to start!\n");
			exit(EXIT_FAILURE);
		}*/
        node_t *set_a, *set_b;
        if ((set_a = load_words(argv[1])) != NULL) {
            printf("First File Copy Done!\n");
        }
		if ((set_b = load_words(argv[2])) != NULL) {
        	printf("Second File Copy Done!\n");
        }
        if (!set_a && !set_b) {
			fprintf(stderr, "Cannot read from %s and %s\n", argv[1], argv[2]);
        }
        print_words(set_a);
        free_words(set_a);
        print_words(set_b);
        free_words(set_b);
		return 0;
	}