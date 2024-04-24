struct your_struct {
    struct your_struct *next;
    // other members
};

void pointer_chasing(struct your_struct **mystruc) {
    asm volatile("mov (%1), %0" 
                 : "=r" (*mystruc)
                 : "r" (*mystruc));
}
