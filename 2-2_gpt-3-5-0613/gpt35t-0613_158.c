ifstream file("example.zip", ios::in | ios::binary| ios::ate);
if (file.is_open())
{
    size = file.tellg();
    memblock.resize(size);
    file.seekg(0, ios::beg);
    file.read(&memblock[0], size);
    file.close();

    // Construct multipart/form-data request body
    postBody += "Content-Disposition: form-data; name=\"datafile\"; filename=\"" + zipFilePath + "\"\r\n";
    postBody += "Content-Type: application/zip\r\n\r\n";
    postBody += memblock;
    postBody += "\r\n--" + boundary + "--\r\n";
}
