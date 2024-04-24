// Free memory for set_a
node_t *temp_a;
while (set_a != NULL) {
    int j = 0;
    printf("No: %d, Var: %s", j++, set_a->my_data);
    temp_a = set_a;
    set_a = set_a->next_it;
    free(temp_a);
}

// Free memory for set_b
node_t *temp_b;
while (set_b != NULL) {
    int j = 0;
    printf("No: %d, Var: %s", j++, set_b->my_data);
    temp_b = set_b;
    set_b = set_b->next_it;
    free(temp_b);
}
