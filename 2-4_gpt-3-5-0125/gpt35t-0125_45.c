struct Album {
    char* title;
}; 
pAlbum[i].title = malloc(sizeof(char) * MAX_TITLE_LENGTH); // Assuming MAX_TITLE_LENGTH is the maximum length of an album title
scanf_s("%s", pAlbum[i].title);
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITLE_LENGTH 100 // Maximum length of album title

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
        pAlbum[i].title = malloc(sizeof(char) * MAX_TITLE_LENGTH);
        printf("Enter the album title: ");
        scanf("%s", pAlbum[i].title);
    }

    // Print the album titles
    for(i=0; i<size; i++) {
        printf("Album %d: %s\n", i+1, pAlbum[i].title);
    }

    // Free the allocated memory
    for(i=0; i<size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);

    return 0;
}
