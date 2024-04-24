#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of album: ");
    scanf("%d", &size);

    // Allocate memory for the array of Albums
    pAlbum = malloc(sizeof(struct Album) * size);

    getchar(); // Clear the newline character remaining in the input buffer from the previous scanf()

    for(i = 0; i < size; i++) {
        printf("Enter the album title: ");

        // Let's keep a fixed size for the album titles
        // You may decide to increase it if needed
        pAlbum[i].title = malloc(50 * sizeof(char));

        fgets(pAlbum[i].title, 50, stdin); // Read string input using fgets to avoid buffer overflows
    }

    // Just to check if it's working, let's print the album titles
    for(i = 0; i < size; i++) {
        printf("Album %d: %s", i+1, pAlbum[i].title);
    }

    // Free the memory allocated for the album titles and the array
    for(i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
