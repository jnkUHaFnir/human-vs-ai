BMPImage* readImage(FILE* fp) {
    // Read BMP Header
    BMPHeader hp;
    fread(&hp, sizeof(BMPHeader), 1, fp);

    // Allocate memory for BMPImage structure
    BMPImage *img = (BMPImage*)malloc(sizeof(BMPImage));
    
    // Initialize BMPImage attributes
    img->header = hp;
    img->norm_height = abs(hp.height_px); // Normalize height to positive value

    // Allocate memory for pixel array
    img->pixels = (Pixel**)malloc(img->norm_height * sizeof(Pixel*));
    for(int i = 0; i < img->norm_height; i++){
        img->pixels[i] = (Pixel*)malloc(hp.width_px * sizeof(Pixel));
    }

    // Read pixel data
    for (int i = 0; i < img->norm_height; i++){
        for(int j = 0; j < hp.width_px; j++){
            fread(&img->pixels[i][j], sizeof(Pixel), 1, fp);
        }
    }

    return img;
}
