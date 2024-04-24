#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

// Your given structures...

BMPImage * readImage(FILE * fp) {
    if (fp == NULL) {
        return NULL;
    }

    // Read BMP header
    BMPHeader bmpHeader;
    if (fread(&bmpHeader, sizeof(BMPHeader), 1, fp) != 1) {
        // Handle error...
        return NULL;
    }

    // Check if it's a valid BMP file
    if (bmpHeader.type != 0x4D42) { // 0x4D42 is 'BM' in hexadecimal
        // Handle error...
        return NULL;
    }
    
    // Allocate memory for BMPImage
    BMPImage *bmpImage = malloc(sizeof(BMPImage));
    if (!bmpImage) {
        // Handle memory allocation error...
        return NULL;
    }
    bmpImage->header = bmpHeader; // copy header
    bmpImage->norm_height = abs(bmpHeader.height_px); // BMP can have negative height

    // Calculate padding
    int padding = (4 - (bmpHeader.width_px * sizeof(Pixel)) % 4) % 4;

    // Allocate memory for pixels
    bmpImage->pixels = malloc(bmpImage->norm_height * sizeof(Pixel *));
    if (!bmpImage->pixels) {
        // Handle memory allocation error...
        free(bmpImage);
        return NULL;
    }
    
    for (int i = 0; i < bmpImage->norm_height; i++) {
        bmpImage->pixels[i] = malloc(bmpHeader.width_px * sizeof(Pixel));
        if (!bmpImage->pixels[i]) {
            // Handle memory allocation error...
            // ...Free previously allocated memory
        }
    }

    // Set file position to the beginning of pixel data
    fseek(fp, bmpHeader.offset, SEEK_SET);

    // Read pixel data row by row
    for (int i = 0; i < bmpImage->norm_height; i++) {
        // Read a row
        if (fread(bmpImage->pixels[i], sizeof(Pixel), bmpHeader.width_px, fp) != bmpHeader.width_px) {
            // Handle error...
        }
        // Skip padding
        fseek(fp, padding, SEEK_CUR);
    }
    
    return bmpImage;
}
