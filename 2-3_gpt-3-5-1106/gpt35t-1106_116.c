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
        pAlbum[i].title = malloc(100 * sizeof(char)); // allocate memory for the title
        printf("Enter the title of album %d: ", i+1);
        scanf(" %99[^\n]", pAlbum[i].title); // read the album title
    }

    // display the album titles
    for (i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i+1, pAlbum[i].title);
    }

    // free memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
