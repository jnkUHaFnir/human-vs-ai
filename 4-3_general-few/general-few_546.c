BMPImage * readImage(FILE * fp) {
    BMPImage * img = malloc(sizeof(BMPImage));

    // Read the BMPHeader
    BMPHeader * hp = malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);

    // Initialize the image properties
    img->header = *hp;
    img->norm_height = abs(hp->height_px);
    
    // Allocate memory for the pixels
    img->pixels = malloc(img->norm_height * sizeof(Pixel *));
    for (int i = 0; i < img->norm_height; i++){
        img->pixels[i] = malloc(hp->width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < img->norm_height; i++) {
        for(int j = 0; j < hp->width_px; j++){
            fread(&(img->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }

    free(hp); // Don't forget to free the memory allocated for BMPHeader
    return img;
}
