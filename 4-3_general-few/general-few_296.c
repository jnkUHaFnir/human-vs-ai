#define DEREFERENCE_PTR(ptr, result) \
    asm volatile("mov %1, %0" : "=r" (result) : "m" (*(ptr)))

// Example usage
int* ptr = &(mystruc->next);
int value;
DEREFERENCE_PTR(ptr, value);
