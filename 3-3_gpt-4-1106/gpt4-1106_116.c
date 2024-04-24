#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Add a semicolon here

int main() {
    int i, size;
    const int TITLE_SIZE = 256; // Define the max title size

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    // Use sizeof(struct Album) for the correct allocation size
    pAlbum = (struct Album*)malloc(sizeof(struct Album) * size);

    if (pAlbum == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each title and read the title from user input
    for(i = 0; i < size; i++) {
        pAlbum[i].title = malloc(TITLE_SIZE);
        if (pAlbum[i].title == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // If allocation fails, free previously allocated memory
            while (i > 0) {
                free(pAlbum[--i].title);
            }
            free(pAlbum);
            return 1;
        }
        printf("Enter the album title: ");
        scanf("%255s", pAlbum[i].title); // Read up to 255 characters (leaving space for the null terminator)
    }

    // Always good practice to check what you've stored
    for(i = 0; i < size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
    }

    // Free the title strings and the album array
    for(i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
