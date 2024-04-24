#include <curl/curl.h>
#include <string>
#include <iostream>

size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string data;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "your_url_here");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Remove non-alphanumeric characters and extra line breaks
            std::string clean_data;
            for (char c : data) {
                if (isalnum(c) || c == ' ') {
                    clean_data += c;
                } else {
                    clean_data += ' ';
                }
            }

            // Remove consecutive spaces and extra line breaks
            std::string final_data;
            bool prev_space = false;
            for (char c : clean_data) {
                if (!(prev_space && c == '')) {
                    final_data += c;
                    prev_space = (c == ' ');
                }
            }

            // Use the final_data for further processing
            std::cout << final_data << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}
