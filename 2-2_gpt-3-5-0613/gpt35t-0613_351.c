int htable_insert(htable h, char *str) {
   // ...

   if (h->key[remainder] != NULL) {
      for (i = 1; i < h->capacity; i++) {
         remainder = (remainder + 1) % h->capacity;

         if (h->key[remainder] == NULL) {
            // Insert the string at the current position
            // ...
            
            return 1;
         }

         if (strcmp(str, h->key[remainder]) == 0) {
            // Increment the frequency at the current position
            // ...
            
            return h->frequencies[remainder];
         }
      }
   }

   // ...
}

int htable_search(htable h, char *str) {
   // ...

   while (h->key[remainder] != NULL && strcmp(str, h->key[remainder]) != 0) {
      remainder = (remainder + 1) % h->capacity;
      collisions++;
   }

   // ...
}
