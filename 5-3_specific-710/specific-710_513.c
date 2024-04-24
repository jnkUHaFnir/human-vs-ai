queue_t queue_empty() {
    queue_t queue = NULL;
    queue = calloc (1, sizeof (struct _queue_t));
    assert(queue != NULL);

    queue->array = (u32 *) calloc(100, sizeof(u32));
    queue->FirstElem = 0;
    queue->LastElem = 0;
    queue->memory_allocated = 100;
    queue->Size = 0;

    return queue;
}

int main() {

    queue_t queue = NULL;
    queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {

        if (queue->memory_allocated == queue->Size) {
            u32 new_memory = queue->memory_allocated + 100;
            queue->array = (u32 *) realloc(queue->array, new_memory * sizeof(u32));
            if(queue->array == NULL) {
                // Handle error reallocating memory
                exit(EXIT_FAILURE);
            }
            queue->memory_allocated = new_memory;
        }

        queue->LastElem += 1;
        queue->array[queue->LastElem] = i;
        queue->Size += 1;
    }

    return 0;
}
