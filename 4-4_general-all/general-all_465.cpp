#include <d3d9.h>
#include <QDebug>

// Define a struct to represent the pixel data
struct ARGB {
    uint8_t b, g, r, a;
};

int main() {
    IDirect3D9 *m_d3d;
    IDirect3DDevice9 *m_d3ddev;
    D3DDISPLAYMODE *m_d3ddm;
    HRESULT hr;

    m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (m_d3d == NULL) {
        qFatal("Cannot create Direct3D!");
    }

    // Initialization code omitted for brevity

    IDirect3DSurface9 *renderTarget = NULL;
    IDirect3DSurface9 *destTarget = NULL;
    // Capture code omitted for brevity

    D3DLOCKED_RECT lr;
    ZeroMemory(&lr, sizeof(D3DLOCKED_RECT));
    hr = destTarget->LockRect(&lr, 0, D3DLOCK_READONLY);
    if (FAILED(hr)) {
        qFatal("Cannot lock rect!");
    }
    ARGB* pixel = (ARGB*)lr.pBits;
    if (!pixel) {
        qFatal("No data!");
    }
    // Output the pixel values as integers (assuming 8-bit components)
    qDebug("%u, %u, %u, %u", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);

    hr = destTarget->UnlockRect();
    if (FAILED(hr)) {
        qFatal("Cannot unlock rect!");
    }
    
    renderTarget->Release();
    destTarget->Release();

    // Cleaning code omitted for brevity

    return 0;
}
