// Assuming a common format like D3DFMT_A8R8G8B8 where every pixel is 4 bytes
uint32_t* pixelData = reinterpret_cast<uint32_t*>(lr.pBits);
if (!pixelData)
{
    qFatal("No data!");
}
// Access first pixel
uint32_t firstPixel = pixelData[0];
qDebug("%d, %d, %d, %d", 
       (firstPixel >> 16) & 0xFF, // R
       (firstPixel >> 8) & 0xFF,  // G
       (firstPixel) & 0xFF,       // B
       (firstPixel >> 24) & 0xFF);// A
