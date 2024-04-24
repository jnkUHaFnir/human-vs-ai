#include <stdio.h>
#include <stdlib.h>

struct Album {
    char* title;
};  // Added semicolon here

#define TITLE_SIZE 256  // Define a maximum title size

int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);  // Using scanf here because this is a simple case

    // Flush the newline character left by scanf in the input buffer
    while (getchar() != '\n');

    pAlbum = malloc(sizeof(struct Album) * size);  // Corrected the size

    for(i=0; i<size; i++) {
        pAlbum[i].title = malloc(sizeof(char) * TITLE_SIZE);  // Allocate memory for title
        
        printf("Enter the album title: ");
        fgets(pAlbum[i].title, TITLE_SIZE, stdin);  // Use fgets to include spaces in the title
        
        // Remove newline character at the end if exists
        size_t ln = strlen(pAlbum[i].title) - 1;
        if (pAlbum[i].title[ln] == '\n')
            pAlbum[i].title[ln] = '\0';
    }

    // Don't forget to free the allocated memory for each title and then for the array
    for(i=0; i<size; i++) {
        free(pAlbum[i].title);
    }
    free(pAlbum);
    return 0;
}
