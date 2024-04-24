#include <fstream>
#include <sstream>
#include <string>

// Function to read a file into a string
std::string readFileIntoString(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        // Failed to open file
        return "";
    }

    // Get the file size
    file.seekg(0, std::ios::end);
    std::streamoff fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Read the whole file into a string
    std::string fileContent(fileSize, '\0');
    if (!file.read(&fileContent[0], fileSize)) {
        // Failed to read file
        return "";
    }

    return fileContent;
}

int main() {
    std::string zipFilePath = "example.zip";
    
    std::string fileContent = readFileIntoString(zipFilePath);
    if (fileContent.empty()) {
        // Handle error reading file
        return 1;
    }

    std::string boundary = "your_boundary"; // Add your boundary here

    // Construct the post request body
    std::stringstream postBody;
    postBody << "Content-Disposition: form-data; name=\"datafile\"; filename=\"" << zipFilePath << "\"\r\n";
    postBody << "Content-Type: application/zip\r\n\n";
    postBody << fileContent;
    postBody << "\r\n--" << boundary << "--\r\n";
    
    // Use postBody.str() to get the resulting string for the POST request

    return 0;
}
