#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

int processFile(const char *filename, 
                YAML::Emitter &out_yaml, 
                char *ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    if (ground_truth_filename[0] == '\0')
        sprintf(ground_truth_filename,"%s.yaml",filename);        

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

    return 0; // Success
}

int main(int argc, char *argv[]) {
    char ground_truth_filename[256];
    ground_truth_filename[0] = '\0'; // Initializing it as an empty string

    const char* filename = "example.txt"; // Just using an example filename

    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            strncpy(ground_truth_filename, argv[i + 1], sizeof(ground_truth_filename) - 6); // Max filename length - 6 (".yaml\0")
            strncat(ground_truth_filename, ".yaml", sizeof(ground_truth_filename) - strlen(ground_truth_filename) - 1);
        }
    }

    YAML::Emitter out_yaml; // Creating out_yaml object

    processFile(filename, out_yaml, ground_truth_filename);
    
    return 0;
}
