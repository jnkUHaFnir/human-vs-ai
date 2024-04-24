#include <QDebug>

struct ARGB {
    unsigned char a;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// Capture part
ARGB* pixel = (ARGB*)lr.pBits;
if (!pixel)
{
    qFatal("No data!");
}
qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);

// Cleaning part - use "delete" for single instances
delete m_d3ddm;
delete m_d3d;
delete m_d3ddev;
