#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint64_t u64;

typedef struct _queue_t *queue_t;

struct _queue_t {
    u32 *array; // Array to store queue elements
    u32 FirstElem; // First element of the queue
    u32 LastElem; // Last element of the queue
    u32 memory_allocated; // To track memory allocation
    u32 Size; // Current number of elements in the queue
};

queue_t queue_empty() {
    queue_t queue = calloc(1, sizeof(struct _queue_t));
    assert(queue != NULL);

    queue->array = calloc(100, sizeof(u32));
    queue->FirstElem = 0;
    queue->LastElem = 0;
    queue->memory_allocated = 100;
    queue->Size = 0;

    return queue;
}

void queue_enqueue(queue_t queue, u32 element) {
    if (queue->memory_allocated == queue->Size) {
        queue->memory_allocated *= 2; // Double the memory allocation
        queue->array = realloc(queue->array, queue->memory_allocated * sizeof(u32));
    }

    queue->LastElem += 1;
    queue->array[queue->LastElem] = element;
    queue->Size += 1;
}

int main() {
    queue_t queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {
        queue_enqueue(queue, i);
    }

    free(queue->array);
    free(queue);

    return 0;
}
