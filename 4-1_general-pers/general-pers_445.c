#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Callback function to write received data to a buffer
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    char *data = (char *)userdata;

    // Concatenate received data to the existing buffer
    strncat(data, ptr, realsize);

    return realsize;
}

// Sanitize function to remove characters other than letters, numbers, and spaces
void sanitize_data(char *data) {
    char *src = data;
    char *dst = data;

    while (*src) {
        if (isalnum(*src) || isspace(*src)) {
            *dst = *src;
            dst++;
        }
        src++;
    }
    *dst = '\0';
}

int main() {
    CURL *curl;
    CURLcode res;
    char data[4096] = {0};

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com/data");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            printf("Original data:\n%s\n", data);

            sanitize_data(data);

            printf("\nSanitized data:\n%s\n", data);
        } else {
            fprintf(stderr, "Failed to fetch data: %s\n", curl_easy_strerror(res));
        }
    } else {
        fprintf(stderr, "Failed to initialize libcurl\n");
    }

    return 0;
}
