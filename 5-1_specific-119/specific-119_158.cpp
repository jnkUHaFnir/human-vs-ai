#include <fstream>
#include <iostream>
#include <sstream>
#include <curl/curl.h> // You might need to install libcurl development library

size_t write_callback(void *contents, size_t size, size_t nmemb, std::string *s) {
    size_t newLength = size * nmemb;
    size_t oldLength = s->size();
    try {
        s->resize(oldLength + newLength);
    } catch (std::bad_alloc &e) {
        // handle memory allocation failure
        return 0;
    }
    std::copy((char*)contents, (char*)contents + newLength, s->begin() + oldLength);
    return size * nmemb;
}

int main() {
    std::ifstream file("example.zip", std::ios::binary);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::ostringstream ss;
    ss << file.rdbuf();
    std::string fileContents = ss.str();

    file.close();

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/zip");
        headers = curl_slist_append(headers, "Expect:");
        
        curl_easy_setopt(curl, CURLOPT_URL, "http://yourserver.com/upload");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, fileContents.size());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fileContents.c_str());

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return 0;
}
