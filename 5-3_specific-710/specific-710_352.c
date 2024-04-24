#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <gc/gc.h>

// Function pointers to hold original memory management functions
static void* (*original_malloc)(size_t size) = NULL;
static void* (*original_calloc)(size_t nmemb, size_t size) = NULL;
static void* (*original_realloc)(void* ptr, size_t size) = NULL;
static void (*original_free)(void* ptr) = NULL;

void* my_malloc(size_t size) {
    if (original_malloc == NULL) {
        original_malloc = dlsym(RTLD_NEXT, "malloc");
    }
    return GC_MALLOC(size);
}

void* my_calloc(size_t nmemb, size_t size) {
    if (original_calloc == NULL) {
        original_calloc = dlsym(RTLD_NEXT, "calloc");
    }
    return GC_MALLOC(nmemb * size);
}

void* my_realloc(void* ptr, size_t size) {
    if (original_realloc == NULL) {
        original_realloc = dlsym(RTLD_NEXT, "realloc");
    }
    return GC_REALLOC(ptr, size);
}

void my_free(void* ptr) {
    if (original_free == NULL) {
        original_free = dlsym(RTLD_NEXT, "free");
    }
    // No operation needed here since GC handles memory management
}

#define malloc my_malloc
#define calloc my_calloc
#define realloc my_realloc
#define free my_free

#include <stdio.h>

// Your code using asprintf
static string printInt(Object self) {
    string str;
    asprintf(&str, "%lu", getValueInt(self));
    return str;
}

int main() {
    // Your code here
    return 0;
}
