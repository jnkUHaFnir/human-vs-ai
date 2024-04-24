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
        pAlbum[i].title = malloc(100 * sizeof(char)); // Assuming max title length is 100

        printf("Enter album title for album %d: ", i+1);
        scanf("%s", pAlbum[i].title);
    }

    // Free allocated memory
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}
