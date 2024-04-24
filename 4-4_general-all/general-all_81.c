BMPImage * readImage(FILE * fp) {
    BMPImage * image = malloc(sizeof(BMPImage));

    // Read BMP Header
    fread(&(image->header), sizeof(BMPHeader), 1, fp);

    // Allocate memory for pixels
    image->pixels = malloc(image->header.height_px * sizeof(Pixel *));
    for (int i = 0; i < image->header.height_px; i++) {
        image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < image->header.height_px; i++) {
        for (int j = 0; j < image->header.width_px; j++) {
            fread(&(image->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }

    return image;
}
