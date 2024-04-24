int* entity_indexes = NULL; // initialize pointer to NULL
int num_entities = 0; // initialize number of entities to 0

// when you want to add a new entity index to the array:
num_entities++;
entity_indexes = (int*)realloc(entity_indexes, num_entities * sizeof(int));
entity_indexes[num_entities-1] = new_entity_index;

// when you are finished with the array:
free(entity_indexes);
