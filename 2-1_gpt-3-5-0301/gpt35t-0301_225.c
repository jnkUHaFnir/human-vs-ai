#include <curl/curl.h>
#include <string>
#include <iostream>

using namespace std;

//Callback function for libcurl
size_t write_callback(char* buf, size_t size, size_t nmemb, void* userdata)
{
    ((string*)userdata)->append(buf, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;
    string webData;
    string cleanData;

    //Initialize curl
    curl = curl_easy_init();
    if (curl)
    {
        //Set options for curl
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &webData);

        //Perform curl request
        res = curl_easy_perform(curl);

        //Check if request was successful
        if (res == CURLE_OK)
        {
            //Loop through each character in webData
            for (int i = 0; i < webData.size(); i++)
            {
                //If character is alphanumeric or a space, append it to cleanData
                if (isalnum(webData[i]) || isspace(webData[i]))
                {
                    cleanData += webData[i];
                }
                //Otherwise, skip it
            }

            //Print cleaned-up data (for testing purposes)
            cout << "Cleaned-up data: " << endl;
            cout << cleanData << endl;
        }
        else
        {
            //Handle error
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        //Cleanup
        curl_easy_cleanup(curl);
    }
    else
    {
        //Handle initialization error
        cerr << "curl_easy_init() failed." << endl;
    }

    return 0;
}
