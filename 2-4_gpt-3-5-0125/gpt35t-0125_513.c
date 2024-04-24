if (queue->memory_allocated == queue->Size) {
    queue->array = (u32 *) realloc (queue->array, (queue->memory_allocated + 100) * sizeof(u32));
    queue->memory_allocated += 100;
}
``` 

With this change, the realloc() call will resize the array dynamically based on the number of elements in the queue, and the error should be resolved.
