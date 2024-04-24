#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

#define DEFAULT_YAML_EXTENSION ".yaml"
#define FILE_ERROR 1

int processFile(const char *filename, YAML::Emitter &out_yaml, char *ground_truth_filename) {
    std::cout << "Here" << std::endl;

    if (ground_truth_filename == nullptr) {
        // Set default ground truth filename if not provided
        ground_truth_filename = new char[strlen(filename) + strlen(DEFAULT_YAML_EXTENSION) + 1];
        strcpy(ground_truth_filename, filename);
        strcat(ground_truth_filename, DEFAULT_YAML_EXTENSION);
    }

    std::ifstream imgstrm(filename, std::ios::binary | std::ios::in);

    if (imgstrm.bad() || !imgstrm.is_open()) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return FILE_ERROR;
    }

    // get ground truth
    std::ifstream ground_truth_stream(ground_truth_filename);

    if (!ground_truth_stream.is_open()) {
        fprintf(stderr, "Failed to open file: %s\n", ground_truth_filename);
        return FILE_ERROR;
    }

    return 0; // Success
}

int main(int argc, char *argv[]) {
    const char *filename = "example.txt";
    YAML::Emitter out_yaml;

    char *ground_truth_filename = nullptr;

    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
            break;
        }
    }

    int result = processFile(filename, out_yaml, ground_truth_filename);

    delete[] ground_truth_filename; // Cleanup if default filename was allocated

    return result;
}
