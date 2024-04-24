#include <stdio.h>
#include <stdlib.h>

struct Album {
    char title[100]; // Assuming a maximum title length of 100 characters
};

int main() {
    int i, size;

    struct Album* pAlbum;
    
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);
    if (pAlbum == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Consume the trailing newline character after reading the size input
    while (getchar() != '\n');

    for (i = 0; i < size; i++) {
        printf("Enter the title for album %d: ", i + 1);
        fgets(pAlbum[i].title, sizeof(pAlbum[i].title), stdin);
        
        // Remove the trailing newline character from the title
        pAlbum[i].title[strcspn(pAlbum[i].title, "\n")] = '\0';
    }

    // Printing the entered titles for verification
    for (i = 0; i < size; i++) {
        printf("Title for album %d: %s\n", i + 1, pAlbum[i].title);
    }

    free(pAlbum);
    return 0;
}
