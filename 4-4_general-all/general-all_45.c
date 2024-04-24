#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main() {
    int i, size;

    printf("Enter the number of albums: ");
    scanf("%d", &size);

    struct Album* pAlbum = malloc(sizeof(struct Album) * size);

    // Check if memory allocation is successful
    if (pAlbum == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Clear the input buffer
    while ((getchar()) != '\n');

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocating memory for title

        printf("Enter the album title: ");
        scanf("%99[^\n]%*c", pAlbum[i].title); // Allowing spaces in the title

        // Clear the input buffer
        while ((getchar()) != '\n');
    }

    // Displaying the entered albums
    for (i = 0; i < size; i++) {
        printf("Album %d Title: %s\n", i+1, pAlbum[i].title);
        free(pAlbum[i].title); // Free the memory for each title
    }

    free(pAlbum); // Free the memory for the array of albums
    return 0;
}
