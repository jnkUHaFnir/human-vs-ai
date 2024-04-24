#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
}; // Don't forget the semicolon at the end of the struct definition

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size); // Use scanf instead of scanf_s for this case

    pAlbum = malloc(sizeof(struct Album) * size); // Allocate memory for the array of struct Album

    // Clear the input buffer
    while (getchar() != '\n');

    for(i=0; i<size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for the title string

        printf("Enter the album title: ");
        fgets(pAlbum[i].title, 100, stdin); // Use fgets to read string input

        // Removing the newline character from the input
        pAlbum[i].title[strcspn(pAlbum[i].title, "\n")] = 0;
    }

    // Free dynamically allocated memory
    for(i=0; i<size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
