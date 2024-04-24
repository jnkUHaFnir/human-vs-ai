#include <iostream>
#include <fstream>
#include <cstring>
#include <yaml-cpp/yaml.h>  // Assuming YAML-CPP library.

#define FILE_ERROR -1

int processFile(const char *filename, YAML::Emitter &out_yaml, const char *ground_truth_filename_input) {
    char *ground_truth_filename = nullptr;
    bool must_free = false;
    
    if (!ground_truth_filename_input) {  // If input parameter is NULL, we create a default name.
        size_t len = strlen(filename) + 5; // +5 for ".yaml" and the NULL terminator.
        ground_truth_filename = new char[len];
        snprintf(ground_truth_filename, len, "%s.yaml", filename);
        must_free = true;
    } else {
        ground_truth_filename = const_cast<char*>(ground_truth_filename_input);
    }

    std::cout << "Using ground truth filename: " << ground_truth_filename << std::endl;

    // Your file processing code here...

    if (must_free) {
        delete[] ground_truth_filename;  // Free allocated memory for the default name.
    }

    return 0;  // Success
}

int main(int argc, char *argv[]) {
    YAML::Emitter out_yaml;  // Example purposes.
    const char *filename = "example.txt";  // Example input filename.

    const char *ground_truth_filename = nullptr;
    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
        }
    }

    processFile(filename, out_yaml, ground_truth_filename);

    return 0;
}
