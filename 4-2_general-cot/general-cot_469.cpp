// Define a structure to store color components
struct Color
{
    int r, g, b, a;
};

// Access the pixel data correctly
ARGB *pixel = (ARGB *)lr.pBits;
if (!pixel)
{
    qFatal("No data!");
}

Color color;
color.a = (pixel[0] >> 24) & 0xFF; // Extract alpha component
color.r = (pixel[0] >> 16) & 0xFF; // Extract red component
color.g = (pixel[0] >> 8) & 0xFF;  // Extract green component
color.b = pixel[0] & 0xFF;         // Extract blue component

qDebug("%.2f, %.2f, %.2f, %.2f", color.r, color.g, color.b, color.a);
