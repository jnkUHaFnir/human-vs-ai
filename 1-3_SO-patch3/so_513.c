        if (queue->memory_allocated == queue->Size) {
          queue->memory_allocated += 100; // increment first
          queue->array = (u32 *) realloc(
              queue->array, queue->memory_allocated * sizeof(u32));
        }