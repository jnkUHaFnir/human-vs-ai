#include <iostream>
#include <fstream>
#include <zlib.h>
#include <vector>

std::vector<char> unzipFile(const std::string& zipFilePath, const std::string& fileInZip) {
    std::vector<char> memblock;
    std::ifstream file(zipFilePath, std::ios::binary);
    
    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        std::vector<char> buffer(size);

        file.seekg(0, std::ios::beg);
        file.read(buffer.data(), size);
        file.close();

        int err;
        z_stream zstream;
        zstream.zalloc = Z_NULL;
        zstream.zfree = Z_NULL;
        zstream.opaque = Z_NULL;
        zstream.avail_in = 0;
        zstream.next_in = Z_NULL;
        err = inflateInit2(&zstream, 15 + 32); // auto-detect gzip/zlib header
        if (err != Z_OK) {
            std::cerr << "Error initializing zlib" << std::endl;
            return memblock;
        }

        zstream.avail_in = buffer.size();
        zstream.next_in = (Bytef*)buffer.data();

        unsigned long total_uncompressed = 0;
        unsigned long capacity = 131072; // initial capacity
        do {
            memblock.resize(capacity);
            zstream.avail_out = capacity;
            zstream.next_out = (Bytef*)memblock.data() + total_uncompressed;
            err = inflate(&zstream, Z_SYNC_FLUSH);
            if (err != Z_OK && err != Z_STREAM_END) {
                std::cerr << "Error inflating data: " << err << std::endl;
                inflateEnd(&zstream);
                return memblock;
            }
            total_uncompressed += capacity - zstream.avail_out;
            capacity *= 2;
        } while (zstream.avail_out == 0);

        memblock.resize(total_uncompressed);

        inflateEnd(&zstream);
    } else {
        std::cerr << "Failed to open ZIP file" << std::endl;
    }

    return memblock;
}

int main() {
    std::string zipFilePath = "example.zip";
    std::string fileInZip = "file.txt";

    std::vector<char> extractedFile = unzipFile(zipFilePath, fileInZip);

    // Include the extracted file contents in the postBody
    std::string postBody;
    postBody.append("Content-Disposition: form-data; name=\"datafile\"; filename=\"").append(fileInZip).append("\"; \r\n\n");

    // Assuming extractedFile is plain text data, you can directly append it to postBody
    postBody.append(extractedFile.data(), extractedFile.size());

    postBody.append("\r\n--boundary--\r\n");

    // Do something with postBody

    return 0;
}
