int htable_insert(htable h, char *str) {
    // ... rest of your code ...
    
    // CHANGE: Loop until you find an empty space or the desired string.
    int start = remainder;
    do {
        // Linear probing: if this slot is not NULL but not our string, move on
        if (h->key[remainder] != NULL && strcmp(h->key[remainder], str) != 0) {
            remainder = (remainder + 1) % h->capacity;
            if (start == remainder) { // We've wrapped around and the table is full
                return 0;
            }
        } else {
            break; // Found an empty slot or our string.
        }
    } while (1);
    
    // ... handle the empty slot or existing string ...

    // CHANGE: Should return frequency here if we found the string already.
    return h->frequencies[remainder];
}

int htable_search(htable h, char *str) {
    // ... rest of your code ...

    // CHANGE: Correctly increment the probing index
    while (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) != 0) {
        remainder = (remainder + 1) % h->capacity;
        collisions++;
        if (collisions == h->capacity) {
            return 0;
        }
    }

    // CHANGE: Return frequency at the correct index.
    if (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) == 0) {
        return h->frequencies[remainder];
    }

    return 0;
}
