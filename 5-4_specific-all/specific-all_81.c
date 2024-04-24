BMPImage * readImage(FILE * fp) {
    BMPImage * image = malloc(sizeof(BMPImage));

    if (image == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Read BMP header
    if (fread(&(image->header), sizeof(BMPHeader), 1, fp) != 1) {
        // Error reading BMPHeader
        free(image);
        return NULL;
    }

    // Allocate memory for pixels
    image->pixels = malloc(image->header.height_px * sizeof(Pixel *));
    if (image->pixels == NULL) {
        // Handle allocation failure
        free(image);
        return NULL;
    }

    for (int i = 0; i < image->header.height_px; i++) {
        image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
        if (image->pixels[i] == NULL) {
            // Handle allocation failure
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(image->pixels[j]);
            }
            free(image->pixels);
            free(image);
            return NULL;
        }
    }

    // Read pixel data
    for (int i = 0; i < image->header.height_px; i++) {
        for (int j = 0; j < image->header.width_px; j++) {
            if (fread(&(image->pixels[i][j]), sizeof(Pixel), 1, fp) != 1) {
                // Error reading pixel data
                // Free allocated memory
                for (int k = 0; k <= i; k++) {
                    free(image->pixels[k]);
                }
                free(image->pixels);
                free(image);
                return NULL;
            }
        }
    }

    return image;
}
