pAlbum = malloc(sizeof(struct Album) * size);
scanf_s("%s", &pAlbum[i].title);
pAlbum[i].title = malloc(100 * sizeof(char)); // assuming a maximum of 99 characters for the title
fgets(pAlbum[i].title, 100, stdin);
#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf_s("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for(i=0; i<size; i++) {
        printf("Enter the album title: ");
        pAlbum[i].title = malloc(100 * sizeof(char));
        fgets(pAlbum[i].title, 100, stdin);
    }

    for(i=0; i<size; i++) {
        printf("Album #%d: %s", i+1, pAlbum[i].title);
        free(pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}
