// inside the first while loop
my_buffer[i] = '\0'; // add null terminator
strcpy(set_a->my_data, my_buffer);

// inside the second while loop
my_buffer[i] = '\0'; // add null terminator
strcpy(set_b->my_data, my_buffer);

// after the while loop for reading files
set_a->next_it = NULL; // null-terminate the linked list
set_b->next_it = NULL; // null-terminate the linked list

// before freeing memory
while (set_a != NULL) {
    printf("Var: %s\n", set_a->my_data);
    node_t *set_c = set_a;
    set_a = set_a->next_it;
    free(set_c);
}

while (set_b != NULL) {
    printf("Var: %s\n", set_b->my_data);
    node_t *set_c = set_b;
    set_b = set_b->next_it;
    free(set_c);
}
