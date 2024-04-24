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
    getchar(); // consume the newline character left behind by scanf

    pAlbum = malloc(sizeof(struct Album) * size);

    for (i = 0; i < size; i++) {
        printf("Enter the title of album %d: ", i + 1);
        pAlbum[i].title = malloc(sizeof(char) * 100); // allocate memory for title
        fgets(pAlbum[i].title, 100, stdin); // use fgets instead of scanf to read entire input line
    }

    printf("\nTitles of the albums:\n");

    for (i = 0; i < size; i++) {
        printf("%d. %s", i + 1, pAlbum[i].title);
        free(pAlbum[i].title); // free memory for title
    }

    free(pAlbum);

    return 0;
}
