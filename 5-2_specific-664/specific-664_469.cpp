// Assuming ARGB definition is like this
struct ARGB {
    unsigned char a;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// Print pixel color values
qDebug("%.2f, %.2f, %.2f, %.2f", static_cast<float>(pixel[0].r), static_cast<float>(pixel[0].g), static_cast<float>(pixel[0].b), static_cast<float>(pixel[0].a));
