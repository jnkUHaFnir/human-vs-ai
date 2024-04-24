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

    // Consume the newline character left in the input buffer
    while (getchar() != '\n');

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for title (adjust size as needed)

        printf("Enter the album title for album %d: ", i + 1);
        fgets(pAlbum[i].title, 100, stdin); // Read input using fgets

        // Remove the trailing newline character from the title
        pAlbum[i].title[strcspn(pAlbum[i].title, "\n")] = 0;
    }

    // Output the titles for each album
    for (i = 0; i < size; i++) {
        printf("Album %d: %s\n", i + 1, pAlbum[i].title);
    }

    // Free memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
