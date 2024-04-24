BMPImage * readImage(FILE * fp) {
    // Read the BMP header
    BMPHeader header;
    fread(&header, sizeof(BMPHeader), 1, fp);

    // Allocate memory for the BMPImage struct
    BMPImage * image = malloc(sizeof(BMPImage));
    image->header = header;
    image->norm_height = abs(header.height_px); // Normalize height

    // Allocate memory for the pixel array
    image->pixels = malloc(image->norm_height * sizeof(Pixel *));
    for (int i = 0; i < image->norm_height; i++) {
        image->pixels[i] = malloc(header.width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < image->norm_height; i++) {
        for (int j = 0; j < header.width_px; j++) {
            fread(&(image->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }

    return image;
}
