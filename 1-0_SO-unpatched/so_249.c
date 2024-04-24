    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL)
        …handle out of memory condition…ptr is still valid!
    ptr = new_ptr;