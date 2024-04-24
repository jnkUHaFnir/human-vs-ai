#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Missing semicolon

int main() {
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size); // Allocate memory for each Album structure

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for the title

        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title); // Use %s to read a string
    }

    // Output the entered titles
    for (i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i + 1, pAlbum[i].title);
    }

    // Free memory for titles
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    // Free memory for the array of albums
    free(pAlbum);

    return 0;
}
