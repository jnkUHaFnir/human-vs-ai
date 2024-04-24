BMPImage * readImage(FILE * fp) {
    // Read BMPHeader
    BMPHeader * hp = (BMPHeader *)malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);

    // Allocate memory for BMPImage
    BMPImage * img = (BMPImage *)malloc(sizeof(BMPImage));
    img->header = *hp;
    img->pixels = (Pixel **)malloc(hp->height_px * sizeof(Pixel *));

    // Allocate memory for pixels
    for (int i = 0; i < hp->height_px; i++) {
        img->pixels[i] = (Pixel *)malloc(hp->width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < hp->height_px; i++) {
        for (int j = 0; j < hp->width_px; j++) {
            fread(&(img->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }

    // Free BMPHeader memory
    free(hp);

    return img;
}
