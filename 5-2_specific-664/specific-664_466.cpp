#include <QDebug> // Assuming this includes the appropriate headers for your application

// Assuming ARGB struct is defined like this:
struct ARGB {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
};

// Inside your code after retrieving pixel data
qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
