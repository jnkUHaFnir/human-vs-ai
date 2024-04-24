qDebug("%d, %d, %d, %d", pixel[0].r, pixel[0].g, pixel[0].b, pixel[0].a);
renderTarget->Release();
destTarget->Release(); 
m_d3ddev->Release();
m_d3d->Release();
