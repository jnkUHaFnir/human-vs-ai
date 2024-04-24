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

    // Allocate memory to hold "size" number of Album structures
    pAlbum = (struct Album*)malloc(sizeof(struct Album) * size);

    // Allocate memory for title in each Album
    for (i = 0; i < size; i++) {
        pAlbum[i].title = (char*)malloc(100 * sizeof(char)); // Assuming max title length is 100 characters
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title);
    }

    // Printing entered album titles
    printf("Album Titles:\n");
    for (i = 0; i < size; i++) {
        printf("%s\n", pAlbum[i].title);
    }

    // Free allocated memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
