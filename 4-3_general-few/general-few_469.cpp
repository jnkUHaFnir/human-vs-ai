ARGB *pixel = (ARGB *)lr.pBits;
if (pixel != nullptr)
{
    unsigned char r = pixel[0].r;
    unsigned char g = pixel[0].g;
    unsigned char b = pixel[0].b;
    unsigned char a = pixel[0].a;
    qDebug("%.2f, %.2f, %.2f, %.2f", r, g, b, a);
}
