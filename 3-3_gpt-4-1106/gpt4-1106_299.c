int max_entities = ...;  // Maximum possible entities, depending on your use case
int* entity_indices = malloc(max_entities * sizeof(int));
if (entity_indices == NULL) {
    // Handle allocation failure (usually by exiting the function/program)
}

int num_entities = 0;  // To keep track of the actual number of entities added
void add_entity(int* entity_array, int* num_entities, int entity_index) {
    if (*num_entities < max_entities) {
        entity_array[*num_entities] = entity_index;
        (*num_entities)++;
    } else {
        // Handle "array full" scenario (e.g., by reallocating or ignoring extra entities)
    }
}
process_entities(entity_indices, num_entities);

// After you're done with the array, free the memory to prevent leaks
free(entity_indices);
// If the array is not large enough, you may resize it with realloc
int* temp = realloc(entity_indices, new_max_entities * sizeof(int));
if (temp == NULL) {
    // Handle reallocation failure
    // Important: If realloc fails, the original array still needs to be freed
    free(entity_indices);
} else {
    entity_indices = temp;
}
