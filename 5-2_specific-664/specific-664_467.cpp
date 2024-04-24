// Define ARGB structure with integer fields for color components
struct ARGB {
    int a;
    int r;
    int g;
    int b;
};

...

D3DLOCKED_RECT lr;
ZeroMemory(&lr, sizeof(D3DLOCKED_RECT));
hr = destTarget->LockRect(&lr, 0, D3DLOCK_READONLY);
if (FAILED(hr))
{
    qFatal("Cannot lock rect!");
}

ARGB *pixel = (ARGB *)lr.pBits;
if (!pixel)
{
    qFatal("No data!");
}

// Access and display color components as integers
qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);

hr = destTarget->UnlockRect();
if (FAILED(hr))
{
    qFatal("Cannot unlock rect!");
}

...
