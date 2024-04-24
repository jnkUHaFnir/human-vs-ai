queue->array = (u32 *) realloc (queue->array, 100*sizeof(u32));
queue->array = (u32 *) realloc (queue->array, (queue->memory_allocated + 100) * sizeof(u32));
queue->array[queue->LastElem] = i;
queue->LastElem += 1;
int main() {
    queue_t queue = NULL;
    queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {
        if (queue->memory_allocated == queue->Size) {
            u32 *new_array = (u32 *) realloc(queue->array, (queue->memory_allocated + 100) * sizeof(u32));
            if (new_array == NULL) {
                // Handle realloc error
            } else {
                queue->array = new_array;
                queue->memory_allocated += 100;
            }
        }
        queue->array[queue->LastElem] = i;
        queue->LastElem += 1;
        queue->Size += 1;
    }

    // Don't forget to free memory allocated with calloc and realloc before your program exits
    free(queue->array);
    free(queue);

    return(0);
}
