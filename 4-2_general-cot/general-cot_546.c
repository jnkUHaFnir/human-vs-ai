BMPImage * readImage(FILE * fp) {
    BMPHeader * hp = malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);

    BMPImage * img = malloc(sizeof(BMPImage));
    img->header = *hp;
    img->pixels = malloc(img->header.height_px * sizeof(Pixel *));

    for (int i = 0; i < img->header.height_px; i++) {
        img->pixels[i] = malloc(img->header.width_px * sizeof(Pixel));
        fread(img->pixels[i], sizeof(Pixel), img->header.width_px, fp);
    }

    free(hp); // Free the BMPHeader pointer since its data is copied to BMPImage

    return img;
}
