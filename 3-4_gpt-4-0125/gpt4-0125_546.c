#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Assuming the .h file definitions are included above

// Function to read BMP image from file
BMPImage *readImage(FILE *fp) {
    if (!fp) {
        return NULL; // Always check if the file pointer is valid
    }

    // Allocate memory for the BMP header and read it from the file
    BMPHeader *hp = malloc(sizeof(BMPHeader));
    if (fread(hp, sizeof(BMPHeader), 1, fp) != 1) {
        free(hp);
        return NULL; // Error reading the header, must clean up and return
    }

    // Allocate memory for the BMPImage structure
    BMPImage *image = malloc(sizeof(BMPImage));
    if (!image) {
        free(hp); // Clean up previously allocated memory before returning
        return NULL;
    }

    // Copy the header to the image struct
    image->header = *hp;
    free(hp); // The header information has been copied, so we can free this

    // Jump to the pixel data location
    fseek(fp, image->header.offset, SEEK_SET);

    // Allocate memory for the pixel data
    image->pixels = malloc(image->header.height_px * sizeof(Pixel*));
    for (int i = 0; i < image->header.height_px; i++) {
      image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
    }

    // Read the pixel data row by row (bottom to top)
    for (int i = 0; i < image->header.height_px; i++) {
        // Read each row; note that rows may be padded to 4 bytes
        size_t rowSize = image->header.width_px * sizeof(Pixel);
        if (fread(image->pixels[i], rowSize, 1, fp) != 1) {
            // Error handling: free allocated memory
            for(int j = 0; j <= i; j++) {
                free(image->pixels[j]);
            }
            free(image->pixels);
            free(image);
            return NULL; // Return NULL to indicate failure
        }
    }

    return image; // Return the pointer to the BMPImage struct
}
