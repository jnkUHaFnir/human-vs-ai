asm volatile("mov %1, %0" : "=r" (address) : "r" (&(mystruc->next)));
mystruc = *(struct Node **)address;
