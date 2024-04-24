// Locking the rectangle
hr = destTarget->LockRect(&lr, NULL, D3DLOCK_READONLY);
if (FAILED(hr))
{
    qFatal("Cannot lock rect!");
}
BYTE* pBits = (BYTE*)lr.pBits;
if (!pBits)
{
    qFatal("No data!");
}
    
// Assuming pixel is structured correctly as ARGB and your back buffer is 32-bit
for (UINT y = 0; y < m_d3ddm->Height; ++y)
{
    ARGB* pixel = (ARGB*)(pBits + y * lr.Pitch);
    // Process pixels here, such as reading the first pixel of each row
    qDebug("%.2f, %.2f, %.2f, %.2f", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
}

// Unlocking the rectangle after processing
hr = destTarget->UnlockRect();
if (FAILED(hr))
{
    qFatal("Cannot unlock rect!");
}
