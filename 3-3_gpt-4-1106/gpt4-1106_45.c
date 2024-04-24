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

    pAlbum = (struct Album*)malloc(sizeof(struct Album) * size);
    if (!pAlbum) {
        perror("Memory allocation failed");
        return 1;
    }

    for (i = 0; i < size; i++) {
        pAlbum[i].title = (char*)malloc(256 * sizeof(char)); // Allocating memory for the title
        if (!pAlbum[i].title) {
            perror("Memory allocation for title failed");
            return 1;
        }
        printf("Enter the album title: ");
        scanf(" %255s", pAlbum[i].title); // Note the space before % to skip any leading whitespace
    }

    // Remember to print/validate album titles and deallocate titles before freeing the array of structs
    for (i = 0; i < size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
        free(pAlbum[i].title); // Deallocate the title string
    }
    free(pAlbum); // Deallocate the array of structs
    return 0;
}
