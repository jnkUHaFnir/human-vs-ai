// Change the ARGB struct to use unsigned char for color channels
struct ARGB {
    uint8_t b, g, r, a;
};

// Access pixel data as unsigned char or uint8_t
uint8_t *pixelData = (uint8_t*)lr.pBits;

// Access the first pixel assuming 32-bit ARGB format
ARGB *pixel = (ARGB *)pixelData;

// Print the color channels using correct format specifiers for unsigned char
qDebug("%u, %u, %u, %u", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
