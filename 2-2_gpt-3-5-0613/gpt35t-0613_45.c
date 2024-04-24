#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main() {
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf_s("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for(i = 0; i < size; i++) {
        pAlbum[i].title = malloc(sizeof(char) * 100);  // Allocate memory for title

        printf("Enter the album title: ");
        scanf_s("%s", pAlbum[i].title);
    }

    for(i = 0; i < size; i++) {
        printf("Album %d title: %s\n", i + 1, pAlbum[i].title);
        free(pAlbum[i].title);  // Free memory for each title
    }

    free(pAlbum);
    return 0;
}
