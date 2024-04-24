#include <fstream>
#include <vector>
#include <string>
#include <cppcodec/base64_rfc4648.hpp>

// Your existing code here...

ifstream::pos_type size;
std::vector<char> vmemblock;
ifstream file ("example.zip", ios::in|ios::binary|ios::ate);

if (file.is_open())
{
    size = file.tellg();
    vmemblock.resize(size);
    file.seekg(0, ios::beg);
    file.read(vmemblock.data(), size);
    file.close();
}

// Encode the zip file data using base64
std::string encodedData = cppcodec::base64_rfc4648::encode(vmemblock.data(), vmemblock.size());

// Append encoded data and set proper Content-Type
postBody.AppendFormat("Content-Disposition: form-data; name=\"datafile\"; filename=\"%s\"\r\n", zipFilePath);
postBody.AppendFormat("Content-Type: application/zip\r\n");
postBody.AppendFormat("\r\n%s", encodedData.c_str());
postBody.AppendFormat("\r\n--%s--\r\n", boundary);
