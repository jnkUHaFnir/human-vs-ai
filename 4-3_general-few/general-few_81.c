BMPImage * readImage(FILE * fp) {
    BMPImage * img = malloc(sizeof(BMPImage));

    // Read BMP header
    fread(&(img->header), sizeof(BMPHeader), 1, fp);

    // Allocate memory for pixels
    img->pixels = malloc(img->header.height_px * sizeof(Pixel*));
    for(int i = 0; i < img->header.height_px; i++) {
        img->pixels[i] = malloc(img->header.width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < img->header.height_px; i++) {
        for (int j = 0; j < img->header.width_px; j++) {
            fread(&(img->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }

    return img;
}
