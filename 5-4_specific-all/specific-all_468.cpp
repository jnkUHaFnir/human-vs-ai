ARGB *pixel = (ARGB *)lr.pBits;
if (!pixel)
{
    qFatal("No data!");
}
qDebug("%u, %u, %u, %u", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
