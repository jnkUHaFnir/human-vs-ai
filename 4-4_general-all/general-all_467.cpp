struct Pixel {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
};

// Capture
D3DLOCKED_RECT lr;
ZeroMemory(&lr, sizeof(D3DLOCKED_RECT));
hr = destTarget->LockRect(&lr, NULL, D3DLOCK_READONLY);
if (FAILED(hr)) {
    qFatal("Cannot lock rect!");
}

Pixel* pixels = (Pixel*)lr.pBits;
if (!pixels) {
    qFatal("No data!");
}

// Access and print the first pixel
qDebug("%u, %u, %u, %u", pixels[0].r, pixels[0].g, pixels[0].b, pixels[0].a);

hr = destTarget->UnlockRect();
if (FAILED(hr)) {
    qFatal("Cannot unlock rect!");
}

// Cleaning
if (destTarget) destTarget->Release();
if (renderTarget) renderTarget->Release();
