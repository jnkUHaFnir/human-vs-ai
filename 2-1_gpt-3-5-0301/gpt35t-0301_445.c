#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <regex.h>
#include <curl/curl.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    // cast the userdata pointer to a string buffer
    char *buffer = (char*)userdata;
    // concatenates the data to the buffer
    strncat(buffer, ptr, size*nmemb);
    return size*nmemb;
}

int main() {
    CURL *curl_handle;
    CURLcode res;
    char buffer[4096] = {0};

    // initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);

    // create a curl handle
    curl_handle = curl_easy_init();

    // set the URL to fetch
    curl_easy_setopt(curl_handle, CURLOPT_URL, "http://example.com");

    // set the write callback function to receive the data
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);

    // set the userdata for the callback to receive the data into the buffer
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, buffer);

    // perform the request
    res = curl_easy_perform(curl_handle);

    // check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        goto cleanup;
    }

    // compile the regex to match non-alphanumeric characters
    regex_t regex;
    const char *pattern = "[^[:alnum:] ]+";
    int rc = regcomp(&regex, pattern, REG_EXTENDED|REG_NEWLINE);
    if (rc != 0) {
        char error_msg[512];
        regerror(rc, &regex, error_msg, sizeof(error_msg));
        fprintf(stderr, "regcomp() failed: %s\n", error_msg);
        goto cleanup;
    }

    // execute the regex to replace non-alphanumeric characters with a space
    char *result = regreplace(buffer, &regex, ' ', REG_EXTENDED|REG_NEWLINE);
    printf("%s\n", result);

    // cleanup
    free(result);
    regfree(&regex);

cleanup:
    // cleanup the curl handle
    curl_easy_cleanup(curl_handle);

    // cleanup the curl library
    curl_global_cleanup();

    return 0;
}
