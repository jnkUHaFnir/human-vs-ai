        #include <stdlib.h>
        // ...
        char *title = malloc(100 * sizeof(char));
        if (title == NULL) {
            // handle out of mem error
        }
        // ...
        if (title == NULL)
            free (title);