BMPImage * readImage(FILE * fp) {
    // Read the BMP header
    BMPHeader * hp = malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);

    // Set up the BMPImage struct
    BMPImage * image = malloc(sizeof(BMPImage));
    image->header = *hp;
    image->pixels = malloc(image->header.height_px * sizeof(Pixel *));
    for (int i = 0; i < image->header.height_px; i++) {
        image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
    }

    // Read the pixel data
    for (int i = 0; i < image->header.height_px; i++) {
        for (int j = 0; j < image->header.width_px; j++) {
            fread(&image->pixels[i][j], sizeof(Pixel), 1, fp);
        }
    }

    // Return the BMPImage
    return image;
}
