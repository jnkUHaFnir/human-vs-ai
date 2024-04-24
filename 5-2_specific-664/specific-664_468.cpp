qDebug("%u, %u, %u, %u", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
struct ARGB {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
};

ARGB* pixel = (ARGB*)lr.pBits;
