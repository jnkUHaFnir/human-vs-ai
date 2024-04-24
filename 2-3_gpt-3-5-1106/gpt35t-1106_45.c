#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
    char* title;
};

int main() {
    int i, size;

    printf("Enter the number of albums: ");
    scanf("%d", &size);

    struct Album* pAlbum = malloc(sizeof(struct Album) * size);

    for (i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100);
        printf("Enter the title for album %d: ", i+1);
        scanf("%s", pAlbum[i].title);
    }

    for (i = 0; i < size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
    }

    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
