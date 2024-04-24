queue->array = (u32 *) realloc (queue->array, (queue->memory_allocated + 100)*sizeof(u32));
int main() {

    queue_t queue = NULL;
    queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {

        if (queue->memory_allocated == queue->Size) {
            queue->array = (u32 *) realloc (queue->array, (queue->memory_allocated + 100)*sizeof(u32));
            queue->memory_allocated += 100;
        }

        queue->LastElem += 1;
        queue->array[queue->LastElem] = i;
        queue->Size += 1;
    }

    return(0);
}
