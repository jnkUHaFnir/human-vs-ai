#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Define the structures
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
    int norm_height; //normalized height
    Pixel **pixels;
} BMPImage;

// Function to read the BMP image
BMPImage * readImage(FILE *fp) {
    BMPHeader *hp = malloc(sizeof(BMPHeader));
    fread(hp, sizeof(BMPHeader), 1, fp);

    BMPImage *p = malloc(sizeof(BMPImage));
    p->header = *hp;

    p->pixels = malloc(p->header.height_px * sizeof(Pixel *));
    for (int i = 0; i < p->header.height_px; i++) {
        p->pixels[i] = malloc(p->header.width_px * sizeof(Pixel));
        fread(p->pixels[i], sizeof(Pixel), p->header.width_px, fp);
    }

    free(hp); // Free the allocated memory for the BMPHeader structure
    return p;
}

// Function to release allocated memory for BMPImage
void freeImage(BMPImage *img) {
    for (int i = 0; i < img->header.height_px; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

int main() {
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    BMPImage *img = readImage(fp);

    // You can use the img structure here...

    freeImage(img); // Free the allocated memory for BMPImage structure

    fclose(fp);
    return 0;
}
