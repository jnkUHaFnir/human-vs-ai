#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint64_t u64;

typedef struct _queue_t *queue_t;

struct _queue_t {
    u32 *array; // Array to store queue elements
    u32 FirstElem; // First element of the queue
    u32 LastElem; // Last element of the queue
    u32 memory_allocated; // Total memory allocated for the queue
    u32 Size; // Current size of the queue
};

queue_t queue_empty() {
    queue_t queue = (queue_t)calloc(1, sizeof(struct _queue_t));
    assert(queue != NULL);

    queue->array = (u32 *)calloc(100, sizeof(u32));
    assert(queue->array != NULL);

    queue->FirstElem = 0;
    queue->LastElem = -1; // Initialize to -1 since we increment before inserting
    queue->memory_allocated = 100;
    queue->Size = 0;

    return queue;
}

int main() {
    queue_t queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {
        if (queue->memory_allocated == queue->Size) {
            queue->array = (u32 *)realloc(queue->array, (queue->memory_allocated + 100) * sizeof(u32));
            assert(queue->array != NULL);
            queue->memory_allocated += 100;
        }

        queue->LastElem = (queue->LastElem + 1) % queue->memory_allocated; // Circular queue
        queue->array[queue->LastElem] = i;
        queue->Size += 1;
    }

    for (u32 i = 0; i < queue->Size; i++) {
        printf("%u\n", queue->array[i]);
    }

    free(queue->array);
    free(queue);

    return 0;
}
