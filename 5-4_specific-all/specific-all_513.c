int main() {

    queue_t queue = NULL;
    queue = queue_empty();

    u32 increment = 100;  // Define the increment size for memory allocation

    for (u32 i = 0; i < 1000; i++) {

        if (queue->memory_allocated == queue->Size) {
            queue->array = (u32 *) realloc(queue->array, (queue->memory_allocated + increment) * sizeof(u32));
            if (queue->array == NULL) {
                // Check if realloc failed
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
            queue->memory_allocated += increment;
        }

        queue->LastElem += 1;
        queue->array[queue->LastElem] = i;
        queue->Size += 1;
    }

    return 0;
}
