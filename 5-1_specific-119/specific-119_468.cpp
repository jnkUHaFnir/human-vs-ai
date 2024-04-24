BYTE* pixelBytes = reinterpret_cast<BYTE*>(lr.pBits); // Treat the pixel data as bytes

if (pixelBytes != nullptr)
{
    // Assuming ARGB layout (4 bytes per pixel)
    int blue = pixelBytes[0];   // Blue component
    int green = pixelBytes[1];  // Green component
    int red = pixelBytes[2];    // Red component
    int alpha = pixelBytes[3];  // Alpha component

    qDebug("Color: R:%d, G:%d, B:%d, A:%d", red, green, blue, alpha);
}
else
{
    qFatal("No data!");
}
