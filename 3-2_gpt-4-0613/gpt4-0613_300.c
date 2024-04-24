void add_entity(int num_entities) {
    int entities[num_entities];
    // Your code here
}
void add_entity(int num_entities) {
    int* entities = malloc(num_entities * sizeof(int));
    if(entities == NULL) {
        // handle the error
        return;
    }

    // Your code here

    free(entities); // very important! don't forget to free the memory
}
