#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LEN 100

struct Album {
    char* title;
};

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = (struct Album*)malloc(sizeof(struct Album) * size);

    for(i=0; i<size; i++) {
        pAlbum[i].title = (char*)malloc(MAX_TITLE_LEN * sizeof(char));
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title);
    }

    // Use the album info...
    for(i=0; i<size; i++) {
        printf("Album [%d]: %s\n", i+1, pAlbum[i].title);
    }

    // Free memory
    for(i=0; i<size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
