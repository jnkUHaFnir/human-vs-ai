int processFile(const char *filename, 
                YAML::Emitter &out_yaml, 
                char *ground_truth_filename)
{   
    std::cout << "Here" << std::endl;

    if (ground_truth_filename == nullptr)
        sprintf(ground_truth_filename, "%s.yaml", filename);        

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

    // Rest of your function code
    return SUCCESS; // Or appropriate return value
}

int main(int argc, char* argv[]) {
    const char* filename = "default_filename.txt";
    char* ground_truth_filename = nullptr;

    for (int i = 1; i + 1 < argc; i += 2) {
        if (!strcmp(argv[i], "--snapshot-markup")) {
            ground_truth_filename = argv[i + 1];
        }
    }

    if (ground_truth_filename == nullptr) {
        // Assign default file name if not provided by the user
        ground_truth_filename = new char[strlen(filename) + 5]; // +5 for ".yaml\0"
        sprintf(ground_truth_filename, "%s.yaml", filename);
    }

    // Call the function
    processFile(filename, out_yaml, ground_truth_filename);

    delete[] ground_truth_filename; // Free memory if it was allocated

    return 0;
}
