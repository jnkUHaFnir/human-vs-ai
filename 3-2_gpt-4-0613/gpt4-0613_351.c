int htable_search(htable h, char *str) {
    int collisions = 0;
    unsigned int index = htable_word_to_int(str);
    int remainder = index%h->capacity;
    int initial_remainder = remainder;
    
    /* While key at the location is not null and is not equal to the string */
    while (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) != 0) {
        remainder = (initial_remainder+collisions)%h->capacity;
        collisions++;
    }

    /*If we have probed all the indices in the hashtable and couldn't find str */
    if(collisions == h->capacity) {
        return 0;
    } else {
        /* return the frequency at our final position */
        return h->frequencies[remainder];
    } 
}
for (i = 0; i < h->capacity; i++) {
    remainder = (remainder+1)%h->capacity;
    // Then your code...
}
