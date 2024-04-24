#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream file("example.zip", std::ios::in | std::ios::binary | std::ios::ate);

    if (file.is_open()) {
        std::ifstream::pos_type size = file.tellg();
        char* memblock = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(memblock, size);
        file.close();

        std::string boundary = "your_boundary_here";

        std::stringstream postBody;
        postBody << "Content-Disposition: form-data; name=\"datafile\"; filename=\"example.zip\"\r\n";
        postBody << "Content-Type: application/zip\r\n";
        postBody << "\r\n";
        postBody.write(memblock, size);
        postBody << "\r\n--" << boundary << "--\r\n";

        // Output the constructed post body
        std::cout << postBody.str() << std::endl;

        delete[] memblock;
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    return 0;
}
