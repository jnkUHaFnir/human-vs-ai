#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint64_t u64;

typedef struct _queue_t {
    u32 *array;
    u32 FirstElem;
    u32 LastElem;
    u32 memory_allocated;
    u32 Size;
} queue_t;

queue_t* queue_empty() {
    queue_t* queue = (queue_t*)calloc(1, sizeof(queue_t));
    assert(queue != NULL);

    queue->array = (u32*)calloc(100, sizeof(u32));
    assert(queue->array != NULL);

    queue->FirstElem = 0;
    queue->LastElem = 0;
    queue->memory_allocated = 100;
    queue->Size = 0;

    return queue;
}

int main() {
    queue_t* queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {
        if (queue->memory_allocated == queue->Size) {
            queue->array = (u32*)realloc(queue->array, (queue->memory_allocated + 100) * sizeof(u32));
            assert(queue->array != NULL); // Check if realloc was successful

            queue->memory_allocated += 100;
        }

        queue->LastElem++;
        queue->array[queue->LastElem] = i;
        queue->Size++;
    }

    // Print elements in the queue for demonstration
    for (u32 i = queue->FirstElem + 1; i <= queue->LastElem; i++) {
        printf("%u ", queue->array[i]);
    }
    printf("\n");

    // Cleanup
    free(queue->array);
    free(queue);

    return 0;
}
