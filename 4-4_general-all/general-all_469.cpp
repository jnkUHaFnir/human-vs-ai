#include <d3d9.h>
#include <QDebug>

struct ARGB {
    union {
        struct {
            unsigned char b, g, r, a;
        };
        unsigned int argb;
    };
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

    m_d3ddm = new D3DDISPLAYMODE;
    hr = m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, m_d3ddm);
    if (hr != D3D_OK) {
        m_d3d->Release();
        delete m_d3ddm;
        qFatal("Cannot get DisplayMode!");
    }

    // Initialization code...

    if (FAILED(hr)) {
        m_d3d->Release();
        delete m_d3ddm;
        qFatal("Failed CreateDevice!");
    } else {
        qDebug("Created Device with %i * %i", m_d3ddm->Width, m_d3ddm->Height);
    }

    // Capture code...

    ARGB *pixel = (ARGB *)lr.pBits;
    if (pixel == NULL) {
        qFatal("No data!");
    }
    qDebug("%u, %u, %u, %u", pixel->r, pixel->g, pixel->b, pixel->a);

    // Cleaning code...

    delete m_d3ddm;
    m_d3d->Release();
    m_d3ddev->Release();

    return 0;
}
