#include <fstream>
#include <sstream>
#include <iomanip>

// Function to encode binary data as Base64
std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
    std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for(i = 0; (i <4) ; i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i) {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';

    }

    return ret;
}

int main() {
    std::ifstream file("example.zip", std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open()) {
        file.seekg(0, std::ios::beg);

        std::stringstream buffer;
        buffer << file.rdbuf();
        
        std::string base64_data = base64_encode(reinterpret_cast<const unsigned char*>(buffer.str().c_str()), buffer.str().size());
        
        postBody.AppendFormat("Content-Disposition: form-data; name=\"datafile\"; filename=\"%s\"; \r\n\n%s", zipFilePath, base64_data.c_str());
        postBody.AppendFormat("\r\n--%s--\r\n", boundary);

        file.close();
    }

    return 0;
}
