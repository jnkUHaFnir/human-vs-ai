    BMPImage *readImage(FILE * fp) {
        // Allocate space for the image.
        // This also covers BMPHeader, since it's not a pointer.
        BMPImage *bmp = malloc(sizeof(BMPImage));
        BMPHeader *bmph = &(bmp->header);