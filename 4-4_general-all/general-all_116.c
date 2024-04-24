#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Add missing semicolon

int main() {
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    if (pAlbum == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for the title
        if (pAlbum[i].title == NULL) {
            printf("Memory allocation failed for title. Exiting...\n");
            return 1;
        }
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title);
    }

    // Output the entered titles
    printf("\nAlbum Titles:\n");
    for (i = 0; i < size; i++) {
        printf("%s\n", pAlbum[i].title);
        free(pAlbum[i].title); // Free memory for each title
    }

    free(pAlbum); // Free memory for the array of albums
    return 0;
}
