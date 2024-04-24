    int remainder = index%h->capacity;
    /* once calculated position in the hash table, 3 possibilities occur*/
    /* no string in this positon, copy string to that position,
       increment number of keys, return 1*/
    if (h->key[remainder] == NULL) {
        char *key = emalloc(strlen(str) + 1);
        strcpy(key, str);
        h->key[remainder] = key;
        h->frequencies[remainder] = 1;
        h->num_keys++;
    /*the exact same string is at the position,
     increment frequency at that position,
     return frequency*/
    if (strcmp(str, h->key[remainder]) == 0) {
        h->frequencies[remainder]++;
        ...