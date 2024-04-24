#include <fstream>
#include <vector>
#include <sstream>

// Assuming `boundary` is a std::string containing your multipart boundary
std::string boundary = "----WebKitFormBoundary7MA4YWxkTrZu0gW";

std::string zipFilePath = "example.zip";
std::ifstream file(zipFilePath, std::ios::binary);
if (!file.is_open()) {
    // Handle error
    return;
}

// Read the file into a vector of bytes
std::vector<char> fileContents((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());

file.close();

// Start building the POST body
std::ostringstream postBody;

// Add file part
postBody << "--" << boundary << "\r\n"
         << "Content-Disposition: form-data; name=\"datafile\"; filename=\"" << zipFilePath << "\"\r\n"
         << "Content-Type: application/octet-stream\r\n\r\n";

// We directly write the binary data from the vector to the postBody stream
// Note: Directly writing binary data like this into a `ostringstream` might work for
// simplicity, but in practice, you should consider directly writing to the output buffer/stream
// of your network library for efficiency and reliability.
postBody.write(fileContents.data(), fileContents.size());

// Finalize the body with the closing boundary
postBody << "\r\n--" << boundary << "--\r\n";

// Now `postBody.str()` contains the body of your POST request.
// You will need to set the `Content-Type` header of your request to
// "multipart/form-data; boundary=----WebKitFormBoundary7MA4YWxkTrZu0gW" (or whatever your boundary is)
// And send `postBody.str()` as the body of your request.

// Remember, for actual network communication, review how you're sending requests
// and adjust for your specific environment, especially handling binary data.
