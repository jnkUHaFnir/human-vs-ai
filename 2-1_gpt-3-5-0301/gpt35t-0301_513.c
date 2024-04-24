if (queue->memory_allocated == queue->Size) {
    queue->array = (u32 *) realloc (queue->array, (queue->memory_allocated + 100)*sizeof(u32));
    queue->memory_allocated += 100;
}
