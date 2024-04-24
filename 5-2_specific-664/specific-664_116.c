#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};  // Added semicolon here

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    for(i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100); // Allocate memory for title
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title); // Use %s to read a string
    }

    // Free memory for each title
    for(i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}
