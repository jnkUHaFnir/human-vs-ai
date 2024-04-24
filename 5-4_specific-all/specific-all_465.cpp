struct ARGB {
    uint8_t b; // Blue
    uint8_t g; // Green
    uint8_t r; // Red
    uint8_t a; // Alpha
};
qDebug("%.2f, %.2f, %.2f, %.2f", pixel[0].r / 255.0, pixel[0].g / 255.0, pixel[0].b / 255.0, pixel[0].a / 255.0);
IDirect3DDevice9* m_d3ddev;
D3DDISPLAYMODE m_d3ddm;
// Other code

hr = m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &m_d3ddm); // Use address of operator
if (hr != D3D_OK) {
    m_d3d->Release();
    qFatal("Cannot get DisplayMode!");
}

D3DPRESENT_PARAMETERS d3dpp;
memset(&d3dpp, 0, sizeof(d3dpp)); // Use memset instead of ZeroMemory

// Other code
