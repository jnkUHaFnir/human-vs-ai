#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_SIZE 100

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
        pAlbum[i].title = malloc(sizeof(char) * MAX_TITLE_SIZE);

        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title);
    }

    // Print the album titles
    for(i=0; i<size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
    }

    // Free memory
    for(i=0; i<size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
