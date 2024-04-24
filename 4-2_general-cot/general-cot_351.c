int htable_search(htable h, char *str) {
    int collisions = 0;
    unsigned int index = htable_word_to_int(str);
    int remainder = index % h->capacity;
    
    // Loop until we find the key or hit an empty slot in the table
    while (h->key[remainder] != NULL) {
        if (strcmp(str, h->key[remainder]) == 0) {
            return h->frequencies[remainder]; // Return frequency if key is found
        }
        
        collisions++;
        remainder = (remainder + 1) % h->capacity; // Move to the next slot
    }
    
    // If we reach here, key was not found in the table
    return 0;
}
