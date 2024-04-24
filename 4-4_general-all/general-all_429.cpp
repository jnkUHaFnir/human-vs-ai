#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "yaml-cpp/yaml.h"

#define FILE_ERROR -1

int processFile(const char *filename, 
                YAML::Emitter &out_yaml, 
                char *ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    if (ground_truth_filename[0] == '\0') { // Checking if ground_truth_filename is not set
        sprintf(ground_truth_filename, "%s.yaml", filename);      
    }

    std::ifstream imgstrm(filename, std::ios::binary | std::ios::in);

    if (imgstrm.bad() || !imgstrm.is_open())
    {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return FILE_ERROR;
    }

    // get ground truth
    std::ifstream ground_truth_stream(ground_truth_filename);

    if (!ground_truth_stream.is_open()) 
    {
        fprintf(stderr, "Failed to open file: %s\n", ground_truth_filename);
        return FILE_ERROR;
    }

    // Rest of your code to process the files
    return 0;
}

int main(int argc, char** argv) {
    char ground_truth_filename[256]; // Assuming a maximum file name size of 255 characters
    ground_truth_filename[0] = '\0'; // Initializing the string

    const char* filename = "default_filename"; // You can replace "default_filename" with your actual default filename

    bool markupFlag = false;
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            strcpy(ground_truth_filename, argv[i + 1]);
            markupFlag = true;
        }
    }

    // Call processFile function
    YAML::Emitter out_yaml;
    processFile(filename, out_yaml, ground_truth_filename);

    return 0;
}
