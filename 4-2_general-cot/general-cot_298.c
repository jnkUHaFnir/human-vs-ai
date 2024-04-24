#include <stdio.h>
#include <stdlib.h>

// Function to add an entity to the index array
void add_entity(int** index_array, int* num_entities, int entity_id) {
    (*num_entities)++;
    *index_array = (int*)realloc(*index_array, *num_entities * sizeof(int));
    (*index_array)[*num_entities - 1] = entity_id;
}

// Function to process entities in the index array
void process_entities(int* index_array, int num_entities) {
    for (int i = 0; i < num_entities; i++) {
        printf("Entity ID: %d\n", index_array[i]);
    }
    // Additional processing code here
}

int main() {
    int* entity_index = NULL;
    int num_entities = 0;

    // Example of adding entities to the index array
    add_entity(&entity_index, &num_entities, 1);
    add_entity(&entity_index, &num_entities, 2);
    add_entity(&entity_index, &num_entities, 3);

    // Process entities
    process_entities(entity_index, num_entities);

    // Free memory allocated for index array
    free(entity_index);

    return 0;
}
