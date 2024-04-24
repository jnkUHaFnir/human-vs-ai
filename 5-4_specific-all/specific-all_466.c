struct ARGB {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
};

// Assuming pixel color channels are in ARGB format
ARGB *pixel = (ARGB *)lr.pBits;

// Print integer pixel values instead of floating-point
qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
