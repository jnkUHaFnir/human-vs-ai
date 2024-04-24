// Open the zip file in binary mode
ifstream file("example.zip", ios::in | ios::binary);

// Check if the file opened successfully
if (file.is_open())
{
    // Determine the size of the file
    file.seekg(0, ios::end);
    size = file.tellg();
    file.seekg(0, ios::beg);

    // Allocate memory for the file contents
    char* memblock = new char[size];

    // Read the file contents into memory
    file.read(memblock, size);

    // Close the file
    file.close();

    // Create a multipart form data body
    stringstream postBody;

    // Add the boundary
    postBody << "--" << boundary << "\r\n";

    // Add the content disposition header
    postBody << "Content-Disposition: form-data; name=\"datafile\"; filename=\"example.zip\"\r\n";

    // Add the content type header
    postBody << "Content-Type: application/zip\r\n\r\n";

    // Add the file contents
    postBody.write(memblock, size);

    // Add the closing boundary
    postBody << "\r\n--" << boundary << "--\r\n";
}
