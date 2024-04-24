#include <d3d9.h>
#include <QDebug>

struct ARGB {
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
};

void captureGamePixels(HWND m_target) {
    IDirect3D9 *m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (m_d3d == NULL) {
        qFatal("Cannot create Direct3D!");
    }

    D3DDISPLAYMODE d3ddm;
    if (FAILED(m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm))) {
        m_d3d->Release();
        qFatal("Cannot get DisplayMode!");
    }

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = m_target;
    d3dpp.BackBufferWidth = d3ddm.Width;
    d3dpp.BackBufferHeight = d3ddm.Height;
    d3dpp.BackBufferFormat = d3ddm.Format;

    IDirect3DDevice9 *m_d3ddev;
    if (FAILED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_target, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_d3ddev))) {
        m_d3d->Release();
        qFatal("Failed CreateDevice!");
    }

    IDirect3DSurface9 *renderTarget = NULL;
    if (FAILED(m_d3ddev->GetRenderTarget(0, &renderTarget))) {
        m_d3ddev->Release();
        m_d3d->Release();
        qFatal("Failed GetRenderTarget!");
    }

    IDirect3DSurface9 *destTarget = NULL;
    if (FAILED(m_d3ddev->CreateOffscreenPlainSurface(d3ddm.Width, d3ddm.Height, d3ddm.Format, D3DPOOL_SYSTEMMEM, &destTarget, NULL))) {
        renderTarget->Release();
        m_d3ddev->Release();
        m_d3d->Release();
        qFatal("Failed CreateOffscreenPlainSurface!");
    }

    if (FAILED(m_d3ddev->GetRenderTargetData(renderTarget, destTarget))) {
        renderTarget->Release();
        destTarget->Release();
        m_d3ddev->Release();
        m_d3d->Release();
        qFatal("Failed GetRenderTargetData!");
    }

    D3DLOCKED_RECT lr;
    if (FAILED(destTarget->LockRect(&lr, NULL, D3DLOCK_READONLY))) {
        renderTarget->Release();
        destTarget->Release();
        m_d3ddev->Release();
        m_d3d->Release();
        qFatal("Cannot lock rect!");
    }

    ARGB *pixels = (ARGB *)lr.pBits;
    if (!pixels) {
        renderTarget->Release();
        destTarget->Release();
        m_d3ddev->Release();
        m_d3d->Release();
        qFatal("No data!");
    }

    qDebug("%d, %d, %d, %d", pixels[0].r, pixels[0].g, pixels[0].b, pixels[0].a);

    destTarget->UnlockRect();
    renderTarget->Release();
    destTarget->Release();

    m_d3ddev->Release();
    m_d3d->Release();
}

int main() {
    // Call this function with the proper window handle
    // Example: captureGamePixels(hwnd_of_game_window);
    return 0;
}
