int htable_search(htable h, char *str) {
    int collisions = 0;
    unsigned int index = htable_word_to_int(str);
    int remainder = index % h->capacity;

    while (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) != 0 && remainder != index % h->capacity) {
        remainder = (remainder + 1) % h->capacity;
        collisions++;
    }
    
    if (collisions == h->capacity) {
        return 0;
    } else {
        return h->frequencies[remainder];
    }
}
