#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Notice the semicolon here

int main() {
    int i, size;
    const int titleSize = 256; // Assuming the title will not exceed 256 characters

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);
    getchar(); // Consume the newline character so it doesn't affect the first fgets call

    pAlbum = malloc(sizeof(struct Album) * size); // Corrected sizeof usage

    for(i = 0; i < size; i++) {
        pAlbum[i].title = malloc(titleSize * sizeof(char)); // Allocate memory for title
        if(pAlbum[i].title != NULL) {
            printf("Enter the album title: ");
            fgets(pAlbum[i].title, titleSize, stdin); // Safe, and includes space characters until the newline
            
            // Remove the newline character, if present
            size_t ln = strlen(pAlbum[i].title) - 1;
            if (pAlbum[i].title[ln] == '\n') {
                pAlbum[i].title[ln] = '\0';
            }
        }
    }

    // Optionally print out the album titles to verify input
    for (i = 0; i < size; i++) {
        printf("Album %d: %s\n", i + 1, pAlbum[i].title);
    }

    // Free allocated memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title); // First free the titles
    }
    free(pAlbum); // Then free the array of structs

    return 0;
}
