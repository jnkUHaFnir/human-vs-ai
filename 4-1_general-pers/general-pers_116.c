#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for(i=0; i<size; i++) {
        pAlbum[i].title = malloc(100 * sizeof(char)); // Allocate memory for title
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title); // Read the title as a string
    }

    for(i=0; i<size; i++) {
        printf("Album %d title: %s\n", i+1, pAlbum[i].title);
        free(pAlbum[i].title); // Free memory for each title
    }

    free(pAlbum);
    return 0;
}
