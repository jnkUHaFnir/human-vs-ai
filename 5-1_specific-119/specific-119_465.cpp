qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
delete m_d3ddm;
delete m_d3d;
delete m_d3ddev;
free(m_d3ddm);
m_d3ddev->Release();
m_d3d->Release();
