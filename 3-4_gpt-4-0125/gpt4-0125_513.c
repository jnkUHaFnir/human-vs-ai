#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint64_t u64;

typedef struct _queue_t *queue_t;

struct _queue_t {
    u32 *array;
    u32 FirstElem;
    u32 LastElem;
    u32 memory_allocated;
    u32 Size;
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

int main() {
    queue_t queue = queue_empty();

    for (u32 i = 0; i < 1000; i++) {
        if (queue->memory_allocated == queue->Size) {
            // Adjusted reallocation: Allocate enough space for new elements
            queue->array = realloc(queue->array, (queue->memory_allocated + 100) * sizeof(u32));
            assert(queue->array != NULL); // Always check that realloc didn't fail
            queue->memory_allocated += 100;
        }

        // Correct indexing by using LastElem as the current position, then increment
        queue->array[queue->LastElem] = i;
        queue->LastElem++;
        queue->Size++;
    }

    // Remember to free the allocated memory
    free(queue->array);
    free(queue);

    return 0;
}
