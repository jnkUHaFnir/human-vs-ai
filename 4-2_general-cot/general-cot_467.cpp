qDebug("%f, %f, %f, %f", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
delete m_d3ddm;
m_d3ddm = nullptr; // Set to nullptr after deletion

m_d3ddev->Release();
m_d3ddev = nullptr; // Set to nullptr after releasing

m_d3d->Release();
m_d3d = nullptr; // Set to nullptr after releasing
