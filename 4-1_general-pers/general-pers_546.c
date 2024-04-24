#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) BMPHeader {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
    uint32_t dib_header_size;
    int32_t width_px;
    int32_t height_px;
    uint16_t num_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size_bytes;
    int32_t x_resolution_ppm;
    int32_t y_resolution_ppm;
    uint32_t num_colors;
    uint32_t important_colors;
} BMPHeader;

typedef struct __attribute__((packed)) Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t alpha;
} Pixel;

typedef struct BMPImage {
    BMPHeader header;
    int norm_height; // normalized height
    Pixel **pixels;
} BMPImage;

BMPImage *readBMPImage(FILE *fp) {
    BMPImage *image = malloc(sizeof(BMPImage));
    if (image == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    fread(&(image->header), sizeof(BMPHeader), 1, fp); // Read BMP header

    image->pixels = malloc(image->header.height_px * sizeof(Pixel *));
    if (image->pixels == NULL) {
        // Handle memory allocation failure
        free(image);
        return NULL;
    }

    for (int i = 0; i < image->header.height_px; i++) {
        image->pixels[i] = malloc(image->header.width_px * sizeof(Pixel));
        if (image->pixels[i] == NULL) {
            // Handle memory allocation failure
            // Free allocated memory before returning
            for (int j = 0; j < i; j++) {
                free(image->pixels[j]);
            }
            free(image->pixels);
            free(image);
            return NULL;
        }
    }

    for (int i = 0; i < image->header.height_px; i++) {
        fread(image->pixels[i], sizeof(Pixel), image->header.width_px, fp); // Read pixel data
    }

    return image;
}

int main() {
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    BMPImage *image = readBMPImage(fp);
    if (image == NULL) {
        fprintf(stderr, "Error reading BMP image\n");
        fclose(fp);
        return 1;
    }

    // Use the image as needed

    fclose(fp);
    return 0;
}
