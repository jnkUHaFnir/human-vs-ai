int main(){
    int i, size;

    struct Album* pAlbum;
    printf("Enter the number of albums: ");
    scanf("%d", &size);

    pAlbum = malloc(sizeof(struct Album) * size);

    // Consume the newline character left in the input buffer by scanf
    getchar();

    for(i = 0; i < size; i++) {
        pAlbum[i].title = malloc(100); // Allocating memory for the title

        printf("Enter the album title: ");
        fgets(pAlbum[i].title, 100, stdin); // Allowing spaces in the title
        
        // Remove the newline character added by fgets
        pAlbum[i].title[strcspn(pAlbum[i].title, "\n")] = '\0';
    }

    // Free memory for each title
    for(i = 0; i < size; i++) {
        free(pAlbum[i].title);
    }

    // Free memory for the array of albums
    free(pAlbum);
    return 0;
}
