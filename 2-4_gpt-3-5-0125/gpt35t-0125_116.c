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

    for(i=0; i<size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocating memory for the title
        
        printf("Enter the title for album %d: ", i+1);
        scanf("%s", pAlbum[i].title);
    }

    for(i=0; i<size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
        free(pAlbum[i].title); // Freeing memory for each title
    }

    free(pAlbum); // Freeing memory for the array of Album structs
    return 0;
}
