// Assuming ARGB structure is defined as follows
struct ARGB {
    uint8_t b;
    uint8_t g;
    uint8_t r;
    uint8_t a;
};

// Inside your Capture block after locking the rect
uint32_t* srcData = (uint32_t*)lr.pBits;
int pitch = lr.Pitch / sizeof(uint32_t); // Pitch is in bytes, so divide by size of uint32_t for DWORD-aligned pitch

ARGB pixel;
pixel.r = (*srcData >> 16) & 0xFF; // Red component
pixel.g = (*srcData >> 8) & 0xFF;  // Green component
pixel.b = (*srcData) & 0xFF;       // Blue component
pixel.a = (*srcData >> 24) & 0xFF; // Alpha component

qDebug("%.2f, %.2f, %.2f, %.2f", pixel.r, pixel.g, pixel.b, pixel.a);
