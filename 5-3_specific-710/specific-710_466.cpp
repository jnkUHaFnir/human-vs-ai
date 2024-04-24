BYTE* pixel = reinterpret_cast<BYTE*>(lr.pBits);
if (!pixel)
{
    qFatal("No data!");
}

// Assuming ARGB structure is 4 bytes (1 byte each for A, R, G, B)
qDebug("%d, %d, %d, %d", pixel[0], pixel[1], pixel[2], pixel[3]);
