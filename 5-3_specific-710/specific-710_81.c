BMPImage* readImage(FILE* fp) {
    // Read BMP header
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, fp);

    // Allocate memory for the image
    BMPImage* image = malloc(sizeof(BMPImage));
    image->header = header;
    image->pixels = malloc(header.height_px * sizeof(Pixel*));

    for (int i = 0; i < header.height_px; i++) {
        image->pixels[i] = malloc(header.width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < header.height_px; i++) {
        for (int j = 0; j < header.width_px; j++) {
            fread(&image->pixels[i][j], sizeof(Pixel), 1, fp);
        }
    }

    return image;
}
