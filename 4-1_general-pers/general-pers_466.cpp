// Define a structure to hold the pixel data
struct ARGB
{
    BYTE b, g, r, a; // Assuming ARGB format
};

// LockRect method should be called with D3DLOCK_READONLY flag for read-only access
hr = destTarget->LockRect(&lr, NULL, D3DLOCK_READONLY);

// Check if the lock was successful
if (SUCCEEDED(hr))
{
    // Check if the format is ARGB
    if (lr.Pitch % 4 == 0 && (m_d3ddm->Format == D3DFMT_A8R8G8B8 || m_d3ddm->Format == D3DFMT_X8R8G8B8))
    {
        ARGB *pixel = (ARGB *)lr.pBits;
        // Access pixel data safely
        qDebug("%.2f, %.2f, %.2f, %.2f", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
    }
    else
    {
        qFatal("Invalid pixel format or pitch!");
    }

    hr = destTarget->UnlockRect();
    if (FAILED(hr))
    {
        qFatal("Cannot unlock rect!");
    }
}
else
{
    qFatal("Cannot lock rect!");
}
