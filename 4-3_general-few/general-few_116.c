#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Don't forget the semicolon here

int main() {
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocating memory for title

        printf("Enter the album title: ");
        scanf(" %99[^\n]", pAlbum[i].title); // Reading input using %[^\n] to include spaces

    }

    // Outputting the albums
    for (i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i+1, pAlbum[i].title);

        // Free memory for each title
        free(pAlbum[i].title);
    }

    // Free memory for the array of albums
    free(pAlbum);

    return 0;
}
