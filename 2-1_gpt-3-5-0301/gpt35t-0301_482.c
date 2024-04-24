int j = 0;
while (set_a != NULL) {
    if (set_a->my_data != NULL) {
        printf("No: %d, Var: %s\n", j++, set_a->my_data);
    }
    node_t *set_c = set_a;
    set_a = set_a->next_it;
    free(set_c);
    set_c = NULL;
}

j = 0;
while (set_b != NULL) {
    if (set_b->my_data != NULL) {
        printf("No: %d, Var: %s\n", j++, set_b->my_data);
    }
    node_t *set_c = set_b;
    set_b = set_b->next_it;
    free(set_c);
    set_c = NULL;
}
