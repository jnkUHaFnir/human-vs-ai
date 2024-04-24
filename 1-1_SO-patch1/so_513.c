        if (queue->memory_allocated == queue->Size) {
          int new_size = queue->memory_allocated + 100; // increment first
          u32* new_array = (u32 *) realloc(queue->array, new_size * sizeof(u32));
          if (new_array) { // update only if realloc() returns a valid address.
            queue->memory_allocated = new_size;
            queue->array = new_array;
          } else {
            // do something in react
          }
        }