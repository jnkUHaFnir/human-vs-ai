for (i = 0; i < h->capacity; i++) {
   int new_remainder = (remainder + i) % h->capacity;
   if (h->key[new_remainder] == NULL) {
      ...
   }

   if (strcmp(str, h->key[new_remainder]) == 0) {
      ...
   }
   ...
}
while (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) != 0 && collisions < h->capacity) {
   remainder = (remainder + 1) % h->capacity;
   collisions++;
}
if(collisions == h->capacity) {
   return 0;
} else {
   if (h->key[remainder] != NULL) {
       return h->frequencies[remainder];
   }
   return 0;
}
