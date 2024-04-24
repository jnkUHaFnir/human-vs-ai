#include <string.h>
#include <stdlib.h>

char* remove_chars(char* mystr) {
    size_t len = strlen(mystr);

    if (len <= 3) {
        return strdup(""); // return an empty string
    }

    char *tmp = malloc(len - 2); // allocate memory on the heap
    if (tmp != NULL) {
        strncpy(tmp, mystr, len - 3); // copy the first (len - 3) characters
        tmp[len - 3] = '\0'; // null-terminate the string
    }
    return tmp;
}

// Remember to free the returned pointer after you're done using it:
//   char* removed = remove_chars(filename);
//   // use removed
//   free(removed);
#include <string.h>

void remove_chars(char* mystr, char* buffer, size_t buf_size) {
    size_t len = strlen(mystr);

    if (len <= 3 || buf_size == 0) {
        buffer[0] = '\0'; // return an empty string
        return;
    }

    strncpy(buffer, mystr, len - 3);
    buffer[len - 3] = '\0';
}

// Usage:
//   char filename[] = "example.txt";
//   char removed[sizeof(filename) - 2];
//   remove_chars(filename, removed, sizeof(removed));
