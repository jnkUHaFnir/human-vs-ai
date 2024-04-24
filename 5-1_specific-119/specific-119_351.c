int htable_search(htable h, char *str) {
    int collisions = 0;
    unsigned int index = htable_word_to_int(str);
    int remainder = index % h->capacity;

    while (h->key[remainder] != NULL && (strcmp(str, h->key[remainder]) != 0 && collisions < h->capacity)) {
        remainder = (remainder + 1) % h->capacity; // Circulate back to the beginning if needed
        collisions++;
    }

    if (collisions == h->capacity) {
        return 0;
    } else {
        return h->frequencies[remainder];  // Return the frequency at the found position
    }
}