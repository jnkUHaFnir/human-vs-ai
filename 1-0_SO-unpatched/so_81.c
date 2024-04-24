    // Read in each pixel
    for (int i = 0; i < bmph->height_px; i++){
        for(int j = 0; j < bmph->width_px; j++){
            Pixel *px = malloc(sizeof(Pixel));
            
            if( fread(px, sizeof(Pixel), 1, fp) < 1 ) {
                fprintf(stderr, "Error while reading bmp: %s", strerror(errno));
                return NULL;
            }
            
            bmp->pixels[i][j] = *px;
        }
    }