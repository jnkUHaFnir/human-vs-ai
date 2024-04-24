#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::string readFileToPost(const std::string& filename, const std::string& boundary) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return "";
    }

    std::ostringstream postBody;
    postBody << "Content-Disposition: form-data; name=\"datafile\"; filename=\"" << filename << "\"\r\n";
    postBody << "Content-Type: application/zip\r\n\r\n";

    char buffer[1024];
    while (file.read(buffer, sizeof(buffer))) {
        postBody.write(buffer, file.gcount());
    }

    postBody << "\r\n--" << boundary << "--\r\n";

    file.close();
    return postBody.str();
}

int main() {
    std::string zipFilePath = "example.zip";
    std::string boundary = "myboundary";

    std::string postBody = readFileToPost(zipFilePath, boundary);

    if (!postBody.empty()) {
        // Post the data to the server using postBody
        std::cout << "Successfully read file contents into postBody." << std::endl;
    } else {
        std::cerr << "Error reading file contents into postBody." << std::endl;
    }

    return 0;
}
