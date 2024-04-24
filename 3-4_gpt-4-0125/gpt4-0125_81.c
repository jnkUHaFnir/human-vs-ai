#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

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
    int norm_height;
    Pixel **pixels;
} BMPImage;

BMPImage * readImage(FILE *fp) {
    // Read the header
    BMPHeader *hp = malloc(sizeof(BMPHeader));
    if(fread(hp, sizeof(BMPHeader), 1, fp) != 1) {
        free(hp);
        return NULL; // Failed reading header
    }

    // Allocate memory for BMPImage
    BMPImage *img = malloc(sizeof(BMPImage));
    img->header = *hp; // Copy the header into our BMPImage structure
    free(hp); // We don't need the temporary header anymore

    // Allocate memory for all pixels [height][width]
    img->pixels = malloc(img->header.height_px * sizeof(Pixel *));
    for(int i = 0; i < img->header.height_px; i++) {
        img->pixels[i] = malloc(img->header.width_px * sizeof(Pixel));
    }

    // Move file pointer to the beginning of pixel data
    fseek(fp, img->header.offset, SEEK_SET);

    // Read pixel data row by row (from bottom to top)
    for(int i = 0; i < img->header.height_px; i++) {
        // Since BMP rows are padded to be a multiple of 4 bytes, calculate padding
        int padding = (4 - (img->header.width_px * sizeof(Pixel)) % 4) % 4;
        // Read one row
        if(fread(img->pixels[img->header.height_px - 1 - i], sizeof(Pixel), img->header.width_px, fp) != img->header.width_px) {
            // Handle read error (not demonstrated here)
        }
        // Skip the padding
        fseek(fp, padding, SEEK_CUR);
    }

    return img;
}
