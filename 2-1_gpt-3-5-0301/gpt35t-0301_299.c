int* indexes = NULL;
int num_entities = 0;
int max_entities = 10; // initial size of index array

indexes = (int*) malloc(max_entities * sizeof(int)); //allocating memory

//add an entity to the list
if(num_entities < max_entities){
  indexes[num_entities++] = entity_index;
}
else{
  max_entities *= 2 //double the size of the array
  indexes = (int*) realloc(indexes, max_entities * sizeof(int)); //reallocate memory
  indexes[num_entities++] = entity_index;
}
