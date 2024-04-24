#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main() {
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocating memory for title

        printf("Enter the album title: ");
        scanf(" %99[^\n]", pAlbum[i].title); // Reading album title

        // You can adjust the length of the title depending on your requirements
    }

    // Print the titles as an example
    for (i = 0; i < size; i++) {
        printf("Album %d: %s\n", i + 1, pAlbum[i].title);
    }

    // Freeing allocated memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
