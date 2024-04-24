// ... the other parts of your code ...

ifstream file("example.zip", ios::in | ios::binary | ios::ate);
if (file.is_open())
{
 size = file.tellg();
 std::vector<char> memblock(size); // Use a vector to handle binary data
 file.seekg(0, ios::beg);
 file.read(memblock.data(), size);
 file.close();

 postBody.AppendFormat("Content-Disposition: form-data; name=\"datafile\"; filename=\"%s\"\r\n", "example.zip");
 postBody.AppendFormat("Content-Type: application/octet-stream\r\n\r\n"); // Add Content-Type header for the file part

 // Directly append the binary data
 postBody.Append(memblock.data(), size);

 postBody.AppendFormat("\r\n--%s--\r\n", boundary);
}

// ... code to actually send the POST request ...
