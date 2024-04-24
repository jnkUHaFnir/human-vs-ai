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
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for the title

        printf("Enter the album title: ");
        fgets(pAlbum[i].title, 100, stdin); // Use fgets to read a line of text

        // Remove the newline character at the end of the input
        pAlbum[i].title[strcspn(pAlbum[i].title, "\n")] = 0;
    }

    // Output the entered titles
    for (i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i+1, pAlbum[i].title);
    }

    // Free allocated memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
