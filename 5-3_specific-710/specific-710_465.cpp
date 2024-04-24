BYTE blue = static_cast<BYTE>(pixel[0] & 0xFF);
BYTE green = static_cast<BYTE>((pixel[0] >> 8) & 0xFF);
BYTE red = static_cast<BYTE>((pixel[0] >> 16) & 0xFF);
BYTE alpha = static_cast<BYTE>((pixel[0] >> 24) & 0xFF);

qDebug("Pixel Color: %d, %d, %d, %d", red, green, blue, alpha);
