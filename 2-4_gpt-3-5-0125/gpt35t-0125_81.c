BMPImage * readImage(FILE * fp) {
    BMPImage * image = malloc(sizeof(BMPImage));
    
    // Read BMPHeader
    BMPHeader * hp = malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);
    
    // Initialize image attributes
    image->header = *hp;
    image->norm_height = abs(hp->height_px);
    
    // Allocate memory for pixels
    image->pixels = malloc(image->norm_height * sizeof(Pixel *));
    for(int i = 0; i < image->norm_height; i++){
        image->pixels[i] = malloc(hp->width_px * sizeof(Pixel));
    }
    
    // Read pixel data
    for(int i = 0; i < image->norm_height; i++){
        for(int j = 0; j < hp->width_px; j++){
            fread(&(image->pixels[i][j]), sizeof(Pixel), 1, fp);
        }
    }
    
    free(hp); // Don't forget to free allocated memory for BMPHeader
    
    return image;
}
