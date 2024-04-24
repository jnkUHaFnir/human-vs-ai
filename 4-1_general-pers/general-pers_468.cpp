// Define a struct to represent the pixel format
struct ARGB
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
};

// Print pixel color values as integers
qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);

// Consider endianness when interpreting pixel data (swap R and B for little-endian systems)
#ifdef LITTLE_ENDIAN
unsigned char temp = pixel[0].r;
pixel[0].r = pixel[0].b;
pixel[0].b = temp;
#endif
