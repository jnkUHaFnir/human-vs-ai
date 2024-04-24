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

    for (i = 0; i < size; i++) {
        pAlbum[i].title = (char*)malloc(sizeof(char) * 100);     // assuming the title length is less than 100 characters
        printf("Enter the album title: ");
        scanf_s("%s", pAlbum[i].title, 100);
    }

    // do something with the titles...

    // free the memory allocated for the titles
    for (i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }

    // free the memory allocated for the album array
    free(pAlbum);
    return 0;
}
