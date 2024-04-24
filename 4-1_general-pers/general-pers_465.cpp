// Define the structure for ARGB
struct ARGB {
    float r, g, b, a;
};

// Access DirectX pixel data as D3DCOLOR
D3DCOLOR *pixel = (D3DCOLOR *)lr.pBits;
if (!pixel)
{
    qFatal("No data!");
}

// Extract color components from D3DCOLOR
ARGB argb;
argb.a = ((pixel[0] >> 24) & 0xFF) / 255.0f;
argb.r = ((pixel[0] >> 16) & 0xFF) / 255.0f;
argb.g = ((pixel[0] >> 8) & 0xFF) / 255.0f;
argb.b = (pixel[0] & 0xFF) / 255.0f;

qDebug("%.2f, %.2f, %.2f, %.2f", argb.r, argb.g, argb.b, argb.a);

// Check if the rect was successfully locked
if (SUCCEEDED(hr)) 
{
    // Use the pixel data
} 
else 
{
    qFatal("Cannot lock rect!");
}

// Release resources after using them
destTarget->UnlockRect();
destTarget->Release();
renderTarget->Release();

// Memory clean-up
delete m_d3ddm; // Only if allocated using new

// Release resources in reverse order of creation
m_d3ddev->Release();
m_d3d->Release();
